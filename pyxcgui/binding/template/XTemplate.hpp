				 #pragma once
#include "pch.h"
#include "xcgui/template/XCListItemTemplate.hpp"

namespace xcgui {

	void declareTemplate(py::module& m) {
		py::class_<XCTemplateNode>(m, "XTemplateNode")
			PYCASTOBJECT(XCTemplateNode)
			.def(py::init<XC_OBJECT_TYPE>(), "objectType"_a)
			.def_static("cloneNode", [](const XCTemplateNode& node) -> XCTemplateNode* {
				auto pNode = new XCTemplateNode();
				if (!pNode->CloneNode(node.getHandle())) {
					return nullptr;
				}
				return pNode;
			}, "node"_a, py::return_value_policy::take_ownership)

			.def("getNode", [](XCTemplateNode& self, int itemId) -> XCTemplateNode* {
				auto handle = self.GetNode(itemId);
				if (!handle)
					return nullptr;
				return new XCTemplateNode(handle);
			}, "itemId"_a, py::return_value_policy::take_ownership)

			.def("addNode", [](XCTemplateNode& self, const XCTemplateNode& childNode)  {
				return self.AddNode(childNode.getHandle());
			}, "childNode"_a, py::return_value_policy::take_ownership)

			.def("setNodeAttribute", &XCTemplateNode::SetNodeAttribute, "name"_a, "value"_a)
			.def("setNodeAttributeEx", &XCTemplateNode::SetNodeAttributeEx, "itemId"_a, "name"_a, "value"_a)
			.def("getHandle", [](XCTemplateNode& self) -> uintptr_t {
				return (uintptr_t)self.getHandle();
			})
			;

		py::class_<XCListItemTemplate>(m, "XTemplate")
			PYCASTOBJECT(XCListItemTemplate)
			.def(py::init<listItemTemp_type_>(), "tempType"_a)
			.def_static("load", [](listItemTemp_type_ nType, const std::wstring& fileName) -> XCListItemTemplate* {
				auto pTemplate = new XCListItemTemplate();
				if (!pTemplate->Load(nType, fileName)) {
					return nullptr;
				}
				return pTemplate;
			}, "tempType"_a, "filename"_a, py::return_value_policy::take_ownership)	

			.def_static("loadMem", [](listItemTemp_type_ nType, const py::bytes& xmlData) -> XCListItemTemplate* {
				auto pTemplate = new XCListItemTemplate();
				if (!pTemplate->LoadFromString(nType, xmlData)) {
					return nullptr;
				}
				return pTemplate;
			}, "tempType"_a, "xmlData"_a, py::return_value_policy::take_ownership)
				
			.def_static("loadZip", [](listItemTemp_type_ nType, const std::wstring& zipFileName, 
				const std::wstring& fileName, const std::wstring& password) -> XCListItemTemplate* {
				auto pTemplate = new XCListItemTemplate();
				if (!pTemplate->LoadZip(nType, zipFileName, fileName, password)) {
					return nullptr;
				}
				return pTemplate;
			}, "tempType"_a, "zipFileName"_a, "fileName"_a, "password"_a, py::return_value_policy::take_ownership)

			.def_static("loadZipMem", [](listItemTemp_type_ nType, const py::bytes& data, const std::wstring& fileName, 
				const std::wstring& password) -> XCListItemTemplate* {
				auto pTemplate = new XCListItemTemplate();
				if (!pTemplate->LoadZipMem(nType, data, fileName, password)) {
					return nullptr;
				}
				return pTemplate;
			}, "tempType"_a, "data"_a, "fileName"_a, "password"_a, py::return_value_policy::take_ownership)

			// 3.3.8 新增
			.def_static("loadFromMem", [](listItemTemp_type_ nType, const std::string& xmlData) -> XCListItemTemplate* {
				auto handle = XTemp_LoadFromMem(nType, xmlData.c_str());
				auto pTemplate = new XCListItemTemplate(handle);
				if (!pTemplate->getHandle()) {
					delete pTemplate;
					return nullptr;
				}
				return pTemplate;
			}, "tempType"_a, "xmlData"_a, py::return_value_policy::take_ownership)

			.def_static("loadFromMemEx", [](listItemTemp_type_ nType, const std::string& xmlData, const std::wstring& prefixName = L"") -> XCListItemTemplate* {
				const wchar_t* pPrefix = prefixName.empty() ? NULL : prefixName.c_str();
				auto handle = XTemp_LoadFromMemEx(nType, xmlData.c_str(), pPrefix);
				auto pTemplate = new XCListItemTemplate(handle);
				if (!pTemplate->getHandle()) {
					delete pTemplate;
					return nullptr;
				}
				return pTemplate;
			}, "tempType"_a, "xmlData"_a, "prefixName"_a = L"", py::return_value_policy::take_ownership)

			.def_static("loadZipRes", [](listItemTemp_type_ nType, int id, const std::wstring& fileName, const std::wstring& password = L"", uintptr_t hModule = 0) -> XCListItemTemplate* {
				const wchar_t* pPassword = password.empty() ? NULL : password.c_str();
				auto handle = XTemp_LoadZipRes(nType, id, fileName.c_str(), pPassword, (HMODULE)hModule);
				auto pTemplate = new XCListItemTemplate(handle);
				if (!pTemplate->getHandle()) {
					delete pTemplate;
					return nullptr;
				}
				return pTemplate;
			}, "tempType"_a, "id"_a, "fileName"_a, "password"_a = L"", "hModule"_a = 0, py::return_value_policy::take_ownership)

			.def_static("loadZipResEx", [](listItemTemp_type_ nType, int id, const std::wstring& fileName, const std::wstring& password = L"", const std::wstring& prefixName = L"", uintptr_t hModule = 0) -> XCListItemTemplate* {
				const wchar_t* pPassword = password.empty() ? NULL : password.c_str();
				const wchar_t* pPrefix = prefixName.empty() ? NULL : prefixName.c_str();
				auto handle = XTemp_LoadZipResEx(nType, id, fileName.c_str(), pPassword, pPrefix, (HMODULE)hModule);
				auto pTemplate = new XCListItemTemplate(handle);
				if (!pTemplate->getHandle()) {
					delete pTemplate;
					return nullptr;
				}
				return pTemplate;
			}, "tempType"_a, "id"_a, "fileName"_a, "password"_a = L"", "prefixName"_a = L"", "hModule"_a = 0, py::return_value_policy::take_ownership)

			.def_static("loadEx", [](listItemTemp_type_ nType, const std::wstring& fileName) -> std::vector<XCListItemTemplate*> {
				HTEMP temp1 = NULL;
				HTEMP temp2 = NULL;

				std::vector<XCListItemTemplate*> out;

				if (!XCListItemTemplate::LoadEx(nType, fileName, &temp1, &temp2)) {
					out.emplace_back(nullptr);
					out.emplace_back(nullptr);
				}
				else {
					if (temp1) {
						out.emplace_back(new XCListItemTemplate(temp1));
					}
					else {
						out.emplace_back(nullptr);
					}
					if (temp2) {
						out.emplace_back(new XCListItemTemplate(temp2));
					}
					else {
						out.emplace_back(nullptr);
					}

				}
				return out;
			}, "tempType"_a, "filename"_a, py::return_value_policy::take_ownership)	

			.def_static("loadMemEx", [](listItemTemp_type_ nType, const py::bytes& xmlData) -> std::vector<XCListItemTemplate*> {
				HTEMP temp1 = NULL;
				HTEMP temp2 = NULL;

				std::vector<XCListItemTemplate*> out;

				if (!XCListItemTemplate::LoadFromStringEx(nType, xmlData, &temp1, &temp2)) {
					out.emplace_back(nullptr);
					out.emplace_back(nullptr);
				}
				else {
					if (temp1) {
						out.emplace_back(new XCListItemTemplate(temp1));
					}
					else {
						out.emplace_back(nullptr);
					}
					if (temp2) {
						out.emplace_back(new XCListItemTemplate(temp2));
					}
					else {
						out.emplace_back(nullptr);
					}

				}
				return out;
			}, "tempType"_a, "xmlData"_a, py::return_value_policy::take_ownership)

			.def_static("loadZipEx", [](listItemTemp_type_ nType, const std::wstring& zipFileName, 
				const std::wstring& fileName, const std::wstring& password) ->std::vector<XCListItemTemplate*>  {
				HTEMP temp1 = NULL;
				HTEMP temp2 = NULL;

				std::vector<XCListItemTemplate*> out;

				if (!XCListItemTemplate::LoadZipEx(nType, zipFileName, fileName, password, &temp1, &temp2)) {
					out.emplace_back(nullptr);
					out.emplace_back(nullptr);
				}
				else {
					if (temp1) {
						out.emplace_back(new XCListItemTemplate(temp1));
					}
					else {
						out.emplace_back(nullptr);
					}
					if (temp2) {
						out.emplace_back(new XCListItemTemplate(temp2));
					}
					else {
						out.emplace_back(nullptr);
					}

				}
				return out;
			}, "tempType"_a, "zipFileName"_a, "fileName"_a, "password"_a, py::return_value_policy::take_ownership)
					
			.def_static("loadZipMemEx", [](listItemTemp_type_ nType, const py::bytes& data, 
				const std::wstring& fileName, const std::wstring& password) ->std::vector < XCListItemTemplate*> {
				HTEMP temp1 = NULL;
				HTEMP temp2 = NULL;

				std::vector<XCListItemTemplate*> out;

				if (!XCListItemTemplate::LoadZipMemEx(nType, data, fileName, password, &temp1, &temp2)) {
					out.emplace_back(nullptr);
					out.emplace_back(nullptr);
				}
				else {
					if (temp1) {
						out.emplace_back(new XCListItemTemplate(temp1));
					}
					else {
						out.emplace_back(nullptr);
					}
					if (temp2) {
						out.emplace_back(new XCListItemTemplate(temp2));
					}
					else {
						out.emplace_back(nullptr);
					}

				}
				return out;
			}, "tempType"_a, "data"_a, "fileName"_a, "password"_a, py::return_value_policy::take_ownership)
					
			.def("getType", &XCListItemTemplate::GetType)
			.def("destroy", &XCListItemTemplate::Destroy)

		   	.def_static("clone", [](const XCListItemTemplate& node) -> XCListItemTemplate* {
				auto pTemplate = new XCListItemTemplate();
				if (!pTemplate->Clone(node.getHandle())) {
					return nullptr;
				}
				return pTemplate;
			}, "template"_a, py::return_value_policy::take_ownership)

			.def("addNodeRoot", [](XCListItemTemplate& self, const XCTemplateNode& node){
				return self.AddNodeRoot(node.getHandle());
			}, "node"_a)

			.def("getNode", [](XCListItemTemplate& self, int index) -> XCTemplateNode* {
				auto handle = self.GetNode(index);
				if (!handle) return nullptr;
				return new XCTemplateNode(handle);
			}, "index"_a, py::return_value_policy::take_ownership)

			.def("insertNode", [](XCListItemTemplate& self, int index, const XCTemplateNode& node) {
				return self.InsertNode(index, node.getHandle());
			}, "index"_a, "node"_a)
			.def("deleteNode", &XCListItemTemplate::DeleteNode, "index"_a)
			.def("getCount", &XCListItemTemplate::GetCount)
			.def("moveColumn", &XCListItemTemplate::MoveColumn, "srcColumn"_a, "destColumn"_a)

			.def("getHandle", [](XCListItemTemplate& self) -> uintptr_t {
				return (uintptr_t)self.getHandle();
			})
			
			;

	}
}