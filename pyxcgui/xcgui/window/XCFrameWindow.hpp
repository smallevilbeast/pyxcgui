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

		// ��������ͼԪ��
		void SetView(HELE ele) {
			XFrameWnd_SetView(GetWindowHandle(), ele);
		}

		// ���ô�����TabBar�߶�
		void SetTabBarHeight(int height) {
			XFrameWnd_SetTabBarHeight(GetWindowHandle(), height);
		}

		// ���ô���ָ�����ɫ.
		void SetPaneSplitBarColor(COLORREF color) {
			XFrameWnd_SetPaneSplitBarColor(GetWindowHandle(), color);
		}

		// ���沼����Ϣ���ļ�
		bool SaveLayoutToFile(const std::wstring& fileName) {
			return XFrameWnd_SaveLayoutToFile(GetWindowHandle(), fileName.c_str());
		}

		// ��Ӵ��񵽿�ܴ���
		bool AddPane(HELE paneDest, HELE paneNew, pane_align_ align) {
			return XFrameWnd_AddPane(GetWindowHandle(), paneDest, paneNew, align);
		}

		// �ϲ�����
		bool MergePane(HELE paneDest, HELE paneNew) {
			return XFrameWnd_MergePane(GetWindowHandle(), paneDest, paneNew);
		}

		// ���ز�����Ϣ�ļ�
		bool LoadLayoutFile(in_buffer_ HELE* aPaneList, int nPaneCount, const std::wstring& fileName) {
			return XFrameWnd_LoadLayoutFile(GetWindowHandle(), aPaneList, nPaneCount, fileName.c_str());
		}

		// �������ִ������������,��������ͷ
		void GetLayoutAreaRect(RECT* pRect) {
			XFrameWnd_GetLayoutAreaRect(GetWindowHandle(), pRect);
		}


		// 3.3.5 ����
		frameWnd_cell_type_  GetDragFloatWndTopFlag() {
			return XFrameWnd_GetDragFloatWndTopFlag(GetWindowHandle());
		}


	};

}