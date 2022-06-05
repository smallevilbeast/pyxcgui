#pragma once
#include "pch.h"
#include "xcgui/XCElement.hpp"

namespace xcgui {

	class XCPane : public XCElement
	{
	public:
		XCPane(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCPane() = default;

		XCPane(const std::wstring& name, int width, int height, HWINDOW parent) {
			m_handle = XPane_Create(name.c_str(), width, height, parent);
		}

		//@备注 设置窗格视图元素.  
		//@参数 hView 绑定视图元素.
		//@别名  置视图()
		void SetView(HELE hView) {
			XPane_SetView(getEleHandle(), hView);
		}

		//@备注 设置标题文本.  
		//@参数 pTitle 文本内容.
		//@别名  置标题()
		void SetTitle(const std::wstring& title) {
			XPane_SetTitle(getEleHandle(), (wchar_t*)title.c_str());
		}

		//@备注 获取标题文本.  
		//@返回 返回文本内容
		//@别名  取标题()
		std::wstring GetTitle() {
			auto pTitle = XPane_GetTitle(getEleHandle());
			if (!pTitle) return L"";
			return pTitle;
		}

		//@备注 设置标题栏高度.  
		//@参数 nHeight 高度.
		//@别名  置标题栏高度()
		void SetCaptionHeight(int nHeight) {
			XPane_SetCaptionHeight(getEleHandle(), nHeight);
		}

		//@备注 获取标题栏高度.  
		//@返回 返回标题栏高度.
		//@别名  取标题栏高度()
		int GetCaptionHeight() {
			return XPane_GetCaptionHeight(getEleHandle());
		}

		//@备注 判断窗格是否显示.  
		//@返回 如果显示返回TRUE否则返回FALSE.
		//@别名  是否显示()
		bool IsShowPane() {
			return XPane_IsShowPane(getEleHandle());
		}

		//@备注 判断窗格是否激活, 当为组成员时有效
		//@返回 如果为窗格组显示项返回TRUE,否则返回FALSE
		//@别名  是否激活()
		bool IsGroupActivate() {
			return XPane_IsGroupActivate(getEleHandle());
		}

		//@备注 设置窗格大小.  
		//@参数 nWidth 宽度.
		//@参数 nHeight 高度.
		//@别名  置大小()
		void SetSize(int nWidth, int nHeight) {
			XPane_SetSize(getEleHandle(), nWidth, nHeight);
		}

		//@备注 获取窗格停靠状态.  
		//@返回 返回状态标识 @ref pane_state_.
		//@别名  取状态()
		pane_state_ GetState() {
			return XPane_GetState(getEleHandle());
		}

		//@备注 获取窗格视图坐标.  
		//@参数 pRect 接收返回的坐标值.
		//@别名  取视图坐标()
		void GetViewRect(RECT* pRect) {
			XPane_GetViewRect(getEleHandle(), pRect);
		}

		//@备注 隐藏窗格.  
		//@参数 bGroupDelay 当为窗格组成员时, 延迟处理窗格组成员激活的切换
		//@别名  隐藏()
		void HidePane(bool bGroupDelay = false) {
			XPane_HidePane(getEleHandle(), bGroupDelay);
		}

		//@备注 显示窗格.  
		//@参数 bGroupActivate 如果是窗格组成员,那么窗格组切换当前窗格为显示状态
		//@别名  显示()
		void ShowPane(bool bGroupActivate) {
			XPane_ShowPane(getEleHandle(), bGroupActivate);
		}

		//@备注 窗格停靠到码头.  
		//@别名  停靠()
		void DockPane() {
			XPane_DockPane(getEleHandle());
		}

		//@备注 锁定窗格.  
		//@别名  锁定()
		void LockPane() {
			XPane_LockPane(getEleHandle());
		}

		//@备注 浮动窗格.  
		//@别名  浮动()
		void FloatPane() {
			XPane_FloatPane(getEleHandle());
		}

		//@备注 手动调用该函数绘制窗格, 以便控制绘制顺序.  
		//@参数 hDraw 图形绘制句柄.
		//@别名  绘制()
		void DrawPane(HDRAW hDraw) {
			XPane_DrawPane(getEleHandle(), hDraw);
		}

		//@备注 如果窗格是组成员,设置选中当前窗格可见
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置选中()
		bool SetSelect() {
			return XPane_SetSelect(getEleHandle());
		}

	};
}