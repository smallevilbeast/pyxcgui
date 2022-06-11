#pragma once
#include "pch.h"
#include "xcgui/element/XCScrollView.hpp"

namespace xcgui {


	class XCListView : public XCScrollView
	{

	public:
		XCListView(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCListView() = default;

		XCListView(int x, int y, int width, int height, HXCGUI parent = NULL) {

			m_handle = XListView_Create(x, y, width, height, parent);
		}

		//@��ע �������������������ݰ󶨵���ģ���ʼ����������������.  
//@���� �������������.
//@����  ��������������()
		HXCGUI CreateAdapter() {
			return XListView_CreateAdapter(getEleHandle());
		}

		//@��ע ������������.  
		//@���� hAdapter ���������� XAdListView.
		//@����  ������������()
		void BindAdapter(HXCGUI hAdapter) {
			XListView_BindAdapter(getEleHandle(), hAdapter);
		}

		//@��ע ��ȡ����������.  
		//@���� ��������������.
		//@����  ȡ����������()
		HXCGUI GetAdapter() {
			return XListView_GetAdapter(getEleHandle());
		}

		//@��ע ����ģ���ļ�.  
		//@���� pXmlFile �ļ���.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ����ģ���ļ�()
		bool SetItemTemplateXML(const std::wstring& xmlFile) {
			return XListView_SetItemTemplateXML(getEleHandle(), xmlFile.c_str());
		}

		//@��ע �����ģ��.  
		//@���� pStringXML �ַ���ָ��.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ����ģ����ַ���()
		bool SetItemTemplateXMLFromString(const std::string& xmlData) {
			return XListView_SetItemTemplateXMLFromString(getEleHandle(), xmlData.c_str());
		}

		//@��ע ���б���ģ��.  
		//@���� hTemp ģ����.
		//@���� ����ɹ�����TRUE,���򷵻�FALSE.
		//@����  ����ģ��()
		bool SetItemTemplate(HTEMP hTemp) {
			return XListView_SetItemTemplate(getEleHandle(), hTemp);
		}

		//@��ע ͨ��ģ����ID,��ȡʵ����ģ����ID��Ӧ�Ķ�����.  
		//@���� iGroup ������.
		//@���� iItem ������.
		//@���� nTempItemID ģ����ID.
		//@���� �ɹ����ض�����,���򷵻�NULL.
		//@����  ȡģ�����()
		HXCGUI GetTemplateObject(int iGroup, int iItem, int nTempItemID) {
			return XListView_GetTemplateObject(getEleHandle(), iGroup, iItem, nTempItemID);
		}

		//@��ע ͨ��ģ����ID,��ȡʵ����ģ����ID��Ӧ�Ķ�����.  
		//@���� iGroup ������.
		//@���� nTempItemID ģ����ID.
		//@���� �ɹ����ض�����,���򷵻�NULL.
		//@����  ȡģ�������()
		HXCGUI GetTemplateObjectGroup(int iGroup, int nTempItemID) {
			return XListView_GetTemplateObjectGroup(getEleHandle(), iGroup, nTempItemID);
		}

		//@��ע ��ȡ��ǰ��������ģ��ʵ��,�����б�������һ����.  
		//@���� hXCGUI ������, UIԪ�ؾ������״������.
		//@���� piGroup ����������.
		//@���� piItem ����������.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ȡ����������()
		bool GetItemIDFromHXCGUI(HXCGUI hXCGUI, int* piGroup, int* piItem) {
			return XListView_GetItemIDFromHXCGUI(getEleHandle(), hXCGUI, piGroup, piItem);
		}

		//@��ע ��������������.  
		//@���� pPt �����.
		//@���� pOutGroup ����������.
		//@���� pOutItem ����������.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ���Ե����()
		bool HitTest(POINT* pPt, int* pOutGroup, int* pOutItem) {
			return XListView_HitTest(getEleHandle(), pPt, pOutGroup, pOutItem);
		}

		//@��ע ��������������,�Զ���ӹ�����ͼƫ����.  
		//@���� pPt �����.
		//@���� pOutGroup ����������.
		//@���� pOutItem ����������.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ���Ե������չ()
		bool HitTestOffset(POINT* pPt, int* pOutGroup, int* pOutItem) {
			return XListView_HitTestOffset(getEleHandle(), pPt, pOutGroup, pOutItem);
		}

		//@��ע ���ö�ѡ.  
		//@���� bEnable �Ƿ�����.
		//@����  ���ö�ѡ()
		void EnableMultiSel(bool bEnable) {
			XListView_EnableMultiSel(getEleHandle(), bEnable);
		}

		//@���� bEnable �Ƿ�����
		//@����  ����ģ�帴��()
		void EnablemTemplateReuse(bool bEnable) {
			XListView_EnablemTemplateReuse(getEleHandle(), bEnable);
		}

		//@���� bEnable �Ƿ�����
		//@����  �������()
		void EnableVirtualTable(bool bEnable) {
			XListView_EnableVirtualTable(getEleHandle(), bEnable);
		}

		//@���� iGroup ������
		//@���� nCount ������
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  �����������()
		bool SetVirtualItemCount(int iGroup, int nCount) {
			return XListView_SetVirtualItemCount(getEleHandle(), iGroup, nCount);
		}

		//@��ע ���Ƿ����ָ��״̬����ı���.  
		//@���� nFlags ��־λ  @ref list_drawItemBk_flag_.
		//@����  ��������Ʊ�־()
		void SetDrawItemBkFlags(int nFlags) {
			XListView_SetDrawItemBkFlags(getEleHandle(), nFlags);
		}

		//@��ע ��ѡ����.  
		//@���� iGroup ������.
		//@���� iItem ������.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ��ѡ����()
		bool SetSelectItem(int iGroup, int iItem) {
			return XListView_SetSelectItem(getEleHandle(), iGroup, iItem);
		}

		//@��ע ��ȡѡ����.  
		//@���� piGroup ����������.
		//@���� piItem ����������.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  ȡѡ����()
		bool GetSelectItem(int* piGroup, int* piItem) {
			return XListView_GetSelectItem(getEleHandle(), piGroup, piItem);
		}

		//@���� iGroup ������
		//@���� iItem ������
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ���ѡ����()
		bool AddSelectItem(int iGroup, int iItem) {
			return XListView_AddSelectItem(getEleHandle(), iGroup, iItem);
		}

		//@��ע ������ͼ��ָ����ɼ�  
		//@���� iGroup ������.
		//@���� iItem ������.
		//@����  ��ʾָ����()
		void VisibleItem(int iGroup, int iItem) {
			XListView_VisibleItem(getEleHandle(), iGroup, iItem);
		}

		//@��ע ��ȡ��ǰ�ɼ��Χ.  
		//@���� piGroup1 ���ӿ�ʼ��, ��ɼ�
		//@���� piGroup2 ���ӽ�����, ��ɼ�
		//@���� piStartGroup ���ӿ�ʼ��
		//@���� piStartItem ���ӿ�ʼ��
		//@���� piEndGroup ���ӽ�����
		//@���� piEndItem ���ӽ�����
		//@����  ȡ�����Χ()
		void GetVisibleItemRange(int* piGroup1, int* piGroup2, int* piStartGroup, int* piStartItem, int* piEndGroup, int* piEndItem) {
			XListView_GetVisibleItemRange(getEleHandle(), piGroup1, piGroup2, piStartGroup, piStartItem, piEndGroup, piEndItem);
		}

		//@��ע ��ȡѡ��������.  
		//@���� ����ѡ��������.
		//@����  ȡѡ��������()
		int GetSelectItemCount() {
			return XListView_GetSelectItemCount(getEleHandle());
		}

		//@��ע ��ȡѡ�����ID.  
		//@���� pArray ����,��������ѡ����ID.
		//@���� nArraySize �����С.
		//@���� ���ؽ���������.
		//@����  ȡѡ����ȫ��()
		int GetSelectAll(listView_item_id_* pArray, int nArraySize) {
			return XListView_GetSelectAll(getEleHandle(), pArray, nArraySize);
		}

		//@��ע ѡ�����е���.  
		//@����  ��ѡ����ȫ��()
		void SetSelectAll() {
			XListView_SetSelectAll(getEleHandle());
		}

		//@��ע ȡ��ѡ��������.  
		//@����  ȡ��ѡ����ȫ��()
		void CancelSelectAll() {
			XListView_CancelSelectAll(getEleHandle());
		}

		//@��ע ���м����С.  
		//@���� space �����С.
		//@����  ���м��()
		void SetColumnSpace(int space) {
			XListView_SetColumnSpace(getEleHandle(), space);
		}

		//@��ע ���м����С.  
		//@���� space �����С.
		//@����  ���м��()
		void SetRowSpace(int space) {
			XListView_SetRowSpace(getEleHandle(), space);
		}

		//@��ע �����С.  
		//@���� width ���.
		//@���� height �߶�.
		//@����  �����С()
		void SetItemSize(int width, int height) {
			XListView_SetItemSize(getEleHandle(), width, height);
		}

		//@��ע ��ȡ���С.  
		//@���� pSize ���շ��ش�С.
		//@����  ȡ���С()
		void GetItemSize(SIZE* pSize) {
			XListView_GetItemSize(getEleHandle(), pSize);
		}

		//@��ע ����߶�.  
		//@���� height �߶�.
		//@����  ����߶�()
		void SetGroupHeight(int height) {
			XListView_SetGroupHeight(getEleHandle(), height);
		}

		//@��ע ��ȡ��߶�.  
		//@���� ������߶�.
		//@����  ȡ��߶�()
		int GetGroupHeight() {
			return XListView_GetGroupHeight(getEleHandle());
		}

		//@��ע �����û�����.  
		//@���� iGroup ������.
		//@���� nData ����.
		//@����  �����û�����()
		void SetGroupUserData(int iGroup, vint nData) {
			XListView_SetGroupUserData(getEleHandle(), iGroup, nData);
		}

		//@��ע �������û�����.  
		//@���� iGroup ������.
		//@���� iItem ������.
		//@���� nData ����.
		//@����  �����û�����()
		void SetItemUserData(int iGroup, int iItem, vint nData) {
			XListView_SetItemUserData(getEleHandle(), iGroup, iItem, nData);
		}

		//@��ע ��ȡ���û�����.  
		//@���� iGroup ������.
		//@���� �����û�����.
		//@����  ȡ���û�����()
		vint GetGroupUserData(int iGroup) {
			return XListView_GetGroupUserData(getEleHandle(), iGroup);
		}

		//@��ע ��ȡ���û�����.  
		//@���� iGroup ������.
		//@���� iItem ������.
		//@���� �����û�����.
		//@����  ȡ���û�����()
		vint GetItemUserData(int iGroup, int iItem) {
			return XListView_GetItemUserData(getEleHandle(), iGroup, iItem);
		}

		//@��ע �޸����ݺ�,ˢ��������ģ��,�Ա�������ݵ�ģ��(�����ɼ�).  
		//@����  ˢ��������()
		void RefreshData() {
			XListView_RefreshData(getEleHandle());
		}

		//@��ע �޸����ݺ�,ˢ��ָ����ģ��,�Ա�������ݵ�ģ��(�����ǰ��ɼ�).  
		//@���� iGroup ������.
		//@���� iItem ������, ���Ϊ-1,����Ϊ��.
		//@����  ˢ��ָ����()
		void RefreshItem(int iGroup, int iItem) {
			XListView_RefreshItem(getEleHandle(), iGroup, iItem);
		}

		//@��ע չ����.  
		//@���� iGroup ������.
		//@���� bExpand �Ƿ�չ��.
		//@���� �ɹ�����TRUE���򷵻�FALSE,���״̬û�иı䷵��FALSE.
		//@����  չ����()
		bool ExpandGroup(int iGroup, bool bExpand) {
			return XListView_ExpandGroup(getEleHandle(), iGroup, bExpand);
		}

		//@���� name.c_str() �ֶγ�
		//@���� ����������
		//@����  �������()
		int Group_AddColumn(const std::wstring& name) {
			return XListView_Group_AddColumn(getEleHandle(), name.c_str());
		}

		//@���� value.c_str() ֵ
		//@���� iPos ����λ��, -1��ӵ�ĩβ
		//@���� ����������
		//@����  ��������ı�()
		int Group_AddItemText(const std::wstring& value, int iPos=-1) {
			return XListView_Group_AddItemText(getEleHandle(), value.c_str(), iPos);
		}

		//@���� name.c_str() �ֶγ�
		//@���� value.c_str() ֵ
		//@���� iPos ����λ��, -1��ӵ�ĩβ
		//@���� ����������
		//@����  ��������ı���չ()
		int Group_AddItemTextEx(const std::wstring& name, const std::wstring& value, int iPos=-1) {
			return XListView_Group_AddItemTextEx(getEleHandle(), name.c_str(), value.c_str(), iPos);
		}

		//@���� hImage ͼƬ���
		//@���� iPos ����λ��, -1��ӵ�ĩβ
		//@���� ����������
		//@����  �������ͼƬ()
		int Group_AddItemImage(HIMAGE hImage, int iPos=-1) {
			return XListView_Group_AddItemImage(getEleHandle(), hImage, iPos);
		}

		//@���� name.c_str() �ֶγ�
		//@���� hImage ͼƬ���
		//@���� iPos ����λ��, -1��ӵ�ĩβ
		//@���� ����������
		//@����  �������ͼƬ��չ()
		int Group_AddItemImageEx(const std::wstring& name, HIMAGE hImage, int iPos) {
			return XListView_Group_AddItemImageEx(getEleHandle(), name.c_str(), hImage, iPos);
		}

		//@���� iGroup ������
		//@���� iColumn ������
		//@���� value.c_str() ֵ
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  �����ı�()
		bool Group_SetText(int iGroup, int iColumn, const std::wstring& value) {
			return XListView_Group_SetText(getEleHandle(), iGroup, iColumn, value.c_str());
		}

		//@���� iGroup ������
		//@���� name.c_str() �ֶ���
		//@���� value.c_str() ֵ
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  �����ı���չ()
		bool Group_SetTextEx(int iGroup, const std::wstring& name, const std::wstring& value) {
			return XListView_Group_SetTextEx(getEleHandle(), iGroup, name.c_str(), value.c_str());
		}

		//@���� iGroup ������
		//@���� iColumn ������
		//@���� hImage ͼƬ���
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ����ͼƬ()
		bool Group_SetImage(int iGroup, int iColumn, HIMAGE hImage) {
			return XListView_Group_SetImage(getEleHandle(), iGroup, iColumn, hImage);
		}

		//@���� iGroup ������
		//@���� name.c_str() �ֶ���
		//@���� hImage ͼƬ���
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ����ͼƬ��չ()
		bool Group_SetImageEx(int iGroup, const std::wstring& name, HIMAGE hImage) {
			return XListView_Group_SetImageEx(getEleHandle(), iGroup, name.c_str(), hImage);
		}

		//@���� iGroup ������
		//@���� iColumn ������
		//@���� �����ı�����
		//@����  ��ȡ�ı�()
		std::wstring Group_GetText(int iGroup, int iColumn) {
			auto pText = XListView_Group_GetText(getEleHandle(), iGroup, iColumn);
			if (!pText) return L"";
			return pText;
		}

		//@���� iGroup ������
		//@���� name.c_str() �ֶ�����
		//@���� �����ı�����
		//@����  ��ȡ�ı���չ()
		std::wstring Group_GetTextEx(int iGroup, const std::wstring& name) {
			auto pText = XListView_Group_GetTextEx(getEleHandle(), iGroup, name.c_str());
			if (!pText) return L"";
			return pText;
		}

		//@���� iGroup ������
		//@���� iColumn ������
		//@���� ����ͼƬ���
		//@����  ��ȡͼƬ()
		HIMAGE Group_GetImage(int iGroup, int iColumn) {
			return XListView_Group_GetImage(getEleHandle(), iGroup, iColumn);
		}

		//@���� iGroup ������
		//@���� name.c_str() �ֶ�����
		//@���� ����ͼƬ���
		//@����  ��ȡͼƬ��չ()
		HIMAGE Group_GetImageEx(int iGroup, const std::wstring& name) {
			return XListView_Group_GetImageEx(getEleHandle(), iGroup, name.c_str());
		}

		//@���� ����������
		//@����  ���ȡ����()
		int Group_GetCount() {
			return XListView_Group_GetCount(getEleHandle());
		}

		//@���� iGroup ������
		//@���� �ɹ�����������,���򷵻� @ref XC_ID_ERROR.
		//@����  ��ȡ����()
		int Item_GetCount(int iGroup) {
			return XListView_Item_GetCount(getEleHandle(), iGroup);
		}

		//@���� name.c_str() �ֶ���
		//@���� ����������
		//@����  �������()
		int Item_AddColumn(const std::wstring& name) {
			return XListView_Item_AddColumn(getEleHandle(), name.c_str());
		}

		//@���� iGroup ������
		//@���� value.c_str() ֵ
		//@���� iPos ����λ��, -1��ӵ�ĩβ
		//@���� ����������
		//@����  ������ı�()
		int Item_AddItemText(int iGroup, const std::wstring& value, int iPos=-1) {
			return XListView_Item_AddItemText(getEleHandle(), iGroup, value.c_str(), iPos);
		}

		//@���� iGroup ������
		//@���� name.c_str() �ֶ���
		//@���� value.c_str() ֵ
		//@���� iPos ����λ��, -1��ӵ�ĩβ
		//@���� ����������
		//@����  ������ı���չ()
		int Item_AddItemTextEx(int iGroup, const std::wstring& name, const std::wstring& value, int iPos=-1) {
			return XListView_Item_AddItemTextEx(getEleHandle(), iGroup, name.c_str(), value.c_str(), iPos);
		}

		//@���� iGroup ������
		//@���� hImage ͼƬ���
		//@���� iPos ����λ��, -1��ӵ�ĩβ
		//@���� ����������
		//@����  �����ͼƬ()
		int Item_AddItemImage(int iGroup, HIMAGE hImage, int iPos=-1) {
			return XListView_Item_AddItemImage(getEleHandle(), iGroup, hImage, iPos);
		}

		//@���� iGroup ������
		//@���� name.c_str() �ֶ���
		//@���� hImage ͼƬ���
		//@���� iPos ����λ��, -1��ӵ�ĩβ
		//@���� ����������
		//@����  �����ͼƬ��չ()
		int Item_AddItemImageEx(int iGroup, const std::wstring& name, HIMAGE hImage, int iPos=-1) {
			return XListView_Item_AddItemImageEx(getEleHandle(), iGroup, name.c_str(), hImage, iPos);
		}

		//@���� iGroup ������
		//@���� iItem ������
		//@���� iColumn ������
		//@���� value.c_str() ֵ
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  �����ı�()
		bool Item_SetText(int iGroup, int iItem, int iColumn, const std::wstring& value) {
			return XListView_Item_SetText(getEleHandle(), iGroup, iItem, iColumn, value.c_str());
		}

		//@���� iGroup ������
		//@���� iItem ������
		//@���� name.c_str() �ֶ���
		//@���� value.c_str() ֵ
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  �����ı���չ()
		bool Item_SetTextEx(int iGroup, int iItem, const std::wstring& name, const std::wstring& value) {
			return XListView_Item_SetTextEx(getEleHandle(), iGroup, iItem, name.c_str(), value.c_str());
		}

		//@���� iGroup ������
		//@���� iItem ������
		//@���� iColumn ������
		//@���� hImage ͼƬ���
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ����ͼƬ()
		bool Item_SetImage(int iGroup, int iItem, int iColumn, HIMAGE hImage) {
			return XListView_Item_SetImage(getEleHandle(), iGroup, iItem, iColumn, hImage);
		}

		//@���� iGroup ������
		//@���� iItem ������
		//@���� name.c_str() ������
		//@���� hImage ͼƬ���
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ����ͼƬ��չ()
		bool Item_SetImageEx(int iGroup, int iItem, const std::wstring& name, HIMAGE hImage) {
			return XListView_Item_SetImageEx(getEleHandle(), iGroup, iItem, name.c_str(), hImage);
		}


		//@���� iGroup ������
		//@���� iItem ������
		//@���� iColumn ������
		//@���� �����ı�����
		//@����  ��ȡ�ı�()
		std::wstring Item_GetText(int iGroup, int iItem, int iColumn) {
			return XListView_Item_GetText(getEleHandle(), iGroup, iItem, iColumn);
		}

		//@���� iGroup ������
		//@���� iItem ������
		//@���� name.c_str() �ֶγ�
		//@���� �����ı�����
		//@����  ��ȡ�ı���չ()
		std::wstring Item_GetTextEx(int iGroup, int iItem, const std::wstring& name) {
			return XListView_Item_GetTextEx(getEleHandle(), iGroup, iItem, name.c_str());
		}

		//@���� iGroup ������
		//@���� iItem ������
		//@���� iColumn ������
		//@���� ����ͼƬ���
		//@����  ��ȡͼƬ()
		HIMAGE Item_GetImage(int iGroup, int iItem, int iColumn) {
			return XListView_Item_GetImage(getEleHandle(), iGroup, iItem, iColumn);
		}

		//@���� iGroup ������
		//@���� iItem ������
		//@���� name.c_str() �ֶγ�
		//@���� ����ͼƬ���
		//@����  ��ȡͼƬ��չ()
		HIMAGE Item_GetImageEx(int iGroup, int iItem, const std::wstring& name) {
			return XListView_Item_GetImageEx(getEleHandle(), iGroup, iItem, name.c_str());
		}

		//@���� iGroup ������
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ��ɾ����()
		bool Group_DeleteItem(int iGroup) {
			return XListView_Group_DeleteItem(getEleHandle(), iGroup);
		}

		//@���� iGroup ������
		//@����  ��ɾ��ȫ������()
		void Group_DeleteAllChildItem(int iGroup) {
			XListView_Group_DeleteAllChildItem(getEleHandle(), iGroup);
		}

		//@���� iGroup ������
		//@���� iItem ������
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ��ɾ��()
		bool Item_DeleteItem(int iGroup, int iItem) {
			return XListView_Item_DeleteItem(getEleHandle(), iGroup, iItem);
		}

		//@����  ɾ��ȫ��()
		void DeleteAll() {
			XListView_DeleteAll(getEleHandle());
		}

		//@����  ɾ��ȫ����()
		void DeleteAllGroup() {
			XListView_DeleteAllGroup(getEleHandle());
		}

		//@����  ɾ��ȫ����()
		void DeleteAllItem() {
			XListView_DeleteAllItem(getEleHandle());
		}

		//@���� iColumn ������
		//@����  ��ɾ����()
		void DeleteColumnGroup(int iColumn) {
			XListView_DeleteColumnGroup(getEleHandle(), iColumn);
		}

		//@���� iColumn ������
		//@����  ��ɾ����()
		void DeleteColumnItem(int iColumn) {
			XListView_DeleteColumnItem(getEleHandle(), iColumn);
		}

		// �б���_���϶�������ɫ
		void SetDragRectColor(COLORREF color, int width) {
			return XListView_SetDragRectColor(getEleHandle(), color, width);
		}





	};
}