#pragma once
#include "pch.h"
#include "XCWidget.hpp"

namespace xcgui {

	class XCElement : virtual public XCWidget
	{
	public:
		XCElement()
			: XCWidget()
		{
		}


		XCElement(HXCGUI ele)
		{
			m_handle = ele;
		}


		HELE getEleHandle() const
		{
			return (HELE)m_handle;
		}


		// ��������Ԫ��
		XCElement(int x, int y, int cx, int cy, HXCGUI hParent = NULL) 
		:XCWidget()
		{
			m_handle = XEle_Create(x, y, cx, cy, hParent);
		}


		HELE Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL) {
			m_handle = XEle_Create(x, y, cx, cy, hParent); 
			return (HELE)m_handle;
		}


		// �����¼�.  
		int SendEvent(int nEvent, WPARAM wParam, LPARAM lParam) {
			return XEle_SendEvent((HELE)m_handle, nEvent, wParam, lParam);
		}


		// POST�¼�.  
		bool PostEvent(int nEvent, WPARAM wParam, LPARAM lParam) {
			return XEle_PostEvent((HELE)m_handle, nEvent, wParam, lParam);
		}


		// ��ȡԪ������.  
		void GetRect(RECT* pRect) {
			XEle_GetRect((HELE)m_handle, pRect);
		}


		// ��ȡԪ������,�߼�����,����������ͼƫ��.  
		void GetRectLogic(RECT* pRect) {
			XEle_GetRectLogic((HELE)m_handle, pRect);
		}


		// ��ȡԪ�ؿͻ�������. 
		void GetClientRect(RECT* pRect) {
			XEle_GetClientRect((HELE)m_handle, pRect);
		}


		// ���ÿ��  
		void SetWidth(int nWidth) {
			XEle_SetWidth((HELE)m_handle, nWidth);
		}


		// ���ø߶�   
		void SetHeight(int nHeight) {
			XEle_SetHeight((HELE)m_handle, nHeight);
		}


		// ��ȡԪ�ؿ��.  
		int GetWidth() {
			return XEle_GetWidth((HELE)m_handle);
		}


		// ��ȡԪ�ظ߶�.  
		int GetHeight() {
			return XEle_GetHeight((HELE)m_handle);
		}


		// ���ڿͻ�������ת����Ԫ�ؿͻ�������.  
		void RectWndClientToEleClient(RECT* pRect) {
			XEle_RectWndClientToEleClient((HELE)m_handle, pRect);
		}


		// ���ڿͻ�������ת����Ԫ�ؿͻ�������.  
		void PointWndClientToEleClient(POINT* pPt) {
			XEle_PointWndClientToEleClient((HELE)m_handle, pPt);
		}


		// Ԫ�ؿͻ�������ת�������ڿͻ�������.  
		//@���� pRect ����.
		//@����  �ͻ������굽���ڿͻ���()
		void RectClientToWndClient(RECT* pRect) {
			XEle_RectClientToWndClient((HELE)m_handle, pRect);
		}

		// Ԫ�ؿͻ�������ת�������ڿͻ�������.  
		//@���� pPt ����.
		//@����  �ͻ����㵽���ڿͻ���()
		void PointClientToWndClient(POINT* pPt) {
			XEle_PointClientToWndClient((HELE)m_handle, pPt);
		}		  

		bool PointClientToScreen(in_out_ POINT* pPt, position_flag_ flag = position_flag_leftBottom, 
			int xOffset = 0, int yOffset = 0) {
			
			RECT rect;
			this->GetRect(&rect);
			switch (flag)
			{
			case position_flag_leftBottom:
			{
				pPt->x = rect.left;
				pPt->y = rect.bottom;
				break;
			}
			case position_flag_leftTop:
			{
				pPt->x = rect.left;
				pPt->y = rect.top;
				break;
			}		
			case position_flag_rightTop:
			{
				pPt->x = rect.right;
				pPt->y = rect.top;
				break;
			}
				
			case position_flag_rightBottom:
			{
				pPt->x = rect.right;
				pPt->y = rect.bottom;
				break;
			}
				
			case position_flag_center:
			{
				pPt->x = rect.left + (rect.right - rect.left) / 2;
				pPt->y = rect.top + (rect.bottom - rect.top) / 2;
				break;
			}
			default:
				break;
			}
			pPt->x += xOffset;
			pPt->y += yOffset;

			return ::ClientToScreen((HWND)GetHWND(), pPt);
		}

