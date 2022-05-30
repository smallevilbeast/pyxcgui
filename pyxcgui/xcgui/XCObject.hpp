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
			:m_handle(handle)
		{
		}

		//  获取对象最终类型
		XC_OBJECT_TYPE GetType()
		{
			return XObj_GetType(m_handle);
		}

		// 获取对象的基础类型
		XC_OBJECT_TYPE GetTypeBase()
		{
			return XObj_GetTypeBase(m_handle);
		}

		// 获取对象扩展类型
		XC_OBJECT_TYPE_EX GetTypeEx()
		{
			return XObj_GetTypeEx(m_handle);
		}

		// 如果是按钮, 请使用按钮的增强接口 XBtn_SetTypeEx()
		void SetTypeEx(XC_OBJECT_TYPE_EX nType)
		{
			XObj_SetTypeEx(m_handle, nType);
		}


		HXCGUI GetHandle() const
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