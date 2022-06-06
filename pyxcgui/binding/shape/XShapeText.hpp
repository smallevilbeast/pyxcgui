#pragma once
#include "pch.h"
#include "xcgui/shape/XCShapeText.hpp"
#include "xcgui/XCStruct.hpp"
#include "xcgui/XCFont.hpp"

namespace xcgui {

	void declareShapeText(py::module& m) {
		py::class_<XCShapeText, XCShape>(m, "XShapeText")
			PYCASTOBJECT(XCShapeText)
			.def(py::init([](int x, int y, int cx, int cy, const std::wstring& text, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCShapeText obj(x, y, cx, cy, text, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "text"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, const std::wstring& text, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCShapeText obj(0,0, cx, cy, text, handle);
				return obj;
			}), "width"_a, "height"_a, "text"_a, "parent"_a=nullptr)


			.def("setText", &XCShapeText::SetText, "text"_a)
			.def("getText", &XCShapeText::GetText)
			.def("getTextLength", &XCShapeText::GetTextLength)
		
			.def("setFont", [](XCShapeText& self, const XCFont& font) {
				self.SetFont(font.getFontHandle());
			}, "font"_a)
			.def("getFont", [](XCShapeText& self) -> XCFont* {
				auto handle = self.GetFont();
				if (!handle) return nullptr;
				return new XCFont(handle);
			}, py::return_value_policy::take_ownership)	

				
			.def("setTextColor", &XCShapeText::SetTextColor, "color"_a)
			.def("getTextColor", &XCShapeText::GetTextColor)

			.def("setTextAlign", &XCShapeText::SetTextAlign, "align"_a)
			.def("setOffset", &XCShapeText::SetOffset, "x"_a, "y"_a)

			;
	}
}