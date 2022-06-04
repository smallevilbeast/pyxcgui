#pragma once
#include "pch.h"
#include "xcgui/element/XCScrollView.hpp"

namespace xcgui {


	class XCEdit : public XCScrollView
	{

	public:
		XCEdit(HELE handle)
		{

			m_handle = handle;
		}

		XCEdit() = default;

		XCEdit(int x, int y, int width, int height, HXCGUI parent = NULL) {

			m_handle = XEdit_Create(x, y, width, height, parent);
		}
		XCEdit(int x, int y, int width, int height, edit_type_ editType, HXCGUI parent = NULL) {

			m_handle = XEdit_CreateEx(x, y, width, height, editType, parent);
		}

		//@备注 启用自动换行  
		//@参数 bEnable 是否启用
		//@别名  启用自动换行()
		void EnableAutoWrap(bool bEnable) {
			XEdit_EnableAutoWrap(getEleHandle(), bEnable);
		}

		//@参数 bEnable 是否启用
		//@别名  启用只读()
		void EnableReadOnly(bool bEnable) {
			XEdit_EnableReadOnly(getEleHandle(), bEnable);
		}

		//@参数 bEnable 
		//@别名  启用多行()
		void EnableMultiLine(bool bEnable) {
			XEdit_EnableMultiLine(getEleHandle(), bEnable);
		}

		//@备注 启用密码模式(只支持默认类型编辑框
		//@参数 bEnable 是否启用
		//@别名  启用密码()
		void EnablePassword(bool bEnable) {
			XEdit_EnablePassword(getEleHandle(), bEnable);
		}

		//@备注 当获得焦点时,自动选择所有内容
		//@参数 bEnable 是否启用
		//@别名  启用自动选择()
		void EnableAutoSelAll(bool bEnable) {
			XEdit_EnableAutoSelAll(getEleHandle(), bEnable);
		}

		//@备注 当失去焦点时自动取消选择
		//@参数 bEnable 是否启用
		//@别名  启用自动取消选择()
		void EnableAutoCancelSel(bool bEnable) {
			XEdit_EnableAutoCancelSel(getEleHandle(), bEnable);
		}

		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  是否只读()
		bool IsReadOnly() {
			return XEdit_IsReadOnly(getEleHandle());
		}

		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  是否多行()
		bool IsMultiLine() {
			return XEdit_IsMultiLine(getEleHandle());
		}

		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  是否密码()
		bool IsPassword() {
			return XEdit_IsPassword(getEleHandle());
		}

		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  是否自动换行()
		bool IsAutoWrap() {
			return XEdit_IsAutoWrap(getEleHandle());
		}

		//@返回 如果为空返回TRUE否则返回FALSE.
		//@别名  是否为空()
		bool IsEmpty() {
			return XEdit_IsEmpty(getEleHandle());
		}

		//@参数 iRow 行索引
		//@参数 iCol 列索引
		//@返回 如果在选择区域内返回TRUE,否则返回FALSE
		//@别名  是否在选择区域()
		bool IsInSelect(int iRow, int iCol) {
			return XEdit_IsInSelect(getEleHandle(), iRow, iCol);
		}

		//@返回 返回从行数
		//@别名  取总行数()
		int GetRowCount() {
			return XEdit_GetRowCount(getEleHandle());
		}

		//@备注 包含文本或非文本内容
		//@返回 返回数据结构
		//@别名  取数据()
		edit_data_copy_* GetData() {
			return XEdit_GetData(getEleHandle());
		}

		//@参数 pData 数据结构
		//@参数 styleTable 样式表
		//@参数 nStyleCount 样式数量
		//@别名  添加数据()
		void AddData(edit_data_copy_* pData, USHORT* styleTable, int nStyleCount) {
			XEdit_AddData(getEleHandle(), pData, styleTable, nStyleCount);
		}

		//@别名  释放数据()
		//@参数 pData 数据结构
		void FreeData(edit_data_copy_* pData) {
			XEdit_FreeData(pData);
		}

