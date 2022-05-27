#pragma once
#include "pch.h"
#include "xcgui/XCBkManager.hpp"

namespace xcgui {

	void declareBkManager(py::module& m) {

		py::class_<XCBkManager, XCObject>(m, "XBkManager");
	}
}