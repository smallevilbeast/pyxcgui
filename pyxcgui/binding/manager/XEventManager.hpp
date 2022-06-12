#pragma once
#include "pch.h"
#include <map>	 
#include <vector>
#include <functional>

#include "xcgui/window/XCWindow.hpp"
#include "XCastManager.hpp"
#include "xcgui/XCStruct.hpp"
#include "XUserDataManager.hpp"
#include "XCastManager.hpp"
#include "XCallbackManager.hpp"

namespace xcgui {

	using XEventCallback = std::function<bool(const XCEvent& event, const py::object& userdata)>;

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

		void RegWindowDestroyEvent(HWINDOW handle) {
			if (!IsReged(handle, WM_DESTROY))
			{
				XWnd_RegEventCPP1(handle, WM_DESTROY, &XEventManager::OnGuiEventCallback);
			}
		}

		void RegElementDestroyEvent(HELE handle) {
			if (!IsReged(handle, XE_DESTROY_END))
			{
				XEle_RegEventCPP1(handle, XE_DESTROY_END, &XEventManager::OnGuiEventCallback);
			}
		}

		void RegDestroyEvent(HXCGUI handle) {
			if (XC_IsHWINDOW(handle)) {
				RegWindowDestroyEvent((HWINDOW)handle);
				return;
			}

			if (XC_IsHELE(handle)) {
				RegElementDestroyEvent((HELE)handle);
				return;
			}
		}

		void RegWindowEvent(HWINDOW handle, int eventType, const XEventCallback& callback, const py::object& userdata)
		{
			this->RegWindowDestroyEvent(handle);

			if (!IsReged(handle, eventType))
			{
				XWnd_RegEventCPP1(handle, eventType, &XEventManager::OnGuiEventCallback);
			}

			XEventObject eventObject(callback, userdata);
			m_mEventCallbacks[handle][eventType].emplace_back(eventObject);
		}

		void RegEleEvent(HELE handle, int eventType, const XEventCallback& callback, const py::object& userdata) {

			this->RegElementDestroyEvent(handle);

			if (!IsReged(handle, eventType))
			{
				XEle_RegEventCPP1(handle, eventType, &XEventManager::OnGuiEventCallback);
			}
			XEventObject eventObject(callback, userdata);
			m_mEventCallbacks[handle][eventType].emplace_back(eventObject);
		}

		void ReleaseByHandle(HXCGUI handle) {
			auto iter = m_mEventCallbacks.find(handle);
			if (iter != m_mEventCallbacks.end()) {
				for (auto& subIter : iter->second) {
					subIter.second.clear();
				}
				iter->second.clear();
				m_mEventCallbacks.erase(iter);
			}
			
		}

		void Release() {
			for (auto& iter : m_mEventCallbacks)
			{
				for (auto& subIter : iter.second) {
					subIter.second.clear();
				}
				iter.second.clear();
			}
			m_mEventCallbacks.clear();
		}

		void ReleaseAllByHandle(HXCGUI handle) {
			ReleaseByHandle(handle);
			XCastManager::GetInstance()->ReleaseByHandle(handle);
			XCallbackManager::GetInstance()->ReleaseByHandle(handle);
			XUserDataManager::GetInstance()->ReleaseByHandle(handle);
		}

	protected:
		
		int OnGuiEventCallback(HXCGUI ele, UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL* pbHandled) {
			
			py::gil_scoped_acquire gil;

			auto winIter = m_mEventCallbacks.find(ele);
			if (winIter != m_mEventCallbacks.end()) {
				auto& eventMap = winIter->second;
				auto eventIter = eventMap.find((int)nEvent);
				if (eventIter != eventMap.end()) {
					auto& eventList = eventIter->second;
					for (auto& eventObj : eventList) {
						auto pSender = XCastManager::GetInstance()->CastObject(ele);
						
						XCEvent event;
						event.eventType = nEvent;
						event.sender = nullptr;
						event.wParam = (uintptr_t)wParam;
						event.lParam = (uintptr_t)lParam;
													  
						
						if (eventObj.callback(event, eventObj.userdata))
						{
						
							*pbHandled = TRUE;
							break;
						}
					}
				}
			}
			if (nEvent == WM_DESTROY || nEvent == XE_DESTROY_END) {
				this->ReleaseByHandle(ele);
			}
			
			return 0;
		}


	protected:
		std::map<HXCGUI, std::map<int, std::vector<XEventObject>>> m_mEventCallbacks;
	};
}