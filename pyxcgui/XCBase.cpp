#pragma once

#include "pch.h"
#include "XCBase.h"


XCBase::XCBase()
: m_handle(nullptr)
{
}

XCBase::XCBase(HXCGUI handle)
:m_handle(handle)
{
}

XC_OBJECT_TYPE XCBase::GetType()
{
	return XObj_GetType(m_handle);
}

XC_OBJECT_TYPE XCBase::GetTypeBase()
{
	return XObj_GetTypeBase(m_handle);
}

XC_OBJECT_TYPE_EX XCBase::GetTypeEx()
{
	return XObj_GetTypeEx(m_handle);
}

void XCBase::SetTypeEx(XC_OBJECT_TYPE_EX nType)
{
	XObj_SetTypeEx(m_handle, nType);
}

HXCGUI XCBase::GetHandle()
{
	return m_handle;
}

void XCBase::SetHandle(HXCGUI handle)
{
	m_handle = handle;
}
