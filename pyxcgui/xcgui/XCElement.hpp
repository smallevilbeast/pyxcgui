#pragma once
#include "pch.h"
#include "XCWidget.hpp"

namespace xcgui {

	class XCElement : virtual public XCWidget
	{
	public:
		XCElement()
			: XCWidget()
		{
		}


		XCElement(HXCGUI ele)
		{
			m_handle = ele;
		}


		HELE getEleHandle() const
		{
			return (HELE)m_handle;
		}


		// 创建基础元素
		XCElement(int x, int y, int cx, int cy, HXCGUI hParent = NULL) 
		:XCWidget()
		{
			m_handle = XEle_Create(x, y, cx, cy, hParent);
		}


		HELE Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL) {
			m_handle = XEle_Create(x, y, cx, cy, hParent); 
			return (HELE)m_handle;
		}


		// 发送事件.  
		int SendEvent(int nEvent, WPARAM wParam, LPARAM lParam) {
			return XEle_SendEvent((HELE)m_handle, nEvent, wParam, lParam);
		}


		// POST事件.  
		bool PostEvent(int nEvent, WPARAM wParam, LPARAM lParam) {
			return XEle_PostEvent((HELE)m_handle, nEvent, wParam, lParam);
		}


		// 获取元素坐标.  
		void GetRect(RECT* pRect) {
			XEle_GetRect((HELE)m_handle, pRect);
		}


		// 获取元素坐标,逻辑坐标,包含滚动视图偏移.  
		void GetRectLogic(RECT* pRect) {
			XEle_GetRectLogic((HELE)m_handle, pRect);
		}


		// 获取元素客户区坐标. 
		void GetClientRect(RECT* pRect) {
			XEle_GetClientRect((HELE)m_handle, pRect);
		}


		// 设置宽度  
		void SetWidth(int nWidth) {
			XEle_SetWidth((HELE)m_handle, nWidth);
		}


		// 设置高度   
		void SetHeight(int nHeight) {
			XEle_SetHeight((HELE)m_handle, nHeight);
		}


		// 获取元素宽度.  
		int GetWidth() {
			return XEle_GetWidth((HELE)m_handle);
		}


		// 获取元素高度.  
		int GetHeight() {
			return XEle_GetHeight((HELE)m_handle);
		}


		// 窗口客户区坐标转换到元素客户区坐标.  
		void RectWndClientToEleClient(RECT* pRect) {
			XEle_RectWndClientToEleClient((HELE)m_handle, pRect);
		}


		// 窗口客户区坐标转换到元素客户区坐标.  
		void PointWndClientToEleClient(POINT* pPt) {
			XEle_PointWndClientToEleClient((HELE)m_handle, pPt);
		}


		// 元素客户区坐标转换到窗口客户区坐标.  
		//@参数 pRect 坐标.
		//@别名  客户区坐标到窗口客户区()
		void RectClientToWndClient(RECT* pRect) {
			XEle_RectClientToWndClient((HELE)m_handle, pRect);
		}

		// 元素客户区坐标转换到窗口客户区坐标.  
		//@参数 pPt 坐标.
		//@别名  客户区点到窗口客户区()
		void PointClientToWndClient(POINT* pPt) {
			XEle_PointClientToWndClient((HELE)m_handle, pPt);
		}		  

		bool PointClientToScreen(in_out_ POINT* pPt, position_flag_ flag = position_flag_leftBottom, 
			int xOffset = 0, int yOffset = 0) {
			
			RECT rect;
			this->GetRect(&rect);
			switch (flag)
			{
			case position_flag_leftBottom:
			{
				pPt->x = rect.left;
				pPt->y = rect.bottom;
				break;
			}
			case position_flag_leftTop:
			{
				pPt->x = rect.left;
				pPt->y = rect.top;
				break;
			}		
			case position_flag_rightTop:
			{
				pPt->x = rect.right;
				pPt->y = rect.top;
				break;
			}
				
			case position_flag_rightBottom:
			{
				pPt->x = rect.right;
				pPt->y = rect.bottom;
				break;
			}
				
			case position_flag_center:
			{
				pPt->x = rect.left + (rect.right - rect.left) / 2;
				pPt->y = rect.top + (rect.bottom - rect.top) / 2;
				break;
			}
			default:
				break;
			}
			pPt->x += xOffset;
			pPt->y += yOffset;

			return ::ClientToScreen((HWND)GetHWND(), pPt);
		}

