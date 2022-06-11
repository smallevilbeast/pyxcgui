#pragma once
#include "pch.h"
#include "xcgui/element/XCScrollView.hpp"

namespace xcgui {


	class XCList : public XCScrollView
	{

	public:
		XCList(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCList() = default;

		XCList(int x, int y, int width, int height, HXCGUI parent = NULL) {

			m_handle = XList_Create(x, y, width, height, parent);
		}

		//@��ע ������.  
		//@���� width �п��.
		//@���� ����λ������.
		//@����  ������()
		int AddColumn(int width) {
			return XList_AddColumn(getEleHandle(), width);
		}

		//@��ע ������.  
		//@���� width �п��.
		//@���� iRow ����λ������.
		//@���� ���ز���λ������.
		//@����  ������()
		int InsertColumn(int width, int iRow) {
			return XList_InsertColumn(getEleHandle(), width, iRow);
		}

		//@��ע ���û�رն�ѡ����.  
		//@���� bEnable �Ƿ�����.
		//@����  ���ö�ѡ()
		void EnableMultiSel(bool bEnable) {
			XList_EnableMultiSel(getEleHandle(), bEnable);
		}

		//@��ע �����϶��ı��п��.  
		//@���� bEnable �Ƿ�����.
		//@����  �����϶������п�()
		void EnableDragChangeColumnWidth(bool bEnable) {
			XList_EnableDragChangeColumnWidth(getEleHandle(), bEnable);
		}

		//@��ע ���ô�ֱ��������������.  
		//@���� bTop �Ƿ�����.
		//@����  ���ô�ֱ��������������()
		void EnableVScrollBarTop(bool bTop) {
			XList_EnableVScrollBarTop(getEleHandle(), bTop);
		}

		//@��ע �������ȫ�����ģʽ.  
		//@���� bFull �Ƿ�����.
		//@����  �������ȫ��ģʽ()
		void EnableItemBkFullRow(bool bFull) {
			XList_EnableItemBkFullRow(getEleHandle(), bFull);
		}

		//@���� bEnable �Ƿ�����
		//@����  ���ù̶��и�()
		void EnableFixedRowHeight(bool bEnable) {
			XList_EnableFixedRowHeight(getEleHandle(), bEnable);
		}

		//@���� bEnable �Ƿ�����
		//@����  ����ģ�帴��()
		void EnablemTemplateReuse(bool bEnable) {
			XList_EnablemTemplateReuse(getEleHandle(), bEnable);
		}

		//@���� bEnable �Ƿ�����
		//@����  �������()
		void EnableVirtualTable(bool bEnable) {
			XList_EnableVirtualTable(getEleHandle(), bEnable);
		}

		//@���� nRowCount ����
		//@����  ���������()
		void SetVirtualRowCount(int nRowCount) {
			XList_SetVirtualRowCount(getEleHandle(), nRowCount);
		}

		//@��ע ������������.  
		//@���� iColumn ������.
		//@���� iColumnAdapter ��Ҫ����������������������е�������.
		//@���� bEnable �Ƿ�����������.
		//@����  ������()
		void SetSort(int iColumn, int iColumnAdapter, bool bEnable) {
			XList_SetSort(getEleHandle(), iColumn, iColumnAdapter, bEnable);
		}

		//@��ע �����Ƿ����ָ��״̬����ı���.  
		//@���� nFlags ��־λ @ref list_drawItemBk_flag_.
		//@����  �û��������־()
		void SetDrawItemBkFlags(int style) {
			XList_SetDrawItemBkFlags(getEleHandle(), style);
		}

		//@���� color ��ɫֵ, ��ʹ�ú�: RGBA()
		//@����  �÷ָ�����ɫ()
		void SetSplitLineColor(COLORREF color) {
			XList_SetSplitLineColor(getEleHandle(), color);
		}

		//@��ע �����п��.  
		//@���� iRow ������.
		//@���� width ���.
		//@����  ���п�()
		void SetColumnWidth(int iRow, int width) {
			XList_SetColumnWidth(getEleHandle(), iRow, width);
		}

		//@��ע ��������С���.  
		//@���� iRow ������.
		//@���� width ���.
		//@����  ������С���()
		void SetColumnMinWidth(int iRow, int width) {
			XList_SetColumnMinWidth(getEleHandle(), iRow, width);
		}

		//@��ע ����ָ���п�ȹ̶�.  
		//@���� iColumn ������.
		//@���� bFixed �Ƿ�̶����.
		//@����  ���п�ȹ̶�()
		void SetColumnWidthFixed(int iColumn, bool bFixed) {
			XList_SetColumnWidthFixed(getEleHandle(), iColumn, bFixed);
		}

		//@��ע ��ȡָ���п��.  
		//@���� iColumn ������.
		//@���� ����ָ���п��.
		//@����  ȡ�п��()
		int GetColumnWidth(int iColumn) {
			return XList_GetColumnWidth(getEleHandle(), iColumn);
		}

		//@��ע ��ȡ������.  
		//@���� ����������.
		//@����  ȡ������()
		int GetColumnCount() {
			return XList_GetColumnCount(getEleHandle());
		}

		//@��ע �������û�����.  
		//@���� iRow ������.
		//@���� iColumn ������.
		//@���� data �û�����.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ��������()
		bool SetItemData(int iRow, int iColumn, int data) {
			return XList_SetItemData(getEleHandle(), iRow, iColumn, data);
		}

		//@��ע ��ȡ���û�����.  
		//@���� iRow ������.
		//@���� iColumn ������.
		//@���� �����û�����.
		//@����  ȡ������()
		int GetItemData(int iRow, int iColumn) {
			return XList_GetItemData(getEleHandle(), iRow, iColumn);
		}

		//@��ע ����ѡ����.  
		//@���� iRow ������.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ��ѡ����()
		bool SetSelectItem(int iRow) {
			return XList_SetSelectItem(getEleHandle(), iRow);
		}

		//@��ע ��ȡѡ����.  
		//@���� ������.
		//@����  ȡѡ����()
		int GetSelectItem() {
			return XList_GetSelectItem(getEleHandle());
		}

		//@��ע ��ȡѡ��������.  
		//@���� ����ѡ��������.
		//@����  ȡѡ��������()
		int GetSelectItemCount() {
			return XList_GetSelectItemCount(getEleHandle());
		}

		//@���� iRow ������
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ���ѡ����()
		bool AddSelectItem(int iRow) {
			return XList_AddSelectItem(getEleHandle(), iRow);
		}

		//@��ע ѡ��ȫ����.  
		//@����  ��ѡ��ȫ��()
		void SetSelectAll() {
			XList_SetSelectAll(getEleHandle());
		}

		//@��ע ��ȡȫ��ѡ�����.  
		//@���� pArray ��������������.
		//@���� nArraySize �����С.
		//@���� ����������.
		//@����  ȡȫ��ѡ��()
		int GetSelectAll(int* pArray, int nArraySize) {
			return XList_GetSelectAll(getEleHandle(), pArray, nArraySize);
		}

		//@��ע ������ͼ��ָ����ɼ�  
		//@���� iRow ������.
		//@����  ��ʾָ����()
		void VisibleItem(int iRow) {
			XList_VisibleItem(getEleHandle(), iRow);
		}

		//@��ע ȡ��ѡ��ָ����(�������������Ϊ��).  
		//@���� iRow ������.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ȡ��ѡ����()
		bool CancelSelectItem(int iRow) {
			return XList_CancelSelectItem(getEleHandle(), iRow);
		}

		//@��ע ȡ��ѡ��������(�������������Ϊ��).  
		//@����  ȡ��ȫ��ѡ����()
		void CancelSelectAll() {
			XList_CancelSelectAll(getEleHandle());
		}

		//@��ע ��ȡ�б�ͷԪ��.  
		//@���� �����б�ͷԪ�ؾ��.
		//@����  ȡ�б�ͷ()
		HELE GetHeaderHELE() {
			return XList_GetHeaderHELE(getEleHandle());
		}

		//@��ע ɾ����.  
		//@���� iRow ������.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ɾ����()
		bool DeleteColumn(int iRow) {
			return XList_DeleteColumn(getEleHandle(), iRow);
		}

		//@��ע ɾ�����е���,��ɾ��List��, �������������в���.   
		//@����  ɾ��ȫ����()
		void DeleteColumnAll() {
			XList_DeleteColumnAll(getEleHandle());
		}

		//@��ע ������������.  
		//@���� hAdapter ������������� XAdTable.
		//@����  ������������()
		void BindAdapter(HXCGUI hAdapter) {
			XList_BindAdapter(getEleHandle(), hAdapter);
		}

		//@��ע �б�ͷ������������.  
		//@���� hAdapter ������������� XAdMap.
		//@����  �б�ͷ������������()
		void BindAdapterHeader(HXCGUI hAdapter) {
			XList_BindAdapterHeader(getEleHandle(), hAdapter);
		}

		//@��ע �������������������ݰ󶨵���ģ���ʼ����������������.  
		//@���� �������������.
		//@����  ��������������()
		HXCGUI CreateAdapter(int colExtendCount=0) {
			return XList_CreateAdapter(getEleHandle(), colExtendCount);
		}

		//@��ע �������������������ݰ󶨵���ģ���ʼ����������������.  
		//@���� �������������.
		//@����  �б�ͷ��������������()
		HXCGUI CreateAdapterHeader() {
			return XList_CreateAdapterHeader(getEleHandle());
		}

		//@��ע ��ȡ����������.  
		//@���� �������������.
		//@����  ȡ����������()
		HXCGUI GetAdapter() {
			return XList_GetAdapter(getEleHandle());
		}

		//@��ע ��ȡ�б�ͷ����������.  
		//@���� �����������������.
		//@����  �б�ͷ��ȡ����������()
		HXCGUI GetAdapterHeader() {
			return XList_GetAdapterHeader(getEleHandle());
		}

		//@��ע �������ģ���ļ�.  
		//@���� pXmlFile �ļ���.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ����ģ���ļ�()
		bool SetItemTemplateXML(const std::wstring& xmlFile) {
			return XList_SetItemTemplateXML(getEleHandle(), xmlFile.c_str());
		}

		//@��ע �������ģ���ļ�.  
		//@���� pStringXML �ַ���ָ��.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ����ģ����ַ���()
		bool SetItemTemplateXMLFromString(const std::string& xmlData) {
			return XList_SetItemTemplateXMLFromString(getEleHandle(), xmlData.c_str());
		}

		//@��ע �����б���ģ��.  
		//@���� hTemp ģ����.
		//@���� ����ɹ�����TRUE,���򷵻�FALSE.
		//@����  ����ģ��()
		bool SetItemTemplate(HTEMP hTemp) {
			return XList_SetItemTemplate(getEleHandle(), hTemp);
		}

		//@��ע ͨ��ģ����ID,��ȡʵ����ģ����ID��Ӧ�Ķ�����.  
		//@���� iRow ������.
		//@���� iColumn ������.
		//@���� nTempItemID ģ����itemID.
		//@���� �ɹ����ض�����,���򷵻�NULL.
		//@����  ȡ��ģ�����()
		HXCGUI GetTemplateObject(int iRow, int iColumn, int nTempItemID) {
			return XList_GetTemplateObject(getEleHandle(), iRow, iColumn, nTempItemID);
		}

		//@��ע ��ȡ��ǰ��������ģ��ʵ��,�����б�����һ����.  
		//@���� hXCGUI ������, UIԪ�ؾ������״������.
		//@���� �ɹ�����������, ���򷵻�@ref XC_ID_ERROR.
		//@����  ȡ����������()
		int GetItemIndexFromHXCGUI(HXCGUI hXCGUI) {
			return XList_GetItemIndexFromHXCGUI(getEleHandle(), hXCGUI);
		}

		//@��ע �б�ͷ,ͨ��ģ����ID,��ȡʵ����ģ����ID��Ӧ�Ķ�����.  
		//@���� iColumn �б�ͷ ������.
		//@���� nTempItemID ģ����ID.
		//@���� �ɹ����ض�����,���򷵻�NULL.
		//@����  ȡ�б�ͷģ�����()
		HXCGUI GetHeaderTemplateObject(int iColumn, int nTempItemID) {
			return XList_GetHeaderTemplateObject(getEleHandle(), iColumn, nTempItemID);
		}

		//@��ע �б�ͷ,��ȡ��ǰ��������ģ��ʵ��,�����б�ͷ����һ����.  
		//@���� hXCGUI ������.
		//@���� �ɹ�����������, ���򷵻�@ref XC_ID_ERROR.
		//@����  ȡ�б�ͷ����������()
		int GetHeaderItemIndexFromHXCGUI(HXCGUI hXCGUI) {
			return XList_GetHeaderItemIndexFromHXCGUI(getEleHandle(), hXCGUI);
		}

		//@��ע �����б�ͷ�߶�.  
		//@���� height �߶�.
		//@����  ���б�ͷ�߶�()
		void SetHeaderHeight(int height) {
			XList_SetHeaderHeight(getEleHandle(), height);
		}

		//@��ע ��ȡ�б�ͷ�߶�.  
		//@���� �����б�ͷ�߶�.
		//@����  ȡ�б�ͷ�߶�()
		int GetHeaderHeight() {
			return XList_GetHeaderHeight(getEleHandle());
		}

		//@��ע ��ȡ��ǰ�ɼ��з�Χ.  
		//@���� piStart ��ʼ������.
		//@���� piEnd ����������.
		//@����  ȡ�����з�Χ()
		void GetVisibleRowRange(int* piStart, int* piEnd) {
			XList_GetVisibleRowRange(getEleHandle(), piStart, piEnd);
		}

		//@��ע ������Ĭ�ϸ߶�.  
		//@���� nHeight �߶�.
		//@���� nSelHeight ѡ��ʱ�߶�.
		//@����  ����Ĭ�ϸ߶�()
		void SetItemHeightDefault(int nHeight, int nSelHeight) {
			XList_SetItemHeightDefault(getEleHandle(), nHeight, nSelHeight);
		}

		//@��ע ��ȡ��Ĭ�ϸ߶�.  
		//@���� pHeight �߶�.
		//@���� pSelHeight ѡ��ʱ�߶�.
		//@����  ȡ��Ĭ�ϸ߶�()
		void GetItemHeightDefault(int* pHeight, int* pSelHeight) {
			XList_GetItemHeightDefault(getEleHandle(), pHeight, pSelHeight);
		}

		//@��ע ������߶�.  
		//@���� iRow ������
		//@���� nHeight �߶�.
		//@���� nSelHeight ѡ��ʱ�߶�.
		//@����  ����߶�()
		void SetItemHeight(int iRow, int nHeight, int nSelHeight) {
			XList_SetItemHeight(getEleHandle(), iRow, nHeight, nSelHeight);
		}

		//@��ע ��ȡ��߶�.  
		//@���� iRow ������
		//@���� pHeight �߶�.
		//@���� pSelHeight ѡ��ʱ�߶�.
		//@����  ȡ��߶�()
		void GetItemHeight(int iRow, int* pHeight, int* pSelHeight) {
			XList_GetItemHeight(getEleHandle(), iRow, pHeight, pSelHeight);
		}

		//@��ע �����м��.  
		//@���� nSpace �м���С.
		//@����  ���м��()
		void SetRowSpace(int nSpace) {
			XList_SetRowSpace(getEleHandle(), nSpace);
		}

		//@��ע ��ȡ�м���С.  
		//@���� �����м���С.
		//@����  ȡ�м��()
		int GetRowSpace() {
			return XList_GetRowSpace(getEleHandle());
		}

		//@��ע ������,������������зֽ�������.  
		//@���� iColumn ������,-1��������.
		//@����  �����������()
		void SetLockColumnLeft(int iColumn) {
			XList_SetLockColumnLeft(getEleHandle(), iColumn);
		}

		//@��ע ������,�����Ҳ������зֽ�������  
		//@���� iColumn ������, -1��������. ��ʱֻ֧������ĩβ�� 
		//@����  ���������Ҳ�()
		void SetLockColumnRight(int iColumn) {
			XList_SetLockColumnRight(getEleHandle(), iColumn);
		}

		//@��ע �����Ƿ�����ĩβ��.  
		//@���� bLock �Ƿ�����.
		//@����  �������еײ�()
		void SetLockRowBottom(bool bLock) {
			XList_SetLockRowBottom(getEleHandle(), bLock);
		}

		//@���� bOverlap �Ƿ��ص�
		//@����  �������еײ��ص�()
		void SetLockRowBottomOverlap(bool bOverlap) {
			XList_SetLockRowBottomOverlap(getEleHandle(), bOverlap);
		}

		//@��ע ��������������.  
		//@���� pPt �����.
		//@���� piRow ������.
		//@���� piColumn ������.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ���Ե����()
		bool HitTest(POINT* pPt, int* piRow, int* piColumn) {
			return XList_HitTest(getEleHandle(), pPt, piRow, piColumn);
		}

		//@��ע ��������������,�Զ���ӹ�����ͼƫ����.  
		//@���� pPt �����.
		//@���� piRow ������.
		//@���� piColumn ������.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ���Ե������չ()
		bool HitTestOffset(POINT* pPt, int* piRow, int* piColumn) {
			return XList_HitTestOffset(getEleHandle(), pPt, piRow, piColumn);
		}

		//@��ע �޸����ݺ�,ˢ��������ģ��,�Ա�������ݵ�ģ��(�����ɼ�).  
		//@����  ˢ��������()
		void RefreshData() {
			XList_RefreshData(getEleHandle());
		}

		//@��ע �޸����ݺ�,ˢ��ָ����ģ��,�Ա�������ݵ�ģ��(�����ǰ��ɼ�).  
		//@���� iRow ������.
		//@����  ˢ��ָ����()
		void RefreshItem(int iRow) {
			XList_RefreshItem(getEleHandle(), iRow);
		}

		//@���� nWidth 
		//@���� name.c_str() 
		//@���� text.c_str() 
		//@���� ������
		//@����  ������ı�()
		int AddColumnText(int nWidth, const std::wstring& name, const std::wstring& text) {
			return XList_AddColumnText(getEleHandle(), nWidth, name.c_str(), text.c_str());
		}

		//@���� nWidth 
		//@���� name.c_str() 
		//@���� hImage 
		//@���� ������
		//@����  �����ͼƬ()
		int AddColumnImage(int nWidth, const std::wstring& name, HIMAGE hImage) {
			return XList_AddColumnImage(getEleHandle(), nWidth, name.c_str(), hImage);
		}

		//@���� text.c_str() 
		//@����  ������ı�()
		int AddItemText(const std::wstring& text) {
			return XList_AddItemText(getEleHandle(), text.c_str());
		}

		//@���� name.c_str() 
		//@���� text.c_str() 
		//@����  ������ı���չ()
		int AddItemTextEx(const std::wstring& name, const std::wstring& text) {
			return XList_AddItemTextEx(getEleHandle(), name.c_str(), text.c_str());
		}

		//@���� hImage 
		//@����  �����ͼƬ()
		int AddItemImage(HIMAGE hImage) {
			return XList_AddItemImage(getEleHandle(), hImage);
		}

		//@���� name.c_str() 
		//@���� hImage 
		//@����  �����ͼƬ��չ()
		int AddItemImageEx(const std::wstring& name, HIMAGE hImage) {
			return XList_AddItemImageEx(getEleHandle(), name.c_str(), hImage);
		}

		//@���� iRow 
		//@���� value.c_str() 
		//@����  �������ı�()
		int InsertItemText(int iRow, const std::wstring& value) {
			return XList_InsertItemText(getEleHandle(), iRow, value.c_str());
		}

		//@���� iRow 
		//@���� name.c_str() 
		//@���� value.c_str() 
		//@����  �������ı���չ()
		int InsertItemTextEx(int iRow, const std::wstring& name, const std::wstring& value) {
			return XList_InsertItemTextEx(getEleHandle(), iRow, name.c_str(), value.c_str());
		}

		//@���� iRow 
		//@���� hImage 
		//@����  ������ͼƬ()
		int InsertItemImage(int iRow, HIMAGE hImage) {
			return XList_InsertItemImage(getEleHandle(), iRow, hImage);
		}

		//@���� iRow 
		//@���� name.c_str() 
		//@���� hImage 
		//@����  ������ͼƬ��չ()
		int InsertItemImageEx(int iRow, const std::wstring& name, HIMAGE hImage) {
			return XList_InsertItemImageEx(getEleHandle(), iRow, name.c_str(), hImage);
		}

		//@���� iRow 
		//@���� iColumn 
		//@���� text.c_str() 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  �����ı�()
		bool SetItemText(int iRow, int iColumn, const std::wstring& text) {
			return XList_SetItemText(getEleHandle(), iRow, iColumn, text.c_str());
		}

		//@���� iRow 
		//@���� name.c_str() 
		//@���� text.c_str() 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  �����ı���չ()
		bool SetItemTextEx(int iRow, const std::wstring& name, const std::wstring& text) {
			return XList_SetItemTextEx(getEleHandle(), iRow, name.c_str(), text.c_str());
		}

		//@���� iRow 
		//@���� iColumn 
		//@���� hImage 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ����ͼƬ()
		bool SetItemImage(int iRow, int iColumn, HIMAGE hImage) {
			return XList_SetItemImage(getEleHandle(), iRow, iColumn, hImage);
		}

		//@���� iRow 
		//@���� name.c_str() 
		//@���� hImage 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ����ͼƬ��չ()
		bool SetItemImageEx(int iRow, const std::wstring& name, HIMAGE hImage) {
			return XList_SetItemImageEx(getEleHandle(), iRow, name.c_str(), hImage);
		}

		//@���� iRow 
		//@���� iColumn 
		//@���� nValue 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ����ָ��ֵ()
		bool SetItemInt(int iRow, int iColumn, int nValue) {
			return XList_SetItemInt(getEleHandle(), iRow, iColumn, nValue);
		}

		//@���� iRow 
		//@���� name.c_str() 
		//@���� nValue 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ��������ֵ��չ()
		bool SetItemIntEx(int iRow, const std::wstring& name, int nValue) {
			return XList_SetItemIntEx(getEleHandle(), iRow, name.c_str(), nValue);
		}

		//@���� iRow 
		//@���� iColumn 
		//@���� fFloat 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  �����ֵ()
		bool SetItemFloat(int iRow, int iColumn, float fFloat) {
			return XList_SetItemFloat(getEleHandle(), iRow, iColumn, fFloat);
		}

		//@���� iRow 
		//@���� name.c_str() 
		//@���� fFloat 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  �����ֵ��չ()
		bool SetItemFloatEx(int iRow, const std::wstring& name, float fFloat) {
			return XList_SetItemFloatEx(getEleHandle(), iRow, name.c_str(), fFloat);
		}

		//@���� iRow 
		//@���� iColumn 
		//@���� �����ı�����
		//@����  ȡ���ı�()
		std::wstring GetItemText(int iRow, int iColumn) {
			auto pText = XList_GetItemText(getEleHandle(), iRow, iColumn);
			if (!pText) return L"";
			return pText;
		}

		//@���� iRow 
		//@���� name.c_str() 
		//@���� �����ı�����
		//@����  ȡ���ı���չ()
		std::wstring GetItemTextEx(int iRow, const std::wstring& name) {
			auto pText =  XList_GetItemTextEx(getEleHandle(), iRow, name.c_str());
			if (!pText) return L"";
			return pText;
		}

		//@���� iRow 
		//@���� iColumn 
		//@����  ȡ��ͼƬ()
		HIMAGE GetItemImage(int iRow, int iColumn) {
			return XList_GetItemImage(getEleHandle(), iRow, iColumn);
		}

		//@���� iRow 
		//@���� name.c_str() 
		//@����  ȡ��ͼƬ��չ()
		HIMAGE GetItemImageEx(int iRow, const std::wstring& name) {
			return XList_GetItemImageEx(getEleHandle(), iRow, name.c_str());
		}

		//@���� iRow 
		//@���� iColumn 
		//@���� pOutValue 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ȡ������ֵ()
		bool GetItemInt(int iRow, int iColumn, int* pOutValue) {
			return XList_GetItemInt(getEleHandle(), iRow, iColumn, pOutValue);
		}

		//@���� iRow 
		//@���� name.c_str() 
		//@���� pOutValue 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ȡ������ֵ��չ()
		bool GetItemIntEx(int iRow, const std::wstring& name, int* pOutValue) {
			return XList_GetItemIntEx(getEleHandle(), iRow, name.c_str(), pOutValue);
		}

		//@���� iRow 
		//@���� iColumn 
		//@���� pOutValue 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ȡ���ֵ()
		bool GetItemFloat(int iRow, int iColumn, float* pOutValue) {
			return XList_GetItemFloat(getEleHandle(), iRow, iColumn, pOutValue);
		}

		//@���� iRow 
		//@���� name.c_str() 
		//@���� pOutValue 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ȡ���ֵ��չ()
		bool GetItemFloatEx(int iRow, const std::wstring& name, float* pOutValue) {
			return XList_GetItemFloatEx(getEleHandle(), iRow, name.c_str(), pOutValue);
		}

		//@���� iRow 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ɾ����()
		bool DeleteItem(int iRow) {
			return XList_DeleteItem(getEleHandle(), iRow);
		}

		//@���� iRow 
		//@���� nCount 
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ɾ������չ()
		bool DeleteItemEx(int iRow, int nCount) {
			return XList_DeleteItemEx(getEleHandle(), iRow, nCount);
		}

		//@����  ɾ����ȫ��()
		void DeleteItemAll() {
			XList_DeleteItemAll(getEleHandle());
		}

		//@����  ɾ����ȫ��AD()
		void DeleteColumnAll_AD() {
			XList_DeleteColumnAll_AD(getEleHandle());
		}

		//@����  ȡ������AD()
		int GetCount_AD() {
			return XList_GetCount_AD(getEleHandle());
		}

		//@����  ȡ������AD()
		int GetCountColumn_AD() {
			return XList_GetCountColumn_AD(getEleHandle());
		}


		// �б���_���϶�������ɫ
		void SetDragRectColor(COLORREF color, int width) {
			return XList_SetDragRectColor(getEleHandle(), color, width);
		}

	};
}