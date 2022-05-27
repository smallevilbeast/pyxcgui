#pragma once
#include "pch.h"
#include "xcgui/element/XCButton.hpp"

namespace xcgui {

	void declareButton(py::module& m) {
		py::class_<XCButton, XCElement, XCWidget, XCObjectUI, XCObject>(m, "XButton")
			.def(py::init([](const XCObjectUI& parent, int x, int y, int cx, int cy, const std::wstring& text) {
				XCButton button(x, y, cx, cy, text, parent.GetHandle());
				return button;
				}), "parent"_a, "x"_a, "y"_a, "width"_a, "height"_a, "text"_a)
			.def("getText", &XCButton::GetText);
	}
}