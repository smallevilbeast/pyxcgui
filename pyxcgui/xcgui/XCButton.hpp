#pragma once
#include "pch.h"
#include "XCElement.hpp"

namespace xcgui {
	class XCButton : XCElement
	{
	public:
		// 创建按钮元素  
		HELE Create(int x, int y, int cx, int cy, const wchar_t* pName, HXCGUI hParent = NULL) {
			m_handle = XBtn_Create(x, y, cx, cy, pName, hParent); return (HELE)m_handle;
		}

		// 创建按钮元素  
		XCButton(int x, int y, int cx, int cy, const wchar_t* pName, HXCGUI hParent = NULL) {
			m_handle = XBtn_Create(x, y, cx, cy, pName, hParent);
		}

		// 是否选中状态.  
		bool IsCheck() {
			return XBtn_IsCheck((HELE)m_handle);
		}

		// 设置选中状态.  
		bool SetCheck(bool bCheck) {
			return XBtn_SetCheck((HELE)m_handle, bCheck);
		}

		// 设置按钮状态.  
		void SetState(common_state3_ nState) {
			XBtn_SetState((HELE)m_handle, nState);
		}

		// 获取按钮状态
		common_state3_ GetState() {
			return XBtn_GetState((HELE)m_handle);
		}

		// 获取按钮状态
		button_state_ GetStateEx() {
			return XBtn_GetStateEx((HELE)m_handle);
		}

		// 设置按钮类型并自动修改样式和文本对齐方式.  
		void SetTypeEx(XC_OBJECT_TYPE_EX nType) {
			XBtn_SetTypeEx((HELE)m_handle, nType);
		}

		// 设置组ID.  
		void SetGroupID(int nID) {
			XBtn_SetGroupID((HELE)m_handle, nID);
		}

		// 获取组ID.  
		int GetGroupID() {
			return XBtn_GetGroupID((HELE)m_handle);
		}

		// 设置绑定元素.  
		void SetBindEle(HELE hBindEle) {
			XBtn_SetBindEle((HELE)m_handle, hBindEle);
		}

		// 获取绑定的元素.  
		HELE GetBindEle() {
			return XBtn_GetBindEle((HELE)m_handle);
		}

		// 设置文本对齐方式.  
		void SetTextAlign(int nFlags) {
			XBtn_SetTextAlign((HELE)m_handle, nFlags);
		}

		// 获取文本对齐方式.  
		int GetTextAlign() {
			return XBtn_GetTextAlign((HELE)m_handle);
		}

		// 设置图标对齐.  
		void SetIconAlign(button_icon_align_ align) {
			XBtn_SetIconAlign((HELE)m_handle, align);
		}

		// 设置按钮文本坐标偏移量.  
		void SetOffset(int x, int y) {
			XBtn_SetOffset((HELE)m_handle, x, y);
		}

		// 设置按钮图标坐标偏移量.  )
		void SetOffsetIcon(int x, int y) {
			XBtn_SetOffsetIcon((HELE)m_handle, x, y);
		}

		// 设置图标与文本间隔大小.  
		void SetIconSpace(int size) {
			XBtn_SetIconSpace((HELE)m_handle, size);
		}

		// 设置文本内容.  
		void SetText(const std::wstring& name) {
			XBtn_SetText((HELE)m_handle, name.c_str());
		}

		// 获取文本内容.  
		std::wstring GetText() {
			auto pText = XBtn_GetText((HELE)m_handle);
			if (!pText) {
				return L"";
			}
			return pText;
		}

		// 设置图标.  
		void SetIcon(HIMAGE hImage) {
			XBtn_SetIcon((HELE)m_handle, hImage);
		}

		// 设置图标禁用状态
		void SetIconDisable(HIMAGE hImage) {
			XBtn_SetIconDisable((HELE)m_handle, hImage);
		}

		// 获取用户设置的图标.  
		HIMAGE GetIcon(int nType) {
			return XBtn_GetIcon((HELE)m_handle, nType);
		}

		// 添加动画帧.  
		void AddAnimationFrame(HIMAGE hImage, UINT uElapse) {
			XBtn_AddAnimationFrame((HELE)m_handle, hImage, uElapse);
		}

		// 开始或关闭图片动画的播放.  
		void EnableAnimation(bool bEnable, bool bLoopPlay = false) {
			XBtn_EnableAnimation((HELE)m_handle, bEnable, bLoopPlay);
		}
	};


}
