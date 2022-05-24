#pragma once
#include "pch.h"
#include "XCWidget.hpp"

namespace xcgui {

	class XCElement: public XCWidget
	{
	public:
		XCElement()
			: XCWidget()
		{
		}

		XCElement(HELE ele)
			:XCWidget((HXCGUI)ele)
		{
		}

		HELE getEleHandle() const
		{
			return (HELE)m_handle;
		}
	};

}
