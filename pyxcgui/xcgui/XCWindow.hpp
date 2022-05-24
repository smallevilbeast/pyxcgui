#pragma once

#include "pch.h"
#include "XCObjectUI.hpp"

namespace xcgui {
	class XCWindow : public XCObjectUI
	{
	public:

		XCWindow(HWINDOW hWindow)
			:XCObjectUI((HXCGUI)hWindow)
		{
		}

		XCWindow()
		: XCObjectUI()
		{
			auto hWindow = XWnd_Create(0, 0, 0, 0, NULL, NULL, window_style_default);
			this->SetWindowHandle(hWindow);
		}

		XCWindow(int width, int height, const std::wstring& title) 
			: XCObjectUI() 
		{
			auto hWindow = XWnd_Create(0, 0, width, height, title.c_str(), NULL, window_style_default);
			this->SetWindowHandle(hWindow);
		}

		XCWindow(int x, int y, int width, int height, const std::wstring& title, uintptr_t hWndParent = 0, int style = window_style_default)
			: XCObjectUI()
		{
			auto hWindow = XWnd_Create(x, y, width, height, title.c_str(), (HWND)hWndParent, style);
			this->SetWindowHandle(hWindow);
		}


		// hWnd 要附加的外部窗口句柄
		bool Attach(uintptr_t hWnd, int style)
		{
			auto hWindow = XWnd_Attach((HWND)hWnd, style);
			this->SetWindowHandle(hWindow);
			return hWindow;
		}

		// 	添加子对象到窗口 
		bool AddChild(const XCObjectUI& child) 
		{
			return XWnd_AddChild(GetWindowHandle(), child.GetHandle());
		}

		// 	插入子对象到指定位置
		bool InsertChild(const XCObjectUI& child, int index)
		{
			return XWnd_InsertChild(GetWindowHandle(), child.GetHandle(), index);
		}

		// 重绘窗口
		void Redraw(bool bImmediate = false)
		{
			XWnd_Redraw(GetWindowHandle(), bImmediate);
		}

		// 重绘窗口指定区域
		void RedrawRect(const XCRect& rect, bool bImmediate = false)
		{
			return XWnd_RedrawRect(GetWindowHandle(), (RECT*)&rect, bImmediate);
		}

		// 设置焦点元素
		void SetFoucsEle(const XCObjectUI& ele) 
		{
			XWnd_SetFocusEle(GetWindowHandle(), (HELE)ele.GetHandle());
		}

		// 获得拥有输入焦点的元素
		HELE GetFocusEle() const
		{
			auto winHandle = GetWindowHandle();
			if (!winHandle)
				return nullptr;

			return XWnd_GetFocusEle(winHandle);
		}

		// 获取当前鼠标所停留元素
		HELE GetStayEle() const 
		{
			auto winHandle = GetWindowHandle();
			if (!winHandle)
				return nullptr;
			return XWnd_GetStayEle(GetWindowHandle());
		}

		//  在自绘事件函数中,用户手动调用绘制窗口,以便控制绘制顺序
		void DrawWindow() 
		{
				
		}

		
		bool ShowWindow(int showType = SW_SHOW)
		{
			return XWnd_ShowWindow(GetWindowHandle(), showType);
		}



	protected:
		void SetWindowHandle(HWINDOW winHandle)
		{
			this->SetHandle((HXCGUI)winHandle);
		}

		HWINDOW GetWindowHandle() const 
		{
			return (HWINDOW)m_handle;
		}

	};

}