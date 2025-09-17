#pragma once
#include "pch.h"
#include "xcgui/XCElement.hpp"

namespace xcgui {

	class XCToolBar : public XCElement
	{
	public:
		XCToolBar(HXCGUI handle)
		{
			m_handle = handle;
		}


		XCToolBar() = default;

		XCToolBar(int x, int y, int width, int height, HXCGUI parent = NULL) {
			m_handle = XToolBar_Create(x, y, width, height, parent);
		}


		//@备注 插入元素到工具条.  
		//@参数 hNewEle 将要插入的元素.
		//@参数 index 插入位置索引, (-1)插入末尾..
		//@返回 返回插入位置索引.
		//@别名  插入元素()
		int InsertEle(HELE hNewEle, int index = -1) {
			return XToolBar_InsertEle(getEleHandle(), hNewEle, index);
		}

		//@备注 插入分隔符到工具条.  
		//@参数 index 插入位置索引, (-1)插入末尾.
		//@参数 color 颜色值, 请使用宏: RGBA()
		//@返回 返回插入位置索引.
		//@别名  插入分割栏()
		int InsertSeparator(int index = -1, COLORREF color = COLORREF_MAKE(128, 128, 128, 255)) {
			return XToolBar_InsertSeparator(getEleHandle(), index, color);
		}

		//@备注 启用下拉菜单,显示隐藏的项.  
		//@参数 bEnable 是否启用.
		//@别名  启用下拉菜单()
		void EnableButtonMenu(bool bEnable) {
			XToolBar_EnableButtonMenu(getEleHandle(), bEnable);
		}

		//@备注 获取工具条上指定元素.  
		//@参数 index 索引值.
		//@返回 返回元素句柄.
		//@别名  取元素()
		HELE GetEle(int index) {
			return XToolBar_GetEle(getEleHandle(), index);
		}

		//@备注 获取左滚动按钮.  
		//@返回 返回按钮句柄.
		//@别名  取左滚动按钮()
		HELE GetButtonLeft() {
			return XToolBar_GetButtonLeft(getEleHandle());
		}

		//@备注 获取右滚动按钮.  
		//@返回 返回按钮句柄.
		//@别名  取右滚动按钮()
		HELE GetButtonRight() {
			return XToolBar_GetButtonRight(getEleHandle());
		}

		//@备注 获取菜单按钮.  
		//@返回 返回菜单按钮句柄.
		//@别名  取菜单按钮()
		HELE GetButtonMenu() {
			return XToolBar_GetButtonMenu(getEleHandle());
		}

		//@备注 设置对象之间的间距.  
		//@参数 nSize 间距大小.
		//@别名  置间距()
		void SetSpace(int nSize) {
			XToolBar_SetSpace(getEleHandle(), nSize);
		}

		//@备注 删除元素,并且销毁.  
		//@参数 index 索引值.
		//@别名  删除元素()
		void DeleteEle(int index) {
			XToolBar_DeleteEle(getEleHandle(), index);
		}

		//@备注 删除所有元素,并且销毁.  
		//@别名  删除全部()
		void DeleteAllEle() {
			XToolBar_DeleteAllEle(getEleHandle());
		}
	};
}
