#pragma once

#include "pch.h"
#include "XCWindow.h"


XCWindow::XCWindow(HWINDOW hWindow)
:XCObjectUI((HXCGUI)hWindow)
{
}

XCWindow::XCWindow(int x, int y, int cx, int cy, const std::wstring & title, uintptr_t hWndParent, int style)
{
	auto hWindow = XWnd_Create(x, y, cx, cy, title.c_str(), (HWND)hWndParent, style);
	this->SetWindowHandle(hWindow);
							   }



bool XCWindow::ShowWindow(int nCmdShow)
{
	return XWnd_ShowWindow(GetWindowHandle(), nCmdShow);
}

bool XCWindow::Attach(uintptr_t hWnd, int style)
{
	auto hWindow = XWnd_Attach((HWND)hWnd, style);
	this->SetWindowHandle(hWindow);
	return hWindow;
}

void XCWindow::SetWindowHandle(HWINDOW winHandle)
{
	this->SetHandle((HXCGUI)winHandle);
}

HWINDOW XCWindow::GetWindowHandle()
{
	return (HWINDOW)m_handle;
}

