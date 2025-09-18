#pragma once
#include "pch.h"
#include "xcgui/window/XCWindow.hpp"
#include "xcgui/XCImage.hpp"

namespace xcgui {

	/**
	 * @brief 托盘图标类 - XCGUI 3.3.8.1新增
	 *
	 * 提供Windows系统托盘图标的完整功能封装，支持RAII资源管理。
	 * 自动在析构时清理托盘图标，防止资源泄露。
	 *
	 * 主要功能：
	 * - 托盘图标的添加、删除和修改
	 * - 图标、提示文本、气球提示的设置
	 * - 消息回调和焦点管理
	 * - 静态方法用于全局托盘系统管理
	 */
	class XCTrayIcon
	{
	private:
		HWINDOW m_hWindow;    ///< 关联的窗口句柄
		UINT m_uID;           ///< 托盘图标唯一标识符
		bool m_bCreated;      ///< 托盘图标是否已创建

	public:
		/**
		 * @brief 默认构造函数
		 *
		 * 创建一个未初始化的托盘图标对象，需要后续调用其他方法设置参数。
		 */
		XCTrayIcon()
			: m_hWindow(NULL), m_uID(0), m_bCreated(false)
		{
		}

		/**
		 * @brief 使用窗口句柄构造托盘图标
		 *
		 * @param hWindow 关联的窗口句柄
		 * @param uID 托盘图标的唯一标识符
		 */
		XCTrayIcon(HWINDOW hWindow, UINT uID)
			: m_hWindow(hWindow), m_uID(uID), m_bCreated(false)
		{
		}

		/**
		 * @brief 使用XCWindow对象构造托盘图标
		 *
		 * @param window XCWindow窗口对象引用
		 * @param uID 托盘图标的唯一标识符
		 */
		XCTrayIcon(const XCWindow& window, UINT uID)
			: m_hWindow(window.GetWindowHandle()), m_uID(uID), m_bCreated(false)
		{
		}

		/**
		 * @brief 析构函数 - RAII资源管理
		 *
		 * 自动清理托盘图标资源，防止系统托盘中留下无效图标。
		 */
		~XCTrayIcon() {
			if (m_bCreated) {
				Remove();
			}
		}

		/**
		 * @brief 重置所有托盘图标（静态方法）
		 *
		 * 清理系统中所有XCGUI创建的托盘图标，通常在程序启动时调用。
		 */
		static void Reset() {
			XTrayIcon_Reset();
		}

		/**
		 * @brief 添加托盘图标到系统托盘
		 *
		 * 使用构造时设置的窗口句柄和ID创建托盘图标。
		 *
		 * @return 成功返回true，失败返回false
		 */
		bool Add() {
			if (XTrayIcon_Add(m_hWindow, m_uID)) {
				m_bCreated = true;
				return true;
			}
			return false;
		}

		/**
		 * @brief 从系统托盘删除托盘图标
		 *
		 * 手动删除托盘图标，正常情况下不需手动调用（析构时自动调用）。
		 *
		 * @return 成功返回true，失败返回false
		 */
		bool Remove() {
			if (m_bCreated && XTrayIcon_Del()) {
				m_bCreated = false;
				return true;
			}
			return false;
		}

		/**
		 * @brief 修改托盘图标属性
		 *
		 * 更新已存在的托盘图标的属性（如图标、提示等）。
		 *
		 * @return 成功返回true，失败返回false
		 */
		bool Modify() {
			return XTrayIcon_Modify();
		}

		/**
		 * @brief 设置托盘图标的图标
		 *
		 * @param hIcon 图标句柄（HICON类型，传入uintptr_t）
		 * @return 始终返回true
		 */
		bool SetIcon(uintptr_t hIcon) {
			XTrayIcon_SetIcon((HICON)hIcon);
			return true;
		}

		/**
		 * @brief 设置托盘图标获取焦点
		 *
		 * 使托盘图标获取焦点，通常用于显示气球提示等情况。
		 *
		 * @return 成功返回true，失败返回false
		 */
		bool SetFocus() {
			return XTrayIcon_SetFocus();
		}

		/**
		 * @brief 设置托盘图标的提示文本（静态方法）
		 *
		 * 设置当前活动托盘图标的鼠标悬停提示文本。
		 * 注意：这是全局设置，影响当前活动的托盘图标。
		 *
		 * @param tips 提示文本字符串
		 */
		static void SetTips(const std::wstring& tips) {
			XTrayIcon_SetTips(tips.c_str());
		}

		/**
		 * @brief 显示托盘图标的气球提示（静态方法）
		 *
		 * 在托盘区显示气球式通知提示。
		 * 注意：这是全局设置，影响当前活动的托盘图标。
		 *
		 * @param title 气球提示的标题
		 * @param text 气球提示的内容文本
		 * @param balloonIcon 气球图标（可选，默认nullptr）
		 * @param flags 气球显示标志（默认0）
		 */
		static void SetPopupBalloon(const std::wstring& title, const std::wstring& text, const XCImage* balloonIcon = nullptr, int flags = 0) {
			HICON hIcon = balloonIcon ? (HICON)balloonIcon->getImageHandle() : NULL;
			XTrayIcon_SetPopupBalloon(title.c_str(), text.c_str(), hIcon, flags);
		}

		/**
		 * @brief 设置托盘图标事件回调消息（静态方法）
		 *
		 * 设置托盘图标事件（如点击、双击等）的回调消息ID。
		 * 注意：这是全局设置，影响所有托盘图标的事件通知。
		 *
		 * @param userMessage 用户自定义消息ID，用于接收托盘事件
		 */
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