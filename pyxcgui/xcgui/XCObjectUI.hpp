#pragma once
#include "pch.h"
#include "XCObject.hpp"

namespace xcgui {
	class XCObjectUI : public XCObject 
	{
	public:
		XCObjectUI() 
		: XCObject()
		{
		}
		XCObjectUI(HXCGUI handle)
		: XCObject(handle)
		{
		}
		
		// 设置UI对象样式
		void SetStyle(XC_OBJECT_STYLE nStyle)
		{
			XUI_SetStyle(m_handle, nStyle);
		}

		// 获取UI对象样式
		XC_OBJECT_STYLE GetStyle()
		{
			return XUI_GetStyle(m_handle);
		}

		//启用或禁用样式
		void EnableCSS(bool bEnable)
		{
			XUI_EnableCSS(m_handle, bEnable);
		}

		// 设置CSS[套用样式]名称
		void SetCssName(const std::wstring& name)
		{
			return XUI_SetCssName(m_handle, name.c_str());
		}

		// 获取CSS样式名称
		std::wstring GetCssName()
		{
			auto pName = XUI_GetCssName(m_handle);
			if (pName) {
				return std::wstring(pName);
			}
			return L"";
		}

	};
}