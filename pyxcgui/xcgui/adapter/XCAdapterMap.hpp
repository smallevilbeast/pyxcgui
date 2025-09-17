#pragma once

#include "pch.h"
#include "xcgui/adapter/XCAdapter.hpp"

namespace xcgui {

	class XCAdapterMap : public XCAdapter
	{
	public:
		XCAdapterMap(HXCGUI handle) {
			m_handle = handle;
		}

		XCAdapterMap() {
			m_handle = XAdMap_Create();
		}

		/// @brief 增加数据项. 
		/// @param name.c_str() 字段称. 
		/// @param value.c_str() 值. 
		/// @return 成功返回TRUE否则返回FALSE. 

		bool AddItemText(const std::wstring& name, const std::wstring& value)
		{
			return XAdMap_AddItemText(m_handle, name.c_str(), value.c_str());
		}

		/// @brief 添加项图片. 
		/// @param name.c_str() 图片句柄. 
		/// @param hImage 图片句柄. 
		/// @return 成功返回TRUE否则返回FALSE. 
		bool AddItemImage(const std::wstring& name, HIMAGE hImage)
		{
			return XAdMap_AddItemImage(m_handle, name.c_str(), hImage);;
		}

		/// @brief 删除项
		/// @param name.c_str() 字段称. 
		/// @return 成功返回TRUE否则返回FALSE. 
		bool DeleteItem(const std::wstring& name)
		{
			return XAdMap_DeleteItem(m_handle, name.c_str());
		}
		/// @brief 取项数量 
		/// @return 取项数量 
		int GetCount()
		{
			return XAdMap_GetCount(m_handle);
		}

		/// @brief 取项文本 
		/// @param name.c_str() 字段称.  
		/// @return 返回文本内容.
		std::wstring GetItemText(const std::wstring& name)
		{
			auto pText = XAdMap_GetItemText(m_handle, name.c_str());
			if (!pText) return L"";
			return pText;
		}
		/// @brief 返回文本内容.
		/// @param name.c_str() 字段称. 
		/// @return 返回图片句柄. 
		HIMAGE GetItemImage(const std::wstring& name)
		{
			return XAdMap_GetItemImage(m_handle, name.c_str());
		}

		/// @brief 置项文本 
		/// @param name.c_str() 字段称. 
		/// @param value.c_str() 值. 
		/// @return 成功返回TRUE否则返回FALSE.  
		bool SetItemText(const std::wstring& name, const std::wstring& value)
		{
			return XAdMap_SetItemText(m_handle, name.c_str(), value.c_str());
		}
		/// @brief 置项图片 
		/// @param name.c_str() 置项图片 
		/// @param hImage 置项图片 
		/// @return 成功返回TRUE否则返回FALSE. 
		bool SetItemImage(const std::wstring& name, HIMAGE hImage)
		{
			return XAdMap_SetItemImage(m_handle, name.c_str(), hImage);
		}
	};
}
