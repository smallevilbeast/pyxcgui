#include "pch.h"
#include "xcgui/window/XCModelWindow.hpp"
#include "xcgui/XCElement.hpp"
#include "xcgui/XCStruct.hpp"

namespace xcgui {

	void declareModelWindow(py::module& m) {

		py::class_<XCModelWindow, XCWindow>(m, "XModelWindow")
			.def(py::init<>())
			.def(py::init([](int width, int height, const std::wstring& title) {
				XCModelWindow window(width, height, title, 0, window_style_default);
				return window;
				}), "width"_a, "height"_a, "title"_a)
			.def(py::init<int, int, const std::wstring&, uintptr_t, int>()
				,"width"_a, "height"_a, "title"_a, "hwndParent"_a, "xcStyle"_a)
			
			.def(py::init<DWORD, DWORD, const std::wstring&,
						int, int, int, int, const std::wstring&, uintptr_t, int>()
				, "exStyle"_a, "style"_a, "className"_a, "x"_a, "y"_a, "width"_a, "height"_a,
				"title"_a, "hwndParent"_a, "xcStyle"_a)

			.def("attach", &XCModelWindow::Attach, "hwnd"_a, "style"_a)
			.def("doModal", &XCModelWindow::DoModal)
			.def("enableAutoClose", &XCModelWindow::EnableAutoClose, "enable"_a)
			.def("enableEscClose", &XCModelWindow::EnableEscClose, "enable"_a)
			.def("endModal", &XCModelWindow::EndModal, "result"_a)
			;
	}
}

