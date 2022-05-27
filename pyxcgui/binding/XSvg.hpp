#pragma once
#include "pch.h"
#include "xcgui/XCSvg.hpp"

namespace xcgui {

	void declareSvg(py::module& m) {

		py::class_<XCSvg, XCObject>(m, "XSvg");
	}
}