#pragma once
#include "pch.h"
#include "xcgui/XCWidget.hpp"

namespace xcgui {

	class XCShape: public XCWidget
	{
	public:
		XCShape(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCShape() = default;

		//@备注 从父UI元素或窗口,和父布局对象中移除.  
		//@别名  移除()
		void RemoveShape() {
			XShape_RemoveShape(m_handle);
		}

		//@备注 获取形状对象Z序.  
		//@返回 成功返回索引值,否则返回 XC_ID_ERROR.
		//@别名  取Z序()
		int GetZOrder() {
			return XShape_GetZOrder(m_handle);
		}

		//@备注 重绘形状对象.  
		//@别名  重绘()
		void Redraw() {
			XShape_Redraw(m_handle);
		}

		//@备注 获取内容宽度.  
		//@返回 返回内容宽度.
		//@别名  取宽度()
		int GetWidth() {
			return XShape_GetWidth(m_handle);
		}

		//@备注 获取内容高度.  
		//@返回 返回内容高度.
		//@别名  取高度()
		int GetHeight() {
			return XShape_GetHeight(m_handle);
		}

		//@备注 移动位置
		//@参数 x x坐标
		//@参数 y y坐标
		//@别名  置位置()
		void SetPosition(int x, int y) {
			XShape_SetPosition(m_handle, x, y);
		}

		//@参数 pOutX 返回X坐标
		//@参数 pOutY 返回Y坐标
		//@别名  取位置()
		void GetPosition(int* pOutX, int* pOutY) {
			XShape_GetPosition(m_handle, pOutX, pOutY);
		}

		//@参数 nWidth 宽度
		//@参数 nHeight 高度
		//@别名  置大小()
		void SetSize(int nWidth, int nHeight) {
			XShape_SetSize(m_handle, nWidth, nHeight);
		}

		//@参数 pOutWidth 返回宽度
		//@参数 pOutHeight 返回高度
		//@别名  取大小()
		void GetSize(int* pOutWidth, int* pOutHeight) {
			XShape_GetSize(m_handle, pOutWidth, pOutHeight);
		}

		//@参数 alpha 透明度
		//@别名  置透明度()
		void SetAlpha(BYTE alpha) {
			XShape_SetAlpha(m_handle, alpha);
		}

		//@返回 返回透明度
		//@别名  取透明度()
		BYTE GetAlpha() {
			return XShape_GetAlpha(m_handle);
		}

		//@备注 获取坐标.  
		//@参数 pRect 接收返回坐标.
		//@别名  取坐标()
		void GetRect(RECT* pRect) {
			XShape_GetRect(m_handle, pRect);
		}

		//@备注 设置坐标.  
		//@参数 pRect 坐标.
		//@别名  置坐标()
		void SetRect(RECT* pRect) {
			XShape_SetRect(m_handle, pRect);
		}

		//@备注 设置元素坐标,逻辑坐标,包含滚动视图偏移.  
		//@参数 pRect 坐标.
		//@参数 bRedraw 是否重绘.
		//@返回 如果成功返回TRUE, 否则返回FALSE.
		//@别名  置逻辑坐标()
		bool SetRectLogic(RECT* pRect, bool bRedraw) {
			return XShape_SetRectLogic(m_handle, pRect, bRedraw);
		}

		//@备注 获取元素坐标,逻辑坐标,包含滚动视图偏移.  
		//@参数 pRect 坐标.
		//@别名  取逻辑坐标()
		void GetRectLogic(RECT* pRect) {
			XShape_GetRectLogic(m_handle, pRect);
		}

		//@备注 基于窗口客户区坐标.  
		//@参数 pRect 坐标.
		//@别名  取基于窗口客户区坐标()
		void GetWndClientRect(RECT* pRect) {
			XShape_GetWndClientRect(m_handle, pRect);
		}

		//@备注 仅计算有效内容, 填充父, 权重依赖父级所以无法计算.  
		//@参数 pSize 接收返回内容大小值.
		//@别名  取内容大小()
		void GetContentSize(SIZE* pSize) {
			XShape_GetContentSize(m_handle, pSize);
		}

		//@备注 是否显示布局边界.  
		//@参数 bShow 是否显示.
		//@别名  显示布局边界()
		void ShowLayout(bool bShow) {
			XShape_ShowLayout(m_handle, bShow);
		}

		//@备注 调整布局.  
		//@别名  调整布局()
		void AdjustLayout() {
			XShape_AdjustLayout(m_handle);
		}

		//@备注 销毁形状对象.  
		//@别名  销毁()
		void Destroy() {
			XShape_Destroy(m_handle);
		}

	};
}