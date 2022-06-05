#pragma once
#include "pch.h"
#include "xcgui/XCElement.hpp"

namespace xcgui {

	class XCScrollBar : public XCElement
	{
	public:
		XCScrollBar(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCScrollBar() = default;

		XCScrollBar(int x, int y, int width, int height, HXCGUI parent = NULL) {
			m_handle = XSBar_Create(x, y, width, height, parent);
		}

		//@备注 设置滚动范围.  
		//@参数 range 范围.
		//@别名  置范围()
		void SetRange(int range) {
			XSBar_SetRange(getEleHandle(), range);
		}

		//@备注 获取滚动范围.  
		//@返回 滚动范围.
		//@别名  取范围()
		int GetRange() {
			return XSBar_GetRange(getEleHandle());
		}

		//@备注 显示隐藏滚动条上下按钮.  
		//@参数 bShow 是否显示.
		//@别名  显示上下按钮()
		void ShowButton(bool bShow) {
			XSBar_ShowButton(getEleHandle(), bShow);
		}

		//@备注 设置滑块长度.  
		//@参数 length 长度.
		//@别名  置滑块长度()
		void SetSliderLength(int length) {
			XSBar_SetSliderLength(getEleHandle(), length);
		}

		//@备注 设置滑块最小长度.  
		//@参数 minLength 长度.
		//@别名  置滑块最小长度()
		void SetSliderMinLength(int minLength) {
			XSBar_SetSliderMinLength(getEleHandle(), minLength);
		}

		//@备注 设置滑块两边的间隔大小.  
		//@参数 nPadding 间隔大小.
		//@别名  置滑块两边间隔()
		void SetSliderPadding(int nPadding) {
			XSBar_SetSliderPadding(getEleHandle(), nPadding);
		}

		//@备注 设置水平或者垂直.  
		//@参数 bEnable 水平或垂直.
		//@返回 如果改变返回TRUE否则返回FALSE.
		//@别名  启用水平()
		bool EnableHorizon(bool bHorizon) {
			return XSBar_EnableHorizon(getEleHandle(), bHorizon);
		}

		//@备注 获取滑块最大长度.  
		//@返回 长度.
		//@别名  取滑块最大长度()
		int GetSliderMaxLength() {
			return XSBar_GetSliderMaxLength(getEleHandle());
		}

		//@备注 向上滚动.  
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  向上滚动()
		bool ScrollUp() {
			return XSBar_ScrollUp(getEleHandle());
		}

		//@备注 向下滚动.  
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  向下滚动()
		bool ScrollDown() {
			return XSBar_ScrollDown(getEleHandle());
		}

		//@备注 滚动到顶部.  
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  滚动到顶部()
		bool ScrollTop() {
			return XSBar_ScrollTop(getEleHandle());
		}

		//@备注 滚动到底部.  
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  滚动到底部()
		bool ScrollBottom() {
			return XSBar_ScrollBottom(getEleHandle());
		}

		//@备注 滚动到指定位置点 ,触发事件 
		//@参数 pos 位置点.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  滚动到指定位置()
		bool ScrollPos(int pos) {
			return XSBar_ScrollPos(getEleHandle(), pos);
		}

		//@备注 获取上按钮.  
		//@返回 返回按钮句柄.
		//@别名  取上按钮()
		HELE GetButtonUp() {
			return XSBar_GetButtonUp(getEleHandle());
		}

		//@备注 获取下按钮.  
		//@返回 返回按钮句柄.
		//@别名  取下按钮()
		HELE GetButtonDown() {
			return XSBar_GetButtonDown(getEleHandle());
		}

		//@备注 获取滑动按钮.  
		//@返回 返回按钮句柄.
		//@别名  取滑块()
		HELE GetButtonSlider() {
			return XSBar_GetButtonSlider(getEleHandle());
		}

	};
}