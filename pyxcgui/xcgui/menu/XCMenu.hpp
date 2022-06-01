#pragma once
#include "pch.h"
#include "xcgui/XCObject.hpp"

namespace xcgui {
	class XCMenu : public XCObject
	{
	public:
		XCMenu(HMENUX handle) :
			XCObject(handle)
		{
			m_handle = handle;
		}

		XCMenu()
			:XCObject(NULL)
		{
			m_handle = this->Create();
		}

		HMENUX Create() {
			m_handle = XMenu_Create(); 
			return (HMENUX)m_handle;
		}

		//@备注 添加菜单项.  
		//@参数 nID 项ID.
		//@参数 text 文本内容.
		//@参数 nParentID 父项ID.
		//@参数 nFlags 标识参见宏定义 @ref menu_item_flag_.
		//@别名  添加项()
		void AddItem(int nID, const std::wstring& text, int parentId = XC_ID_ROOT, int nFlags = 0) {
			XMenu_AddItem((HMENUX)m_handle, nID, text.c_str(), parentId, nFlags);
		}

		//@备注 添加菜单项.  
		//@参数 nID 项ID.
		//@参数 text 文本内容.
		//@参数 nParentID 父项ID.
		//@参数 hIcon 菜单项图标句柄.
		//@参数 nFlags 标识参见宏定义 @ref menu_item_flag_.
		//@别名  添加项图标()
		void AddItemIcon(int nID, const std::wstring& text, int nParentID, HIMAGE hImage, int nFlags = 0) {
			XMenu_AddItemIcon((HMENUX)m_handle, nID, text.c_str(), nParentID, hImage, nFlags);
		}

		//@备注 插入菜单项.  
		//@参数 nID 项ID.
		//@参数 text 文本内容.
		//@参数 nFlags 标识参见宏定义 @ref menu_item_flag_.
		//@参数 insertID 插入位置ID.
		//@别名  插入项()
		void InsertItem(int nID, const std::wstring& text, int nFlags, int insertID) {
			XMenu_InsertItem((HMENUX)m_handle, nID, text.c_str(), nFlags, insertID);
		}

		//@备注 插入菜单项.  
		//@参数 nID 项ID.
		//@参数 text 文本内容.
		//@参数 hIcon 菜单项图标句柄.
		//@参数 nFlags 标识参见宏定义 @ref menu_item_flag_.
		//@参数 insertID 插入位置ID.
		//@别名  插入项图标()
		void InsertItemIcon(int nID, const std::wstring& text, HIMAGE hIcon, int nFlags, int insertID) {
			XMenu_InsertItemIcon((HMENUX)m_handle, nID, text.c_str(), hIcon, nFlags, insertID);
		}

		//@备注 获取第一个子项.  
		//@参数 nID 项ID.
		//@返回 返回项ID.
		//@别名  取第一个子项()
		int GetFirstChildItem(int nID) {
			return XMenu_GetFirstChildItem((HMENUX)m_handle, nID);
		}

		//@备注 获取末尾子项.  
		//@参数 nID 项ID.
		//@返回 返回项ID.
		//@别名  取末尾子项()
		int GetEndChildItem(int nID) {
			return XMenu_GetEndChildItem((HMENUX)m_handle, nID);
		}

		//@备注 获取上一个兄弟项.  
		//@参数 nID 项ID.
		//@返回 返回项ID.
		//@别名  取上一个兄弟项()
		int GetPrevSiblingItem(int nID) {
			return XMenu_GetPrevSiblingItem((HMENUX)m_handle, nID);
		}

		//@备注 获取下一个兄弟项.  
		//@参数 nID 项ID.
		//@返回 返回项ID.
		//@别名  取下一个兄弟项()
		int GetNextSiblingItem(int nID) {
			return XMenu_GetNextSiblingItem((HMENUX)m_handle, nID);
		}

		//@备注 获取父项.  
		//@参数 nID 项ID.
		//@返回 返回项ID.
		//@别名  取父项()
		int GetParentItem(int nID) {
			return XMenu_GetParentItem((HMENUX)m_handle, nID);
		}

		//@备注 设置是否自动销毁菜单.  
		//@参数 bAuto 是否自动销毁.
		//@别名  置自动销毁()
		void SetAutoDestroy(bool bAuto) {
			XMenu_SetAutoDestroy((HMENUX)m_handle, bAuto);
		}

		//@备注 是否有用户绘制菜单背景,如果启用XWM_MENU_DRAW_BACKGROUND和XE_MENU_DRAW_BACKGROUND事件有效.  
		//@参数 bEnable 是否启用.
		//@别名  启用用户绘制背景()
		void EnableDrawBackground(bool bEnable) {
			XMenu_EnableDrawBackground((HMENUX)m_handle, bEnable);
		}

		//@备注 是否有用户绘制菜单项,如果启用XWM_MENU_DRAWITEM和XE_MENU_DRAWITEM事件有效.  
		//@参数 bEnable 是否启用.
		//@别名  启用用户绘制项()
		void EnableDrawItem(bool bEnable) {
			XMenu_EnableDrawItem((HMENUX)m_handle, bEnable);
		}

		//@备注 弹出菜单.  
		//@参数 hParentWnd 父窗口句柄.
		//@参数 x x坐标.
		//@参数 y y坐标.
		//@参数 hParentEle 父元素句柄,如果该值不为NULL,hParentEle元素将接收菜单消息事件,
		//@参数 nPosition 弹出位置,参见宏定义.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  弹出()
		bool Popup(HWND hParentWnd, int x, int y, HELE hParentEle = NULL, menu_popup_position_ nPosition = menu_popup_position_left_top) {
			return XMenu_Popup((HMENUX)m_handle, hParentWnd, x, y, hParentEle, nPosition);
		}