		// Ԫ�ػ��ڴ��ڿͻ�������.  
		//@���� pRect ����.
		//@����  ���ڴ��ڿͻ�������()
		void GetWndClientRect(RECT* pRect) {
			XEle_GetWndClientRect((HELE)m_handle, pRect);
		}

		// ��ȡԪ�������.  
		//@���� ���ع����.
		//@����  ȡ���()
		HCURSOR GetCursor() {
			return XEle_GetCursor((HELE)m_handle);
		}

		// ����Ԫ�������.  
		//@���� hCursor �����.
		//@����  �ù��()
		void SetCursor(HCURSOR hCursor) {
			XEle_SetCursor((HELE)m_handle, hCursor);
		}

		// ����Ӷ���. 
		//@���� hChild Ҫ��ӵ���Ԫ�ؾ������״������.
		//@���� ����ɹ�����TRUE,�����෴.
		//@����  ����Ӷ���()
		bool AddChild(HXCGUI hChild) {
			return XEle_AddChild((HELE)m_handle, hChild);
		}

		// �����Ӷ���ָ��λ��.  
		//@���� hChild Ҫ�����Ԫ�ؾ������״������.
		//@���� index ����λ������.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  �����Ӷ���()
		bool InsertChild(HXCGUI hChild, int index) {
			return XEle_InsertChild((HELE)m_handle, hChild, index);
		}

		// ����Ԫ������.  
		//@���� pRect ����.
		//@���� bRedraw �Ƿ��ػ�.
		//@���� nFlags �������ֱ�ʶλ, @ref adjustLayout_
		//@���� nAdjustNo ����������ˮ��
		//@���� �������0����û�иı�,�����С�ı䷵��2(����XE_SIZE), ���򷵻�1(���ı�left,top,û�иı��С).
		//@����  ������()
		int SetRect(const XCRect& rect, bool bRedraw = false, int nFlags = adjustLayout_all, UINT nAdjustNo = 0) {
			return XEle_SetRect((HELE)m_handle, (RECT*)&rect, bRedraw, nFlags, nAdjustNo);
		}

		// ����Ԫ������.  
		//@���� x X����.
		//@���� y Y����.
		//@���� cx ���.
		//@���� cy �߶�.
		//@���� bRedraw �Ƿ��ػ�.
		//@���� nFlags �������ֱ�ʶλ, @ref adjustLayout_
		//@���� nAdjustNo ����������ˮ��
		//@���� �������δ�ı䷵��0,�����С�ı䷵��2(����XE_SIZE), ���򷵻�1.
		//@����  ��������չ()
		int SetRectEx(int x, int y, int cx, int cy, bool bRedraw = false, int nFlags = adjustLayout_all, UINT nAdjustNo = 0) {
			return XEle_SetRectEx((HELE)m_handle, x, y, cx, cy, bRedraw, nFlags, nAdjustNo);
		}

		// ����Ԫ������,�߼�����,����������ͼƫ��.  
		//@���� pRect ����.
		//@���� bRedraw �Ƿ��ػ�.
		//@���� nFlags ������������ XE_SIZE ,XE_ADJUSTLAYOUT �¼��ص�.@ref adjustLayout_
		//@���� nAdjustNo ����������ˮ��
		//@���� �������δ�ı䷵��0,�����С�ı䷵��2(����XE_SIZE), ���򷵻�1.
		//@����  ���߼�����()
		int SetRectLogic(const XCRect& rect, bool bRedraw = false, int nFlags = adjustLayout_all, UINT nAdjustNo = 0) {
			return XEle_SetRectLogic((HELE)m_handle, (RECT*)&rect, bRedraw, nFlags, nAdjustNo);
		}

		// �ƶ�Ԫ������
		//@���� x X����.
		//@���� y Y����.
		//@���� bRedraw �Ƿ��ػ�.
		//@���� nFlags �������ֱ�ʶλ, @ref adjustLayout_
		//@���� nAdjustNo ����������ˮ��
		//@���� �������δ�ı䷵��0,�����С�ı䷵��2(����XE_SIZE), ���򷵻�1.
		//@����  ��λ��()
		int SetPosition(int x, int y, bool bRedraw = false, int nFlags = adjustLayout_all, UINT nAdjustNo = 0) {
			return XEle_SetPosition((HELE)m_handle, x, y, bRedraw, nFlags, nAdjustNo);
		}

