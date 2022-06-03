#pragma once
#include "pch.h"
#include "xcgui/XCElement.hpp"

namespace xcgui {

	class XCSliderBar : public XCElement
	{
	public:
		XCSliderBar(HELE handle)
		{
			m_handle = handle;
		}

		XCSliderBar() = default;

		XCSliderBar(int x, int y, int width, int height, HXCGUI parent = NULL) {
			m_handle = XSliderBar_Create(x, y, width, height, parent);
		}

		//@备注 设置滑动范围.  
		//@参数 range 范围.
		//@别名  置范围()
		void SetRange(int range) {
			XSliderBar_SetRange(getEleHandle(), range);
		}

		//@备注 获取滚动范围.  
		//@返回 返回滚动范围.
		//@别名  取范围()
		int GetRange() {
			return XSliderBar_GetRange(getEleHandle());
		}

		//@备注 设置进度贴图.  
		//@参数 hImage 图片句柄.
		//@别名  置进度图片()
		void SetImageLoad(HIMAGE hImage) {
			XSliderBar_SetImageLoad(getEleHandle(), hImage);
		}

		//@备注 设置滑块按钮宽度.  
		//@参数 width 宽度.
		//@别名  置滑块宽度()
		void SetButtonWidth(int width) {
			XSliderBar_SetButtonWidth(getEleHandle(), width);
		}

		//@备注 设置滑块按钮高度.  
		//@参数 height 高度.
		//@别名  置滑块高度()
		void SetButtonHeight(int height) {
			XSliderBar_SetButtonHeight(getEleHandle(), height);
		}

		//@备注 设置当前进度点.  
		//@参数 pos 进度点.
		//@别名  置当前位置()
		void SetPos(int pos) {
			XSliderBar_SetPos(getEleHandle(), pos);
		}

		//@备注 获取当前进度点.  
		//@返回 返回当前进度点.
		//@别名  取当前位置()
		int GetPos() {
			return XSliderBar_GetPos(getEleHandle());
		}

		//@备注 获取滑块按钮.  
		//@返回 按钮句柄.
		//@别名  取滑块()
		HELE GetButton() {
			return XSliderBar_GetButton(getEleHandle());
		}

		//@备注 设置水平或垂直.  
		//@参数 bHorizon 水平或垂直.
		//@别名  启用水平()
		void EnableHorizon(bool bHorizon) {
			XSliderBar_EnableHorizon(getEleHandle(), bHorizon);
		}

	};
}