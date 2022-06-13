#pragma once
#include "pch.h"
#include "xcgui/shape/XCShapeGroupBox.hpp"
#include "xcgui/XCStruct.hpp"
#include "xcgui/XCFont.hpp"

namespace xcgui {

	void declareShapeGroupBox(py::module& m) {
		py::class_<XCShapeGroupBox, XCShape>(m, "XShapeGroupBox")
			PYCASTOBJECT(XCShapeGroupBox)
			PYOBJECTVALID(XCShapeGroupBox, XC_SHAPE_GROUPBOX)
			.def(py::init([](int x, int y, int cx, int cy, const std::wstring& text, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCShapeGroupBox obj(x, y, cx, cy, text, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "text"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, const std::wstring& text, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCShapeGroupBox obj(0,0, cx, cy, text, handle);
				return obj;
			}), "width"_a, "height"_a, "text"_a, "parent"_a=nullptr)


			.def("setBorderColor", &XCShapeGroupBox::SetBorderColor, "color"_a)
			.def("setTextColor", &XCShapeGroupBox::SetTextColor, "color"_a)
			.def("setFont", [](XCShapeGroupBox& self, const XCFont& font) {
				self.SetFontX(font.getFontHandle());
			}, "font"_a)


			.def("setTextOffset", &XCShapeGroupBox::SetTextOffset, "offsetX"_a, "offsetY"_a)
			.def("setRoundAngle", &XCShapeGroupBox::SetRoundAngle, "width"_a, "height"_a)
			.def("setText", &XCShapeGroupBox::SetText, "text"_a)
			.def("getTextOffset", [](XCShapeGroupBox& self) {
				XCPoint pt;
				self.GetTextOffset(&pt.x, &pt.y);
				return pt;
			})
			.def("getRoundAngle", [](XCShapeGroupBox& self) {
				XCSize info;
				self.GetRoundAngle(&info.width, &info.height);
				return info;
			})
			.def("enableRoundAngle", &XCShapeGroupBox::EnableRoundAngle, "enable"_a)

			;
	}
}