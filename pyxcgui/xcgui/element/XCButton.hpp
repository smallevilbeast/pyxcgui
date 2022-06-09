#pragma once
#include "pch.h"
#include "xcgui/XCElement.hpp"

namespace xcgui {
	class XCButton : public XCElement
	{
	public:
		XCButton(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCButton() = default;

		// ������ťԪ��  
		HELE Create(int x, int y, int cx, int cy, const std::wstring& name, HXCGUI hParent = NULL) {
			m_handle = XBtn_Create(x, y, cx, cy, name.c_str(), hParent); return (HELE)m_handle;
		}

		// ������ťԪ��  
		XCButton(int x, int y, int cx, int cy, const std::wstring& name, HXCGUI hParent = NULL) {
			m_handle = XBtn_Create(x, y, cx, cy, name.c_str(), hParent);
		}

		// �Ƿ�ѡ��״̬.  
		bool IsCheck() {
			return XBtn_IsCheck((HELE)m_handle);
		}

		// ����ѡ��״̬.  
		bool SetCheck(bool bCheck) {
			return XBtn_SetCheck((HELE)m_handle, bCheck);
		}

		// ���ð�ť״̬.  
		void SetState(common_state3_ nState) {
			XBtn_SetState((HELE)m_handle, nState);
		}

		// ��ȡ��ť״̬
		common_state3_ GetState() {
			return XBtn_GetState((HELE)m_handle);
		}

		// ��ȡ��ť״̬
		button_state_ GetStateEx() {
			return XBtn_GetStateEx((HELE)m_handle);
		}

		// ���ð�ť���Ͳ��Զ��޸���ʽ���ı����뷽ʽ.  
		void SetBtnTypeEx(XC_OBJECT_TYPE_EX nType) {
			XBtn_SetTypeEx((HELE)m_handle, nType);
		}

		// ������ID.  
		void SetGroupID(int nID) {
			XBtn_SetGroupID((HELE)m_handle, nID);
		}

		// ��ȡ��ID.  
		int GetGroupID() {
			return XBtn_GetGroupID((HELE)m_handle);
		}

		// ���ð�Ԫ��.  
		void SetBindEle(HELE hBindEle) {
			XBtn_SetBindEle((HELE)m_handle, hBindEle);
		}

		// ��ȡ�󶨵�Ԫ��.  
		HELE GetBindEle() {
			return XBtn_GetBindEle((HELE)m_handle);
		}

		// �����ı����뷽ʽ.  
		void SetTextAlign(int nFlags) {
			XBtn_SetTextAlign((HELE)m_handle, nFlags);
		}

		// ��ȡ�ı����뷽ʽ.  
		int GetTextAlign() {
			return XBtn_GetTextAlign((HELE)m_handle);
		}

		// ����ͼ�����.  
		void SetIconAlign(button_icon_align_ align) {
			XBtn_SetIconAlign((HELE)m_handle, align);
		}

		// ���ð�ť�ı�����ƫ����.  
		void SetOffset(int x, int y) {
			XBtn_SetOffset((HELE)m_handle, x, y);
		}

		// ���ð�ťͼ������ƫ����.  )
		void SetOffsetIcon(int x, int y) {
			XBtn_SetOffsetIcon((HELE)m_handle, x, y);
		}

		// ����ͼ�����ı������С.  
		void SetIconSpace(int size) {
			XBtn_SetIconSpace((HELE)m_handle, size);
		}

		// �����ı�����.  
		void SetText(const std::wstring& name) {
			XBtn_SetText((HELE)m_handle, name.c_str());
		}

		// ��ȡ�ı�����.  
		std::wstring GetText() {
			auto pText = XBtn_GetText((HELE)m_handle);
			if (!pText) {
				return L"";
			}
			return pText;
		}

		// ����ͼ��.  
		void SetIcon(HIMAGE hImage) {
			XBtn_SetIcon((HELE)m_handle, hImage);
		}

		// ����ͼ�����״̬
		void SetIconDisable(HIMAGE hImage) {
			XBtn_SetIconDisable((HELE)m_handle, hImage);
		}

		// ��ȡ�û����õ�ͼ��.  
		HIMAGE GetIcon(int nType) {
			return XBtn_GetIcon((HELE)m_handle, nType);
		}

		// ��Ӷ���֡.  
		void AddAnimationFrame(HIMAGE hImage, UINT uElapse) {
			XBtn_AddAnimationFrame((HELE)m_handle, hImage, uElapse);
		}

		// ��ʼ��ر�ͼƬ�����Ĳ���.  
		void EnableAnimation(bool bEnable, bool bLoopPlay = false) {
			XBtn_EnableAnimation((HELE)m_handle, bEnable, bLoopPlay);
		}
	};


}
