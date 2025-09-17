#pragma once
#include "pch.h"
#include "xcgui/shape/XCShape.hpp"

namespace xcgui {

	class XCShapeRect : public XCShape
	{
	public:
		XCShapeRect() = default;

		XCShapeRect(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCShapeRect(int x, int y, int cx, int cy, HXCGUI hParent = NULL) {
			this->Create(x, y, cx, cy, hParent);
		}

		HXCGUI Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL) {
			m_handle = XShapeRect_Create(x, y, cx, cy, hParent);
			return m_handle;
		}

		//@备注 设置边框颜色.  
		//@参数 color 颜色值, 请使用宏: RGBA()
		//@别名  置边框色()
		void SetBorderColor(COLORREF color) {
			XShapeRect_SetBorderColor(m_handle, color);
		}

		//@备注 设置填充颜色.  
		//@参数 color 颜色值, 请使用宏: RGBA()
		//@别名  置填充色()
		void SetFillColor(COLORREF color) {
			XShapeRect_SetFillColor(m_handle, color);
		}

		//@备注 设置圆角大小.  
		//@参数 nWidth 圆角宽度.
		//@参数 nHeight 圆角高度.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置圆角大小()
		void SetRoundAngle(int nWidth, int nHeight) {
			XShapeRect_SetRoundAngle(m_handle, nWidth, nHeight);
		}

		//@备注 获取圆角大小.  
		//@参数 pWidth 圆角宽度.
		//@参数 pHeight 圆角高度.
		//@别名  取圆角大小()
		void GetRoundAngle(int* pWidth, int* pHeight) {
			XShapeRect_GetRoundAngle(m_handle, pWidth, pHeight);
		}

		//@备注 启用绘制矩形边框.  
		//@参数 bEnable 是否启用.
		//@别名  启用边框()
		void EnableBorder(bool bEnable) {
			XShapeRect_EnableBorder(m_handle, bEnable);
		}

		//@备注 启用填充矩形.  
		//@参数 bEnable 是否启用.
		//@别名  启用填充()
		void EnableFill(bool bEnable) {
			XShapeRect_EnableFill(m_handle, bEnable);
		}

		//@备注 启用圆角.  
		//@参数 bEnable 是否启用.
		//@别名  启用圆角()
		void EnableRoundAngle(bool bEnable) {
			XShapeRect_EnableRoundAngle(m_handle, bEnable);
		}

	};
}