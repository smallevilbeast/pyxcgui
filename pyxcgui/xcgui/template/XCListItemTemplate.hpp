#pragma once
#include "pch.h"

namespace xcgui {

	using HTNODE = void*;

	class XCTemplateNode 
	{
	public:
		XCTemplateNode() = default;

		XCTemplateNode(HXCGUI handle) {
			m_handle = (HTNODE)handle;
		}


		XCTemplateNode(XC_OBJECT_TYPE nType) {
			m_handle = XTemp_CreateNode(nType);
		}

		XCTemplateNode(const XCTemplateNode& cloneNode) {
			m_handle = XTemp_CloneNode(cloneNode.getHandle());
		}


		HTNODE CloneNode(HTNODE otherNode) {
			m_handle = XTemp_CloneNode(otherNode);
			return m_handle;
		}


		HTNODE GetNode(int itemId) {
			return XTemp_GetNode(m_handle, itemId);
		}


		bool AddNode(HTNODE childNode) {
			return XTemp_AddNode(m_handle, childNode);
		}


		bool SetNodeAttribute(const std::wstring& name, const std::wstring& value) {
			return XTemp_SetNodeAttribute(m_handle, name.c_str(), value.c_str());
		}

		bool SetNodeAttributeEx(int itemId, std::wstring& name, const std::wstring& value) {
			return XTemp_SetNodeAttributeEx(m_handle, itemId, name.c_str(), value.c_str());
		}

		HTNODE getHandle() const {
			return m_handle;
		}
	protected:
		HTNODE m_handle;
	};

	class XCListItemTemplate
	{

	public:
		XCListItemTemplate() = default;

		XCListItemTemplate(HXCGUI handle)
		{

			m_handle = (HTEMP)handle;
		}


		XCListItemTemplate(listItemTemp_type_ tempType) {

			m_handle = XTemp_Create(tempType);
		}

		//@备注 列表项模板文件载入
		//@参数 nType 模板类型,支持类型: \n
		//@参数 pFileName 文件名.
		//@返回 返回模板信息.
		//@别名 项模板_加载从文件()
		HTEMP Load(listItemTemp_type_ nType, const std::wstring& fileName) {
			m_handle = XTemp_Load(nType, fileName.c_str());
			return m_handle;
		}

		//@备注 加载列表项模板从zip压缩包中
		//@参数 nType 模板类型,支持类型: \n
		//@参数 pZipFile zip文件
		//@参数 pFileName 文件名
		//@参数 pPassword zip密码
		//@返回 返回模板句柄.
		//@别名 项模板_加载从ZIP()
		HTEMP LoadZip(listItemTemp_type_ nType, const std::wstring& zipFile, 
			const std::wstring& fileName, const std::wstring& password) 
		{
			m_handle = XTemp_LoadZip(nType, zipFile.c_str(), fileName.c_str(), password.c_str());
			return m_handle;
		}

		//@备注 加载列表项模板从内存zip压缩包中
		//@参数 nType 模板类型,支持类型, 只可选一个: \n
		//@参数 data 内存块指针
		//@参数 length 内存块大小,字节为单位
		//@参数 pFileName 文件名
		//@参数 pPassword zip密码
		//@返回 返回模板句柄.
		//@别名 项模板_加载从内存ZIP()
		HTEMP LoadZipMem(listItemTemp_type_ nType, const std::string& data,
			const std::wstring& fileName, const std::wstring& password) 
		{
			m_handle = XTemp_LoadZipMem(nType, (void*)data.c_str(), data.size(), fileName.c_str(), password.c_str());
			return m_handle;
		}

		//@备注 加载列表项模板从文件
		//@参数 nType 模板类型, 支持类型, 只可选一个: \n 
		//@参数 pFileName 文件名
		//@参数 pOutTemp1 返回模板句柄1, 项模板
		//@参数 pOutTemp2 返回模板句柄2, 列表头模板或列表视组模板
		//@返回 如果成功返回TRUE,否则返回FALSE.
		//@别名 项模板_加载从文件扩展()
		static bool LoadEx(listItemTemp_type_ nType, const std::wstring& fileName, HTEMP* pOutTemp1, HTEMP* pOutTemp2) {
			return XTemp_LoadEx(nType, fileName.c_str(), pOutTemp1, pOutTemp2);
		}

		//@备注 加载列表项模板从zip压缩包中
		//@参数 nType 模板类型, 支持类型: \n 
		//@参数 pZipFile zip文件
		//@参数 pFileName 文件名
		//@参数 pPassword zip密码
		//@参数 pOutTemp1 返回模板句柄1, 项模板
		//@参数 pOutTemp2 返回模板句柄2, 列表头模板或列表视组模板
		//@返回 如果成功返回TRUE,否则返回FALSE.
		//@别名 项模板_加载从ZIP扩展()
		static bool LoadZipEx(listItemTemp_type_ nType, const std::wstring& zipFile, 
			const std::wstring& fileName, const std::wstring& password, HTEMP* pOutTemp1, HTEMP* pOutTemp2) 
		{
			return XTemp_LoadZipEx(nType, zipFile.c_str(), fileName.c_str(), password.c_str(), pOutTemp1, pOutTemp2);
		}