		// �ƶ�Ԫ������;  �߼�����,����������ͼƫ��
		//@���� x X����.
		//@���� y Y����.
		//@���� bRedraw �Ƿ��ػ�.
		//@���� nFlags �������ֱ�ʶλ, @ref adjustLayout_
		//@���� nAdjustNo ����������ˮ��
		//@���� �������δ�ı䷵��0,�����С�ı䷵��2(����XE_SIZE), ���򷵻�1.
		//@����  ��λ���߼�()
		int SetPositionLogic(int x, int y, bool bRedraw = false, int nFlags = adjustLayout_all, UINT nAdjustNo = 0) {
			return XEle_SetPositionLogic((HELE)m_handle, x, y, bRedraw, nFlags, nAdjustNo);
		}

		//@���� pOutX ����X����
		//@���� pOutY ����Y����
		//@����  ȡλ��()
		void GetPosition(int* pOutX, int* pOutY) {
			XEle_GetPosition((HELE)m_handle, pOutX, pOutY);
		}

		//@���� nWidth ���
		//@���� nHeight �߶�
		//@���� bRedraw �Ƿ��ػ�
		//@���� nFlags �������ֱ�ʶλ, @ref adjustLayout_
		//@���� nAdjustNo ����������ˮ��
		//@����  �ô�С()
		int SetSize(int nWidth, int nHeight, bool bRedraw = false, int nFlags = adjustLayout_all, UINT nAdjustNo = 0) {
			return XEle_SetSize((HELE)m_handle, nWidth, nHeight, bRedraw, nFlags, nAdjustNo);
		}

		//@���� pOutWidth ���ؿ��
		//@���� pOutHeight ���ظ߶�
		//@����  ȡ��С()
		void GetSize(int* pOutWidth, int* pOutHeight) {
			XEle_GetSize((HELE)m_handle, pOutWidth, pOutHeight);
		}

		// Ԫ���Ƿ���ƽ���.  
		//@���� ������ƽ��㷵��TRUE���򷵻�FALSE.
		//@����  �Ƿ���ƽ���()
		bool IsDrawFocus() {
			return XEle_IsDrawFocus((HELE)m_handle);
		}

		// Ԫ���Ƿ�Ϊ����״̬.  
		//@���� �������״̬����TRUE���򷵻�FALSE.
		//@����  �Ƿ�����()
		bool IsEnable() {
			return XEle_IsEnable((HELE)m_handle);
		}

		// Ԫ���Ƿ����ý���.  
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  �Ƿ����ý���()
		bool IsEnableFocus() {
			return XEle_IsEnableFocus((HELE)m_handle);
		}

		// Ԫ���Ƿ�������괩͸.  
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  �Ƿ���괩͸()
		bool IsMouseThrough() {
			return XEle_IsMouseThrough((HELE)m_handle);
		}

		// ������������Ԫ��,������Ԫ�ص���Ԫ��.  
		//@���� pPt �����.
		//@���� �ɹ�����Ԫ�ؾ��,���򷵻�NULL.
		//@����  ���Ե��Ԫ��()
		HELE HitChildEle(POINT* pPt) {
			return XEle_HitChildEle((HELE)m_handle, pPt);
		}

		// �Ƿ񱳾�͸��. 
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  �Ƿ񱳾�͸��()
		bool IsBkTransparent() {
			return XEle_IsBkTransparent((HELE)m_handle);
		}

		// �Ƿ���XE_PAINT_END���¼�.  
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  �Ƿ������¼�_XE_PAINT_END()
		bool IsEnableEvent_XE_PAINT_END() {
			return XEle_IsEnableEvent_XE_PAINT_END((HELE)m_handle);
		}

		// �Ƿ����Tab������; ����: XRichEdit, XEdit  
		//@���� �Ƿ���TRUE���򷵻�FALSE
		//@����  �Ƿ����TAB()
		bool IsKeyTab() {
			return XEle_IsKeyTab((HELE)m_handle);
		}

