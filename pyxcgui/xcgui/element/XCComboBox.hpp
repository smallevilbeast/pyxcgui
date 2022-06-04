#pragma once
#include "pch.h"
#include "xcgui/element/XCEdit.hpp"

namespace xcgui {


	class XCComboBox : public XCEdit
	{

	public:
		XCComboBox(HELE handle)
		{

			m_handle = handle;
		}

		XCComboBox() = default;

		XCComboBox(int x, int y, int width, int height, HXCGUI parent = NULL) {

			m_handle = XComboBox_Create(x, y, width, height, parent);
		}

		//@备注 设置选择项.  
		//@参数 iIndex 项索引.
		//@返回 成功返回否则返回FALSE.
		//@别名  置选择项()
		bool SetSelItem(int iIndex) {
			return XComboBox_SetSelItem(getEleHandle(), iIndex);
		}

		//@返回 返回数据适配器句柄
		//@别名  创建数据适配器()
		HXCGUI CreateAdapter() {
			return XComboBox_CreateAdapter(getEleHandle());
		}

		//@备注 绑定数据适配器.  
		//@参数 hAdapter 适配器句柄.
		//@别名  绑定数据适配器()
		void BindAdapter(HXCGUI hAdapter) {
			XComboBox_BindAdapter(getEleHandle(), hAdapter);
		}

		//@备注 获取绑定的数据适配器.  
		//@返回 返回数据适配器.
		//@别名  取数据适配器()
		HXCGUI GetAdapter() {
			return XComboBox_GetAdapter(getEleHandle());
		}

		//@备注 设置绑定数据适配器字段名.  
		//@参数 name.c_str() 字段名
		//@别名  置绑定名称()
		void SetBindName(const std::wstring& name) {
			XComboBox_SetBindName(getEleHandle(), name.c_str());
		}

		//@备注 获取下拉按钮坐标.  
		//@参数 pRect 坐标.
		//@别名  取下拉按钮坐标()
		void GetButtonRect(RECT* pRect) {
			XComboBox_GetButtonRect(getEleHandle(), pRect);
		}

		//@备注 设置下拉按钮大小.  
		//@参数 size 大小.
		//@别名  置下拉按钮大小()
		void SetButtonSize(int size) {
			XComboBox_SetButtonSize(getEleHandle(), size);
		}

		//@备注 设置下拉列表允许的最大高度, 
		//@参数 height 高度, -1自动计算高度
		//@别名  置下拉列表高度()
		void SetDropHeight(int height) {
			XComboBox_SetDropHeight(getEleHandle(), height);
		}

		//@备注 获取下拉列表高度.  
		//@返回 下拉列表高度.
		//@别名  取下拉列表高度()
		int GetDropHeight() {
			return XComboBox_GetDropHeight(getEleHandle());
		}

		//@备注 设置下拉列表项模板文件
		//@参数 pXmlFile 项模板文件.
		//@别名  置项模板文件()
		void SetItemTemplateXML(const std::wstring& xmlFile) {
			XComboBox_SetItemTemplateXML(getEleHandle(), xmlFile.c_str());
		}

		//@备注 设置下拉列表项模板.  
		//@参数 pStringXML 字符串指针.
		//@别名  置项模板从字符串()
		void SetItemTemplateXMLFromString(const char* pStringXML) {
			XComboBox_SetItemTemplateXMLFromString(getEleHandle(), pStringXML);
		}

		//@参数 hTemp 项模板句柄
		//@返回 如果成功返回TRUE,否则返回FALSE
		//@别名  置项模板()
		bool SetItemTemplate(HTEMP hTemp) {
			return XComboBox_SetItemTemplate(getEleHandle(), hTemp);
		}

		//@备注 是否绘制下拉按钮.  
		//@参数 bEnable 是否绘制.
		//@别名  启用绘制下拉按钮()
		void EnableDrawButton(bool bEnable) {
			XComboBox_EnableDrawButton(getEleHandle(), bEnable);
		}

		//@备注 启用可编辑显示的文本内容.  
		//@参数 bEdit TRUE可编辑,否则相反.
		//@别名  启用编辑()
		void EnableEdit(bool bEdit) {
			XComboBox_EnableEdit(getEleHandle(), bEdit);
		}

		//@备注 启用/关闭下拉列表高度固定大小.  
		//@参数 bEnable 是否启用
		//@别名  启用下拉列表高度固定大小()
		void EnableDropHeightFixed(bool bEnable) {
			XComboBox_EnableDropHeightFixed(getEleHandle(), bEnable);
		}

		//@返回 如果成功返回TRUE,否则返回FALSE
		//@别名  弹出下拉列表()
		void PopupDropList() {
			XComboBox_PopupDropList(getEleHandle());
		}