		//@备注 加载列表项模板从内存zip压缩包中
		//@参数 nType 模板类型, 支持类型: \n 
		//@参数 data 内存块指针
		//@参数 length 内存块大小,字节为单位
		//@参数 pFileName 文件名
		//@参数 pPassword zip密码
		//@参数 pOutTemp1 返回模板句柄1, 项模板
		//@参数 pOutTemp2 返回模板句柄2, 列表头模板或列表视组模板
		//@返回 如果成功返回TRUE,否则返回FALSE.
		//@别名 项模板_加载从内存ZIP扩展()
		static bool LoadZipMemEx(listItemTemp_type_ nType, const std::string& data, const std::wstring& fileName, 
			const std::wstring& password, HTEMP* pOutTemp1, HTEMP* pOutTemp2) 
		{
			return XTemp_LoadZipMemEx(nType, (void*)data.c_str(), data.size(), 
				fileName.c_str(), password.c_str(), pOutTemp1, pOutTemp2);
		}


		//@备注 加载列表项模板文件从内存字符串
		//@参数 nType 模板类型,支持类型: \n
		//@参数 pStringXML 字符串指针.
		//@返回 返回模板信息.
		//@别名 项模板_加载从字符串()
		HTEMP LoadFromString(listItemTemp_type_ nType, const std::string& xmlData) 
		{
			m_handle = XTemp_LoadFromString(nType, xmlData.c_str());
			return m_handle;
		}


		//@备注 加载列表项模板从字符串
		//@参数 nType 模板类型, 支持类型: \n 
		//@参数 pStringXML 字符串内容
		//@参数 pOutTemp1 返回模板句柄1, 项模板
		//@参数 pOutTemp2 返回模板句柄2, 列表头模板或列表视组模板
		//@返回 如果成功返回TRUE,否则返回FALSE.
		//@别名 项模板_加载从字符串扩展()
		static bool LoadFromStringEx(listItemTemp_type_ nType, const std::string& xmlData, HTEMP* pOutTemp1, HTEMP* pOutTemp2) {
			return XTemp_LoadFromStringEx(nType, xmlData.c_str(), pOutTemp1, pOutTemp2);
		}


		//@备注 获取列表项模板类型
		//@参数 hTemp 列表项模板句柄.
		//@返回 返回模板类型.
		//@别名 项模板_取类型()
		listItemTemp_type_ GetType() {
			return XTemp_GetType(m_handle);
		}	

		//@备注 项模板销毁
		//@参数 hTemp 项模板句柄.
		//@别名 项模板_销毁()
		bool Destroy() {
			return 	XTemp_Destroy(m_handle);
		}


		//@备注 复制一份新的项模板
		//@参数 hTemp 列表项模板句柄
		//@返回 返回模板句柄
		//@别名 项模板_克隆()
		HTEMP Clone(HTEMP hTemp) {
			m_handle = XTemp_Clone(hTemp);
			return m_handle;
		}

		//@备注 添加根节点
		//@参数 hTemp 项模板句柄.
		//@参数 pNode 节点指针.
		//@返回 成功返回TRUE,否则返回FALSE.
		//@别名 项模板_添加根节点()
		bool AddNodeRoot(HTNODE pNode) {
			return XTemp_AddNodeRoot(m_handle, pNode);
		}

		//@备注 获取列表中的节点
		//@参数 hTemp 模板句柄
		//@参数 index 节点位置索引
		//@返回 返回返回节点指针
		//@别名 项模板_取列表中的节点()
		HTNODE GetNode(int index) {
			return XTemp_List_GetNode(m_handle, index);
		}

		//@备注 在指定位置插入节点
		//@参数 index 插入位置索引
		//@参数 pNode 节点指针
		//@返回 如果成功返回TRUE,否则返回FALSE
		//@别名 项模板_列表_插入节点()
		bool InsertNode(int index, HTNODE pNode) {
			return XTemp_List_InsertNode(m_handle, index, pNode);
		}

		//@备注 删除指定位置的节点
		//@参数 index 节点位置索引
		//@返回 如果成功返回TRUE,否则返回FALSE
		//@别名 项模板_列表_删除节点()
		bool DeleteNode(int index) {
			return XTemp_List_DeleteNode(m_handle, index);
		}

		//@备注 获取子节点数量,只当前层子节点
		//@返回 返回节点数量
		//@别名 项模板_列表_取数量()
		int GetCount() {
			return XTemp_List_GetCount(m_handle);
		}

		//@备注 移动列位置
		//@参数 iColSrc 源列索引
		//@参数 iColDest 目标列索引
		//@返回 如果成功返回TRUE,否则返回FALSE
		//@别名 项模板_列表_移动列()
		bool MoveColumn(int iColSrc, int iColDest) {
			return XTemp_List_MoveColumn(m_handle, iColSrc, iColDest);
		}

		HTEMP getHandle() const {
			return m_handle;
		}

	protected:
		HTEMP m_handle;
	};

}