#pragma once
#include "pch.h"
#include "xcgui/menu/XCMenu.hpp"
#include "xcgui/XCImage.hpp"
#include "xcgui/XCElement.hpp"

namespace xcgui {

	void declareMenu(py::module& m) {
		py::class_<XCMenu>(m, "XMenu")
			.def(py::init())
			
			.def("addItem", &XCMenu::AddItem, "nId"_a, "text"_a, "parentId"_a=XC_ID_ROOT, "flags"_a=0)
			.def("addItemIcon", [](XCMenu& self, int nID, const std::wstring& text, 
				int nParentID, const XCImage& image, int nFlags = 0){
					self.AddItemIcon(nID, text, nParentID, image.getImageHandle(), nFlags);
			}, "nId"_a, "text"_a, "parentId"_a, "image"_a, "flags"_a)

			.def("insertItem", &XCMenu::InsertItem, "nId"_a, "text"_a, "flags"_a, "insertId"_a)
			.def("insertItemIcon", [](XCMenu& self, int nID, const std::wstring& text, 
				const XCImage& image, int nFlags, int insertID){
					self.InsertItemIcon(nID, text, image.getImageHandle(), nFlags, insertID);
			}, "nId"_a, "text"_a, "image"_a, "flags"_a, "insertId"_a)

			
			.def("getFirstChildItem", &XCMenu::GetFirstChildItem, "nId"_a)
			
			.def("getEndChildItem", &XCMenu::GetEndChildItem, "nId"_a)
				
			.def("getPrevSiblingItem", &XCMenu::GetPrevSiblingItem, "nId"_a)
				
			.def("getNextSiblingItem", &XCMenu::GetNextSiblingItem, "nId"_a)
			.def("getParentItem", &XCMenu::GetParentItem, "nId"_a)
			.def("setAutoDestroy", &XCMenu::SetAutoDestroy, "enable"_a)
			.def("enableDrawBackground", &XCMenu::EnableDrawBackground, "enable"_a)

			.def("popup", [](XCMenu& self, uintptr_t hParentWnd, int x, int y,
				XCElement* parentEle = nullptr, menu_popup_position_ nPosition = menu_popup_position_left_top) {
				return self.Popup((HWND)hParentWnd, x, y, parentEle ? parentEle->getEleHandle() : nullptr, nPosition);
			}, "parentHWND"_a, "x"_a, "y"_a, "parentEle"_a=nullptr, "position"_a=menu_popup_position_left_top)

			.def("destroyMenu", &XCMenu::DestroyMenu)
			.def("closeMenu", &XCMenu::CloseMenu)
			.def("setBkImage", [](XCMenu& self, const XCImage& image) {
				self.SetBkImage(image.getImageHandle());
			}, "image"_a)

			.def("setItemText", &XCMenu::SetItemText, "nId"_a, "text"_a)
			.def("getItemText", &XCMenu::GetItemText, "nId"_a)
			.def("getItemTextLength", &XCMenu::GetItemTextLength, "nId"_a)
			.def("setItemIcon", [](XCMenu& self, int nId, const XCImage& image) {
				self.SetItemIcon(nId, image.getImageHandle());
			}, "nId"_a, "image"_a)
			.def("setItemFlags", &XCMenu::SetItemFlags, "nId"_a, "flags"_a)
			.def("setItemHeight", &XCMenu::SetItemHeight, "height"_a)
			.def("getItemHeight", &XCMenu::GetItemHeight)
			.def("setItemWidth", &XCMenu::SetItemWidth, "nId"_a, "width"_a)
			.def("setBorderColor", &XCMenu::SetBorderColor, "color"_a)
			.def("setBorderSize", &XCMenu::SetBorderSize, "left"_a, "top"_a, "right"_a, "bottom"_a)
			.def("getLeftWidth", &XCMenu::GetLeftWidth)
			.def("getLeftSpaceText", &XCMenu::GetLeftSpaceText)
			.def("setItemCheck", &XCMenu::SetItemCheck, "nId"_a, "check"_a)
			.def("isItemCheck", &XCMenu::IsItemCheck, "nId"_a);
	}
}