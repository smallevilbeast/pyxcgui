#pragma once
#include "pch.h"
#include "xcgui/shape/XCShape.hpp"

namespace xcgui {

	class XCShapeGroupBox : public XCShape
	{
	public:
		XCShapeGroupBox() = default;

		XCShapeGroupBox(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCShapeGroupBox(int x, int y, int cx, int cy, const std::wstring& name, HXCGUI hParent = NULL) {
			this->Create(x, y, cx, cy, name, hParent);
		}

		HXCGUI Create(int x, int y, int cx, int cy, const std::wstring& name, HXCGUI hParent = NULL) {
			m_handle = XShapeGroupBox_Create(x, y, cx, cy, name.c_str(), hParent);
			return m_handle;
		}

		//@备注 设置边框颜色.  
		//@参数 color 颜色值, 请使用宏: RGBA()
		//@别名  置边框颜色()
		void SetBorderColor(COLORREF color) {
			XShapeGroupBox_SetBorderColor(m_handle, color);
		}

		//@备注 设置文本颜色.  
		//@参数 color 颜色值, 请使用宏: RGBA()
		//@别名  置文本颜色()
		void SetTextColor(COLORREF color) {
			XShapeGroupBox_SetTextColor(m_handle, color);
		}

		//@备注 设置字体.  
		//@参数 hFontX 炫彩字体.
		//@别名  置字体()
		void SetFontX(HFONTX hFontX) {
			XShapeGroupBox_SetFontX(m_handle, hFontX);
		}

		//@备注 设置文本偏移量.  
		//@参数 offsetX 水平偏移.
		//@参数 offsetY 垂直偏移.
		//@别名  置文本偏移()
		void SetTextOffset(int offsetX, int offsetY) {
			XShapeGroupBox_SetTextOffset(m_handle, offsetX, offsetY);
		}

		//@备注 设置圆角大小.  
		//@参数 nWidth 圆角宽度.
		//@参数 nHeight 圆角高度.
		//@别名  置圆角大小()
		void SetRoundAngle(int nWidth, int nHeight) {
			XShapeGroupBox_SetRoundAngle(m_handle, nWidth, nHeight);
		}

		//@备注 设置文本内容.  
		//@参数 pText 文本内容.
		//@别名  置文本()
		void SetText(const std::wstring& text) {
			XShapeGroupBox_SetText(m_handle, text.c_str());
		}

		//@备注 获取文本偏移量.  
		//@参数 pOffsetX X坐标偏移量.
		//@参数 pOffsetY Y坐标偏移量.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  取文本偏移()
		void GetTextOffset(int* pOffsetX, int* pOffsetY) {
			XShapeGroupBox_GetTextOffset(m_handle, pOffsetX, pOffsetY);
		}

		//@备注 获取圆角大小.  
		//@参数 pWidth 返回圆角宽度.
		//@参数 pHeight 返回圆角高度.
		//@别名  取圆角大小()
		void GetRoundAngle(int* pWidth, int* pHeight) {
			XShapeGroupBox_GetRoundAngle(m_handle, pWidth, pHeight);
		}

		//@备注 启用圆角.  
		//@参数 bEnable 是否启用.
		//@别名  启用圆角()
		void EnableRoundAngle(bool bEnable) {
			XShapeGroupBox_EnableRoundAngle(m_handle, bEnable);
		}

	};
}