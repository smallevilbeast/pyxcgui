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

		XCSvg(HSVG svgHandle)
			:XCObject(svgHandle)
		{
			m_handle = svgHandle;
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

		// 加载图片从ZIP压缩包
		HSVG LoadZip(const std::wstring& zipFileName, const std::wstring& fileName, const std::wstring& password) {
			m_handle = XSvg_LoadZip(zipFileName.c_str(), fileName.c_str(), password.c_str());
			return (HSVG)m_handle;
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

		// 启用或关闭自动销毁,当与UI元素关联时有效
		void EnableAutoDestroy(bool bEnable) {
			XSvg_EnableAutoDestroy((HSVG)m_handle, bEnable);
		}

		// 增加引用计数
		void AddRef() {
			XSvg_AddRef((HSVG)m_handle);
		}

		// 释放引用计数,当引用计数为0时,自动销毁
		void Release() {
			XSvg_Release((HSVG)m_handle);
		}

		// 获取引用计数
		int GetRefCount() {
			return XSvg_GetRefCount((HSVG)m_handle);
		}

		// 强制销毁图片
		void Destroy() {
			XSvg_Destroy((HSVG)m_handle);
		}


	};
}