		//@备注 当内容为空时,显示默认文本
		//@参数 pString 文本内容
		//@别名  置默认文本()
		void SetDefaultText(const std::wstring& text) {
			XEdit_SetDefaultText(getEleHandle(), text.c_str());
		}

		//@参数 color 颜色值, 请使用宏: RGBA()
		//@别名  置默认文本颜色()
		void SetDefaultTextColor(COLORREF color) {
			XEdit_SetDefaultTextColor(getEleHandle(), color);
		}

		//@参数 ch 字符
		//@别名  置密码字符()
		void SetPasswordCharacter(wchar_t ch) {
			XEdit_SetPasswordCharacter(getEleHandle(), ch);
		}

		//@备注 单行模式下有效
		//@参数 align 对齐方式 @ref edit_textAlign_flag_
		//@别名  置文本对齐()
		void SetTextAlign(int align) {
			XEdit_SetTextAlign(getEleHandle(), align);
		}

		//@参数 nSpace 空格数量
		//@别名  置TAB空格()
		void SetTabSpace(int nSpace) {
			XEdit_SetTabSpace(getEleHandle(), nSpace);
		}

		//@备注 置中文字体;  如果已设置, 当遇到中文字符时使用后备字体, 解决不支持中文的字体问题
		//@参数 hFont 字体
		//@别名  置后备字体()
		void SetBackFont(HFONTX hFont) {
			XEdit_SetBackFont(getEleHandle(), hFont);
		}

		//@参数 size 空格大小
		//@别名  置空格大小()
		void SetSpaceSize(int size) {
			XEdit_SetSpaceSize(getEleHandle(), size);
		}

		//@参数 size 英文字符间距大小
		//@参数 sizeZh 中文字符间距大小
		//@别名  置字符间距()
		void SetCharSpaceSize(int size, int sizeZh) {
			XEdit_SetCharSpaceSize(getEleHandle(), size, sizeZh);
		}

		//@参数 pString 字符串
		//@别名  置文本()
		void SetText(const std::wstring& text) {
			XEdit_SetText(getEleHandle(), text.c_str());
		}

		//@参数 nValue 整数值
		//@别名  置文本整数()
		void SetTextInt(int nValue) {
			XEdit_SetTextInt(getEleHandle(), nValue);
		}

		//@备注 不包含非文本内容
		//@参数 pOut 接收文本内存指针
		//@参数 nOutlen 内存大小, 字符为单位
		//@返回 返回实际接收文本长度
		//@别名  取文本()
		int GetText(wchar_t* pOut, int nOutlen) {
			return XEdit_GetText(getEleHandle(), pOut, nOutlen);
		}

		//@备注 获取指定行文本内容
		//@参数 iRow 行索引
		//@参数 pOut 接收文本内存指针
		//@参数 nOutlen 接收文本内存块长度,字符为单位
		//@返回 返回实际接收文本长度
		//@别名  取文本行()
		int GetTextRow(int iRow, wchar_t* pOut, int nOutlen) {
			return XEdit_GetTextRow(getEleHandle(), iRow, pOut, nOutlen);
		}

		//@备注 包含非文本内容
		//@返回 返回内容长度
		//@别名  取内容长度()
		int GetLength() {
			return XEdit_GetLength(getEleHandle());
		}

		//@备注 包含非文本内容
		//@参数 iRow 行索引
		//@返回 返回内容长度
		//@别名  取内容长度行()
		int GetLengthRow(int iRow) {
			return XEdit_GetLengthRow(getEleHandle(), iRow);
		}

		//@参数 iRow 行索引
		//@参数 iCol 列索引
		//@返回 返回指定位置字符
		//@别名  取字符()
		wchar_t GetAt(int iRow, int iCol) {
			return XEdit_GetAt(getEleHandle(), iRow, iCol);
		}

		//@参数 iRow 行索引
		//@参数 iCol 列索引
		//@参数 pString 字符串
		//@别名  插入文本()
		void InsertText(int iRow, int iCol, const std::wstring& text) {
			XEdit_InsertText(getEleHandle(), iRow, iCol, text.c_str());
		}

