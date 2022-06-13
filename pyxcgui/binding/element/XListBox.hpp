							#pragma once
#include "pch.h"
#include "xcgui/element/XCListBox.hpp"
#include "binding/manager/XUserDataManager.hpp"
#include "binding/manager/XCastManager.hpp"
#include "xcgui/XCStruct.hpp"
#include "xcgui/template/XCListItemTemplate.hpp"
#include "xcgui/adapter/XCAdapter.hpp"
#include "xcgui/XCImage.hpp"

namespace xcgui {

	void declareListBox(py::module& m) {

		py::class_<XCListBox, XCScrollView>(m, "XListBox")
			PYCASTOBJECT(XCListBox)
			PYOBJECTVALID(XCListBox, XC_LISTBOX)
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCListBox obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCListBox obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)


			.def("enableFixedRowHeight", &XCListBox::EnableFixedRowHeight, "enable"_a)
			.def("enableTemplateReuse", &XCListBox::EnablemTemplateReuse, "enable"_a)
			.def("enableVirtualTable", &XCListBox::EnableVirtualTable, "enable"_a)
			.def("setVirtualRowCount", &XCListBox::SetVirtualRowCount, "rowCount"_a)
			.def("setDrawItemBkFlags", &XCListBox::SetDrawItemBkFlags, "flags"_a)
			.def("setSplitLineColor", &XCListBox::SetSplitLineColor, "color"_a)
			
			.def("setItemData", [](XCListBox& self, int itemId, const py::object& object) {
				XUserDataManager::GetInstance()->SetItemUserData(self.getEleHandle(), std::to_string(itemId), object);
			}, "itemId"_a, "userdata"_a)

			.def("getItemData", [](XCListBox& self, int itemId) {
				XUserDataManager::GetInstance()->getItemUserData(self.getEleHandle(), std::to_string(itemId));
			}, "itemId"_a)

			.def("setItemInfo", [](XCListBox& self, int iItem, listBox_item_info_& info) {
				self.SetItemInfo(iItem, &info);
			}, "itemId"_a, "itemInfo"_a)

			.def("getItemInfo", [](XCListBox& self, int iItem) {
				listBox_item_info_ info = { 0 };
				self.GetItemInfo(iItem, &info);
				return info;
			}, "itemId"_a)

			.def("setSelectItem", &XCListBox::SetSelectItem, "itemId"_a)
			.def("getSelectItem", &XCListBox::GetSelectItem)
			.def("addSelectItem", &XCListBox::AddSelectItem, "itemId"_a)
			.def("cancelSelectItem", &XCListBox::CancelSelectItem, "itemId"_a)
			.def("cancelSelectAll", &XCListBox::CancelSelectAll)

			.def("getSelectAll", [](XCListBox& self) {
				std::vector<int> out;
				out.resize(self.GetSelectCount());
				auto retSelCount = self.GetSelectAll(&out[0], out.size());
				out.resize(retSelCount);
				return out;
			})
			.def("getSelectCount", &XCListBox::GetSelectCount)
			.def("getItemMouseStay", &XCListBox::GetItemMouseStay)
			.def("selectAll", &XCListBox::SelectAll)
			.def("visibleItem", &XCListBox::VisibleItem, "itemId"_a)
			.def("getVisibleRowRange", [](XCListBox& self) {
				XCRange range;
				self.GetVisibleRowRange(&range.start, &range.end);
				return range;
			})

			.def("setItemHeightDefault", &XCListBox::SetItemHeightDefault, "height"_a, "selHeight"_a)
			.def("getItemHeightDefault", [](XCListBox& self) {
				XCItemHeightInfo info;
				self.GetItemHeightDefault(&info.height, &info.selHeight);
				return info;
			})
			.def("getItemIndexFromUIObject", [](XCListBox& self, const XCWidget& widget) {
				return self.GetItemIndexFromHXCGUI(widget.GetHandle());
			}, "ele"_a)
			.def("setRowSpace", &XCListBox::SetRowSpace, "space"_a)
			.def("getRowSpace", &XCListBox::GetRowSpace)
			.def("hitTest", [](XCListBox& self, const XCPoint& point) {
				return self.HitTest((POINT*)&point);
			}, "point"_a)
			.def("hitTestOffset", [](XCListBox& self, const XCPoint& point) {
				return self.HitTestOffset((POINT*)&point);
			}, "point"_a)

			.def("setItemTemplateXML", &XCListBox::SetItemTemplateXML, "xmlFile"_a)
			.def("setItemTemplate", [](XCListBox& self, const XCListItemTemplate& itemTemplate) {
				return self.SetItemTemplate(itemTemplate.getHandle());
			}, "template"_a)
			.def("setItemTemplateFromMem", [](XCListBox& self, const py::bytes xmlData) {
				return self.SetItemTemplateXMLFromString(xmlData);
			}, "xmlData"_a)
			.def("getTemplateObject", [](XCListBox& self, int itemId, int templateId) -> XCObject* {
				auto handle = self.GetTemplateObject(itemId, templateId);
				return XCastManager::GetInstance()->CastObject(handle);
			},  "itemId"_a, "templateId"_a, py::return_value_policy::take_ownership)


