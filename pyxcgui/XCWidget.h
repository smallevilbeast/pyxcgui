#pragma once
#include "pch.h"
#include "XCObjectUI.h"
#include "XCWindow.h"
#include "XCWidgetLayout.h"

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

	// 取窗口
	XCWindow* getWindow();

	// 设置元素ID
	void SetID(int nID);

	// 获取元素ID
	int GetID();

	// 设置元素UID, 全局唯一标识符
	void SetUID(int nUID);

	// 获取元素UID,全局唯一标识符
	int GetUID();

	// 设置元素name
	void SetName(const std::wstring& name);

	// 获取元素name
	std::wstring GetName();

public:
	XCWidgetLayout m_layout;
};

