#pragma once
#include "pch.h"

struct XCLayoutSizeInfo
{
	layout_size_ sizeType;
	int size;
};

class XCWidgetLayout
{
public:
	XCWidgetLayout(HXCGUI handle);

	// 强制换行
	void EnableWrap(bool bWrap);

	// 根据水平垂直布局变换, 交换属性(宽度,高度,最小宽度,最小高度)
	void EnableSwap(bool bEnable);

	// 向反方向对齐
	void EnableFloat(bool bFloat);

	// 设置宽度
	void SetWidth(const XCLayoutSizeInfo& sizeInfo);

	// 设置高度
	void SetHeight(const XCLayoutSizeInfo& sizeInfo);

	// 取宽度
	XCLayoutSizeInfo* GetWidth();

	// 取高度信息
	XCLayoutSizeInfo* GetHeight();

	// 根据水平垂直轴变化对齐
	void SetAlign(layout_align_axis_ nAlign);

	// 布局项_置外间距
	void SetMargin(const marginSize_& marginInfo);

	// 布局项_取外间距
	marginSize_* GetMargin();

	// 限制大小仅针对缩放有效(自动, 填充父, 比例, 百分比)
	void SetMinSize(int width, int height);

	// 相对位置, 值大于等于0有效
	void SetPosition(int left, int top, int right, int bottom);

protected:
	HXCGUI m_handle;
	
};

