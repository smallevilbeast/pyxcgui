#pragma once
#include "pch.h"
#include "xcgui/element/XCButton.hpp"

namespace xcgui {

	class XCTextLink : public XCButton
	{
	public:
		XCTextLink(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCTextLink() = default;

		XCTextLink(int x, int y, int width, int height, const std::wstring& name, HXCGUI parent = NULL) {
			m_handle = XTextLink_Create(x, y, width, height, name.c_str(), parent);
		}

		// 启用下划线,鼠标离开状态
		void EnableUnderlineLeave(bool bEnable) {
			XTextLink_EnableUnderlineLeave(getEleHandle(), bEnable);
		}
		
		// 启用下划线,鼠标停留状态.
		void EnableUnderlineStay(bool bEnable) {
			XTextLink_EnableUnderlineStay(getEleHandle(), bEnable);
		}

		// 设置文本颜色,鼠标停留状态
		void SetTextColorStay(COLORREF color) {
			XTextLink_SetTextColorStay(getEleHandle(), color);
		}

		// 设置下划线颜色,鼠标离开状态
		void SetUnderlineColorLeave(COLORREF color) {
			XTextLink_SetUnderlineColorLeave(getEleHandle(), color);
		}

		// 设置下划线颜色,鼠标停留状态.
		void SetUnderlineColorStay(COLORREF color) {
			XTextLink_SetUnderlineColorStay(getEleHandle(), color);
		}
	};
}