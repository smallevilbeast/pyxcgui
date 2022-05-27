#pragma once
#include "pch.h"
#include "XCObject.hpp"

namespace xcgui {

	class XCImage : public XCObject
	{
	public:
		XCImage()
			: XCObject()
		{
		}

		XCImage(HIMAGE ele)
			:XCObject((HXCGUI)ele)
		{
		}


		HIMAGE getImageHandle() const
		{
			return (HIMAGE)m_handle;
		}

		// 加载从图片源
		HIMAGE loadSrc(HIMAGE hImageSrc) {
			m_handle = XImage_LoadSrc(hImageSrc);
			return (HIMAGE)m_handle;
		}

		// 加载从文件
		HIMAGE LoadFile(const std::wstring& fileName) { 
			m_handle = XImage_LoadFile(fileName.c_str()); 
			return (HIMAGE)m_handle;
		}

		// 加载图片从文件,自适应图片
		HIMAGE LoadFileAdaptive(const std::wstring& fileName, int leftSize, int topSize, int rightSize, int bottomSize) {
			m_handle = XImage_LoadFileAdaptive(fileName.c_str(), leftSize, topSize, rightSize, bottomSize);
			return (HIMAGE)m_handle;
		}

		// 加载图片,指定区位置及大小
		HIMAGE LoadFileRect(const std::wstring& fileName, int x, int y, int cx, int cy) {
			m_handle = XImage_LoadFileRect(fileName.c_str(), x, y, cx, cy);
			return (HIMAGE)m_handle;
		}

		// 加载图片从资源,自适应图片
		HIMAGE LoadResAdaptive(int id, const std::wstring& typeName, int leftSize, int topSize, int rightSize, int bottomSize, HMODULE hModule = NULL) { 
			m_handle = XImage_LoadResAdaptive(id, typeName.c_str(), leftSize, topSize, rightSize, bottomSize, hModule);
			return (HIMAGE)m_handle;
		}

		// 加载图片从资源
		HIMAGE LoadRes(int id, const std::wstring& typeName, HMODULE hModule = NULL) { 
			m_handle = XImage_LoadRes(id, typeName.c_str(), hModule);
			return (HIMAGE)m_handle;
		}


		// 加载图片从ZIP压缩包
		HIMAGE LoadZip(const std::wstring& zipFileName, const std::wstring& fileName, const std::wstring& password) {
			m_handle = XImage_LoadZip(zipFileName.c_str(), fileName.c_str(), password.c_str());
			return (HIMAGE)m_handle;
		}

		//	加载图片从ZIP压缩包,自适应图片
		HIMAGE LoadZipAdaptive(const std::wstring& zipFileName, const std::wstring& fileName, const std::wstring& password, int x1, int x2, int y1, int y2) {
			m_handle = XImage_LoadZipAdaptive(zipFileName.c_str(), fileName.c_str(), password.c_str(), x1, x2, y1, y2);
			return (HIMAGE)m_handle;
		}

		// 加载ZIP图片,指定区位置及大小
		HIMAGE LoadZipRect(const std::wstring& zipFileName, const std::wstring& fileName, const std::wstring& password, int x, int y, int cx, int cy) {
			m_handle = XImage_LoadZipRect(zipFileName.c_str(), fileName.c_str(), password.c_str(), x, y, cx, cy);
			return (HIMAGE)m_handle;
		}

		// 加载从内存ZIP
		HIMAGE LoadZipMem(const std::string& data, const std::wstring& fileName, const std::wstring& password) {
			m_handle = XImage_LoadZipMem((void*)data.c_str(), data.size(), fileName.c_str(), password.c_str());
			return (HIMAGE)m_handle;
		}

		// 加载流图片,指定区位置及大小
		HIMAGE LoadMemory(const std::string& data) {
			m_handle = XImage_LoadMemory((void*)data.c_str(), data.size());
			return (HIMAGE)m_handle;
		}

		// 加载流图片,指定区位置及大小
		HIMAGE LoadMemoryRect(const std::string& data, int x, int y, int cx, int cy) {
			m_handle = XImage_LoadMemoryRect((void*)data.c_str(), data.size(), x, y, cx, cy);
			return (HIMAGE)m_handle;
		}

		// 加载流图片压缩包,自适应图片(九宫格)
		HIMAGE LoadMemoryAdaptive(const std::string& data, int leftSize, int topSize, int rightSize, int bottomSize) { 
			m_handle = XImage_LoadMemoryAdaptive((void*)data.c_str(), data.size(), leftSize, topSize, rightSize, bottomSize);
			return (HIMAGE)m_handle;
		}

		// 加载图片从GDI+的Image对象
		HIMAGE LoadFromImage(void* pImage) { 
			m_handle = XImage_LoadFromImage(pImage);
			return (HIMAGE)m_handle;
		}

		// 加载文件图标,从一个EXE文件或DLL文件或图标文件;例如:*.exe文件的图标
		HIMAGE LoadFromExtractIcon(const std::wstring& fileName) { 
			m_handle = XImage_LoadFromExtractIcon(fileName.c_str());
			return (HIMAGE)m_handle;
		}

