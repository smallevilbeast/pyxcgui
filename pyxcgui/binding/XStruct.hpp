#pragma once
#include "pch.h"
#include "xcgui/XCStruct.hpp"


namespace xcgui {

	void declareStruct(py::module& m) {

		py::class_<XCPoint>(m, "XPoint")
			.def(py::init<>())
			.def(py::init<int, int>(), "x"_a, "y"_a)
			.def_readwrite("x", &XCPoint::x)
			.def_readwrite("y", &XCPoint::y);

		py::class_<XCRect>(m, "XRect")
			.def(py::init<>())
			.def(py::init<int, int, int, int>(), "left"_a, "top"_a, "right"_a, "bottom"_a)
			.def_readwrite("left", &XCRect::left)
			.def_readwrite("top", &XCRect::top)
			.def_readwrite("right", &XCRect::right)
			.def_readwrite("bottom", &XCRect::bottom);
	}
}