		//@备注 获取组合框下拉列表中选择项索引.  
		//@返回 返回项索引.
		//@别名  取选择项()
		int GetSelItem() {
			return XComboBox_GetSelItem(getEleHandle());
		}

		//@备注 获取状态.  
		//@返回 状态.
		//@别名  取状态()
		comboBox_state_ GetState() {
			return XComboBox_GetState(getEleHandle());
		}

		//@参数 text.c_str() 
		//@返回 返回项索引
		//@别名  添加项文本()
		int AddItemText(const std::wstring& text) {
			return XComboBox_AddItemText(getEleHandle(), text.c_str());
		}

		//@参数 name.c_str() 字段名
		//@参数 text.c_str() 文本
		//@返回 返回项索引
		//@别名  添加项文本扩展()
		int AddItemTextEx(const std::wstring& name, const std::wstring& text) {
			return XComboBox_AddItemTextEx(getEleHandle(), name.c_str(), text.c_str());
		}

		//@参数 hImage 图片句柄
		//@返回 返回项索引
		//@别名  添加项图片()
		int AddItemImage(HIMAGE hImage) {
			return XComboBox_AddItemImage(getEleHandle(), hImage);
		}

		//@参数 name.c_str() 字段名
		//@参数 hImage 图片句柄
		//@返回 返回项索引
		//@别名  添加项图片扩展()
		int AddItemImageEx(const std::wstring& name, HIMAGE hImage) {
			return XComboBox_AddItemImageEx(getEleHandle(), name.c_str(), hImage);
		}

		//@参数 iItem 项索引
		//@参数 text.c_str() 文本
		//@返回 返回项索引
		//@别名  插入项文本()
		int InsertItemText(int iItem, const std::wstring& value) {
			return XComboBox_InsertItemText(getEleHandle(), iItem, value.c_str());
		}

		//@参数 iItem 项索引
		//@参数 name.c_str() 字段名
		//@参数 text.c_str() 文本
		//@返回 返回项索引
		//@别名  插入项文本扩展()
		int InsertItemTextEx(int iItem, const std::wstring& name, const std::wstring& value) {
			return XComboBox_InsertItemTextEx(getEleHandle(), iItem, name.c_str(), value.c_str());
		}

		//@参数 iItem 项索引
		//@参数 hImage 图片句柄
		//@返回 返回项索引
		//@别名  插入项图片()
		int InsertItemImage(int iItem, HIMAGE hImage) {
			return XComboBox_InsertItemImage(getEleHandle(), iItem, hImage);
		}

		//@参数 iItem 项索引
		//@参数 name.c_str() 字段名
		//@参数 hImage 图片句柄
		//@返回 返回项索引
		//@别名  插入项图片扩展()
		int InsertItemImageEx(int iItem, const std::wstring& name, HIMAGE hImage) {
			return XComboBox_InsertItemImageEx(getEleHandle(), iItem, name.c_str(), hImage);
		}

		//@参数 iItem 项索引
		//@参数 iColumn 列索引
		//@参数 text.c_str() 文本
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项文本()
		bool SetItemText(int iItem, int iColumn, const std::wstring& text) {
			return XComboBox_SetItemText(getEleHandle(), iItem, iColumn, text.c_str());
		}

		//@参数 iItem 项索引
		//@参数 name.c_str() 字段名
		//@参数 text.c_str() 文本
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项文本扩展()
		bool SetItemTextEx(int iItem, const std::wstring& name, const std::wstring& text) {
			return XComboBox_SetItemTextEx(getEleHandle(), iItem, name.c_str(), text.c_str());
		}

		//@参数 iItem 项索引
		//@参数 iColumn 列索引
		//@参数 hImage 图片句柄
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项图片()
		bool SetItemImage(int iItem, int iColumn, HIMAGE hImage) {
			return XComboBox_SetItemImage(getEleHandle(), iItem, iColumn, hImage);
		}

		//@参数 iItem 项索引
		//@参数 name.c_str() 字段名
		//@参数 hImage 图片句柄
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项图片扩展()
		bool SetItemImageEx(int iItem, const std::wstring& name, HIMAGE hImage) {
			return XComboBox_SetItemImageEx(getEleHandle(), iItem, name.c_str(), hImage);
		}

		//@参数 iItem 项索引
		//@参数 iColumn 列索引
		//@参数 nValue 整数值
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项整数值()
		bool SetItemInt(int iItem, int iColumn, int nValue) {
			return XComboBox_SetItemInt(getEleHandle(), iItem, iColumn, nValue);
		}