		// �Ƿ����ͨ�������л�����(�����,TAB��).  
		//@���� �Ƿ���TRUE���򷵻�FALSE.
		//@����  �Ƿ�����л�����()
		bool IsSwitchFocus() {
			return XEle_IsSwitchFocus((HELE)m_handle);
		}

		// �ж��Ƿ������������¼�,���������ô�¼��ᷢ�͸����ĸ�Ԫ��.  
		//@���� �Ƿ���TRUE���򷵻�FALSE.
		//@����  �Ƿ�����_XE_MOUSEWHEEL()
		bool IsEnable_XE_MOUSEWHEEL() {
			return XEle_IsEnable_XE_MOUSEWHEEL((HELE)m_handle);
		}

		// �ж�hChildEle�Ƿ�ΪhEle����Ԫ��,   
		//@���� hChildEle ��Ԫ�ؾ��
		//@���� �Ƿ���TRUE���򷵻�FALSE.
		//@����  �Ƿ�Ϊ��Ԫ��()
		bool IsChildEle(HELE hChildEle) {
			return XEle_IsChildEle((HELE)m_handle, hChildEle);
		}

		// �ж��Ƿ����û���,  
		//@���� �Ƿ���TRUE���򷵻�FALSE.
		//@����  �Ƿ����û���()
		bool IsEnableCanvas() {
			return XEle_IsEnableCanvas((HELE)m_handle);
		}

		// �ж��Ƿ�ӵ�н���.  
		//@���� ���ӵ�н��㷵��TRUE,���򷵻�FALSE.
		//@����  �Ƿ񽹵�()
		bool IsFocus() {
			return XEle_IsFocus((HELE)m_handle);
		}

		// �жϸ�Ԫ�ػ��Ԫ�ص���Ԫ���Ƿ�ӵ�н���  
		//@���� ���ӵ�н��㷵��TRUE,���򷵻�FALSE.
		//@����  �Ƿ񽹵���չ()
		bool IsFocusEx() {
			return XEle_IsFocusEx((HELE)m_handle);
		}

		// ���û����Ԫ��.  
		//@���� bEnable ���û����.
		//@����  ����()
		void Enable(bool bEnable) {
			XEle_Enable((HELE)m_handle, bEnable);
		}

		// ���ý���.  
		//@���� bEnable �Ƿ�����.
		//@����  ���ý���()
		void EnableFocus(bool bEnable) {
			XEle_EnableFocus((HELE)m_handle, bEnable);
		}

		// ���û��ƽ���.  
		//@���� bEnable �Ƿ�����.
		//@����  ���û��ƽ���()
		void EnableDrawFocus(bool bEnable) {
			XEle_EnableDrawFocus((HELE)m_handle, bEnable);
		}

		// ���û���û���Ĭ�ϱ߿�.  
		//@���� bEnable �Ƿ�����.
		//@����  ���û��Ʊ߿�()
		void EnableDrawBorder(bool bEnable) {
			XEle_EnableDrawBorder((HELE)m_handle, bEnable);
		}

		// ���û���ñ�������;���������ô�������ڸ��Ļ���֮��,Ҳ����˵��û���Լ��Ļ���.  
		//@���� bEnable �Ƿ�����.
		//@����  ���û���()
		void EnableCanvas(bool bEnable) {
			XEle_EnableCanvas((HELE)m_handle, bEnable);
		}

		// ����XE_PAINT_END�¼�.  
		//@���� bEnable �Ƿ�����.
		//@����  �����¼�_XE_PAINT_END()
		void EnableEvent_XE_PAINT_END(bool bEnable) {
			XEle_EnableEvent_XE_PAINT_END((HELE)m_handle, bEnable);
		}

		// ���ñ���͸��.  
		//@���� bEnable �Ƿ�����.
		//@����  ���ñ���͸��()
		void EnableBkTransparent(bool bEnable) {
			XEle_EnableBkTransparent((HELE)m_handle, bEnable);
		}

		// ������괩͸, �������,��ô��Ԫ�ز��ܽ��յ�����¼�,����������Ԫ�ز���Ӱ��,��Ȼ���Խ�������¼�.  
		//@���� bEnable �Ƿ�����.
		//@����  ������괩͸()
		void EnableMouseThrough(bool bEnable) {
			XEle_EnableMouseThrough((HELE)m_handle, bEnable);
		}

