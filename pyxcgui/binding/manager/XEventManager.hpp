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
			if (iter != m_mEventCallbacks.end()) {
				auto& typeMap = iter->second;
				auto subIter = typeMap.find(eventType);
				if (subIter != typeMap.end()) {
					return true;
				}
			}
			return false;
		}


		void RegWindowEvent(HWINDOW handle, int eventType, const XEventCallback& callback, const py::object& userdata)
		{

			if (!IsReged(handle, eventType))
			{
				XWnd_RegEventCPP1(handle, eventType, &XEventManager::OnGuiEventCallback);
			}

			XEventObject* eventObject =  new XEventObject(callback, userdata);
			m_mEventCallbacks[handle][eventType] = std::move(XEventItem(eventObject));
		}

		void RegEleEvent(HELE handle, int eventType, const XEventCallback& callback, const py::object& userdata) {

			if (!IsReged(handle, eventType))
			{
				XEle_RegEventCPP1(handle, eventType, &XEventManager::OnGuiEventCallback);
			}
			XEventObject* eventObject = new XEventObject(callback, userdata);
			m_mEventCallbacks[handle][eventType] = std::move(XEventItem(eventObject));
		}

		void ReleaseByHandle(HXCGUI handle) {
			auto iter = m_mEventCallbacks.find(handle);
			if (iter != m_mEventCallbacks.end()) {
				iter->second.clear();
				m_mEventCallbacks.erase(iter);
			}
			
		}

		void Release() {
			for (auto& iter : m_mEventCallbacks)
			{
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

			auto winIter = m_mEventCallbacks.find(ele);
			if (winIter != m_mEventCallbacks.end()) {
				auto& eventMap = winIter->second;
				auto eventIter = eventMap.find((int)nEvent);
				if (eventIter != eventMap.end()) {
					auto& eventItem = eventIter->second;
					auto pSender = XCastManager::GetInstance()->CastObject(ele);

					XCEvent event;
					event.eventType = nEvent;
					event.sender = pSender;
					event.wParam = (uintptr_t)wParam;
					event.lParam = (uintptr_t)lParam;

					if ((*eventIter->second.notify).callback(event, (*eventIter->second.notify).userdata))
					{

						*pbHandled = TRUE;
					}
				}
			}
			return 0;
		}


	protected:
		struct XEventItem
		{
			XEventItem(XEventObject* _notify = nullptr)
			{
				notify.reset(_notify);
			}

			XEventItem(XEventItem&& item) throw()
				: notify(std::move(item.notify))
			{
			}

			XEventItem& operator=(XEventItem&& item) throw()
			{
				if (this != &item)
					notify = std::move(item.notify);
				return *this;
			}

			std::unique_ptr<XEventObject> notify;
		};

		std::map<HXCGUI, std::map<int, XEventItem>> m_mEventCallbacks;
	};
}