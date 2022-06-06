#pragma once
#include "pch.h"
#include "xcgui/shape/XCShape.hpp"

namespace xcgui {

	class XCShapeText : public XCShape
	{
	public:
		XCShapeText() = default;

		XCShapeText(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCShapeText(int x, int y, int cx, int cy, const std::wstring& name, HXCGUI hParent = NULL) {
			this->Create(x, y, cx, cy, name, hParent);
		}

		HXCGUI Create(int x, int y, int cx, int cy, const std::wstring& name, HXCGUI hParent = NULL) {
			m_handle = XShapeText_Create(x, y, cx, cy, name.c_str(), hParent);
			return m_handle;
		}

		//@备注 设置文本内容.  
		//@参数 name.c_str() 文本内容.
		//@别名  置文本()
		void SetText(const std::wstring& name) {
			XShapeText_SetText(m_handle, name.c_str());
		}

		//@备注 获取文本内容.  
		//@别名  取文本()
		std::wstring GetText() {
			auto pText = XShapeText_GetText(m_handle);
			if (!pText) return L"";
			return pText;
		}

		//@备注 获取文本长度.  
		//@返回 文本长度.
		//@别名  取文本长度()
		int GetTextLength() {
			return XShapeText_GetTextLength(m_handle);
		}

		//@备注 设置字体.  
		//@参数 hFontx 字体句柄.
		//@别名  置字体()
		void SetFont(HFONTX hFontx) {
			XShapeText_SetFont(m_handle, hFontx);
		}

		//@备注 获取字体.  
		//@返回 返回字体句柄.
		//@别名  取字体()
		HFONTX GetFont() {
			return XShapeText_GetFont(m_handle);
		}

		//@备注 设置文本颜色.  
		//@参数 color 颜色值, 请使用宏: RGBA()
		//@别名  置文本颜色()
		void SetTextColor(COLORREF color) {
			XShapeText_SetTextColor(m_handle, color);
		}

		//@备注 获取文本颜色.  
		//@返回 颜色值.
		//@别名  取文本颜色()
		COLORREF GetTextColor() {
			return XShapeText_GetTextColor(m_handle);
		}

		//@备注 设置文本对齐方式.  
		//@参数 align 文本对齐方式; @ref textFormatFlag_ .
		//@别名  置文本对齐()
		void SetTextAlign(int align) {
			XShapeText_SetTextAlign(m_handle, align);
		}

		//@备注 设置内容偏移.  
		//@参数 x X坐标.
		//@参数 y Y坐标.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置偏移()
		void SetOffset(int x, int y) {
			XShapeText_SetOffset(m_handle, x, y);
		}
	};
}