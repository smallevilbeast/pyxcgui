				 #pragma once
#include "pch.h"
#include "xcgui/template/XListItemTemplate.hpp"

namespace xcgui {

	void declareTemplate(py::module& m) {
		py::class_<XCTemplateNode>(m, "XTemplateNode")
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

			.def("getHandle", [](XCListItemTemplate& self) -> uintptr_t {
				return (uintptr_t)self.getHandle();
			})
			
			;

	}
}