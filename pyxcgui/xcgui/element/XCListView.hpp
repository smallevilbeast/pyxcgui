#pragma once
#include "pch.h"
#include "xcgui/element/XCScrollView.hpp"

namespace xcgui {


	class XCListView : public XCScrollView
	{

	public:
		XCListView(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCListView() = default;

		XCListView(int x, int y, int width, int height, HXCGUI parent = NULL) {

			m_handle = XListView_Create(x, y, width, height, parent);
		}

		//@备注 创建数据适配器，根据绑定的项模板初始化数据适配器的列.  
//@返回 返回适配器句柄.
//@别名  创建数据适配器()
		HXCGUI CreateAdapter() {
			return XListView_CreateAdapter(getEleHandle());
		}

		//@备注 绑定数据适配器.  
		//@参数 hAdapter 数据适配器 XAdListView.
		//@别名  绑定数据适配器()
		void BindAdapter(HXCGUI hAdapter) {
			XListView_BindAdapter(getEleHandle(), hAdapter);
		}

		//@备注 获取数据适配器.  
		//@返回 返回数据适配器.
		//@别名  取数据适配器()
		HXCGUI GetAdapter() {
			return XListView_GetAdapter(getEleHandle());
		}

		//@备注 置项模板文件.  
		//@参数 pXmlFile 文件名.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置项模板文件()
		bool SetItemTemplateXML(const std::wstring& xmlFile) {
			return XListView_SetItemTemplateXML(getEleHandle(), xmlFile.c_str());
		}

		//@备注 置项布局模板.  
		//@参数 pStringXML 字符串指针.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置项模板从字符串()
		bool SetItemTemplateXMLFromString(const std::string& xmlData) {
			return XListView_SetItemTemplateXMLFromString(getEleHandle(), xmlData.c_str());
		}

		//@备注 置列表项模板.  
		//@参数 hTemp 模板句柄.
		//@返回 如果成功返回TRUE,否则返回FALSE.
		//@别名  置项模板()
		bool SetItemTemplate(HTEMP hTemp) {
			return XListView_SetItemTemplate(getEleHandle(), hTemp);
		}

		//@备注 通过模板项ID,获取实例化模板项ID对应的对象句柄.  
		//@参数 iGroup 组索引.
		//@参数 iItem 项索引.
		//@参数 nTempItemID 模板项ID.
		//@返回 成功返回对象句柄,否则返回NULL.
		//@别名  取模板对象()
		HXCGUI GetTemplateObject(int iGroup, int iItem, int nTempItemID) {
			return XListView_GetTemplateObject(getEleHandle(), iGroup, iItem, nTempItemID);
		}

		//@备注 通过模板项ID,获取实例化模板项ID对应的对象句柄.  
		//@参数 iGroup 组索引.
		//@参数 nTempItemID 模板项ID.
		//@返回 成功返回对象句柄,否则返回NULL.
		//@别名  取模板对象组()
		HXCGUI GetTemplateObjectGroup(int iGroup, int nTempItemID) {
			return XListView_GetTemplateObjectGroup(getEleHandle(), iGroup, nTempItemID);
		}

		//@备注 获取当前对象所在模板实例,属于列表视中哪一个项.  
		//@参数 hXCGUI 对象句柄, UI元素句柄或形状对象句柄.
		//@参数 piGroup 接收组索引.
		//@参数 piItem 接收项索引.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  取对象所在项()
		bool GetItemIDFromHXCGUI(HXCGUI hXCGUI, int* piGroup, int* piItem) {
			return XListView_GetItemIDFromHXCGUI(getEleHandle(), hXCGUI, piGroup, piItem);
		}

		//@备注 检查坐标点所在项.  
		//@参数 pPt 坐标点.
		//@参数 pOutGroup 接收组索引.
		//@参数 pOutItem 接收项索引.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  测试点击项()
		bool HitTest(POINT* pPt, int* pOutGroup, int* pOutItem) {
			return XListView_HitTest(getEleHandle(), pPt, pOutGroup, pOutItem);
		}

		//@备注 检查坐标点所在项,自动添加滚动视图偏移量.  
		//@参数 pPt 坐标点.
		//@参数 pOutGroup 接收做索引.
		//@参数 pOutItem 接收项索引.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  测试点击项扩展()
		bool HitTestOffset(POINT* pPt, int* pOutGroup, int* pOutItem) {
			return XListView_HitTestOffset(getEleHandle(), pPt, pOutGroup, pOutItem);
		}

		//@备注 启用多选.  
		//@参数 bEnable 是否启用.
		//@别名  启用多选()
		void EnableMultiSel(bool bEnable) {
			XListView_EnableMultiSel(getEleHandle(), bEnable);
		}

		//@参数 bEnable 是否启用
		//@别名  启用模板复用()
		void EnablemTemplateReuse(bool bEnable) {
			XListView_EnablemTemplateReuse(getEleHandle(), bEnable);
		}

		//@参数 bEnable 是否启用
		//@别名  启用虚表()
		void EnableVirtualTable(bool bEnable) {
			XListView_EnableVirtualTable(getEleHandle(), bEnable);
		}

		//@参数 iGroup 组索引
		//@参数 nCount 项数量
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置虚表项数量()
		bool SetVirtualItemCount(int iGroup, int nCount) {
			return XListView_SetVirtualItemCount(getEleHandle(), iGroup, nCount);
		}

		//@备注 置是否绘制指定状态下项的背景.  
		//@参数 nFlags 标志位  @ref list_drawItemBk_flag_.
		//@别名  置项背景绘制标志()
		void SetDrawItemBkFlags(int nFlags) {
			XListView_SetDrawItemBkFlags(getEleHandle(), nFlags);
		}

		//@备注 置选择项.  
		//@参数 iGroup 组索引.
		//@参数 iItem 项索引.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置选择项()
		bool SetSelectItem(int iGroup, int iItem) {
			return XListView_SetSelectItem(getEleHandle(), iGroup, iItem);
		}

		//@备注 获取选择项.  
		//@参数 piGroup 接收组索引.
		//@参数 piItem 接收项索引.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  取选择项()
		bool GetSelectItem(int* piGroup, int* piItem) {
			return XListView_GetSelectItem(getEleHandle(), piGroup, piItem);
		}

		//@参数 iGroup 组索引
		//@参数 iItem 项索引
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  添加选择项()
		bool AddSelectItem(int iGroup, int iItem) {
			return XListView_AddSelectItem(getEleHandle(), iGroup, iItem);
		}

		//@备注 滚动视图让指定项可见  
		//@参数 iGroup 组索引.
		//@参数 iItem 项索引.
		//@别名  显示指定项()
		void VisibleItem(int iGroup, int iItem) {
			XListView_VisibleItem(getEleHandle(), iGroup, iItem);
		}

		//@备注 获取当前可见项范围.  
		//@参数 piGroup1 可视开始组, 组可见
		//@参数 piGroup2 可视结束组, 组可见
		//@参数 piStartGroup 可视开始组
		//@参数 piStartItem 可视开始项
		//@参数 piEndGroup 可视结束组
		//@参数 piEndItem 可视结束项
		//@别名  取可视项范围()
		void GetVisibleItemRange(int* piGroup1, int* piGroup2, int* piStartGroup, int* piStartItem, int* piEndGroup, int* piEndItem) {
			XListView_GetVisibleItemRange(getEleHandle(), piGroup1, piGroup2, piStartGroup, piStartItem, piEndGroup, piEndItem);
		}

		//@备注 获取选择项数量.  
		//@返回 返回选择项数量.
		//@别名  取选择项数量()
		int GetSelectItemCount() {
			return XListView_GetSelectItemCount(getEleHandle());
		}

		//@备注 获取选择的项ID.  
		//@参数 pArray 数组,用来接收选择项ID.
		//@参数 nArraySize 数组大小.
		//@返回 返回接收项数量.
		//@别名  取选择项全部()
		int GetSelectAll(listView_item_id_* pArray, int nArraySize) {
			return XListView_GetSelectAll(getEleHandle(), pArray, nArraySize);
		}

		//@备注 选择所有的项.  
		//@别名  置选择项全部()
		void SetSelectAll() {
			XListView_SetSelectAll(getEleHandle());
		}

		//@备注 取消选择所有项.  
		//@别名  取消选择项全部()
		void CancelSelectAll() {
			XListView_CancelSelectAll(getEleHandle());
		}

		//@备注 置列间隔大小.  
		//@参数 space 间隔大小.
		//@别名  置列间隔()
		void SetColumnSpace(int space) {
			XListView_SetColumnSpace(getEleHandle(), space);
		}

		//@备注 置行间隔大小.  
		//@参数 space 间隔大小.
		//@别名  置行间隔()
		void SetRowSpace(int space) {
			XListView_SetRowSpace(getEleHandle(), space);
		}

		//@备注 置项大小.  
		//@参数 width 宽度.
		//@参数 height 高度.
		//@别名  置项大小()
		void SetItemSize(int width, int height) {
			XListView_SetItemSize(getEleHandle(), width, height);
		}

		//@备注 获取项大小.  
		//@参数 pSize 接收返回大小.
		//@别名  取项大小()
		void GetItemSize(SIZE* pSize) {
			XListView_GetItemSize(getEleHandle(), pSize);
		}

		//@备注 置组高度.  
		//@参数 height 高度.
		//@别名  置组高度()
		void SetGroupHeight(int height) {
			XListView_SetGroupHeight(getEleHandle(), height);
		}

		//@备注 获取组高度.  
		//@返回 返回组高度.
		//@别名  取组高度()
		int GetGroupHeight() {
			return XListView_GetGroupHeight(getEleHandle());
		}

		//@备注 置组用户数据.  
		//@参数 iGroup 组索引.
		//@参数 nData 数据.
		//@别名  置组用户数据()
		void SetGroupUserData(int iGroup, vint nData) {
			XListView_SetGroupUserData(getEleHandle(), iGroup, nData);
		}

		//@备注 设置项用户数据.  
		//@参数 iGroup 组索引.
		//@参数 iItem 项索引.
		//@参数 nData 数据.
		//@别名  置项用户数据()
		void SetItemUserData(int iGroup, int iItem, vint nData) {
			XListView_SetItemUserData(getEleHandle(), iGroup, iItem, nData);
		}

		//@备注 获取组用户数据.  
		//@参数 iGroup 组索引.
		//@返回 返回用户数据.
		//@别名  取组用户数据()
		vint GetGroupUserData(int iGroup) {
			return XListView_GetGroupUserData(getEleHandle(), iGroup);
		}

		//@备注 获取项用户数据.  
		//@参数 iGroup 组索引.
		//@参数 iItem 项索引.
		//@返回 返回用户数据.
		//@别名  取项用户数据()
		vint GetItemUserData(int iGroup, int iItem) {
			return XListView_GetItemUserData(getEleHandle(), iGroup, iItem);
		}

		//@备注 修改数据后,刷新所有项模板,以便更新数据到模板(如果项可见).  
		//@别名  刷新项数据()
		void RefreshData() {
			XListView_RefreshData(getEleHandle());
		}

		//@备注 修改数据后,刷新指定项模板,以便更新数据到模板(如果当前项可见).  
		//@参数 iGroup 组索引.
		//@参数 iItem 项索引, 如果为-1,代表为组.
		//@别名  刷新指定项()
		void RefreshItem(int iGroup, int iItem) {
			XListView_RefreshItem(getEleHandle(), iGroup, iItem);
		}

		//@备注 展开组.  
		//@参数 iGroup 组索引.
		//@参数 bExpand 是否展开.
		//@返回 成功返回TRUE否则返回FALSE,如果状态没有改变返回FALSE.
		//@别名  展开组()
		bool ExpandGroup(int iGroup, bool bExpand) {
			return XListView_ExpandGroup(getEleHandle(), iGroup, bExpand);
		}

		//@参数 name.c_str() 字段称
		//@返回 返回列索引
		//@别名  组添加列()
		int Group_AddColumn(const std::wstring& name) {
			return XListView_Group_AddColumn(getEleHandle(), name.c_str());
		}

		//@参数 value.c_str() 值
		//@参数 iPos 插入位置, -1添加到末尾
		//@返回 返回组索引
		//@别名  组添加项文本()
		int Group_AddItemText(const std::wstring& value, int iPos) {
			return XListView_Group_AddItemText(getEleHandle(), value.c_str(), iPos);
		}

		//@参数 name.c_str() 字段称
		//@参数 value.c_str() 值
		//@参数 iPos 插入位置, -1添加到末尾
		//@返回 返回组索引
		//@别名  组添加项文本扩展()
		int Group_AddItemTextEx(const std::wstring& name, const std::wstring& value, int iPos) {
			return XListView_Group_AddItemTextEx(getEleHandle(), name.c_str(), value.c_str(), iPos);
		}

		//@参数 hImage 图片句柄
		//@参数 iPos 插入位置, -1添加到末尾
		//@返回 返回组索引
		//@别名  组添加项图片()
		int Group_AddItemImage(HIMAGE hImage, int iPos) {
			return XListView_Group_AddItemImage(getEleHandle(), hImage, iPos);
		}

		//@参数 name.c_str() 字段称
		//@参数 hImage 图片句柄
		//@参数 iPos 插入位置, -1添加到末尾
		//@返回 返回组索引
		//@别名  组添加项图片扩展()
		int Group_AddItemImageEx(const std::wstring& name, HIMAGE hImage, int iPos) {
			return XListView_Group_AddItemImageEx(getEleHandle(), name.c_str(), hImage, iPos);
		}

		//@参数 iGroup 组索引
		//@参数 iColumn 列索引
		//@参数 value.c_str() 值
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  组置文本()
		bool Group_SetText(int iGroup, int iColumn, const std::wstring& value) {
			return XListView_Group_SetText(getEleHandle(), iGroup, iColumn, value.c_str());
		}

		//@参数 iGroup 组索引
		//@参数 name.c_str() 字段名
		//@参数 value.c_str() 值
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  组置文本扩展()
		bool Group_SetTextEx(int iGroup, const std::wstring& name, const std::wstring& value) {
			return XListView_Group_SetTextEx(getEleHandle(), iGroup, name.c_str(), value.c_str());
		}

		//@参数 iGroup 组索引
		//@参数 iColumn 列索引
		//@参数 hImage 图片句柄
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  组置图片()
		bool Group_SetImage(int iGroup, int iColumn, HIMAGE hImage) {
			return XListView_Group_SetImage(getEleHandle(), iGroup, iColumn, hImage);
		}

		//@参数 iGroup 组索引
		//@参数 name.c_str() 字段名
		//@参数 hImage 图片句柄
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  组置图片扩展()
		bool Group_SetImageEx(int iGroup, const std::wstring& name, HIMAGE hImage) {
			return XListView_Group_SetImageEx(getEleHandle(), iGroup, name.c_str(), hImage);
		}

		//@参数 iGroup 组索引
		//@参数 iColumn 列索引
		//@返回 返回文本内容
		//@别名  组取文本()
		std::wstring Group_GetText(int iGroup, int iColumn) {
			return XListView_Group_GetText(getEleHandle(), iGroup, iColumn);
		}

		//@参数 iGroup 组索引
		//@参数 name.c_str() 字段名称
		//@返回 返回文本内容
		//@别名  组取文本扩展()
		std::wstring Group_GetTextEx(int iGroup, const std::wstring& name) {
			return XListView_Group_GetTextEx(getEleHandle(), iGroup, name.c_str());
		}

		//@参数 iGroup 组索引
		//@参数 iColumn 列索引
		//@返回 返回图片句柄
		//@别名  组取图片()
		HIMAGE Group_GetImage(int iGroup, int iColumn) {
			return XListView_Group_GetImage(getEleHandle(), iGroup, iColumn);
		}

		//@参数 iGroup 组索引
		//@参数 name.c_str() 字段名称
		//@返回 返回图片句柄
		//@别名  组取图片扩展()
		HIMAGE Group_GetImageEx(int iGroup, const std::wstring& name) {
			return XListView_Group_GetImageEx(getEleHandle(), iGroup, name.c_str());
		}

		//@返回 返回组数量
		//@别名  组获取数量()
		int Group_GetCount() {
			return XListView_Group_GetCount(getEleHandle());
		}

		//@参数 iGroup 组索引
		//@返回 成功返回项数量,否则返回 @ref XC_ID_ERROR.
		//@别名  项取数量()
		int Item_GetCount(int iGroup) {
			return XListView_Item_GetCount(getEleHandle(), iGroup);
		}

		//@参数 name.c_str() 字段名
		//@返回 返回列索引
		//@别名  项添加列()
		int Item_AddColumn(const std::wstring& name) {
			return XListView_Item_AddColumn(getEleHandle(), name.c_str());
		}

		//@参数 iGroup 组索引
		//@参数 value.c_str() 值
		//@参数 iPos 插入位置, -1添加到末尾
		//@返回 返回项索引
		//@别名  项添加文本()
		int Item_AddItemText(int iGroup, const std::wstring& value, int iPos) {
			return XListView_Item_AddItemText(getEleHandle(), iGroup, value.c_str(), iPos);
		}

		//@参数 iGroup 组索引
		//@参数 name.c_str() 字段名
		//@参数 value.c_str() 值
		//@参数 iPos 插入位置, -1添加到末尾
		//@返回 返回项索引
		//@别名  项添加文本扩展()
		int Item_AddItemTextEx(int iGroup, const std::wstring& name, const std::wstring& value, int iPos) {
			return XListView_Item_AddItemTextEx(getEleHandle(), iGroup, name.c_str(), value.c_str(), iPos);
		}

		//@参数 iGroup 组索引
		//@参数 hImage 图片句柄
		//@参数 iPos 插入位置, -1添加到末尾
		//@返回 返回项索引
		//@别名  项添加图片()
		int Item_AddItemImage(int iGroup, HIMAGE hImage, int iPos) {
			return XListView_Item_AddItemImage(getEleHandle(), iGroup, hImage, iPos);
		}

		//@参数 iGroup 组索引
		//@参数 name.c_str() 字段名
		//@参数 hImage 图片句柄
		//@参数 iPos 插入位置, -1添加到末尾
		//@返回 返回项索引
		//@别名  项添加图片扩展()
		int Item_AddItemImageEx(int iGroup, const std::wstring& name, HIMAGE hImage, int iPos) {
			return XListView_Item_AddItemImageEx(getEleHandle(), iGroup, name.c_str(), hImage, iPos);
		}

		//@参数 iGroup 组索引
		//@参数 iItem 项索引
		//@参数 iColumn 列索引
		//@参数 value.c_str() 值
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  项置文本()
		bool Item_SetText(int iGroup, int iItem, int iColumn, const std::wstring& value) {
			return XListView_Item_SetText(getEleHandle(), iGroup, iItem, iColumn, value.c_str());
		}

		//@参数 iGroup 组索引
		//@参数 iItem 项索引
		//@参数 name.c_str() 字段名
		//@参数 value.c_str() 值
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  项置文本扩展()
		bool Item_SetTextEx(int iGroup, int iItem, const std::wstring& name, const std::wstring& value) {
			return XListView_Item_SetTextEx(getEleHandle(), iGroup, iItem, name.c_str(), value.c_str());
		}

		//@参数 iGroup 组索引
		//@参数 iItem 项索引
		//@参数 iColumn 列索引
		//@参数 hImage 图片句柄
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  项置图片()
		bool Item_SetImage(int iGroup, int iItem, int iColumn, HIMAGE hImage) {
			return XListView_Item_SetImage(getEleHandle(), iGroup, iItem, iColumn, hImage);
		}

		//@参数 iGroup 组索引
		//@参数 iItem 项索引
		//@参数 name.c_str() 列名称
		//@参数 hImage 图片句柄
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  项置图片扩展()
		bool Item_SetImageEx(int iGroup, int iItem, const std::wstring& name, HIMAGE hImage) {
			return XListView_Item_SetImageEx(getEleHandle(), iGroup, iItem, name.c_str(), hImage);
		}

		//@参数 iGroup 组索引
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  组删除项()
		bool Group_DeleteItem(int iGroup) {
			return XListView_Group_DeleteItem(getEleHandle(), iGroup);
		}

		//@参数 iGroup 组索引
		//@别名  组删除全部子项()
		void Group_DeleteAllChildItem(int iGroup) {
			XListView_Group_DeleteAllChildItem(getEleHandle(), iGroup);
		}

		//@参数 iGroup 组索引
		//@参数 iItem 项索引
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  项删除()
		bool Item_DeleteItem(int iGroup, int iItem) {
			return XListView_Item_DeleteItem(getEleHandle(), iGroup, iItem);
		}

		//@别名  删除全部()
		void DeleteAll() {
			XListView_DeleteAll(getEleHandle());
		}

		//@别名  删除全部组()
		void DeleteAllGroup() {
			XListView_DeleteAllGroup(getEleHandle());
		}

		//@别名  删除全部项()
		void DeleteAllItem() {
			XListView_DeleteAllItem(getEleHandle());
		}

		//@参数 iColumn 列索引
		//@别名  组删除列()
		void DeleteColumnGroup(int iColumn) {
			XListView_DeleteColumnGroup(getEleHandle(), iColumn);
		}

		//@参数 iColumn 列索引
		//@别名  项删除列()
		void DeleteColumnItem(int iColumn) {
			XListView_DeleteColumnItem(getEleHandle(), iColumn);
		}

		//@参数 iGroup 组索引
		//@参数 iItem 项索引
		//@参数 iColumn 列索引
		//@返回 返回文本内容
		//@别名  项取文本()
		std::wstring Item_GetText(int iGroup, int iItem, int iColumn) {
			return XListView_Item_GetText(getEleHandle(), iGroup, iItem, iColumn);
		}

		//@参数 iGroup 组索引
		//@参数 iItem 项索引
		//@参数 name.c_str() 字段称
		//@返回 返回文本内容
		//@别名  项取文本扩展()
		std::wstring Item_GetTextEx(int iGroup, int iItem, const std::wstring& name) {
			return XListView_Item_GetTextEx(getEleHandle(), iGroup, iItem, name.c_str());
		}

		//@参数 iGroup 组索引
		//@参数 iItem 项索引
		//@参数 iColumn 列索引
		//@返回 返回图片句柄
		//@别名  项取图片()
		HIMAGE Item_GetImage(int iGroup, int iItem, int iColumn) {
			return XListView_Item_GetImage(getEleHandle(), iGroup, iItem, iColumn);
		}

		//@参数 iGroup 组索引
		//@参数 iItem 项索引
		//@参数 name.c_str() 字段称
		//@返回 返回图片句柄
		//@别名  项取图片扩展()
		HIMAGE Item_GetImageEx(int iGroup, int iItem, const std::wstring& name) {
			return XListView_Item_GetImageEx(getEleHandle(), iGroup, iItem, name.c_str());
		}

	};
}