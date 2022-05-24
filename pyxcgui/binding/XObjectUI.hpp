#pragma once
#include "pch.h"
#include "xcgui/XCObjectUI.hpp"

namespace xcgui {

	void declareObjectUI(py::module& m) {

		py::class_<XCObjectUI, XCObject>(m, "XObjectUI")
			.def("setStyle", &XCObjectUI::SetStyle, "style"_a)
			.def("getStyle", &XCObjectUI::GetStyle)
			.def("enableCss", &XCObjectUI::EnableCSS, "enable"_a)
			.def("setCssName", &XCObjectUI::SetCssName, "name"_a)
			.def("getCssName", &XCObjectUI::GetCssName);

	}
}