#pragma once
#include "pch.h"
#include "XCWidget.h"

class XCElement: public XCWidget
{		  
public:
	XCElement() = default;
	XCElement(HXCGUI handle);
	XCElement(HELE handle);

protected:
	HELE m_handle;

};

