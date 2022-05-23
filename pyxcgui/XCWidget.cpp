#include "pch.h"
#include "XCWidget.h"

XCWidget::XCWidget(HXCGUI handle)
:XCObjectUI(handle)
, m_layout(handle)
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

XCWindow* XCWidget::getWindow()
{
	auto winHandle = XWidget_GetHWINDOW(m_handle);
	if (!winHandle) {
		return nullptr;
	}

	return new XCWindow(winHandle);
}

void XCWidget::SetID(int nID)
{
	XWidget_SetID(m_handle, nID);
}

int XCWidget::GetID()
{
	return XWidget_GetID(m_handle);
}

void XCWidget::SetUID(int nUID)
{
	XWidget_SetUID(m_handle, nUID);
}

int XCWidget::GetUID()
{
	return XWidget_GetUID(m_handle);
}

void XCWidget::SetName(const std::wstring& name)
{
	XWidget_SetName(m_handle, name.c_str());
}

std::wstring XCWidget::GetName()
{
	auto pName = XWidget_GetName(m_handle);
	if (!pName) {
		return L"";
	}
	return pName;
}

