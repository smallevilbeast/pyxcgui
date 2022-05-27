#pragma once
#include "pch.h"
#include "xcgui/XCDraw.hpp"

namespace xcgui {

	void declareDraw(py::module& m) {

		py::class_<XCDraw, XCObject>(m, "XDraw");
	}
}