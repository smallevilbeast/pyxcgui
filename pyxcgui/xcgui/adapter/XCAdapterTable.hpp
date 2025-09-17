#pragma once

#include "pch.h"
#include "xcgui/adapter/XCAdapter.hpp"

namespace xcgui {

	class XCAdapterTable : public XCAdapter
	{
	public:
		XCAdapterTable(HXCGUI handle) {
			m_handle = handle;
		}

		XCAdapterTable() {
			m_handle = XAdTable_Create();
		}

		//@备注 对内容进行排序.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iColumn 要排序的列索引。
		//@参数 bAscending 是否按照升序方式排序.
		//@别名 数据适配器表_排序()
		void Sort(int iColumn, bool bAscending) {
			XAdTable_Sort(m_handle, iColumn, bAscending);
		}

		//@备注 获取项数据类型.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 项索引.
		//@参数 iColumn 列索引.
		//@返回 返还项数据类型 @ref adapter_date_type_ .
		//@别名 数据适配器表_取项数据类型()
		adapter_date_type_ GetItemDataType(int iItem, int iColumn) {
			return XAdTable_GetItemDataType(m_handle, iItem, iColumn);
		}

		//@备注 获取项数据类型.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 项索引.
		//@参数 pName 字段称.
		//@返回 返还项数据类型 @ref adapter_date_type_ .
		//@别名 数据适配器表_取项数据类型扩展()
		adapter_date_type_  GetItemDataTypeEx(int iItem, const std::wstring& name)
		{
			return XAdTable_GetItemDataTypeEx(m_handle, iItem, name.c_str());
		}

		//@备注 添加数据列.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 pName 字段称.
		//@返回 返回列索引.
		//@别名 数据适配器表_添加列()
		int AddColumn(const std::wstring& name) {
			return XAdTable_AddColumn(m_handle, name.c_str());
		}


		//@备注 设置列.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 pColName 列名,多个列名用逗号分开.
		//@返回 返回列数量.
		//@别名 数据适配器表_置列()
		int SetColumn(const std::wstring& colName) {
			return XAdTable_SetColumn(m_handle, colName.c_str());
		}

		//@备注 添加数据项,默认值放到第一列.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 pValue 值.
		//@返回 返回项索引值.
		//@别名 数据适配器表_添加项文本()
		int AddItemText(const std::wstring& value)
		{
			return XAdTable_AddItemText(m_handle, value.c_str());
		}

		//@备注 添加数据项,填充指定列数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 pName 字段称.
		//@参数 pValue 值.
		//@返回 返回项索引.
		//@别名 数据适配器表_添加项文本扩展()
		int AddItemTextEx(const std::wstring& name, const std::wstring& value) {
			return XAdTable_AddItemTextEx(m_handle, name.c_str(), value.c_str());
		}


		//@备注 添加数据项,默认值放到第一列.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 hImage 图片句柄.
		//@返回 返回项索引值.
		//@别名 数据适配器表_添加项图片()
		int AddItemImage(HIMAGE hImage) {
			return XAdTable_AddItemImage(m_handle, hImage);
		}


		//@备注 添加数据项,并填充指定列数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 pName 字段称.
		//@参数 hImage 图片句柄.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器表_添加项图片扩展()
		int AddItemImageEx(const std::wstring& name, HIMAGE hImage) {
			return XAdTable_AddItemImageEx(m_handle, name.c_str(), hImage);
		}

		//@备注 插入数据项,填充第一列数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 插入位置索引.
		//@参数 pValue 值.
		//@返回 返回项索引.
		//@别名 数据适配器表_插入项文本()
		int  InsertItemText(int iItem, const std::wstring& value) {
			return XAdTable_InsertItemText(m_handle, iItem, value.c_str());
		}


		//@备注 插入数据项,并填充指定列数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 插入位置索引.
		//@参数 pName 字段称.
		//@参数 pValue 值.
		//@返回 返回项索引.
		//@别名 数据适配器表_插入项文本扩展()
		int InsertItemTextEx(int iItem, const std::wstring& name, const std::wstring& value) {
			return XAdTable_InsertItemTextEx(m_handle, iItem, name.c_str(), value.c_str());
		}


