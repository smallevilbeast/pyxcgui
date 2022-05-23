#include "pch.h"
#include "XCWidgetLayout.h"

XCWidgetLayout::XCWidgetLayout(HXCGUI handle)
:m_handle(handle)
{

}

void XCWidgetLayout::EnableWrap(bool bWrap)
{
	XWidget_LayoutItem_EnableWrap(m_handle, bWrap);
}

void XCWidgetLayout::EnableSwap(bool bEnable)
{
	XWidget_LayoutItem_EnableSwap(m_handle, bEnable);
}

void XCWidgetLayout::EnableFloat(bool bFloat)
{
	XWidget_LayoutItem_EnableFloat(m_handle, bFloat);
}

void XCWidgetLayout::SetWidth(const XCLayoutSizeInfo & sizeInfo)
{
	XWidget_LayoutItem_SetWidth(m_handle, sizeInfo.sizeType, sizeInfo.size);
}

void XCWidgetLayout::SetHeight(const XCLayoutSizeInfo & sizeInfo)
{
	XWidget_LayoutItem_SetHeight(m_handle, sizeInfo.sizeType, sizeInfo.size);
}

XCLayoutSizeInfo * XCWidgetLayout::GetWidth()
{
	auto sizeInfo = new XCLayoutSizeInfo();
	XWidget_LayoutItem_GetWidth(m_handle, &sizeInfo->sizeType, &sizeInfo->size);
	return sizeInfo;
}

XCLayoutSizeInfo * XCWidgetLayout::GetHeight()
{
	auto sizeInfo = new XCLayoutSizeInfo();
	XWidget_LayoutItem_GetHeight(m_handle, &sizeInfo->sizeType, &sizeInfo->size);
	return sizeInfo;
}

void XCWidgetLayout::SetAlign(layout_align_axis_ nAlign)
{
	XWidget_LayoutItem_SetAlign(m_handle, nAlign);
}

void XCWidgetLayout::SetMargin(const marginSize_ & marginInfo)
{
	XWidget_LayoutItem_SetMargin(m_handle, marginInfo.leftSize, marginInfo.topSize, 
		marginInfo.rightSize, marginInfo.bottomSize);
}

marginSize_ * XCWidgetLayout::GetMargin()
{
	auto marginInfo = new marginSize_();
	XWidget_LayoutItem_GetMargin(m_handle, marginInfo);
	return marginInfo;
}

void XCWidgetLayout::SetMinSize(int width, int height)
{
	XWidget_LayoutItem_SetMinSize(m_handle, width, height);
}

void XCWidgetLayout::SetPosition(int left, int top, int right, int bottom)
{
	XWidget_LayoutItem_SetPosition(m_handle, left, top, right, bottom);
}


