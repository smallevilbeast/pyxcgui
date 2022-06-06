#include "pch.h"
#include "xcgui/window/XCMsgWindow.hpp"

namespace xcgui {

	void declareMsgWindow(py::module& m) {

		py::class_<XCMsgWindow, XCModelWindow>(m, "XMsgWindow")
			PYCASTOBJECT(XCMsgWindow)
			.def(py::init<const std::wstring&, const std::wstring&, int, uintptr_t, int>()
				,"title"_a, "text"_a, "flags"_a= messageBox_flag_ok | messageBox_flag_icon_info, "hwndParent"_a=0, "xcStyle"_a= (int)window_style_modal)
			
			.def(py::init<DWORD, DWORD, const std::wstring&, const std::wstring&, const std::wstring&, int, uintptr_t, int>()
				, "exStyle"_a, "style"_a, "className"_a, "title"_a, "text"_a, "flags"_a, "hwndParent"_a, "xcStyle"_a = (int)window_style_modal)

			;
		}
}