#include "pch.h"
#include "main.h"


#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

namespace py = pybind11;

#include <xcgui.h>



PYBIND11_MODULE(xcgui, m) {
	m.doc() = "xcgui for python"; // optional module docstring

	m.def("XInitXCGUI", [](bool bD2D) {
			return XInitXCGUI(bD2D ? TRUE : FALSE);
	});

	m.def("XWnd_Create", [](int x, int y, int cx, int cy, const std::wstring& title, int hWndParent, int XCStyle) {
		return (int)XWnd_Create(x, y, cx, cy, title.c_str(), (HWND)hWndParent, XCStyle);
	});

	m.def("XWnd_ShowWindow", [](int hWindow, int nCmdShow) {
		return XWnd_ShowWindow((HWINDOW)hWindow, nCmdShow);
	});

	m.def("XRunXCGUI", []() {
		XRunXCGUI();
	});

	m.def("XExitXCGUI", []() {
		XExitXCGUI();
	});

}