			.def("enableMultiSel", &XCListBox::EnableMultiSel, "enable"_a)
			.def("createAdapter", [](XCListBox& self) -> XCObject* {
				auto handle = self.CreateAdapter();
				return XCastManager::GetInstance()->CastObject(handle);
			}, py::return_value_policy::take_ownership)
			.def("bindAdapter", [](XCListBox& self, const XCAdapter& adapter) {
				self.BindAdapter(adapter.GetHandle());
			}, "adapter"_a)
			.def("getAdapter", [](XCListBox& self) -> XCObject* {
				auto handle = self.GetAdapter();
				return XCastManager::GetInstance()->CastObject(handle);
			}, py::return_value_policy::take_ownership)

			.def("sort", &XCListBox::Sort, "columnAdapter"_a, "ascending"_a)
			.def("refreshData", &XCListBox::RefreshData)
			.def("refreshItem", &XCListBox::RefreshItem, "itemId"_a)

			.def("addItemText", &XCListBox::AddItemText, "text"_a)
			.def("addItemTextEx", &XCListBox::AddItemTextEx, "name"_a, "text"_a)
			
			.def("addItemImage", [](XCListBox& self, const XCImage& image) {
				return self.AddItemImage(image.getImageHandle());
			}, "image"_a)
			.def("addItemImageEx", [](XCListBox& self, const std::wstring& name, const XCImage& image) {
				return self.AddItemImageEx(name, image.getImageHandle());
			}, "name"_a, "image"_a)

			.def("insertItemText", &XCListBox::InsertItemText, "itemId"_a, "text"_a)
			.def("insertItemTextEx", &XCListBox::InsertItemTextEx, "itemId"_a, "name"_a, "text"_a)

			.def("insertItemImage", [](XCListBox& self, int iItem, const XCImage& image) {
				return self.InsertItemImage(iItem, image.getImageHandle());
			}, "itemId"_a, "image"_a)
			.def("insertItemImageEx", [](XCListBox& self, int iItem, const std::wstring& name, const XCImage& image) {
				return self.InsertItemImageEx(iItem, name, image.getImageHandle());
			}, "itemId"_a, "name"_a, "image"_a)

			.def("setItemText", &XCListBox::SetItemText, "itemId"_a, "column"_a, "text"_a)
			.def("setItemTextEx", &XCListBox::SetItemTextEx, "itemId"_a, "name"_a, "text"_a)

			.def("setItemImage", [](XCListBox& self, int iItem, int iColumn, const XCImage& image) {
				return self.SetItemImage(iItem, iColumn, image.getImageHandle());
			}, "itemId"_a, "column"_a, "image"_a)
			.def("setItemImageEx", [](XCListBox& self, int iItem, const std::wstring& name, const XCImage& image) {
				return self.SetItemImageEx(iItem, name, image.getImageHandle());
			}, "itemId"_a, "name"_a, "image"_a)

			.def("setItemInt", &XCListBox::SetItemInt, "itemId"_a, "column"_a, "value"_a)
			.def("setItemIntEx", &XCListBox::SetItemIntEx, "itemId"_a, "name"_a, "value"_a)

			.def("setItemFloat", &XCListBox::SetItemFloat, "itemId"_a, "column"_a, "value"_a)
			.def("setItemFloatEx", &XCListBox::SetItemFloatEx, "itemId"_a, "name"_a, "value"_a)

			.def("getItemText", &XCListBox::GetItemText, "itemId"_a, "column"_a)
			.def("getItemTextEx", &XCListBox::GetItemTextEx, "itemId"_a, "name"_a)
	
			.def("getItemImage", [](XCListBox& self, int iItem, int iColumn) -> XCImage* {
				auto handle = self.GetItemImage(iItem, iColumn);
				if (!handle) return nullptr;
				return new XCImage(handle);

			}, "itemId"_a, "column"_a, py::return_value_policy::take_ownership)

			.def("getItemImageEx", [](XCListBox& self, int iItem, const std::wstring& name) -> XCImage* {
				auto handle = self.GetItemImageEx(iItem, name);
				if (!handle) return nullptr;
				return new XCImage(handle);

			}, "itemId"_a, "name"_a, py::return_value_policy::take_ownership)

			.def("getItemInt", [](XCListBox& self, int iItem, int iColumn) {
				int ret = 0;
				self.GetItemInt(iItem, iColumn, &ret);
				return ret;
			}, "itemId"_a, "column"_a)
			.def("getItemIntEx", [](XCListBox& self, int iItem, const std::wstring& name) {
				int ret = 0;
				self.GetItemIntEx(iItem, name, &ret);
				return ret;
			}, "itemId"_a, "name"_a)

			.def("getItemFloat", [](XCListBox& self, int iItem, int iColumn) {
				float ret = 0;
				self.GetItemFloat(iItem, iColumn, &ret);
				return ret;
			}, "itemId"_a, "column"_a)
			.def("getItemFloatEx", [](XCListBox& self, int iItem, const std::wstring& name) {
				float ret = 0;
				self.GetItemFloatEx(iItem, name, &ret);
				return ret;
			}, "itemId"_a, "name"_a)

			.def("deleteItem", &XCListBox::DeleteItem, "itemId"_a)
			.def("deleteItemEx", &XCListBox::DeleteItemEx, "itemId"_a, "count"_a)
			.def("deleteItemAll", &XCListBox::DeleteItemAll)
			.def("deleteColumnAll", &XCListBox::DeleteColumnAll)
			.def("getCount_AD", &XCListBox::GetCount_AD)
			.def("getCountColumn_AD", &XCListBox::GetCountColumn_AD)
			.def("setDragRectColor", &XCListBox::SetDragRectColor, "color"_a, "width"_a)
			;
	}
}