		// 元素基于窗口客户区坐标.  
		//@参数 pRect 坐标.
		//@别名  基于窗口客户区坐标()
		void GetWndClientRect(RECT* pRect) {
			XEle_GetWndClientRect((HELE)m_handle, pRect);
		}

		// 获取元素鼠标光标.  
		//@返回 返回光标句柄.
		//@别名  取光标()
		HCURSOR GetCursor() {
			return XEle_GetCursor((HELE)m_handle);
		}

		// 设置元素鼠标光标.  
		//@参数 hCursor 光标句柄.
		//@别名  置光标()
		void SetCursor(HCURSOR hCursor) {
			XEle_SetCursor((HELE)m_handle, hCursor);
		}

		// 添加子对象. 
		//@参数 hChild 要添加的子元素句柄或形状对象句柄.
		//@返回 如果成功返回TRUE,否则相反.
		//@别名  添加子对象()
		bool AddChild(HXCGUI hChild) {
			return XEle_AddChild((HELE)m_handle, hChild);
		}

		// 插入子对象到指定位置.  
		//@参数 hChild 要插入的元素句柄或形状对象句柄.
		//@参数 index 插入位置索引.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  插入子对象()
		bool InsertChild(HXCGUI hChild, int index) {
			return XEle_InsertChild((HELE)m_handle, hChild, index);
		}

		// 设置元素坐标.  
		//@参数 pRect 坐标.
		//@参数 bRedraw 是否重绘.
		//@参数 nFlags 调整布局标识位, @ref adjustLayout_
		//@参数 nAdjustNo 调整布局流水号
		//@返回 如果返回0坐标没有改变,如果大小改变返回2(触发XE_SIZE), 否则返回1(仅改变left,top,没有改变大小).
		//@别名  置坐标()
		int SetRect(const XCRect& rect, bool bRedraw = false, int nFlags = adjustLayout_all, UINT nAdjustNo = 0) {
			return XEle_SetRect((HELE)m_handle, (RECT*)&rect, bRedraw, nFlags, nAdjustNo);
		}

		// 设置元素坐标.  
		//@参数 x X坐标.
		//@参数 y Y坐标.
		//@参数 cx 宽度.
		//@参数 cy 高度.
		//@参数 bRedraw 是否重绘.
		//@参数 nFlags 调整布局标识位, @ref adjustLayout_
		//@参数 nAdjustNo 调整布局流水号
		//@返回 如果坐标未改变返回0,如果大小改变返回2(触发XE_SIZE), 否则返回1.
		//@别名  置坐标扩展()
		int SetRectEx(int x, int y, int cx, int cy, bool bRedraw = false, int nFlags = adjustLayout_all, UINT nAdjustNo = 0) {
			return XEle_SetRectEx((HELE)m_handle, x, y, cx, cy, bRedraw, nFlags, nAdjustNo);
		}

		// 设置元素坐标,逻辑坐标,包含滚动视图偏移.  
		//@参数 pRect 坐标.
		//@参数 bRedraw 是否重绘.
		//@参数 nFlags 参数将被带入 XE_SIZE ,XE_ADJUSTLAYOUT 事件回调.@ref adjustLayout_
		//@参数 nAdjustNo 调整布局流水号
		//@返回 如果坐标未改变返回0,如果大小改变返回2(触发XE_SIZE), 否则返回1.
		//@别名  置逻辑坐标()
		int SetRectLogic(const XCRect& rect, bool bRedraw = false, int nFlags = adjustLayout_all, UINT nAdjustNo = 0) {
			return XEle_SetRectLogic((HELE)m_handle, (RECT*)&rect, bRedraw, nFlags, nAdjustNo);
		}

