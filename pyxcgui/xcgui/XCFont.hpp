#pragma once
#include "pch.h"
#include "XCObject.hpp"
#include "xcgui/window/XCWindow.hpp"

namespace xcgui {

	class XCFont : public XCObject
	{
	public:
		XCFont()
			: XCObject()
		{
		}

		XCFont(HXCGUI handle)
		{
			m_handle = handle;
		}



		HFONTX getFontHandle() const
		{
			return (HFONTX)m_handle;
		}

		// 创建炫彩字体,当字体句柄与元素关联后,会自动释放. 
		XCFont(int size) { 
			m_handle = XFont_Create(size); 
		}

		// 创建炫彩字体,当字体句柄与元素关联后,会自动释放.  
		HFONTX Create(int size) { 
			m_handle = XFont_Create(size);
			return (HFONTX)m_handle;
		}

		// 创建炫彩字体
		HFONTX CreateEx(const std::wstring& name = L"宋体", int size = 12, int style = fontStyle_regular) {
			m_handle = XFont_CreateEx(name.c_str(), size, style);
			return (HFONTX)m_handle;
		}

		// 创建炫彩字体 D2D不支持此接口
		HFONTX CreateFromLOGFONTW(LOGFONTW* pFontInfo) { 
			m_handle = XFont_CreateFromLOGFONTW(pFontInfo);
			return (HFONTX)m_handle;
		}

		// 创建炫彩字体从现有HFONT字体,  D2D不支持此接口 
		HFONTX CreateFromHFONT(HFONT hFont) { 
			m_handle = XFont_CreateFromHFONT(hFont);
			return (HFONTX)m_handle;
		}
		
		// 创建炫彩字体从GDI+字体(Font), D2D不支持此接口
		HFONTX CreateFromFont(void* pFont) { 
			m_handle = XFont_CreateFromFont(pFont);
			return (HFONTX)m_handle;
		}

		//  创建字体从文件
		HFONTX CreateFromFile(const std::wstring& fontFile, int size = 12, int style = fontStyle_regular) { 
			m_handle = XFont_CreateFromFile(fontFile.c_str(), size, style);
			return (HFONTX)m_handle;
		}
		

		// 创建从内存
		HFONTX CreateFromMem(const std::string& data, int fontSize = 12, int style = fontStyle_regular) { 
			m_handle = XFont_CreateFromMem((void*)data.c_str(), data.size(), fontSize, style);
			return (HFONTX)m_handle;
		}

		// 创建从资源
		HFONTX CreateFromRes(int id, const std::wstring& typeName, int fontSize, int style, HMODULE hModule = NULL) { 
			m_handle = XFont_CreateFromRes(id, typeName.c_str(), fontSize, style, hModule);
			return (HFONTX)m_handle;
		}

		//字体_创建从ZIP
		HFONTX CreateFromZip(const std::wstring& zipFileName, const std::wstring& fileName, const std::wstring& password, int fontSize, int style = fontStyle_regular) {
			m_handle = XFont_CreateFromZip(zipFileName.c_str(), fileName.c_str(), password.c_str(), fontSize, style);
			return (HFONTX)m_handle;
		}

		// 加载从内存ZIP
		HFONTX  CreateFromZipMem(const std::string& data, const std::wstring& fileName, const std::wstring& password, int fontStyle, int style) {
			m_handle = XFont_CreateFromZipMem((void*)data.c_str(), data.size(), fileName.c_str(), password.c_str(), fontStyle, style);
			return (HFONTX)m_handle;
		}

		// 是否自动销毁
		void EnableAutoDestroy(bool bEnable) { 
			XFont_EnableAutoDestroy((HFONTX)m_handle, bEnable);
		}

		
		// 获取字体,返回GDI+ Font指针
		void* GetFont() { 
			return XFont_GetFont((HFONTX)m_handle); 
		}

		// 获取字体信息.  
		void GetFontInfo(font_info_* pInfo) { 
			XFont_GetFontInfo((HFONTX)m_handle, pInfo); 
		}

		// 获取字体LOGFONTW  
		bool GetLOGFONTW(HDC hdc, LOGFONTW* pOut) { 
			return XFont_GetLOGFONTW((HFONTX)m_handle, hdc, pOut);
		}

		// 强制销毁炫彩字体,谨慎使用, 建议使用 
		void Destroy() { 
			XFont_Destroy((HFONTX)m_handle);
		}

		// 增加引用计数.  
		void AddRef() { 
			XFont_AddRef((HFONTX)m_handle); 
		}

		// 获取引用计数.  
		int GetRefCount() { 
			return XFont_GetRefCount((HFONTX)m_handle);
		}

		// 释放引用计数,当引用计数为0时,自动销毁.  
		void Release() { 
			XFont_Release((HFONTX)m_handle); 
		}

	};

}
