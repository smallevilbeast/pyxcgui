#pragma once
#include "pch.h"
#include "xcgui/element/XCTree.hpp"
#include "binding/manager/XUserDataManager.hpp"
#include "binding/manager/XCastManager.hpp"
#include "xcgui/XCStruct.hpp"
#include "xcgui/template/XCListItemTemplate.hpp"
#include "xcgui/adapter/XCAdapter.hpp"
#include "xcgui/XCImage.hpp"
#include "xcgui/utils/String.hpp"

namespace xcgui {

	void declareTree(py::module& m) {

		py::class_<XCTree, XCScrollView>(m, "XTree")
			PYCASTOBJECT(XCTree)
			PYOBJECTVALID(XCTree, XC_TREE)
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCTree obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCTree obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)


			.def("enableDragItem", &XCTree::EnableDragItem, "enable"_a)
			.def("enableConnectLine", &XCTree::EnableConnectLine, "enable"_a, "solid"_a)
			.def("enableExpand", &XCTree::EnableExpand, "enable"_a)
			.def("enableTemplateReuse", &XCTree::EnableTemplateReuse, "enable"_a)
			.def("setConnectLineColor", &XCTree::SetConnectLineColor, "color"_a)

			
			.def("setExpandButtonSize", &XCTree::SetExpandButtonSize, "width"_a, "height"_a)
			.def("setConnectLineLength", &XCTree::SetConnectLineLength, "length"_a)
			.def("setDragInsertPositionColor", &XCTree::SetDragInsertPositionColor, "color"_a)

			
			.def("setItemTemplateXML", &XCTree::SetItemTemplateXML, "xmlFile"_a)
			.def("setItemTemplateXMLSel", &XCTree::SetItemTemplateXMLSel, "xmlFile"_a)

			.def("setItemTemplate", [](XCTree& self, const XCListItemTemplate& itemTemplate) {
				return self.SetItemTemplate(itemTemplate.getHandle());
			}, "template"_a)
			.def("setItemTemplateSel", [](XCTree& self, const XCListItemTemplate& itemTemplate) {
				return self.SetItemTemplateSel(itemTemplate.getHandle());
			}, "template"_a)

			.def("setItemTemplateXMLFromMem", [](XCTree& self, const py::bytes xmlData) {
				return self.SetItemTemplateXMLFromString(xmlData);
			}, "xmlData"_a)
			.def("setItemTemplateSelXMLFromMem", [](XCTree& self, const py::bytes xmlData) {
				return self.SetItemTemplateXMLSelFromString(xmlData);
			}, "xmlData"_a)

