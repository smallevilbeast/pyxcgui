#include "pch.h"
#include "XCObjectUI.h"

XCObjectUI::XCObjectUI(HXCGUI handle)
: XCBase(handle)
{
}

void XCObjectUI::SetStyle(XC_OBJECT_STYLE nStyle)
{
	XUI_SetStyle(m_handle, nStyle);
}

XC_OBJECT_STYLE XCObjectUI::GetStyle()
{
	return XUI_GetStyle(m_handle);
}

void XCObjectUI::EnableCSS(bool bEnable)
{
	XUI_EnableCSS(m_handle, bEnable);
}

void XCObjectUI::SetCssName(const std::wstring & name)
{
	return XUI_SetCssName(m_handle, name.c_str());
}

std::wstring XCObjectUI::GetCssName()
{
	auto pName = XUI_GetCssName(m_handle);
	if (pName) {
		return std::wstring(pName);
	}
	return L"";
}
