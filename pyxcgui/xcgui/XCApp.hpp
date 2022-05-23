#pragma once
#include "pch.h"

namespace xcgui {
	class XCApp
	{
	public:
		XCApp(bool bD2D = false)
		{
			XInitXCGUI(bD2D);
		}

		void Run() 
		{
			XRunXCGUI();
		}

		void Exit() 
		{
			XExitXCGUI();
		}
	};
}
