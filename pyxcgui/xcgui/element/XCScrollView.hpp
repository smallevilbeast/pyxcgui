#pragma once
#include "pch.h"
#include "xcgui/XCElement.hpp"

namespace xcgui {

	class XCScrollView : virtual public XCElement
	{
	public:
		XCScrollView(HELE handle)
		{
			m_handle = handle;
		}

		XCScrollView() = default;

		XCScrollView(int x, int y, int width, int height, HXCGUI parent = NULL) {
			m_handle = XSView_Create(x, y, width, height, parent);
		}

		//@备注 设置内容大小.  
		//@参数 cx 宽度.
		//@参数 cy 高度.
		//@返回 如果内容改变返回TRUE否则返回FALSE.
		//@别名  置视图大小()
		bool SetTotalSize(int cx, int cy) {
			return XSView_SetTotalSize(getEleHandle(), cx, cy);
		}

		//@备注 获取内容总大小.  
		//@参数 pSize 大小.
		//@别名  取视图大小()
		void GetTotalSize(SIZE* pSize) {
			XSView_GetTotalSize(getEleHandle(), pSize);
		}

		//@备注 设置滚动单位大小.  
		//@参数 nWidth 宽度.
		//@参数 nHeight 高度.
		//@返回 如果内容改变返回TRUE否则返回FALSE.
		//@别名  置滚动单位大小()
		bool SetLineSize(int nWidth, int nHeight) {
			return XSView_SetLineSize(getEleHandle(), nWidth, nHeight);
		}

		//@备注 获取滚动单位大小.  
		//@参数 pSize 返回大小.
		//@别名  取滚动单位大小()
		void GetLineSize(SIZE* pSize) {
			XSView_GetLineSize(getEleHandle(), pSize);
		}

		//@备注 设置滚动条大小.  
		//@参数 size 滚动条大小.
		//@别名  置滚动条大小()
		void SetScrollBarSize(int size) {
			XSView_SetScrollBarSize(getEleHandle(), size);
		}

		//@备注 获取视口原点X坐标.  
		//@返回 视口原点X坐标.
		//@别名  取视口原点X()
		int GetViewPosH() {
			return XSView_GetViewPosH(getEleHandle());
		}

		//@备注 获取视口原点Y坐标.  
		//@返回 视口原点Y坐标.
		//@别名  取视口原点Y()
		int GetViewPosV() {
			return XSView_GetViewPosV(getEleHandle());
		}

		//@备注 获取视口宽度.  
		//@返回 返回视口宽度.
		//@别名  取视口宽度()
		int GetViewWidth() {
			return XSView_GetViewWidth(getEleHandle());
		}

		//@备注 获取视口高度.  
		//@返回 返回视口高度.
		//@别名  取视口高度()
		int GetViewHeight() {
			return XSView_GetViewHeight(getEleHandle());
		}

		//@备注 获取视口坐标.  
		//@参数 pRect 坐标.
		//@别名  取视口坐标()
		void GetViewRect(RECT* pRect) {
			XSView_GetViewRect(getEleHandle(), pRect);
		}

		//@备注 获取水平滚动条.  
		//@返回 滚动条句柄.
		//@别名  取水平滚动条()
		HELE GetScrollBarH() {
			return XSView_GetScrollBarH(getEleHandle());
		}

		//@备注 获取垂直滚动条.  
		//@返回 垂直滚动条句柄.
		//@别名  取垂直滚动条()
		HELE GetScrollBarV() {
			return XSView_GetScrollBarV(getEleHandle());
		}

		//@备注 水平滚动条,滚动到指定位置点.  
		//@参数 pos 位置点.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  水平滚动()
		bool ScrollPosH(int pos) {
			return XSView_ScrollPosH(getEleHandle(), pos);
		}

		//@备注 垂直滚动条,滚动到指定位置点.  
		//@参数 pos 位置点.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  垂直滚动()
		bool ScrollPosV(int pos) {
			return XSView_ScrollPosV(getEleHandle(), pos);
		}

		//@备注 水平滚动条,滚动到指定坐标.  
		//@参数 posX X坐标.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  水平滚动到X()
		bool ScrollPosXH(int posX) {
			return XSView_ScrollPosXH(getEleHandle(), posX);
		}

		//@备注 垂直滚动条,滚动到指定坐标.  
		//@参数 posY Y坐标.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  垂直滚动到Y()
		bool ScrollPosYV(int posY) {
			return XSView_ScrollPosYV(getEleHandle(), posY);
		}

		//@备注 显示水平滚动条.  
		//@参数 bShow 是否显示.
		//@别名  显示水平滚动条()
		void ShowSBarH(bool bShow) {
			XSView_ShowSBarH(getEleHandle(), bShow);
		}

		//@备注 显示垂直滚动条.  
		//@参数 bShow 是否显示.
		//@别名  显示垂直滚动条()
		void ShowSBarV(bool bShow) {
			XSView_ShowSBarV(getEleHandle(), bShow);
		}

		//@备注 启用自动显示滚动条.  
		//@参数 bEnable 是否启用.
		//@别名  启用自动显示滚动条()
		void EnableAutoShowScrollBar(bool bEnable) {
			XSView_EnableAutoShowScrollBar(getEleHandle(), bEnable);
		}

		//@备注 向左滚动.  
		//@返回 如果成功返回TRUE,否则相反.
		//@别名  向左滚动()
		bool ScrollLeftLine() {
			return XSView_ScrollLeftLine(getEleHandle());
		}

		//@备注 向右滚动.  
		//@返回 如果成功返回TRUE,否则相反.
		//@别名  向右滚动()
		bool ScrollRightLine() {
			return XSView_ScrollRightLine(getEleHandle());
		}

		//@备注 向上滚动.  
		//@返回 如果成功返回TRUE,否则相反.
		//@别名  向上滚动()
		bool ScrollTopLine() {
			return XSView_ScrollTopLine(getEleHandle());
		}

		//@备注 向下滚动.  
		//@返回 如果成功返回TRUE,否则相反.
		//@别名  向下滚动()
		bool ScrollBottomLine() {
			return XSView_ScrollBottomLine(getEleHandle());
		}

		//@备注 水平滚动到左侧.  
		//@返回 如果成功返回TRUE,否则相反.
		//@别名  滚动到左侧()
		bool ScrollLeft() {
			return XSView_ScrollLeft(getEleHandle());
		}

		//@备注 水平滚动到右侧.  
		//@返回 如果成功返回TRUE,否则相反.
		//@别名  滚动到右侧()
		bool ScrollRight() {
			return XSView_ScrollRight(getEleHandle());
		}

		//@备注 垂直滚动到顶部.  
		//@返回 如果成功返回TRUE,否则相反.
		//@别名  滚动到顶部()
		bool ScrollTop() {
			return XSView_ScrollTop(getEleHandle());
		}

		//@备注 垂直滚动到底部.  
		//@返回 如果成功返回TRUE,否则相反.
		//@别名  滚动到底部()
		bool ScrollBottom() {
			return XSView_ScrollBottom(getEleHandle());
		}

	};
}