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
		XUserDataManager() = default;
		~XUserDataManager() {
			Release();
		}


	public:
		void Release() {
			m_mData.clear();
		}
		void SetUserData(HXCGUI handle, const py::object& object) {
			m_mData[handle] = object;
		}
		py::object& GetUserData(HXCGUI handle) {
			auto iter = m_mData.find(handle);
			if (iter == m_mData.end()) {
				m_mData[handle] = py::none();
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
		std::map<HXCGUI, py::object> m_mData;
	};
}