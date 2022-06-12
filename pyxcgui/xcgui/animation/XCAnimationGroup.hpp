#pragma once
#include "pch.h"
#include "XCAnimation.hpp"

namespace xcgui {


	class XCAnimationGroup : public XCAnimation
	{

	public:
		XCAnimationGroup(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCAnimationGroup() = default;

		XCAnimationGroup(int nLoopCount=0) {

			m_handle = XAnimaGroup_Create(nLoopCount);
		}

		void AddItem(HXCGUI hSequence) {
			XAnimaGroup_AddItem(m_handle, hSequence);
		}
	};
}