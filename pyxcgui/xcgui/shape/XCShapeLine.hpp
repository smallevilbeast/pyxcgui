#pragma once
#include "pch.h"
#include "xcgui/shape/XCShape.hpp"

namespace xcgui {

	class XCShapeLine : public XCShape
	{
	public:
		XCShapeLine() = default;

		XCShapeLine(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCShapeLine(int x, int y, int cx, int cy, HXCGUI hParent = NULL) {
			this->Create(x, y, cx, cy, hParent);
		}

		HXCGUI Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL) {
			m_handle = XShapeLine_Create(x, y, cx, cy, hParent);
			return m_handle;
		}

		void SetColor(COLORREF color) {
			XShapeLine_SetColor(m_handle, color);
		}

		void SetPosition(int x1, int y1, int x2, int y2) {
			XShapeLine_SetPosition(m_handle, x1, y1, x2, y2);
		}
	};
}