			.def("getTemplateObject", [](XCTree& self, int itemId, int templateId) -> XCObject* {
				auto handle = self.GetTemplateObject(itemId, templateId);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "itemId"_a, "templateId"_a, py::return_value_policy::take_ownership)

			.def("getItemIdFromUIObject", [](XCTree& self, const XCWidget& widget) {
				return self.GetItemIDFromHXCGUI(widget.GetHandle());
			}, "ele"_a)


			.def("setDrawItemBkFlags", &XCTree::SetDrawItemBkFlags, "flags"_a)
			.def("setSplitLineColor", &XCTree::SetSplitLineColor, "color"_a)

			.def("setItemData", [](XCTree& self, int itemId, const py::object& object) {
				XUserDataManager::GetInstance()->SetItemUserData(self.getEleHandle(), std::to_string(itemId), object);
			}, "itemId"_a, "userdata"_a)
			.def("getItemData", [](XCTree& self, int itemId) {
				XUserDataManager::GetInstance()->getItemUserData(self.getEleHandle(), std::to_string(itemId));
			}, "itemId"_a)

			.def("setSelectItem", &XCTree::SetSelectItem, "itemId"_a)
			.def("getSelectItem", &XCTree::GetSelectItem)
			.def("isExpand", &XCTree::IsExpand, "itemId"_a)
			.def("expandItem", &XCTree::ExpandItem, "itemId"_a, "expand"_a)
			.def("expandAllChildItem", &XCTree::ExpandAllChildItem, "itemId"_a, "expand"_a)

			.def("hitTest", [](XCTree& self, const XCPoint& point) {
				return self.HitTest((POINT*)&point);
			}, "point"_a)
			.def("hitTestOffset", [](XCTree& self, const XCPoint& point) {
				return self.HitTestOffset((POINT*)&point);
			}, "point"_a)

			.def("getFirstChildItem", &XCTree::SetSelectItem, "itemId"_a)
			.def("getEndChildItem", &XCTree::GetEndChildItem, "itemId"_a)
			.def("getPrevSiblingItem", &XCTree::GetPrevSiblingItem, "itemId"_a)
			.def("getNextSiblingItem", &XCTree::GetNextSiblingItem, "itemId"_a)
			.def("getParentItem", &XCTree::GetParentItem, "itemId"_a)

			.def("createAdapter", [](XCTree& self) -> XCObject* {
				auto handle = self.CreateAdapter();
				return XCastManager::GetInstance()->CastObject(handle);
			}, py::return_value_policy::take_ownership)
			.def("bindAdapter", [](XCTree& self, const XCAdapter& adapter) {
				self.BindAdapter(adapter.GetHandle());
			}, "adapter"_a)
			.def("getAdapter", [](XCTree& self) -> XCObject* {
				auto handle = self.GetAdapter();
				return XCastManager::GetInstance()->CastObject(handle);
			}, py::return_value_policy::take_ownership)

			.def("refreshData", &XCTree::RefreshData)
			.def("refreshItem", &XCTree::RefreshItem, "itemId"_a)

			.def("setIndentation", &XCTree::SetIndentation, "width"_a)
			.def("getIndentation", &XCTree::GetIndentation)

			.def("setItemHeightDefault", &XCTree::SetItemHeightDefault, "height"_a, "selHeight"_a)
			.def("getItemHeightDefault", [](XCTree& self) {
				XCItemHeightInfo info;
				self.GetItemHeightDefault(&info.height, &info.selHeight);
				return info;
			})

			.def("setItemHeight", &XCTree::SetItemHeight, "itemId"_a, "height"_a, "selHeight"_a)
			.def("getItemHeight", [](XCTree& self, int itemId) {
				XCItemHeightInfo info;
				self.GetItemHeight(itemId, &info.height, &info.selHeight);
				return info;
			}, "itemId"_a)

					
			.def("setRowSpace", &XCTree::SetRowSpace, "space"_a)
			.def("getRowSpace", &XCTree::GetRowSpace)
			.def("moveItem", &XCTree::MoveItem, "srcItemId"_a, "destItemId"_a, "flag"_a)


			.def("insertItemText", &XCTree::InsertItemText, "text"_a, "parentId"_a=XC_ID_ROOT, "insertId"_a=XC_ID_LAST)
			.def("insertItemTextEx", &XCTree::InsertItemTextEx, "name"_a, "text"_a, "parentId"_a = XC_ID_ROOT, "insertId"_a = XC_ID_LAST)

			.def("insertItemImage", [](XCTree& self, const XCImage& image, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST) {
				return self.InsertItemImage(image.getImageHandle(), nParentID, insertID);
			}, "image"_a, "parentId"_a = XC_ID_ROOT, "insertId"_a = XC_ID_LAST)
			.def("insertItemImageEx", [](XCTree& self, const std::wstring& name, const XCImage& image, 
				int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST) {
				return self.InsertItemImageEx(name, image.getImageHandle(), nParentID, insertID);
			}, "name"_a, "image"_a, "parentId"_a = XC_ID_ROOT, "insertId"_a = XC_ID_LAST)

			
			.def("getCount", &XCTree::GetCount)
			.def("getCountColumn", &XCTree::GetCountColumn)


			.def("setItemText", &XCTree::SetItemText, "itemId"_a, "column"_a, "text"_a)
			.def("setItemTextEx", &XCTree::SetItemTextEx, "itemId"_a, "name"_a, "text"_a)

			.def("setItemImage", [](XCTree& self, int nID, int iColumn, const XCImage& image) {
				return self.SetItemImage(nID, iColumn, image.getImageHandle());
			}, "itemId"_a, "column"_a, "image"_a)
			.def("setItemImageEx", [](XCTree& self, int nID, const std::wstring& name, const XCImage& image) {
				return self.SetItemImageEx(nID, name, image.getImageHandle());
			}, "itemId"_a, "name"_a, "image"_a)


			.def("getItemText", &XCTree::GetItemText, "itemId"_a, "column"_a)
			.def("getItemTextEx", &XCTree::GetItemTextEx, "itemId"_a, "name"_a)


			.def("getItemImage", [](XCTree& self, int iItem, int iColumn) -> XCImage* {
				auto handle = self.GetItemImage(iItem, iColumn);
				if (!handle) return nullptr;
				return new XCImage(handle);

			}, "itemId"_a, "column"_a, py::return_value_policy::take_ownership)

			.def("getItemImageEx", [](XCTree& self, int iItem, const std::wstring& name) -> XCImage* {
				auto handle = self.GetItemImageEx(iItem, name);
				if (!handle) return nullptr;
				return new XCImage(handle);

			}, "itemId"_a, "name"_a, py::return_value_policy::take_ownership)

			.def("deleteItem", &XCTree::DeleteItem, "itemId"_a)
			.def("deleteItemAll", &XCTree::DeleteItemAll)
			.def("deleteColumnAll", &XCTree::DeleteColumnAll)
			;
	}
}