#pragma once
#include "pch.h"
#include <map>	 
#include <vector>
#include <functional>

#include "xcgui/window/XCWindow.hpp"
#include "XCastManager.hpp"
#include "xcgui/XCStruct.hpp"
#include "xcgui/XCResource.hpp"
#include "xcgui/animation/XCAnimationItem.hpp"
#include "xcgui/animation/XCAnimation.hpp"

namespace xcgui {
	
	

	using XResourceLoadFileCallback = std::function<bool(const std::wstring& filename)>;
	using XAnimationItemCallback = std::function<void(XCAnimationItem* sender, float pos)>;
	using XAnimationCallback = std::function<void(XCAnimation* sender, int flag)>;

	class XCallbackManager {
	public:
		SINGLETON_DEFINE(XCallbackManager);
		XCallbackManager() {
			m_bLoadFileCallbackReg = false;
		}
		~XCallbackManager() {
			Release();
		}


	public:
		void Release() {
			m_mResourceCallbacks.clear();
			m_mAnimationItemCallbacks.clear();
			m_mAnimationCallbacks.clear();
		}

		void ReleaseByHandle(HXCGUI handle) {
			auto iter = m_mAnimationCallbacks.find(handle);
			if (iter != m_mAnimationCallbacks.end()) {
				m_mAnimationCallbacks.erase(iter);
			}

			auto iterItem = m_mAnimationItemCallbacks.find(handle);
			if (iterItem != m_mAnimationItemCallbacks.end()) {
				m_mAnimationItemCallbacks.erase(iterItem);
			}

		}
		
		static BOOL WINAPI OnLoadFileCallback(const wchar_t* pName) {
			XCallbackManager::GetInstance()->ExecLoadFileCallback(pName);
			return FALSE;
		}

		void SetLoadFileCallback(const XResourceLoadFileCallback& callback) {
			if (!m_bLoadFileCallbackReg) {
				XCResource::SetLoadFileCallback(&XCallbackManager::OnLoadFileCallback);
				m_bLoadFileCallbackReg = true;
			}


			m_mResourceCallbacks.emplace_back(callback);
		}
		
		void ExecLoadFileCallback(const std::wstring& name) {
			for (auto& callback : m_mResourceCallbacks)
			{
				if (callback(name)) {
					break;
				}
			}
		}


		// 动画项
		static void WINAPI OnAnimationItemCallback(HXCGUI hAnimationItem, float pos) {
			XCallbackManager::GetInstance()->ExecAnimationItemCallback(hAnimationItem, pos);
		}

		void SetAnimationItemCallback(HXCGUI handle, const XAnimationItemCallback& callback) {
			auto iter = m_mAnimationItemCallbacks.find(handle);
			if (iter == m_mAnimationItemCallbacks.end()) {
				XAnimaItem_SetCallback(handle, &XCallbackManager::OnAnimationItemCallback);
			}
			m_mAnimationItemCallbacks[handle] = callback;
		}

		void ExecAnimationItemCallback(HXCGUI hAnimationItem, float pos) {
			auto iter = m_mAnimationItemCallbacks.find(hAnimationItem);
			if (iter != m_mAnimationItemCallbacks.end()) {
				XCAnimationItem* pSender = dynamic_cast<XCAnimationItem*>(XCastManager::GetInstance()->CastObject(hAnimationItem));
				iter->second(pSender, pos);
			}
		}

		// 动画
		static void WINAPI OnAnimationCallback(HXCGUI hAnimation, int flag) {
			XCallbackManager::GetInstance()->ExecAnimationCallback(hAnimation, flag);
		}

		void SetAnimationCallback(HXCGUI handle, const XAnimationCallback& callback) {
			auto iter = m_mAnimationCallbacks.find(handle);
			if (iter == m_mAnimationCallbacks.end()) {
				XAnima_SetCallback(handle, &XCallbackManager::OnAnimationCallback);
			}
			m_mAnimationCallbacks[handle] = callback;
		}

		void ExecAnimationCallback(HXCGUI hAnimation, int flag) {
			auto iter = m_mAnimationCallbacks.find(hAnimation);
			if (iter != m_mAnimationCallbacks.end()) {
				XCAnimation* pSender = dynamic_cast<XCAnimation*>(XCastManager::GetInstance()->CastObject(hAnimation));
				iter->second(pSender, flag);
			}
		}

	protected:
		bool m_bLoadFileCallbackReg;
		std::vector<XResourceLoadFileCallback> m_mResourceCallbacks;
		std::map<HXCGUI, XAnimationItemCallback> m_mAnimationItemCallbacks;
		std::map<HXCGUI, XAnimationCallback> m_mAnimationCallbacks;
	};
}