		//@参数 pString 字符串
		//@别名  添加文本()
		void AddText(const std::wstring& text) {
			XEdit_AddText(getEleHandle(), text.c_str());
		}

		//@备注 自动刷新UI, 支持撤销/恢复
		//@参数 pString 字符串
		//@别名  添加文本模拟用户操作()
		void AddTextUser(const std::wstring& text) {
			XEdit_AddTextUser(getEleHandle(), text.c_str());
		}

		//@参数 pString 字符串
		//@参数 iStyle 样式索引
		//@别名  添加文本扩展()
		void AddTextEx(const std::wstring& text, int iStyle) {
			XEdit_AddTextEx(getEleHandle(), text.c_str(), iStyle);
		}

		//@备注 例如: 字体, 图片, UI对象
		//@参数 hObj 对象句柄
		//@返回 返回样式索引
		//@别名  添加对象()
		int AddObject(HXCGUI hObj) {
			return XEdit_AddObject(getEleHandle(), hObj);
		}

		//@备注 当样式为图片时有效
		//@参数 iStyle 样式索引
		//@别名  添加对象从样式()
		void AddByStyle(int iStyle) {
			XEdit_AddByStyle(getEleHandle(), iStyle);
		}

		//@参数 hFont_image_Obj 字体,图片或UI对象
		//@参数 color 颜色
		//@参数 bColor 是否使用颜色
		//@返回 返回样式索引
		//@别名  添加样式()
		int AddStyle(HXCGUI hFont_image_Obj, COLORREF color, bool bColor) {
			return XEdit_AddStyle(getEleHandle(), hFont_image_Obj, color, bColor);
		}

		//@参数 fontName 字体名称
		//@参数 fontSize 字体大小
		//@参数 fontStyle 字体样式 @ref fontStyle_
		//@参数 color 颜色
		//@参数 bColor 是否使用颜色
		//@返回 返回样式索引
		//@别名  添加样式扩展()
		int AddStyleEx(const wchar_t* fontName, int fontSize, int fontStyle, COLORREF color, bool bColor) {
			return XEdit_AddStyleEx(getEleHandle(), fontName, fontSize, fontStyle, color, bColor);
		}

		//@参数 iStyle 样式索引
		//@参数 hFont 字体句柄
		//@参数 color 颜色
		//@参数 bColor 是否使用颜色
		//@返回 如果成功返回TRUE,否则返回FALSE
		//@别名  修改样式()
		bool ModifyStyle(int iStyle, HFONTX hFont, COLORREF color, bool bColor) {
			return XEdit_ModifyStyle(getEleHandle(), iStyle, hFont, color, bColor);
		}

		//@参数 iStyle 样式
		//@返回 如果成功返回TRUE,否则返回FALSE 
		//@别名  释放样式()
		bool ReleaseStyle(int iStyle) {
			return XEdit_ReleaseStyle(getEleHandle(), iStyle);
		}

		//@参数 iStyle 样式索引
		//@参数 info 返回样式信息
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  取样式信息()
		bool GetStyleInfo(int iStyle, edit_style_info_* info) {
			return XEdit_GetStyleInfo(getEleHandle(), iStyle, info);
		}

		//@参数 iStyle 样式索引
		//@别名  置当前样式()
		void SetCurStyle(int iStyle) {
			XEdit_SetCurStyle(getEleHandle(), iStyle);
		}

		//@参数 iStyle 样式索引
		//@别名  置选择文本样式()
		void SetSelectTextStyle(int iStyle) {
			XEdit_SetSelectTextStyle(getEleHandle(), iStyle);
		}

		//@参数 color 颜色
		//@别名  置插入符颜色()
		void SetCaretColor(COLORREF color) {
			XEdit_SetCaretColor(getEleHandle(), color);
		}

