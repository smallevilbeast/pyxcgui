#pragma once
#include "pch.h"
#include "XCObject.hpp"

namespace xcgui {

	class XCBkManager: public XCObject
	{
	public:
		XCBkManager()
			: XCObject() 
		{
			m_handle = XBkM_Create();
		}

		~XCBkManager() {
		}

		XCBkManager(HBKM handle) :
			XCObject(handle)
		{

		}

		HBKM GetBkmHandle() const {
			return (HBKM)m_handle;
		}

		// 
		void Destroy() { 
			XBkM_Destroy(GetBkmHandle());
		}

		// 设置背景内容
		int SetBkInfo(const std::wstring& text) { 
			return XBkM_SetBkInfo(GetBkmHandle(), text.c_str()); 
		}

		// 	设置背景内容
		int SetInfo(const std::wstring& text) {
			return XBkM_SetInfo(GetBkmHandle(), text.c_str());
		}

		// 添加背景内容
		int AddInfo(const std::wstring& text) {
			return XBkM_AddInfo(GetBkmHandle(), text.c_str());
		}

		// 添加边框()
		void AddBorder(int nState, COLORREF color, int width, int id = 0) {
			XBkM_AddBorder(GetBkmHandle(), nState, color, width, id);
		}

		// 添加背景内容填充
		void AddFill(int nState, COLORREF color, int id = 0) {
			XBkM_AddFill(GetBkmHandle(), nState, color, id);
		}

		// 添加背景内容图片
		void AddImage(int nState, HIMAGE hImage, int id = 0) {
			XBkM_AddImage(GetBkmHandle(), nState, hImage, id);
		}
		
		// 获取背景内容数量
		int GetCount() {
			return XBkM_GetCount(GetBkmHandle());
		}

		// 	清空背景内容
		void Clear() {
			XBkM_Clear(GetBkmHandle());
		}

		// 绘制背景内容
		bool Draw(int nState, HDRAW hDraw, RECT* pRect) {
			return XBkM_Draw(GetBkmHandle(), nState, hDraw, pRect);
		}

		// 绘制背景内容, 设置条件
		bool DrawEx(int nState, HDRAW hDraw, RECT* pRect, int nStateEx) { 
			return XBkM_DrawEx(GetBkmHandle(), nState, hDraw, pRect, nStateEx);
		}

		// 是否自动销毁
		void EnableAutoDestroy(BOOL bEnable) {
			XBkM_EnableAutoDestroy(GetBkmHandle(), bEnable);
		}

		// 增加引用计数
		void AddRef() { 
			XBkM_AddRef(GetBkmHandle()); 
		}

	    // 释放引用计数,当引用计数为0时,自动销毁
		void Release() { 
			XBkM_Release(GetBkmHandle()); 
		}

		// 获取引用计数
		int GetRefCount() { 
			return XBkM_GetRefCount(GetBkmHandle()); 
		}

		// 取指定状态文本颜色
		bool GetStateTextColor(int nState, COLORREF* color) { 
			return XBkM_GetStateTextColor(GetBkmHandle(), nState, color); 
		}

		// 背景对象ID
		vint GetObject(int id) { 
			return XBkM_GetObject(GetBkmHandle(), id); 
		}

	};
}
