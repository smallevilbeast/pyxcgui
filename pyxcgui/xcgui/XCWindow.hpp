#pragma once

#include "pch.h"
#include "XCObjectUI.hpp"

namespace xcgui {
	class XCWindow : public XCObjectUI
	{
	public:

		XCWindow() = default;
		XCWindow(HWINDOW hWindow)
			:XCObjectUI((HXCGUI)hWindow)
		{
		}

		XCWindow(int x, int y, int cx, int cy, const std::wstring& title, uintptr_t hWndParent = 0, int style = window_style_default)
		{
			auto hWindow = XWnd_Create(x, y, cx, cy, title.c_str(), (HWND)hWndParent, style);
			this->SetWindowHandle(hWindow);
		}

		bool ShowWindow(int nCmdShow = SW_SHOW)
		{
			return XWnd_ShowWindow(GetWindowHandle(), nCmdShow);
		}


		bool Attach(uintptr_t hWnd, int style)
		{
			auto hWindow = XWnd_Attach((HWND)hWnd, style);
			this->SetWindowHandle(hWindow);
			return hWindow;
		}

	protected:
		void SetWindowHandle(HWINDOW winHandle)
		{
			this->SetHandle((HXCGUI)winHandle);
		}

		HWINDOW GetWindowHandle()
		{
			return (HWINDOW)m_handle;
		}

	};

}