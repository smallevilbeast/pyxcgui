#pragma once
#include "pch.h"
#include "xcgui/element/XCComboBox.hpp"
#include "xcgui/XCImage.hpp"
#include "binding/manager/XCastManager.hpp"

namespace xcgui {

	void declareComboBox(py::module& m) {
		py::class_<XCComboBox, XCEdit>(m, "XComboBox")
			PYCASTOBJECT(XCComboBox)
			PYOBJECTVALID(XCComboBox, XC_COMBOBOX)
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCComboBox box(x, y, cx, cy, handle);
				return box;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a=nullptr)

			.def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCComboBox box(0,0, cx, cy, handle);
				return box;
			}), "width"_a, "height"_a, "parent"_a=nullptr)

			.def("setSelItem", &XCComboBox::SetSelItem, "index"_a)
			.def("createAdapter", [](XCComboBox& self) -> XCObject* {
				auto handle = self.CreateAdapter();
				return XCastManager::GetInstance()->CastObject(handle);
			}, py::return_value_policy::take_ownership)
			.def("bindAdapter", [](XCComboBox& self, const XCAdapter& adapter) {
				self.BindAdapter(adapter.GetHandle());
			}, "adapter"_a)

			.def("getAdapter", [](XCComboBox& self) -> XCObject* {
				auto handle = self.GetAdapter();
				return XCastManager::GetInstance()->CastObject(handle);
			}, py::return_value_policy::take_ownership)

			.def("setBindName", &XCComboBox::SetBindName, "name"_a)
			.def("getButtonRect", [](XCComboBox& self) -> XCRect {
					XCRect rect;
					self.GetButtonRect((RECT*)&rect);
					return rect;
			})
			.def("setButtonSize", &XCComboBox::SetButtonSize, "size"_a)
			.def("setDropHeight", &XCComboBox::SetDropHeight, "height"_a)
			.def("getDropHeight", &XCComboBox::GetDropHeight)
			.def("setItemTemplateXML", &XCComboBox::SetItemTemplateXML, "xml"_a)
			.def("setItemTemplate", [](XCComboBox& self, const XCListItemTemplate& itemTemplate) {
				return self.SetItemTemplate(itemTemplate.getHandle());
			}, "template"_a)
			
			.def("enableDrawButton", &XCComboBox::EnableDrawButton, "enable"_a)
			.def("enableEdit", &XCComboBox::EnableEdit, "enable"_a)
			.def("enableDropHeightFixed", &XCComboBox::EnableDropHeightFixed, "enable"_a)
			.def("popupDropList", &XCComboBox::PopupDropList)
			.def("getSelItem", &XCComboBox::GetSelItem)
			.def("getState", &XCComboBox::GetState)
			.def("addItemText", &XCComboBox::AddItemText, "text"_a)
			.def("addItemTextEx", &XCComboBox::AddItemTextEx, "name"_a, "text"_a)

			.def("addItemImage", [](XCComboBox& self, const XCImage& image) {
				return self.AddItemImage(image.getImageHandle());
			}, "image"_a)
			.def("addItemImageEx", [](XCComboBox& self, const std::wstring& name, const XCImage& image) {
				return self.AddItemImageEx(name, image.getImageHandle());
			}, "name"_a, "image"_a)


			.def("insertItemText", &XCComboBox::InsertItemText, "item"_a, "text"_a)
			.def("insertItemTextEx", &XCComboBox::InsertItemTextEx, "item"_a, "name"_a, "text"_a)

			.def("insertItemImage", [](XCComboBox& self, int iItem, const XCImage& image) {
				return self.InsertItemImage(iItem, image.getImageHandle());
			}, "item"_a, "image"_a)
			.def("insertItemImageEx", [](XCComboBox& self, int iItem, const std::wstring& name, const XCImage& image) {
				return self.InsertItemImageEx(iItem, name, image.getImageHandle());
			}, "item"_a, "name"_a, "image"_a)

			.def("setItemText", &XCComboBox::SetItemText, "item"_a, "column"_a, "text"_a)
			.def("setItemTextEx", &XCComboBox::SetItemTextEx, "item"_a, "name"_a, "text"_a)

			.def("setItemImage", [](XCComboBox& self, int iItem, int iColumn, const XCImage& image) {
				return self.SetItemImage(iItem, iColumn, image.getImageHandle());
			}, "item"_a, "column"_a, "image"_a)
			.def("setItemImageEx", [](XCComboBox& self, int iItem, const std::wstring& name, const XCImage& image) {
				return self.SetItemImageEx(iItem, name, image.getImageHandle());
			}, "item"_a, "name"_a, "image"_a)

			.def("setItemInt", &XCComboBox::SetItemInt, "item"_a, "column"_a, "value"_a)
			.def("setItemIntEx", &XCComboBox::SetItemIntEx, "item"_a, "name"_a, "value"_a)

			.def("setItemFloat", &XCComboBox::SetItemFloat, "item"_a, "column"_a, "value"_a)
			.def("setItemFloatEx", &XCComboBox::SetItemFloatEx, "item"_a, "name"_a, "value"_a)

			.def("getItemText", &XCComboBox::GetItemText, "item"_a, "column"_a)
			.def("getItemTextEx", &XCComboBox::GetItemTextEx, "item"_a, "name"_a)

			.def("getItemImage", [](XCComboBox& self, int row, int iColumn) -> XCImage* {
				auto handle = self.GetItemImage(row, iColumn);
				if (!handle) return nullptr;
				return new XCImage(handle);

			}, "item"_a, "column"_a, py::return_value_policy::take_ownership)

			.def("getItemImageEx", [](XCComboBox& self, int row, const std::wstring& name) -> XCImage* {
				auto handle = self.GetItemImageEx(row, name);
				if (!handle) return nullptr;
				return new XCImage(handle);

			}, "item"_a, "name"_a, py::return_value_policy::take_ownership)


			.def("getItemInt", [](XCComboBox& self, int row, int iColumn) {
				int ret = 0;
				self.GetItemInt(row, iColumn, &ret);
				return ret;
			}, "item"_a, "column"_a)
			.def("getItemIntEx", [](XCComboBox& self, int row, const std::wstring& name) {
				int ret = 0;
				self.GetItemIntEx(row, name, &ret);
				return ret;
			}, "item"_a, "name"_a)

			.def("getItemFloat", [](XCComboBox& self, int row, int iColumn) {
				float ret = 0;
				self.GetItemFloat(row, iColumn, &ret);
				return ret;
			}, "item"_a, "column"_a)
			.def("getItemFloatEx", [](XCComboBox& self, int row, const std::wstring& name) {
				float ret = 0;
				self.GetItemFloatEx(row, name, &ret);
				return ret;
			}, "item"_a, "name"_a)
				
			
			.def("deleteItem", &XCComboBox::DeleteItem, "item"_a)
			.def("deleteItemEx", &XCComboBox::DeleteItemEx, "item"_a, "count"_a)
			.def("deleteItemAll", &XCComboBox::DeleteItemAll)
			.def("deleteColumnAll", &XCComboBox::DeleteColumnAll)
			.def("getCount", &XCComboBox::GetCount)
			.def("getCountColumn", &XCComboBox::GetCountColumn);
	}
}