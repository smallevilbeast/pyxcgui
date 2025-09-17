#pragma once
#include "pch.h"
#include "xcgui/shape/XCShape.hpp"

namespace xcgui {

	class XCShapeGif : public XCShape
	{
	public:
		XCShapeGif() = default;

		XCShapeGif(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCShapeGif(int x, int y, int cx, int cy, HXCGUI hParent = NULL) {
			this->Create(x, y, cx, cy, hParent);
		}

		HXCGUI Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL) {
			m_handle = XShapeGif_Create(x, y, cx, cy, hParent);
			return m_handle;
		}

		//@备注 设置GIF图片.  
		//@参数 hImage 图片句柄.
		//@别名  置图片()
		void SetImage(HIMAGE hImage) { 
			XShapeGif_SetImage(m_handle, hImage);
		}

		//@备注 获取图片句柄.  
		//@返回 返回图片句柄.
		//@别名  取图片()
		HIMAGE GetImage() { 
			return XShapeGif_GetImage(m_handle);
		}
	};
}