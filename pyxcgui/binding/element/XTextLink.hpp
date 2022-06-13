#pragma once
#include "pch.h"
#include "xcgui/element/XCTextLink.hpp"


namespace xcgui {

	void declareTextLink(py::module& m) {
		py::class_<XCTextLink, XCButton>(m, "XTextLink")
			PYCASTOBJECT(XCTextLink)
			PYOBJECTVALID(XCTextLink, XC_TEXTLINK)
			.def(py::init([](int x, int y, int cx, int cy, const std::wstring& text, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCTextLink textLink(x, y, cx, cy, text, handle);
				return textLink;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "text"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, const std::wstring& text, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCTextLink textLink(0,0, cx, cy, text, handle);
				return textLink;
			}), "width"_a, "height"_a, "text"_a, "parent"_a=nullptr)

			.def("enableUnderlineLeave", &XCTextLink::EnableUnderlineLeave, "enable"_a)
			.def("enableUnderlineStay", &XCTextLink::EnableUnderlineStay, "enable"_a)
			.def("setTextColorStay", &XCTextLink::SetTextColorStay, "color"_a)
			.def("setUnderlineColorLeave", &XCTextLink::SetUnderlineColorLeave, "color"_a)
			.def("setUnderlineColorStay", &XCTextLink::SetUnderlineColorStay, "color"_a)

			;
	}
}