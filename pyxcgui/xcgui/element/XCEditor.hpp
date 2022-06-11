#pragma once
#include "pch.h"
#include "xcgui/element/XCEdit.hpp"

namespace xcgui {

	class XCEditor : public XCEdit
	{
	public:
		XCEditor(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCEditor() = default;

		XCEditor(int x, int y, int width, int height, HXCGUI parent = NULL) {
			m_handle = XEditor_Create(x, y, width, height, parent);
		}

		//@���� hEle Ԫ�ؾ��
		//@���� iRow ������
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@���� ����༭��_�Ƿ�ϵ�()
		bool IsBreakpoint(int iRow) {
			return XEditor_IsBreakpoint(getEleHandle(), iRow);
		}

		//@���� hEle Ԫ�ؾ��
		//@���� iRow ������
		//@���� bActivate �Ƿ񼤻�
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@���� ����༭��_�öϵ�()
		bool SetBreakpoint(int iRow, bool bActivate = true) {
			return XEditor_SetBreakpoint(getEleHandle(), iRow, bActivate);
		}

		//@���� hEle Ԫ�ؾ��
		//@���� iRow ������
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@���� ����༭��_�Ƴ��ϵ�()
		bool RemoveBreakpoint(int iRow) {
			return XEditor_RemoveBreakpoint(getEleHandle(), iRow);
		}

		//@���� hEle Ԫ�ؾ��
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@���� ����༭��_��նϵ�()
		void ClearBreakpoint() {
			XEditor_ClearBreakpoint(getEleHandle());
		}


		//@���� hEle Ԫ�ؾ��
		//@���� iRow ������
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@���� ����༭��_�õ�ǰ����()
		bool SetRunRow(int iRow) {
			return XEditor_SetRunRow(getEleHandle(), iRow);
		}

		//@���� hEle Ԫ�ؾ��
		//@���� pInfo ��ɫ��Ϣ�ṹ��ָ��
		//@���� ����༭��_ȡ��ɫ��Ϣ()
		void GetColor(editor_color_* pInfo) {
			XEditor_GetColor(getEleHandle(), pInfo);
		}

		//@���� hEle Ԫ�ؾ��
		//@���� pInfo ��ɫ��Ϣ�ṹ��ָ��
		//@���� ����༭��_����ɫ()
		void SetColor(editor_color_* pInfo) {
			XEditor_SetColor(getEleHandle(), pInfo);
		}


		//@���� hEle Ԫ�ؾ��
		//@���� ���ضϵ�����
		//@���� ����༭��_ȡ�ϵ�����()
		int GetBreakpointCount() {
			return XEditor_GetBreakpointCount(getEleHandle());
		}

		//@���� hEle Ԫ�ؾ��
		//@���� nDelay �ӳ�ֵ����
		//@���� ����༭��_����ʾ��Ϣ�ӳ�()
		void SetTipsDelay(int nDelay) {
			return XEditor_SetTipsDelay(getEleHandle(), nDelay);
		}

		//@���� hEle Ԫ�ؾ��
		//@���� model 0:�س�ѡ��, 1:�ո�ѡ��, 3:tab��ѡ��
		//@���� ����༭��_���Զ�ƥ��ѡ��ģʽ()
		void SetAutoMatchSelectModel( int model) {
			XEditor_SetAutoMatchSelectModel(getEleHandle(), model);
		}


		//@���� hEle Ԫ�ؾ��
		//@���� aPoints ���նϵ�����
		//@���� nCount �����С
		//@���� ����ʵ�ʻ�ȡ�ϵ�����
		//@���� ����༭��_ȡȫ���ϵ�()
		int GetBreakpoints(int* aPoints, int nCount) {
			return XEditor_GetBreakpoints(getEleHandle(), aPoints, nCount);
		}

		//@��ע ����������
		//@���� hEle Ԫ�ؾ��
		//@���� iRow ������
		//@���� ����༭��_���õ�ǰ��()
		void SetCurRow(int iRow) {
			XEditor_SetCurRow(getEleHandle(), iRow);
		}

		//@���� hEle Ԫ�ؾ��
		//@���� iRow ������
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@���� ����༭��_��ȡ���()
		int GetDepth(int iRow) {
			return XEditor_GetDepth(getEleHandle(), iRow);
		}

		//@��ע ����������
		//@���� hEle Ԫ�ؾ��
		//@���� iRow ������
		//@���� ����չ��������
		//@���� ����༭��_ת����չ����()
		int ToExpandRow(int iRow) {
			return XEditor_ToExpandRow(getEleHandle(), iRow);
		}

		//@��ע ��ȫչ��ָ����,����:�а������۵�������,����չ��
		//@���� hEle Ԫ�ؾ��
		//@���� iRow ������
		//@���� ����༭��_չ����չ()
		void ExpandEx(int iRow) {
			XEditor_ExpandEx(getEleHandle(), iRow);
		}

		//@���� hEle Ԫ�ؾ��
		//@���� bExpand �Ƿ�չ��
		//@���� ����༭��_չ��ȫ��()
		void ExpandAll(bool bExpand) {
			XEditor_ExpandAll(getEleHandle(), bExpand);
		}

		//@���� hEle Ԫ�ؾ��
		//@���� iRow ������
		//@���� bExpand �Ƿ�չ��
		//@���� �ɹ�����TRUE,���򷵻�FALSE
		//@���� ����༭��_չ��ָ����()
		void Expand(int iRow, bool bExpand) {
			XEditor_Expand(getEleHandle(), iRow, bExpand);
		}

		//@��ע ����Ѵ���,��ô��������ʽ
		//@���� hEle Ԫ�ؾ��
		//@���� pKey �ַ���
		//@���� iStyle ��ʽ
		//@���� ����༭��_��ӹؼ���()
		void AddKeyword(const std::wstring& key, int iStyle) {
			XEditor_AddKeyword(getEleHandle(), key.c_str(), iStyle);
		}

		//@���� hEle Ԫ�ؾ��
		//@���� pKey �ַ���
		//@���� ����༭��_����Զ�ƥ���ַ���()
		void AddConst(const std::wstring& key) {
			XEditor_AddConst(getEleHandle(), key.c_str());
		}

		//@���� hEle Ԫ�ؾ��
		//@���� pKey �ַ���
		//@���� ����༭��_����Զ�ƥ�亯��()
		void AddFunction(const std::wstring& key) {
			XEditor_AddFunction(getEleHandle(), key.c_str());
		}

		//@��ע �ų���������Ĺؼ���, �����ų��������, ��Ϊ������������Զ�ƥ��;
		//@���� hEle Ԫ�ؾ��
		//@���� pKeyword �ַ���
		//@���� ����༭��_����ų���������ؼ���()
		void AddExcludeDefVarKeyword(const std::wstring& keyword) {
			return XEditor_AddExcludeDefVarKeyword(getEleHandle(), keyword.c_str());
		}

		// ����༭��_���Զ�ƥ������ʾģʽ  	0:��Ӣ��, 1:Ӣ��, 3:����
		void SetAutoMatchMode(int mode) {
			XEditor_SetAutoMatchMode(getEleHandle(), mode);
		}

	};
}