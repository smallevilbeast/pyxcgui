#pragma once

#include "pch.h"
#include "XCObjectUI.hpp"  
#include "XCStruct.hpp"
#include "XCLayoutBox.hpp"

namespace xcgui {
	class XCWindow : public XCObjectUI,  public XCLayoutBox
	{
	public:

		XCWindow(HWINDOW hWindow)
			:XCObjectUI((HXCGUI)hWindow)
		{
		}

		XCWindow()
		: XCObjectUI()
		{
			auto hWindow = XWnd_Create(0, 0, 0, 0, NULL, NULL, window_style_default);
			this->SetWindowHandle(hWindow);
		}

		XCWindow(int width, int height, const std::wstring& title) 
			: XCObjectUI() 
		{
			auto hWindow = XWnd_Create(0, 0, width, height, title.c_str(), NULL, window_style_default);
			this->SetWindowHandle(hWindow);
		}

		XCWindow(int x, int y, int width, int height, const std::wstring& title, uintptr_t hWndParent = 0, int style = window_style_default)
			: XCObjectUI()
		{
			auto hWindow = XWnd_Create(x, y, width, height, title.c_str(), (HWND)hWndParent, style);
			this->SetWindowHandle(hWindow);
		}


		// hWnd 要附加的外部窗口句柄
		bool Attach(uintptr_t hWnd, int style)
		{
			auto hWindow = XWnd_Attach((HWND)hWnd, style);
			this->SetWindowHandle(hWindow);
			return hWindow;
		}

		// 	添加子对象到窗口 
		bool AddChild(const XCObjectUI& child) 
		{
			return XWnd_AddChild(GetWindowHandle(), child.GetHandle());
		}

		// 	插入子对象到指定位置
		bool InsertChild(const XCObjectUI& child, int index)
		{
			return XWnd_InsertChild(GetWindowHandle(), child.GetHandle(), index);
		}

		// 重绘窗口
		void Redraw(bool bImmediate = false)
		{
			XWnd_Redraw(GetWindowHandle(), bImmediate);
		}

		// 重绘窗口指定区域
		void RedrawRect(const XCRect& rect, bool bImmediate = false)
		{
			return XWnd_RedrawRect(GetWindowHandle(), (RECT*)&rect, bImmediate);
		}

		// 设置焦点元素
		void SetFoucsEle(const XCObjectUI& ele) 
		{
			XWnd_SetFocusEle(GetWindowHandle(), (HELE)ele.GetHandle());
		}

		// 获得拥有输入焦点的元素
		HELE GetFocusEle() const
		{
			auto winHandle = GetWindowHandle();
			if (!winHandle)
				return nullptr;

			return XWnd_GetFocusEle(winHandle);
		}

		// 获取当前鼠标所停留元素
		HELE GetStayEle() const 
		{
			auto winHandle = GetWindowHandle();
			if (!winHandle)
				return nullptr;
			return XWnd_GetStayEle(GetWindowHandle());
		}

		//  在自绘事件函数中,用户手动调用绘制窗口,以便控制绘制顺序
		void DrawWindow(HDRAW hDraw) 
		{
			XWnd_DrawWindow(GetWindowHandle(), hDraw);
		}

		// 居中窗口
		void Center() {
			XWnd_Center(GetWindowHandle());
		}

		// 居中扩展
		void CenterEx(int width, int height) {
			XWnd_CenterEx(GetWindowHandle(), width, height);
		}


		// 设置窗口鼠标光标
		void SetCursor(HCURSOR hCursor) {
			XWnd_SetCursor(GetWindowHandle(), hCursor);
		}


		// 获取窗口的鼠标光标
		HCURSOR GetCursor() { 
			return XWnd_GetCursor(GetWindowHandle());
		}

		// 获取HWND句柄
		HWND GetHWND() { 
			return XWnd_GetHWND(GetWindowHandle());
		}

		// 启用拖动窗口边框
		void EnableDragBorder(bool bEnable) { 
			XWnd_EnableDragBorder(GetWindowHandle(), bEnable);
		}

		// 启用拖动窗口
		void EnableDragWindow(bool bEnable) { 
			XWnd_EnableDragWindow(GetWindowHandle(), bEnable); 
		}

		// 启用拖动窗口标题栏
		void EnableDragCaption(bool bEnable) { 
			XWnd_EnableDragCaption(GetWindowHandle(), bEnable);
		}

		// 是否绘制窗口背景
		void EnableDrawBk(bool bEnable) {
			XWnd_EnableDrawBk(GetWindowHandle(), bEnable); 
		}

		// 启用自动焦点(当鼠标左键按下是否获得焦点.)
		void EnableAutoFocus(bool bEnable) { 
			XWnd_EnableAutoFocus(GetWindowHandle(), bEnable);
		}

