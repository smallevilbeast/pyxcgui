#pragma once
#include "pch.h"
#include <map>	 
#include <vector>
#include <functional>

#include "xcgui/window/XCWindow.hpp"
#include "XCastManager.hpp"
#include "xcgui/XCStruct.hpp"
#include "xcgui/XCResource.hpp"

namespace xcgui {
	
	

	using XResourceLoadFileCallback = std::function<bool(const std::wstring& filename)>;

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

	protected:
		bool m_bLoadFileCallbackReg;
		std::vector<XResourceLoadFileCallback> m_mResourceCallbacks;
	};
}