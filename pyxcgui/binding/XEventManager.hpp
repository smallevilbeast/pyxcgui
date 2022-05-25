#pragma once
#include "pch.h"
#include <map>	 
#include <vector>
#include <functional>

#include "xcgui/XCWindow.hpp"

#define SINGLETON_DEFINE(TypeName)				\
static TypeName* GetInstance()					\
{												\
	static TypeName type_instance;				\
	return &type_instance;						\
}												\
												\
TypeName(const TypeName&) = delete;				\
TypeName& operator=(const TypeName&) = delete

namespace xcgui {


	using XEventCallback = std::function<bool(const py::object& userdata)>;

	class XEventObject {
	public:
		XEventObject(const XEventCallback& callback, const py::object& userdata)
			: callback(callback)
			, userdata(userdata)
		{

		}
		XEventCallback callback;
		py::object userdata;
	};


	class XEventManager {
	public:
		SINGLETON_DEFINE(XEventManager);
		XEventManager() = default;
		~XEventManager() {
			Release();
		}


	public:
		bool IsReged(HXCGUI handle, int eventType) {
			auto iter = m_mEventCallbacks.find(handle);
			if (iter != m_mEventCallbacks.end() && iter->second.find(eventType) != iter->second.end()) {
				return true;
			}
			return false;
		}

		void RegWindowEvent(HWINDOW handle, int eventType, const XEventCallback& callback, const py::object& userdata)
		{
			if (!IsReged(handle, eventType))
			{
				XWnd_RegEventCPP1(handle, eventType, &XEventManager::OnGuiEventCallback);
			}

			XEventObject eventObject(callback, userdata);
			m_mEventCallbacks[handle][eventType].emplace_back(eventObject);
		}

		void RegEleEvent(HELE handle, int eventType, const XEventCallback& callback, const py::object& userdata) {
	
			if (!IsReged(handle, eventType))
			{
				XEle_RegEventCPP1(handle, eventType, &XEventManager::OnGuiEventCallback);
			}
			XEventObject eventObject(callback, userdata);
			m_mEventCallbacks[handle][eventType].emplace_back(eventObject);
		}

		void Release() {
			m_mEventCallbacks.clear();
		}

	protected:
		int OnGuiEventCallback(HXCGUI ele, UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL* pbHandled) {
			
			auto winIter = m_mEventCallbacks.find(ele);
			if (winIter != m_mEventCallbacks.end()) {
				auto& eventMap = winIter->second;
				auto eventIter = eventMap.find((int)nEvent);
				if (eventIter != eventMap.end()) {
					auto& eventList = eventIter->second;
					for (auto& event : eventList) {
						if (event.callback(event.userdata))
						{
							*pbHandled = TRUE;
							break;
						}
					}
				}
			}
			return 0;
		}


	protected:
		std::map<HXCGUI, std::map<int, std::vector<XEventObject>>> m_mEventCallbacks;
	};
}