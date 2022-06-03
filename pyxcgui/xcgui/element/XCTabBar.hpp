#pragma once
#include "pch.h"
#include "xcgui/XCElement.hpp"

namespace xcgui {

	class XCTabBar : public XCElement
	{
	public:
		XCTabBar(HELE handle)
		{
			m_handle = handle;
		}

		XCTabBar() = default;

		XCTabBar(int x, int y, int width, int height, HXCGUI parent = NULL) {
			m_handle = XTabBar_Create(x, y, width, height, parent);
		}

		//@备注 添加一个标签.  
		//@参数 name.c_str() 标签文本内容.
		//@返回 标签索引.
		//@别名  添加标签()
		int AddLabel(const std::wstring& name) {
			return XTabBar_AddLabel(getEleHandle(), name.c_str());
		}

		//@备注 插入一个标签.  
		//@参数 index 插入位置.
		//@参数 name.c_str() 标签文本内容.
		//@返回 标签索引.
		//@别名  标签()
		int InsertLabel(int index, const std::wstring& name) {
			return XTabBar_InsertLabel(getEleHandle(), index, name.c_str());
		}

		//@参数 iSrc 源位置索引
		//@参数 iDest 目标位置索引
		//@返回 成功返回TRUE否则FALSE.
		//@别名  移动标签()
		bool MoveLabel(int iSrc, int iDest) {
			return XTabBar_MoveLabel(getEleHandle(), iSrc, iDest);
		}

		//@备注 删除一个标签.  
		//@参数 index 位置索引.
		//@返回 成功返回TRUE否则FALSE.
		//@别名  删除标签()
		bool DeleteLabel(int index) {
			return XTabBar_DeleteLabel(getEleHandle(), index);
		}

		//@备注 删除所有标签.  
		//@别名  删除全部()
		void DeleteLabelAll() {
			XTabBar_DeleteLabelAll(getEleHandle());
		}

		//@备注 获取标签按钮Button.  
		//@参数 index 位置索引.
		//@返回 按钮句柄.
		//@别名  取标签()
		HELE GetLabel(int index) {
			return XTabBar_GetLabel(getEleHandle(), index);
		}

		//@备注 获取标签上关闭按钮.  
		//@参数 index 位置索引.
		//@返回 按钮句柄.
		//@别名  取标签上的关闭按钮()
		HELE GetLabelClose(int index) {
			return XTabBar_GetLabelClose(getEleHandle(), index);
		}

		//@备注 获取左滚动按钮.  
		//@返回 返回按钮句柄.
		//@别名  取左滚动按钮()
		HELE GetButtonLeft() {
			return XTabBar_GetButtonLeft(getEleHandle());
		}

		//@备注 获取右滚动按钮.  
		//@返回 返回按钮句柄.
		//@别名  取右滚动按钮()
		HELE GetButtonRight() {
			return XTabBar_GetButtonRight(getEleHandle());
		}

		//@返回 返回按钮句柄.
		//@别名  取下拉菜单按钮句柄()
		HELE GetButtonDropMenu() {
			return XTabBar_GetButtonDropMenu(getEleHandle());
		}

		//@备注 获取选择的标签索引.  
		//@返回 标签位置索引.
		//@别名  取当前选择()
		int GetSelect() {
			return XTabBar_GetSelect(getEleHandle());
		}

		//@备注 获取标签间距, 0没有间距.  
		//@返回 标签间隔大小.
		//@别名  取间隔()
		int GetLabelSpacing() {
			return XTabBar_GetLabelSpacing(getEleHandle());
		}

		//@备注 获取标签项数量.  
		//@返回 标签项数量.
		//@别名  取标签数量()
		int GetLabelCount() {
			return XTabBar_GetLabelCount(getEleHandle());
		}

		//@备注 获取标签按钮位置索引.  
		//@参数 hLabel 标签按钮句柄.
		//@返回 成功返回索引值,否则返回 @ref XC_ID_ERROR.
		//@别名  取标签位置索引()
		int GetindexByEle(HELE hLabel) {
			return XTabBar_GetindexByEle(getEleHandle(), hLabel);
		}

		//@备注 设置标签间距, 0没有间距.  
		//@参数 spacing 标签间隔大小.
		//@别名  置间隔()
		void SetLabelSpacing(int spacing) {
			XTabBar_SetLabelSpacing(getEleHandle(), spacing);
		}

		//@备注 设置内容与边框的间隔大小.  
		//@参数 left 左边间隔大小.
		//@参数 top 上边间隔大小.
		//@参数 right 右边间隔大小.
		//@参数 bottom 下边间隔大小.
		//@别名  置边距()
		void SetPadding(int left, int top, int right, int bottom) {
			XTabBar_SetPadding(getEleHandle(), left, top, right, bottom);
		}

		//@备注 设置选择标签.  
		//@参数 index 标签位置索引.
		//@别名  置选择()
		void SetSelect(int index) {
			XTabBar_SetSelect(getEleHandle(), index);
		}

		//@备注 左按钮滚动.  
		//@别名  左滚动()
		void SetUp() {
			XTabBar_SetUp(getEleHandle());
		}

		//@备注 右按钮滚动.  
		//@别名  右滚动()
		void SetDown() {
			XTabBar_SetDown(getEleHandle());
		}

		//@备注 平铺标签,每个标签显示相同大小.  
		//@参数 bTile 是否启用.
		//@别名  启用平铺()
		void EnableTile(bool bTile) {
			XTabBar_EnableTile(getEleHandle(), bTile);
		}

		//@参数 bEnable 是否启用.
		//@别名  启用下拉菜单按钮()
		void EnableDropMenu(bool bEnable) {
			XTabBar_EnableDropMenu(getEleHandle(), bEnable);
		}

		//@备注 启用关闭标签功能.  
		//@参数 bEnable 是否启用.
		//@别名  启用标签带关闭按钮()
		void EnableClose(bool bEnable) {
			XTabBar_EnableClose(getEleHandle(), bEnable);
		}

		//@备注 设置关闭按钮大小.  
		//@参数 pSize 大小值, 宽度和高度可以为-1,-1代表默认值.
		//@别名  置关闭按钮大小()
		void SetCloseSize(SIZE* pSize) {
			XTabBar_SetCloseSize(getEleHandle(), pSize);
		}

		//@备注 设置翻滚按钮大小.  
		//@参数 pSize 大小值, 宽度和高度可以为-1,-1代表默认值.
		//@别名  置滚动按钮大小()
		void SetTurnButtonSize(SIZE* pSize) {
			XTabBar_SetTurnButtonSize(getEleHandle(), pSize);
		}

		//@备注 设置指定标签为固定宽度.  
		//@参数 index 索引.
		//@参数 nWidth 宽度, 如果值为-1,那么自动计算宽度.
		//@别名  置指定标签固定宽度()
		void SetLabelWidth(int index, int nWidth) {
			XTabBar_SetLabelWidth(getEleHandle(), index, nWidth);
		}

		//@备注 显示或隐藏指定标签.  
		//@参数 index 标签索引.
		//@参数 bShow 是否显示.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  显示标签()
		bool ShowLabel(int index, bool bShow) {
			return XTabBar_ShowLabel(getEleHandle(), index, bShow);
		}

	};
}