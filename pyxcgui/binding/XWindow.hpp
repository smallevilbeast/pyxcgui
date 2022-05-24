#include "pch.h"
#include "xcgui/XCWindow.hpp"

namespace xcgui {

	void declareWindow(py::module& m) {

		py::class_<XCWindow>(m, "XWindow")
			.def(py::init<>())
			.def(py::init<int, int, int, int, const std::wstring&, uintptr_t, int>(),
				py::arg("x"), py::arg("y"), py::arg("cx"), py::arg("cy"),
				py::arg("title"), py::arg("hWndParent") = 0, py::arg("style") = (int)window_style_default)
			.def("showWindow", &XCWindow::ShowWindow, py::arg("nCmdShow") = SW_SHOW);

	}
}