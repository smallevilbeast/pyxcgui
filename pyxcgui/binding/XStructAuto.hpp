#pragma once
#include "pch.h"
#include "xcgui/XCStruct.hpp"


namespace xcgui {

	void declareStructAuto(py::module& m) 
	{
		py::class_<POINTF>(m, "POINTF")
            PYCAST(POINTF)
	        .def(py::init<>())
	        .def_readwrite("x", &POINTF::x)
	        .def_readwrite("y", &POINTF::y);

        py::class_<RECTF>(m, "RECTF")
            PYCAST(RECTF)
	        .def(py::init<>())
	        .def_readwrite("left", &RECTF::left)
	        .def_readwrite("top", &RECTF::top)
	        .def_readwrite("right", &RECTF::right)
	        .def_readwrite("bottom", &RECTF::bottom);

        py::class_<borderSize_>(m, "borderSize_")
            PYCAST(borderSize_)
	        .def(py::init<>())
	        .def_readwrite("leftSize", &borderSize_::leftSize)
	        .def_readwrite("topSize", &borderSize_::topSize)
	        .def_readwrite("rightSize", &borderSize_::rightSize)
	        .def_readwrite("bottomSize", &borderSize_::bottomSize);

        py::class_<position_>(m, "position_")
            PYCAST(position_)
	        .def(py::init<>())
	        .def_readwrite("iRow", &position_::iRow)
	        .def_readwrite("iColumn", &position_::iColumn);

        py::class_<listBox_item_>(m, "listBox_item_")
            PYCAST(listBox_item_)
	        .def(py::init<>())
	        .def_readwrite("index", &listBox_item_::index)
	        .def_readwrite("nUserData", &listBox_item_::nUserData)
	        .def_readwrite("nHeight", &listBox_item_::nHeight)
	        .def_readwrite("nSelHeight", &listBox_item_::nSelHeight)
	        .def_readwrite("nState", &listBox_item_::nState)
	        .def_readwrite("rcItem", &listBox_item_::rcItem)

            .def_property("hLayout", [](listBox_item_ self) -> uintptr_t {
                return (uintptr_t)self.hLayout;
            }, 
            [](listBox_item_ self, uintptr_t hLayout) {
                self.hLayout = (HXCGUI)hLayout;
    
            })


            .def_property("hTemp", [](listBox_item_ self) -> uintptr_t {
                return (uintptr_t)self.hTemp;
            }, 
            [](listBox_item_ self, uintptr_t hTemp) {
                self.hTemp = (HTEMP)hTemp;
    
            })
        ;

        py::class_<listBox_item_info_>(m, "listBox_item_info_")
            PYCAST(listBox_item_info_)
	        .def(py::init<>())
	        .def_readwrite("nUserData", &listBox_item_info_::nUserData)
	        .def_readwrite("nHeight", &listBox_item_info_::nHeight)
	        .def_readwrite("nSelHeight", &listBox_item_info_::nSelHeight);

        py::class_<listView_item_id_>(m, "listView_item_id_")
            PYCAST(listView_item_id_)
	        .def(py::init<>())
	        .def_readwrite("iGroup", &listView_item_id_::iGroup)
	        .def_readwrite("iItem", &listView_item_id_::iItem);

        py::class_<list_item_>(m, "list_item_")
            PYCAST(list_item_)
	        .def(py::init<>())
	        .def_readwrite("index", &list_item_::index)
	        .def_readwrite("iSubItem", &list_item_::iSubItem)
	        .def_readwrite("nUserData", &list_item_::nUserData)
	        .def_readwrite("nState", &list_item_::nState)
	        .def_readwrite("rcItem", &list_item_::rcItem)

            .def_property("hLayout", [](list_item_ self) -> uintptr_t {
                return (uintptr_t)self.hLayout;
            }, 
            [](list_item_ self, uintptr_t hLayout) {
                self.hLayout = (HXCGUI)hLayout;
    
            })


            .def_property("hTemp", [](list_item_ self) -> uintptr_t {
                return (uintptr_t)self.hTemp;
            }, 
            [](list_item_ self, uintptr_t hTemp) {
                self.hTemp = (HTEMP)hTemp;
    
            })
        ;

        py::class_<list_header_item_>(m, "list_header_item_")
            PYCAST(list_header_item_)
	        .def(py::init<>())
	        .def_readwrite("index", &list_header_item_::index)
	        .def_readwrite("nUserData", &list_header_item_::nUserData)

            .def_property("bSort", [](list_header_item_ self) -> bool {
                return (bool)self.bSort;
            }, 
            [](list_header_item_ self, bool bSort) {
                self.bSort = (BOOL)bSort;
    
            })

	        .def_readwrite("nSortType", &list_header_item_::nSortType)
	        .def_readwrite("iColumnAdapter", &list_header_item_::iColumnAdapter)
	        .def_readwrite("nState", &list_header_item_::nState)
	        .def_readwrite("rcItem", &list_header_item_::rcItem)

            .def_property("hLayout", [](list_header_item_ self) -> uintptr_t {
                return (uintptr_t)self.hLayout;
            }, 
            [](list_header_item_ self, uintptr_t hLayout) {
                self.hLayout = (HXCGUI)hLayout;
    
            })


            .def_property("hTemp", [](list_header_item_ self) -> uintptr_t {
                return (uintptr_t)self.hTemp;
            }, 
            [](list_header_item_ self, uintptr_t hTemp) {
                self.hTemp = (HTEMP)hTemp;
    
            })
        ;

        py::class_<tree_item_>(m, "tree_item_")
            PYCAST(tree_item_)
	        .def(py::init<>())
	        .def_readwrite("nID", &tree_item_::nID)
	        .def_readwrite("nDepth", &tree_item_::nDepth)
	        .def_readwrite("nHeight", &tree_item_::nHeight)
	        .def_readwrite("nSelHeight", &tree_item_::nSelHeight)
	        .def_readwrite("nUserData", &tree_item_::nUserData)

            .def_property("bExpand", [](tree_item_ self) -> bool {
                return (bool)self.bExpand;
            }, 
            [](tree_item_ self, bool bExpand) {
                self.bExpand = (BOOL)bExpand;
    
            })

	        .def_readwrite("nState", &tree_item_::nState)
	        .def_readwrite("rcItem", &tree_item_::rcItem)

            .def_property("hLayout", [](tree_item_ self) -> uintptr_t {
                return (uintptr_t)self.hLayout;
            }, 
            [](tree_item_ self, uintptr_t hLayout) {
                self.hLayout = (HXCGUI)hLayout;
    
            })


            .def_property("hTemp", [](tree_item_ self) -> uintptr_t {
                return (uintptr_t)self.hTemp;
            }, 
            [](tree_item_ self, uintptr_t hTemp) {
                self.hTemp = (HTEMP)hTemp;
    
            })
        ;

        py::class_<listView_item_>(m, "listView_item_")
            PYCAST(listView_item_)
	        .def(py::init<>())
	        .def_readwrite("iGroup", &listView_item_::iGroup)
	        .def_readwrite("iItem", &listView_item_::iItem)
	        .def_readwrite("nUserData", &listView_item_::nUserData)
	        .def_readwrite("nState", &listView_item_::nState)
	        .def_readwrite("rcItem", &listView_item_::rcItem)

            .def_property("hLayout", [](listView_item_ self) -> uintptr_t {
                return (uintptr_t)self.hLayout;
            }, 
            [](listView_item_ self, uintptr_t hLayout) {
                self.hLayout = (HXCGUI)hLayout;
    
            })


            .def_property("hTemp", [](listView_item_ self) -> uintptr_t {
                return (uintptr_t)self.hTemp;
            }, 
            [](listView_item_ self, uintptr_t hTemp) {
                self.hTemp = (HTEMP)hTemp;
    
            })
        ;

        py::class_<menu_popupWnd_>(m, "menu_popupWnd_")
            PYCAST(menu_popupWnd_)
	        .def(py::init<>())

            .def_property("hWindow", [](menu_popupWnd_ self) -> uintptr_t {
                return (uintptr_t)self.hWindow;
            }, 
            [](menu_popupWnd_ self, uintptr_t hWindow) {
                self.hWindow = (HWINDOW)hWindow;
    
            })

	        .def_readwrite("nParentID", &menu_popupWnd_::nParentID);

        py::class_<menu_drawBackground_>(m, "menu_drawBackground_")
            PYCAST(menu_drawBackground_)
	        .def(py::init<>())

            .def_property("hMenu", [](menu_drawBackground_ self) -> uintptr_t {
                return (uintptr_t)self.hMenu;
            }, 
            [](menu_drawBackground_ self, uintptr_t hMenu) {
                self.hMenu = (HMENUX)hMenu;
    
            })


            .def_property("hWindow", [](menu_drawBackground_ self) -> uintptr_t {
                return (uintptr_t)self.hWindow;
            }, 
            [](menu_drawBackground_ self, uintptr_t hWindow) {
                self.hWindow = (HWINDOW)hWindow;
    
            })

	        .def_readwrite("nParentID", &menu_drawBackground_::nParentID);

        py::class_<menu_drawItem_>(m, "menu_drawItem_")
            PYCAST(menu_drawItem_)
	        .def(py::init<>())

            .def_property("hMenu", [](menu_drawItem_ self) -> uintptr_t {
                return (uintptr_t)self.hMenu;
            }, 
            [](menu_drawItem_ self, uintptr_t hMenu) {
                self.hMenu = (HMENUX)hMenu;
    
            })


            .def_property("hWindow", [](menu_drawItem_ self) -> uintptr_t {
                return (uintptr_t)self.hWindow;
            }, 
            [](menu_drawItem_ self, uintptr_t hWindow) {
                self.hWindow = (HWINDOW)hWindow;
    
            })

	        .def_readwrite("nID", &menu_drawItem_::nID)
	        .def_readwrite("nState", &menu_drawItem_::nState)
	        .def_readwrite("rcItem", &menu_drawItem_::rcItem)

            .def_property("hIcon", [](menu_drawItem_ self) -> uintptr_t {
                return (uintptr_t)self.hIcon;
            }, 
            [](menu_drawItem_ self, uintptr_t hIcon) {
                self.hIcon = (HIMAGE)hIcon;
    
            })

	        .def_readwrite("pText", &menu_drawItem_::pText);

        py::class_<tree_drag_item_>(m, "tree_drag_item_")
            PYCAST(tree_drag_item_)
	        .def(py::init<>())
	        .def_readwrite("nDragItem", &tree_drag_item_::nDragItem)
	        .def_readwrite("nDestItem", &tree_drag_item_::nDestItem)
	        .def_readwrite("nType", &tree_drag_item_::nType);

        py::class_<font_info_>(m, "font_info_")
            PYCAST(font_info_)
	        .def(py::init<>())
	        .def_readwrite("nSize", &font_info_::nSize)
	        .def_readwrite("nStyle", &font_info_::nStyle)
			.def_property_readonly("name", [](font_info_ self) {
                 return std::wstring(self.name);
			});

        py::class_<propertyGrid_item_>(m, "propertyGrid_item_")
            PYCAST(propertyGrid_item_)
	        .def(py::init<>())
	        .def_readwrite("nType", &propertyGrid_item_::nType)
	        .def_readwrite("nID", &propertyGrid_item_::nID)
	        .def_readwrite("nDepth", &propertyGrid_item_::nDepth)
	        .def_readwrite("nUserData", &propertyGrid_item_::nUserData)
	        .def_readwrite("nNameColWidth", &propertyGrid_item_::nNameColWidth)
	        .def_readwrite("rcItem", &propertyGrid_item_::rcItem)
	        .def_readwrite("rcExpand", &propertyGrid_item_::rcExpand)

            .def_property("bExpand", [](propertyGrid_item_ self) -> bool {
                return (bool)self.bExpand;
            }, 
            [](propertyGrid_item_ self, bool bExpand) {
                self.bExpand = (BOOL)bExpand;
    
            })


            .def_property("bShow", [](propertyGrid_item_ self) -> bool {
                return (bool)self.bShow;
            }, 
            [](propertyGrid_item_ self, bool bShow) {
                self.bShow = (BOOL)bShow;
    
            })
        ;

        py::class_<edit_style_info_>(m, "edit_style_info_")
            PYCAST(edit_style_info_)
	        .def(py::init<>())
	        .def_readwrite("type", &edit_style_info_::type)
	        .def_readwrite("nRef", &edit_style_info_::nRef)

            .def_property("hFont_image_obj", [](edit_style_info_ self) -> uintptr_t {
                return (uintptr_t)self.hFont_image_obj;
            }, 
            [](edit_style_info_ self, uintptr_t hFont_image_obj) {
                self.hFont_image_obj = (HXCGUI)hFont_image_obj;
    
            })

	        .def_readwrite("color", &edit_style_info_::color)

            .def_property("bColor", [](edit_style_info_ self) -> bool {
                return (bool)self.bColor;
            }, 
            [](edit_style_info_ self, bool bColor) {
                self.bColor = (BOOL)bColor;
    
            })
        ;

        py::class_<edit_data_copy_style_>(m, "edit_data_copy_style_")
            PYCAST(edit_data_copy_style_)
	        .def(py::init<>())

            .def_property("hFont_image_obj", [](edit_data_copy_style_ self) -> uintptr_t {
                return (uintptr_t)self.hFont_image_obj;
            }, 
            [](edit_data_copy_style_ self, uintptr_t hFont_image_obj) {
                self.hFont_image_obj = (HIMAGE)hFont_image_obj;
    
            })

	        .def_readwrite("color", &edit_data_copy_style_::color)

            .def_property("bColor", [](edit_data_copy_style_ self) -> bool {
                return (bool)self.bColor;
            }, 
            [](edit_data_copy_style_ self, bool bColor) {
                self.bColor = (BOOL)bColor;
    
            })
        ;

        py::class_<edit_data_copy_>(m, "edit_data_copy_")
            PYCAST(edit_data_copy_)
	        .def(py::init<>())
	        .def_readwrite("nCount", &edit_data_copy_::nCount)
	        .def_readwrite("nStyleCount", &edit_data_copy_::nStyleCount)
	        .def_readwrite("pStyle", &edit_data_copy_::pStyle)
	        .def_readwrite("pData", &edit_data_copy_::pData);

        py::class_<editor_color_>(m, "editor_color_")
            PYCAST(editor_color_)
	        .def(py::init<>())

            .def_property("bAlignLineArrow", [](editor_color_ self) -> bool {
                return (bool)self.bAlignLineArrow;
            }, 
            [](editor_color_ self, bool bAlignLineArrow) {
                self.bAlignLineArrow = (BOOL)bAlignLineArrow;
    
            })

	        .def_readwrite("clrMargin1", &editor_color_::clrMargin1)
	        .def_readwrite("clrMargin2", &editor_color_::clrMargin2)
	        .def_readwrite("clrMargin_text", &editor_color_::clrMargin_text)
	        .def_readwrite("clrMargin_breakpoint", &editor_color_::clrMargin_breakpoint)
	        .def_readwrite("clrMargin_breakpointBorder", &editor_color_::clrMargin_breakpointBorder)
	        .def_readwrite("clrMargin_runRowArrow", &editor_color_::clrMargin_runRowArrow)
	        .def_readwrite("clrMargin_curRow", &editor_color_::clrMargin_curRow)
	        .def_readwrite("clrMargin_error", &editor_color_::clrMargin_error)
	        .def_readwrite("clrCurRowFull", &editor_color_::clrCurRowFull)
	        .def_readwrite("clrMatchSel", &editor_color_::clrMatchSel)
	        .def_readwrite("clrAlignLine", &editor_color_::clrAlignLine)
	        .def_readwrite("clrAlignLineSel", &editor_color_::clrAlignLineSel)
	        .def_readwrite("clrFunSplitLine", &editor_color_::clrFunSplitLine)
	        .def_readwrite("styleSys", &editor_color_::styleSys)
	        .def_readwrite("styleFunction", &editor_color_::styleFunction)
	        .def_readwrite("styleVar", &editor_color_::styleVar)
	        .def_readwrite("styleDataType", &editor_color_::styleDataType)
	        .def_readwrite("styleClass", &editor_color_::styleClass)
	        .def_readwrite("styleMacro", &editor_color_::styleMacro)
	        .def_readwrite("styleEnum", &editor_color_::styleEnum)
	        .def_readwrite("styleNumber", &editor_color_::styleNumber)
	        .def_readwrite("styleString", &editor_color_::styleString)
	        .def_readwrite("styleComment", &editor_color_::styleComment)
	        .def_readwrite("StylePunctuation", &editor_color_::StylePunctuation);

        py::class_<monthCal_item_>(m, "monthCal_item_")
            PYCAST(monthCal_item_)
	        .def(py::init<>())
	        .def_readwrite("nDay", &monthCal_item_::nDay)
	        .def_readwrite("nType", &monthCal_item_::nType)
	        .def_readwrite("nState", &monthCal_item_::nState)
	        .def_readwrite("rcItem", &monthCal_item_::rcItem);
	}
}