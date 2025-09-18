#pragma once
#include "pch.h"
#include "xcgui/element/XCListView.hpp"
#include "binding/manager/XUserDataManager.hpp"
#include "binding/manager/XCastManager.hpp"
#include "xcgui/XCStruct.hpp"
#include "xcgui/template/XCListItemTemplate.hpp"
#include "xcgui/adapter/XCAdapter.hpp"
#include "xcgui/XCImage.hpp"
#include "xcgui/utils/String.hpp"

namespace xcgui {

	void declareListView(py::module& m) {

		py::class_<XCListView, XCScrollView>(m, "XListView")
			PYCASTOBJECT(XCListView)
			PYOBJECTVALID(XCListView, XC_LISTVIEW)
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCListView obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent, int flags) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				auto eleHandle = XListView_CreateEx(x, y, cx, cy, handle, flags);
				XCListView obj;
				obj.SetHandle(eleHandle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a, "flags"_a)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCListView obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)

			.def("createAdapter", [](XCListView& self) -> XCObject* {
				auto handle = self.CreateAdapter();
				return XCastManager::GetInstance()->CastObject(handle);
			}, py::return_value_policy::take_ownership)
			.def("bindAdapter", [](XCListView& self, const XCAdapter& adapter) {
				self.BindAdapter(adapter.GetHandle());
			}, "adapter"_a)
			.def("getAdapter", [](XCListView& self) -> XCObject* {
				auto handle = self.GetAdapter();
				return XCastManager::GetInstance()->CastObject(handle);
			}, py::return_value_policy::take_ownership)


			.def("setItemTemplateXML", &XCListView::SetItemTemplateXML, "xmlFile"_a)

			// 3.3.8 新增
			.def("setItemTemplateXMLFromMem", [](XCListView& self, const std::string& xmlData) {
				return XListView_SetItemTemplateXMLFromMem(self.getEleHandle(), xmlData.c_str());
			}, "xmlData"_a)
			.def("setItemTemplateXMLFromZipRes", [](XCListView& self, int id, const std::wstring& fileName, const std::wstring& password = L"", uintptr_t hModule = 0) {
				const wchar_t* pPassword = password.empty() ? NULL : password.c_str();
				return XListView_SetItemTemplateXMLFromZipRes(self.getEleHandle(), id, fileName.c_str(), pPassword, (HMODULE)hModule);
			}, "id"_a, "fileName"_a, "password"_a = L"", "hModule"_a = 0)
			.def("getItemTemplate", [](XCListView& self) -> XCListItemTemplate* {
				auto handle = XListView_GetItemTemplate(self.getEleHandle());
				if (!handle) return nullptr;
				auto pTemplate = new XCListItemTemplate(handle);
				return pTemplate;
			}, py::return_value_policy::take_ownership)
			.def("getItemTemplateGroup", [](XCListView& self) -> XCListItemTemplate* {
				auto handle = XListView_GetItemTemplateGroup(self.getEleHandle());
				if (!handle) return nullptr;
				auto pTemplate = new XCListItemTemplate(handle);
				return pTemplate;
			}, py::return_value_policy::take_ownership)

			.def("setItemTemplate", [](XCListView& self, const XCListItemTemplate& itemTemplate) {
				return self.SetItemTemplate(itemTemplate.getHandle());
			}, "template"_a)
			.def("setItemTemplateFromMem", [](XCListView& self, const py::bytes xmlData) {
				return self.SetItemTemplateXMLFromString(xmlData);
			}, "xmlData"_a)
			.def("getTemplateObject", [](XCListView& self, int groupId, int itemId, int templateId) -> XCObject* {
				auto handle = self.GetTemplateObject(groupId, itemId, templateId);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "groupId"_a, "itemId"_a, "templateId"_a, py::return_value_policy::take_ownership)

			.def("getTemplateObjectGroup", [](XCListView& self, int groupId, int itemId) -> XCObject* {
				auto handle = self.GetTemplateObjectGroup(groupId, itemId);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "groupId"_a, "itemId"_a, py::return_value_policy::take_ownership)

			.def("getItemIdFromUIObject", [](XCListView& self, const XCWidget& widget) {
				listView_item_id_ info = {0};
				self.GetItemIDFromHXCGUI(widget.GetHandle(), &info.iGroup, &info.iItem);
				return info;
			}, "ele"_a)

			.def("hitTest", [](XCListView& self, const XCPoint& point) {
				listView_item_id_ info = { 0 };
				self.HitTest((POINT*)&point, &info.iGroup, &info.iItem);
				return info;
			}, "point"_a)
			.def("hitTestOffset", [](XCListView& self, const XCPoint& point) {
				listView_item_id_ info = { 0 };
				self.HitTestOffset((POINT*)&point, &info.iGroup, &info.iItem);
				return info;
			}, "point"_a)

			.def("enableMultiSel", &XCListView::EnableMultiSel, "enable"_a)
			.def("enableTemplateReuse", &XCListView::EnableTemplateReuse, "enable"_a)
			.def("enableVirtualTable", &XCListView::EnableVirtualTable, "enable"_a)
			.def("setVirtualItemCount", &XCListView::SetVirtualItemCount, "group"_a, "count"_a)
			.def("setDrawItemBkFlags", &XCListView::SetDrawItemBkFlags, "flags"_a)
			
			.def("setSelectItem", &XCListView::SetSelectItem, "group"_a, "item"_a)
			.def("getSelectItem", [](XCListView& self) {
				listView_item_id_ info = {0};
				self.GetSelectItem(&info.iGroup, &info.iItem);
				return info;
			})

			.def("addSelectItem", &XCListView::AddSelectItem, "group"_a, "item"_a)
			.def("visibleItem", &XCListView::VisibleItem, "group"_a, "item"_a)
			.def("getVisibleItemRange", [](XCListView& self) {
				XCListViewItemRangeInfo info = {0};
				self.GetVisibleItemRange(&info.group1, &info.group2, 
					&info.startGroup, &info.startItem, 
					&info.endGroup, &info.endItem);
				return info;
			})	
			.def("getSelectItemCount", &XCListView::GetSelectItemCount)
			.def("getSelectAll", [](XCListView& self) {
				std::vector<listView_item_id_> out;
				out.resize(self.GetSelectItemCount());
				auto retSelCount = self.GetSelectAll(&out[0], out.size());
				out.resize(retSelCount);
				return out;
			})
			.def("cancelSelectAll", &XCListView::CancelSelectAll)
			.def("setColumnSpace", &XCListView::SetColumnSpace, "space"_a)		
			.def("setRowSpace", &XCListView::SetRowSpace, "space"_a)

			.def("setItemSize", &XCListView::SetItemSize, "width"_a, "height"_a)
			.def("getItemSize", [](XCListView& self) {
				XCSize info;
				self.GetItemSize((SIZE*)&info);
				return info;
			})
			.def("setGroupHeight", &XCListView::SetGroupHeight, "height"_a)
			.def("getGroupHeight", &XCListView::GetGroupHeight)

			.def("setGroupUserData", [](XCListView& self, int groupId, const py::object& object) {
				XUserDataManager::GetInstance()->SetItemUserData(self.getEleHandle(), std::to_string(groupId), object);
			}, "group"_a, "userdata"_a)

			.def("getGroupUserData", [](XCListView& self, int groupId) {
				XUserDataManager::GetInstance()->getItemUserData(self.getEleHandle(), std::to_string(groupId));
			}, "group"_a)

			.def("setItemUserData", [](XCListView& self, int group, int item, const py::object& object) {
				XUserDataManager::GetInstance()->SetItemUserData(self.getEleHandle(), 
					vformat("%d_%d", group,  item), 
					object);
			}, "group"_a, "item"_a, "userdata"_a)

			.def("getItemUserData", [](XCListView& self, int group, int item) {
				XUserDataManager::GetInstance()->getItemUserData(self.getEleHandle(), vformat("%d_%d", group, item));
			}, "group"_a, "item"_a)

			.def("refreshData", &XCListView::RefreshData)
			.def("refreshItem", &XCListView::RefreshItem, "group"_a, "item"_a)
			.def("expandGroup", &XCListView::ExpandGroup, "group"_a, "expand"_a)

			.def("groupAddColumn", &XCListView::Group_AddColumn, "name"_a)
			.def("groupAddItemText", &XCListView::Group_AddItemText, "text"_a, "pos"_a=-1)
			.def("groupAddItemTextEx", &XCListView::Group_AddItemTextEx, "name"_a, "text"_a, "pos"_a=-1)
			
			.def("groupAddItemImage", [](XCListView& self, const XCImage& image, int pos=-1) {
				return self.Group_AddItemImage(image.getImageHandle(), pos);
			}, "image"_a, "pos"_a=-1)
			.def("groupAddItemImageEx", [](XCListView& self, const std::wstring& name, const XCImage& image, int pos = -1) {
				return self.Group_AddItemImageEx(name, image.getImageHandle(), pos);
			}, "name"_a, "image"_a, "pos"_a=-1)
			
			.def("groupSetText", &XCListView::Group_SetText, "group"_a, "column"_a, "text"_a)
			.def("groupSetTextEx", &XCListView::Group_SetTextEx, "group"_a, "name"_a, "text"_a)
			.def("groupSetImage", [](XCListView& self, int group, int column, const XCImage& image) {
				return self.Group_SetImage(group, column, image.getImageHandle());
			}, "group"_a, "column"_a, "image"_a)
			.def("groupSetImageEx", [](XCListView& self, int group, const std::wstring& name, const XCImage& image) {
				return self.Group_SetImageEx(group, name, image.getImageHandle());
			}, "group"_a, "name"_a, "image"_a)
			
			.def("groupGetText", &XCListView::Group_GetText, "group"_a, "column"_a)
			.def("groupGetTextEx", &XCListView::Group_GetTextEx, "group"_a, "name"_a)
			.def("groupGetImage", [](XCListView& self, int group, int iColumn) -> XCImage* {
				auto handle = self.Group_GetImage(group, iColumn);
				if (!handle) return nullptr;
				return new XCImage(handle);

			}, "group"_a, "column"_a, py::return_value_policy::take_ownership)
			.def("groupGetImageEx", [](XCListView& self, int group, const std::wstring& name) -> XCImage* {
				auto handle = self.Group_GetImageEx(group, name);
				if (!handle) return nullptr;
				return new XCImage(handle);
			}, "group"_a, "name"_a, py::return_value_policy::take_ownership)

			.def("groupGetCount", &XCListView::Group_GetCount)
			.def("itemGetCount", &XCListView::Item_GetCount, "group"_a)
			.def("itemAddColumn", &XCListView::Item_AddColumn, "name"_a)
			
			.def("itemAddItemText", &XCListView::Item_AddItemText, "group"_a, "text"_a, "pos"_a=-1)
			.def("itemAddItemTextEx", &XCListView::Item_AddItemTextEx, "group"_a, "name"_a, "text"_a, "pos"_a =-1)

			.def("itemAddItemImage", [](XCListView& self, int group, const XCImage& image, int pos=-1) {
				return self.Item_AddItemImage(group, image.getImageHandle(), pos);
			}, "group"_a, "image"_a, "pos"_a=-1)
			.def("itemAddItemImageEx", [](XCListView& self, int group, const std::wstring& name, const XCImage& image, int pos = -1) {
				return self.Item_AddItemImageEx(group, name, image.getImageHandle(), pos);
			}, "group"_a, "name"_a, "image"_a, "pos"_a=-1)

			.def("itemSetText", &XCListView::Item_SetText, "group"_a, "item"_a, "column"_a, "text"_a)
			.def("itemSetTextEx", &XCListView::Item_SetTextEx, "group"_a, "item"_a, "name"_a, "text"_a)

			.def("itemSetImage", [](XCListView& self, int group, int item, int column, const XCImage& image) {
				return self.Item_SetImage(group, item, column, image.getImageHandle());
			}, "group"_a, "item"_a, "column"_a, "image"_a)
			.def("itemSetImageEx", [](XCListView& self, int group, int item, const std::wstring& name, const XCImage& image) {
				return self.Item_SetImageEx(group, item, name, image.getImageHandle());
			}, "group"_a, "item"_a, "name"_a, "image"_a)

			.def("itemGetText", &XCListView::Item_GetText, "group"_a, "item"_a, "column"_a)
			.def("itemGetTextEx", &XCListView::Item_GetTextEx, "group"_a, "item"_a, "name"_a)

			.def("itemGetImage", [](XCListView& self, int group, int item, int iColumn) -> XCImage* {
				auto handle = self.Item_GetImage(group, item, iColumn);
				if (!handle) return nullptr;
				return new XCImage(handle);

			}, "group"_a, "item"_a, "column"_a, py::return_value_policy::take_ownership)
			.def("itemGetImageEx", [](XCListView& self, int group, int item, const std::wstring& name) -> XCImage* {
				auto handle = self.Item_GetImageEx(group, item, name);
				if (!handle) return nullptr;
				return new XCImage(handle);
			}, "group"_a, "item"_a, "name"_a, py::return_value_policy::take_ownership)

			.def("groupDeleteItem", &XCListView::Group_DeleteItem, "group"_a)
			.def("groupDeleteAllChildItem", &XCListView::Group_DeleteAllChildItem, "group"_a)
			.def("itemDeleteItem", &XCListView::Item_DeleteItem, "group"_a, "item"_a)
			.def("deleteAll", &XCListView::DeleteAll)
			.def("deleteAllGroup", &XCListView::DeleteAllGroup)
			.def("deleteAllItem", &XCListView::DeleteAllItem)
			.def("deleteColumnGroup", &XCListView::DeleteColumnGroup, "column"_a)
			.def("deleteColumnItem", &XCListView::DeleteColumnItem, "column"_a)
			.def("setDragRectColor", &XCListView::SetDragRectColor, "color"_a, "width"_a)
			;
	}
}