#pragma once
#include "pch.h"
#include "xcgui/XCApp.hpp"
#include "XEventManager.hpp"

namespace xcgui {

	void declareApp(py::module& m) {
		py::class_<XCApp>(m, "XApp")
			.def(py::init<bool>(), py::arg("bD2D") = false)
			.def("run", &XCApp::Run)
			.def("exit", [](XCApp& self) {
				XEventManager::GetInstance()->Release();
				self.Exit();
			});
	}
}