#include "pch.h"
#include "xcgui/XCWindow.hpp"
#include "xcgui/XCCast.hpp"

namespace xcgui {

	void declareWindow(py::module& m) {

		py::class_<XCWindow, XCObjectUI>(m, "XWindow")
			.def(py::init<>())
			.def(py::init<int, int, const std::wstring&>(), "width"_a, "height"_a, "title"_a)
			.def(py::init<int, int, int, int, const std::wstring&, uintptr_t, int>(),
				"x"_a, "y"_a, "width"_a, "height"_a, "title"_a,
				"hWndParent"_a = 0, "style"_a = (int)window_style_default)
			.def("attach", &XCWindow::Attach, "hwnd"_a, "style"_a)
			.def("addChild", &XCWindow::AddChild, "child"_a)
			.def("insertChild", &XCWindow::InsertChild, "child"_a, "index"_a)
			.def("redraw", &XCWindow::Redraw, "immediate"_a)
			.def("redrawRect", &XCWindow::RedrawRect, "rect"_a, "immediate"_a)
			.def("setFoucsEle", &XCWindow::SetFoucsEle, "ele"_a)
			.def("getFoucsEle", [](const XCWindow& self) -> XCObject* {
				return CastObject((HXCGUI)self.GetFocusEle());
			}, py::return_value_policy::take_ownership)

			.def("getStayEle", [](const XCWindow& self) -> XCObject* {
				return CastObject((HXCGUI)self.GetStayEle());
			}, py::return_value_policy::take_ownership)

			.def("showWindow", &XCWindow::ShowWindow, "showType"_a = SW_SHOW);

	}
}