		// ���ý���Tab����.  
		//@���� bEnable �Ƿ�����.
		//@����  ���ý���TAB()
		void EnableKeyTab(bool bEnable) {
			XEle_EnableKeyTab((HELE)m_handle, bEnable);
		}

		// ���ý���ͨ�������л�����.  
		//@���� bEnable �Ƿ�����.
		//@����  �����л�����()
		void EnableSwitchFocus(bool bEnable) {
			XEle_EnableSwitchFocus((HELE)m_handle, bEnable);
		}

		// ���ý����������¼�,���������ô�¼��ᴫ�ݸ���Ԫ��.  
		//@���� bEnable �Ƿ�����.
		//@����  �����¼�_XE_MOUSEWHEEL()
		void EnableEvent_XE_MOUSEWHEEL(bool bEnable) {
			XEle_EnableEvent_XE_MOUSEWHEEL((HELE)m_handle, bEnable);
		}

		// �Ƴ�Ԫ��,��������.  
		//@����  �Ƴ�()
		void Remove() {
			XEle_Remove((HELE)m_handle);
		}

		// ����Ԫ��Z��.  
		//@���� index λ������.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ��Z��()
		bool SetZOrder(int index) {
			return XEle_SetZOrder((HELE)m_handle, index);
		}

		// ����Ԫ��Z��.  
		//@���� hDestEle Ŀ��Ԫ��.
		//@���� nType ����.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ��Z����չ()
		bool SetZOrderEx(HELE hDestEle, zorder_ nType) {
			return XEle_SetZOrderEx((HELE)m_handle, hDestEle, nType);
		}

		// ��ȡԪ��Z������, λ������.  
		//@���� �ɹ���������ֵ,���򷵻� XC_ID_ERROR.
		//@����  ȡZ��()
		int GetZOrder() {
			return XEle_GetZOrder((HELE)m_handle);
		}

		// ����Ԫ���ö�.  
		//@���� bTopmost �Ƿ��ö���ʾ
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  �����ö�()
		bool EnableTopmost(bool bTopmost) {
			return XEle_EnableTopmost((HELE)m_handle, bTopmost);
		}

		// �ػ�Ԫ��.  
		//@���� bImmediate �Ƿ������ػ�,Ĭ��Ϊ��.
		//@����  �ػ�()
		void Redraw(bool bImmediate = false) {
			XEle_Redraw((HELE)m_handle, bImmediate);
		}

		// �ػ�Ԫ��ָ������.  
		//@���� pRect �����Ԫ�ؿͻ�������.
		//@���� bImmediate �Ƿ������ػ�,Ĭ��Ϊ��.
		//@����  �ػ�ָ������()
		void RedrawRect(RECT* pRect, bool bImmediate = false) {
			XEle_RedrawRect((HELE)m_handle, pRect, bImmediate);
		}

		// ��ȡ�Ӷ���(UIԪ�غ���״����)����,ֻ��⵱ǰ���Ӷ���.  
		//@���� ��Ԫ������.
		//@����  ȡ�Ӷ�������()
		int GetChildCount() {
			return XEle_GetChildCount((HELE)m_handle);
		}

		// ��ȡ�Ӷ���ͨ������,ֻ��⵱ǰ���Ӷ���.  
		//@���� index ����.
		//@���� ������.
		//@����  ȡ�Ӷ��������()
		HXCGUI GetChildByIndex(int index) {
			return XEle_GetChildByIndex((HELE)m_handle, index);
		}

		// ��ȡ�Ӷ���ͨ��ID,ֻ��⵱ǰ���Ӷ���.  
		//@���� nID Ԫ��ID.
		//@���� ������.
		//@����  ȡ�Ӷ����ID()
		HXCGUI GetChildByID(int nID) {
			return XEle_GetChildByID((HELE)m_handle, nID);
		}

		// ���ñ߿��С.  
		//@���� left ��ߴ�С.
		//@���� top �ϱߴ�С.
		//@���� right �ұߴ�С.
		//@���� bottom �±ߴ�С.
		//@����  �ñ߿��С()
		void SetBorderSize(int left, int top, int right, int bottom) {
			XEle_SetBorderSize((HELE)m_handle, left, top, right, bottom);
		}

