#pragma once
#include "pch.h"

namespace xcgui {


	class XCGlobal {
	public:

		// 弹出提示框
		static void Alert(const std::wstring& title, const std::wstring& text) {
			XC_Alert(title.c_str(), text.c_str());
		}

		// 消息框
		static int MessageBox(const std::wstring& title, const std::wstring& text, int flags, HWND hWndParent, int XCStyle) {
			return XC_MessageBox(title.c_str(), text.c_str(), flags, hWndParent, XCStyle);
		}

		static bool PostMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
			return ::PostMessage(hWnd, msg, wParam, lParam);
		}

		static bool SendMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
			return ::SendMessage(hWnd, msg, wParam, lParam);
		}

		static void PostQuitMessage(int exitCode) {
			return XC_PostQuitMessage(exitCode);
		}

		static bool RegisterWindowClassName(const std::wstring& className) {
			return XC_RegisterWindowClassName(className.c_str());
		}

		// 激活当前进程最上层窗口
		static bool SetActivateTopWindow() {
			return XC_SetActivateTopWindow();
		}

		static void SetDefaultFont(HFONTX font) {
			XC_SetDefaultFont(font);
		}

		static HFONTX GetDefaultFont() {
			return XC_GetDefaultFont();
		}


		static void CombineRect(RECT* pDest, RECT* pSrc1, RECT* pSrc2) {
			XC_CombineRect(pDest, pSrc1, pSrc2);
		}


		static bool RectInRect(RECT* pRect1, RECT* pRect2) {
			return XC_RectInRect(pRect1, pRect2);
		}


		static void* Malloc(int size) {
			return XC_Malloc(size);
		}

		static FARPROC GetProcAddress(HMODULE hModule, const std::string& procName) {
			return XC_GetProcAddress(hModule, procName.c_str());
		}

		static HMODULE LoadDll(const std::wstring& dll) {
			return XC_LoadDll(dll.c_str());
		}

		static HMODULE LoadLibrary(const std::wstring& fileName) {
			return XC_LoadLibrary(fileName.c_str());
		}


		static void Free(void* p) {
			XC_Free(p);
		}

		static bool FreeLibrary(HMODULE hModule) {
			return XC_FreeLibrary(hModule);
		}


	};


	



}