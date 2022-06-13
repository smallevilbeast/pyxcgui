						 #pragma once
#include "pch.h"
#include "xcgui/adapter/XCAdapterTable.hpp"
#include "xcgui/XCImage.hpp"

namespace xcgui {

	void declareAdapterTable(py::module& m) {

		py::class_<XCAdapterTable, XCAdapter>(m, "XAdapterTable")
			PYCASTOBJECT(XCAdapterTable)
			PYOBJECTVALID(XCAdapterTable, XC_ADAPTER_TABLE)
			.def(py::init<>())
			.def("sort", &XCAdapterTable::Sort, "column"_a, "ascending"_a)
			.def("getItemDataType", &XCAdapterTable::GetItemDataType, "item"_a, "column"_a)
			.def("getItemDataTypeEx", &XCAdapterTable::GetItemDataTypeEx, "item"_a, "name"_a)

			.def("addColumn", &XCAdapterTable::AddColumn, "name"_a)
			.def("setColumn", &XCAdapterTable::SetColumn, "colName"_a)

			.def("addItemText", &XCAdapterTable::AddItemText, "value"_a)
			.def("addItemTextEx", &XCAdapterTable::AddItemTextEx, "name"_a, "value"_a)


			.def("addItemImage", [](XCAdapterTable& self, const XCImage& image) {
				return self.AddItemImage(image.getImageHandle());
			}, "image"_a)


		   .def("addItemImageEx", [](XCAdapterTable& self, const std::wstring& name, const XCImage& image) 
			{
				return self.AddItemImageEx(name, image.getImageHandle());
			}, "name"_a, "image"_a)

			.def("insertItemText", &XCAdapterTable::InsertItemText, "item"_a, "value"_a)
			.def("insertItemTextEx", &XCAdapterTable::InsertItemTextEx, "item"_a, "name"_a, "value"_a)
			
			.def("insertItemImage", [](XCAdapterTable& self, int item, const XCImage& image){
				return self.InsertItemImage(item, image.getImageHandle());
			}, "item"_a, "image"_a)
			 .def("insertItemImageEx", [](XCAdapterTable& self, int item, const std::wstring& name, const XCImage& image){
				return self.InsertItemImageEx(item, name, image.getImageHandle());
			}, "item"_a, "name"_a, "image"_a)

			.def("setItemText", &XCAdapterTable::SetItemText, "item"_a, "column"_a, "value"_a)
			.def("setItemTextEx", &XCAdapterTable::SetItemTextEx, "item"_a, "name"_a, "value"_a)
			
			.def("setItemInt", &XCAdapterTable::SetItemInt, "item"_a, "column"_a, "value"_a)
			.def("setItemIntEx", &XCAdapterTable::SetItemIntEx, "item"_a, "name"_a, "value"_a)
			
			.def("setItemFloat", &XCAdapterTable::SetItemFloat, "item"_a, "column"_a, "value"_a)
			.def("setItemFloatEx", &XCAdapterTable::SetItemFloatEx, "item"_a, "name"_a, "value"_a)

			.def("setItemImage", [](XCAdapterTable& self, int item, int iColumn, const XCImage& image){
				return self.SetItemImage(item, iColumn, image.getImageHandle());
			}, "item"_a, "column"_a, "image"_a)
			.def("setItemImageEx", [](XCAdapterTable& self, int item, const std::wstring& name, const XCImage& image){
				return self.SetItemImageEx(item, name, image.getImageHandle());
			}, "item"_a, "name"_a, "image"_a)

			.def("deleteItem", &XCAdapterTable::DeleteItem, "item"_a)
			.def("deleteItemEx", &XCAdapterTable::DeleteItemEx, "item"_a, "count"_a)
			.def("deleteItemAll", &XCAdapterTable::DeleteItemAll)
			.def("deleteColumnAll", &XCAdapterTable::DeleteColumnAll)
			
			.def("getCount", &XCAdapterTable::GetCount)
			.def("getCountColumn", &XCAdapterTable::GetCountColumn)

			.def("getItemText", &XCAdapterTable::GetItemText, "item"_a, "column"_a)
			.def("getItemTextEx", &XCAdapterTable::GetItemTextEx, "item"_a, "name"_a)
			
			.def("getItemImage", [](XCAdapterTable& self,  int item, int column) -> XCImage* {
				auto handle = self.GetItemImage(item, column);
				if (!handle) return nullptr;
				return new XCImage(handle);
			}, "item"_a, "column"_a, py::return_value_policy::take_ownership)
			.def("getItemImageEx", [](XCAdapterTable& self,  int item, const std::wstring& name) -> XCImage* {
				auto handle = self.GetItemImageEx(item, name);
				if (!handle) return nullptr;
				return new XCImage(handle);
			}, "item"_a, "name"_a, py::return_value_policy::take_ownership)

			.def("getItemInt", [](XCAdapterTable& self,  int item, int column) {
				int value = -1;
				self.GetItemInt(item, column, &value);
				return value;
			}, "item"_a, "column"_a)

			.def("getItemIntEx", [](XCAdapterTable& self,  int item, const std::wstring& name) {
				int value = -1;
				self.GetItemIntEx(item, name, &value);
				return value;
			}, "item"_a, "name"_a)

			.def("getItemFloat", [](XCAdapterTable& self,  int item, int column) {
				float value = -1;
				self.GetItemFloat(item, column, &value);
				return value;
			}, "item"_a, "column"_a)

			.def("getItemFloatEx", [](XCAdapterTable& self,  int item, const std::wstring& name) {
				float value = -1;
				self.GetItemFloatEx(item, name, &value);
				return value;
			}, "item"_a, "name"_a)			
		;
	}
}