#pragma once
#include "pch.h"
#include "xcgui/shape/XCShapeTable.hpp"
#include "xcgui/XCStruct.hpp"
#include "xcgui/XCFont.hpp"

namespace xcgui {

	void declareShapeTable(py::module& m) {
		py::class_<XCShapeTable, XCShape>(m, "XShapeTable")
			PYCASTOBJECT(XCShapeTable)
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCShapeTable obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCShapeTable obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)


			.def("reset", &XCShapeTable::Reset, "row"_a, "column"_a)
			.def("comboRow", &XCShapeTable::ComboRow, "row"_a, "column"_a, "count"_a)
			.def("comboColumn", &XCShapeTable::ComboCol, "row"_a, "column"_a, "count"_a)
			.def("setColumnWidth", &XCShapeTable::SetColWidth, "column"_a, "width"_a)
			.def("setRowHeight", &XCShapeTable::SetRowHeight, "row"_a, "height"_a)
			.def("setBorderColor", &XCShapeTable::SetBorderColor, "color"_a)
			.def("setTextColor", &XCShapeTable::SetTextColor, "color"_a)
			.def("setFont", [](XCShapeTable& self, const XCFont& font) {
				self.SetFont(font.getFontHandle());
			}, "font"_a)

			.def("setItemPadding", &XCShapeTable::SetItemPadding, "left"_a, "top"_a, "right"_a, "bottom"_a)
			.def("setItemText", &XCShapeTable::SetItemText, "row"_a, "column"_a, "text"_a)
			.def("setItemFont", [](XCShapeTable& self, int iRow, int iCol, const XCFont& font) {
				self.SetItemFont(iRow, iCol, font.getFontHandle());
			}, "row"_a, "column"_a, "font"_a)
			.def("setItemTextAlign", &XCShapeTable::SetItemTextAlign, "row"_a, "column"_a, "align"_a)
			.def("setItemTextColor", &XCShapeTable::SetItemTextColor, "row"_a, "column"_a, "color"_a, "enable"_a)
			.def("setItemBkColor", &XCShapeTable::SetItemBkColor, "row"_a, "column"_a, "color"_a, "enable"_a)
			.def("setItemLine", &XCShapeTable::SetItemLine, "row1"_a, "column1"_a, "row2"_a, "column2"_a, "flag"_a, "color"_a)
			.def("setItemFlag", &XCShapeTable::SetItemFlag, "row"_a, "column"_a, "flag"_a)
			.def("getItemRect", [](XCShapeTable& self, int iRow, int iCol) {
				XCRect info;
				self.GetItemRect(iRow, iCol,(RECT*)&info);
				return info;
			}, "row"_a, "column"_a)
			;
	}
}