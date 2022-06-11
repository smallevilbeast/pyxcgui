#pragma once
#include "pch.h"


namespace xcgui {

	void declareEnum(py::module& m) {

		py::enum_<XC_OBJECT_TYPE>(m, "XC_OBJECT_TYPE", py::arithmetic())
			.value("XC_ERROR", XC_ERROR)
			.value("XC_NOTHING", XC_NOTHING)
			.value("XC_WINDOW", XC_WINDOW)
			.value("XC_MODALWINDOW", XC_MODALWINDOW)
			.value("XC_FRAMEWND", XC_FRAMEWND)
			.value("XC_FLOATWND", XC_FLOATWND)
			.value("XC_COMBOBOXWINDOW", XC_COMBOBOXWINDOW)
			.value("XC_POPUPMENUWINDOW", XC_POPUPMENUWINDOW)
			.value("XC_POPUPMENUCHILDWINDOW", XC_POPUPMENUCHILDWINDOW)
			.value("XC_OBJECT_UI", XC_OBJECT_UI)
			.value("XC_WIDGET_UI", XC_WIDGET_UI)
			.value("XC_ELE", XC_ELE)
			.value("XC_ELE_LAYOUT", XC_ELE_LAYOUT)
			.value("XC_LAYOUT_FRAME", XC_LAYOUT_FRAME)
			.value("XC_BUTTON", XC_BUTTON)
			.value("XC_EDIT", XC_EDIT)
			.value("XC_EDITOR", XC_EDITOR)
			.value("XC_RICHEDIT", XC_RICHEDIT)
			.value("XC_COMBOBOX", XC_COMBOBOX)
			.value("XC_SCROLLBAR", XC_SCROLLBAR)
			.value("XC_SCROLLVIEW", XC_SCROLLVIEW)
			.value("XC_LIST", XC_LIST)
			.value("XC_LISTBOX", XC_LISTBOX)
			.value("XC_LISTVIEW", XC_LISTVIEW)
			.value("XC_TREE", XC_TREE)
			.value("XC_MENUBAR", XC_MENUBAR)
			.value("XC_SLIDERBAR", XC_SLIDERBAR)
			.value("XC_PROGRESSBAR", XC_PROGRESSBAR)
			.value("XC_TOOLBAR", XC_TOOLBAR)
			.value("XC_MONTHCAL", XC_MONTHCAL)
			.value("XC_DATETIME", XC_DATETIME)
			.value("XC_PROPERTYGRID", XC_PROPERTYGRID)
			.value("XC_EDIT_COLOR", XC_EDIT_COLOR)
			.value("XC_EDIT_SET", XC_EDIT_SET)
			.value("XC_TABBAR", XC_TABBAR)
			.value("XC_TEXTLINK", XC_TEXTLINK)
			.value("XC_PANE", XC_PANE)
			.value("XC_PANE_SPLIT", XC_PANE_SPLIT)
			.value("XC_MENUBAR_BUTTON", XC_MENUBAR_BUTTON)
			.value("XC_EDIT_FILE", XC_EDIT_FILE)
			.value("XC_EDIT_FOLDER", XC_EDIT_FOLDER)
			.value("XC_LIST_HEADER", XC_LIST_HEADER)
			.value("XC_SHAPE", XC_SHAPE)
			.value("XC_SHAPE_TEXT", XC_SHAPE_TEXT)
			.value("XC_SHAPE_PICTURE", XC_SHAPE_PICTURE)
			.value("XC_SHAPE_RECT", XC_SHAPE_RECT)
			.value("XC_SHAPE_ELLIPSE", XC_SHAPE_ELLIPSE)
			.value("XC_SHAPE_LINE", XC_SHAPE_LINE)
			.value("XC_SHAPE_GROUPBOX", XC_SHAPE_GROUPBOX)
			.value("XC_SHAPE_GIF", XC_SHAPE_GIF)
			.value("XC_SHAPE_TABLE", XC_SHAPE_TABLE)
			.value("XC_MENU", XC_MENU)
			.value("XC_IMAGE", XC_IMAGE)
			.value("XC_IMAGE_TEXTURE", XC_IMAGE_TEXTURE)
			.value("XC_HDRAW", XC_HDRAW)
			.value("XC_FONT", XC_FONT)
			.value("XC_IMAGE_FRAME", XC_IMAGE_FRAME)
			.value("XC_SVG", XC_SVG)
			.value("XC_LAYOUT_OBJECT", XC_LAYOUT_OBJECT)
			.value("XC_ADAPTER", XC_ADAPTER)
			.value("XC_ADAPTER_TABLE", XC_ADAPTER_TABLE)
			.value("XC_ADAPTER_TREE", XC_ADAPTER_TREE)
			.value("XC_ADAPTER_LISTVIEW", XC_ADAPTER_LISTVIEW)
			.value("XC_ADAPTER_MAP", XC_ADAPTER_MAP)
			.value("XC_BKINFOM", XC_BKINFOM)
			.value("XC_LAYOUT_LISTVIEW", XC_LAYOUT_LISTVIEW)
			.value("XC_LAYOUT_LIST", XC_LAYOUT_LIST)
			.value("XC_LAYOUT_OBJECT_GROUP", XC_LAYOUT_OBJECT_GROUP)
			.value("XC_LAYOUT_OBJECT_ITEM", XC_LAYOUT_OBJECT_ITEM)
			.value("XC_LAYOUT_PANEL", XC_LAYOUT_PANEL)
			.value("XC_LAYOUT_BOX", XC_LAYOUT_BOX)
			.value("XC_ANIMATION_SEQUENCE", XC_ANIMATION_SEQUENCE)
			.value("XC_ANIMATION_GROUP", XC_ANIMATION_GROUP)
			.value("XC_ANIMATION_ITEM", XC_ANIMATION_ITEM)
			.export_values();

		py::enum_<XC_OBJECT_TYPE_EX>(m, "XC_OBJECT_TYPE_EX", py::arithmetic())
			.value("xc_ex_error", xc_ex_error)
			.value("button_type_default", button_type_default)
			.value("button_type_radio", button_type_radio)
			.value("button_type_check", button_type_check)
			.value("button_type_close", button_type_close)
			.value("button_type_min", button_type_min)
			.value("button_type_max", button_type_max)
			.value("element_type_layout", element_type_layout)
			.export_values();

		py::enum_<XC_OBJECT_STYLE>(m, "XC_OBJECT_STYLE", py::arithmetic())
			.value("xc_style_default", xc_style_default)
			.value("button_style_default", button_style_default)
			.value("button_style_radio", button_style_radio)
			.value("button_style_check", button_style_check)
			.value("button_style_icon", button_style_icon)
			.value("button_style_expand", button_style_expand)
			.value("button_style_close", button_style_close)
			.value("button_style_max", button_style_max)
			.value("button_style_min", button_style_min)
			.value("button_style_scrollbar_left", button_style_scrollbar_left)
			.value("button_style_scrollbar_right", button_style_scrollbar_right)
			.value("button_style_scrollbar_up", button_style_scrollbar_up)
			.value("button_style_scrollbar_down", button_style_scrollbar_down)
			.value("button_style_scrollbar_slider_h", button_style_scrollbar_slider_h)
			.value("button_style_scrollbar_slider_v", button_style_scrollbar_slider_v)
			.value("button_style_tabBar", button_style_tabBar)
			.value("button_style_slider", button_style_slider)
			.value("button_style_toolBar", button_style_toolBar)
			.value("button_style_toolBar_left", button_style_toolBar_left)
			.value("button_style_toolBar_right", button_style_toolBar_right)
			.value("button_style_pane_close", button_style_pane_close)
			.value("button_style_pane_lock", button_style_pane_lock)
			.value("button_style_pane_menu", button_style_pane_menu)
			.value("button_style_pane_dock_left", button_style_pane_dock_left)
			.value("button_style_pane_dock_top", button_style_pane_dock_top)
			.value("button_style_pane_dock_right", button_style_pane_dock_right)
			.value("button_style_pane_dock_bottom", button_style_pane_dock_bottom)
			.value("element_style_frameWnd_dock_left", element_style_frameWnd_dock_left)
			.value("element_style_frameWnd_dock_top", element_style_frameWnd_dock_top)
			.value("element_style_frameWnd_dock_right", element_style_frameWnd_dock_right)
			.value("element_style_frameWnd_dock_bottom", element_style_frameWnd_dock_bottom)
			.value("element_style_toolBar_separator", element_style_toolBar_separator)
			.value("listBox_style_comboBox", listBox_style_comboBox)
			.export_values();

		py::enum_<window_style_>(m, "window_style_", py::arithmetic())
			.value("window_style_nothing", window_style_nothing)
			.value("window_style_caption", window_style_caption)
			.value("window_style_border", window_style_border)
			.value("window_style_center", window_style_center)
			.value("window_style_drag_border", window_style_drag_border)
			.value("window_style_drag_window", window_style_drag_window)
			.value("window_style_allow_maxWindow", window_style_allow_maxWindow)
			.value("window_style_icon", window_style_icon)
			.value("window_style_title", window_style_title)
			.value("window_style_btn_min", window_style_btn_min)
			.value("window_style_btn_max", window_style_btn_max)
			.value("window_style_btn_close", window_style_btn_close)
			.value("window_style_default", window_style_default)
			.value("window_style_simple", window_style_simple)
			.value("window_style_pop", window_style_pop)
			.value("window_style_modal", window_style_modal)
			.value("window_style_modal_simple", window_style_modal_simple)
			.export_values();

		py::enum_<window_position_>(m, "window_position_", py::arithmetic())
			.value("window_position_error", window_position_error)
			.value("window_position_top", window_position_top)
			.value("window_position_bottom", window_position_bottom)
			.value("window_position_left", window_position_left)
			.value("window_position_right", window_position_right)
			.value("window_position_body", window_position_body)
			.value("window_position_window", window_position_window)
			.export_values();

		py::enum_<element_position_>(m, "element_position_", py::arithmetic())
			.value("element_position_no", element_position_no)
			.value("element_position_left", element_position_left)
			.value("element_position_top", element_position_top)
			.value("element_position_right", element_position_right)
			.value("element_position_bottom", element_position_bottom)
			.export_values();

		py::enum_<position_flag_>(m, "position_flag_", py::arithmetic())
			.value("position_flag_left", position_flag_left)
			.value("position_flag_top", position_flag_top)
			.value("position_flag_right", position_flag_right)
			.value("position_flag_bottom", position_flag_bottom)
			.value("position_flag_leftTop", position_flag_leftTop)
			.value("position_flag_leftBottom", position_flag_leftBottom)
			.value("position_flag_rightTop", position_flag_rightTop)
			.value("position_flag_rightBottom", position_flag_rightBottom)
			.value("position_flag_center", position_flag_center)
			.export_values();

		py::enum_<window_transparent_>(m, "window_transparent_", py::arithmetic())
			.value("window_transparent_false", window_transparent_false)
			.value("window_transparent_shaped", window_transparent_shaped)
			.value("window_transparent_shadow", window_transparent_shadow)
			.value("window_transparent_simple", window_transparent_simple)
			.value("window_transparent_win7", window_transparent_win7)
			.export_values();

		py::enum_<menu_item_flag_>(m, "menu_item_flag_", py::arithmetic())
			.value("menu_item_flag_normal", menu_item_flag_normal)
			.value("menu_item_flag_select", menu_item_flag_select)
			.value("menu_item_flag_stay", menu_item_flag_stay)
			.value("menu_item_flag_check", menu_item_flag_check)
			.value("menu_item_flag_popup", menu_item_flag_popup)
			.value("menu_item_flag_separator", menu_item_flag_separator)
			.value("menu_item_flag_disable", menu_item_flag_disable)
			.export_values();

		py::enum_<menu_popup_position_>(m, "menu_popup_position_", py::arithmetic())
			.value("menu_popup_position_left_top", menu_popup_position_left_top)
			.value("menu_popup_position_left_bottom", menu_popup_position_left_bottom)
			.value("menu_popup_position_right_top", menu_popup_position_right_top)
			.value("menu_popup_position_right_bottom", menu_popup_position_right_bottom)
			.value("menu_popup_position_center_left", menu_popup_position_center_left)
			.value("menu_popup_position_center_top", menu_popup_position_center_top)
			.value("menu_popup_position_center_right", menu_popup_position_center_right)
			.value("menu_popup_position_center_bottom", menu_popup_position_center_bottom)
			.export_values();

		py::enum_<image_draw_type_>(m, "image_draw_type_", py::arithmetic())
			.value("image_draw_type_default", image_draw_type_default)
			.value("image_draw_type_stretch", image_draw_type_stretch)
			.value("image_draw_type_adaptive", image_draw_type_adaptive)
			.value("image_draw_type_tile", image_draw_type_tile)
			.value("image_draw_type_fixed_ratio", image_draw_type_fixed_ratio)
			.value("image_draw_type_adaptive_border", image_draw_type_adaptive_border)
			.export_values();

		py::enum_<common_state3_>(m, "common_state3_", py::arithmetic())
			.value("common_state3_leave", common_state3_leave)
			.value("common_state3_stay", common_state3_stay)
			.value("common_state3_down", common_state3_down)
			.export_values();

		py::enum_<button_state_>(m, "button_state_", py::arithmetic())
			.value("button_state_leave", button_state_leave)
			.value("button_state_stay", button_state_stay)
			.value("button_state_down", button_state_down)
			.value("button_state_check", button_state_check)
			.value("button_state_disable", button_state_disable)
			.export_values();

		py::enum_<comboBox_state_>(m, "comboBox_state_", py::arithmetic())
			.value("comboBox_state_leave", comboBox_state_leave)
			.value("comboBox_state_stay", comboBox_state_stay)
			.value("comboBox_state_down", comboBox_state_down)
			.export_values();

		py::enum_<list_item_state_>(m, "list_item_state_", py::arithmetic())
			.value("list_item_state_leave", list_item_state_leave)
			.value("list_item_state_stay", list_item_state_stay)
			.value("list_item_state_select", list_item_state_select)
			.value("list_item_state_cache", list_item_state_cache)
			.export_values();

		py::enum_<tree_item_state_>(m, "tree_item_state_", py::arithmetic())
			.value("tree_item_state_leave", tree_item_state_leave)
			.value("tree_item_state_stay", tree_item_state_stay)
			.value("tree_item_state_select", tree_item_state_select)
			.export_values();

		py::enum_<button_icon_align_>(m, "button_icon_align_", py::arithmetic())
			.value("button_icon_align_left", button_icon_align_left)
			.value("button_icon_align_top", button_icon_align_top)
			.value("button_icon_align_right", button_icon_align_right)
			.value("button_icon_align_bottom", button_icon_align_bottom)
			.export_values();

		py::enum_<list_drawItemBk_flag_>(m, "list_drawItemBk_flag_", py::arithmetic())
			.value("list_drawItemBk_flag_nothing", list_drawItemBk_flag_nothing)
			.value("list_drawItemBk_flag_leave", list_drawItemBk_flag_leave)
			.value("list_drawItemBk_flag_stay", list_drawItemBk_flag_stay)
			.value("list_drawItemBk_flag_select", list_drawItemBk_flag_select)
			.value("list_drawItemBk_flag_group_leave", list_drawItemBk_flag_group_leave)
			.value("list_drawItemBk_flag_group_stay", list_drawItemBk_flag_group_stay)
			.value("list_drawItemBk_flag_line", list_drawItemBk_flag_line)
			.value("list_drawItemBk_flag_lineV", list_drawItemBk_flag_lineV)
			.export_values();

		py::enum_<messageBox_flag_>(m, "messageBox_flag_", py::arithmetic())
			.value("messageBox_flag_other", messageBox_flag_other)
			.value("messageBox_flag_ok", messageBox_flag_ok)
			.value("messageBox_flag_cancel", messageBox_flag_cancel)
			.value("messageBox_flag_icon_appicon", messageBox_flag_icon_appicon)
			.value("messageBox_flag_icon_info", messageBox_flag_icon_info)
			.value("messageBox_flag_icon_qustion", messageBox_flag_icon_qustion)
			.value("messageBox_flag_icon_error", messageBox_flag_icon_error)
			.value("messageBox_flag_icon_warning", messageBox_flag_icon_warning)
			.value("messageBox_flag_icon_shield", messageBox_flag_icon_shield)
			.export_values();

		py::enum_<propertyGrid_item_type_>(m, "propertyGrid_item_type_", py::arithmetic())
			.value("propertyGrid_item_type_text", propertyGrid_item_type_text)
			.value("propertyGrid_item_type_edit", propertyGrid_item_type_edit)
			.value("propertyGrid_item_type_edit_color", propertyGrid_item_type_edit_color)
			.value("propertyGrid_item_type_edit_file", propertyGrid_item_type_edit_file)
			.value("propertyGrid_item_type_edit_set", propertyGrid_item_type_edit_set)
			.value("propertyGrid_item_type_comboBox", propertyGrid_item_type_comboBox)
			.value("propertyGrid_item_type_group", propertyGrid_item_type_group)
			.value("propertyGrid_item_type_panel", propertyGrid_item_type_panel)
			.export_values();

		py::enum_<zorder_>(m, "zorder_", py::arithmetic())
			.value("zorder_top", zorder_top)
			.value("zorder_bottom", zorder_bottom)
			.value("zorder_before", zorder_before)
			.value("zorder_after", zorder_after)
			.export_values();

		py::enum_<pane_align_>(m, "pane_align_", py::arithmetic())
			.value("pane_align_error", pane_align_error)
			.value("pane_align_left", pane_align_left)
			.value("pane_align_top", pane_align_top)
			.value("pane_align_right", pane_align_right)
			.value("pane_align_bottom", pane_align_bottom)
			.value("pane_align_center", pane_align_center)
			.export_values();

		py::enum_<layout_align_>(m, "layout_align_", py::arithmetic())
			.value("layout_align_left", layout_align_left)
			.value("layout_align_top", layout_align_top)
			.value("layout_align_right", layout_align_right)
			.value("layout_align_bottom", layout_align_bottom)
			.value("layout_align_center", layout_align_center)
			.value("layout_align_equidistant", layout_align_equidistant)
			.export_values();

		py::enum_<layout_size_>(m, "layout_size_", py::arithmetic())
			.value("layout_size_fixed", layout_size_fixed)
			.value("layout_size_fill", layout_size_fill)
			.value("layout_size_auto", layout_size_auto)
			.value("layout_size_weight", layout_size_weight)
			.value("layout_size_percent", layout_size_percent)
			.value("layout_size_disable", layout_size_disable)
			.export_values();

		py::enum_<layout_align_axis_>(m, "layout_align_axis_", py::arithmetic())
			.value("layout_align_axis_auto", layout_align_axis_auto)
			.value("layout_align_axis_start", layout_align_axis_start)
			.value("layout_align_axis_center", layout_align_axis_center)
			.value("layout_align_axis_end", layout_align_axis_end)
			.export_values();

		py::enum_<edit_textAlign_flag_>(m, "edit_textAlign_flag_", py::arithmetic())
			.value("edit_textAlign_flag_left", edit_textAlign_flag_left)
			.value("edit_textAlign_flag_right", edit_textAlign_flag_right)
			.value("edit_textAlign_flag_center", edit_textAlign_flag_center)
			.value("edit_textAlign_flag_top", edit_textAlign_flag_top)
			.value("edit_textAlign_flag_bottom", edit_textAlign_flag_bottom)
			.value("edit_textAlign_flag_center_v", edit_textAlign_flag_center_v)
			.export_values();

		py::enum_<pane_state_>(m, "pane_state_", py::arithmetic())
			.value("pane_state_error", pane_state_error)
			.value("pane_state_any", pane_state_any)
			.value("pane_state_lock", pane_state_lock)
			.value("pane_state_dock", pane_state_dock)
			.value("pane_state_float", pane_state_float)
			.export_values();

		py::enum_<textFormatFlag_>(m, "textFormatFlag_", py::arithmetic())
			.value("textAlignFlag_left", textAlignFlag_left)
			.value("textAlignFlag_top", textAlignFlag_top)
			.value("textAlignFlag_left_top", textAlignFlag_left_top)
			.value("textAlignFlag_center", textAlignFlag_center)
			.value("textAlignFlag_right", textAlignFlag_right)
			.value("textAlignFlag_vcenter", textAlignFlag_vcenter)
			.value("textAlignFlag_bottom", textAlignFlag_bottom)
			.value("textFormatFlag_DirectionRightToLeft", textFormatFlag_DirectionRightToLeft)
			.value("textFormatFlag_NoWrap", textFormatFlag_NoWrap)
			.value("textFormatFlag_DirectionVertical", textFormatFlag_DirectionVertical)
			.value("textFormatFlag_NoFitBlackBox", textFormatFlag_NoFitBlackBox)
			.value("textFormatFlag_DisplayFormatControl", textFormatFlag_DisplayFormatControl)
			.value("textFormatFlag_NoFontFallback", textFormatFlag_NoFontFallback)
			.value("textFormatFlag_MeasureTrailingSpaces", textFormatFlag_MeasureTrailingSpaces)
			.value("textFormatFlag_LineLimit", textFormatFlag_LineLimit)
			.value("textFormatFlag_NoClip", textFormatFlag_NoClip)
			.value("textTrimming_None", textTrimming_None)
			.value("textTrimming_Character", textTrimming_Character)
			.value("textTrimming_Word", textTrimming_Word)
			.value("textTrimming_EllipsisCharacter", textTrimming_EllipsisCharacter)
			.value("textTrimming_EllipsisWord", textTrimming_EllipsisWord)
			.value("textTrimming_EllipsisPath", textTrimming_EllipsisPath)
			.export_values();

		py::enum_<XC_DWRITE_RENDERING_MODE>(m, "XC_DWRITE_RENDERING_MODE", py::arithmetic())
			.value("XC_DWRITE_RENDERING_MODE_DEFAULT", XC_DWRITE_RENDERING_MODE_DEFAULT)
			.value("XC_DWRITE_RENDERING_MODE_ALIASED", XC_DWRITE_RENDERING_MODE_ALIASED)
			.value("XC_DWRITE_RENDERING_MODE_CLEARTYPE_GDI_CLASSIC", XC_DWRITE_RENDERING_MODE_CLEARTYPE_GDI_CLASSIC)
			.value("XC_DWRITE_RENDERING_MODE_CLEARTYPE_GDI_NATURAL", XC_DWRITE_RENDERING_MODE_CLEARTYPE_GDI_NATURAL)
			.value("XC_DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL", XC_DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL)
			.value("XC_DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL_SYMMETRIC", XC_DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL_SYMMETRIC)
			.value("XC_DWRITE_RENDERING_MODE_OUTLINE", XC_DWRITE_RENDERING_MODE_OUTLINE)
			.export_values();

		py::enum_<listItemTemp_type_>(m, "listItemTemp_type_", py::arithmetic())
			.value("listItemTemp_type_tree", listItemTemp_type_tree)
			.value("listItemTemp_type_listBox", listItemTemp_type_listBox)
			.value("listItemTemp_type_list_head", listItemTemp_type_list_head)
			.value("listItemTemp_type_list_item", listItemTemp_type_list_item)
			.value("listItemTemp_type_listView_group", listItemTemp_type_listView_group)
			.value("listItemTemp_type_listView_item", listItemTemp_type_listView_item)
			.value("listItemTemp_type_list", listItemTemp_type_list)
			.value("listItemTemp_type_listView", listItemTemp_type_listView)
			.export_values();

		py::enum_<adjustLayout_>(m, "adjustLayout_", py::arithmetic())
			.value("adjustLayout_no", adjustLayout_no)
			.value("adjustLayout_all", adjustLayout_all)
			.value("adjustLayout_self", adjustLayout_self)
			.export_values();

		py::enum_<edit_type_>(m, "edit_type_", py::arithmetic())
			.value("edit_type_none", edit_type_none)
			.value("edit_type_editor", edit_type_editor)
			.value("edit_type_richedit", edit_type_richedit)
			.value("edit_type_chat", edit_type_chat)
			.value("edit_type_codeTable", edit_type_codeTable)
			.export_values();

		py::enum_<edit_style_type_>(m, "edit_style_type_", py::arithmetic())
			.value("edit_style_type_font_color", edit_style_type_font_color)
			.value("edit_style_type_image", edit_style_type_image)
			.value("edit_style_type_obj", edit_style_type_obj)
			.export_values();

		py::enum_<chat_flag_>(m, "chat_flag_", py::arithmetic())
			.value("chat_flag_left", chat_flag_left)
			.value("chat_flag_right", chat_flag_right)
			.value("chat_flag_center", chat_flag_center)
			.value("chat_flag_next_row_bubble", chat_flag_next_row_bubble)
			.export_values();

		py::enum_<table_flag_>(m, "table_flag_", py::arithmetic())
			.value("table_flag_full", table_flag_full)
			.value("table_flag_none", table_flag_none)
			.export_values();

		py::enum_<table_line_flag_>(m, "table_line_flag_", py::arithmetic())
			.value("table_line_flag_left", table_line_flag_left)
			.value("table_line_flag_top", table_line_flag_top)
			.value("table_line_flag_right", table_line_flag_right)
			.value("table_line_flag_bottom", table_line_flag_bottom)
			.value("table_line_flag_left2", table_line_flag_left2)
			.value("table_line_flag_top2", table_line_flag_top2)
			.value("table_line_flag_right2", table_line_flag_right2)
			.value("table_line_flag_bottom2", table_line_flag_bottom2)
			.export_values();

		py::enum_<monthCal_button_type_>(m, "monthCal_button_type_", py::arithmetic())
			.value("monthCal_button_type_today", monthCal_button_type_today)
			.value("monthCal_button_type_last_year", monthCal_button_type_last_year)
			.value("monthCal_button_type_next_year", monthCal_button_type_next_year)
			.value("monthCal_button_type_last_month", monthCal_button_type_last_month)
			.value("monthCal_button_type_next_month", monthCal_button_type_next_month)
			.export_values();

		py::enum_<fontStyle_>(m, "fontStyle_", py::arithmetic())
			.value("fontStyle_regular", fontStyle_regular)
			.value("fontStyle_bold", fontStyle_bold)
			.value("fontStyle_italic", fontStyle_italic)
			.value("fontStyle_boldItalic", fontStyle_boldItalic)
			.value("fontStyle_underline", fontStyle_underline)
			.value("fontStyle_strikeout", fontStyle_strikeout)
			.export_values();

		py::enum_<adapter_date_type_>(m, "adapter_date_type_", py::arithmetic())
			.value("adapter_date_type_error", adapter_date_type_error)
			.value("adapter_date_type_int", adapter_date_type_int)
			.value("adapter_date_type_float", adapter_date_type_float)
			.value("adapter_date_type_string", adapter_date_type_string)
			.value("adapter_date_type_image", adapter_date_type_image)
			.export_values();

		py::enum_<ease_type_>(m, "ease_type_", py::arithmetic())
			.value("easeIn", easeIn)
			.value("easeOut", easeOut)
			.value("easeInOut", easeInOut)
			.export_values();

		py::enum_<ease_flag_>(m, "ease_flag_", py::arithmetic())
			.value("ease_flag_linear", ease_flag_linear)
			.value("ease_flag_quad", ease_flag_quad)
			.value("ease_flag_cubic", ease_flag_cubic)
			.value("ease_flag_quart", ease_flag_quart)
			.value("ease_flag_quint", ease_flag_quint)
			.value("ease_flag_sine", ease_flag_sine)
			.value("ease_flag_expo", ease_flag_expo)
			.value("ease_flag_circ", ease_flag_circ)
			.value("ease_flag_elastic", ease_flag_elastic)
			.value("ease_flag_back", ease_flag_back)
			.value("ease_flag_bounce", ease_flag_bounce)
			.value("ease_flag_in", ease_flag_in)
			.value("ease_flag_out", ease_flag_out)
			.value("ease_flag_inOut", ease_flag_inOut)
			.export_values();

		py::enum_<notifyMsg_skin_>(m, "notifyMsg_skin_", py::arithmetic())
			.value("notifyMsg_skin_no", notifyMsg_skin_no)
			.value("notifyMsg_skin_success", notifyMsg_skin_success)
			.value("notifyMsg_skin_warning", notifyMsg_skin_warning)
			.value("notifyMsg_skin_message", notifyMsg_skin_message)
			.value("notifyMsg_skin_error", notifyMsg_skin_error)
			.export_values();

		py::enum_<animation_move_>(m, "animation_move_", py::arithmetic())
			.value("animation_move_x", animation_move_x)
			.value("animation_move_y", animation_move_y)
			.export_values();

		py::enum_<bkObject_align_flag_>(m, "bkObject_align_flag_", py::arithmetic())
			.value("bkObject_align_flag_no", bkObject_align_flag_no)
			.value("bkObject_align_flag_left", bkObject_align_flag_left)
			.value("bkObject_align_flag_top", bkObject_align_flag_top)
			.value("bkObject_align_flag_right", bkObject_align_flag_right)
			.value("bkObject_align_flag_bottom", bkObject_align_flag_bottom)
			.value("bkObject_align_flag_center", bkObject_align_flag_center)
			.value("bkObject_align_flag_center_v", bkObject_align_flag_center_v)
			.export_values();

		py::enum_<frameWnd_cell_type_>(m, "frameWnd_cell_type_", py::arithmetic())
			.value("frameWnd_cell_type_no", frameWnd_cell_type_no)
			.value("frameWnd_cell_type_pane", frameWnd_cell_type_pane)
			.value("frameWnd_cell_type_group", frameWnd_cell_type_group)
			.value("frameWnd_cell_type_bodyView", frameWnd_cell_type_bodyView)
			.value("frameWnd_cell_type_top_bottom", frameWnd_cell_type_top_bottom)
			.value("frameWnd_cell_type_left_right", frameWnd_cell_type_left_right)
			.export_values();

		py::enum_<window_state_flag_>(m, "window_state_flag_", py::arithmetic())
			.value("window_state_flag_nothing", window_state_flag_nothing)
			.value("window_state_flag_leave", window_state_flag_leave)
			.value("window_state_flag_body_leave", window_state_flag_body_leave)
			.value("window_state_flag_top_leave", window_state_flag_top_leave)
			.value("window_state_flag_bottom_leave", window_state_flag_bottom_leave)
			.value("window_state_flag_left_leave", window_state_flag_left_leave)
			.value("window_state_flag_right_leave", window_state_flag_right_leave)
			.value("window_state_flag_layout_body", window_state_flag_layout_body)
			.export_values();

		py::enum_<element_state_flag_>(m, "element_state_flag_", py::arithmetic())
			.value("element_state_flag_nothing", element_state_flag_nothing)
			.value("element_state_flag_enable", element_state_flag_enable)
			.value("element_state_flag_disable", element_state_flag_disable)
			.value("element_state_flag_focus", element_state_flag_focus)
			.value("element_state_flag_focus_no", element_state_flag_focus_no)
			.value("element_state_flag_focusEx", element_state_flag_focusEx)
			.value("element_state_flag_focusEx_no", element_state_flag_focusEx_no)
			.value("layout_state_flag_layout_body", layout_state_flag_layout_body)
			.value("element_state_flag_leave", element_state_flag_leave)
			.value("element_state_flag_stay", element_state_flag_stay)
			.value("element_state_flag_down", element_state_flag_down)
			.export_values();

		py::enum_<button_state_flag_>(m, "button_state_flag_", py::arithmetic())
			.value("button_state_flag_leave", button_state_flag_leave)
			.value("button_state_flag_stay", button_state_flag_stay)
			.value("button_state_flag_down", button_state_flag_down)
			.value("button_state_flag_check", button_state_flag_check)
			.value("button_state_flag_check_no", button_state_flag_check_no)
			.value("button_state_flag_WindowRestore", button_state_flag_WindowRestore)
			.value("button_state_flag_WindowMaximize", button_state_flag_WindowMaximize)
			.export_values();

		py::enum_<comboBox_state_flag_>(m, "comboBox_state_flag_", py::arithmetic())
			.value("comboBox_state_flag_leave", comboBox_state_flag_leave)
			.value("comboBox_state_flag_stay", comboBox_state_flag_stay)
			.value("comboBox_state_flag_down", comboBox_state_flag_down)
			.export_values();

		py::enum_<listBox_state_flag_>(m, "listBox_state_flag_", py::arithmetic())
			.value("listBox_state_flag_item_leave", listBox_state_flag_item_leave)
			.value("listBox_state_flag_item_stay", listBox_state_flag_item_stay)
			.value("listBox_state_flag_item_select", listBox_state_flag_item_select)
			.value("listBox_state_flag_item_select_no", listBox_state_flag_item_select_no)
			.export_values();

		py::enum_<list_state_flag_>(m, "list_state_flag_", py::arithmetic())
			.value("list_state_flag_item_leave", list_state_flag_item_leave)
			.value("list_state_flag_item_stay", list_state_flag_item_stay)
			.value("list_state_flag_item_select", list_state_flag_item_select)
			.value("list_state_flag_item_select_no", list_state_flag_item_select_no)
			.export_values();

		py::enum_<listHeader_state_flag_>(m, "listHeader_state_flag_", py::arithmetic())
			.value("listHeader_state_flag_item_leave", listHeader_state_flag_item_leave)
			.value("listHeader_state_flag_item_stay", listHeader_state_flag_item_stay)
			.value("listHeader_state_flag_item_down", listHeader_state_flag_item_down)
			.export_values();

		py::enum_<listView_state_flag_>(m, "listView_state_flag_", py::arithmetic())
			.value("listView_state_flag_item_leave", listView_state_flag_item_leave)
			.value("listView_state_flag_item_stay", listView_state_flag_item_stay)
			.value("listView_state_flag_item_select", listView_state_flag_item_select)
			.value("listView_state_flag_item_select_no", listView_state_flag_item_select_no)
			.value("listView_state_flag_group_leave", listView_state_flag_group_leave)
			.value("listView_state_flag_group_stay", listView_state_flag_group_stay)
			.value("listView_state_flag_group_select", listView_state_flag_group_select)
			.value("listView_state_flag_group_select_no", listView_state_flag_group_select_no)
			.export_values();

		py::enum_<tree_state_flag_>(m, "tree_state_flag_", py::arithmetic())
			.value("tree_state_flag_item_leave", tree_state_flag_item_leave)
			.value("tree_state_flag_item_stay", tree_state_flag_item_stay)
			.value("tree_state_flag_item_select", tree_state_flag_item_select)
			.value("tree_state_flag_item_select_no", tree_state_flag_item_select_no)
			.value("tree_state_flag_group", tree_state_flag_group)
			.value("tree_state_flag_group_no", tree_state_flag_group_no)
			.export_values();

		py::enum_<monthCal_state_flag_>(m, "monthCal_state_flag_", py::arithmetic())
			.value("monthCal_state_flag_leave", monthCal_state_flag_leave)
			.value("monthCal_state_flag_item_leave", monthCal_state_flag_item_leave)
			.value("monthCal_state_flag_item_stay", monthCal_state_flag_item_stay)
			.value("monthCal_state_flag_item_down", monthCal_state_flag_item_down)
			.value("monthCal_state_flag_item_select", monthCal_state_flag_item_select)
			.value("monthCal_state_flag_item_select_no", monthCal_state_flag_item_select_no)
			.value("monthCal_state_flag_item_today", monthCal_state_flag_item_today)
			.value("monthCal_state_flag_item_last_month", monthCal_state_flag_item_last_month)
			.value("monthCal_state_flag_item_cur_month", monthCal_state_flag_item_cur_month)
			.value("monthCal_state_flag_item_next_month", monthCal_state_flag_item_next_month)
			.export_values();

		py::enum_<propertyGrid_state_flag_>(m, "propertyGrid_state_flag_", py::arithmetic())
			.value("propertyGrid_state_flag_item_leave", propertyGrid_state_flag_item_leave)
			.value("propertyGrid_state_flag_item_stay", propertyGrid_state_flag_item_stay)
			.value("propertyGrid_state_flag_item_select", propertyGrid_state_flag_item_select)
			.value("propertyGrid_state_flag_item_select_no", propertyGrid_state_flag_item_select_no)
			.value("propertyGrid_state_flag_group_leave", propertyGrid_state_flag_group_leave)
			.value("propertyGrid_state_flag_group_expand", propertyGrid_state_flag_group_expand)
			.value("propertyGrid_state_flag_group_expand_no", propertyGrid_state_flag_group_expand_no)
			.export_values();

		py::enum_<pane_state_flag_>(m, "pane_state_flag_", py::arithmetic())
			.value("pane_state_flag_leave", pane_state_flag_leave)
			.value("pane_state_flag_stay", pane_state_flag_stay)
			.value("pane_state_flag_caption", pane_state_flag_caption)
			.value("pane_state_flag_body", pane_state_flag_body)
			.export_values();

		py::enum_<layout_state_flag_>(m, "layout_state_flag_", py::arithmetic())
			.value("layout_state_flag_nothing", layout_state_flag_nothing)
			.value("layout_state_flag_full", layout_state_flag_full)
			.value("layout_state_flag_body", layout_state_flag_body)
			.export_values();


	}
}

