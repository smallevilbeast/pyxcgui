#pragma once
#include "pch.h"
#include "xcgui/XCElement.hpp"

namespace xcgui {

	class XCMonthCal : public XCElement
	{
	public:
		XCMonthCal(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCMonthCal() = default;

		XCMonthCal(int x, int y, int width, int height, HXCGUI parent = NULL) {
			m_handle = XMonthCal_Create(x, y, width, height, parent);
		}


		HELE GetButton(monthCal_button_type_ nType) {
			return XMonthCal_GetButton(getEleHandle(), nType);
		}

		//@备注 设置月历当前年月日.  
		//@参数 nYear 年.
		//@参数 nMonth 月.
		//@参数 nDay 日.
		//@别名  置当前日期()
		void SetToday(int nYear, int nMonth, int nDay) {
			XMonthCal_SetToday(getEleHandle(), nYear, nMonth, nDay);
		}

		//@备注 获取月历当前年月日.  
		//@参数 pnYear 年.[INT,OUT]
		//@参数 pnMonth 月.[INT,OUT]
		//@参数 pnDay 日.[INT,OUT]
		//@别名  取当前日期()
		void GetToday(int* pnYear, int* pnMonth, int* pnDay) {
			XMonthCal_GetToday(getEleHandle(), pnYear, pnMonth, pnDay);
		}

		//@备注 获取月历选中的年月日.  
		//@参数 pnYear 年.[INT,OUT]
		//@参数 pnMonth 月.[INT,OUT]
		//@参数 pnDay 日.[INT,OUT]
		//@别名  取选择日期()
		void GetSelDate(int* pnYear, int* pnMonth, int* pnDay) {
			XMonthCal_GetSelDate(getEleHandle(), pnYear, pnMonth, pnDay);
		}

		//@参数 nFlag 1:周六,周日文字颜色, 2:日期文字的颜色;  其它周文字颜色, 使用元素自身颜色
		//@参数 color 颜色值
		//@别名  置文本颜色()
		void SetTextColor(int nFlag, COLORREF color) {
			XMonthCal_SetTextColor(getEleHandle(), nFlag, color);
		}


	};
}