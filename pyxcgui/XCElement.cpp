#include "pch.h"
#include "XCElement.h"

XCElement::XCElement(HXCGUI handle)
{
	m_handle = (HELE)handle;
}

XCElement::XCElement(HELE handle)
{
	m_handle = handle;
}
