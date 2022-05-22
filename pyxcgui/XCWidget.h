#pragma once
#include "pch.h"
#include "XCObjectUI.h"
#include "XCWindow.h"

class XCWidget: public XCObjectUI
{
public:
	XCWidget() = default;
	XCWidget(HXCGUI handle);
	// 是否显示
	bool IsShow();

	// 显示
	void Show(bool bShow);

	// 启用布局控制
	void EnableLayoutControl(bool bEnable);

	// 是否布局控制
	bool IsLayoutControl();

	// 取父元素
	XCWidget* GetParentEle();

	// 获取父对象,父可能是元素或窗口,通过此函数可以检查是否有父
	XCObjectUI* getParent();

	// 取窗口句柄系统
	uintptr_t GetHWND();
};

