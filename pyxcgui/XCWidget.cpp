#include "pch.h"
#include "XCWidget.h"

XCWidget::XCWidget(HXCGUI handle)
:XCObjectUI(handle)
{
}

bool XCWidget::IsShow()
{
	return XWidget_IsShow(m_handle);
}

void XCWidget::Show(bool bShow)
{
	XWidget_Show(m_handle, bShow);
}

void XCWidget::EnableLayoutControl(bool bEnable)
{
	XWidget_EnableLayoutControl(m_handle, bEnable);
}

bool XCWidget::IsLayoutControl()
{
	return XWidget_IsLayoutControl(m_handle);
}

XCWidget* XCWidget::GetParentEle()
{
	if (!m_handle)
		return nullptr;

	auto eleHandle = XWidget_GetParentEle(m_handle);
	if (!eleHandle) {
		return nullptr;
	}
	return new XCWidget((HXCGUI)eleHandle);
}

XCObjectUI* XCWidget::getParent()
{
	if (!m_handle)
		return nullptr;

	auto handle = XWidget_GetParent(m_handle);
	if (!handle)
		return nullptr;

	return new XCObjectUI(handle);
}

uintptr_t XCWidget::GetHWND()
{
	return (uintptr_t)XWidget_GetHWND(m_handle);
}
