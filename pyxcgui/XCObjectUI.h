#pragma once
#include "pch.h"
#include "XCBase.h"

class XCObjectUI : public XCBase {

public:
	XCObjectUI() = default;
	XCObjectUI(HXCGUI handle);
	// 设置UI对象样式
	void SetStyle(XC_OBJECT_STYLE nStyle);

	// 获取UI对象样式
	XC_OBJECT_STYLE GetStyle();
	
	//启用或禁用样式
	void EnableCSS(bool bEnable);
	
	// 设置CSS[套用样式]名称
	void SetCssName(const std::wstring& name);

	// 获取CSS样式名称
	std::wstring GetCssName();
};