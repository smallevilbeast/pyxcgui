#pragma once
#include "pch.h"
#include "xcgui/adapter/XCAdapterTree.hpp"
#include "xcgui/XCImage.hpp"

namespace xcgui {

	void declareAdapterTree(py::module& m) {

		py::class_<XCAdapterTree, XCAdapter>(m, "XAdapterTree")
			.def(py::init<>())
			.def("addColumn", &XCAdapterTree::AddColumn, "name"_a)
			.def("setColumn", &XCAdapterTree::SetColumn, "colName"_a)
			
			.def("insertItemText", &XCAdapterTree::InsertItemText, "value"_a, "parentId"_a =XC_ID_ROOT, "insertId"_a=XC_ID_LAST)
			.def("insertItemTextEx", &XCAdapterTree::InsertItemTextEx, "name"_a, 
				"value"_a, "parentId"_a =XC_ID_ROOT, "insertId"_a=XC_ID_LAST)
			
			
			.def("insertItemImage", [](XCAdapterTree& self, const XCImage& image, 
				int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST) 
			{
				return self.InsertItemImage(image.getImageHandle(), nParentID, insertID);
			}, "image"_a, "parentId"_a = XC_ID_ROOT, "insertId"_a = XC_ID_LAST)

		   .def("insertItemImageEx", [](XCAdapterTree& self, const std::wstring& name, const XCImage& image,
				int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST) 
			{
				return self.InsertItemImageEx(name, image.getImageHandle(), nParentID, insertID);
			}, "name"_a, "image"_a, "parentId"_a = XC_ID_ROOT, "insertId"_a = XC_ID_LAST)

			.def("getCount", &XCAdapterTree::GetCount)
			.def("getCountColumn", &XCAdapterTree::GetCountColumn)
			
			.def("setItemText", &XCAdapterTree::SetItemText, "nId"_a, "column"_a, "value"_a)
			.def("setItemTextEx", &XCAdapterTree::SetItemTextEx, "nId"_a, "name"_a, "value"_a)
			
			.def("setItemImage", [](XCAdapterTree& self, int nID, int iColumn, const XCImage& image){
				return self.SetItemImage(nID, iColumn, image.getImageHandle());
			}, "nId"_a, "column"_a, "image"_a)

			.def("setItemImageEx", [](XCAdapterTree& self, int nID, const std::wstring& name, const XCImage& image){
				return self.SetItemImageEx(nID, name, image.getImageHandle());
			}, "nId"_a, "name"_a, "image"_a)

			.def("getItemText", &XCAdapterTree::GetItemText, "nId"_a, "column"_a)
			.def("getItemTextEx", &XCAdapterTree::GetItemTextEx, "nId"_a, "name"_a)
			
			.def("getItemImage", [](XCAdapterTree& self,  int nId, int column) -> XCImage* {
				auto handle = self.GetItemImage(nId, column);
				if (!handle) return nullptr;
				return new XCImage(handle);
			}, "nId"_a, "column"_a, py::return_value_policy::take_ownership)

			.def("getItemImageEx", [](XCAdapterTree& self,  int nId, const std::wstring& name) {
				return self.GetItemImageEx(nId, name);
			}, "nId"_a, "name"_a)

			.def("deleteItem", &XCAdapterTree::DeleteItem, "nId"_a)
			.def("deleteItemAll", &XCAdapterTree::DeleteItemAll)
			.def("deleteColumnAll", &XCAdapterTree::DeleteColumnAll)			
		;
	}
}