#pragma once

#include "pch.h"
#include "xcgui/XCObject.hpp"

namespace xcgui {

	class XCAdapter : public XCObject
	{
	public:
		XCAdapter() = default;

		XCAdapter(HXCGUI handle)
		{
			m_handle = handle;
		}
		
		// 增加引用计数()
		int AddRef() {
			return XAd_AddRef(m_handle);
		}

		// 释放引用计数()
		int Release() {
			return XAd_Release(m_handle);
		}

		// 取引用计数()
		int GetRefCount() {
			return XAd_GetRefCount(m_handle);
		}

		// 销毁()
		void Destroy() {
			XAd_Destroy(m_handle);
		}

		// 启用自动销毁()
		void EnableAutoDestroy(BOOL bEnable) {
			XAd_EnableAutoDestroy(m_handle, bEnable);
		}

	};

}