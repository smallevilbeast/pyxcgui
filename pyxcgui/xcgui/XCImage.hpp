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

		XCImage(HXCGUI ele)
		{
			m_handle = ele;
		}


		HIMAGE getImageHandle() const
		{
			return (HIMAGE)m_handle;
		}

		// ���ش�ͼƬԴ
		HIMAGE loadSrc(HIMAGE hImageSrc) {
			m_handle = XImage_LoadSrc(hImageSrc);
			return (HIMAGE)m_handle;
		}

		// ���ش��ļ�
		HIMAGE LoadFile(const std::wstring& fileName) { 
			m_handle = XImage_LoadFile(fileName.c_str()); 
			return (HIMAGE)m_handle;
		}

		// ����ͼƬ���ļ�,����ӦͼƬ
		HIMAGE LoadFileAdaptive(const std::wstring& fileName, int leftSize, int topSize, int rightSize, int bottomSize) {
			m_handle = XImage_LoadFileAdaptive(fileName.c_str(), leftSize, topSize, rightSize, bottomSize);
			return (HIMAGE)m_handle;
		}

		// ����ͼƬ,ָ����λ�ü���С
		HIMAGE LoadFileRect(const std::wstring& fileName, int x, int y, int cx, int cy) {
			m_handle = XImage_LoadFileRect(fileName.c_str(), x, y, cx, cy);
			return (HIMAGE)m_handle;
		}

		// ����ͼƬ����Դ,����ӦͼƬ
		HIMAGE LoadResAdaptive(int id, const std::wstring& typeName, int leftSize, int topSize, int rightSize, int bottomSize, HMODULE hModule = NULL) { 
			m_handle = XImage_LoadResAdaptive(id, typeName.c_str(), leftSize, topSize, rightSize, bottomSize, hModule);
			return (HIMAGE)m_handle;
		}

		// ����ͼƬ����Դ
		HIMAGE LoadRes(int id, const std::wstring& typeName, HMODULE hModule = NULL) { 
			m_handle = XImage_LoadRes(id, typeName.c_str(), hModule);
			return (HIMAGE)m_handle;
		}


		// ����ͼƬ��ZIPѹ����
		HIMAGE LoadZip(const std::wstring& zipFileName, const std::wstring& fileName, const std::wstring& password) {
			m_handle = XImage_LoadZip(zipFileName.c_str(), fileName.c_str(), password.c_str());
			return (HIMAGE)m_handle;
		}

		//	����ͼƬ��ZIPѹ����,����ӦͼƬ
		HIMAGE LoadZipAdaptive(const std::wstring& zipFileName, const std::wstring& fileName, const std::wstring& password, int x1, int x2, int y1, int y2) {
			m_handle = XImage_LoadZipAdaptive(zipFileName.c_str(), fileName.c_str(), password.c_str(), x1, x2, y1, y2);
			return (HIMAGE)m_handle;
		}

		// ����ZIPͼƬ,ָ����λ�ü���С
		HIMAGE LoadZipRect(const std::wstring& zipFileName, const std::wstring& fileName, const std::wstring& password, int x, int y, int cx, int cy) {
			m_handle = XImage_LoadZipRect(zipFileName.c_str(), fileName.c_str(), password.c_str(), x, y, cx, cy);
			return (HIMAGE)m_handle;
		}

		// ���ش��ڴ�ZIP
		HIMAGE LoadZipMem(const std::string& data, const std::wstring& fileName, const std::wstring& password) {
			m_handle = XImage_LoadZipMem((void*)data.c_str(), data.size(), fileName.c_str(), password.c_str());
			return (HIMAGE)m_handle;
		}

		// ������ͼƬ,ָ����λ�ü���С
		HIMAGE LoadMemory(const std::string& data) {
			m_handle = XImage_LoadMemory((void*)data.c_str(), data.size());
			return (HIMAGE)m_handle;
		}

		// ������ͼƬ,ָ����λ�ü���С
		HIMAGE LoadMemoryRect(const std::string& data, int x, int y, int cx, int cy) {
			m_handle = XImage_LoadMemoryRect((void*)data.c_str(), data.size(), x, y, cx, cy);
			return (HIMAGE)m_handle;
		}

		// ������ͼƬѹ����,����ӦͼƬ(�Ź���)
		HIMAGE LoadMemoryAdaptive(const std::string& data, int leftSize, int topSize, int rightSize, int bottomSize) { 
			m_handle = XImage_LoadMemoryAdaptive((void*)data.c_str(), data.size(), leftSize, topSize, rightSize, bottomSize);
			return (HIMAGE)m_handle;
		}

		// ����ͼƬ��GDI+��Image����
		HIMAGE LoadFromImage(void* pImage) { 
			m_handle = XImage_LoadFromImage(pImage);
			return (HIMAGE)m_handle;
		}

		// �����ļ�ͼ��,��һ��EXE�ļ���DLL�ļ���ͼ���ļ�;����:*.exe�ļ���ͼ��
		HIMAGE LoadFromExtractIcon(const std::wstring& fileName) { 
			m_handle = XImage_LoadFromExtractIcon(fileName.c_str());
			return (HIMAGE)m_handle;
		}

		// ����һ���Ų�ͼƬ���,��һ�����е�ͼ����HICON.
		HIMAGE LoadFromHICON(HICON hIcon) { 
			m_handle = XImage_LoadFromHICON(hIcon);
			return (HIMAGE)m_handle;
		}

		//  ����һ���Ų�ͼƬ���,��һ�����е�λͼ���HBITMAP
		HIMAGE LoadFromHBITMAP(HBITMAP hBitmap) { 
			m_handle = XImage_LoadFromHBITMAP(hBitmap);
			return (HIMAGE)m_handle;
		}

		// 	hSvg SVG���
		HIMAGE LoadSvg(HSVG hSvg) {
			m_handle = XImage_LoadSvg(hSvg);
			return (HIMAGE)m_handle;
		}

		// ���ش�SVG�ļ�
		HIMAGE LoadSvgFile(const std::wstring& fileName) {
			m_handle = XImage_LoadSvgFile(fileName.c_str());
			return (HIMAGE)m_handle;
		}

		//  ���ֽ��ַ���ANSI
		HIMAGE LoadSvgString(const std::string& data) {
			m_handle = XImage_LoadSvgString(data.c_str());
			return (HIMAGE)m_handle;
		}

		// UNICODE�ַ���
		HIMAGE LoadSvgStringW(const std::wstring& data) {
			m_handle = XImage_LoadSvgStringW(data.c_str());
			return (HIMAGE)m_handle;
		}

		//  ���ش�SVG�ַ���UTF8
		HIMAGE LoadSvgStringUtf8(const std::string& data) {
			m_handle = XImage_LoadSvgStringUtf8(data.c_str());
			return (HIMAGE)m_handle;
		}

		// �Ƿ�Ϊ����ͼƬ���
		bool IsStretch() { 
			return XImage_IsStretch((HIMAGE)m_handle);
		}

		//	�Ƿ�Ϊƽ��ͼƬ
		bool IsTile() { 
			return XImage_IsTile((HIMAGE)m_handle);
		}


		// SVG���
		HSVG GetSvg() { 
			return XImage_GetSvg((HIMAGE)m_handle);
		}

		// ����ͼƬ��������
		bool SetDrawType(image_draw_type_ nType) { 
			return XImage_SetDrawType((HIMAGE)m_handle, nType);
		}

		// ����ͼƬ����Ӧ(�Ź���)
		bool SetDrawTypeAdaptive(int leftSize, int topSize, int rightSize, int bottomSize) { 
			return XImage_SetDrawTypeAdaptive((HIMAGE)m_handle, leftSize, topSize, rightSize, bottomSize);
		}

		// ָ��ͼƬ͸����ɫ
		void SetTranColor(COLORREF color) { 
			XImage_SetTranColor((HIMAGE)m_handle, color);
		}

		// ָ��ͼƬ͸����ɫ��͸����
		void SetTranColorEx(COLORREF color, BYTE tranColor) { 
			XImage_SetTranColorEx((HIMAGE)m_handle, color, tranColor);
		}

		// ������ת�Ƕ�
		float SetRotateAngle(float fAngle) { 
			return XImage_SetRotateAngle((HIMAGE)m_handle, fAngle);
		}

		// �õȷ�()
		void SetSplitEqual(int nCount, int iIndex) { 
			XImage_SetSplitEqual((HIMAGE)m_handle, nCount, iIndex);
		}
		

		// ���û�ر�ͼƬ͸��ɫ
		void EnableTranColor(bool bEnable) {
			XImage_EnableTranColor((HIMAGE)m_handle, bEnable);
		}

		// ���û�ر��Զ�����,����UIԪ�ع���ʱ��Ч
		void EnableAutoDestroy(bool bEnable) {
			XImage_EnableAutoDestroy((HIMAGE)m_handle, bEnable);
		}


		// ���û�ر�ͼƬ������ʾ��Ĭ������ͼƬ��Ч
		void EnableCenter(bool bCenter) { 
			XImage_EnableCenter((HIMAGE)m_handle, bCenter);
		}

		// �ж�ͼƬ�Ƿ������ʾ  
		bool IsCenter() { 
			return XImage_IsCenter((HIMAGE)m_handle);
		}
		

		// ��ȡͼƬ��������
		image_draw_type_ GetDrawType() { 
			return XImage_GetDrawType((HIMAGE)m_handle);
		}
		
		// ��ȡͼƬ���
		int GetWidth() { 
			return XImage_GetWidth((HIMAGE)m_handle); 
		}
		
		// ��ȡͼƬ�߶�.
		int GetHeight() { 
			return XImage_GetHeight((HIMAGE)m_handle);
		}

		// ����ͼƬԴ���
		HIMAGE GetImageSrc() { 
			return XImage_GetImageSrc((HIMAGE)m_handle);
		}
		
		// �������ü���
		void AddRef() { 
			XImage_AddRef((HIMAGE)m_handle);
		}
		
		// �ͷ����ü���,�����ü���Ϊ0ʱ,�Զ�����
		void Release() { 
			XImage_Release((HIMAGE)m_handle);
		}
		
		// ��ȡ���ü���
		int GetRefCount() { 
			return XImage_GetRefCount((HIMAGE)m_handle);
		}
		
		// ǿ������ͼƬ
		void Destroy() { 
			XImage_Destroy((HIMAGE)m_handle);
		}

		// 3.3.5 ����
		// �����Ŵ�С �����������Ժ���Ч,ֵ����0��Ч
		void SetScaleSize(int width, int height) {
			XImage_SetScaleSize((HIMAGE)m_handle, width, height);
		}
		
	};

}
