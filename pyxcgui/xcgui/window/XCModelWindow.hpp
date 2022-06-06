#pragma once

#include "pch.h"
#include "xcgui/window/XCWindow.hpp"
#include "xcgui/XCElement.hpp"

namespace xcgui {

	class XCModelWindow : public XCWindow
	{
	public:
		XCModelWindow() = default;
		XCModelWindow(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCModelWindow(int width, int height, const std::wstring& title, uintptr_t hWndParent, int xcStyle= window_style_modal) {
			m_handle = XModalWnd_Create(width, height, title.c_str(), (HWND)hWndParent, xcStyle);
		}

		XCModelWindow(DWORD dwExStyle, DWORD dwStyle, const std::wstring& className,
			int x, int y, int cx, int cy, const std::wstring& title, uintptr_t hWndParent, int xcStyle = window_style_modal)
		{
			m_handle = XModalWnd_CreateEx(dwExStyle, dwStyle, (wchar_t*)className.c_str(),
				x, y, cx, cy, (wchar_t*)title.c_str(), (HWND)hWndParent, xcStyle);
		}

		virtual bool Attach(uintptr_t hwnd, int style) override {
			m_handle = XModalWnd_Attach((HWND)hwnd, style);
			return m_handle;
		}

		// 启动显示模态窗口,当窗口关闭时返回.
		int DoModal() {
			return XModalWnd_DoModal(GetWindowHandle());
		}

		//  是否自动关闭窗口,当窗口失去焦点时.
		void EnableAutoClose(bool bEnable) {
			XModalWnd_EnableAutoClose(GetWindowHandle(), bEnable);
		}

		// 当用户按ESC键时自动关闭模态窗口.
		void EnableEscClose(bool bEnable) {
			XModalWnd_EnableEscClose(GetWindowHandle(), bEnable);
		}

		// 结束模态窗口
		void EndModal(int result) {
			XModalWnd_EndModal(GetWindowHandle(), result);
		}



	};

}