#pragma once
#include "pch.h"
#include "xcgui/element/XCScrollView.hpp"

namespace xcgui {


	class XCListBox : public XCScrollView
	{

	public:
		XCListBox(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCListBox() = default;

		XCListBox(int x, int y, int width, int height, HXCGUI parent = NULL) {

			m_handle = XListBox_Create(x, y, width, height, parent);
		}

		//@���� bEnable �Ƿ�����
		//@����  ���ù̶��и�()
		void EnableFixedRowHeight(bool bEnable) {
			XListBox_EnableFixedRowHeight(getEleHandle(), bEnable);
		}

		//@���� bEnable �Ƿ�����
		//@����  ����ģ�帴��()
		void EnablemTemplateReuse(bool bEnable) {
			XListBox_EnablemTemplateReuse(getEleHandle(), bEnable);
		}

		//@���� bEnable �Ƿ�����
		//@����  �������()
		void EnableVirtualTable(bool bEnable) {
			XListBox_EnableVirtualTable(getEleHandle(), bEnable);
		}

		//@���� nRowCount ����
		//@����  ���������()
		void SetVirtualRowCount(int nRowCount) {
			XListBox_SetVirtualRowCount(getEleHandle(), nRowCount);
		}

		//@��ע �����Ƿ����ָ��״̬����ı���.  
		//@���� nFlags ��־λ @ref list_drawItemBk_flag_.
		//@����  �û��������־()
		void SetDrawItemBkFlags(int nFlags) {
			XListBox_SetDrawItemBkFlags(getEleHandle(), nFlags);
		}

		//@���� color ��ɫֵ
		//@����  �÷ָ�����ɫ()
		void SetSplitLineColor(COLORREF color) {
			XListBox_SetSplitLineColor(getEleHandle(), color);
		}

		//@��ע �������û�����.  
		//@���� iItem ������.
		//@���� nUserData �û�����.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ��������()
		bool SetItemData(int iItem, vint nUserData) {
			return XListBox_SetItemData(getEleHandle(), iItem, nUserData);
		}

		//@��ע ��ȡ���û�����.  
		//@���� iItem ������.
		//@���� �û�����.
		//@����  ȡ������()
		vint GetItemData(int iItem) {
			return XListBox_GetItemData(getEleHandle(), iItem);
		}

		//@��ע ��������Ϣ.  
		//@���� iItem ������.
		//@���� pItem ����Ϣ.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ������Ϣ()
		bool SetItemInfo(int iItem, listBox_item_info_* pItem) {
			return XListBox_SetItemInfo(getEleHandle(), iItem, pItem);
		}

		//@��ע ��ȡ����Ϣ.  
		//@���� iItem ������.
		//@���� pItem ����Ϣ.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ȡ�����Ϣ()
		bool GetItemInfo(int iItem, listBox_item_info_* pItem) {
			return XListBox_GetItemInfo(getEleHandle(), iItem, pItem);
		}

		//@��ע ����ѡ��ѡ.  
		//@���� iItem ������.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ��ѡ����()
		bool SetSelectItem(int iItem) {
			return XListBox_SetSelectItem(getEleHandle(), iItem);
		}

		//@��ע ��ȡѡ����.  
		//@���� ������.
		//@����  ȡѡ����()
		int GetSelectItem() {
			return XListBox_GetSelectItem(getEleHandle());
		}

		//@���� iItem ������
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ���ѡ����()
		bool AddSelectItem(int iItem) {
			return XListBox_AddSelectItem(getEleHandle(), iItem);
		}

		//@��ע ȡ��ѡ��ָ����.  
		//@���� iItem ������.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ȡ��ѡ����()
		bool CancelSelectItem(int iItem) {
			return XListBox_CancelSelectItem(getEleHandle(), iItem);
		}

		//@��ע ȡ������ѡ�е���.  
		//@���� ���֮ǰ��ѡ��״̬�����TRUE,��ʱ���Ը���UI,���򷵻�FALSE.
		//@����  ȡ��ѡ��ȫ��()
		bool CancelSelectAll() {
			return XListBox_CancelSelectAll(getEleHandle());
		}

		//@��ע ��ȡ����ѡ����.  
		//@���� pArray ���黺����.
		//@���� nArraySize �����С.
		//@���� ���ؽ�������.
		//@����  ȡȫ��ѡ��()
		int GetSelectAll(int* pArray, int nArraySize) {
			return XListBox_GetSelectAll(getEleHandle(), pArray, nArraySize);
		}

		//@��ע ��ȡѡ��������.  
		//@���� ��������.
		//@����  ȡѡ��������()
		int GetSelectCount() {
			return XListBox_GetSelectCount(getEleHandle());
		}

		//@��ע ��ȡ���ͣ����.  
		//@���� �������������.
		//@����  ȡ���ͣ����()
		int GetItemMouseStay() {
			return XListBox_GetItemMouseStay(getEleHandle());
		}

		//@��ע ѡ��������.  
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ѡ��ȫ����()
		bool SelectAll() {
			return XListBox_SelectAll(getEleHandle());
		}

		//@��ע ������ͼ��ָ����ɼ�  
		//@���� iItem ������.
		//@����  ��ʾָ����()
		void VisibleItem(int iItem) {
			XListBox_VisibleItem(getEleHandle(), iItem);
		}

		//@��ע ��ȡ��ǰ�ɼ��з�Χ.  
		//@���� piStart ��ʼ������
		//@���� piEnd ����������
		//@����  ȡ�����з�Χ()
		void GetVisibleRowRange(int* piStart, int* piEnd) {
			XListBox_GetVisibleRowRange(getEleHandle(), piStart, piEnd);
		}

		//@��ע ������Ĭ�ϸ߶�.  
		//@���� nHeight ��߶�.
		//@���� nSelHeight ѡ����߶�.
		//@����  ����Ĭ�ϸ߶�()
		void SetItemHeightDefault(int nHeight, int nSelHeight) {
			XListBox_SetItemHeightDefault(getEleHandle(), nHeight, nSelHeight);
		}

		//@��ע ��ȡ��Ĭ�ϸ߶�.  
		//@���� pHeight �߶�.
		//@���� pSelHeight ѡ��ʱ�߶�.
		//@����  ȡ��Ĭ�ϸ߶�()
		void GetItemHeightDefault(int* pHeight, int* pSelHeight) {
			XListBox_GetItemHeightDefault(getEleHandle(), pHeight, pSelHeight);
		}

		//@��ע ��ȡ��ǰ��������ģ��ʵ��,�����б�����һ����(��).  
		//@���� hXCGUI ������, UIԪ�ؾ������״������.
		//@���� �ɹ�����������, ���򷵻�@ref XC_ID_ERROR.
		//@����  ȡ����������()
		int GetItemIndexFromHXCGUI(HXCGUI hXCGUI) {
			return XListBox_GetItemIndexFromHXCGUI(getEleHandle(), hXCGUI);
		}

		//@��ע �����м��.  
		//@���� nSpace ����С.
		//@����  ���м��()
		void SetRowSpace(int nSpace) {
			XListBox_SetRowSpace(getEleHandle(), nSpace);
		}

		//@��ע ��ȡ�м���С.  
		//@���� �����м���С.
		//@����  ȡ�м��()
		int GetRowSpace() {
			return XListBox_GetRowSpace(getEleHandle());
		}

		//@��ע ��������������.  
		//@���� pPt �����.
		//@���� ����������.
		//@����  ���Ե����()
		int HitTest(POINT* pPt) {
			return XListBox_HitTest(getEleHandle(), pPt);
		}

		//@��ע ��������������,�Զ���ӹ�����ͼƫ����.  
		//@���� pPt �����.
		//@���� ������.
		//@����  ���Ե������չ()
		int HitTestOffset(POINT* pPt) {
			return XListBox_HitTestOffset(getEleHandle(), pPt);
		}

		//@��ע �����б���ģ���ļ�.  
		//@���� pXmlFile �ļ���.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ����ģ���ļ�()
		bool SetItemTemplateXML(const std::wstring& xmlFile) {
			return XListBox_SetItemTemplateXML(getEleHandle(), xmlFile.c_str());
		}

		//@��ע �����б���ģ��.  
		//@���� hTemp ģ����
		//@���� ����ɹ�����TRUE,���򷵻�FALSE.
		//@����  ����ģ��()
		bool SetItemTemplate(HTEMP hTemp) {
			return XListBox_SetItemTemplate(getEleHandle(), hTemp);
		}

		//@��ע �������ģ���ļ�.  
		//@���� pStringXML �ַ���ָ��.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ����ģ����ַ���()
		bool SetItemTemplateXMLFromString(const std::string& xmlData) {
			return XListBox_SetItemTemplateXMLFromString(getEleHandle(), xmlData.c_str());
		}

		//@��ע ͨ��ģ����ID,��ȡʵ����ģ����ID��Ӧ�Ķ�����.  
		//@���� iItem ������.
		//@���� nTempItemID ģ����ID.
		//@���� �ɹ����ض�����,���򷵻�NULL.
		//@����  ȡģ�����()
		HXCGUI GetTemplateObject(int iItem, int nTempItemID) {
			return XListBox_GetTemplateObject(getEleHandle(), iItem, nTempItemID);
		}

		//@��ע �Ƿ����ö���ѡ����.  
		//@���� bEnable �Ƿ�����.
		//@����  ���ö�ѡ()
		void EnableMultiSel(bool bEnable) {
			XListBox_EnableMultiSel(getEleHandle(), bEnable);
		}

		//@��ע ������������������,���ݰ󶨵���ģ���ʼ����������������.  
		//@���� �������������.
		//@����  ��������������()
		HXCGUI CreateAdapter() {
			return XListBox_CreateAdapter(getEleHandle());
		}

		//@��ע ������������.  
		//@���� hAdapter ������������� XAdTable.
		//@����  ������������()
		void BindAdapter(HXCGUI hAdapter) {
			XListBox_BindAdapter(getEleHandle(), hAdapter);
		}

		//@��ע ��ȡ�󶨵�����������.  
		//@���� �����������������.
		//@����  ȡ����������()
		HXCGUI GetAdapter() {
			return XListBox_GetAdapter(getEleHandle());
		}

		//@��ע ����.  
		//@���� iColumnAdapter ��Ҫ���������������������������������.
		//@���� bAscending ����(TRUE)����(FALSE).
		//@����  ����()
		void Sort(int iColumnAdapter, bool bAscending) {
			XListBox_Sort(getEleHandle(), iColumnAdapter, bAscending);
		}

		//@��ע �޸����ݺ�,ˢ��������ģ��,�Ա�������ݵ�ģ��(�����ɼ�).  
		//@����  ˢ������()
		void RefreshData() {
			XListBox_RefreshData(getEleHandle());
		}

		//@��ע �޸����ݺ�,ˢ��ָ����ģ��,�Ա�������ݵ�ģ��(�����ǰ��ɼ�).  
		//@���� iItem ������.
		//@����  ˢ��ָ����()
		void RefreshItem(int iItem) {
			XListBox_RefreshItem(getEleHandle(), iItem);
		}

		//@��ע XAdTable_AddItemText  
		//@���� text.c_str() 
		//@���� ����������
		//@����  ������ı�()
		int AddItemText(const std::wstring& text) {
			return XListBox_AddItemText(getEleHandle(), text.c_str());
		}

		//@��ע XAdTable_AddItemTextEx  
		//@���� name.c_str() 
		//@���� text.c_str() 
		//@����  ������ı���չ()
		int AddItemTextEx(const std::wstring& name, const std::wstring& text) {
			return XListBox_AddItemTextEx(getEleHandle(), name.c_str(), text.c_str());
		}

		//@��ע XAdTable_AddItemImage  
		//@���� hImage 
		//@����  �����ͼƬ()
		int AddItemImage(HIMAGE hImage) {
			return XListBox_AddItemImage(getEleHandle(), hImage);
		}

		//@��ע XAdTable_AddItemImageEx  
		//@���� name.c_str() 
		//@���� hImage 
		//@����  �����ͼƬ��չ()
		int AddItemImageEx(const std::wstring& name, HIMAGE hImage) {
			return XListBox_AddItemImageEx(getEleHandle(), name.c_str(), hImage);
		}

		//@���� iItem 
		//@���� value.c_str() 
		//@����  �������ı�()
		int InsertItemText(int iItem, const std::wstring& value) {
			return XListBox_InsertItemText(getEleHandle(), iItem, value.c_str());
		}

		//@���� iItem 
		//@���� name.c_str() 
		//@���� value.c_str() 
		//@����  �������ı���չ()
		int InsertItemTextEx(int iItem, const std::wstring& name, const std::wstring& value) {
			return XListBox_InsertItemTextEx(getEleHandle(), iItem, name.c_str(), value.c_str());
		}

		//@���� iItem 
		//@���� hImage 
		//@����  ������ͼƬ()
		int InsertItemImage(int iItem, HIMAGE hImage) {
			return XListBox_InsertItemImage(getEleHandle(), iItem, hImage);
		}

		//@���� iItem 
		//@���� name.c_str() 
		//@���� hImage 
		//@����  ������ͼƬ��չ()
		int InsertItemImageEx(int iItem, const std::wstring& name, HIMAGE hImage) {
			return XListBox_InsertItemImageEx(getEleHandle(), iItem, name.c_str(), hImage);
		}

		//@���� iItem 
		//@���� iColumn 
		//@���� text.c_str() 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  �����ı�()
		bool SetItemText(int iItem, int iColumn, const std::wstring& text) {
			return XListBox_SetItemText(getEleHandle(), iItem, iColumn, text.c_str());
		}

		//@���� iItem 
		//@���� name.c_str() 
		//@���� text.c_str() 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  �����ı���չ()
		bool SetItemTextEx(int iItem, const std::wstring& name, const std::wstring& text) {
			return XListBox_SetItemTextEx(getEleHandle(), iItem, name.c_str(), text.c_str());
		}

		//@���� iItem 
		//@���� iColumn 
		//@���� hImage 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ����ͼƬ()
		bool SetItemImage(int iItem, int iColumn, HIMAGE hImage) {
			return XListBox_SetItemImage(getEleHandle(), iItem, iColumn, hImage);
		}

		//@���� iItem 
		//@���� name.c_str() 
		//@���� hImage 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ����ͼƬ��չ()
		bool SetItemImageEx(int iItem, const std::wstring& name, HIMAGE hImage) {
			return XListBox_SetItemImageEx(getEleHandle(), iItem, name.c_str(), hImage);
		}

		//@���� iItem 
		//@���� iColumn 
		//@���� nValue 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ��������ֵ()
		bool SetItemInt(int iItem, int iColumn, int nValue) {
			return XListBox_SetItemInt(getEleHandle(), iItem, iColumn, nValue);
		}

		//@���� iItem 
		//@���� name.c_str() 
		//@���� nValue 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ��������ֵ��չ()
		bool SetItemIntEx(int iItem, const std::wstring& name, int nValue) {
			return XListBox_SetItemIntEx(getEleHandle(), iItem, name.c_str(), nValue);
		}

		//@���� iItem 
		//@���� iColumn 
		//@���� fFloat 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  �����ֵ()
		bool SetItemFloat(int iItem, int iColumn, float fFloat) {
			return XListBox_SetItemFloat(getEleHandle(), iItem, iColumn, fFloat);
		}

		//@���� iItem 
		//@���� name.c_str() 
		//@���� fFloat 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  �����ֵ��չ()
		bool SetItemFloatEx(int iItem, const std::wstring& name, float fFloat) {
			return XListBox_SetItemFloatEx(getEleHandle(), iItem, name.c_str(), fFloat);
		}

		//@���� iItem 
		//@���� iColumn 
		//@���� �����ı�����
		//@����  ȡ���ı�()
		std::wstring GetItemText(int iItem, int iColumn) {
			auto pText = XListBox_GetItemText(getEleHandle(), iItem, iColumn);
			if (!pText) return L"";
			return pText;
		}

		//@���� iItem 
		//@���� name.c_str() 
		//@���� �����ı�����
		//@����  ȡ���ı���չ()
		std::wstring GetItemTextEx(int iItem, const std::wstring& name) {
			auto pText = XListBox_GetItemTextEx(getEleHandle(), iItem, name.c_str());
			if (!pText) return L"";
			return pText;
		}

		//@���� iItem 
		//@���� iColumn 
		//@����  ȡ��ͼƬ()
		HIMAGE GetItemImage(int iItem, int iColumn) {
			return XListBox_GetItemImage(getEleHandle(), iItem, iColumn);
		}

		//@���� iItem 
		//@���� name.c_str() 
		//@����  ȡ��ͼƬ��չ()
		HIMAGE GetItemImageEx(int iItem, const std::wstring& name) {
			return XListBox_GetItemImageEx(getEleHandle(), iItem, name.c_str());
		}

		//@���� iItem 
		//@���� iColumn 
		//@���� pOutValue 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ȡ������ֵ()
		bool GetItemInt(int iItem, int iColumn, int* pOutValue) {
			return XListBox_GetItemInt(getEleHandle(), iItem, iColumn, pOutValue);
		}

		//@���� iItem 
		//@���� name.c_str() 
		//@���� pOutValue 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ȡ������ֵ��չ()
		bool GetItemIntEx(int iItem, const std::wstring& name, int* pOutValue) {
			return XListBox_GetItemIntEx(getEleHandle(), iItem, name.c_str(), pOutValue);
		}

		//@���� iItem 
		//@���� iColumn 
		//@���� pOutValue 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ȡ���ֵ()
		bool GetItemFloat(int iItem, int iColumn, float* pOutValue) {
			return XListBox_GetItemFloat(getEleHandle(), iItem, iColumn, pOutValue);
		}

		//@���� iItem 
		//@���� name.c_str() 
		//@���� pOutValue 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ȡ���ֵ��չ()
		bool GetItemFloatEx(int iItem, const std::wstring& name, float* pOutValue) {
			return XListBox_GetItemFloatEx(getEleHandle(), iItem, name.c_str(), pOutValue);
		}

		//@���� iItem 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ɾ����()
		bool DeleteItem(int iItem) {
			return XListBox_DeleteItem(getEleHandle(), iItem);
		}

		//@���� iItem 
		//@���� nCount 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ɾ������չ()
		bool DeleteItemEx(int iItem, int nCount) {
			return XListBox_DeleteItemEx(getEleHandle(), iItem, nCount);
		}

		//@����  ɾ����ȫ��()
		void DeleteItemAll() {
			XListBox_DeleteItemAll(getEleHandle());
		}

		//@����  ɾ����ȫ��()
		void DeleteColumnAll() {
			XListBox_DeleteColumnAll(getEleHandle());
		}

		//@����  ȡ������AD()
		int GetCount_AD() {
			return XListBox_GetCount_AD(getEleHandle());
		}

		//@����  ȡ������AD()
		int GetCountColumn_AD() {
			return XListBox_GetCountColumn_AD(getEleHandle());
		}


		// �б���_���϶�������ɫ
		void SetDragRectColor(COLORREF color, int width) {
			return XListBox_SetDragRectColor(getEleHandle(), color, width);
		}


	};
}