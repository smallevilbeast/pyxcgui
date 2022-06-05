#pragma once

#include "pch.h"
#include "xcgui/adapter/XCAdapter.hpp"

namespace xcgui {

	class XCAdapterListView : public XCAdapter
	{
	public:
		XCAdapterListView(HXCGUI handle) {
			m_handle = handle;
		}

		XCAdapterListView() {
			m_handle = XAdListView_Create();
		}

		//@备注 组操作,添加数据列.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 pName 字段名称.
		//@返回 返回列索引.
		//@别名 数据适配器列表视_组添加列()
		int GroupAddColumn(const std::wstring& name) {
			return XAdListView_Group_AddColumn(m_handle, name.c_str());
		}

		//@备注 组操作,添加组,数据默认填充到第一列.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 pValue 值.
		//@参数 iPos 插入位置, -1添加到末尾
		//@返回 返回组索引.
		//@别名 数据适配器列表视_添加组文本()
		int GroupAddItemText(const std::wstring& value, int iPos = -1) {
			return XAdListView_Group_AddItemText(m_handle, value.c_str(), iPos);
		}

		//@备注 组操作,添加组,数据填充指定列.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 pName 字段名称.
		//@参数 pValue 值.
		//@参数 iPos 插入位置, -1添加到末尾
		//@返回 返回组索引.
		//@别名 数据适配器列表视_添加组文本扩展()
		int GroupAddItemTextEx(const std::wstring& name, const std::wstring& value, int iPos = -1) {
			return XAdListView_Group_AddItemTextEx(m_handle, name.c_str(), value.c_str(), iPos);
		}

		//@备注 组操作,添加组,数据默认填充第一列.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 hImage 图片句柄.
		//@参数 iPos 插入位置, -1添加到末尾
		//@返回 返回组索引.
		//@别名 数据适配器列表视_添加组图片()
		int GroupAddItemImage(HIMAGE hImage, int iPos = -1) {
			return XAdListView_Group_AddItemImage(m_handle, hImage, iPos);
		}

		//@备注 组操作,添加组,数据填充指定列.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 pName 字段名称.
		//@参数 hImage 图片句柄.
		//@参数 iPos 插入位置, -1添加到末尾
		//@返回 返回组索引.
		//@别名 数据适配器列表视_添加组图片扩展()
		int GroupAddItemImageEx(const std::wstring& name, HIMAGE hImage, int iPos = -1)
		{
			return 	XAdListView_Group_AddItemImageEx(m_handle, name.c_str(), hImage, iPos);
		}
		
		//@备注 组操作,设置指定项数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@参数 iColumn 列索引.
		//@参数 pValue 值.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器列表视_组设置文本()
		bool GroupSetText(int iGroup, int iColumn, const std::wstring& value) {
			return XAdListView_Group_SetText(m_handle, iGroup, iColumn, value.c_str());
		}
		
		//@备注 组操作,设置指定项数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@参数 pName 字段名.
		//@参数 pValue 值.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器列表视_组设置文本扩展()
		bool GroupSetTextEx(int iGroup, const std::wstring& name, const std::wstring& value) {
			return XAdListView_Group_SetTextEx(m_handle, iGroup, name.c_str(), value.c_str());
		}

		//@备注 组操作,设置指定项数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@参数 iColumn 列索引.
		//@参数 hImage 图片句柄.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器列表视_组设置图片()
		bool GroupSetImage(int iGroup, int iColumn, HIMAGE hImage) {
			return XAdListView_Group_SetImage(m_handle, iGroup, iColumn, hImage);
		}

		//@备注 组操作,设置指定项数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@参数 pName 字段名.
		//@参数 hImage 图片句柄.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器列表视_组设置图片扩展()
		bool GroupSetImageEx(int iGroup, const std::wstring& name, HIMAGE hImage) {
			return XAdListView_Group_SetImageEx(m_handle, iGroup, name.c_str(), hImage);
		}

		//@参数 hAdapter 数据适配器句柄
		//@参数 iGroup 组索引
		//@参数 iColumn 列索引
		//@返回 返回文本内容
		//@别名 数据适配器列表视_组取文本()
		std::wstring GroupGetText(int iGroup, int iColumn) {
			auto pText = XAdListView_Group_GetText(m_handle, iGroup, iColumn);
			if (!pText) return L"";
			return pText;
		}
		
		//@参数 hAdapter 数据适配器句柄
		//@参数 iGroup 组索引
		//@参数 pName 字段名称
		//@返回 返回文本内容
		//@别名 数据适配器列表视_组取文本扩展()
		std::wstring GroupGetTextEx(int iGroup, const std::wstring& name) {
			return XAdListView_Group_GetTextEx(m_handle, iGroup, name.c_str());
		}
		