		//@备注 销毁菜单.  
		//@别名  销毁()
		void DestroyMenu() {
			XMenu_DestroyMenu((HMENUX)m_handle);
		}

		//@备注 关闭菜单.  
		//@别名  关闭()
		void CloseMenu() {
			XMenu_CloseMenu((HMENUX)m_handle);
		}

		//@备注 设置菜单背景图片.  
		//@参数 hImage 图片句柄.
		//@别名  置背景图片()
		void SetBkImage(HIMAGE hImage) {
			XMenu_SetBkImage((HMENUX)m_handle, hImage);
		}

		//@备注 设置项文本.  
		//@参数 nID 项ID.
		//@参数 text 文本内容.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置项文本()
		bool SetItemText(int nID, const std::wstring& text) {
			return XMenu_SetItemText((HMENUX)m_handle, nID, text.c_str());
		}

		//@备注 获取项文本.  
		//@参数 nID 项ID.
		//@返回 返回文本内容
		//@别名  取项文本()
		std::wstring GetItemText(int nID) {
			 auto pText = XMenu_GetItemText((HMENUX)m_handle, nID);
			 if (!pText)
				 return nullptr;
			 return pText;
		}

		//@备注 获取项文本长度,不包含字符串空终止符.  
		//@参数 nID 项ID.
		//@返回 长度,字符为单位.
		//@别名  取项文本长度()
		int GetItemTextLength(int nID) {
			return XMenu_GetItemTextLength((HMENUX)m_handle, nID);
		}

		//@备注 设置菜单项图标.  
		//@参数 nID 项ID.
		//@参数 hIcon 菜单项图标句柄.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置项图标()
		bool SetItemIcon(int nID, HIMAGE hIcon) {
			return XMenu_SetItemIcon((HMENUX)m_handle, nID, hIcon);
		}

		//@备注 设置项标识.  
		//@参数 nID 项ID.
		//@参数 uFlags 标识参见宏定义 @ref menu_item_flag_.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置项标志()
		bool SetItemFlags(int nID, int uFlags) {
			return XMenu_SetItemFlags((HMENUX)m_handle, nID, uFlags);
		}

		//@备注 设置项高度.  
		//@参数 height 高度.
		//@别名  置项高度()
		void SetItemHeight(int height) {
			XMenu_SetItemHeight((HMENUX)m_handle, height);
		}

		//@备注 获取项高度.  
		//@返回 返回项高度.
		//@别名  取项高度()
		int GetItemHeight() {
			return XMenu_GetItemHeight((HMENUX)m_handle);
		}

		//@备注 此宽度为文本显示区域宽度, 不包含侧边条和与文本间隔
		//@参数 nID 项ID
		//@参数 nWidth 指定文本区域宽度
		//@返回 如果成功返回TRUE,否则返回FALSE
		//@别名  置项宽度()
		bool SetItemWidth(int nID, int nWidth) {
			return XMenu_SetItemWidth((HMENUX)m_handle, nID, nWidth);
		}

		//@备注 设置菜单边框颜色.  
		//@参数 crColor 颜色值, 请使用宏: RGBA()
		//@别名  置边框颜色()
		void SetBorderColor(COLORREF crColor) {
			XMenu_SetBorderColor((HMENUX)m_handle, crColor);
		}

		//@备注 设置弹出菜单窗口边框大小.  
		//@参数 nLeft 边大小.
		//@参数 nTop 边大小.
		//@参数 nRight 边大小.
		//@参数 nBottom 边大小.
		//@别名  置边框大小()
		void SetBorderSize(int nLeft, int nTop, int nRight, int nBottom) {
			XMenu_SetBorderSize((HMENUX)m_handle, nLeft, nTop, nRight, nBottom);
		}

		//@备注 获取左侧区域宽度.  
		//@返回 返回左侧区域宽度.
		//@别名  取左侧宽度()
		int GetLeftWidth() {
			return XMenu_GetLeftWidth((HMENUX)m_handle);
		}

		//@备注 获取菜单项文本左间隔.  
		//@返回 返回菜单项文件左间隔大小.
		//@别名  取左侧文本间隔()
		int GetLeftSpaceText() {
			return XMenu_GetLeftSpaceText((HMENUX)m_handle);
		}

		//@备注 获取菜单项数量,包含子菜单项.  
		//@返回 菜单项数量.
		//@别名  取项数量()
		int GetItemCount() {
			return XMenu_GetItemCount((HMENUX)m_handle);
		}

		//@备注 设置菜单项勾选状态.  
		//@参数 nID 菜单项ID
		//@参数 bCheck 勾选TRUE,非勾选FALSE
		//@返回 如果勾选返回TRUE,否则返回FALSE.
		//@别名  置项勾选()
		bool SetItemCheck(int nID, bool bCheck) {
			return XMenu_SetItemCheck((HMENUX)m_handle, nID, bCheck);
		}

		//@备注 判断菜单项是否勾选.  
		//@参数 nID 菜单项ID
		//@返回 如果勾选返回TRUE,否则返回FALSE.
		//@别名  是否项勾选()
		bool IsItemCheck(int nID) {
			return XMenu_IsItemCheck((HMENUX)m_handle, nID);
		}

	};
}