		//@参数 nWidth 宽度
		//@别名  置插入符宽度()
		void SetCaretWidth(int nWidth) {
			XEdit_SetCaretWidth(getEleHandle(), nWidth);
		}

		//@参数 color 颜色值, 请使用宏: RGBA()
		//@别名  置选择背景颜色()
		void SetSelectBkColor(COLORREF color) {
			XEdit_SetSelectBkColor(getEleHandle(), color);
		}

		//@参数 nHeight 行高
		//@别名  置默认行高()
		void SetRowHeight(int nHeight) {
			XEdit_SetRowHeight(getEleHandle(), nHeight);
		}

		//@备注 当类型为 edit_type_richedit 支持指定不同行高
		//@参数 iRow 行索引
		//@参数 nHeight 高度
		//@别名  置指定行高度()
		void SetRowHeightEx(int iRow, int nHeight) {
			XEdit_SetRowHeightEx(getEleHandle(), iRow, nHeight);
		}

		//@备注 设置行间隔大小,多行模式有效
		//@参数 nSpace 行间隔大小
		//@别名  置行间隔()
		void SetRowSpace(int nSpace) {
			XEdit_SetRowSpace(getEleHandle(), nSpace);
		}

		//@参数 pos 位置
		//@返回 如果成功返回TRUE,否则返回FALSE
		//@别名  置当前位置()
		bool SetCurPos(int pos) {
			return XEdit_SetCurPos(getEleHandle(), pos);
		}

		//@返回 返回位置
		//@别名  取当前位置()
		int GetCurPos() {
			return XEdit_GetCurPos(getEleHandle());
		}

		//@参数 iRow 行索引
		//@参数 iCol 列索引
		//@别名  置当前位置扩展()
		void SetCurPosEx(int iRow, int iCol) {
			XEdit_SetCurPosEx(getEleHandle(), iRow, iCol);
		}

		//@参数 iRow 返回行索引
		//@参数 iCol 返回列索引
		//@别名  取当前位置扩展()
		void GetCurPosEx(int* iRow, int* iCol) {
			XEdit_GetCurPosEx(getEleHandle(), iRow, iCol);
		}

		//@返回 返回行索引
		//@别名  取当前行()
		int GetCurRow() {
			return XEdit_GetCurRow(getEleHandle());
		}

		//@返回 返回列索引
		//@别名  取当前列()
		int GetCurCol() {
			return XEdit_GetCurCol(getEleHandle());
		}

		//@别名  移动到末尾()
		void MoveEnd() {
			XEdit_MoveEnd(getEleHandle());
		}

		//@参数 iRow 行索引
		//@参数 iCol 列索引
		//@参数 pOut 接收返回坐标点
		//@别名  取坐标点()
		void GetPoint(int iRow, int iCol, POINT* pOut) {
			XEdit_GetPoint(getEleHandle(), iRow, iCol, pOut);
		}

		//@备注 视图自动滚动到当前插入符位置
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  自动滚动()
		bool AutoScroll() {
			return XEdit_AutoScroll(getEleHandle());
		}

		//@备注 视图自动滚动到指定位置
		//@参数 iRow 行索引
		//@参数 iCol 列索引
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  自动滚动扩展()
		bool AutoScrollEx(int iRow, int iCol) {
			return XEdit_AutoScrollEx(getEleHandle(), iRow, iCol);
		}

		//@备注 转换位置点到行列
		//@参数 iPos 位置点
		//@参数 pInfo 行列
		//@别名  位置到行列()
		void PosToRowCol(int iPos, position_* pInfo) {
			XEdit_PosToRowCol(getEleHandle(), iPos, pInfo);
		}

		//@参数 iRow 行索引
		//@参数 iCol 列索引
		//@返回 位置点
		//@别名  行列到位置()
		int RowColToPos(int iRow, int iCol) {
			return XEdit_RowColToPos(getEleHandle(), iRow, iCol);
		}

		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  选择全部()
		bool SelectAll() {
			return XEdit_SelectAll(getEleHandle());
		}

		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  取消选择()
		bool CancelSelect() {
			return XEdit_CancelSelect(getEleHandle());
		}

		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  删除选择内容()
		bool DeleteSelect() {
			return XEdit_DeleteSelect(getEleHandle());
		}

