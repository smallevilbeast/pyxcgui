#pragma once
#include "pch.h"
#include "xcgui/element/XCEdit.hpp"

namespace xcgui {


	class XCComboBox : public XCEdit
	{

	public:
		XCComboBox(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCComboBox() = default;

		XCComboBox(int x, int y, int width, int height, HXCGUI parent = NULL) {

			m_handle = XComboBox_Create(x, y, width, height, parent);
		}

		//@��ע ����ѡ����.  
		//@���� iIndex ������.
		//@���� �ɹ����ط��򷵻�FALSE.
		//@����  ��ѡ����()
		bool SetSelItem(int iIndex) {
			return XComboBox_SetSelItem(getEleHandle(), iIndex);
		}

		//@���� �����������������
		//@����  ��������������()
		HXCGUI CreateAdapter() {
			return XComboBox_CreateAdapter(getEleHandle());
		}

		//@��ע ������������.  
		//@���� hAdapter ���������.
		//@����  ������������()
		void BindAdapter(HXCGUI hAdapter) {
			XComboBox_BindAdapter(getEleHandle(), hAdapter);
		}

		//@��ע ��ȡ�󶨵�����������.  
		//@���� ��������������.
		//@����  ȡ����������()
		HXCGUI GetAdapter() {
			return XComboBox_GetAdapter(getEleHandle());
		}

		//@��ע ���ð������������ֶ���.  
		//@���� name.c_str() �ֶ���
		//@����  �ð�����()
		void SetBindName(const std::wstring& name) {
			XComboBox_SetBindName(getEleHandle(), name.c_str());
		}

		//@��ע ��ȡ������ť����.  
		//@���� pRect ����.
		//@����  ȡ������ť����()
		void GetButtonRect(RECT* pRect) {
			XComboBox_GetButtonRect(getEleHandle(), pRect);
		}

		//@��ע ����������ť��С.  
		//@���� size ��С.
		//@����  ��������ť��С()
		void SetButtonSize(int size) {
			XComboBox_SetButtonSize(getEleHandle(), size);
		}

		//@��ע ���������б���������߶�, 
		//@���� height �߶�, -1�Զ�����߶�
		//@����  �������б�߶�()
		void SetDropHeight(int height) {
			XComboBox_SetDropHeight(getEleHandle(), height);
		}

		//@��ע ��ȡ�����б�߶�.  
		//@���� �����б�߶�.
		//@����  ȡ�����б�߶�()
		int GetDropHeight() {
			return XComboBox_GetDropHeight(getEleHandle());
		}

		//@��ע ���������б���ģ���ļ�
		//@���� pXmlFile ��ģ���ļ�.
		//@����  ����ģ���ļ�()
		void SetItemTemplateXML(const std::wstring& xmlFile) {
			XComboBox_SetItemTemplateXML(getEleHandle(), xmlFile.c_str());
		}

		//@��ע ���������б���ģ��.  
		//@���� pStringXML �ַ���ָ��.
		//@����  ����ģ����ַ���()
		void SetItemTemplateXMLFromString(const char* pStringXML) {
			XComboBox_SetItemTemplateXMLFromString(getEleHandle(), pStringXML);
		}

		//@���� hTemp ��ģ����
		//@���� ����ɹ�����TRUE,���򷵻�FALSE
		//@����  ����ģ��()
		bool SetItemTemplate(HTEMP hTemp) {
			return XComboBox_SetItemTemplate(getEleHandle(), hTemp);
		}

		//@��ע �Ƿ����������ť.  
		//@���� bEnable �Ƿ����.
		//@����  ���û���������ť()
		void EnableDrawButton(bool bEnable) {
			XComboBox_EnableDrawButton(getEleHandle(), bEnable);
		}

		//@��ע ���ÿɱ༭��ʾ���ı�����.  
		//@���� bEdit TRUE�ɱ༭,�����෴.
		//@����  ���ñ༭()
		void EnableEdit(bool bEdit) {
			XComboBox_EnableEdit(getEleHandle(), bEdit);
		}

		//@��ע ����/�ر������б�߶ȹ̶���С.  
		//@���� bEnable �Ƿ�����
		//@����  ���������б�߶ȹ̶���С()
		void EnableDropHeightFixed(bool bEnable) {
			XComboBox_EnableDropHeightFixed(getEleHandle(), bEnable);
		}

		//@���� ����ɹ�����TRUE,���򷵻�FALSE
		//@����  ���������б�()
		void PopupDropList() {
			XComboBox_PopupDropList(getEleHandle());
		}

		//@��ע ��ȡ��Ͽ������б���ѡ��������.  
		//@���� ����������.
		//@����  ȡѡ����()
		int GetSelItem() {
			return XComboBox_GetSelItem(getEleHandle());
		}

		//@��ע ��ȡ״̬.  
		//@���� ״̬.
		//@����  ȡ״̬()
		comboBox_state_ GetState() {
			return XComboBox_GetState(getEleHandle());
		}

		//@���� text.c_str() 
		//@���� ����������
		//@����  ������ı�()
		int AddItemText(const std::wstring& text) {
			return XComboBox_AddItemText(getEleHandle(), text.c_str());
		}

		//@���� name.c_str() �ֶ���
		//@���� text.c_str() �ı�
		//@���� ����������
		//@����  ������ı���չ()
		int AddItemTextEx(const std::wstring& name, const std::wstring& text) {
			return XComboBox_AddItemTextEx(getEleHandle(), name.c_str(), text.c_str());
		}

		//@���� hImage ͼƬ���
		//@���� ����������
		//@����  �����ͼƬ()
		int AddItemImage(HIMAGE hImage) {
			return XComboBox_AddItemImage(getEleHandle(), hImage);
		}

		//@���� name.c_str() �ֶ���
		//@���� hImage ͼƬ���
		//@���� ����������
		//@����  �����ͼƬ��չ()
		int AddItemImageEx(const std::wstring& name, HIMAGE hImage) {
			return XComboBox_AddItemImageEx(getEleHandle(), name.c_str(), hImage);
		}

		//@���� iItem ������
		//@���� text.c_str() �ı�
		//@���� ����������
		//@����  �������ı�()
		int InsertItemText(int iItem, const std::wstring& value) {
			return XComboBox_InsertItemText(getEleHandle(), iItem, value.c_str());
		}

		//@���� iItem ������
		//@���� name.c_str() �ֶ���
		//@���� text.c_str() �ı�
		//@���� ����������
		//@����  �������ı���չ()
		int InsertItemTextEx(int iItem, const std::wstring& name, const std::wstring& value) {
			return XComboBox_InsertItemTextEx(getEleHandle(), iItem, name.c_str(), value.c_str());
		}

		//@���� iItem ������
		//@���� hImage ͼƬ���
		//@���� ����������
		//@����  ������ͼƬ()
		int InsertItemImage(int iItem, HIMAGE hImage) {
			return XComboBox_InsertItemImage(getEleHandle(), iItem, hImage);
		}

		//@���� iItem ������
		//@���� name.c_str() �ֶ���
		//@���� hImage ͼƬ���
		//@���� ����������
		//@����  ������ͼƬ��չ()
		int InsertItemImageEx(int iItem, const std::wstring& name, HIMAGE hImage) {
			return XComboBox_InsertItemImageEx(getEleHandle(), iItem, name.c_str(), hImage);
		}

		//@���� iItem ������
		//@���� iColumn ������
		//@���� text.c_str() �ı�
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  �����ı�()
		bool SetItemText(int iItem, int iColumn, const std::wstring& text) {
			return XComboBox_SetItemText(getEleHandle(), iItem, iColumn, text.c_str());
		}

		//@���� iItem ������
		//@���� name.c_str() �ֶ���
		//@���� text.c_str() �ı�
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  �����ı���չ()
		bool SetItemTextEx(int iItem, const std::wstring& name, const std::wstring& text) {
			return XComboBox_SetItemTextEx(getEleHandle(), iItem, name.c_str(), text.c_str());
		}

		//@���� iItem ������
		//@���� iColumn ������
		//@���� hImage ͼƬ���
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ����ͼƬ()
		bool SetItemImage(int iItem, int iColumn, HIMAGE hImage) {
			return XComboBox_SetItemImage(getEleHandle(), iItem, iColumn, hImage);
		}

		//@���� iItem ������
		//@���� name.c_str() �ֶ���
		//@���� hImage ͼƬ���
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ����ͼƬ��չ()
		bool SetItemImageEx(int iItem, const std::wstring& name, HIMAGE hImage) {
			return XComboBox_SetItemImageEx(getEleHandle(), iItem, name.c_str(), hImage);
		}

		//@���� iItem ������
		//@���� iColumn ������
		//@���� nValue ����ֵ
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ��������ֵ()
		bool SetItemInt(int iItem, int iColumn, int nValue) {
			return XComboBox_SetItemInt(getEleHandle(), iItem, iColumn, nValue);
		}

		//@���� iItem ������
		//@���� name.c_str() �ֶ���
		//@���� nValue ����ֵ
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ����ָ��ֵ��չ()
		bool SetItemIntEx(int iItem, const std::wstring& name, int nValue) {
			return XComboBox_SetItemIntEx(getEleHandle(), iItem, name.c_str(), nValue);
		}

		//@���� iItem ������
		//@���� iColumn ������
		//@���� fFloat ������
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  �����ֵ()
		bool SetItemFloat(int iItem, int iColumn, float fFloat) {
			return XComboBox_SetItemFloat(getEleHandle(), iItem, iColumn, fFloat);
		}

		//@���� iItem ������
		//@���� name.c_str() �ֶ���
		//@���� fFloat ������
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  �����ֵ��չ()
		bool SetItemFloatEx(int iItem, const std::wstring& name, float fFloat) {
			return XComboBox_SetItemFloatEx(getEleHandle(), iItem, name.c_str(), fFloat);
		}

		//@���� iItem ������
		//@���� iColumn ������
		//@���� �����ı�����
		//@����  ȡ���ı�()
		std::wstring GetItemText(int iItem, int iColumn) {
			auto pText = XComboBox_GetItemText(getEleHandle(), iItem, iColumn);
			if (!pText) return L"";
			return pText;
		}

		//@���� iItem ������
		//@���� name.c_str() �ֶ���
		//@���� �����ı�����
		//@����  ȡ���ı���չ()
		std::wstring GetItemTextEx(int iItem, const std::wstring& name) {
			auto pText = XComboBox_GetItemTextEx(getEleHandle(), iItem, name.c_str());
			if (!pText) return L"";
			return pText;
		}

		//@���� iItem ������
		//@���� iColumn ������
		//@���� ����ͼƬ���
		//@����  ȡ��ͼƬ()
		HIMAGE GetItemImage(int iItem, int iColumn) {
			return XComboBox_GetItemImage(getEleHandle(), iItem, iColumn);
		}

		//@���� iItem ������
		//@���� name.c_str() �ֶ���
		//@���� ����ͼƬ���
		//@����  ȡ��ͼƬ��չ()
		HIMAGE GetItemImageEx(int iItem, const std::wstring& name) {
			return XComboBox_GetItemImageEx(getEleHandle(), iItem, name.c_str());
		}

		//@���� iItem ������
		//@���� iColumn ������
		//@���� pOutValue ���շ�������ֵ
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ȡ������ֵ()
		bool GetItemInt(int iItem, int iColumn, int* pOutValue) {
			return XComboBox_GetItemInt(getEleHandle(), iItem, iColumn, pOutValue);
		}

		//@���� iItem ������
		//@���� name.c_str() �ֶ���
		//@���� pOutValue ���շ�������ֵ
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ȡ������ֵ��չ()
		bool GetItemIntEx(int iItem, const std::wstring& name, int* pOutValue) {
			return XComboBox_GetItemIntEx(getEleHandle(), iItem, name.c_str(), pOutValue);
		}

		//@���� iItem ������
		//@���� iColumn ������
		//@���� pOutValue ���շ��ظ���ֵ
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ȡ���ֵ()
		bool GetItemFloat(int iItem, int iColumn, float* pOutValue) {
			return XComboBox_GetItemFloat(getEleHandle(), iItem, iColumn, pOutValue);
		}

		//@���� iItem ������
		//@���� name.c_str() �ֶ���
		//@���� pOutValue ���շ��ظ���ֵ
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ȡ���ֵ��չ()
		bool GetItemFloatEx(int iItem, const std::wstring& name, float* pOutValue) {
			return XComboBox_GetItemFloatEx(getEleHandle(), iItem, name.c_str(), pOutValue);
		}

		//@���� iItem ������
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ɾ����()
		bool DeleteItem(int iItem) {
			return XComboBox_DeleteItem(getEleHandle(), iItem);
		}

		//@���� iItem ������
		//@���� nCount ɾ������
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@����  ɾ������չ()
		bool DeleteItemEx(int iItem, int nCount) {
			return XComboBox_DeleteItemEx(getEleHandle(), iItem, nCount);
		}

		//@����  ɾ����ȫ��()
		void DeleteItemAll() {
			XComboBox_DeleteItemAll(getEleHandle());
		}

		//@����  ɾ����ȫ��()
		void DeleteColumnAll() {
			XComboBox_DeleteColumnAll(getEleHandle());
		}

		//@���� ����������
		//@����  ȡ������()
		int GetCount() {
			return XComboBox_GetCount(getEleHandle());
		}

		//@���� ����������
		//@����  ȡ������()
		int GetCountColumn() {
			return XComboBox_GetCountColumn(getEleHandle());
		}

	};
}