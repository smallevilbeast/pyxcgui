#pragma once
#include "pch.h"

namespace xcgui {

	class XCResource
	{
	public:
		// 启用延迟加载;图片文件,列表项模板文件
		static void EnableDelayLoad(bool bEnable) {
			XRes_EnableDelayLoad(bEnable);
		}

		// 从资源中查找背景
		static HBKM GetBkM(const std::wstring& name) {
			return XRes_GetBkM(name.c_str());
		}

		// 从资源中查找颜色
		static COLORREF GetColor(const std::wstring& name) {
			return XRes_GetColor(name.c_str());
		}

		// 从资源中查找字体
		static HFONTX GetFont(const std::wstring& name) {
			return XRes_GetFont(name.c_str());
		}

		// 获取资源ID整型值
		static int GetIDValue(const std::wstring& name) {
			return XRes_GetIDValue(name.c_str());
		}

		// 查找资源图片
		static HIMAGE GetImage(const std::wstring& name) {
			return XRes_GetImage(name.c_str());
		}

		// 从指定的资源文件中查找图片
		static HIMAGE GetImageEx(const std::wstring& fileName, const std::wstring& name) {
			return XRes_GetImageEx(fileName.c_str(), name.c_str());
		}

		// 设置文件加载回调函数
		static void SetLoadFileCallback(funLoadFile pFun) {
			XRes_SetLoadFileCallback(pFun);
		}

	};
}