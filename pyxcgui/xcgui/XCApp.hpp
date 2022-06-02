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

		// 添加文件搜索路径, 默认路为exe目录和程序当前运行目录
		void AddFileSearchPath(const std::wstring& path) {
			XC_AddFileSearchPath(path.c_str());
		}


	};
}