		// 允许窗口最大化
		void EnableMaxWindow(bool bEnable) { 
			XWnd_EnableMaxWindow(GetWindowHandle(), bEnable);
		}

		// 限制窗口最小和最大尺寸
		void EnablemLimitWindowSize(bool bEnable) { 
			XWnd_EnablemLimitWindowSize(GetWindowHandle(), bEnable); 
		}

		// 启用拖放文件
		void EnableDragFiles(bool bEnable) { 
			XWnd_EnableDragFiles(GetWindowHandle(), bEnable);
		}

		// 启用布局功能
		void EnableLayout(bool bEnable) {
			XWnd_EnableLayout(GetWindowHandle(), bEnable);
		}

		// 启用布局覆盖边框
		void EnableLayoutOverlayBorder(bool bEnable) { 
			XWnd_EnableLayoutOverlayBorder(GetWindowHandle(), bEnable);
		}

		// 显示布局边界
		void ShowLayoutFrame(bool bEnable) { 
			XWnd_ShowLayoutFrame(GetWindowHandle(), bEnable);
		}

		// 判断是否启用布局
		bool IsEnableLayout() { 
			return XWnd_IsEnableLayout(GetWindowHandle());
		}

		// 是否最大化
		bool IsMaxWindow() { 
			return XWnd_IsMaxWindow(GetWindowHandle()); 
		}

		// 是否可拖动边框
		bool IsDragBorder() { 
			return XWnd_IsDragBorder(GetWindowHandle());
		}

		// 是否可拖动标题栏
		bool IsDragCaption() { 
			return XWnd_IsDragCaption(GetWindowHandle());
		}

		// 设置鼠标捕获元素
		void SetCaptureEle(HELE hEle) { 
			XWnd_SetCaptureEle(GetWindowHandle(), hEle);
		}

		// 获取当前鼠标捕获元素
		HELE GetCaptureEle() { 
			return XWnd_GetCaptureEle(GetWindowHandle());
		}

		// 获取重绘区域
		void GetDrawRect(RECT* pRcPaint) { 
			XWnd_GetDrawRect(GetWindowHandle(), pRcPaint);
		}

		// 	显示隐藏窗口
		void Show(bool bShow) { 
			XWnd_Show(GetWindowHandle(), bShow); 
		}

		// 显示隐藏及控制窗口最大化还原等
		bool ShowWindow(int showType = SW_SHOW)
		{
			return XWnd_ShowWindow(GetWindowHandle(), showType);
		}

		// 系统函数,设置窗口类光标句柄
		HCURSOR SetCursorSys(HCURSOR hCursor) { 
			return XWnd_SetCursorSys(GetWindowHandle(), hCursor);
		}

		// 设置窗口字体
		void SetFont(HFONTX hFontx) { 
			XWnd_SetFont(GetWindowHandle(), hFontx); 
		}

		// 设置文本颜色
		void SetTextColor(COLORREF color) { 
			XWnd_SetTextColor(GetWindowHandle(), color); 
		}

		// 获取文本颜色
		COLORREF GetTextColor() { 
			return XWnd_GetTextColor(GetWindowHandle());
		}

		// 获取文本颜色,优先从资源中获取
		COLORREF GetTextColorEx() { 
			return XWnd_GetTextColorEx(GetWindowHandle()); 
		}

		// 设置窗口ID
		void SetID(int nID) { 
			XWnd_SetID(GetWindowHandle(), nID);
		}

		// 获取窗口ID
		int GetID() { 
			return XWnd_GetID(GetWindowHandle());
		}

		// 设置窗口name
		void SetName(const std::wstring& name) { 
			XWnd_SetName(GetWindowHandle(), name.c_str());
		}

		// 获取窗口name
		std::wstring GetName() { 
			auto pName = XWnd_GetName(GetWindowHandle());
			if (!pName) {
				return L"";
			}
			return pName;
		}

		// 设置边大小
		void SetBorderSize(int left, int top, int right, int bottom) { 
			XWnd_SetBorderSize(GetWindowHandle(), left, top, right, bottom); 
		}

		// 获取边大小
		void GetBorderSize(borderSize_* pBorder) { 
			XWnd_GetBorderSize(GetWindowHandle(), pBorder);
		}

		// 置内填充大小
		void SetPadding(int left, int top, int right, int bottom) { 
			XWnd_SetPadding(GetWindowHandle(), left, top, right, bottom);
		}

		// 设置窗口拖动边框大小
		void SetDragBorderSize(int left, int top, int right, int bottom) { 
			XWnd_SetDragBorderSize(GetWindowHandle(), left, top, right, bottom);
		}

		// 获取窗口拖动边框大小
		void GetDragBorderSize(borderSize_* pSize) { 
			XWnd_GetDragBorderSize(GetWindowHandle(), pSize); 
		}

