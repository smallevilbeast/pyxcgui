#pragma once
#include "pch.h"

class XCBase
{
public:
	XCBase();
	XCBase(HXCGUI handle);

	//  获取对象最终类型
	XC_OBJECT_TYPE GetType();

	// 获取对象的基础类型
	XC_OBJECT_TYPE GetTypeBase();

	// 获取对象扩展类型
	XC_OBJECT_TYPE_EX GetTypeEx();

	// 如果是按钮, 请使用按钮的增强接口 XBtn_SetTypeEx()
	void SetTypeEx(XC_OBJECT_TYPE_EX nType);

	HXCGUI GetHandle();
	void SetHandle(HXCGUI handle);

protected:
	HXCGUI m_handle;
};