		//@参数 iStartRow 起始行索引
		//@参数 iStartCol 起始行列索引
		//@参数 iEndRow 结束行索引
		//@参数 iEndCol 结束行列索引
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置选择()
		bool SetSelect(int iStartRow, int iStartCol, int iEndRow, int iEndCol) {
			return XEdit_SetSelect(getEleHandle(), iStartRow, iStartCol, iEndRow, iEndCol);
		}

		//@备注 不包括非文本内容
		//@参数 pOut 接收返回文本内容
		//@参数 nOutLen 接收内存大小,字符为单位
		//@返回 返回接收文本内容实际长度
		//@别名  取选择文本()
		int GetSelectText(wchar_t* pOut, int nOutLen) {
			return XEdit_GetSelectText(getEleHandle(), pOut, nOutLen);
		}

		//@备注 不包括非文本内容
		//@返回 返回文本内容长度
		//@别名  取选择文本长度()
		int GetSelectTextLength() {
			return XEdit_GetSelectTextLength(getEleHandle());
		}

		//@参数 pBegin 起始位置
		//@参数 pEnd 结束位置
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  取选择内容范围()
		bool GetSelectRange(position_* pBegin, position_* pEnd) {
			return XEdit_GetSelectRange(getEleHandle(), pBegin, pEnd);
		}

		//@参数 piStart 起始行索引
		//@参数 piEnd 结束行索引
		//@别名  取可视行范围()
		void GetVisibleRowRange(int* piStart, int* piEnd) {
			XEdit_GetVisibleRowRange(getEleHandle(), piStart, piEnd);
		}

		//@备注 删除指定范围内容; 删除全部请使用 XEdit_SetText(hEdit,L"")
		//@参数 iStartRow 起始行索引
		//@参数 iStartCol 起始行列索引
		//@参数 iEndRow 结束行索引
		//@参数 iEndCol 结束行列索引
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  删除()
		bool Delete(int iStartRow, int iStartCol, int iEndRow, int iEndCol) {
			return XEdit_Delete(getEleHandle(), iStartRow, iStartCol, iEndRow, iEndCol);
		}

		//@参数 iRow 行索引
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  删除行()
		bool DeleteRow(int iRow) {
			return XEdit_DeleteRow(getEleHandle(), iRow);
		}

		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  剪贴板剪切()
		bool ClipboardCut() {
			return XEdit_ClipboardCut(getEleHandle());
		}

		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  剪贴板复制()
		bool ClipboardCopy() {
			return XEdit_ClipboardCopy(getEleHandle());
		}

		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  剪贴板粘贴()
		bool ClipboardPaste() {
			return XEdit_ClipboardPaste(getEleHandle());
		}

		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  撤销()
		bool Undo() {
			return XEdit_Undo(getEleHandle());
		}

		//@备注 恢复/重做
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  恢复()
		bool Redo() {
			return XEdit_Redo(getEleHandle());
		}

		//@备注 当前行开始
		//@参数 hImageAvatar 头像
		//@参数 hImageBubble 气泡背景
		//@参数 nFlag 标志 @ref chat_flag_
		//@别名  添加气泡开始()
		void AddChatBegin(HIMAGE hImageAvatar, HIMAGE hImageBubble, int nFlag) {
			XEdit_AddChatBegin(getEleHandle(), hImageAvatar, hImageBubble, nFlag);
		}

		//@备注 当前行结束
		//@别名  添加气泡结束()
		void AddChatEnd() {
			XEdit_AddChatEnd(getEleHandle());
		}

		//@备注 设置聊天气泡内容缩进
		//@参数 nIndentation 缩进值
		//@别名  置气泡缩进()
		void SetChatIndentation(int nIndentation) {
			XEdit_SetChatIndentation(getEleHandle(), nIndentation);
		}

	};
}