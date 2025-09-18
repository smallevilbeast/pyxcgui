#pragma once
#include "pch.h"
#include <vector>
#include "xcgui/element/XCEdit.hpp"
#include "xcgui/XCFont.hpp"
#include "binding/manager/XCastManager.hpp"

namespace xcgui {

	void declareEdit(py::module& m) {

		py::class_<XCEdit, XCScrollView>(m, "XEdit")
			PYCASTOBJECT(XCEdit)
			PYOBJECTVALID(XCEdit, XC_EDIT)
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCEdit obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

			.def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCEdit obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)
			
			
			.def("enableAutoWrap", &XCEdit::EnableAutoWrap, "enable"_a)
			.def("enableReadOnly", &XCEdit::EnableReadOnly, "enable"_a)
			.def("enableMultiLine", &XCEdit::EnableMultiLine, "enable"_a)
			.def("enablePassword", &XCEdit::EnablePassword, "enable"_a)
			.def("enableAutoSelAll", &XCEdit::EnableAutoSelAll, "enable"_a)
			.def("enableAutoCancelSel", &XCEdit::EnableAutoCancelSel, "enable"_a)

			.def("isReadOnly", &XCEdit::IsReadOnly)
			.def("isMultiLine", &XCEdit::IsMultiLine)
			.def("isPassword", &XCEdit::IsPassword)
			.def("isAutoWrap", &XCEdit::IsAutoWrap)
			.def("isEmpty", &XCEdit::IsEmpty)
			.def("isInSelect", &XCEdit::IsInSelect, "row"_a, "column"_a)
			.def("getRowCount", &XCEdit::GetRowCount)

			.def("getData", &XCEdit::GetData, py::return_value_policy::take_ownership)
			.def("addData", [](XCEdit& self, edit_data_copy_* data, std::vector<USHORT> styleTable){
				self.AddData(data, &styleTable[0], styleTable.size());
			}, "data"_a, "styleTableList"_a)
		    .def("freeData", &XCEdit::FreeData, "data"_a)

			.def("setDefaultText", &XCEdit::SetDefaultText, "text"_a)
			.def("setDefaultTextColor", &XCEdit::SetDefaultTextColor, "color"_a)
			.def("setPasswordCharacter", &XCEdit::SetPasswordCharacter, "ch"_a)
			.def("setTextAlign", &XCEdit::SetTextAlign, "align"_a)
			.def("setTabSpace", &XCEdit::SetTabSpace, "space"_a)
			
			.def("setBackFont", [](XCEdit& self, const XCFont& font) {
				self.SetBackFont(font.getFontHandle());
			}, "font"_a)

			.def("setSpaceSize", &XCEdit::SetSpaceSize, "size"_a)
			.def("setCharSpaceSize", &XCEdit::SetCharSpaceSize, "size"_a, "sizeZh"_a)
			.def("setText", &XCEdit::SetText, "text"_a)
			.def("setTextInt", &XCEdit::SetTextInt, "value"_a)
			.def("getText", &XCEdit::GetText, "maxSize"_a=-1)
			.def("getTextTemp", &XCEdit::GetText_Temp)
			.def("getTextRow", &XCEdit::GetTextRow, "row"_a, "maxSize"_a=-1)
			.def("getLength", &XCEdit::GetLength)
			.def("getLengthRow", &XCEdit::GetLengthRow, "row"_a)
			.def("insertText", &XCEdit::InsertText, "row"_a, "column"_a, "text"_a)
			.def("insertChatBegin", [](XCEdit& self, const XCImage& avatarImage, const XCImage& bubbleImage, int flag) {
				self.InsertChatBegin(avatarImage.getImageHandle(), bubbleImage.getImageHandle(), flag);
			}, "avatarImage"_a, "bubbleImage"_a, "flag"_a)
			.def("setChatMaxWidth", &XCEdit::SetChatMaxWidth, "width"_a)
			.def("getChatFlags", &XCEdit::GetChatFlags)
			.def("insertTextEx", &XCEdit::InsertTextEx, "row"_a, "column"_a, "text"_a, "style"_a)
			.def("insertObject", [](XCEdit& self, const XCObject& obj, int row, int col) {
				self.InsertObject(row, col, obj.GetHandle());
			}, "obj"_a, "row"_a, "column"_a)
			.def("addText", &XCEdit::AddText, "text"_a)
			.def("addTextUser", &XCEdit::AddTextUser, "text"_a)
			.def("addTextEx", &XCEdit::AddTextEx, "text"_a, "style"_a)
			.def("addObject", [](XCEdit& self, const XCObject& obj) {
				return self.AddObject(obj.GetHandle());
			}, "obj"_a)

