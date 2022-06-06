#pragma once
#include "pch.h"
#include "xcgui/shape/XCShapeEllipse.hpp"

namespace xcgui {

	void declareShapeEllipse(py::module& m) {
		py::class_<XCShapeEllipse, XCShape>(m, "XShapeEllipse")
			PYCASTOBJECT(XCShapeEllipse)
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCShapeEllipse obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCShapeEllipse obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)


			.def("setBorderColor", &XCShapeEllipse::SetBorderColor, "color"_a)
			.def("setFillColor", &XCShapeEllipse::SetFillColor, "color"_a)
			.def("enableBorder", &XCShapeEllipse::EnableBorder, "enable"_a)
			.def("enableFill", &XCShapeEllipse::EnableFill, "enable"_a)				
			;
	}
}