		//@参数 hAdapter 数据适配器句柄
		//@参数 iGroup 组索引
		//@参数 iColumn 列索引
		//@返回 返回图片句柄
		//@别名 数据适配器列表视_组取图片()
		HIMAGE GroupGetImage(int iGroup, int iColumn) {
			return XAdListView_Group_GetImage(m_handle, iGroup, iColumn);
		}


		//@参数 hAdapter 数据适配器句柄
		//@参数 iGroup 组索引
		//@参数 pName 字段名称
		//@返回 返回图片句柄
		//@别名 数据适配器列表视_组取图片扩展()
		HIMAGE GroupGetImageEx(int iGroup, const std::wstring& name) {
			return XAdListView_Group_GetImageEx(m_handle, iGroup, name.c_str());
		}

		//@备注 项操作,添加列.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 pName 字段名称.
		//@返回 返回列索引.
		//@别名 数据适配器列表视_项添加列()
		int ItemAddColumn(const std::wstring& name) {
			return XAdListView_Item_AddColumn(m_handle, name.c_str());
		}


		//@备注 组操作,获取组数量.  
		//@参数 hAdapter 数据适配器句柄.
		//@返回 返回组数量.
		//@别名 数据适配器列表视_取组数量()
		int GroupGetCount() {
			return XAdListView_Group_GetCount(m_handle);
		 }
		
		//@备注 项操作,获取指定组中项数量.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@返回 成功返回项数量,否则返回 @ref XC_ID_ERROR.
		//@别名 数据适配器列表视_取组中项数量()
		int ItemGetCount(int iGroup) {
			return XAdListView_Item_GetCount(m_handle, iGroup);
		}


		//@备注 项操作,添加项.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@参数 pValue 值.
		//@参数 iPos 插入位置, -1添加到末尾
		//@返回 返回项索引.
		//@别名 数据适配器列表视_添加项文本()
		int ItemAddItemText(int iGroup, const std::wstring& value, int iPos = -1) {
			return XAdListView_Item_AddItemText(m_handle, iGroup, value.c_str(), iPos);
		}

		//@备注 项操作,添加项,数据填充指定列.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@参数 pName 字段名称.
		//@参数 pValue 值.
		//@参数 iPos 插入位置, -1添加到末尾
		//@返回 返回项索引.
		//@别名 数据适配器列表视_添加项文本扩展()
		int ItemAddItemTextEx(int iGroup, const std::wstring& name, const std::wstring& value, int iPos = -1) {
			return XAdListView_Item_AddItemTextEx(m_handle, iGroup, name.c_str(), value.c_str(), iPos);
		}

		
		//@备注 项操作,添加项.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@参数 hImage 图片句柄.
		//@参数 iPos 插入位置, -1添加到末尾
		//@返回 返回项索引.
		//@别名 数据适配器列表视_添加项图片()
		int ItemAddItemImage(int iGroup, HIMAGE hImage, int iPos = -1) {
			return XAdListView_Item_AddItemImage(m_handle, iGroup, hImage, iPos);
		}


		//@备注 项操作,添加项,填充指定列数据.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@参数 pName 字段名称.
		//@参数 hImage 图片句柄.
		//@参数 iPos 插入位置, -1添加到末尾
		//@返回 返回项索引.
		//@别名 数据适配器列表视_添加项图片扩展()
		int ItemAddItemImageEx(int iGroup, const std::wstring& name, HIMAGE hImage, int iPos = -1) {
			return 	XAdListView_Item_AddItemImageEx(m_handle, iGroup, name.c_str(), hImage, iPos);
		}

		//@备注 删除组,自动删除子项.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器列表视_组删除项()
		bool GroupDeleteItem(int iGroup) {
			return 	XAdListView_Group_DeleteItem(m_handle, iGroup);
		}
		
		//@备注 删除指定组的所有子项.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@别名 数据适配器列表视_删除全部子项()
		void GroupDeleteAllChildItem(int iGroup) {
			XAdListView_Group_DeleteAllChildItem(m_handle, iGroup);
		}

		//@备注 删除项.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@参数 iItem 项索引.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器列表视_删除项()
		bool ItemDeleteItem(int iGroup, int iItem) {
			return 	XAdListView_Item_DeleteItem(m_handle, iGroup, iItem);
		}


		//@备注 删除所有(组,项,列).  
		//@参数 hAdapter 数据适配器句柄.
		//@别名 数据适配器列表视_删除全部()
		void DeleteAll() {
			XAdListView_DeleteAll(m_handle);
		}

