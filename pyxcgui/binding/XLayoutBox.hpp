#pragma once
#include "pch.h"
#include "xcgui/XCLayoutBox.hpp"

namespace xcgui {

	void declareLayoutBox(py::module& m) {

		py::class_<XCLayoutBox, XCObject>(m, "XLayoutBox")
			PYCASTOBJECT(XCLayoutBox)
			.def("enableHorizon", &XCLayoutBox::EnableHorizon, "enable"_a)
			.def("enableAutoWrap", &XCLayoutBox::EnableAutoWrap, "enable"_a)
			.def("enableOverflowHide", &XCLayoutBox::EnableOverflowHide, "enable"_a)
			.def("setAlignH", &XCLayoutBox::SetAlignH, "align"_a)
			.def("setAlignV", &XCLayoutBox::SetAlignV, "align"_a)
			.def("setAlignBaseline", &XCLayoutBox::SetAlignBaseline, "align"_a)
			.def("setSpace", &XCLayoutBox::SetSpace, "space"_a)
			.def("setSpaceRow", &XCLayoutBox::SetSpaceRow, "space"_a);
	}
}