		// 移动元素坐标
		//@参数 x X坐标.
		//@参数 y Y坐标.
		//@参数 bRedraw 是否重绘.
		//@参数 nFlags 调整布局标识位, @ref adjustLayout_
		//@参数 nAdjustNo 调整布局流水号
		//@返回 如果坐标未改变返回0,如果大小改变返回2(触发XE_SIZE), 否则返回1.
		//@别名  置位置()
		int SetPosition(int x, int y, bool bRedraw = false, int nFlags = adjustLayout_all, UINT nAdjustNo = 0) {
			return XEle_SetPosition((HELE)m_handle, x, y, bRedraw, nFlags, nAdjustNo);
		}

		// 移动元素坐标;  逻辑坐标,包含滚动视图偏移
		//@参数 x X坐标.
		//@参数 y Y坐标.
		//@参数 bRedraw 是否重绘.
		//@参数 nFlags 调整布局标识位, @ref adjustLayout_
		//@参数 nAdjustNo 调整布局流水号
		//@返回 如果坐标未改变返回0,如果大小改变返回2(触发XE_SIZE), 否则返回1.
		//@别名  置位置逻辑()
		int SetPositionLogic(int x, int y, bool bRedraw = false, int nFlags = adjustLayout_all, UINT nAdjustNo = 0) {
			return XEle_SetPositionLogic((HELE)m_handle, x, y, bRedraw, nFlags, nAdjustNo);
		}

		//@参数 pOutX 返回X坐标
		//@参数 pOutY 返回Y坐标
		//@别名  取位置()
		void GetPosition(int* pOutX, int* pOutY) {
			XEle_GetPosition((HELE)m_handle, pOutX, pOutY);
		}

		//@参数 nWidth 宽度
		//@参数 nHeight 高度
		//@参数 bRedraw 是否重绘
		//@参数 nFlags 调整布局标识位, @ref adjustLayout_
		//@参数 nAdjustNo 调整布局流水号
		//@别名  置大小()
		int SetSize(int nWidth, int nHeight, bool bRedraw = false, int nFlags = adjustLayout_all, UINT nAdjustNo = 0) {
			return XEle_SetSize((HELE)m_handle, nWidth, nHeight, bRedraw, nFlags, nAdjustNo);
		}

		//@参数 pOutWidth 返回宽度
		//@参数 pOutHeight 返回高度
		//@别名  取大小()
		void GetSize(int* pOutWidth, int* pOutHeight) {
			XEle_GetSize((HELE)m_handle, pOutWidth, pOutHeight);
		}

		// 元素是否绘制焦点.  
		//@返回 如果绘制焦点返回TRUE否则返回FALSE.
		//@别名  是否绘制焦点()
		bool IsDrawFocus() {
			return XEle_IsDrawFocus((HELE)m_handle);
		}

		// 元素是否为启用状态.  
		//@返回 如果启用状态返回TRUE否则返回FALSE.
		//@别名  是否启用()
		bool IsEnable() {
			return XEle_IsEnable((HELE)m_handle);
		}

		// 元素是否启用焦点.  
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  是否启用焦点()
		bool IsEnableFocus() {
			return XEle_IsEnableFocus((HELE)m_handle);
		}

		// 元素是否启用鼠标穿透.  
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  是否鼠标穿透()
		bool IsMouseThrough() {
			return XEle_IsMouseThrough((HELE)m_handle);
		}

		// 检测坐标点所在元素,包含子元素的子元素.  
		//@参数 pPt 坐标点.
		//@返回 成功返回元素句柄,否则返回NULL.
		//@别名  测试点击元素()
		HELE HitChildEle(POINT* pPt) {
			return XEle_HitChildEle((HELE)m_handle, pPt);
		}

		// 是否背景透明. 
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  是否背景透明()
		bool IsBkTransparent() {
			return XEle_IsBkTransparent((HELE)m_handle);
		}

		// 是否启XE_PAINT_END用事件.  
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  是否启用事件_XE_PAINT_END()
		bool IsEnableEvent_XE_PAINT_END() {
			return XEle_IsEnableEvent_XE_PAINT_END((HELE)m_handle);
		}

