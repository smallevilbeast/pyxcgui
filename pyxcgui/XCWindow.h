#pragma once

#include "pch.h"
#include "XCObjectUI.h"

class XCWindow : public XCObjectUI
{
public:

	XCWindow() = default;
	XCWindow(HWINDOW hWindow);
	XCWindow(int x, int y, int cx, int cy, const std::wstring& title, uintptr_t hWndParent = 0, int style = window_style_default);
	bool ShowWindow(int nCmdShow = SW_SHOW);
	bool Attach(uintptr_t hWnd, int style);

protected:
	void SetWindowHandle(HWINDOW winHandle);
	HWINDOW GetWindowHandle();
};
