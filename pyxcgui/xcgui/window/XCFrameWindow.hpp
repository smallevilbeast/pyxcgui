#pragma once

#include "pch.h"
#include "xcgui/window/XCWindow.hpp"
#include "xcgui/XCElement.hpp"

namespace xcgui {

	class XCFrameWindow : public XCWindow
	{
	public:
		XCFrameWindow() = default;
		XCFrameWindow(HXCGUI handle)
		{
			m_handle = handle;
		}
		XCFrameWindow(int x, int y, int cx, int cy, const std::wstring& title, uintptr_t hWndParent, int xcStyle= window_style_default) {
			m_handle = XFrameWnd_Create(x, y, cx, cy, title.c_str(), (HWND)hWndParent, xcStyle);
		}

		XCFrameWindow(DWORD dwExStyle, DWORD dwStyle, const std::wstring& className,
			int x, int y, int cx, int cy, const std::wstring& title, uintptr_t hWndParent, int xcStyle= window_style_default)
		{
			m_handle = XFrameWnd_CreateEx(dwExStyle, dwStyle, (wchar_t*)className.c_str(), 
				x, y, cx, cy, (wchar_t*)title.c_str(), (HWND)hWndParent, xcStyle);
		}

		virtual bool Attach(uintptr_t hwnd, int style) override {
			m_handle = XFrameWnd_Attach((HWND)hwnd, style);
			return m_handle;
		}

		// 设置主视图元素
		void SetView(HELE ele) {
			XFrameWnd_SetView(GetWindowHandle(), ele);
		}

		// 设置窗格组TabBar高度
		void SetTabBarHeight(int height) {
			XFrameWnd_SetTabBarHeight(GetWindowHandle(), height);
		}

		// 设置窗格分隔条颜色.
		void SetPaneSplitBarColor(COLORREF color) {
			XFrameWnd_SetPaneSplitBarColor(GetWindowHandle(), color);
		}

		// 保存布局信息到文件
		bool SaveLayoutToFile(const std::wstring& fileName) {
			return XFrameWnd_SaveLayoutToFile(GetWindowHandle(), fileName.c_str());
		}

		// 添加窗格到框架窗口
		bool AddPane(HELE paneDest, HELE paneNew, pane_align_ align) {
			return XFrameWnd_AddPane(GetWindowHandle(), paneDest, paneNew, align);
		}

		// 合并窗格
		bool MergePane(HELE paneDest, HELE paneNew) {
			return XFrameWnd_MergePane(GetWindowHandle(), paneDest, paneNew);
		}

		// 加载布局信息文件
		bool LoadLayoutFile(in_buffer_ HELE* aPaneList, int nPaneCount, const std::wstring& fileName) {
			return XFrameWnd_LoadLayoutFile(GetWindowHandle(), aPaneList, nPaneCount, fileName.c_str());
		}

		// 用来布局窗格的区域坐标,不包含码头
		void GetLayoutAreaRect(RECT* pRect) {
			XFrameWnd_GetLayoutAreaRect(GetWindowHandle(), pRect);
		}


		// 3.3.5 新增
		frameWnd_cell_type_  GetDragFloatWndTopFlag() {
			return XFrameWnd_GetDragFloatWndTopFlag(GetWindowHandle());
		}


	};

}