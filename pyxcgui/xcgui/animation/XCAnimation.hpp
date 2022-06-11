#pragma once
#include "pch.h"
#include "xcgui/XCObject.hpp"

namespace xcgui {

	class XCAnimation : public XCObject
	{
	public:
		XCAnimation(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCAnimation() = default;


		//@��ע ���������붯��ϵͳ������
		//@���� hAnimationEx �������л򶯻�����
		//@���� hRedrawObjectUI ������UIʱ�ػ��UI��;  UI������: ���ھ��,Ԫ�ؾ��,��״���,SVG���
		//@���� ����_����()
		void Run(HXCGUI hRedRawObjectUI) {
			XAnima_Run(m_handle, hRedRawObjectUI);
		}
		//@��ע �������Ӷ���ϵͳ���Ƴ�,�����Զ�����(��������Զ�����)
		//@���� hAnimationEx �������л򶯻�����
		//@���� bEnd �Ƿ�����ִ�е��յ�
		//@���� ����_�ͷ�()
		bool Release(bool bEnd = true) {
			return XAnima_Release(m_handle, bEnd);

		}
		//@��ע �Ӷ���ϵͳ���Ƴ���ָ��UI������������ж���, �����Զ�����(��������Զ�����)
		//@���� hObjectUI ָ��UI������
		//@���� bEnd �Ƿ�����ִ�е��յ�
		//@���� �����ͷŶ�������
		//@���� ����_�ͷ���չ()
		static int ReleaseEx(HXCGUI objectUI, bool bEnd) {
			return XAnima_ReleaseEx(objectUI, bEnd);
		}



		//@��ע true:�Զ����� false:�ֶ�����
		//@���� hAnimationEx �������л򶯻�����
		//@���� bEnable �Ƿ�����
		//@���� ����_�����Զ�����()
		void EnableAutoDestroy(bool bEnable) {
			XAnima_EnableAutoDestroy(m_handle, bEnable);
		}


		//@��ע ��ȡ����������UI����
		//@���� hAnimationEx �������л򶯻���򶯻�����
		//@���� ����UI������
		//@���� ����_ȡUI����()
		HXCGUI GetObjectUI() {
			return XAnima_GetObjectUI(m_handle);
		}

		//@���� hAnimationEx �������л򶯻�����
		//@���� callback �ص�����
		//@���� ����_�ûص�()
		void SetCallBack(funAnimation callback) {
			XAnima_SetCallback(m_handle, callback);
		}


		//@���� hAnimationEx �������л򶯻�����
		//@���� nUserData ������
		//@���� ����_���û�����()
		void SetUserData(vint nUserData) {
			return XAnima_SetUserData(m_handle, nUserData);
		}


		//@���� hAnimationEx �������л򶯻�����
		//@���� �����û�����
		//@���� ����_ȡ�û�����()
		vint GetUserData() {
			return XAnima_GetUserData(m_handle);
		}

		//@���� hAnimationEx �������л򶯻�����
		//@���� ����_ֹͣ()
		void Stop() {
			XAnima_Stop(m_handle);
		}


		//@���� hAnimationEx �������л򶯻�����
		//@���� ����_��ʼ()
		void Start() {
			XAnima_Start(m_handle);
		}

		//@��ע δʵ�ֹ���
		//@���� hAnimationEx �������л򶯻�����
		//@���� ����_��ͣ()
		void Pause() {
			XAnima_Pause(m_handle);
		}

	protected:
		HXCGUI m_objectHandle;
	};
}