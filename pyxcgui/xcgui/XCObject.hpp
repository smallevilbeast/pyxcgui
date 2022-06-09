#pragma once
#include "pch.h"

namespace xcgui {

	class XCObject
	{
	public:
		XCObject()
			: m_handle(NULL)
		{}
		virtual ~XCObject() = default;

		XCObject(HXCGUI handle)
		{
			m_handle = handle;
		}

		//  ��ȡ������������
		XC_OBJECT_TYPE GetType()
		{
			return XObj_GetType(m_handle);
		}

		// ��ȡ����Ļ�������
		XC_OBJECT_TYPE GetTypeBase()
		{
			return XObj_GetTypeBase(m_handle);
		}

		// ��ȡ������չ����
		XC_OBJECT_TYPE_EX GetTypeEx()
		{
			return XObj_GetTypeEx(m_handle);
		}

		// ����ǰ�ť, ��ʹ�ð�ť����ǿ�ӿ� XBtn_SetTypeEx()
		void SetTypeEx(XC_OBJECT_TYPE_EX nType)
		{
			XObj_SetTypeEx(m_handle, nType);
		}


		// ��ȡ��������.
		std::wstring GetProperty(const std::wstring& name) {
			auto pName = XC_GetProperty(m_handle, name.c_str());
			if (!pName) {
				return L"";
			}
			return pName;
		}

		bool SetProperty(const std::wstring& name, const std::wstring& value) {
			return XC_SetProperty(m_handle, name.c_str(), value.c_str());
		}

		void ReleaseAnimation(bool end=true) {
			XAnima_ReleaseEx(m_handle, end);
		}

		virtual HXCGUI GetHandle() const
		{
			return m_handle;
		}


		void SetHandle(HXCGUI handle)
		{
			m_handle = handle;
		}

	protected:
		HXCGUI m_handle;
	};

}