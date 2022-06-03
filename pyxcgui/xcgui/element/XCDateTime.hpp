#pragma once
#include "pch.h"
#include "xcgui/XCElement.hpp"

namespace xcgui {

	class XCDateTime : public XCElement
	{
	public:
		XCDateTime(HELE handle)
		{
			m_handle = handle;
		}

		XCDateTime() = default;

		XCDateTime(int x, int y, int width, int height, HXCGUI parent = NULL) {
			m_handle = XDateTime_Create(x, y, width, height, parent);
		}

		//@备注 设置样式.  
		//@参数 nStyle 样式, 0为日期元素,1为时间元素.
		//@别名  置样式()
		void SetStyle(int nStyle) {
			XDateTime_SetStyle(getEleHandle(), nStyle);
		}

		//@备注 获取样式.  
		//@返回 元素样式.
		//@别名  取样式()
		int GetStyle() {
			return XDateTime_GetStyle(getEleHandle());
		}

		//@备注 切换分割栏为:斜线或横线.  
		//@参数 bSlash TRUE:斜线, FALSE:横线.
		//@别名  启用分割栏为斜线()
		void EnableSplitSlash(bool bSlash) {
			XDateTime_EnableSplitSlash(getEleHandle(), bSlash);
		}

		//@备注 获取内部按钮元素.  
		//@参数 nType 按钮类型, 0:日历下拉按钮, 1:上箭头按钮, 2:下箭头按钮
		//@返回 元素样式.
		//@别名  取内部按钮()
		HELE GetButton(int nType) {
			return XDateTime_GetButton(getEleHandle(), nType);
		}

		//@备注 获取被选择文字的背景颜色.  
		//@返回 元素样式.
		//@别名  取选择日期背景颜色()
		COLORREF GetSelBkColor() {
			return XDateTime_GetSelBkColor(getEleHandle());
		}

		//@备注 设置被选择文字的背景颜色.  
		//@参数 crSelectBk 文字被选中背景色, 颜色值, 请使用宏: RGBA()
		//@别名  置选择日期背景颜色()
		void SetSelBkColor(COLORREF crSelectBk) {
			XDateTime_SetSelBkColor(getEleHandle(), crSelectBk);
		}

		//@备注 获取当前日期.  
		//@参数 pnYear 年.[OUT]
		//@参数 pnMonth 月.[OUT]
		//@参数 pnDay 日.[OUT]
		//@别名  取当前日期()
		void GetDate(int* pnYear, int* pnMonth, int* pnDay) {
			XDateTime_GetDate(getEleHandle(), pnYear, pnMonth, pnDay);
		}

		//@备注 设置当前日期.  
		//@参数 nYear 年.
		//@参数 nMonth 月.
		//@参数 nDay 日.
		//@别名  置当前日期()
		void SetDate(int nYear, int nMonth, int nDay) {
			XDateTime_SetDate(getEleHandle(), nYear, nMonth, nDay);
		}

		//@备注 获取当前时间.  
		//@参数 pnHour 时.[OUT]
		//@参数 pnMinute 分.[OUT]
		//@参数 pnSecond 秒.[OUT]
		//@别名  取当前时间()
		void GetTime(int* pnHour, int* pnMinute, int* pnSecond) {
			XDateTime_GetTime(getEleHandle(), pnHour, pnMinute, pnSecond);
		}

		//@备注 设置当前时分秒.  
		//@参数 nHour 时.
		//@参数 nMinute 分.
		//@参数 nSecond 秒.
		//@别名  置当前时间()
		void SetTime(int nHour, int nMinute, int nSecond) {
			XDateTime_SetTime(getEleHandle(), nHour, nMinute, nSecond);
		}

		//@备注 弹出月历卡片
		//@别名  弹出()
		void Popup() {
			XDateTime_Popup(getEleHandle());
		}

	};
}