#pragma once
#include "pch.h"
#include "xcgui/XCObject.hpp"
#include "xcgui/XCFont.hpp"
#include "xcgui/XCImage.hpp"

namespace xcgui {

	class XCBkObject
	{
	public:
		XCBkObject()
			:m_handle(0) 
		{

		}
		XCBkObject(vint handle) {
			m_handle = handle;
		}

		XCBkObject(HXCGUI handle)
		{
			m_handle = (vint)handle;
		}
		
		virtual ~XCBkObject() = default;

		// 背景对象_置外间距
		void SetMargin(int left, int top, int right, int bottom) {
			XBkObj_SetMargin(m_handle, left, top, right, bottom);
		}

		// 背景对象_置对齐  对齐方式 @ref bkObject_align_flag_
		void SetAlign(int nFlags) {
			XBkObj_SetAlign(m_handle, nFlags);
		}

		// 背景对象_置图片
		void SetImage(const XCImage& image) {
			XBkObj_SetImage(m_handle, image.getImageHandle());
		}

		// 背景对象_置旋转
		void SetRotate(float angle) {
			XBkObj_SetRotate(m_handle, angle);
		}

		// 背景对象_置填充颜色
		void SetFillColor(COLORREF color)
		{
			XBkObj_SetFillColor(m_handle, color);
		}

		// 背景对象_置边框宽度
		void SetBorderWidth(int width) {
			XBkObj_SetBorderWidth(m_handle, width);
		}

		// 背景对象_置边框颜色
		void SetBorderColor(COLORREF color) {
			XBkObj_SetBorderColor(m_handle, color);
		}

		// 背景对象_置矩形圆角
		void SetRectRoundAngle(int leftTop, int leftBottom, int rightTop, int rightBottom) {
			XBkObj_SetRectRoundAngle(m_handle, leftTop, leftBottom, rightTop, rightBottom);
		}

		// 背景对象_启用填充
		void EnableFill(bool bEnable) {
			XBkObj_EnableFill(m_handle, bEnable);
		}

		// 背景对象_启用边框
		void EnableBorder(bool bEnable) {
			XBkObj_EnableBorder(m_handle, bEnable);
		}

		// 背景对象_置文本
		void SetText(const std::wstring& text) {
			XBkObj_SetText(m_handle, text.c_str());
		}

		// 背景对象_置字体
		void SetFont(HFONTX hFont) {
			XBkObj_SetFont(m_handle, hFont);
		}

		// 背景对象_置文本对齐
		void SetTextAlign(int align) {
			XBkObj_SetTextAlign(m_handle, align);
		}

		// 背景对象_取外间距
		void GetMargin(marginSize_* pMargin) {
			XBkObj_GetMargin(m_handle, pMargin);
		}

		// 背景对象_取对齐 返回对齐标识 @ref bkObject_align_flag_
		int GetAlign() {
			return XBkObj_GetAlign(m_handle);
		}

		// 背景对象_取图片
		HIMAGE GetImage() {
			return XBkObj_GetImage(m_handle);
		}

		// 背景对象_取旋转角度
		int GetRotate() {
			return XBkObj_GetRotate(m_handle);
		}

		// 背景对象_取填充色
		COLORREF GetFillColor() {
			return XBkObj_GetFillColor(m_handle);
		}

		// 背景对象_取边框色
		COLORREF GetBorderColor() {
			return XBkObj_GetBorderColor(m_handle);
		}

		// 背景对象_取边框宽度
		int GetBorderWidth() {
			return XBkObj_GetBorderWidth(m_handle);
		}

		//背景对象_取矩形圆角
		void GetRectRoundAngle(RECT* pRect) {
			XBkObj_GetRectRoundAngle(m_handle, pRect);
		}

		// 背景对象_是否填充
		bool IsFill() {
			return XBkObj_IsFill(m_handle);
		}

		// 背景对象_是否边框
		bool IsBorder() {
			return XBkObj_IsBorder(m_handle);
		}

		// 背景对象_取文本
		std::wstring GetText() {
			auto pText = XBkObj_GetText(m_handle);
			if (!pText) {
				return L"";
			}
			return pText;
		}

		// 背景对象_取字体
		HFONTX GetFont() {
			return XBkObj_GetFont(m_handle);
		}

		// 背景对象_取文本对齐, 返回文本对齐方式 @ref textFormatFlag_ 
		int GetTextAlign() {
			return XBkObj_GetTextAlign(m_handle);
		}

		vint GetId() {
			return m_handle;
		}

	protected:
		vint m_handle;
	};
}