		// 是否接受Tab键输入; 例如: XRichEdit, XEdit  
		//@返回 是返回TRUE否则返回FALSE
		//@别名  是否接受TAB()
		bool IsKeyTab() {
			return XEle_IsKeyTab((HELE)m_handle);
		}

		// 是否接受通过键盘切换焦点(方向键,TAB键).  
		//@返回 是返回TRUE否则返回FALSE.
		//@别名  是否接受切换焦点()
		bool IsSwitchFocus() {
			return XEle_IsSwitchFocus((HELE)m_handle);
		}

		// 判断是否启用鼠标滚动事件,如果禁用那么事件会发送给他的父元素.  
		//@返回 是返回TRUE否则返回FALSE.
		//@别名  是否启用_XE_MOUSEWHEEL()
		bool IsEnable_XE_MOUSEWHEEL() {
			return XEle_IsEnable_XE_MOUSEWHEEL((HELE)m_handle);
		}

		// 判断hChildEle是否为hEle的子元素,   
		//@参数 hChildEle 子元素句柄
		//@返回 是返回TRUE否则返回FALSE.
		//@别名  是否为子元素()
		bool IsChildEle(HELE hChildEle) {
			return XEle_IsChildEle((HELE)m_handle, hChildEle);
		}

		// 判断是否启用画布,  
		//@返回 是返回TRUE否则返回FALSE.
		//@别名  是否启用画布()
		bool IsEnableCanvas() {
			return XEle_IsEnableCanvas((HELE)m_handle);
		}

		// 判断是否拥有焦点.  
		//@返回 如果拥有焦点返回TRUE,否则返回FALSE.
		//@别名  是否焦点()
		bool IsFocus() {
			return XEle_IsFocus((HELE)m_handle);
		}

		// 判断该元素或该元素的子元素是否拥有焦点  
		//@返回 如果拥有焦点返回TRUE,否则返回FALSE.
		//@别名  是否焦点扩展()
		bool IsFocusEx() {
			return XEle_IsFocusEx((HELE)m_handle);
		}

		// 启用或禁用元素.  
		//@参数 bEnable 启用或禁用.
		//@别名  启用()
		void Enable(bool bEnable) {
			XEle_Enable((HELE)m_handle, bEnable);
		}

		// 启用焦点.  
		//@参数 bEnable 是否启用.
		//@别名  启用焦点()
		void EnableFocus(bool bEnable) {
			XEle_EnableFocus((HELE)m_handle, bEnable);
		}

		// 启用绘制焦点.  
		//@参数 bEnable 是否启用.
		//@别名  启用绘制焦点()
		void EnableDrawFocus(bool bEnable) {
			XEle_EnableDrawFocus((HELE)m_handle, bEnable);
		}

		// 启用或禁用绘制默认边框.  
		//@参数 bEnable 是否启用.
		//@别名  启用绘制边框()
		void EnableDrawBorder(bool bEnable) {
			XEle_EnableDrawBorder((HELE)m_handle, bEnable);
		}

		// 启用或禁用背景画布;如果禁用那么将绘制在父的画布之上,也就是说他没有自己的画布.  
		//@参数 bEnable 是否启用.
		//@别名  启用画布()
		void EnableCanvas(bool bEnable) {
			XEle_EnableCanvas((HELE)m_handle, bEnable);
		}

		// 启用XE_PAINT_END事件.  
		//@参数 bEnable 是否启用.
		//@别名  启用事件_XE_PAINT_END()
		void EnableEvent_XE_PAINT_END(bool bEnable) {
			XEle_EnableEvent_XE_PAINT_END((HELE)m_handle, bEnable);
		}

		// 启用背景透明.  
		//@参数 bEnable 是否启用.
		//@别名  启用背景透明()
		void EnableBkTransparent(bool bEnable) {
			XEle_EnableBkTransparent((HELE)m_handle, bEnable);
		}

		// 启用鼠标穿透, 如果启用,那么该元素不能接收到鼠标事件,但是他的子元素不受影响,任然可以接收鼠标事件.  
		//@参数 bEnable 是否启用.
		//@别名  启用鼠标穿透()
		void EnableMouseThrough(bool bEnable) {
			XEle_EnableMouseThrough((HELE)m_handle, bEnable);
		}

