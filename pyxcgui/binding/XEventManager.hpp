#pragma once
#include "pch.h"
#include <map>	 
#include <vector>
#include <functional>

#include "xcgui/XCApp.hpp"

namespace xcgui {

	class XPyEvent {
		py::args args;
		py::kwargs kwargs;
	};

	class XEventManager {
	public:

	protected:
		std::map < HWINDOW, std::map<int, int>> a;
	};
}