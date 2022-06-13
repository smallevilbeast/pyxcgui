#pragma once

#include "pch.h"
#include "xcgui/XCObjectUI.hpp"  
#include "xcgui/XCStruct.hpp"
#include "xcgui/XCLayoutBox.hpp"
#include "xcgui/XCImage.hpp"
#include "xcgui/XCDesigner.hpp"

namespace xcgui {
	class XCWindow : public XCObjectUI,  public XCLayoutBox
	{
	public:

		XCWindow(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCWindow()
		{
			//auto hWindow = XWnd_Create(0, 0, 0, 0, NULL, NULL, window_style_default);
			//this->SetWindowHandle(hWindow);
		}

		XCWindow(int width, int height, const std::wstring& title) 
			: XCObjectUI() 
		{
			m_handle = XWnd_Create(0, 0, width, height, title.c_str(), NULL, window_style_default);
		}

		XCWindow(int x, int y, int width, int height, const std::wstring& title, uintptr_t hWndParent = 0, int style = window_style_default)
			: XCObjectUI()
		{
			m_handle = XWnd_Create(x, y, width, height, title.c_str(), (HWND)hWndParent, style);
		}

		XCWindow(DWORD dwExStyle, DWORD dwStyle, const std::wstring& className,
			int x, int y, int cx, int cy, const std::wstring& title, uintptr_t hWndParent, int xcStyle = window_style_default)
		{
			m_handle = XWnd_CreateEx(dwExStyle, dwStyle, (wchar_t*)className.c_str(),
				x, y, cx, cy, (wchar_t*)title.c_str(), (HWND)hWndParent, xcStyle);
		}


		// hWnd Ҫ���ӵ��ⲿ���ھ��
		virtual bool Attach(uintptr_t hWnd, int style)
		{
			m_handle = XWnd_Attach((HWND)hWnd, style);
			return m_handle;
		}

		// 	����Ӷ��󵽴��� 
		bool AddChild(const XCObjectUI& child) 
		{
			return XWnd_AddChild(GetWindowHandle(), child.GetHandle());
		}

		// 	�����Ӷ���ָ��λ��
		bool InsertChild(const XCObjectUI& child, int index)
		{
			return XWnd_InsertChild(GetWindowHandle(), child.GetHandle(), index);
		}

		// �ػ洰��
		void Redraw(bool bImmediate = false)
		{
			XWnd_Redraw(GetWindowHandle(), bImmediate);
		}

		// �ػ洰��ָ������
		void RedrawRect(const XCRect& rect, bool bImmediate = false)
		{
			return XWnd_RedrawRect(GetWindowHandle(), (RECT*)&rect, bImmediate);
		}

		// ���ý���Ԫ��
		void SetFoucsEle(const XCObjectUI& ele) 
		{
			XWnd_SetFocusEle(GetWindowHandle(), (HELE)ele.GetHandle());
		}

		// ���ӵ�����뽹���Ԫ��
		HELE GetFocusEle() const
		{
			auto winHandle = GetWindowHandle();
			if (!winHandle)
				return nullptr;

			return XWnd_GetFocusEle(winHandle);
		}

		// ��ȡ��ǰ�����ͣ��Ԫ��
		HELE GetStayEle() const 
		{
			auto winHandle = GetWindowHandle();
			if (!winHandle)
				return nullptr;
			return XWnd_GetStayEle(GetWindowHandle());
		}

		//  ���Ի��¼�������,�û��ֶ����û��ƴ���,�Ա���ƻ���˳��
		void DrawWindow(HDRAW hDraw) 
		{
			XWnd_DrawWindow(GetWindowHandle(), hDraw);
		}

		// ���д���
		void Center() {
			XWnd_Center(GetWindowHandle());
		}

		// ������չ
		void CenterEx(int width, int height) {
			XWnd_CenterEx(GetWindowHandle(), width, height);
		}


		// ���ô��������
		void SetCursor(HCURSOR hCursor) {
			XWnd_SetCursor(GetWindowHandle(), hCursor);
		}


		// ��ȡ���ڵ������
		HCURSOR GetCursor() { 
			return XWnd_GetCursor(GetWindowHandle());
		}

		// ��ȡHWND���
		HWND GetHWND() { 
			return XWnd_GetHWND(GetWindowHandle());
		}

		// �����϶����ڱ߿�
		void EnableDragBorder(bool bEnable) { 
			XWnd_EnableDragBorder(GetWindowHandle(), bEnable);
		}

		// �����϶�����
		void EnableDragWindow(bool bEnable) { 
			XWnd_EnableDragWindow(GetWindowHandle(), bEnable); 
		}

		// �����϶����ڱ�����
		void EnableDragCaption(bool bEnable) { 
			XWnd_EnableDragCaption(GetWindowHandle(), bEnable);
		}

		// �Ƿ���ƴ��ڱ���
		void EnableDrawBk(bool bEnable) {
			XWnd_EnableDrawBk(GetWindowHandle(), bEnable); 
		}

		// �����Զ�����(�������������Ƿ��ý���.)
		void EnableAutoFocus(bool bEnable) { 
			XWnd_EnableAutoFocus(GetWindowHandle(), bEnable);
		}

		// ���������
		void EnableMaxWindow(bool bEnable) { 
			XWnd_EnableMaxWindow(GetWindowHandle(), bEnable);
		}

		// ���ƴ�����С�����ߴ�
		void EnablemLimitWindowSize(bool bEnable) { 
			XWnd_EnablemLimitWindowSize(GetWindowHandle(), bEnable); 
		}

		// �����Ϸ��ļ�
		void EnableDragFiles(bool bEnable) { 
			XWnd_EnableDragFiles(GetWindowHandle(), bEnable);
		}

		// ���ò��ֹ���
		void EnableLayout(bool bEnable) {
			XWnd_EnableLayout(GetWindowHandle(), bEnable);
		}

		// ���ò��ָ��Ǳ߿�
		void EnableLayoutOverlayBorder(bool bEnable) { 
			XWnd_EnableLayoutOverlayBorder(GetWindowHandle(), bEnable);
		}

		// ��ʾ���ֱ߽�
		void ShowLayoutFrame(bool bEnable) { 
			XWnd_ShowLayoutFrame(GetWindowHandle(), bEnable);
		}

		// �ж��Ƿ����ò���
		bool IsEnableLayout() { 
			return XWnd_IsEnableLayout(GetWindowHandle());
		}

		// �Ƿ����
		bool IsMaxWindow() { 
			return XWnd_IsMaxWindow(GetWindowHandle()); 
		}

		// �Ƿ���϶��߿�
		bool IsDragBorder() { 
			return XWnd_IsDragBorder(GetWindowHandle());
		}

		// �Ƿ���϶�������
		bool IsDragCaption() { 
			return XWnd_IsDragCaption(GetWindowHandle());
		}

		// ������겶��Ԫ��
		void SetCaptureEle(HELE hEle) { 
			XWnd_SetCaptureEle(GetWindowHandle(), hEle);
		}

		// ��ȡ��ǰ��겶��Ԫ��
		HELE GetCaptureEle() { 
			return XWnd_GetCaptureEle(GetWindowHandle());
		}

		// ��ȡ�ػ�����
		void GetDrawRect(RECT* pRcPaint) { 
			XWnd_GetDrawRect(GetWindowHandle(), pRcPaint);
		}

		// 	��ʾ���ش���
		void Show(bool bShow) { 
			XWnd_Show(GetWindowHandle(), bShow); 
		}

		// ��ʾ���ؼ����ƴ�����󻯻�ԭ��
		bool ShowWindow(int showType = SW_SHOW)
		{
			return XWnd_ShowWindow(GetWindowHandle(), showType);
		}

		// ϵͳ����,���ô���������
		HCURSOR SetCursorSys(HCURSOR hCursor) { 
			return XWnd_SetCursorSys(GetWindowHandle(), hCursor);
		}

		// ���ô�������
		void SetFont(HFONTX hFontx) { 
			XWnd_SetFont(GetWindowHandle(), hFontx); 
		}

		// �����ı���ɫ
		void SetTextColor(COLORREF color) { 
			XWnd_SetTextColor(GetWindowHandle(), color); 
		}

		// ��ȡ�ı���ɫ
		COLORREF GetTextColor() { 
			return XWnd_GetTextColor(GetWindowHandle());
		}

		// ��ȡ�ı���ɫ,���ȴ���Դ�л�ȡ
		COLORREF GetTextColorEx() { 
			return XWnd_GetTextColorEx(GetWindowHandle()); 
		}

		// ���ô���ID
		void SetID(int nID) { 
			XWnd_SetID(GetWindowHandle(), nID);
		}

		// ��ȡ����ID
		int GetID() { 
			return XWnd_GetID(GetWindowHandle());
		}

		// ���ô���name
		void SetName(const std::wstring& name) { 
			XWnd_SetName(GetWindowHandle(), name.c_str());
		}

		// ��ȡ����name
		std::wstring GetName() { 
			auto pName = XWnd_GetName(GetWindowHandle());
			if (!pName) {
				return L"";
			}
			return pName;
		}

		// ���ñߴ�С
		void SetBorderSize(int left, int top, int right, int bottom) { 
			XWnd_SetBorderSize(GetWindowHandle(), left, top, right, bottom); 
		}

		// ��ȡ�ߴ�С
		void GetBorderSize(borderSize_* pBorder) { 
			XWnd_GetBorderSize(GetWindowHandle(), pBorder);
		}

		// ��������С
		void SetPadding(int left, int top, int right, int bottom) { 
			XWnd_SetPadding(GetWindowHandle(), left, top, right, bottom);
		}

		// ���ô����϶��߿��С
		void SetDragBorderSize(int left, int top, int right, int bottom) { 
			XWnd_SetDragBorderSize(GetWindowHandle(), left, top, right, bottom);
		}

		// ��ȡ�����϶��߿��С
		void GetDragBorderSize(borderSize_* pSize) { 
			XWnd_GetDragBorderSize(GetWindowHandle(), pSize); 
		}

		//  �ñ�������
		void SetCaptionMargin(int left, int top, int right, int bottom) { 
			XWnd_SetCaptionMargin(GetWindowHandle(), left, top, right, bottom);
		}

		// ���ô��ڵ���С��Ⱥ͸߶�
		void SetMinimumSize(int width, int height) { 
			XWnd_SetMinimumSize(GetWindowHandle(), width, height); 
		}

		// �������Ԫ��
		HELE HitChildEle(POINT* pPt) { 
			return XWnd_HitChildEle(GetWindowHandle(), pPt);
		}

		// ��ȡ��ǰ���Ӷ�������,��������Ԫ�ص���Ԫ��
		int GetChildCount() { 
			return XWnd_GetChildCount(GetWindowHandle());
		}

		// ��ȡ��ǰ����Ԫ��ͨ������
		HXCGUI GetChildByIndex(int index) { 
			return XWnd_GetChildByIndex(GetWindowHandle(), index);
		}

		// ��ȡ��ǰ���Ӷ���ͨ������ID
		HXCGUI GetChildByID(int nID) { 
			return XWnd_GetChildByID(GetWindowHandle(), nID); 
		}

		// ��ȡ�Ӷ���ͨ������ID,��������ڸô�������Ч
		HXCGUI FindChildByID(int nID) { 
			return XWnd_GetChild(GetWindowHandle(), nID); 
		}

		HXCGUI FindChildByIDName(const std::wstring& name) {
			return XC_GetObjectByIDName(GetWindowHandle(), name.c_str());
		}
		
		// ��ͼ��
		void SetIcon(HIMAGE hImage) { 
			XWnd_SetIcon(GetWindowHandle(), hImage);
		}

		// �ñ���
		void SetTitle(const std::wstring& title) { 
			XWnd_SetTitle(GetWindowHandle(), title.c_str());
		}

		// �ñ�����ɫ
		void SetTitleColor(COLORREF color) { 
			XWnd_SetTitleColor(GetWindowHandle(), color);
		}

		// ȡ���ư�ť nFlag ����ֵ: @ref window_style_btn_min , @ref window_style_btn_max , @ref window_style_btn_close
		HELE GetButton(int nFlag) { 
			return XWnd_GetButton(GetWindowHandle(), nFlag);
		}

		// ����ͼ����
		HIMAGE GetIcon() { 
			return XWnd_GetIcon(GetWindowHandle());
		}

		// ȡ����
		std::wstring GetTitle() { 
			auto pTitle = XWnd_GetTitle(GetWindowHandle()); 
			if (!pTitle) {
				return L"";
			}
			return pTitle;
		}

		// ȡ������ɫ
		COLORREF GetTitleColor() { 
			return XWnd_GetTitleColor(GetWindowHandle());
		}

		// �رմ���
		void CloseWindow() { 
			XWnd_CloseWindow(GetWindowHandle()); 
		}

		// �������ڲ���
		void AdjustLayout() { 
			XWnd_AdjustLayout(GetWindowHandle());
		}

		// ����������չ
		void AdjustLayoutEx(adjustLayout_ nFlags = adjustLayout_self) {
			XWnd_AdjustLayoutEx(GetWindowHandle(), nFlags); 
		}

		// ���������,����Ԫ������
		void CreateCaret(HELE hEle, int x, int y, int width, int height) { 
			XWnd_CreateCaret(GetWindowHandle(), hEle, x, y, width, height); 
		}

		// 	���ò����λ��
		void SetCaretPos(int x, int y, int width, int height, bool bUpdate = false) { 
			XWnd_SetCaretPos(GetWindowHandle(), x, y, width, height, bUpdate);
		}
		
		// ���ò������ɫ
		void SetCaretColor(COLORREF color) { 
			XWnd_SetCaretColor(GetWindowHandle(), color);
		}


		// ��ʾ�����
		void ShowCaret(bool bShow) { 
			XWnd_ShowCaret(GetWindowHandle(), bShow);
		}

		// ���ز����Ԫ��
		HELE GetCaretHELE() { 
			return XWnd_GetCaretHELE(GetWindowHandle());
		}

		// ��ȡ�������Ϣ
		HELE GetCaretInfo(int* pX, int* pY, int* pWidth, int* pHeight) { 
			return XWnd_GetCaretInfo(GetWindowHandle(), pX, pY, pWidth, pHeight); 
		}

		// ���ٲ����
		void DestroyCaret() { 
			XWnd_DestroyCaret(GetWindowHandle()); 
		}

		// ��ȡ���ڿͻ�������;�������Ӱ����,��ô��������Ӱ����
		bool GetClientRect(RECT* pRect) { 
			return XWnd_GetClientRect(GetWindowHandle(), pRect); 
		}

		// ��ȡbody����
		void GetBodyRect(RECT* pRect) { 
			XWnd_GetBodyRect(GetWindowHandle(), pRect);
		}

		// ȡ��������
		void GetLayoutRect(RECT* pRect) { 
			XWnd_GetLayoutRect(GetWindowHandle(), pRect); 
		}

		// �ƶ�����
		void SetPosition(int x, int y) { 
			XWnd_SetPosition(GetWindowHandle(), x, y); 
		}

		// ȡ����
		void GetRect(RECT* pRect) { 
			XWnd_GetRect(GetWindowHandle(), pRect);
		}

		// ������
		void SetRect(RECT* pRect) { 
			XWnd_SetRect(GetWindowHandle(), pRect);
		}

		// �ö�
		void SetTop() { 
			XWnd_SetTop(GetWindowHandle()); 
		}

		//  ���
		void MaxWindow(bool bMaximize) { 
			XWnd_MaxWindow(GetWindowHandle(), bMaximize);
		}

		// ���ô��ڶ�ʱ��
		UINT SetTimer(UINT nIDEvent, UINT uElapse) { 
			return XWnd_SetTimer(GetWindowHandle(), nIDEvent, uElapse); 
		}

		// �رն�ʱ��
		bool KillTimer(UINT nIDEvent) { 
			return XWnd_KillTimer(GetWindowHandle(), nIDEvent);
		}

		// �����Ųʴ��ڶ�ʱ��
		bool SetXCTimer(UINT nIDEvent, UINT uElapse) { 
			return XWnd_SetXCTimer(GetWindowHandle(), nIDEvent, uElapse);
		}

		// �ر��Ųʴ��ڶ�ʱ��
		bool KillXCTimer(UINT nIDEvent) { 
			return XWnd_KillXCTimer(GetWindowHandle(), nIDEvent);
		}

		// ��ӱ������ݱ߿�
		void AddBkBorder(int nState, COLORREF color, int width) { 
			XWnd_AddBkBorder(GetWindowHandle(), nState, color, width);
		}

		// ��ӱ����������
		void AddBkFill(int nState, COLORREF color) { 
			XWnd_AddBkFill(GetWindowHandle(), nState, color);
		}

		// 	��ӱ�������ͼƬ
		void AddBkImage(int nState, HIMAGE hImage) { 
			XWnd_AddBkImage(GetWindowHandle(), nState, hImage);
		}
		
		// �ñ���
		int SetBkInfo(const std::wstring& text) { 
			return XWnd_SetBkInfo(GetWindowHandle(), text.c_str());
		}

		// ��ȡ������������
		int GetBkInfoCount() { 
			return XWnd_GetBkInfoCount(GetWindowHandle());
		}

		// ��ձ�������; �������û������,��ʹ��ϵͳĬ������,�Ա㱣֤������ȷ
		void ClearBkInfo() { 
			XWnd_ClearBkInfo(GetWindowHandle());
		}

		HBKM GetBkManager() { 
			return XWnd_GetBkManager(GetWindowHandle()); 
		}

		// ��ȡ����������,���ȴ���Դ�л�ȡ
		HBKM GetBkManagerEx() { 
			return XWnd_GetBkManagerEx(GetWindowHandle());
		}

		// �ñ���������
		void SetBkMagager(HBKM hBkInfoM) { 
			XWnd_SetBkMagager(GetWindowHandle(), hBkInfoM);
		}

		// ����͸������,ͬʱ����ͨ���ú����ر�͸������
		void SetTransparentType(window_transparent_ nType) { 
			XWnd_SetTransparentType(GetWindowHandle(), nType);
		}

		// ����͸�����ڵ�͸����,���ú�����ػ洰��API������  alpha ����͸����,��Χ0-255֮��,0͸��,255��͸��
		void SetTransparentAlpha(BYTE alpha) { 
			XWnd_SetTransparentAlpha(GetWindowHandle(), alpha); 
		}

		// ����͸�����ڵ�͸��ɫ
		void SetTransparentColor(COLORREF color) { 
			XWnd_SetTransparentColor(GetWindowHandle(), color);
		}

		// ���ô�����Ӱ��Ϣ
		void SetShadowInfo(int nSize, int nDepth, int nAngeleSize, bool bRightAngle, COLORREF color) { 
			XWnd_SetShadowInfo(GetWindowHandle(), nSize, nDepth, nAngeleSize, bRightAngle, color); 
		}

		// ��ȡ������Ӱ��Ϣ
		void GetShadowInfo(int* pnSize, int* pnDepth, int* pnAngeleSize, BOOL* pbRightAngle, COLORREF* pColor) { 
			XWnd_GetShadowInfo(GetWindowHandle(), pnSize, pnDepth, pnAngeleSize, pbRightAngle, pColor); 
		}

		// ��ȡ����͸������
		window_transparent_ GetTransparentType() { 
			return XWnd_GetTransparentType(GetWindowHandle()); 
		}

		bool PostMessage(UINT msg, WPARAM wParam, LPARAM lParam) {
			return XC_PostMessage(GetWindowHandle(), msg, wParam, lParam);
		}

		bool SendMessage(UINT msg, WPARAM wParam, LPARAM lParam) {
			return XC_SendMessage(GetWindowHandle(), msg, wParam, lParam);
		}

		void NotifyMsgSetBorderSize(int left, int top, int right, int bottom) {
			XNotifyMsg_SetBorderSize(GetWindowHandle(), left, top, right, bottom);
		}


		void NotifyMsgSetCaptionHeight(int height) {
			XNotifyMsg_SetCaptionHeight(GetWindowHandle(), height);
		}

		void NotifyMsgSetDuration(uint32_t duration) {
			XNotifyMsg_SetDuration(GetWindowHandle(), duration);
		}

		void NotifyMsgSetParentMargin(int left, int top, int right, int bottom) {
			XNotifyMsg_SetParentMargin(GetWindowHandle(), left, top, right, bottom);
		}

		void NotifyMsgSetSpace(int space) {
			XNotifyMsg_SetSpace(GetWindowHandle(), space);
		}

		void NotifyMsgSetWidth(int width) {
			XNotifyMsg_SetWidth(GetWindowHandle(), width);
		}

		void NotifyMsgWindowPopup(position_flag_ position, const std::wstring& title,
			const std::wstring& text, const XCImage& icon, notifyMsg_skin_ skin)
		{
			const wchar_t* pTitle = nullptr;
			if (!title.empty()) {
				pTitle = title.c_str();
			}
			XNotifyMsg_WindowPopup(GetWindowHandle(), position, pTitle, text.c_str(), icon.getImageHandle(), skin);
		}

		void NotifyMsgWindowPopupEx(position_flag_ position, const std::wstring& title,
			const std::wstring& text, const XCImage& icon, notifyMsg_skin_ skin,
			bool btnClose, bool autoClose, int width, int height)
		{
			const wchar_t* pTitle = nullptr;
			if (!title.empty()) {
				pTitle = title.c_str();
			}
			XNotifyMsg_WindowPopupEx(GetWindowHandle(), position, pTitle, 
				text.c_str(), icon.getImageHandle(), skin, btnClose, autoClose, width, height);
		}
		

		HWINDOW GetWindowHandle() const
		{
			return (HWINDOW)m_handle;
		}




	protected:
		void SetWindowHandle(HWINDOW winHandle)
		{
			this->SetHandle((HXCGUI)winHandle);
		}



	};

}