		// 启用接收Tab输入.  
		//@参数 bEnable 是否启用.
		//@别名  启用接收TAB()
		void EnableKeyTab(bool bEnable) {
			XEle_EnableKeyTab((HELE)m_handle, bEnable);
		}

		// 启用接受通过键盘切换焦点.  
		//@参数 bEnable 是否启用.
		//@别名  启用切换焦点()
		void EnableSwitchFocus(bool bEnable) {
			XEle_EnableSwitchFocus((HELE)m_handle, bEnable);
		}

		// 启用接收鼠标滚动事件,如果禁用那么事件会传递给父元素.  
		//@参数 bEnable 是否启用.
		//@别名  启用事件_XE_MOUSEWHEEL()
		void EnableEvent_XE_MOUSEWHEEL(bool bEnable) {
			XEle_EnableEvent_XE_MOUSEWHEEL((HELE)m_handle, bEnable);
		}

		// 移除元素,但不销毁.  
		//@别名  移除()
		void Remove() {
			XEle_Remove((HELE)m_handle);
		}

		// 设置元素Z序.  
		//@参数 index 位置索引.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置Z序()
		bool SetZOrder(int index) {
			return XEle_SetZOrder((HELE)m_handle, index);
		}

		// 设置元素Z序.  
		//@参数 hDestEle 目标元素.
		//@参数 nType 类型.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置Z序扩展()
		bool SetZOrderEx(HELE hDestEle, zorder_ nType) {
			return XEle_SetZOrderEx((HELE)m_handle, hDestEle, nType);
		}

		// 获取元素Z序索引, 位置索引.  
		//@返回 成功返回索引值,否则返回 XC_ID_ERROR.
		//@别名  取Z序()
		int GetZOrder() {
			return XEle_GetZOrder((HELE)m_handle);
		}

		// 设置元素置顶.  
		//@参数 bTopmost 是否置顶显示
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  启用置顶()
		bool EnableTopmost(bool bTopmost) {
			return XEle_EnableTopmost((HELE)m_handle, bTopmost);
		}

		// 重绘元素.  
		//@参数 bImmediate 是否立即重绘,默认为否.
		//@别名  重绘()
		void Redraw(bool bImmediate = false) {
			XEle_Redraw((HELE)m_handle, bImmediate);
		}

		// 重绘元素指定区域.  
		//@参数 pRect 相对于元素客户区坐标.
		//@参数 bImmediate 是否立即重绘,默认为否.
		//@别名  重绘指定区域()
		void RedrawRect(RECT* pRect, bool bImmediate = false) {
			XEle_RedrawRect((HELE)m_handle, pRect, bImmediate);
		}

		// 获取子对象(UI元素和形状对象)数量,只检测当前层子对象.  
		//@返回 子元素数量.
		//@别名  取子对象数量()
		int GetChildCount() {
			return XEle_GetChildCount((HELE)m_handle);
		}

		// 获取子对象通过索引,只检测当前层子对象.  
		//@参数 index 索引.
		//@返回 对象句柄.
		//@别名  取子对象从索引()
		HXCGUI GetChildByIndex(int index) {
			return XEle_GetChildByIndex((HELE)m_handle, index);
		}

		// 获取子对象通过ID,只检测当前层子对象.  
		//@参数 nID 元素ID.
		//@返回 对象句柄.
		//@别名  取子对象从ID()
		HXCGUI GetChildByID(int nID) {
			return XEle_GetChildByID((HELE)m_handle, nID);
		}

		// 设置边框大小.  
		//@参数 left 左边大小.
		//@参数 top 上边大小.
		//@参数 right 右边大小.
		//@参数 bottom 下边大小.
		//@别名  置边框大小()
		void SetBorderSize(int left, int top, int right, int bottom) {
			XEle_SetBorderSize((HELE)m_handle, left, top, right, bottom);
		}

