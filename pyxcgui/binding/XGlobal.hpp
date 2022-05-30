#pragma once
#include "pch.h"
#include "XCastManager.hpp"

namespace xcgui {

	void declareGlobal(py::module& m) {

		m.def("cast", [](uintptr_t handle) -> XCObject* {
			return XCastManager::GetInstance()->CastObject((HXCGUI)handle);
		}, py::return_value_policy::reference);
	}

}