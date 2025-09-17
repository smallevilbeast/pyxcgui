#pragma once
#include "pch.h"
#include "xcgui/XCElement.hpp"
#include "xcgui/XCLayoutBox.hpp"

namespace xcgui {

	class XCLayoutEle : public XCElement, public XCLayoutBox
	{
	public:
		XCLayoutEle(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCLayoutEle() = default;

		XCLayoutEle(int x, int y, int width, int height, HXCGUI parent = NULL) {
			m_handle = XLayout_Create(x, y, width, height, parent);
		}

		HXCGUI CreateEx(HXCGUI parent) {
			m_handle = XLayout_CreateEx(parent);
			return m_handle;
		}

		//@备注 启用布局功能.  
		//@参数 bEnable 是否启用.
		//@别名  启用()
		void EnableLayout(bool bEnable) {
			XLayout_EnableLayout(getEleHandle(), bEnable);
		}

		//@备注 是否已经启用布局功能  
		//@返回 如果启用布局返回TRUE,否则返回FALSE
		//@别名  是否启用()
		bool IsEnableLayout() {
			return XLayout_IsEnableLayout(getEleHandle());
		}

		//@备注 显示布局边界.  
		//@参数 bEnable 是否显示
		//@别名  显示布局边界()
		void ShowLayoutFrame(bool bEnable) {
			XLayout_ShowLayoutFrame(getEleHandle(), bEnable);
		}

		//@备注 获取宽度,不包含内边距大小  
		//@返回 返回宽度
		//@别名  取内宽度()
		int GetWidthIn() {
			return XLayout_GetWidthIn(getEleHandle());
		}

		//@备注 获取高度,不包含内边距大小  
		//@返回 返回高度
		//@别名  取内高度()
		int GetHeightIn() {
			return XLayout_GetHeightIn(getEleHandle());
		}



	};
}