		// 获取边框大小.  
		//@参数 pBorder 大小.
		//@别名  取边框大小()
		void GetBorderSize(borderSize_* pBorder) {
			XEle_GetBorderSize((HELE)m_handle, pBorder);
		}

		// 设置被填充大小.  
		//@参数 left 左边大小.
		//@参数 top 上边大小.
		//@参数 right 右边大小.
		//@参数 bottom 下边大小.
		//@别名  置内填充大小()
		void SetPadding(int left, int top, int right, int bottom) {
			XEle_SetPadding((HELE)m_handle, left, top, right, bottom);
		}

		// 获取内填充大小.  
		//@参数 pPadding 大小.
		//@别名  取内填充大小()
		void GetPadding(paddingSize_* pPadding) {
			XEle_GetPadding((HELE)m_handle, pPadding);
		}

		// 设置拖动边框.  
		//@参数 nFlags 边框位置组合. element_position_
		//@别名  置拖动边框()
		void SetDragBorder(int nFlags) {
			XEle_SetDragBorder((HELE)m_handle, nFlags);
		}

		// 设置拖动边框绑定元素,当拖动边框时, 自动调整绑定元素的大小.  
		//@参数 nFlags 边框位置标识,不可组合.  element_position_
		//@参数 hBindEle 绑定元素.
		//@参数 nSpace 元素间隔大小
		//@别名  置拖动边框绑定元素()
		void SetDragBorderBindEle(int nFlags, HELE hBindEle, int nSpace) {
			XEle_SetDragBorderBindEle((HELE)m_handle, nFlags, hBindEle, nSpace);
		}

		// 设置元素最小大小  
		//@参数 nWidth 最小宽度
		//@参数 nHeight 最小高度.
		//@别名  置最小大小()
		void SetMinSize(int nWidth, int nHeight) {
			XEle_SetMinSize((HELE)m_handle, nWidth, nHeight);
		}

		// 设置元素最大大小.  
		//@参数 nWidth 最大宽度.
		//@参数 nHeight 最大高度.
		//@别名  置最大大小()
		void SetMaxSize(int nWidth, int nHeight) {
			XEle_SetMaxSize((HELE)m_handle, nWidth, nHeight);
		}

		// 设置锁定元素在滚动视图中跟随滚动,如果设置TRUE将不跟随滚动.  
		//@参数 bHorizon 是否锁定水平滚动.
		//@参数 bVertical 是否锁定垂直滚动.
		//@别名  置锁定滚动()
		void SetLockScroll(bool bHorizon, bool bVertical) {
			XEle_SetLockScroll((HELE)m_handle, bHorizon, bVertical);
		}

		// 设置文本颜色.  
		//@参数 color 颜色值, 请使用宏: RGBA()
		//@别名  置文本颜色()
		void SetTextColor(COLORREF color) {
			XEle_SetTextColor((HELE)m_handle, color);
		}

		// 获取文本颜色.  
		//@返回 文本颜色值.
		//@别名  取文本颜色()
		COLORREF GetTextColor() {
			return XEle_GetTextColor((HELE)m_handle);
		}

		// 获取文本颜色,优先从资源中获取.  
		//@返回 文本颜色值.
		//@别名  取文本颜色扩展()
		COLORREF GetTextColorEx() {
			return XEle_GetTextColorEx((HELE)m_handle);
		}

		// 设置焦点边框颜色.  
		//@参数 color 颜色值, 请使用宏: RGBA()
		//@别名  置焦点边框颜色()
		void SetFocusBorderColor(COLORREF color) {
			XEle_SetFocusBorderColor((HELE)m_handle, color);
		}

		// 获取焦点边框颜色.  
		//@返回 返回颜色值
		//@别名  取焦点边框颜色()
		COLORREF GetFocusBorderColor() {
			return XEle_GetFocusBorderColor((HELE)m_handle);
		}

		// 设置元素字体.  
		//@参数 hFontx 炫彩字体.
		//@别名  置字体()
		void SetFont(HFONTX hFontx) {
			XEle_SetFont((HELE)m_handle, hFontx);
		}