		//@备注 删除所有的组.  
		//@参数 hAdapter 数据适配器句柄.
		//@别名 数据适配器列表视_删除全部组()
		void DeleteAllGroup() {
			return XAdListView_DeleteAllGroup(m_handle);
		}

		//@备注 删除所有的项.  
		//@参数 hAdapter 数据适配器句柄.
		//@别名 数据适配器列表视_删除全部项()
		void DeleteAllItem() {
			return XAdListView_DeleteAllItem(m_handle);
		}


		//@备注 删除组的列.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iColumn 列索引.
		//@别名 数据适配器列表视_组删除列()
		void DeleteColumnGroup(int iColumn) {
			XAdListView_DeleteColumnGroup(m_handle, iColumn);
		}

		//@备注 删除项的列.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iColumn 列索引.
		//@别名 数据适配器列表视_项删除列()
		void DeleteColumnItem(int iColumn) {
			XAdListView_DeleteColumnItem(m_handle, iColumn);
		}

		//@备注 项操作,获取项文本内容.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@参数 iItem 项索引.
		//@参数 iColumn 列索引.
		//@返回 返回文本内容
		//@别名 数据适配器列表视_项取文本()
		std::wstring ItemGetText(int iGroup, int iItem, int iColumn) {
			auto pText = XAdListView_Item_GetText(m_handle, iGroup, iItem, iColumn);
			if (!pText) return L"";
			return pText;
		}

		//@备注 项操作,获取项文本内容.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@参数 iItem 项索引.
		//@参数 pName 字段名称.
		//@返回 返回文本内容
		//@别名 数据适配器列表视_项取文本扩展()
		std::wstring ItemGetTextEx(int iGroup, int iItem, const std::wstring& name) {
			auto pText = XAdListView_Item_GetTextEx(m_handle, iGroup, iItem, name.c_str());
			if (!pText) return L"";
			return pText;
		}

		//@备注 项操作,获取项图片句柄.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@参数 iItem 项索引.
		//@参数 iColumn 列索引.
		//@返回 返回图片句柄.
		//@别名 数据适配器列表视_项取图片()
		HIMAGE ItemGetImage(int iGroup, int iItem, int iColumn) {
			return XAdListView_Item_GetImage(m_handle, iGroup, iItem, iColumn);
		}

		//@备注 项操作,获取项图片句柄.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@参数 iItem 项索引.
		//@参数 pName 字段称.
		//@返回 返回图片句柄.
		//@别名 数据适配器列表视_项取图片扩展()
		HIMAGE ItemGetImageEx(int iGroup, int iItem, const std::wstring& name) {
			return 	XAdListView_Item_GetImageEx(m_handle, iGroup, iItem, name.c_str());
		}


		//@备注 项操作,数据填充指定列.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@参数 iItem 项索引.
		//@参数 iColumn 列索引.
		//@参数 pValue 值.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器列表视_项置文本()
		bool ItemSetText(int iGroup, int iItem, int iColumn, const std::wstring& value) {
			return XAdListView_Item_SetText(m_handle, iGroup, iItem, iColumn, value.c_str());
		}

		//@备注 项操作,数据填充指定列.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@参数 iItem 项索引.
		//@参数 pName 字段称.
		//@参数 pValue 值.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器列表视_项置文本扩展()
		bool ItemSetTextEx(int iGroup, int iItem, const std::wstring& name, const std::wstring& value) {
			return XAdListView_Item_SetTextEx(m_handle, iGroup, iItem, name.c_str(), value.c_str());
		}

		//@备注 项操作,数据填充指定列.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@参数 iItem 项索引.
		//@参数 iColumn 列索引.
		//@参数 hImage 图片句柄.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器列表视_项置图片()
		bool ItemSetImage(int iGroup, int iItem, int iColumn, HIMAGE hImage) {
			return XAdListView_Item_SetImage(m_handle, iGroup, iItem, iColumn, hImage);
		}

		//@备注 项操作,数据填充指定列.  
		//@参数 hAdapter 数据适配器句柄.
		//@参数 iGroup 组索引.
		//@参数 iItem 项索引.
		//@参数 pName 字段称.
		//@参数 hImage 图片句柄.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名 数据适配器列表视_项置图片扩展()
		bool ItemSetImageEx(int iGroup, int iItem, const std::wstring& name, HIMAGE hImage) {
			return XAdListView_Item_SetImageEx(m_handle, iGroup, iItem, name.c_str(), hImage);
		}

	};
}