		// 创建一个炫彩图片句柄,从一个现有的图标句柄HICON.
		HIMAGE LoadFromHICON(HICON hIcon) { 
			m_handle = XImage_LoadFromHICON(hIcon);
			return (HIMAGE)m_handle;
		}

		//  创建一个炫彩图片句柄,从一个现有的位图句柄HBITMAP
		HIMAGE LoadFromHBITMAP(HBITMAP hBitmap) { 
			m_handle = XImage_LoadFromHBITMAP(hBitmap);
			return (HIMAGE)m_handle;
		}

		// 	hSvg SVG句柄
		HIMAGE LoadSvg(HSVG hSvg) {
			m_handle = XImage_LoadSvg(hSvg);
			return (HIMAGE)m_handle;
		}

		// 加载从SVG文件
		HIMAGE LoadSvgFile(const std::wstring& fileName) {
			m_handle = XImage_LoadSvgFile(fileName.c_str());
			return (HIMAGE)m_handle;
		}

		//  多字节字符串ANSI
		HIMAGE LoadSvgString(const std::string& data) {
			m_handle = XImage_LoadSvgString(data.c_str());
			return (HIMAGE)m_handle;
		}

		// UNICODE字符串
		HIMAGE LoadSvgStringW(const std::wstring& data) {
			m_handle = XImage_LoadSvgStringW(data.c_str());
			return (HIMAGE)m_handle;
		}

		//  加载从SVG字符串UTF8
		HIMAGE LoadSvgStringUtf8(const std::string& data) {
			m_handle = XImage_LoadSvgStringUtf8(data.c_str());
			return (HIMAGE)m_handle;
		}

		// 是否为拉伸图片句柄
		bool IsStretch() { 
			return XImage_IsStretch((HIMAGE)m_handle);
		}

		//	是否为平铺图片
		bool IsTile() { 
			return XImage_IsTile((HIMAGE)m_handle);
		}


		// SVG句柄
		HSVG GetSvg() { 
			return XImage_GetSvg((HIMAGE)m_handle);
		}

		// 设置图片绘制类型
		bool SetDrawType(image_draw_type_ nType) { 
			return XImage_SetDrawType((HIMAGE)m_handle, nType);
		}

		// 设置图片自适应(九宫格)
		bool SetDrawTypeAdaptive(int leftSize, int topSize, int rightSize, int bottomSize) { 
			return XImage_SetDrawTypeAdaptive((HIMAGE)m_handle, leftSize, topSize, rightSize, bottomSize);
		}

		// 指定图片透明颜色
		void SetTranColor(COLORREF color) { 
			XImage_SetTranColor((HIMAGE)m_handle, color);
		}

		// 指定图片透明颜色及透明度
		void SetTranColorEx(COLORREF color, BYTE tranColor) { 
			XImage_SetTranColorEx((HIMAGE)m_handle, color, tranColor);
		}

		// 设置旋转角度
		float SetRotateAngle(float fAngle) { 
			return XImage_SetRotateAngle((HIMAGE)m_handle, fAngle);
		}

		// 置等分()
		void SetSplitEqual(int nCount, int iIndex) { 
			XImage_SetSplitEqual((HIMAGE)m_handle, nCount, iIndex);
		}
		

		// 启用或关闭图片透明色
		void EnableTranColor(bool bEnable) {
			XImage_EnableTranColor((HIMAGE)m_handle, bEnable);
		}

		// 启用或关闭自动销毁,当与UI元素关联时有效
		void EnableAutoDestroy(bool bEnable) {
			XImage_EnableAutoDestroy((HIMAGE)m_handle, bEnable);
		}


		// 启用或关闭图片居中显示，默认属性图片有效
		void EnableCenter(bool bCenter) { 
			XImage_EnableCenter((HIMAGE)m_handle, bCenter);
		}

		// 判断图片是否居中显示  
		bool IsCenter() { 
			return XImage_IsCenter((HIMAGE)m_handle);
		}
		

		// 获取图片绘制类型
		image_draw_type_ GetDrawType() { 
			return XImage_GetDrawType((HIMAGE)m_handle);
		}
		
		// 获取图片宽度
		int GetWidth() { 
			return XImage_GetWidth((HIMAGE)m_handle); 
		}
		
		// 获取图片高度.
		int GetHeight() { 
			return XImage_GetHeight((HIMAGE)m_handle);
		}

		// 返回图片源句柄
		HIMAGE GetImageSrc() { 
			return XImage_GetImageSrc((HIMAGE)m_handle);
		}
		
		// 增加引用计数
		void AddRef() { 
			XImage_AddRef((HIMAGE)m_handle);
		}
		
		// 释放引用计数,当引用计数为0时,自动销毁
		void Release() { 
			XImage_Release((HIMAGE)m_handle);
		}
		
		// 获取引用计数
		int GetRefCount() { 
			return XImage_GetRefCount((HIMAGE)m_handle);
		}
		
		// 强制销毁图片
		void Destroy() { 
			XImage_Destroy((HIMAGE)m_handle);
		}
	};

}