		// 获取元素字体.  
		//@返回 返回炫彩字体句柄.
		//@别名  取字体()
		HFONTX GetFont() {
			return XEle_GetFont((HELE)m_handle);
		}

		// 获取元素字体,优先从资源中获取.  
		//@返回 返回炫彩字体句柄.
		//@别名  取字体扩展()
		HFONTX GetFontEx() {
			return XEle_GetFontEx((HELE)m_handle);
		}

		// 设置元素透明度.  
		//@参数 alpha 透明度.
		//@别名  置透明度()
		void SetAlpha(BYTE alpha) {
			XEle_SetAlpha((HELE)m_handle, alpha);
		}

		//@返回 返回透明度
		//@别名  取透明度()
		BYTE GetAlpha() {
			return XEle_GetAlpha((HELE)m_handle);
		}

		// 销毁元素.  
		//@别名  销毁()
		void Destroy() {
			XEle_Destroy((HELE)m_handle);
		}

		// 添加背景内容边框.  
		//@参数 nState 组合状态
		//@参数 color 颜色.
		//@参数 width 线宽.
		//@别名  添加背景边框()
		void AddBkBorder(int nState, COLORREF color, int width) {
			XEle_AddBkBorder((HELE)m_handle, nState, color, width);
		}

		// 添加背景内容填充.  
		//@参数 nState 组合状态
		//@参数 color 颜色.
		//@别名  添加背景填充()
		void AddBkFill(int nState, COLORREF color) {
			XEle_AddBkFill((HELE)m_handle, nState, color);
		}

		// 添加背景内容图片.  
		//@参数 nState 组合状态
		//@参数 hImage 图片句柄.
		//@别名  添加背景图片()
		void AddBkImage(int nState, HIMAGE hImage) {
			XEle_AddBkImage((HELE)m_handle, nState, hImage);
		}

		// 设置背景内容
		//@参数 pText 背景内容字符串
		//@返回 返回设置的背景对象数量
		//@别名  置背景()
		int SetBkInfo(const std::wstring& text) {
			return XEle_SetBkInfo((HELE)m_handle, text.c_str());
		}

		// 获取背景内容数量.  
		//@返回 返回背景内容数量.
		//@别名  取背景对象数量()
		int GetBkInfoCount() {
			return XEle_GetBkInfoCount((HELE)m_handle);
		}

		// 清空背景内容; 如果背景没有内容,将使用系统默认内容,以便保证背景正确.  
		//@别名  清空背景对象()
		void ClearBkInfo() {
			XEle_ClearBkInfo((HELE)m_handle);
		}

		// 获取元素背景管理器.  
		//@返回 背景管理器.
		//@别名  取背景管理器()
		HBKM GetBkManager() {
			return XEle_GetBkManager((HELE)m_handle);
		}

		// 获取元素背景管理器,优先从资源中获取.  
		//@返回 背景管理器.
		//@别名  取背景管理器扩展()
		HBKM GetBkManagerEx() {
			return XEle_GetBkManagerEx((HELE)m_handle);
		}

		//@参数 hBkInfoM 背景管理器
		//@别名  置背景管理器()
		void SetBkManager(HBKM hBkInfoM) {
			XEle_SetBkManager((HELE)m_handle, hBkInfoM);
		}

		// 获取组合状态.  
		//@返回 返回组合状态.
		//@别名  取状态()
		int GetStateFlags() {
			return XEle_GetStateFlags((HELE)m_handle);
		}

		// 绘制元素焦点.  
		//@参数 hDraw 图形绘制句柄.
		//@参数 pRect 区域坐标.
		//@返回 绘制成功返回TRUE,如果不需要绘制焦点返回FALSE.
		//@别名  绘制焦点()
		bool DrawFocus(HDRAW hDraw, RECT* pRect) {
			return XEle_DrawFocus((HELE)m_handle, hDraw, pRect);
		}

		// 在自绘事件函数中,用户手动调用绘制元素,以便控制绘制顺序.  
		//@参数 hDraw 图形绘制句柄.
		//@别名  绘制()
		void DrawEle(HDRAW hDraw) {
			XEle_DrawEle((HELE)m_handle, hDraw);
		}

