#pragma once
#include "pch.h"
#include "XCObject.hpp"
#include "XCWindow.hpp"

namespace xcgui {

	class XCImageSrc : public XCObject
	{
	public:
		XCImageSrc()
			: XCObject()
		{
		}

		XCImageSrc(HIMAGE handle)
			:XCObject((HXCGUI)handle)
		{
		}

		HIMAGE getImageSrcHandle() const
		{
			return (HIMAGE)m_handle;
		}

		//  加载图片从文件
		HIMAGE LoadFile(const std::wstring& fileName) { 
			m_handle = XImgSrc_LoadFile(fileName.c_str());
			return (HIMAGE)m_handle;
		}

		// 加载图片,指定区位置及大小.  
		HIMAGE LoadFileRect(const std::wstring& fileName, int x, int y, int cx, int cy) { 
			m_handle = XImgSrc_LoadFileRect(fileName.c_str(), x, y, cx, cy);
			return (HIMAGE)m_handle;
		}

		// 加载图片从资源.  
		HIMAGE LoadRes(int id, const std::wstring& typeName, HMODULE hModule) { 
			//m_handle = XImgSrc_LoadRes(id, typeName.c_str(), hModule);
			return (HIMAGE)m_handle;
		}
		

		// 加载图片从ZIP压缩包. 
		HIMAGE LoadZip(const std::wstring& zipFileName, const std::wstring& fileName, const std::wstring& password) { 
			m_handle = XImgSrc_LoadZip(zipFileName.c_str(), fileName.c_str(), password.c_str());
			return (HIMAGE)m_handle;
		}
		
		// 加载ZIP图片,指定区位置及大小
		HIMAGE LoadZipRect(const std::wstring& zipFileName, const std::wstring& fileName, const std::wstring& password, int x, int y, int cx, int cy) {
			m_handle = XImgSrc_LoadZipRect(zipFileName.c_str(), fileName.c_str(), password.c_str(), x, y, cx, cy);
			return (HIMAGE)m_handle;
		}
		
		// 加载从内存ZIP
		HIMAGE LoadZipMem(const std::string& data, const std::wstring& fileName, const std::wstring& password) {
			m_handle = XImgSrc_LoadZipMem((void*)data.c_str(), data.size(), fileName.c_str(), password.c_str());
			return (HIMAGE)m_handle;
		}
		

		// 加载从内存
		HIMAGE LoadMemory(const std::string& data) { 
			m_handle = XImgSrc_LoadMemory((void*)data.c_str(), data.size());
			return (HIMAGE)m_handle;
		}
		
		// 加载从内存指定区域
		HIMAGE LoadMemoryRect(const std::string& data, int x, int y, int cx, int cy) { 
			m_handle = XImgSrc_LoadMemoryRect((void*)data.c_str(), data.size(), x, y, cx, cy);
			return (HIMAGE)m_handle;
		}
		
		// 加载图片从GDI+的Image对象
		HIMAGE LoadFromImage(void* pImage) { 
			m_handle = XImgSrc_LoadFromImage(pImage);
			return (HIMAGE)m_handle;;
		}

		// 加载文件图标,从一个EXE文件或DLL文件或图标文件;例如:*.exe文件的图标
		HIMAGE LoadFromExtractIcon(const std::wstring& fileName) {
			m_handle = XImgSrc_LoadFromExtractIcon(fileName.c_str());
			return (HIMAGE)m_handle;
		}


		// 创建一个炫彩图片句柄,从一个现有的图标句柄HICON.  
		HIMAGE LoadFromHICON(HICON hIcon) { 
			m_handle = XImgSrc_LoadFromHICON(hIcon);
			return (HIMAGE)m_handle;
		}

		// 创建一个炫彩图片句柄,从一个现有的位图句柄HBITMAP.  
		HIMAGE LoadFromHBITMAP(HBITMAP hBitmap) { 
			m_handle = XImgSrc_LoadFromHBITMAP(hBitmap);
			return (HIMAGE)m_handle;
		}

		// 启用或关闭自动销毁,当与UI元素关联时有效  
		void EnableAutoDestroy(bool bEnable) { 
			XImgSrc_EnableAutoDestroy((HIMAGE)m_handle, bEnable);
		}

		// 获取图片宽度
		int GetWidth() { 
			return XImgSrc_GetWidth((HIMAGE)m_handle);
		}

		// 获取图片高度.
		int GetHeight() { 
			return XImgSrc_GetHeight((HIMAGE)m_handle);
		}
		
		// 获取图片文件名 
		std::wstring GetFile() { 
			auto pFile = XImgSrc_GetFile((HIMAGE)m_handle);
			if (!pFile)
				return L"";
			return pFile;
		}

		// 增加引用计数.  
		void AddRef() { 
			XImgSrc_AddRef((HIMAGE)m_handle);
		}
		
		// 释放引用计数,当引用计数为0时,自动销毁
		void Release() { 
			XImgSrc_Release((HIMAGE)m_handle);
		}
		

		// 获取引用计数.
		int GetRefCount() { 
			return XImgSrc_GetRefCount((HIMAGE)m_handle);
		}
		
		// 强制销毁图片, 谨慎使用, 建议使用
		void Destroy() { 
			XImgSrc_Destroy((HIMAGE)m_handle);
		}
	};

}
