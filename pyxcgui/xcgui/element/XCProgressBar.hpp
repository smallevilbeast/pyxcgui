#pragma once
#include "pch.h"
#include "xcgui/XCElement.hpp"

namespace xcgui {

	class XCProgressBar : public XCElement
	{
	public:
		XCProgressBar(HELE handle)
		{
			m_handle = handle;
		}

		XCProgressBar() = default;

		XCProgressBar(int x, int y, int width, int height, HXCGUI parent = NULL) {
			m_handle = XProgBar_Create(x, y, width, height, parent);
		}

		//@备注 显示进度值文本
		//@参数 bShow 是否启用
		//@别名  启用进度文本()
		void EnableShowText(bool bShow) {
			XProgBar_EnableShowText(getEleHandle(), bShow);
		}

		//@备注 缩放进度贴图为当前进度区域(当前进度所显示区域),否则为整体100%进度区域
		//@参数 bStretch 缩放
		//@返回 如果成功返回TRUE,否则返回FALSE
		//@别名  启用缩放()
		void EnableStretch(bool bStretch) {
			XProgBar_EnableStretch(getEleHandle(), bStretch);
		}

		//@备注 设置范围.  
		//@参数 range 范围.
		//@别名  置范围()
		void SetRange(int range) {
			XProgBar_SetRange(getEleHandle(), range);
		}

		//@备注 获取范围.  
		//@返回 返回范围.
		//@别名  取范围()
		int GetRange() {
			return XProgBar_GetRange(getEleHandle());
		}

		//@备注 设置进度贴图.  
		//@参数 hImage 图片句柄.
		//@别名  置进度图片()
		void SetImageLoad(HIMAGE hImage) {
			XProgBar_SetImageLoad(getEleHandle(), hImage);
		}

		//@备注 设置位置点.  
		//@参数 pos 位置点.
		//@别名  置进度()
		void SetPos(int pos) {
			XProgBar_SetPos(getEleHandle(), pos);
		}

		//@备注 获取当前位置点.  
		//@返回 返回当前位置点.
		//@别名  取进度()
		int GetPos() {
			return XProgBar_GetPos(getEleHandle());
		}

		//@备注 设置水平或垂直.  
		//@参数 bHorizon 水平或垂直.
		//@别名  启用水平()
		void EnableHorizon(bool bHorizon) {
			XProgBar_EnableHorizon(getEleHandle(), bHorizon);
		}


	};
}