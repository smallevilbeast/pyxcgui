#pragma once
#include "pch.h"
#include <map>	 
#include <vector>
#include <functional>

#include "xcgui/window/XCWindow.hpp"

namespace xcgui {

	class XUserDataManager {
	public:
		SINGLETON_DEFINE(XUserDataManager);
		XUserDataManager() :
			m_none(py::none())
		{

		}
		~XUserDataManager() {
			Release();
		}


	public:
		void Release() {
			m_mData.clear();
			m_mItemData.clear();
		}
		void SetUserData(HXCGUI handle, const py::object& object) {
			m_mData[handle] = object;
		}

		void SetItemUserData(HELE handle, const std::string& item, const py::object& object) {
			m_mItemData[handle][item] = object;
		}

		py::object& getItemUserData(HELE handle, const std::string& item) {
			auto iter = m_mItemData.find(handle);
			if (iter == m_mItemData.end()) {
				return m_none;
			}
			auto& itemData = iter->second;
			auto itemIter = itemData.find(item);
			if (itemIter == itemData.end()) {
				return m_none;
			}
			return itemIter->second;
		}

		py::object& GetUserData(HXCGUI handle) {
			auto iter = m_mData.find(handle);
			if (iter == m_mData.end()) {
				return m_none;
			}
			return m_mData[handle];
		}

		void RemoveUserData(HXCGUI handle) {
			auto iter = m_mData.find(handle);
			if (iter != m_mData.end()) {
				m_mData.erase(iter);
			}
		}


	protected:
		py::object m_none;
		std::map<HXCGUI, py::object> m_mData;
		std::map<HELE, std::map<std::string, py::object>> m_mItemData;
	};
}