#pragma once

#include "pch.h"
#include "xcgui/adapter/XCAdapter.hpp"

namespace xcgui {

	class XCAdapterTree : public XCAdapter
	{
	public:
		XCAdapterTree(HXCGUI handle) {
			m_handle = handle;
		}

		XCAdapterTree() {
			m_handle = XAdTree_Create();
		}
		
		//@备注 添加列.  
		//@参数 name.c_str() 字段名称.
		//@返回 返回索引值.
		//@别名  添加列()
		int AddColumn(const std::wstring& name) {
			return XAdTree_AddColumn(m_handle, name.c_str());
		}

		//@备注 设置列.  
		//@参数 pColName 列名,多个列名用逗号分开.
		//@返回 返回列数量.
		//@别名  置列()
		int SetColumn(const std::wstring& colName) {
			return XAdTree_SetColumn(m_handle, colName.c_str());
		}

		//@备注 插入项,数据填充到第一列.  
		//@参数 value.c_str() 值.
		//@参数 nParentID 父ID.
		//@参数 insertID 插入位置ID.
		//@返回 返回项ID值.
		//@别名  插入项文本()
		int InsertItemText(const std::wstring& value, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST) {
			return XAdTree_InsertItemText(m_handle, value.c_str(), nParentID, insertID);
		}

		//@备注 插入项,数据填充到指定列.  
		//@参数 name.c_str() 字段名称.
		//@参数 value.c_str() 值.
		//@参数 nParentID 父ID.
		//@参数 insertID 插入位置ID.
		//@返回 返回项ID值.
		//@别名  插入项文本扩展()
		int InsertItemTextEx(const std::wstring& name, const std::wstring& value, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST) {
			return XAdTree_InsertItemTextEx(m_handle, name.c_str(), value.c_str(), nParentID, insertID);
		}

		//@备注 插入项,数据填充到第一列.  
		//@参数 hImage 图片句柄.
		//@参数 nParentID 父ID.
		//@参数 insertID 插入位置ID.
		//@返回 返回项ID值.
		//@别名  插入项图片()
		int InsertItemImage(HIMAGE hImage, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST) {
			return XAdTree_InsertItemImage(m_handle, hImage, nParentID, insertID);
		}

		//@备注 插入项,数据填充到指定列.  
		//@参数 name.c_str() 字段名称.
		//@参数 hImage 图片句柄.
		//@参数 nParentID 父ID.
		//@参数 insertID 插入位置ID.
		//@返回 返回项ID值.
		//@别名  插入项图片扩展()
		int InsertItemImageEx(const std::wstring& name, HIMAGE hImage, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST) {
			return XAdTree_InsertItemImageEx(m_handle, name.c_str(), hImage, nParentID, insertID);
		}

		//@备注 获取项数量.  
		//@返回 返回数量.
		//@别名  取项数量()
		int GetCount() {
			return XAdTree_GetCount(m_handle);
		}

		//@备注 获取列数量.  
		//@返回 返回列数量.
		//@别名  取列数量()
		int GetCountColumn() {
			return XAdTree_GetCountColumn(m_handle);
		}

		//@备注 设置项数据.  
		//@参数 nID 项ID.
		//@参数 iColumn 列索引.
		//@参数 value.c_str() 值.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置项文本()
		bool SetItemText(int nID, int iColumn, const std::wstring& value) {
			return XAdTree_SetItemText(m_handle, nID, iColumn, value.c_str());
		}

		//@备注 设置项文件内容.  
		//@参数 nID 项ID.
		//@参数 name.c_str() 字段名称.
		//@参数 value.c_str() 值.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置项文本扩展()
		bool SetItemTextEx(int nID, const std::wstring& name, const std::wstring& value) {
			return XAdTree_SetItemTextEx(m_handle, nID, name.c_str(), value.c_str());
		}

		//@备注 设置项数据.  
		//@参数 nID 项ID.
		//@参数 iColumn 列索引.
		//@参数 hImage 图片句柄.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置项图片()
		bool SetItemImage(int nID, int iColumn, HIMAGE hImage) {
			return XAdTree_SetItemImage(m_handle, nID, iColumn, hImage);
		}

		//@备注 设置项内容.  
		//@参数 nID 项ID.
		//@参数 name.c_str() 字段名称.
		//@参数 hImage 图片句柄.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置项图片扩展()
		bool SetItemImageEx(int nID, const std::wstring& name, HIMAGE hImage) {
			return XAdTree_SetItemImageEx(m_handle, nID, name.c_str(), hImage);
		}

		//@备注 获取项文本内容.  
		//@参数 nID 项ID.
		//@参数 iColumn 列索引.
		//@返回 返回文本内容
		//@别名  取项文本()
		std::wstring GetItemText(int nID, int iColumn) {
			auto pText = XAdTree_GetItemText(m_handle, nID, iColumn);
			if (!pText) return L"";
			return pText;
		}

		//@备注 获取项文本内容.  
		//@参数 nID 项ID.
		//@参数 name.c_str() 字段名称.
		//@返回 返回文本内容
		//@别名  取项文本扩展()
		std::wstring GetItemTextEx(int nID, const std::wstring& name) {
			auto pText = XAdTree_GetItemTextEx(m_handle, nID, name.c_str());
			if (!pText) return L"";
			return pText;
		}

		//@备注 获取项内容.  
		//@参数 nID 项ID.
		//@参数 iColumn 列索引.
		//@返回 返回图片句柄.
		//@别名  取项图片()
		HIMAGE GetItemImage(int nID, int iColumn) {
			return XAdTree_GetItemImage(m_handle, nID, iColumn);
		}

		//@备注 获取项内容.  
		//@参数 nID 项ID.
		//@参数 name.c_str() 字段名称.
		//@返回 返回图片句柄.
		//@别名  取项图片扩展()
		HIMAGE GetItemImageEx(int nID, const std::wstring& name) {
			return XAdTree_GetItemImageEx(m_handle, nID, name.c_str());
		}

		//@备注 删除项.  
		//@参数 nID 项ID.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  删除项()
		bool DeleteItem(int nID) {
			return XAdTree_DeleteItem(m_handle, nID);
		}

		//@备注 删除所有项.  
		//@别名  删除项全部()
		void DeleteItemAll() {
			XAdTree_DeleteItemAll(m_handle);
		}

		//@备注 删除所有列,并且清空数据.  
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  删除列全部()
		void DeleteColumnAll() {
			XAdTree_DeleteColumnAll(m_handle);
		}


	};
}