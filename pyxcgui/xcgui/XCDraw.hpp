#pragma once
#include "pch.h"
#include "XCObject.hpp"
#include "XCWindow.hpp"

namespace xcgui {

	class XCDraw : public XCObject
	{
	public:
		XCDraw()
			: XCObject()
		{
		}	  

		XCDraw(HWINDOW hWin) 
		{
			auto drawHandle = XDraw_Create(hWin);
			this->setDrawHandle(drawHandle);
		}


		XCDraw(HDRAW drawHandle)
			:XCObject((HXCGUI)drawHandle)
		{
		}

		HDRAW getDrawHandle() const
		{
			return (HDRAW)m_handle;
		}

		void setDrawHandle(HDRAW drawHandle) {
			this->SetHandle((HXCGUI)drawHandle);
		}
	};

}