		// 设置用户数据.  
		//@参数 nData 用户数据.
		//@别名  置用户数据()
		void SetUserData(vint nData) {
			XEle_SetUserData((HELE)m_handle, nData);
		}

		// 获取用户数据.  
		//@返回 用户数据.
		//@别名  取用户数据()
		vint GetUserData() {
			return XEle_GetUserData((HELE)m_handle);
		}

		// 获取内容大小.  
		//@参数 bHorizon 水平或垂直,  布局属性交换依赖
		//@参数 cx 宽度
		//@参数 cy 高度
		//@参数 pSize 返回大小.
		//@别名  取内容大小()
		void GetContentSize(bool bHorizon, int cx, int cy, SIZE* pSize) {
			XEle_GetContentSize((HELE)m_handle, bHorizon, cx, cy, pSize);
		}

		// 设置鼠标捕获.  
		//@参数 b TRUE设置,FALSE取消.
		//@别名  置鼠标捕获()
		void SetCapture(bool b) {
			XEle_SetCapture((HELE)m_handle, b);
		}

		// 启用或关闭元素透明通道,如果启用,将强制设置元素背景不透明,默认为启用,此功能是为了兼容GDI不支持透明通道问题.  
		//@参数 bEnable 启用或关闭.
		//@别名  启用透明通道()
		void EnableTransparentChannel(bool bEnable) {
			XEle_EnableTransparentChannel((HELE)m_handle, bEnable);
		}

		// 设置元素定时器.  
		//@参数 nIDEvent 事件ID.
		//@参数 uElapse 延时毫秒.
		//@返回 如果成功返回TRUE,否则返回FALSE.
		//@别名  置炫彩定时器()
		bool SetXCTimer(UINT nIDEvent, UINT uElapse) {
			return XEle_SetXCTimer((HELE)m_handle, nIDEvent, uElapse);
		}

		// 关闭元素定时器.  
		//@参数 nIDEvent 事件ID.
		//@返回 如果成功返回TRUE,否则返回FALSE.
		//@别名  关闭炫彩定时器()
		bool KillXCTimer(UINT nIDEvent) {
			return XEle_KillXCTimer((HELE)m_handle, nIDEvent);
		}

		// 设置工具提示内容.  
		//@参数 pText 工具提示内容.
		//@别名  置工具提示()
		void SetToolTip(const std::wstring& text) {
			XEle_SetToolTip((HELE)m_handle, text.c_str());
		}

		// 设置工具提示内容.  
		//@参数 pText 工具提示内容.
		//@参数 nTextAlign 文本对齐方式 @ref textFormatFlag_
		//@别名  置工具提示扩展()
		void SetToolTipEx(const std::wstring& text, int nTextAlign) {
			XEle_SetToolTipEx((HELE)m_handle, text.c_str(), nTextAlign);
		}

		// 获取工具提示内容.  
		//@返回 返回文本内容
		//@别名  取工具提示()
		std::wstring GetToolTip() {
			auto pTip = XEle_GetToolTip((HELE)m_handle);
			if (!pTip)
				return L"";
			return pTip;
		}

		// 弹出工具提示.  
		//@参数 x X坐标.
		//@参数 y Y坐标.
		//@别名  弹出工具提示()
		void PopupToolTip(int x, int y) {
			XEle_PopupToolTip((HELE)m_handle, x, y);
		}

		// 调整布局.  
		//@参数 nAdjustNo 调整布局流水号
		//@别名  调整布局()
		void AdjustLayout(UINT nAdjustNo = 0) {
			XEle_AdjustLayout((HELE)m_handle, nAdjustNo);
		}

		// 调整布局.    
		//@参数 nFlags 调整标识,  adjustLayout_
		//@参数 nAdjustNo 调整布局流水号
		//@别名  调整布局扩展()
		void AdjustLayoutEx(int nFlags = adjustLayout_self, UINT nAdjustNo = 0) {
			XEle_AdjustLayoutEx((HELE)m_handle, nFlags, nAdjustNo);
		}


	}
;

}