		//@备注 插入数据项,填充第一列数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 插入位置索引.
		//@参数 hImage 图片句柄.
		//@返回 返回项索引.
		//@别名 数据适配器表_插入项图片()
		int InsertItemImage(int iItem, HIMAGE hImage) {
			return XAdTable_InsertItemImage(m_handle, iItem, hImage);
		}


		//@备注 插入数据项,并填充指定列数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 插入位置索引.
		//@参数 pName 字段称.
		//@参数 hImage 图片句柄.
		//@返回 返回项索引.
		//@别名 数据适配器表_插入项图片扩展()
		int InsertItemImageEx(int iItem, const std::wstring& name, HIMAGE hImage) {
			return 	XAdTable_InsertItemImageEx(m_handle, iItem, name.c_str(), hImage);
		}


		//@备注 设置项数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 项索引.
		//@参数 iColumn 列索引.
		//@参数 pValue 值.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器表_置项文本()
		bool SetItemText(int iItem, int iColumn, const std::wstring& value) {
			return XAdTable_SetItemText(m_handle, iItem, iColumn, value.c_str());
		}


		//@备注 设置项数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 项索引.
		//@参数 pName 字段称.
		//@参数 pValue 值.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器表_置项文本扩展()
		bool SetItemTextEx(int iItem, const std::wstring& name, const std::wstring& value) {
			return XAdTable_SetItemTextEx(m_handle, iItem, name.c_str(), value.c_str());
		}


		//@备注 设置项数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 项索引.
		//@参数 iColumn 列索引.
		//@参数 nValue 值.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器表_置项整数值()
		bool SetItemInt(int iItem, int iColumn, int nValue) {
			return XAdTable_SetItemInt(m_handle, iItem, iColumn, nValue);
		}


		//@备注 设置项数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 项索引.
		//@参数 pName 字段称.
		//@参数 nValue 值.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器表_置项整数值扩展()
		bool  SetItemIntEx(int iItem, const std::wstring& name, int nValue) {
			return XAdTable_SetItemIntEx(m_handle, iItem, name.c_str(), nValue);
		}


		//@备注 设置项数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 项索引.
		//@参数 iColumn 列索引.
		//@参数 fValue 值.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器表_置项浮点值()
		bool SetItemFloat(int iItem, int iColumn, float nValue) {
			return XAdTable_SetItemFloat(m_handle, iItem, iColumn, nValue);
		}


		//@备注 设置项数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 项索引.
		//@参数 pName 字段称.
		//@参数 fValue 值.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器表_置项浮点值扩展()
		bool  SetItemFloatEx(int iItem, const std::wstring& name, float nValue) {
			return XAdTable_SetItemFloatEx(m_handle, iItem, name.c_str(), nValue);
		}


		//@备注 设置项数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 项索引.
		//@参数 iColumn 列索引.
		//@参数 hImage 图片句柄.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器表_置项图片()
		bool SetItemImage(int iItem, int iColumn, HIMAGE hImage) {
			return XAdTable_SetItemImage(m_handle, iItem, iColumn, hImage);
		}


		//@备注 设置项数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 项索引.
		//@参数 pName 字段称.
		//@参数 hImage 图片句柄.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器表_置项图片扩展()
		bool SetItemImageEx(int iItem, const std::wstring& name, HIMAGE hImage) {
			return XAdTable_SetItemImageEx(m_handle, iItem, name.c_str(), hImage);
		}


		//@备注 删除项.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 项索引.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器表_删除项()
		bool DeleteItem(int iItem) {
			return XAdTable_DeleteItem(m_handle, iItem);
		}

		//@备注 删除多个项.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 项起始索引.
		//@参数 nCount 删除项数量.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器表_删除项扩展()
		bool DeleteItemEx(int iItem, int nCount) {
			return XAdTable_DeleteItemEx(m_handle, iItem, nCount);
		}