		//  置标题外间距
		void SetCaptionMargin(int left, int top, int right, int bottom) { 
			XWnd_SetCaptionMargin(GetWindowHandle(), left, top, right, bottom);
		}

		// 设置窗口的最小宽度和高度
		void SetMinimumSize(int width, int height) { 
			XWnd_SetMinimumSize(GetWindowHandle(), width, height); 
		}

		// 检测所在元素
		HELE HitChildEle(POINT* pPt) { 
			return XWnd_HitChildEle(GetWindowHandle(), pPt);
		}

		// 获取当前层子对象数量,不包含子元素的子元素
		int GetChildCount() { 
			return XWnd_GetChildCount(GetWindowHandle());
		}

		// 获取当前层子元素通过索引
		HXCGUI GetChildByIndex(int index) { 
			return XWnd_GetChildByIndex(GetWindowHandle(), index);
		}

		// 获取当前层子对象通过对象ID
		HXCGUI GetChildByID(int nID) { 
			return XWnd_GetChildByID(GetWindowHandle(), nID); 
		}

		// 获取子对象通过对象ID,如果对象不在该窗口上无效
		HXCGUI GetChild(int nID) { 
			return XWnd_GetChild(GetWindowHandle(), nID); 
		}
		
		// 置图标
		void SetIcon(HIMAGE hImage) { 
			XWnd_SetIcon(GetWindowHandle(), hImage);
		}

		// 置标题
		void SetTitle(const std::wstring& title) { 
			XWnd_SetTitle(GetWindowHandle(), title.c_str());
		}

		// 置标题颜色
		void SetTitleColor(COLORREF color) { 
			XWnd_SetTitleColor(GetWindowHandle(), color);
		}

		// 取控制按钮 nFlag 可用值: @ref window_style_btn_min , @ref window_style_btn_max , @ref window_style_btn_close
		HELE GetButton(int nFlag) { 
			return XWnd_GetButton(GetWindowHandle(), nFlag);
		}

		// 返回图标句柄
		HIMAGE GetIcon() { 
			return XWnd_GetIcon(GetWindowHandle());
		}

		// 取标题
		std::wstring GetTitle() { 
			auto pTitle = XWnd_GetTitle(GetWindowHandle()); 
			if (!pTitle) {
				return L"";
			}
			return pTitle;
		}

		// 取标题颜色
		COLORREF GetTitleColor() { 
			return XWnd_GetTitleColor(GetWindowHandle());
		}

		// 关闭窗口
		void CloseWindow() { 
			XWnd_CloseWindow(GetWindowHandle()); 
		}

		// 调整窗口布局
		void AdjustLayout() { 
			XWnd_AdjustLayout(GetWindowHandle());
		}

		// 调整布局扩展
		void AdjustLayoutEx(adjustLayout_ nFlags = adjustLayout_self) {
			XWnd_AdjustLayoutEx(GetWindowHandle(), nFlags); 
		}

		// 创建插入符,基于元素坐标
		void CreateCaret(HELE hEle, int x, int y, int width, int height) { 
			XWnd_CreateCaret(GetWindowHandle(), hEle, x, y, width, height); 
		}

		// 	设置插入符位置
		void SetCaretPos(int x, int y, int width, int height, bool bUpdate = false) { 
			XWnd_SetCaretPos(GetWindowHandle(), x, y, width, height, bUpdate);
		}
		
		// 设置插入符颜色
		void SetCaretColor(COLORREF color) { 
			XWnd_SetCaretColor(GetWindowHandle(), color);
		}


		// 显示插入符
		void ShowCaret(bool bShow) { 
			XWnd_ShowCaret(GetWindowHandle(), bShow);
		}

		// 返回插入符元素
		HELE GetCaretHELE() { 
			return XWnd_GetCaretHELE(GetWindowHandle());
		}

		// 获取插入符信息
		HELE GetCaretInfo(int* pX, int* pY, int* pWidth, int* pHeight) { 
			return XWnd_GetCaretInfo(GetWindowHandle(), pX, pY, pWidth, pHeight); 
		}

		// 销毁插入符
		void DestroyCaret() { 
			XWnd_DestroyCaret(GetWindowHandle()); 
		}

		// 获取窗口客户区坐标;如果是阴影窗口,那么不包含阴影部分
		bool GetClientRect(RECT* pRect) { 
			return XWnd_GetClientRect(GetWindowHandle(), pRect); 
		}

		// 获取body坐标
		void GetBodyRect(RECT* pRect) { 
			XWnd_GetBodyRect(GetWindowHandle(), pRect);
		}

		// 取布局坐标
		void GetLayoutRect(RECT* pRect) { 
			XWnd_GetLayoutRect(GetWindowHandle(), pRect); 
		}

