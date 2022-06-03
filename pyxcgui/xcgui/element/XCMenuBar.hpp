#pragma once
#include "pch.h"
#include "xcgui/XCElement.hpp"

namespace xcgui {

	class XCMenuBar : public XCElement
	{
	public:
		XCMenuBar(HELE handle)
		{
			m_handle = handle;
		}

		XCMenuBar() = default;

		XCMenuBar(int x, int y, int width, int height, HXCGUI parent = NULL) {
			m_handle = XMenuBar_Create(x, y, width, height, parent);
		}

		//@备注 添加弹出菜单按钮.  
		 //@参数 pText 文本内容.
		 //@返回 返回菜单按钮索引.
		 //@别名  添加按钮()
		int AddButton(const std::wstring& text) {
			return XMenuBar_AddButton(getEleHandle(), text.c_str());
		}

		//@备注 设置菜单按钮高度.  
		//@参数 height 高度.
		//@别名  置按钮高度()
		void SetButtonHeight(int height) {
			XMenuBar_SetButtonHeight(getEleHandle(), height);
		}

		//@备注 获取菜单.  
		//@参数 nIndex 菜单条上菜单按钮的索引.
		//@返回 返回菜单句柄.
		//@别名  取菜单()
		HMENUX GetMenu(int nIndex) {
			return XMenuBar_GetMenu(getEleHandle(), nIndex);
		}

		//@参数 nIndex 菜单条上菜单按钮的索引
		//@返回 返回按钮句柄
		//@别名  取菜单按钮()
		HELE GetButton(int nIndex) {
			return XMenuBar_GetButton(getEleHandle(), nIndex);
		}

		//@备注 删除菜单条上的菜单按钮,同时该按钮下的弹出菜单也被销毁.  
		//@参数 nIndex 菜单条按钮索引.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  删除按钮()
		bool DeleteButton(int nIndex) {
			return XMenuBar_DeleteButton(getEleHandle(), nIndex);
		}

		//@备注 根据内容自动调整宽度
		//@参数 bEnable 是否启用.
		//@别名  启用自动宽度()
		void EnableAutoWidth(bool bEnable) {
			XMenuBar_EnableAutoWidth(getEleHandle(), bEnable);
		}

	};
}
