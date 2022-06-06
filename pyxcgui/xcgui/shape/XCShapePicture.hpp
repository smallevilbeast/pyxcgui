#pragma once
#include "pch.h"
#include "xcgui/shape/XCShape.hpp"

namespace xcgui {

	class XCShapePicture : public XCShape
	{
	public:
		XCShapePicture() = default;

		XCShapePicture(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCShapePicture(int x, int y, int cx, int cy, HXCGUI hParent = NULL) {
			this->Create(x, y, cx, cy, hParent);
		}

		HXCGUI Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL) {
			m_handle = XShapePic_Create(x, y, cx, cy, hParent);
			return m_handle;
		}
		
		//@备注 设置图片.  
		//@参数 hImage 图片句柄.
		//@别名  置图片()
		void SetImage(HIMAGE hImage) { 
			XShapePic_SetImage(m_handle, hImage); 
		}
		
		//@备注 获取图片句柄  
		//@返回 返回图片句柄.
		//@别名  取图片()
		HIMAGE GetImage() { 
			return XShapePic_GetImage(m_handle);
		}
	};
}