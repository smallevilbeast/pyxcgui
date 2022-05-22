#pragma once

#include "pch.h"
#include "XCWindow.h"


XCWindow::XCWindow(int x, int y, int cx, int cy, const std::wstring & title, uintptr_t hWndParent, int style)
{
	m_hWindow = XWnd_Create(x, y, cx, cy, title.c_str(), (HWND)hWndParent, style);
}

bool XCWindow::ShowWindow(int nCmdShow)
{
	return XWnd_ShowWindow(m_hWindow, nCmdShow);
}

bool XCWindow::Attach(uintptr_t hWnd, int style)
{
	return XWnd_Attach((HWND)hWnd, style);
}


