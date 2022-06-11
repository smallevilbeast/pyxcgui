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

		XCSvg(HXCGUI handle)
		{
			m_handle = handle;
		}

		HSVG getSvgHandle() const {
			return (HSVG)m_handle;
		}

		HSVG LoadFile(const std::wstring& fileName) {
			m_handle = XSvg_LoadFile(fileName.c_str());
			return (HSVG)m_handle;
		}

		HSVG LoadRes(int id, const std::wstring& typeName, HMODULE hModule) {
			m_handle = XSvg_LoadRes(id, typeName.c_str(), hModule);
			return (HSVG)m_handle;
		}

		HSVG LoadString(const std::string& data) {
			m_handle = XSvg_LoadString(data.c_str());
			return (HSVG)m_handle;
		}

		HSVG LoadStringUtf8(const std::string& data) {
			m_handle = XSvg_LoadStringUtf8(data.c_str());
			return (HSVG)m_handle;
		}

		HSVG LoadStringW(const std::wstring& data) {
			m_handle = XSvg_LoadStringW(data.c_str());
			return (HSVG)m_handle;
		}

		// ����ͼƬ��ZIPѹ����
		HSVG LoadZip(const std::wstring& zipFileName, const std::wstring& fileName, const std::wstring& password) {
			m_handle = XSvg_LoadZip(zipFileName.c_str(), fileName.c_str(), password.c_str());
			return (HSVG)m_handle;
		}

		// ���ش��ڴ�ZIP
		HIMAGE LoadZipMem(const std::string& data, const std::wstring& fileName, const std::wstring& password) {
			m_handle = XSvg_LoadZipMem((void*)data.c_str(), data.size(), fileName.c_str(), password.c_str());
			return (HIMAGE)m_handle;
		}

		void Show(bool bShow) {
			XSvg_Show((HSVG)m_handle, bShow);
		}

		void SetAlpha(BYTE alpha) {
			XSvg_SetAlpha((HSVG)m_handle, alpha);
		}

		BYTE GetAlpha() {
			return XSvg_GetAlpha((HSVG)m_handle);
		}

		void SetPosition(int x, int y) {
			XSvg_SetPosition((HSVG)m_handle, x, y);
		}

		void GetPosition(int* pX, int* pY) {
			XSvg_GetPosition((HSVG)m_handle, pX, pY);
		}

		void SetRotate(float angle, float x, float y, bool bOffset) {
			XSvg_SetRotate((HSVG)m_handle, x, y, bOffset);
		}

		void GetRotate(float* angle, float* pX, float* pY, bool* offset) {
			XSvg_GetRotate((HSVG)m_handle, angle, pX, pY, (BOOL*)offset);
		}

		void SetRotateAngle(float angle) {
			XSvg_SetRotateAngle((HSVG)m_handle, angle);
		}

		float GetRotateAngle() {
			return XSvg_GetRotateAngle((HSVG)m_handle);
		}

		void SetSize(int width, int height) {
			XSvg_SetSize((HSVG)m_handle, width, height);
		}

		void GetSize(int* pWidth, int* pHeight) {
			XSvg_GetSize((HSVG)m_handle, pWidth, pHeight);
		}

		int GetWidth() {
			return XSvg_GetWidth((HSVG)m_handle);
		}

		int GetHeight() {
			return XSvg_GetHeight((HSVG)m_handle);
		}

		void GetViewBox(RECT* pViewBox) {
			XSvg_GetViewBox((HSVG)m_handle, pViewBox);
		}

		void SetUserFillColor(COLORREF color, bool bEnable) {
			XSvg_SetUserFillColor((HSVG)m_handle, color, bEnable);
		}

		bool GetUserFillColor(COLORREF* pColor) {
			return XSvg_GetUserFillColor((HSVG)m_handle, pColor);
		}

		bool GetUserStrokeColor(COLORREF* pColor, float* pStrokeWidth) {
			return XSvg_GetUserStrokeColor((HSVG)m_handle, pColor, pStrokeWidth);
		}

		void SetUserStrokeColor(COLORREF color, float strokeWidth, bool bEnable) {
			XSvg_SetUserStrokeColor((HSVG)m_handle, color, strokeWidth, bEnable);
		}

		// ���û�ر��Զ�����,����UIԪ�ع���ʱ��Ч
		void EnableAutoDestroy(bool bEnable) {
			XSvg_EnableAutoDestroy((HSVG)m_handle, bEnable);
		}

		// �������ü���
		void AddRef() {
			XSvg_AddRef((HSVG)m_handle);
		}

		// �ͷ����ü���,�����ü���Ϊ0ʱ,�Զ�����
		void Release() {
			XSvg_Release((HSVG)m_handle);
		}

		// ��ȡ���ü���
		int GetRefCount() {
			return XSvg_GetRefCount((HSVG)m_handle);
		}

		// ǿ������ͼƬ
		void Destroy() {
			XSvg_Destroy((HSVG)m_handle);
		}


	};
}