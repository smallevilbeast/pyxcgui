 #pragma once
#include "pch.h"
#include "xcgui/shape/XCShapeLine.hpp"

namespace xcgui {

	void declareShapeLine(py::module& m) {
		py::class_<XCShapeLine, XCShape>(m, "XShapeLine")
			PYCASTOBJECT(XCShapeLine)
			PYOBJECTVALID(XCShapeLine, XC_SHAPE_LINE)
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCShapeLine obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCShapeLine obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)


			.def("setColor", &XCShapeLine::SetColor, "color"_a)
			.def("setPosition", &XCShapeLine::SetPosition, "x1"_a, "y1"_a, "x2"_a, "y2"_a)				
			;
	}
}