#pragma once
#include "pch.h"
#include "xcgui/XCFont.hpp"

namespace xcgui {

	void declareFont(py::module& m) {

		py::class_<XCFont, XCObject>(m, "XFont");
	}
}