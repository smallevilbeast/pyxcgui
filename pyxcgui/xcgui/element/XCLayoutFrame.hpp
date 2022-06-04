#pragma once
#include "pch.h"
#include "xcgui/element/XCScrollView.hpp"
#include "xcgui/XCLayoutBox.hpp"

namespace xcgui {


	class XCLayoutFrame : public XCScrollView, public XCLayoutBox
	{

	public:
		XCLayoutFrame(HELE handle)
		{

			m_handle = handle;
		}

		XCLayoutFrame() = default;

		XCLayoutFrame(int x, int y, int width, int height, HXCGUI parent = NULL) {

			m_handle = XLayoutFrame_Create(x, y, width, height, parent);
		}
		XCLayoutFrame(HXCGUI parent) {

			m_handle = XLayoutFrame_CreateEx(parent);
		}

		//@备注 启用布局功能
		//@参数 bEnable 是否启用
		//@别名  启用()
		void EnableLayout(bool bEnable) {
			XLayoutFrame_EnableLayout(getEleHandle(), bEnable);
		}

		//@备注 是否已经启用布局功能
		//@返回 如果启用布局返回TRUE,否则返回FALSE
		//@别名  是否启用()
		bool IsEnableLayout() {
			return XLayoutFrame_IsEnableLayout(getEleHandle());
		}

		//@参数 bEnable 是否显示
		//@别名  显示布局边界()
		void ShowLayoutFrame(bool bEnable) {
			XLayoutFrame_ShowLayoutFrame(getEleHandle(), bEnable);
		}

		//@备注 获取宽度,不包含内边距大小
		//@返回 返回宽度
		//@别名  取内宽度()
		int GetWidthIn() {
			return XLayoutFrame_GetWidthIn(getEleHandle());
		}

		//@备注 获取高度,不包含内边距大小
		//@返回 返回高度
		//@别名  取内高度()
		int GetHeightIn() {
			return XLayoutFrame_GetHeightIn(getEleHandle());
		}


	};
}