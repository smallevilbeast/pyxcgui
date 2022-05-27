#pragma once
#include "pch.h"
#include "XCObject.hpp"


namespace xcgui {

	class XCSvg : public XCObject
	{
	public:
		XCSvg()
			: XCObject()
		{
		}

		XCSvg(HSVG svgHandle)
			:XCObject(svgHandle)
		{
		}

		HSVG getSvgHandle() const {
			return (HSVG)m_handle;
		}
	};
}