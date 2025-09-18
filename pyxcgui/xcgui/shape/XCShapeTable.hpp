#pragma once
#include "pch.h"
#include "xcgui/shape/XCShape.hpp"

namespace xcgui {

	class XCShapeTable : public XCShape
	{
	public:
		XCShapeTable() = default;

		XCShapeTable(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCShapeTable(int x, int y, int cx, int cy, HXCGUI hParent = NULL) {
			this->Create(x, y, cx, cy, hParent);
		}

		HXCGUI Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL) {
			m_handle = XTable_Create(x, y, cx, cy, hParent);
			return m_handle;
		}

		//@参数 nRow 行数量
		//@参数 nCol 列数量
		//@别名  重置()
		void Reset(int nRow, int nCol) {
			XTable_Reset(m_handle, nRow, nCol);
		}

		//@参数 iRow 行索引
		//@参数 iCol 列索引
		//@参数 count 数量
		//@别名  组合行()
		void ComboRow(int iRow, int iCol, int count) {
			XTable_ComboRow(m_handle, iRow, iCol, count);
		}

		//@参数 iRow 行索引
		//@参数 iCol 列索引
		//@参数 count 数量
		//@别名  组合列()
		void ComboCol(int iRow, int iCol, int count) {
			XTable_ComboCol(m_handle, iRow, iCol, count);
		}

		//@参数 iCol 列索引
		//@参数 width 宽度
		//@别名  置列宽()
		void SetColWidth(int iCol, int width) {
			XTable_SetColWidth(m_handle, iCol, width);
		}

		//@参数 iRow 行索引
		//@参数 height 高度
		//@别名  置行高()
		void SetRowHeight(int iRow, int height) {
			XTable_SetRowHeight(m_handle, iRow, height);
		}

		//@参数 color 颜色
		//@别名  置边颜色()
		void SetBorderColor(COLORREF color) {
			XTable_SetBorderColor(m_handle, color);
		}

		//@参数 color 颜色
		//@别名  置文本颜色()
		void SetTextColor(COLORREF color) {
			XTable_SetTextColor(m_handle, color);
		}

		//@参数 hFont 字体句柄
		//@别名  置字体()
		void SetFont(HFONTX hFont) {
			XTable_SetFont(m_handle, hFont);
		}

		//@参数 leftSize 内填充大小
		//@参数 topSize 内填充大小
		//@参数 rightSize 内填充大小
		//@参数 bottomSize 内填充大小
		//@别名  置项内填充()
		void SetItemPadding(int leftSize, int topSize, int rightSize, int bottomSize) {
			XTable_SetItemPadding(m_handle, leftSize, topSize, rightSize, bottomSize);
		}

		//@参数 iRow 行索引
		//@参数 iCol 列索引
		//@参数 text.c_str() 文本
		//@别名  置项文本()
		void SetItemText(int iRow, int iCol, const std::wstring& text) {
			XTable_SetItemText(m_handle, iRow, iCol, text.c_str());
		}

		//@参数 iRow 行索引
		//@参数 iCol 列索引
		//@参数 hFont 字体句柄
		//@别名  置项字体()
		void SetItemFont(int iRow, int iCol, HFONTX hFont) {
			XTable_SetItemFont(m_handle, iRow, iCol, hFont);
		}

		//@参数 iRow 行索引
		//@参数 iCol 列索引
		//@参数 nAlign 对齐方式  @ref textFormatFlag_
		//@别名  置项文本对齐()
		void SetItemTextAlign(int iRow, int iCol, int nAlign) {
			XTable_SetItemTextAlign(m_handle, iRow, iCol, nAlign);
		}

		//@参数 iRow 行索引
		//@参数 iCol 列索引
		//@参数 color 颜色
		//@参数 bColor 是否使用
		//@别名  置项文本色()
		void SetItemTextColor(int iRow, int iCol, COLORREF color, bool bColor) {
			XTable_SetItemTextColor(m_handle, iRow, iCol, color, bColor);
		}

		//@参数 iRow 行索引
		//@参数 iCol 列索引
		//@参数 color 颜色
		//@参数 bColor 是否使用
		//@别名  置项背景色()
		void SetItemBkColor(int iRow, int iCol, COLORREF color, bool bColor) {
			XTable_SetItemBkColor(m_handle, iRow, iCol, color, bColor);
		}

		//@参数 iRow1 行索引1
		//@参数 iCol1 列索引1
		//@参数 iRow2 行索引2
		//@参数 iCol2 列索引2
		//@参数 nFlag 标识  @ref  table_line_flag_
		//@参数 color 颜色
		//@别名  置项线()
		void SetItemLine(int iRow1, int iCol1, int iRow2, int iCol2, int nFlag, COLORREF color) {
			XTable_SetItemLine(m_handle, iRow1, iCol1, iRow2, iCol2, nFlag, color);
		}

		//@参数 iRow 行索引
		//@参数 iCol 列索引
		//@参数 flag 标识   @ref table_flag_
		//@别名  置项标识()
		void SetItemFlag(int iRow, int iCol, int flag) {
			XTable_SetItemFlag(m_handle, iRow, iCol, flag);
		}

		//@参数 iRow 行索引
		//@参数 iCol 列索引
		//@参数 pRect 接收返回坐标
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  取项坐标()
		bool GetItemRect(int iRow, int iCol, RECT* pRect) {
			return XTable_GetItemRect(m_handle, iRow, iCol, pRect);
		}

		// 3.3.9.1 新增
		/// @brief 设置表格项目的文本和样式（扩展版本）
		/// @param iRow 行索引
		/// @param iCol 列索引
		/// @param pText 文本内容
		/// @param textColor 文本颜色
		/// @param bkColor 背景颜色
		/// @param bTextColor 是否应用文本颜色（默认TRUE）
		/// @param bBkColor 是否应用背景颜色（默认TRUE）
		/// @param hFont 字体句柄（默认NULL）
		void SetItemTextEx(int iRow, int iCol, const std::wstring& text, COLORREF textColor, COLORREF bkColor, bool bTextColor = true, bool bBkColor = true, HFONTX hFont = nullptr) {
			XTable_SetItemTextEx(m_handle, iRow, iCol, text.c_str(), textColor, bkColor, bTextColor, bBkColor, hFont);
		}

	};
}