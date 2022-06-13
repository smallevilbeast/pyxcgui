#pragma once
#include "pch.h"
#include "xcgui/shape/XCShapeRect.hpp"

namespace xcgui {

	void declareShapeRect(py::module& m) {
		py::class_<XCShapeRect, XCShape>(m, "XShapeRect")
			PYCASTOBJECT(XCShapeRect)
			PYOBJECTVALID(XCShapeRect, XC_SHAPE_RECT)
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCShapeRect obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCShapeRect obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)


			.def("setBorderColor", &XCShapeRect::SetBorderColor, "color"_a)
			.def("setFillColor", &XCShapeRect::SetFillColor, "color"_a)

			.def("setRoundAngle", &XCShapeRect::SetRoundAngle, "width"_a, "height"_a)
			.def("getRoundAngle", [](XCShapeRect& self) {
				XCSize info;
				self.GetRoundAngle(&info.width, &info.height);
				return info;
			})
			.def("enableBorder", &XCShapeRect::EnableBorder, "enable"_a)
			.def("enableFill", &XCShapeRect::EnableFill, "enable"_a)	
			.def("enableRoundAngle", &XCShapeRect::EnableRoundAngle, "enable"_a)
			;
	}
}