		// ��ȡ�߿��С.  
		//@���� pBorder ��С.
		//@����  ȡ�߿��С()
		void GetBorderSize(borderSize_* pBorder) {
			XEle_GetBorderSize((HELE)m_handle, pBorder);
		}

		// ���ñ�����С.  
		//@���� left ��ߴ�С.
		//@���� top �ϱߴ�С.
		//@���� right �ұߴ�С.
		//@���� bottom �±ߴ�С.
		//@����  ��������С()
		void SetPadding(int left, int top, int right, int bottom) {
			XEle_SetPadding((HELE)m_handle, left, top, right, bottom);
		}

		// ��ȡ������С.  
		//@���� pPadding ��С.
		//@����  ȡ������С()
		void GetPadding(paddingSize_* pPadding) {
			XEle_GetPadding((HELE)m_handle, pPadding);
		}

		// �����϶��߿�.  
		//@���� nFlags �߿�λ�����. element_position_
		//@����  ���϶��߿�()
		void SetDragBorder(int nFlags) {
			XEle_SetDragBorder((HELE)m_handle, nFlags);
		}

		// �����϶��߿��Ԫ��,���϶��߿�ʱ, �Զ�������Ԫ�صĴ�С.  
		//@���� nFlags �߿�λ�ñ�ʶ,�������.  element_position_
		//@���� hBindEle ��Ԫ��.
		//@���� nSpace Ԫ�ؼ����С
		//@����  ���϶��߿��Ԫ��()
		void SetDragBorderBindEle(int nFlags, HELE hBindEle, int nSpace) {
			XEle_SetDragBorderBindEle((HELE)m_handle, nFlags, hBindEle, nSpace);
		}

		// ����Ԫ����С��С  
		//@���� nWidth ��С���
		//@���� nHeight ��С�߶�.
		//@����  ����С��С()
		void SetMinSize(int nWidth, int nHeight) {
			XEle_SetMinSize((HELE)m_handle, nWidth, nHeight);
		}

		// ����Ԫ������С.  
		//@���� nWidth �����.
		//@���� nHeight ���߶�.
		//@����  ������С()
		void SetMaxSize(int nWidth, int nHeight) {
			XEle_SetMaxSize((HELE)m_handle, nWidth, nHeight);
		}

		// ��������Ԫ���ڹ�����ͼ�и������,�������TRUE�����������.  
		//@���� bHorizon �Ƿ�����ˮƽ����.
		//@���� bVertical �Ƿ�������ֱ����.
		//@����  ����������()
		void SetLockScroll(bool bHorizon, bool bVertical) {
			XEle_SetLockScroll((HELE)m_handle, bHorizon, bVertical);
		}

		// �����ı���ɫ.  
		//@���� color ��ɫֵ, ��ʹ�ú�: RGBA()
		//@����  ���ı���ɫ()
		void SetTextColor(COLORREF color) {
			XEle_SetTextColor((HELE)m_handle, color);
		}

		// ��ȡ�ı���ɫ.  
		//@���� �ı���ɫֵ.
		//@����  ȡ�ı���ɫ()
		COLORREF GetTextColor() {
			return XEle_GetTextColor((HELE)m_handle);
		}

		// ��ȡ�ı���ɫ,���ȴ���Դ�л�ȡ.  
		//@���� �ı���ɫֵ.
		//@����  ȡ�ı���ɫ��չ()
		COLORREF GetTextColorEx() {
			return XEle_GetTextColorEx((HELE)m_handle);
		}

		// ���ý���߿���ɫ.  
		//@���� color ��ɫֵ, ��ʹ�ú�: RGBA()
		//@����  �ý���߿���ɫ()
		void SetFocusBorderColor(COLORREF color) {
			XEle_SetFocusBorderColor((HELE)m_handle, color);
		}

		// ��ȡ����߿���ɫ.  
		//@���� ������ɫֵ
		//@����  ȡ����߿���ɫ()
		COLORREF GetFocusBorderColor() {
			return XEle_GetFocusBorderColor((HELE)m_handle);
		}

		// ����Ԫ������.  
		//@���� hFontx �Ų�����.
		//@����  ������()
		void SetFont(HFONTX hFontx) {
			XEle_SetFont((HELE)m_handle, hFontx);
		}

