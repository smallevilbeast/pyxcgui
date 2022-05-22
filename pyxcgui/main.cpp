#include "pch.h"
#include "main.h"
#include "XCApp.h"
#include "XCWindow.h"
#include "XCWidget.h"
#include "XCElement.h"

using namespace pybind11::literals;


PYBIND11_MODULE(xcgui, m) {
	m.doc() = "xcgui for python";


	py::enum_<window_style_>(m, "window_style_", py::arithmetic())
		.value("window_style_nothing", window_style_nothing)
		.value("window_style_caption", window_style_caption)
		.value("window_style_border", window_style_border)
		.value("window_style_center", window_style_center)
		.value("window_style_drag_border", window_style_drag_border)
		.value("window_style_drag_window", window_style_drag_window)
		.value("window_style_allow_maxWindow", window_style_allow_maxWindow)
		.value("window_style_icon", window_style_icon)
		.value("window_style_title", window_style_title)
		.value("window_style_btn_min", window_style_btn_min)
		.value("window_style_btn_max", window_style_btn_max)
		.value("window_style_btn_close", window_style_btn_close)
		.value("window_style_default", window_style_default)
		.value("window_style_simple", window_style_simple)
		.value("window_style_pop", window_style_pop)
		.value("window_style_modal", window_style_modal)
		.value("window_style_modal_simple", window_style_modal_simple)
		.export_values();




	py::class_<XCApp>(m, "XApp")
		.def(py::init<bool>(), py::arg("bD2D") = false)
		.def("run", &XCApp::Run)
		.def("exit", &XCApp::Exit);



	py::class_<XCElement>(m, "XElement")
		.def(py::init<>());

	py::class_<XCWidget>(m, "XWidget")
		.def(py::init<>())
		.def("show", &XCWidget::Show, py::arg("bShow"))
		.def("enableLayoutControl", &XCWidget::EnableLayoutControl, py::arg("bEnable"))
		.def("IsLayoutControl", &XCWidget::IsLayoutControl)
		.def("getParentEle", &XCWidget::GetParentEle, py::return_value_policy::take_ownership);


	py::class_<XCWindow>(m, "XWindow")
		.def(py::init<>())
		.def(py::init<int, int, int, int, const std::wstring&, uintptr_t, int>(),
			py::arg("x"), py::arg("y"), py::arg("cx"), py::arg("cy"),
			py::arg("title"), py::arg("hWndParent") = 0, py::arg("style") = (int)window_style_default)
		.def("showWindow", &XCWindow::ShowWindow, py::arg("nCmdShow") = SW_SHOW);


}