			.def("addByStyle", &XCEdit::AddByStyle, "style"_a)
			.def("addStyle", [](XCEdit& self, const XCObject& obj, COLORREF color, bool bColor) {
				return self.AddObject(obj.GetHandle());
			}, "obj"_a, "color"_a, "enableColor"_a)
			.def("addStyleEx", &XCEdit::AddStyleEx, "fontName"_a, "fontSize"_a, "fontStyle"_a, "color"_a, "enableColor"_a)
			.def("modifyStyle", [](XCEdit& self, int style, const XCFont& font, COLORREF color, bool bColor) {
				return self.ModifyStyle(style, font.getFontHandle(), color, bColor);
			}, "style"_a, "font"_a, "color"_a, "enableColor"_a)
			.def("releaseStyle", &XCEdit::ReleaseStyle, "style"_a)

			.def("getStyleInfo", [](XCEdit& self, int style) {
				edit_style_info_ info = { 0 };
				self.GetStyleInfo(style, &info);
				return info;
			}, "style"_a)

			.def("setCurStyle", &XCEdit::SetCurStyle, "style"_a)
			.def("setSelectTextStyle", &XCEdit::SetSelectTextStyle, "style"_a)
			
			.def("setCaretColor", &XCEdit::SetCaretColor, "color"_a)
			.def("setCaretWidth", &XCEdit::SetCaretWidth, "width"_a)
			.def("setSelectBkColor", &XCEdit::SetSelectBkColor, "color"_a)
			.def("setRowHeight", &XCEdit::SetRowHeight, "row"_a)
			.def("setRowHeightEx", &XCEdit::SetRowHeightEx, "row"_a, "height"_a)
			.def("setRowSpace", &XCEdit::SetRowSpace, "space"_a)
			.def("setCurPos", &XCEdit::SetCurPos, "pos"_a)
			.def("getCurPos", &XCEdit::GetCurPos)
			.def("setCurPosEx", &XCEdit::SetCurPosEx, "row"_a, "column"_a)
			.def("getCurPosEx", [](XCEdit& self) {
				position_ info = { 0 };
				self.GetCurPosEx(&info.iRow, &info.iColumn);
				return info;
			})
			.def("getCurRow", &XCEdit::GetCurRow)
			.def("getCurCol", &XCEdit::GetCurCol)
			.def("moveEnd", &XCEdit::MoveEnd)


			.def("getPoint", [](XCEdit& self, int row, int col) {
				XCPoint info;
				self.GetPoint(row, col, (POINT*)&info);
				return info;
			}, "row"_a, "column"_a)

			.def("autoScroll", &XCEdit::AutoScroll)
			.def("autoScrollEx", &XCEdit::AutoScrollEx, "row"_a, "column"_a)
			
			.def("posToRowCol", [](XCEdit& self, int pos) {
				position_ info;
				self.PosToRowCol(pos, &info);
				return info;
			}, "pos"_a)
			.def("rowColToPos", &XCEdit::RowColToPos, "row"_a, "column"_a)


			.def("selectAll", &XCEdit::SelectAll)
			.def("cancelSelect", &XCEdit::CancelSelect)
			.def("deleteSelect", &XCEdit::DeleteSelect)
			.def("setSelect", &XCEdit::SetSelect, "startRow"_a, "startCol"_a, "endRow"_a, "endCol"_a)
			.def("getSelectText", &XCEdit::GetSelectText, "maxSize"_a=-1)
			.def("getSelectTextLength", &XCEdit::GetSelectTextLength)
			.def("getSelectRange", [](XCEdit& self) {
				position_ begin;
				position_ end;
				self.GetSelectRange(&begin, &end);

				std::vector<position_> out;
				out.emplace_back(begin);
				out.emplace_back(end);
				return out;
			})
			.def("getVisibleRowRange", [](XCEdit& self) {
				int start =0;
				int end = 0;
				self.GetVisibleRowRange(&start, &end);

				std::vector<int> out;
				out.emplace_back(start);
				out.emplace_back(end);
				return out;
			})

			.def("delete", &XCEdit::Delete, "startRow"_a, "startCol"_a, "endRow"_a, "endCol"_a)
			.def("deleteRow", &XCEdit::DeleteRow, "row"_a)

			.def("clipboardCut", &XCEdit::ClipboardCut)
			.def("clipboardCopy", &XCEdit::ClipboardCopy)
			.def("clipboardPaste", &XCEdit::ClipboardPaste)
			.def("undo", &XCEdit::Undo)
			.def("redo", &XCEdit::Redo)
			.def("addChatBegin", [](XCEdit& self, const XCImage& avatar, const XCImage& bubble, int flag) {
				self.AddChatBegin(avatar.getImageHandle(), bubble.getImageHandle(), flag);
			}, "avatar"_a, "bubble"_a, "flag"_a)

			.def("addChatEnd", &XCEdit::AddChatEnd)
			.def("setChatIndentation", &XCEdit::SetChatIndentation, "indentation"_a)

			;
	}
}