#pragma once

#include "pch.h"
#include "xcgui/window/XCModelWindow.hpp"

namespace xcgui {

	class XCMsgWindow : public XCModelWindow
	{
	public:
		XCMsgWindow() = default;
		XCMsgWindow(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCMsgWindow(const std::wstring& title, const std::wstring& text, int flags= messageBox_flag_ok | messageBox_flag_icon_info, uintptr_t hWndParent=0, int xcStyle = window_style_modal) {
			m_handle = XMsg_Create(title.c_str(), text.c_str(), flags, (HWND)hWndParent, xcStyle);
		}

		XCMsgWindow(DWORD dwExStyle, DWORD dwStyle, const std::wstring& className, 
			const std::wstring& title, const std::wstring& text, int flags, uintptr_t hWndParent, int xcStyle = window_style_modal)
		{
			m_handle = XMsg_CreateEx(dwExStyle, dwStyle, className.c_str(),
				title.c_str(), text.c_str(), flags,  (HWND)hWndParent, xcStyle);
		}
	};
}