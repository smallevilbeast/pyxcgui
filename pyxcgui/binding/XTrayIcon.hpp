#pragma once
#include "pch.h"
#include "xcgui/XCTrayIcon.hpp"
#include "xcgui/window/XCWindow.hpp"

namespace xcgui {

	void declareTrayIcon(py::module& m) {
		py::class_<XCTrayIcon>(m, "XTrayIcon")
			.def(py::init<>())
			.def(py::init<const XCWindow&, unsigned int>(), "window"_a, "id"_a)

			// 静态方法
			.def_static("reset", &XCTrayIcon::Reset)
			.def_static("setCallbackMessage", &XCTrayIcon::SetCallbackMessage, "userMessage"_a)
			.def_static("setTips", &XCTrayIcon::SetTips, "tips"_a)
			.def_static("setPopupBalloon", [](const std::wstring& title, const std::wstring& text, const XCImage* balloonIcon = nullptr, int flags = 0) {
				XCTrayIcon::SetPopupBalloon(title, text, balloonIcon, flags);
			}, "title"_a, "text"_a, "balloonIcon"_a = nullptr, "flags"_a = 0)

			// 实例方法
			.def("add", &XCTrayIcon::Add)

			.def("remove", &XCTrayIcon::Remove)

			.def("modify", &XCTrayIcon::Modify)

			.def("setIcon", &XCTrayIcon::SetIcon, "hIcon"_a)

			.def("setFocus", &XCTrayIcon::SetFocus)
			;
	}
}