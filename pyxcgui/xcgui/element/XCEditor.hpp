#pragma once
#include "pch.h"
#include "xcgui/element/XCEdit.hpp"

namespace xcgui {

	class XCEditor : public XCEdit
	{
	public:
		XCEditor(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCEditor() = default;

		XCEditor(int x, int y, int width, int height, HXCGUI parent = NULL) {
			m_handle = XEditor_Create(x, y, width, height, parent);
		}

		//@参数 hEle 元素句柄
		//@参数 iRow 行索引
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名 代码编辑框_是否断点()
		bool IsBreakpoint(int iRow) {
			return XEditor_IsBreakpoint(getEleHandle(), iRow);
		}

		//@参数 hEle 元素句柄
		//@参数 iRow 行索引
		//@参数 bActivate 是否激活
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名 代码编辑框_置断点()
		bool SetBreakpoint(int iRow, bool bActivate = true) {
			return XEditor_SetBreakpoint(getEleHandle(), iRow, bActivate);
		}

		//@参数 hEle 元素句柄
		//@参数 iRow 行索引
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名 代码编辑框_移除断点()
		bool RemoveBreakpoint(int iRow) {
			return XEditor_RemoveBreakpoint(getEleHandle(), iRow);
		}

		//@参数 hEle 元素句柄
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名 代码编辑框_清空断点()
		void ClearBreakpoint() {
			XEditor_ClearBreakpoint(getEleHandle());
		}


		//@参数 hEle 元素句柄
		//@参数 iRow 行索引
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名 代码编辑框_置当前运行()
		bool SetRunRow(int iRow) {
			return XEditor_SetRunRow(getEleHandle(), iRow);
		}

		//@参数 hEle 元素句柄
		//@参数 pInfo 颜色信息结构体指针
		//@别名 代码编辑框_取颜色信息()
		void GetColor(editor_color_* pInfo) {
			XEditor_GetColor(getEleHandle(), pInfo);
		}

		//@参数 hEle 元素句柄
		//@参数 pInfo 颜色信息结构体指针
		//@别名 代码编辑框_置颜色()
		void SetColor(editor_color_* pInfo) {
			XEditor_SetColor(getEleHandle(), pInfo);
		}


		//@参数 hEle 元素句柄
		//@返回 返回断点数量
		//@别名 代码编辑框_取断点数量()
		int GetBreakpointCount() {
			return XEditor_GetBreakpointCount(getEleHandle());
		}

		//@参数 hEle 元素句柄
		//@参数 nDelay 延迟值毫秒
		//@别名 代码编辑框_置提示信息延迟()
		void SetTipsDelay(int nDelay) {
			return XEditor_SetTipsDelay(getEleHandle(), nDelay);
		}

		//@参数 hEle 元素句柄
		//@参数 model 0:回车选择, 1:空格选择, 3:tab键选择
		//@别名 代码编辑框_置自动匹配选择模式()
		void SetAutoMatchSelectModel( int model) {
			XEditor_SetAutoMatchSelectModel(getEleHandle(), model);
		}


		//@参数 hEle 元素句柄
		//@参数 aPoints 接收断点数组
		//@参数 nCount 数组大小
		//@返回 返回实际获取断点数量
		//@别名 代码编辑框_取全部断点()
		int GetBreakpoints(int* aPoints, int nCount) {
			return XEditor_GetBreakpoints(getEleHandle(), aPoints, nCount);
		}

		//@备注 跳过收缩行
		//@参数 hEle 元素句柄
		//@参数 iRow 行索引
		//@别名 代码编辑框_设置当前行()
		void SetCurRow(int iRow) {
			XEditor_SetCurRow(getEleHandle(), iRow);
		}

		//@参数 hEle 元素句柄
		//@参数 iRow 行索引
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名 代码编辑框_获取深度()
		int GetDepth(int iRow) {
			return XEditor_GetDepth(getEleHandle(), iRow);
		}

		//@备注 跳过收缩行
		//@参数 hEle 元素句柄
		//@参数 iRow 行索引
		//@返回 返回展开行索引
		//@别名 代码编辑框_转换到展开行()
		int ToExpandRow(int iRow) {
			return XEditor_ToExpandRow(getEleHandle(), iRow);
		}

		//@备注 完全展开指定行,例如:行包含在折叠内容中,将其展开
		//@参数 hEle 元素句柄
		//@参数 iRow 行索引
		//@别名 代码编辑框_展开扩展()
		void ExpandEx(int iRow) {
			XEditor_ExpandEx(getEleHandle(), iRow);
		}

		//@参数 hEle 元素句柄
		//@参数 bExpand 是否展开
		//@别名 代码编辑框_展开全部()
		void ExpandAll(bool bExpand) {
			XEditor_ExpandAll(getEleHandle(), bExpand);
		}

		//@参数 hEle 元素句柄
		//@参数 iRow 行索引
		//@参数 bExpand 是否展开
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名 代码编辑框_展开指定行()
		void Expand(int iRow, bool bExpand) {
			XEditor_Expand(getEleHandle(), iRow, bExpand);
		}

		//@备注 如果已存在,那么仅更新样式
		//@参数 hEle 元素句柄
		//@参数 pKey 字符串
		//@参数 iStyle 样式
		//@别名 代码编辑框_添加关键字()
		void AddKeyword(const std::wstring& key, int iStyle) {
			XEditor_AddKeyword(getEleHandle(), key.c_str(), iStyle);
		}

		//@参数 hEle 元素句柄
		//@参数 pKey 字符串
		//@别名 代码编辑框_添加自动匹配字符串()
		void AddConst(const std::wstring& key) {
			XEditor_AddConst(getEleHandle(), key.c_str());
		}

		//@参数 hEle 元素句柄
		//@参数 pKey 字符串
		//@别名 代码编辑框_添加自动匹配函数()
		void AddFunction(const std::wstring& key) {
			XEditor_AddFunction(getEleHandle(), key.c_str());
		}

		//@备注 排除定义变量的关键字, 用于排除定义变量, 因为定义变量禁用自动匹配;
		//@参数 hEle 元素句柄
		//@参数 pKeyword 字符串
		//@别名 代码编辑框_添加排除定义变量关键字()
		void AddExcludeDefVarKeyword(const std::wstring& keyword) {
			return XEditor_AddExcludeDefVarKeyword(getEleHandle(), keyword.c_str());
		}

		// 代码编辑框_置自动匹配结果显示模式  	0:中英文, 1:英文, 3:中文
		void SetAutoMatchMode(int mode) {
			XEditor_SetAutoMatchMode(getEleHandle(), mode);
		}

	};
}