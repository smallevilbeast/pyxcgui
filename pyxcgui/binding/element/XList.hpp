#pragma once
#include "pch.h"
#include "xcgui/element/XCList.hpp"
#include "binding/manager/XUserDataManager.hpp"
#include "binding/manager/XCastManager.hpp"
#include "xcgui/XCStruct.hpp"
#include "xcgui/template/XCListItemTemplate.hpp"
#include "xcgui/adapter/XCAdapter.hpp"
#include "xcgui/XCImage.hpp"
#include "xcgui/utils/String.hpp"

namespace xcgui {

	void declareList(py::module& m) {

		py::class_<XCList, XCScrollView>(m, "XList")
			PYCASTOBJECT(XCList)
			PYOBJECTVALID(XCList, XC_LIST)
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCList obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent, int flags) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				auto eleHandle = XList_CreateEx(x, y, cx, cy, handle, flags);
				XCList obj;
				obj.SetHandle(eleHandle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a, "flags"_a)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCList obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)


			.def("addColumn", &XCList::AddColumn, "width"_a)
			.def("insertColumn", &XCList::InsertColumn, "width"_a, "row"_a)
			.def("enableMultiSel", &XCList::EnableMultiSel, "enable"_a)
			.def("enableDragChangeColumnWidth", &XCList::EnableDragChangeColumnWidth, "enable"_a)
			.def("enableVScrollBarTop", &XCList::EnableVScrollBarTop, "enable"_a)
			.def("enableItemBkFullRow", &XCList::EnableItemBkFullRow, "enable"_a)
			.def("enableFixedRowHeight", &XCList::EnableFixedRowHeight, "enable"_a)
			.def("enableTemplateReuse", &XCList::EnableTemplateReuse, "enable"_a)
			.def("enableVirtualTable", &XCList::EnableVirtualTable, "enable"_a)
			.def("setVirtualRowCount", &XCList::SetVirtualRowCount, "rowCount"_a)
			.def("setSort", &XCList::SetSort, "column"_a, "columnAdapter"_a, "enable"_a)
			.def("setDrawItemBkFlags", &XCList::SetDrawItemBkFlags, "flags"_a)
			.def("setSplitLineColor", &XCList::SetSplitLineColor, "color"_a)

			.def("setColumnWidth", &XCList::SetColumnWidth, "row"_a, "width"_a)
			.def("setColumnMinWidth", &XCList::SetColumnMinWidth, "row"_a, "width"_a)
			.def("setColumnWidthFixed", &XCList::SetColumnWidthFixed, "column"_a, "fixed"_a)
			.def("getColumnWidth", &XCList::GetColumnWidth, "column"_a)
			.def("getColumnCount", &XCList::GetColumnCount)

			
			.def("setItemData", [](XCList& self, int row, int column, const py::object& object) {
				XUserDataManager::GetInstance()->SetItemUserData(self.getEleHandle(), 
					vformat("%d_%d", row,  column), 
					object);
			}, "row"_a, "column"_a, "userdata"_a)

			.def("getItemData", [](XCList& self, int row, int column) {
				XUserDataManager::GetInstance()->getItemUserData(self.getEleHandle(), vformat("%d_%d", row, column));
			}, "row"_a, "column"_a)

			.def("setSelectItem", &XCList::SetSelectItem, "row"_a)
			.def("getSelectItem", &XCList::GetSelectItem)
			.def("getSelectItemCount", &XCList::GetSelectItemCount)
			.def("addSelectItem", &XCList::AddSelectItem, "row"_a)
			.def("setSelectAll", &XCList::SetSelectAll)

			.def("getSelectAll", [](XCList& self) {
				std::vector<int> out;
				out.resize(self.GetSelectItemCount());
				auto retSelCount = self.GetSelectAll(&out[0], out.size());
				out.resize(retSelCount);
				return out;
			})
			.def("visibleItem", &XCList::VisibleItem, "row"_a)
			.def("cancelSelectItem", &XCList::CancelSelectItem, "row"_a)
			.def("cancelSelectAll", &XCList::CancelSelectAll)

			.def("getHeader", [](XCList& self) -> XCObject* {
				auto handle = self.GetHeaderHELE();
				return XCastManager::GetInstance()->CastObject(handle);
			})

			.def("deleteColumn", &XCList::DeleteColumn, "row"_a)
			.def("deleteColumnAll", &XCList::DeleteColumnAll)
			
			.def("bindAdapter", [](XCList& self, const XCAdapter& adapter) {
				self.BindAdapter(adapter.GetHandle());
			}, "adapter"_a)
			
			.def("bindAdapterHeader", [](XCList& self, const XCAdapter& adapter) {
				self.BindAdapterHeader(adapter.GetHandle());
			}, "adapter"_a)

			.def("createAdapter", [](XCList& self, int colExtendCount) -> XCObject* {
				auto handle = self.CreateAdapter(colExtendCount);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "colExtendCount"_a, py::return_value_policy::take_ownership)

			.def("createAdapterHeader", [](XCList& self) -> XCObject* {
				auto handle = self.CreateAdapterHeader();
				return XCastManager::GetInstance()->CastObject(handle);
			}, py::return_value_policy::take_ownership)

			.def("getAdapter", [](XCList& self) -> XCObject* {
				auto handle = self.GetAdapter();
				return XCastManager::GetInstance()->CastObject(handle);
			}, py::return_value_policy::take_ownership)

			.def("getAdapterHeader", [](XCList& self) -> XCObject* {
				auto handle = self.GetAdapterHeader();
				return XCastManager::GetInstance()->CastObject(handle);
			}, py::return_value_policy::take_ownership)

			.def("setItemTemplateXML", &XCList::SetItemTemplateXML, "xmlFile"_a)

			// 3.3.8 新增
			.def("setItemTemplateXMLFromMem", [](XCList& self, const std::string& xmlData) {
				return XList_SetItemTemplateXMLFromMem(self.getEleHandle(), xmlData.c_str());
			}, "xmlData"_a)
			.def("setItemTemplateXMLFromZipRes", [](XCList& self, int id, const std::wstring& fileName, const std::wstring& password = L"", uintptr_t hModule = 0) {
				const wchar_t* pPassword = password.empty() ? NULL : password.c_str();
				return XList_SetItemTemplateXMLFromZipRes(self.getEleHandle(), id, fileName.c_str(), pPassword, (HMODULE)hModule);
			}, "id"_a, "fileName"_a, "password"_a = L"", "hModule"_a = 0)

			.def("setItemTemplate", [](XCList& self, const XCListItemTemplate& itemTemplate) {
				return self.SetItemTemplate(itemTemplate.getHandle());
			}, "template"_a)
			.def("getItemTemplate", [](XCList& self) -> XCListItemTemplate* {
				auto handle = self.GetItemTemplate();
				if (!handle) return nullptr;
				return new XCListItemTemplate(handle);
			}, py::return_value_policy::take_ownership)
			.def("getItemTemplateHeader", [](XCList& self) -> XCListItemTemplate* {
				auto handle = self.GetItemTemplateHeader();
				if (!handle) return nullptr;
				return new XCListItemTemplate(handle);
			}, py::return_value_policy::take_ownership)
			.def("setItemTemplateFromMem", [](XCList& self, const py::bytes xmlData) {
				return self.SetItemTemplateXMLFromString(xmlData);
			}, "xmlData"_a)
			.def("getTemplateObject", [](XCList& self, int row, int column, int templateId) -> XCListItemTemplate* {
				auto handle = self.GetTemplateObject(row, column, templateId);
				if (!handle) return nullptr;
				return new XCListItemTemplate((HTEMP)handle);
			},  "row"_a, "column"_a, "templateId"_a, py::return_value_policy::take_ownership)

			.def("getItemIndexFromUIObject", [](XCList& self, const XCWidget& widget) {
				return self.GetItemIndexFromHXCGUI(widget.GetHandle());
			}, "ele"_a)

			.def("getHeaderTemplateObject", [](XCList& self, int column, int templateId) -> XCListItemTemplate* {
				auto handle = self.GetHeaderTemplateObject(column, templateId);
				if (!handle) return nullptr;
				return new XCListItemTemplate((HTEMP)handle);
			},  "column"_a, "templateId"_a, py::return_value_policy::take_ownership)

			.def("getItemIndexFromUIObject", [](XCList& self, const XCWidget& widget) {
				return self.GetHeaderItemIndexFromHXCGUI(widget.GetHandle());
			}, "ele"_a)


			.def("setHeaderHeight", &XCList::SetHeaderHeight, "height"_a)
			.def("getHeaderHeight", &XCList::GetHeaderHeight)
			
			.def("getVisibleRowRange", [](XCList& self) {
				XCRange range;
				self.GetVisibleRowRange(&range.start, &range.end);
				return range;
			})

			.def("setItemHeightDefault", &XCList::SetItemHeightDefault, "height"_a, "selHeight"_a)
			.def("getItemHeightDefault", [](XCList& self) {
				XCItemHeightInfo info;
				self.GetItemHeightDefault(&info.height, &info.selHeight);
				return info;
			})

			.def("setItemHeight", &XCList::SetItemHeight, "row"_a, "height"_a, "selHeight"_a)
			.def("getItemHeight", [](XCList& self, int row) {
				XCItemHeightInfo info;
				self.GetItemHeight(row, &info.height, &info.selHeight);
				return info;
			}, "row"_a)
			.def("setLockColumnLeft", &XCList::SetLockColumnLeft, "column"_a)
			.def("setLockColumnRight", &XCList::SetLockColumnRight, "column"_a)
			.def("setLockRowBottom", &XCList::SetLockRowBottom, "enable"_a)
			.def("setLockRowBottomOverlap", &XCList::SetLockRowBottomOverlap, "enable"_a)


			.def("hitTest", [](XCList& self, const XCPoint& point) {
				position_ info = { 0 };
				self.HitTest((POINT*)&point, &info.iRow, &info.iColumn);
				return info;
			}, "point"_a)

			.def("hitTestOffset", [](XCList& self, const XCPoint& point) {
				position_ info = { 0 };
				self.HitTestOffset((POINT*)&point, &info.iRow, &info.iColumn);
				return info;
			}, "point"_a)


			.def("refreshData", &XCList::RefreshData)
			.def("refreshDataHeader", &XCList::RefreshDataHeader)
			.def("refreshItem", &XCList::RefreshItem, "row"_a)

			.def("addColumnText", &XCList::AddColumnText, "width"_a, "name"_a, "text"_a)
			.def("addColumnImage", [](XCList& self, int nWidth, const std::wstring& name, const XCImage& image) {
				return self.AddColumnImage(nWidth, name, image.getImageHandle());
			}, "width"_a, "name"_a, "image"_a)


			.def("addItemText", &XCList::AddItemText, "text"_a)
			.def("addItemTextEx", &XCList::AddItemTextEx, "name"_a, "text"_a)
			
			.def("addItemImage", [](XCList& self, const XCImage& image) {
				return self.AddItemImage(image.getImageHandle());
			}, "image"_a)
			.def("addItemImageEx", [](XCList& self, const std::wstring& name, const XCImage& image) {
				return self.AddItemImageEx(name, image.getImageHandle());
			}, "name"_a, "image"_a)

			.def("insertItemText", &XCList::InsertItemText, "row"_a, "text"_a)
			.def("insertItemTextEx", &XCList::InsertItemTextEx, "row"_a, "name"_a, "text"_a)

			.def("insertItemImage", [](XCList& self, int iItem, const XCImage& image) {
				return self.InsertItemImage(iItem, image.getImageHandle());
			}, "row"_a, "image"_a)
			.def("insertItemImageEx", [](XCList& self, int iItem, const std::wstring& name, const XCImage& image) {
				return self.InsertItemImageEx(iItem, name, image.getImageHandle());
			}, "row"_a, "name"_a, "image"_a)

			.def("setItemText", &XCList::SetItemText, "row"_a, "column"_a, "text"_a)
			.def("setItemTextEx", &XCList::SetItemTextEx, "row"_a, "name"_a, "text"_a)

			.def("setItemImage", [](XCList& self, int iItem, int iColumn, const XCImage& image) {
				return self.SetItemImage(iItem, iColumn, image.getImageHandle());
			}, "row"_a, "column"_a, "image"_a)
			.def("setItemImageEx", [](XCList& self, int iItem, const std::wstring& name, const XCImage& image) {
				return self.SetItemImageEx(iItem, name, image.getImageHandle());
			}, "row"_a, "name"_a, "image"_a)

			.def("setItemInt", &XCList::SetItemInt, "row"_a, "column"_a, "value"_a)
			.def("setItemIntEx", &XCList::SetItemIntEx, "row"_a, "name"_a, "value"_a)

			.def("setItemFloat", &XCList::SetItemFloat, "row"_a, "column"_a, "value"_a)
			.def("setItemFloatEx", &XCList::SetItemFloatEx, "row"_a, "name"_a, "value"_a)

			.def("getItemText", &XCList::GetItemText, "row"_a, "column"_a)
			.def("getItemTextEx", &XCList::GetItemTextEx, "row"_a, "name"_a)
	
			.def("getItemImage", [](XCList& self, int row, int iColumn) -> XCImage* {
				auto handle = self.GetItemImage(row, iColumn);
				if (!handle) return nullptr;
				return new XCImage(handle);

			}, "row"_a, "column"_a, py::return_value_policy::take_ownership)

			.def("getItemImageEx", [](XCList& self, int row, const std::wstring& name) -> XCImage* {
				auto handle = self.GetItemImageEx(row, name);
				if (!handle) return nullptr;
				return new XCImage(handle);

			}, "row"_a, "name"_a, py::return_value_policy::take_ownership)

			.def("getItemInt", [](XCList& self, int row, int iColumn) {
				int ret = 0;
				self.GetItemInt(row, iColumn, &ret);
				return ret;
			}, "row"_a, "column"_a)
			.def("getItemIntEx", [](XCList& self, int row, const std::wstring& name) {
				int ret = 0;
				self.GetItemIntEx(row, name, &ret);
				return ret;
			}, "row"_a, "name"_a)

			.def("getItemFloat", [](XCList& self, int row, int iColumn) {
				float ret = 0;
				self.GetItemFloat(row, iColumn, &ret);
				return ret;
			}, "row"_a, "column"_a)
			.def("getItemFloatEx", [](XCList& self, int row, const std::wstring& name) {
				float ret = 0;
				self.GetItemFloatEx(row, name, &ret);
				return ret;
			}, "row"_a, "name"_a)

			.def("deleteItem", &XCList::DeleteItem, "row"_a)
			.def("deleteItemEx", &XCList::DeleteItemEx, "row"_a, "count"_a)
			.def("deleteItemAll", &XCList::DeleteItemAll)
			.def("deleteColumnAll", &XCList::DeleteColumnAll)
			.def("getCount_AD", &XCList::GetCount_AD)
			.def("getCountColumn_AD", &XCList::GetCountColumn_AD)
			.def("setDragRectColor", &XCList::SetDragRectColor, "color"_a, "width"_a)

			// 3.3.9 新增 - 虚拟表格功能
			.def("enableVirtualTable", [](XCList& self, bool enable) {
				XList_EnableVirtualTable(self.getEleHandle(), enable);
			}, "enable"_a)
			.def("setVirtualRowCount", [](XCList& self, int rowCount) {
				XList_SetVirtualRowCount(self.getEleHandle(), rowCount);
			}, "rowCount"_a)

			// 3.3.9 新增 - 行操作增强功能
			.def("addRowText", [](XCList& self, const std::wstring& text) {
				return XList_AddRowText(self.getEleHandle(), text.c_str());
			}, "text"_a)
			.def("addRowTextEx", [](XCList& self, const std::wstring& name, const std::wstring& text) {
				return XList_AddRowTextEx(self.getEleHandle(), name.c_str(), text.c_str());
			}, "name"_a, "text"_a)
			.def("addRowImage", [](XCList& self, const XCImage& image) {
				return XList_AddRowImage(self.getEleHandle(), image.getImageHandle());
			}, "image"_a)
			.def("addRowImageEx", [](XCList& self, const std::wstring& name, const XCImage& image) {
				return XList_AddRowImageEx(self.getEleHandle(), name.c_str(), image.getImageHandle());
			}, "name"_a, "image"_a)

			.def("insertRowText", [](XCList& self, int row, const std::wstring& value) {
				return XList_InsertRowText(self.getEleHandle(), row, value.c_str());
			}, "row"_a, "value"_a)
			.def("insertRowTextEx", [](XCList& self, int row, const std::wstring& name, const std::wstring& value) {
				return XList_InsertRowTextEx(self.getEleHandle(), row, name.c_str(), value.c_str());
			}, "row"_a, "name"_a, "value"_a)
			.def("insertRowImage", [](XCList& self, int row, const XCImage& image) {
				return XList_InsertRowImage(self.getEleHandle(), row, image.getImageHandle());
			}, "row"_a, "image"_a)
			.def("insertRowImageEx", [](XCList& self, int row, const std::wstring& name, const XCImage& image) {
				return XList_InsertRowImageEx(self.getEleHandle(), row, name.c_str(), image.getImageHandle());
			}, "row"_a, "name"_a, "image"_a)

			.def("deleteRow", [](XCList& self, int row) {
				return XList_DeleteRow(self.getEleHandle(), row);
			}, "row"_a)
			.def("deleteRowEx", [](XCList& self, int row, int count) {
				return XList_DeleteRowEx(self.getEleHandle(), row, count);
			}, "row"_a, "count"_a)
			.def("deleteRowAll", [](XCList& self) {
				XList_DeleteRowAll(self.getEleHandle());
			})

			// 3.3.9 新增 - 选择操作
			.def("setSelectRow", [](XCList& self, int row) {
				return XList_SetSelectRow(self.getEleHandle(), row);
			}, "row"_a)
			.def("getSelectRow", [](XCList& self) {
				return XList_GetSelectRow(self.getEleHandle());
			})
			.def("getSelectRowCount", [](XCList& self) {
				return XList_GetSelectRowCount(self.getEleHandle());
			})
			.def("addSelectRow", [](XCList& self, int row) {
				return XList_AddSelectRow(self.getEleHandle(), row);
			}, "row"_a)
			.def("visibleRow", [](XCList& self, int row) {
				XList_VisibleRow(self.getEleHandle(), row);
			}, "row"_a)
			.def("cancelSelectRow", [](XCList& self, int row) {
				return XList_CancelSelectRow(self.getEleHandle(), row);
			}, "row"_a)

			// 3.3.9 新增 - 索引和属性操作
			.def("getRowIndexFromHXCGUI", [](XCList& self, uintptr_t hXCGUI) {
				return XList_GetRowIndexFromHXCGUI(self.getEleHandle(), (HXCGUI)hXCGUI);
			}, "hXCGUI"_a)
			.def("getHeaderColumnIndexFromHXCGUI", [](XCList& self, uintptr_t hXCGUI) {
				return XList_GetHeaderColumnIndexFromHXCGUI(self.getEleHandle(), (HXCGUI)hXCGUI);
			}, "hXCGUI"_a)
			.def("setRowHeightDefault", [](XCList& self, int height, int selHeight) {
				XList_SetRowHeightDefault(self.getEleHandle(), height, selHeight);
			}, "height"_a, "selHeight"_a)
			.def("getRowHeightDefault", [](XCList& self) {
				int height, selHeight;
				XList_GetRowHeightDefault(self.getEleHandle(), &height, &selHeight);
				return py::make_tuple(height, selHeight);
			})
			.def("setRowHeight", [](XCList& self, int row, int height, int selHeight) {
				XList_SetRowHeight(self.getEleHandle(), row, height, selHeight);
			}, "row"_a, "height"_a, "selHeight"_a)
			.def("getRowHeight", [](XCList& self, int row) {
				int height, selHeight;
				XList_GetRowHeight(self.getEleHandle(), row, &height, &selHeight);
				return py::make_tuple(height, selHeight);
			}, "row"_a)
			.def("enableRowBkFull", [](XCList& self, bool full) {
				XList_EnableRowBkFull(self.getEleHandle(), full);
			}, "full"_a)
			.def("setDrawRowBkFlags", [](XCList& self, int style) {
				XList_SetDrawRowBkFlags(self.getEleHandle(), style);
			}, "style"_a)
			.def("refreshRow", [](XCList& self, int row) {
				XList_RefreshRow(self.getEleHandle(), row);
			}, "row"_a)
			;
	}
}