		// 移动窗口
		void SetPosition(int x, int y) { 
			XWnd_SetPosition(GetWindowHandle(), x, y); 
		}

		// 取坐标
		void GetRect(RECT* pRect) { 
			XWnd_GetRect(GetWindowHandle(), pRect);
		}

		// 置坐标
		void SetRect(RECT* pRect) { 
			XWnd_SetRect(GetWindowHandle(), pRect);
		}

		// 置顶
		void SetTop() { 
			XWnd_SetTop(GetWindowHandle()); 
		}

		//  最大化
		void MaxWindow(bool bMaximize) { 
			XWnd_MaxWindow(GetWindowHandle(), bMaximize);
		}

		// 设置窗口定时器
		UINT SetTimer(UINT nIDEvent, UINT uElapse) { 
			return XWnd_SetTimer(GetWindowHandle(), nIDEvent, uElapse); 
		}

		// 关闭定时器
		bool KillTimer(UINT nIDEvent) { 
			return XWnd_KillTimer(GetWindowHandle(), nIDEvent);
		}

		// 设置炫彩窗口定时器
		bool SetXCTimer(UINT nIDEvent, UINT uElapse) { 
			return XWnd_SetXCTimer(GetWindowHandle(), nIDEvent, uElapse);
		}

		// 关闭炫彩窗口定时器
		bool KillXCTimer(UINT nIDEvent) { 
			return XWnd_KillXCTimer(GetWindowHandle(), nIDEvent);
		}

		// 添加背景内容边框
		void AddBkBorder(int nState, COLORREF color, int width) { 
			XWnd_AddBkBorder(GetWindowHandle(), nState, color, width);
		}

		// 添加背景内容填充
		void AddBkFill(int nState, COLORREF color) { 
			XWnd_AddBkFill(GetWindowHandle(), nState, color);
		}

		// 	添加背景内容图片
		void AddBkImage(int nState, HIMAGE hImage) { 
			XWnd_AddBkImage(GetWindowHandle(), nState, hImage);
		}
		
		// 置背景
		int SetBkInfo(const std::wstring& text) { 
			return XWnd_SetBkInfo(GetWindowHandle(), text.c_str());
		}

		// 获取背景内容数量
		int GetBkInfoCount() { 
			return XWnd_GetBkInfoCount(GetWindowHandle());
		}

		// 清空背景内容; 如果背景没有内容,将使用系统默认内容,以便保证背景正确
		void ClearBkInfo() { 
			XWnd_ClearBkInfo(GetWindowHandle());
		}

		HBKM GetBkManager() { 
			return XWnd_GetBkManager(GetWindowHandle()); 
		}

		// 获取背景管理器,优先从资源中获取
		HBKM GetBkManagerEx() { 
			return XWnd_GetBkManagerEx(GetWindowHandle());
		}

		// 置背景管理器
		void SetBkMagager(HBKM hBkInfoM) { 
			XWnd_SetBkMagager(GetWindowHandle(), hBkInfoM);
		}

		// 设置透明窗口,同时可以通过该函数关闭透明窗口
		void SetTransparentType(window_transparent_ nType) { 
			XWnd_SetTransparentType(GetWindowHandle(), nType);
		}

		// 设置透明窗口的透明度,设置后调用重绘窗口API来更新  alpha 窗口透明度,范围0-255之间,0透明,255不透明
		void SetTransparentAlpha(BYTE alpha) { 
			XWnd_SetTransparentAlpha(GetWindowHandle(), alpha); 
		}

		// 设置透明窗口的透明色
		void SetTransparentColor(COLORREF color) { 
			XWnd_SetTransparentColor(GetWindowHandle(), color);
		}

		// 设置窗口阴影信息
		void SetShadowInfo(int nSize, int nDepth, int nAngeleSize, bool bRightAngle, COLORREF color) { 
			XWnd_SetShadowInfo(GetWindowHandle(), nSize, nDepth, nAngeleSize, bRightAngle, color); 
		}

		// 获取窗口阴影信息
		void GetShadowInfo(int* pnSize, int* pnDepth, int* pnAngeleSize, BOOL* pbRightAngle, COLORREF* pColor) { 
			XWnd_GetShadowInfo(GetWindowHandle(), pnSize, pnDepth, pnAngeleSize, pbRightAngle, pColor); 
		}

		// 获取窗口透明类型
		window_transparent_ GetTransparentType() { 
			return XWnd_GetTransparentType(GetWindowHandle()); 
		}
		

		HWINDOW GetWindowHandle() const
		{
			return (HWINDOW)m_handle;
		}

	protected:
		void SetWindowHandle(HWINDOW winHandle)
		{
			this->SetHandle((HXCGUI)winHandle);
		}



	};

}