		//@备注 删除所有项.  
		//@参数 hAdapter 数据适配器句柄.
		//@别名 数据适配器表_删除项全部()
		void DeleteItemAll() {
			XAdTable_DeleteItemAll(m_handle);
		}


		//@备注 删除所有列,并且清空所有数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@别名 数据适配器表_删除列全部()
		void DeleteColumnAll() {
			XAdTable_DeleteColumnAll(m_handle);
		}


		//@备注 获取项数量.  
		//@参数 hAdapter 数据适配器句柄.
		//@返回 返回数量.
		//@别名 数据适配器表_取项数量()
		int GetCount() {
			return XAdTable_GetCount(m_handle);
		}


		//@备注 获取列数量.  
		//@参数 hAdapter 数据适配器句柄.
		//@返回 返回列数量.
		//@别名 数据适配器表_取列数量()
		int GetCountColumn() {
			return XAdTable_GetCountColumn(m_handle);
		}


		//@备注 获取项文本内容.  
		//@参数 hAdapter 数据适配器句柄
		//@参数 iItem 项索引
		//@参数 iColumn 列索引
		//@返回 返回文本内容
		//@别名 数据适配器表_取项文本()
		std::wstring GetItemText(int iItem, int iColumn) {
			auto pText = XAdTable_GetItemText(m_handle, iItem, iColumn);
			if (!pText) {
				return L"";
			}
			return pText;
		}

		//@备注 获取项文本内容.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 项索引.
		//@参数 pName 字段称.
		//@返回 返回文本内容
		//@别名 数据适配器表_取项文本扩展()
		std::wstring GetItemTextEx(int iItem, const std::wstring& name) {
			auto pText = XAdTable_GetItemTextEx(m_handle, iItem, name.c_str());
			if (!pText) return L"";
			return pText;
		}


		//@备注 获取项图片句柄.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 项索引.
		//@参数 iColumn 列索引.
		//@返回 返回图片句柄.
		//@别名 数据适配器表_取项图片()
		HIMAGE GetItemImage(int iItem, int iColumn) {
			return XAdTable_GetItemImage(m_handle, iItem, iColumn);
		}


		//@备注 获取项图片句柄.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 项索引.
		//@参数 pName 字段称.
		//@返回 返回图片句柄.
		//@别名 数据适配器表_取项图片扩展()
		HIMAGE GetItemImageEx(int iItem, const std::wstring& name) {
			return XAdTable_GetItemImageEx(m_handle, iItem, name.c_str());
		}


		//@备注 获取项值.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 项索引.
		//@参数 iColumn 列索引.
		//@参数 pOutValue 接收返还值.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器表_取项整数值()
		bool GetItemInt(int iItem, int iColumn, int* pOutValue) {
			return XAdTable_GetItemInt(m_handle, iItem, iColumn, pOutValue);
		}


		//@备注 获取项值.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 项索引.
		//@参数 pName 字段称.
		//@参数 pOutValue 接收返还值.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器表_取项整数值扩展()
		bool GetItemIntEx(int iItem, const std::wstring& name, int* pOutValue) {
			return XAdTable_GetItemIntEx(m_handle, iItem, name.c_str(), pOutValue);
		}


		//@备注 获取项值.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 项索引.
		//@参数 iColumn 列索引.
		//@参数 pOutValue 接收返还值.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器表_取项浮点值()
		bool GetItemFloat(int iItem, int iColumn, float* pOutValue) {
			return XAdTable_GetItemFloat(m_handle, iItem, iColumn, pOutValue);
		}


		//@备注 获取项值.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iItem 项索引.
		//@参数 pName 字段称.
		//@参数 pOutValue 接收返还值.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器表_取项浮点值扩展()
		bool GetItemFloatEx(int iItem, const std::wstring& name, float* pOutValue) {
			return XAdTable_GetItemFloatEx(m_handle, iItem, name.c_str(), pOutValue);
		}
	};

}