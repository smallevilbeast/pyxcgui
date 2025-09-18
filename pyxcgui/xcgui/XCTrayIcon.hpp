#pragma once
#include "pch.h"
#include "xcgui/window/XCWindow.hpp"
#include "xcgui/XCImage.hpp"

namespace xcgui {

	class XCTrayIcon
	{
	private:
		HWINDOW m_hWindow;
		UINT m_uID;
		bool m_bCreated;

	public:
		XCTrayIcon()
			: m_hWindow(NULL), m_uID(0), m_bCreated(false)
		{
		}

		XCTrayIcon(HWINDOW hWindow, UINT uID)
			: m_hWindow(hWindow), m_uID(uID), m_bCreated(false)
		{
		}

		XCTrayIcon(const XCWindow& window, UINT uID)
			: m_hWindow(window.GetWindowHandle()), m_uID(uID), m_bCreated(false)
		{
		}

		~XCTrayIcon() {
			if (m_bCreated) {
				Remove();
			}
		}

		// 静态方法：重置所有托盘图标
		static void Reset() {
			XTrayIcon_Reset();
		}

		// 添加托盘图标
		bool Add() {
			if (XTrayIcon_Add(m_hWindow, m_uID)) {
				m_bCreated = true;
				return true;
			}
			return false;
		}

		// 删除托盘图标
		bool Remove() {
			if (m_bCreated && XTrayIcon_Del()) {
				m_bCreated = false;
				return true;
			}
			return false;
		}

		// 修改托盘图标
		bool Modify() {
			return XTrayIcon_Modify();
		}

		// 设置图标
		bool SetIcon(uintptr_t hIcon) {
			XTrayIcon_SetIcon((HICON)hIcon);
			return true;
		}

		// 设置焦点
		bool SetFocus() {
			return XTrayIcon_SetFocus();
		}

		// 设置提示文本（全局方法，影响当前活动的托盘图标）
		static void SetTips(const std::wstring& tips) {
			XTrayIcon_SetTips(tips.c_str());
		}

		// 设置气泡提示（全局方法）
		static void SetPopupBalloon(const std::wstring& title, const std::wstring& text, const XCImage* balloonIcon = nullptr, int flags = 0) {
			HICON hIcon = balloonIcon ? (HICON)balloonIcon->getImageHandle() : NULL;
			XTrayIcon_SetPopupBalloon(title.c_str(), text.c_str(), hIcon, flags);
		}

		// 设置回调消息（全局方法）
		static void SetCallbackMessage(UINT userMessage) {
			XTrayIcon_SetCallbackMessage(userMessage);
		}

		// 获取窗口句柄
		HWINDOW GetWindow() const {
			return m_hWindow;
		}

		// 获取托盘图标ID
		UINT GetID() const {
			return m_uID;
		}

		// 是否已创建
		bool IsCreated() const {
			return m_bCreated;
		}

		// 设置窗口和ID
		void SetWindow(HWINDOW hWindow) {
			m_hWindow = hWindow;
		}

		void SetWindow(const XCWindow& window) {
			m_hWindow = window.GetWindowHandle();
		}

		void SetID(UINT uID) {
			m_uID = uID;
		}
	};

}