		// ��ȡԪ������.  
		//@���� �����Ų�������.
		//@����  ȡ����()
		HFONTX GetFont() {
			return XEle_GetFont((HELE)m_handle);
		}

		// ��ȡԪ������,���ȴ���Դ�л�ȡ.  
		//@���� �����Ų�������.
		//@����  ȡ������չ()
		HFONTX GetFontEx() {
			return XEle_GetFontEx((HELE)m_handle);
		}

		// ����Ԫ��͸����.  
		//@���� alpha ͸����.
		//@����  ��͸����()
		void SetAlpha(BYTE alpha) {
			XEle_SetAlpha((HELE)m_handle, alpha);
		}

		//@���� ����͸����
		//@����  ȡ͸����()
		BYTE GetAlpha() {
			return XEle_GetAlpha((HELE)m_handle);
		}

		// ����Ԫ��.  
		//@����  ����()
		void Destroy() {
			XEle_Destroy((HELE)m_handle);
		}

		// ��ӱ������ݱ߿�.  
		//@���� nState ���״̬
		//@���� color ��ɫ.
		//@���� width �߿�.
		//@����  ��ӱ����߿�()
		void AddBkBorder(int nState, COLORREF color, int width) {
			XEle_AddBkBorder((HELE)m_handle, nState, color, width);
		}

		// ��ӱ����������.  
		//@���� nState ���״̬
		//@���� color ��ɫ.
		//@����  ��ӱ������()
		void AddBkFill(int nState, COLORREF color) {
			XEle_AddBkFill((HELE)m_handle, nState, color);
		}

		// ��ӱ�������ͼƬ.  
		//@���� nState ���״̬
		//@���� hImage ͼƬ���.
		//@����  ��ӱ���ͼƬ()
		void AddBkImage(int nState, HIMAGE hImage) {
			XEle_AddBkImage((HELE)m_handle, nState, hImage);
		}

		// ���ñ�������
		//@���� pText ���������ַ���
		//@���� �������õı�����������
		//@����  �ñ���()
		int SetBkInfo(const std::wstring& text) {
			return XEle_SetBkInfo((HELE)m_handle, text.c_str());
		}

		// ��ȡ������������.  
		//@���� ���ر�����������.
		//@����  ȡ������������()
		int GetBkInfoCount() {
			return XEle_GetBkInfoCount((HELE)m_handle);
		}

		// ��ձ�������; �������û������,��ʹ��ϵͳĬ������,�Ա㱣֤������ȷ.  
		//@����  ��ձ�������()
		void ClearBkInfo() {
			XEle_ClearBkInfo((HELE)m_handle);
		}

		// ��ȡԪ�ر���������.  
		//@���� ����������.
		//@����  ȡ����������()
		HBKM GetBkManager() {
			return XEle_GetBkManager((HELE)m_handle);
		}

		// ��ȡԪ�ر���������,���ȴ���Դ�л�ȡ.  
		//@���� ����������.
		//@����  ȡ������������չ()
		HBKM GetBkManagerEx() {
			return XEle_GetBkManagerEx((HELE)m_handle);
		}

		//@���� hBkInfoM ����������
		//@����  �ñ���������()
		void SetBkManager(HBKM hBkInfoM) {
			XEle_SetBkManager((HELE)m_handle, hBkInfoM);
		}

		// ��ȡ���״̬.  
		//@���� �������״̬.
		//@����  ȡ״̬()
		int GetStateFlags() {
			return XEle_GetStateFlags((HELE)m_handle);
		}

		// ����Ԫ�ؽ���.  
		//@���� hDraw ͼ�λ��ƾ��.
		//@���� pRect ��������.
		//@���� ���Ƴɹ�����TRUE,�������Ҫ���ƽ��㷵��FALSE.
		//@����  ���ƽ���()
		bool DrawFocus(HDRAW hDraw, RECT* pRect) {
			return XEle_DrawFocus((HELE)m_handle, hDraw, pRect);
		}

		// ���Ի��¼�������,�û��ֶ����û���Ԫ��,�Ա���ƻ���˳��.  
		//@���� hDraw ͼ�λ��ƾ��.
		//@����  ����()
		void DrawEle(HDRAW hDraw) {
			XEle_DrawEle((HELE)m_handle, hDraw);
		}