		//@参数 iItem 项索引
		//@参数 name.c_str() 字段名
		//@参数 nValue 整数值
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项指数值扩展()
		bool SetItemIntEx(int iItem, const std::wstring& name, int nValue) {
			return XComboBox_SetItemIntEx(getEleHandle(), iItem, name.c_str(), nValue);
		}

		//@参数 iItem 项索引
		//@参数 iColumn 列索引
		//@参数 fFloat 浮点数
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项浮点值()
		bool SetItemFloat(int iItem, int iColumn, float fFloat) {
			return XComboBox_SetItemFloat(getEleHandle(), iItem, iColumn, fFloat);
		}

		//@参数 iItem 项索引
		//@参数 name.c_str() 字段名
		//@参数 fFloat 浮点数
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项浮点值扩展()
		bool SetItemFloatEx(int iItem, const std::wstring& name, float fFloat) {
			return XComboBox_SetItemFloatEx(getEleHandle(), iItem, name.c_str(), fFloat);
		}

		//@参数 iItem 项索引
		//@参数 iColumn 列索引
		//@返回 返回文本内容
		//@别名  取项文本()
		const wchar_t* GetItemText(int iItem, int iColumn) {
			return XComboBox_GetItemText(getEleHandle(), iItem, iColumn);
		}

		//@参数 iItem 项索引
		//@参数 name.c_str() 字段名
		//@返回 返回文本内容
		//@别名  取项文本扩展()
		const wchar_t* GetItemTextEx(int iItem, const std::wstring& name) {
			return XComboBox_GetItemTextEx(getEleHandle(), iItem, name.c_str());
		}

		//@参数 iItem 项索引
		//@参数 iColumn 列索引
		//@返回 返回图片句柄
		//@别名  取项图片()
		HIMAGE GetItemImage(int iItem, int iColumn) {
			return XComboBox_GetItemImage(getEleHandle(), iItem, iColumn);
		}

		//@参数 iItem 项索引
		//@参数 name.c_str() 字段名
		//@返回 返回图片句柄
		//@别名  取项图片扩展()
		HIMAGE GetItemImageEx(int iItem, const std::wstring& name) {
			return XComboBox_GetItemImageEx(getEleHandle(), iItem, name.c_str());
		}

		//@参数 iItem 项索引
		//@参数 iColumn 列索引
		//@参数 pOutValue 接收返回整数值
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  取项整数值()
		bool GetItemInt(int iItem, int iColumn, int* pOutValue) {
			return XComboBox_GetItemInt(getEleHandle(), iItem, iColumn, pOutValue);
		}

		//@参数 iItem 项索引
		//@参数 name.c_str() 字段名
		//@参数 pOutValue 接收返回整数值
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  取项整数值扩展()
		bool GetItemIntEx(int iItem, const std::wstring& name, int* pOutValue) {
			return XComboBox_GetItemIntEx(getEleHandle(), iItem, name.c_str(), pOutValue);
		}

		//@参数 iItem 项索引
		//@参数 iColumn 列索引
		//@参数 pOutValue 接收返回浮点值
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  取项浮点值()
		bool GetItemFloat(int iItem, int iColumn, float* pOutValue) {
			return XComboBox_GetItemFloat(getEleHandle(), iItem, iColumn, pOutValue);
		}

		//@参数 iItem 项索引
		//@参数 name.c_str() 字段名
		//@参数 pOutValue 接收返回浮点值
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  取项浮点值扩展()
		bool GetItemFloatEx(int iItem, const std::wstring& name, float* pOutValue) {
			return XComboBox_GetItemFloatEx(getEleHandle(), iItem, name.c_str(), pOutValue);
		}

		//@参数 iItem 项索引
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  删除项()
		bool DeleteItem(int iItem) {
			return XComboBox_DeleteItem(getEleHandle(), iItem);
		}

		//@参数 iItem 项索引
		//@参数 nCount 删除数量
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  删除项扩展()
		bool DeleteItemEx(int iItem, int nCount) {
			return XComboBox_DeleteItemEx(getEleHandle(), iItem, nCount);
		}

		//@别名  删除项全部()
		void DeleteItemAll() {
			XComboBox_DeleteItemAll(getEleHandle());
		}

		//@别名  删除列全部()
		void DeleteColumnAll() {
			XComboBox_DeleteColumnAll(getEleHandle());
		}

		//@返回 返回项数量
		//@别名  取项数量()
		int GetCount() {
			return XComboBox_GetCount(getEleHandle());
		}

		//@返回 返回列数量
		//@别名  取列数量()
		int GetCountColumn() {
			return XComboBox_GetCountColumn(getEleHandle());
		}

	};
}