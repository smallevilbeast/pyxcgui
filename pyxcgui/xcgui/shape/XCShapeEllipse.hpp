#pragma once
#include "pch.h"
#include "xcgui/shape/XCShape.hpp"

namespace xcgui {

	class XCShapeEllipse : public XCShape
	{
	public:
		XCShapeEllipse() = default;

		XCShapeEllipse(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCShapeEllipse(int x, int y, int cx, int cy, HXCGUI hParent = NULL) {
			this->Create(x, y, cx, cy, hParent);
		}

		HXCGUI Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL) {
			m_handle = XShapeEllipse_Create(x, y, cx, cy, hParent);
			return m_handle;
		}

		//@备注 设置边框颜色.  
		//@参数 color 颜色值, 请使用宏: RGBA()
		//@别名  置边框色()
		void SetBorderColor(COLORREF color) { 
			XShapeEllipse_SetBorderColor(m_handle, color); 
		}

		//@备注 设置填充颜色.  
		//@参数 color 颜色值, 请使用宏: RGBA()
		//@别名  置填充色()
		void SetFillColor(COLORREF color) { 
			XShapeEllipse_SetFillColor(m_handle, color); 
		}

		//@备注 启用绘制圆边框.  
		//@参数 bEnable 是否启用.
		//@别名  启用边框()
		void EnableBorder(bool bEnable) { 
			XShapeEllipse_EnableBorder(m_handle, bEnable); 
		}
		
		//@备注 启用填充圆.  
		//@参数 bEnable 是否启用.
		//@别名  启用填充()
		void EnableFill(bool bEnable) { 
			XShapeEllipse_EnableFill(m_handle, bEnable); 
		}
	};
}