		// �����û�����.  
		//@���� nData �û�����.
		//@����  ���û�����()
		void SetUserData(vint nData) {
			XEle_SetUserData((HELE)m_handle, nData);
		}

		// ��ȡ�û�����.  
		//@���� �û�����.
		//@����  ȡ�û�����()
		vint GetUserData() {
			return XEle_GetUserData((HELE)m_handle);
		}

		// ��ȡ���ݴ�С.  
		//@���� bHorizon ˮƽ��ֱ,  �������Խ�������
		//@���� cx ���
		//@���� cy �߶�
		//@���� pSize ���ش�С.
		//@����  ȡ���ݴ�С()
		void GetContentSize(bool bHorizon, int cx, int cy, SIZE* pSize) {
			XEle_GetContentSize((HELE)m_handle, bHorizon, cx, cy, pSize);
		}

		// ������겶��.  
		//@���� b TRUE����,FALSEȡ��.
		//@����  ����겶��()
		void SetCapture(bool b) {
			XEle_SetCapture((HELE)m_handle, b);
		}

		// ���û�ر�Ԫ��͸��ͨ��,�������,��ǿ������Ԫ�ر�����͸��,Ĭ��Ϊ����,�˹�����Ϊ�˼���GDI��֧��͸��ͨ������.  
		//@���� bEnable ���û�ر�.
		//@����  ����͸��ͨ��()
		void EnableTransparentChannel(bool bEnable) {
			XEle_EnableTransparentChannel((HELE)m_handle, bEnable);
		}

		// ����Ԫ�ض�ʱ��.  
		//@���� nIDEvent �¼�ID.
		//@���� uElapse ��ʱ����.
		//@���� ����ɹ�����TRUE,���򷵻�FALSE.
		//@����  ���Ųʶ�ʱ��()
		bool SetXCTimer(UINT nIDEvent, UINT uElapse) {
			return XEle_SetXCTimer((HELE)m_handle, nIDEvent, uElapse);
		}

		// �ر�Ԫ�ض�ʱ��.  
		//@���� nIDEvent �¼�ID.
		//@���� ����ɹ�����TRUE,���򷵻�FALSE.
		//@����  �ر��Ųʶ�ʱ��()
		bool KillXCTimer(UINT nIDEvent) {
			return XEle_KillXCTimer((HELE)m_handle, nIDEvent);
		}

		// ���ù�����ʾ����.  
		//@���� pText ������ʾ����.
		//@����  �ù�����ʾ()
		void SetToolTip(const std::wstring& text) {
			XEle_SetToolTip((HELE)m_handle, text.c_str());
		}

		// ���ù�����ʾ����.  
		//@���� pText ������ʾ����.
		//@���� nTextAlign �ı����뷽ʽ @ref textFormatFlag_
		//@����  �ù�����ʾ��չ()
		void SetToolTipEx(const std::wstring& text, int nTextAlign) {
			XEle_SetToolTipEx((HELE)m_handle, text.c_str(), nTextAlign);
		}

		// ��ȡ������ʾ����.  
		//@���� �����ı�����
		//@����  ȡ������ʾ()
		std::wstring GetToolTip() {
			auto pTip = XEle_GetToolTip((HELE)m_handle);
			if (!pTip)
				return L"";
			return pTip;
		}

		// ����������ʾ.  
		//@���� x X����.
		//@���� y Y����.
		//@����  ����������ʾ()
		void PopupToolTip(int x, int y) {
			XEle_PopupToolTip((HELE)m_handle, x, y);
		}

		// ��������.  
		//@���� nAdjustNo ����������ˮ��
		//@����  ��������()
		void AdjustLayout(UINT nAdjustNo = 0) {
			XEle_AdjustLayout((HELE)m_handle, nAdjustNo);
		}

		// ��������.    
		//@���� nFlags ������ʶ,  adjustLayout_
		//@���� nAdjustNo ����������ˮ��
		//@����  ����������չ()
		void AdjustLayoutEx(int nFlags = adjustLayout_self, UINT nAdjustNo = 0) {
			XEle_AdjustLayoutEx((HELE)m_handle, nFlags, nAdjustNo);
		}


	}
;

}

