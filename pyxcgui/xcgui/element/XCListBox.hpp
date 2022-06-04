#pragma once
#include "pch.h"
#include "xcgui/element/XCScrollView.hpp"

namespace xcgui {


	class XCListBox : public XCScrollView
	{

	public:
		XCListBox(HELE handle)
		{

			m_handle = handle;
		}

		XCListBox() = default;

		XCListBox(int x, int y, int width, int height, HXCGUI parent = NULL) {

			m_handle = XListBox_Create(x, y, width, height, parent);
		}

		//@参数 bEnable 是否启用
		//@别名  启用固定行高()
		void EnableFixedRowHeight(bool bEnable) {
			XListBox_EnableFixedRowHeight(getEleHandle(), bEnable);
		}

		//@参数 bEnable 是否启用
		//@别名  启用模板复用()
		void EnablemTemplateReuse(bool bEnable) {
			XListBox_EnablemTemplateReuse(getEleHandle(), bEnable);
		}

		//@参数 bEnable 是否启用
		//@别名  启用虚表()
		void EnableVirtualTable(bool bEnable) {
			XListBox_EnableVirtualTable(getEleHandle(), bEnable);
		}

		//@参数 nRowCount 行数
		//@别名  置虚表行数()
		void SetVirtualRowCount(int nRowCount) {
			XListBox_SetVirtualRowCount(getEleHandle(), nRowCount);
		}

		//@备注 设置是否绘制指定状态下项的背景.  
		//@参数 nFlags 标志位 @ref list_drawItemBk_flag_.
		//@别名  置绘制项背景标志()
		void SetDrawItemBkFlags(int nFlags) {
			XListBox_SetDrawItemBkFlags(getEleHandle(), nFlags);
		}

		//@参数 color 颜色值
		//@别名  置分割线颜色()
		void SetSplitLineColor(COLORREF color) {
			XListBox_SetSplitLineColor(getEleHandle(), color);
		}

		//@备注 设置项用户数据.  
		//@参数 iItem 想索引.
		//@参数 nUserData 用户数据.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置项数据()
		bool SetItemData(int iItem, vint nUserData) {
			return XListBox_SetItemData(getEleHandle(), iItem, nUserData);
		}

		//@备注 获取项用户数据.  
		//@参数 iItem 项索引.
		//@返回 用户数据.
		//@别名  取项数据()
		vint GetItemData(int iItem) {
			return XListBox_GetItemData(getEleHandle(), iItem);
		}

		//@备注 设置项信息.  
		//@参数 iItem 项索引.
		//@参数 pItem 项信息.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置项信息()
		bool SetItemInfo(int iItem, listBox_item_info_* pItem) {
			return XListBox_SetItemInfo(getEleHandle(), iItem, pItem);
		}

		//@备注 获取项信息.  
		//@参数 iItem 项索引.
		//@参数 pItem 项信息.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  取项背景信息()
		bool GetItemInfo(int iItem, listBox_item_info_* pItem) {
			return XListBox_GetItemInfo(getEleHandle(), iItem, pItem);
		}

		//@备注 设置选择选.  
		//@参数 iItem 项索引.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置选择项()
		bool SetSelectItem(int iItem) {
			return XListBox_SetSelectItem(getEleHandle(), iItem);
		}

		//@备注 获取选择项.  
		//@返回 项索引.
		//@别名  取选择项()
		int GetSelectItem() {
			return XListBox_GetSelectItem(getEleHandle());
		}

		//@参数 iItem 项索引
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  添加选择项()
		bool AddSelectItem(int iItem) {
			return XListBox_AddSelectItem(getEleHandle(), iItem);
		}

		//@备注 取消选择指定项.  
		//@参数 iItem 项索引.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  取消选择项()
		bool CancelSelectItem(int iItem) {
			return XListBox_CancelSelectItem(getEleHandle(), iItem);
		}

		//@备注 取消所有选中的项.  
		//@返回 如果之前有选择状态的项返回TRUE,此时可以更新UI,否则返回FALSE.
		//@别名  取消选择全部()
		bool CancelSelectAll() {
			return XListBox_CancelSelectAll(getEleHandle());
		}

		//@备注 获取所有选择项.  
		//@参数 pArray 数组缓冲区.
		//@参数 nArraySize 数组大小.
		//@返回 返回接收数量.
		//@别名  取全部选择()
		int GetSelectAll(int* pArray, int nArraySize) {
			return XListBox_GetSelectAll(getEleHandle(), pArray, nArraySize);
		}

		//@备注 获取选择项数量.  
		//@返回 返回数量.
		//@别名  取选择项数量()
		int GetSelectCount() {
			return XListBox_GetSelectCount(getEleHandle());
		}

		//@备注 获取鼠标停留项.  
		//@返回 返回鼠标所在项.
		//@别名  取鼠标停留项()
		int GetItemMouseStay() {
			return XListBox_GetItemMouseStay(getEleHandle());
		}

		//@备注 选择所有项.  
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  选择全部项()
		bool SelectAll() {
			return XListBox_SelectAll(getEleHandle());
		}

		//@备注 滚动视图让指定项可见  
		//@参数 iItem 项索引.
		//@别名  显示指定项()
		void VisibleItem(int iItem) {
			XListBox_VisibleItem(getEleHandle(), iItem);
		}

		//@备注 获取当前可见行范围.  
		//@参数 piStart 开始行索引
		//@参数 piEnd 结束行索引
		//@别名  取可视行范围()
		void GetVisibleRowRange(int* piStart, int* piEnd) {
			XListBox_GetVisibleRowRange(getEleHandle(), piStart, piEnd);
		}

		//@备注 设置项默认高度.  
		//@参数 nHeight 项高度.
		//@参数 nSelHeight 选中项高度.
		//@别名  置项默认高度()
		void SetItemHeightDefault(int nHeight, int nSelHeight) {
			XListBox_SetItemHeightDefault(getEleHandle(), nHeight, nSelHeight);
		}

		//@备注 获取项默认高度.  
		//@参数 pHeight 高度.
		//@参数 pSelHeight 选中时高度.
		//@别名  取项默认高度()
		void GetItemHeightDefault(int* pHeight, int* pSelHeight) {
			XListBox_GetItemHeightDefault(getEleHandle(), pHeight, pSelHeight);
		}

		//@备注 获取当前对象所在模板实例,属于列表中哪一个项(行).  
		//@参数 hXCGUI 对象句柄, UI元素句柄或形状对象句柄.
		//@返回 成功返回项索引, 否则返回@ref XC_ID_ERROR.
		//@别名  取所在行索引()
		int GetItemIndexFromHXCGUI(HXCGUI hXCGUI) {
			return XListBox_GetItemIndexFromHXCGUI(getEleHandle(), hXCGUI);
		}

		//@备注 设置行间距.  
		//@参数 nSpace 间距大小.
		//@别名  置行间距()
		void SetRowSpace(int nSpace) {
			XListBox_SetRowSpace(getEleHandle(), nSpace);
		}

		//@备注 获取行间距大小.  
		//@返回 返回行间距大小.
		//@别名  取行间距()
		int GetRowSpace() {
			return XListBox_GetRowSpace(getEleHandle());
		}

		//@备注 检测坐标点所在项.  
		//@参数 pPt 坐标点.
		//@返回 返回项索引.
		//@别名  测试点击项()
		int HitTest(POINT* pPt) {
			return XListBox_HitTest(getEleHandle(), pPt);
		}

		//@备注 检测坐标点所在项,自动添加滚动视图偏移量.  
		//@参数 pPt 坐标点.
		//@返回 项索引.
		//@别名  测试点击项扩展()
		int HitTestOffset(POINT* pPt) {
			return XListBox_HitTestOffset(getEleHandle(), pPt);
		}

		//@备注 设置列表项模板文件.  
		//@参数 pXmlFile 文件名.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置项模板文件()
		bool SetItemTemplateXML(const std::wstring& xmlFile) {
			return XListBox_SetItemTemplateXML(getEleHandle(), xmlFile.c_str());
		}

		//@备注 设置列表项模板.  
		//@参数 hTemp 模板句柄
		//@返回 如果成功返回TRUE,否则返回FALSE.
		//@别名  置项模板()
		bool SetItemTemplate(HTEMP hTemp) {
			return XListBox_SetItemTemplate(getEleHandle(), hTemp);
		}

		//@备注 设置项布局模板文件.  
		//@参数 pStringXML 字符串指针.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置项模板从字符串()
		bool SetItemTemplateXMLFromString(const char* pStringXML) {
			return XListBox_SetItemTemplateXMLFromString(getEleHandle(), pStringXML);
		}

		//@备注 通过模板项ID,获取实例化模板项ID对应的对象句柄.  
		//@参数 iItem 项索引.
		//@参数 nTempItemID 模板项ID.
		//@返回 成功返回对象句柄,否则返回NULL.
		//@别名  取模板对象()
		HXCGUI GetTemplateObject(int iItem, int nTempItemID) {
			return XListBox_GetTemplateObject(getEleHandle(), iItem, nTempItemID);
		}

		//@备注 是否启用多行选择功能.  
		//@参数 bEnable 是否启用.
		//@别名  启用多选()
		void EnableMultiSel(bool bEnable) {
			XListBox_EnableMultiSel(getEleHandle(), bEnable);
		}

		//@备注 创建数据适配器并绑定,根据绑定的项模板初始化数据适配器的列.  
		//@返回 返回适配器句柄.
		//@别名  创建数据适配器()
		HXCGUI CreateAdapter() {
			return XListBox_CreateAdapter(getEleHandle());
		}

		//@备注 绑定数据适配器.  
		//@参数 hAdapter 数据适配器句柄 XAdTable.
		//@别名  绑定数据适配器()
		void BindAdapter(HXCGUI hAdapter) {
			XListBox_BindAdapter(getEleHandle(), hAdapter);
		}

		//@备注 获取绑定的数据适配器.  
		//@返回 返回数据适配器句柄.
		//@别名  取数据适配器()
		HXCGUI GetAdapter() {
			return XListBox_GetAdapter(getEleHandle());
		}

		//@备注 排序.  
		//@参数 iColumnAdapter 需要排序的数据在数据适配器中所属列索引.
		//@参数 bAscending 升序(TRUE)或降序(FALSE).
		//@别名  排序()
		void Sort(int iColumnAdapter, bool bAscending) {
			XListBox_Sort(getEleHandle(), iColumnAdapter, bAscending);
		}

		//@备注 修改数据后,刷新所有项模板,以便更新数据到模板(如果项可见).  
		//@别名  刷新数据()
		void RefreshData() {
			XListBox_RefreshData(getEleHandle());
		}

		//@备注 修改数据后,刷新指定项模板,以便更新数据到模板(如果当前项可见).  
		//@参数 iItem 项索引.
		//@别名  刷新指定项()
		void RefreshItem(int iItem) {
			XListBox_RefreshItem(getEleHandle(), iItem);
		}

		//@备注 XAdTable_AddItemText  
		//@参数 text.c_str() 
		//@返回 返回项索引
		//@别名  添加项文本()
		int AddItemText(const std::wstring& text) {
			return XListBox_AddItemText(getEleHandle(), text.c_str());
		}

		//@备注 XAdTable_AddItemTextEx  
		//@参数 name.c_str() 
		//@参数 text.c_str() 
		//@别名  添加项文本扩展()
		int AddItemTextEx(const std::wstring& name, const std::wstring& text) {
			return XListBox_AddItemTextEx(getEleHandle(), name.c_str(), text.c_str());
		}

		//@备注 XAdTable_AddItemImage  
		//@参数 hImage 
		//@别名  添加项图片()
		int AddItemImage(HIMAGE hImage) {
			return XListBox_AddItemImage(getEleHandle(), hImage);
		}

		//@备注 XAdTable_AddItemImageEx  
		//@参数 name.c_str() 
		//@参数 hImage 
		//@别名  添加项图片扩展()
		int AddItemImageEx(const std::wstring& name, HIMAGE hImage) {
			return XListBox_AddItemImageEx(getEleHandle(), name.c_str(), hImage);
		}

		//@参数 iItem 
		//@参数 value.c_str() 
		//@别名  插入项文本()
		int InsertItemText(int iItem, const std::wstring& value) {
			return XListBox_InsertItemText(getEleHandle(), iItem, value.c_str());
		}

		//@参数 iItem 
		//@参数 name.c_str() 
		//@参数 value.c_str() 
		//@别名  插入项文本扩展()
		int InsertItemTextEx(int iItem, const std::wstring& name, const std::wstring& value) {
			return XListBox_InsertItemTextEx(getEleHandle(), iItem, name.c_str(), value.c_str());
		}

		//@参数 iItem 
		//@参数 hImage 
		//@别名  插入项图片()
		int InsertItemImage(int iItem, HIMAGE hImage) {
			return XListBox_InsertItemImage(getEleHandle(), iItem, hImage);
		}

		//@参数 iItem 
		//@参数 name.c_str() 
		//@参数 hImage 
		//@别名  插入项图片扩展()
		int InsertItemImageEx(int iItem, const std::wstring& name, HIMAGE hImage) {
			return XListBox_InsertItemImageEx(getEleHandle(), iItem, name.c_str(), hImage);
		}

		//@参数 iItem 
		//@参数 iColumn 
		//@参数 text.c_str() 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项文本()
		bool SetItemText(int iItem, int iColumn, const std::wstring& text) {
			return XListBox_SetItemText(getEleHandle(), iItem, iColumn, text.c_str());
		}

		//@参数 iItem 
		//@参数 name.c_str() 
		//@参数 text.c_str() 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项文本扩展()
		bool SetItemTextEx(int iItem, const std::wstring& name, const std::wstring& text) {
			return XListBox_SetItemTextEx(getEleHandle(), iItem, name.c_str(), text.c_str());
		}

		//@参数 iItem 
		//@参数 iColumn 
		//@参数 hImage 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项图片()
		bool SetItemImage(int iItem, int iColumn, HIMAGE hImage) {
			return XListBox_SetItemImage(getEleHandle(), iItem, iColumn, hImage);
		}

		//@参数 iItem 
		//@参数 name.c_str() 
		//@参数 hImage 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项图片扩展()
		bool SetItemImageEx(int iItem, const std::wstring& name, HIMAGE hImage) {
			return XListBox_SetItemImageEx(getEleHandle(), iItem, name.c_str(), hImage);
		}

		//@参数 iItem 
		//@参数 iColumn 
		//@参数 nValue 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项整数值()
		bool SetItemInt(int iItem, int iColumn, int nValue) {
			return XListBox_SetItemInt(getEleHandle(), iItem, iColumn, nValue);
		}

		//@参数 iItem 
		//@参数 name.c_str() 
		//@参数 nValue 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项整数值扩展()
		bool SetItemIntEx(int iItem, const std::wstring& name, int nValue) {
			return XListBox_SetItemIntEx(getEleHandle(), iItem, name.c_str(), nValue);
		}

		//@参数 iItem 
		//@参数 iColumn 
		//@参数 fFloat 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项浮点值()
		bool SetItemFloat(int iItem, int iColumn, float fFloat) {
			return XListBox_SetItemFloat(getEleHandle(), iItem, iColumn, fFloat);
		}

		//@参数 iItem 
		//@参数 name.c_str() 
		//@参数 fFloat 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项浮点值扩展()
		bool SetItemFloatEx(int iItem, const std::wstring& name, float fFloat) {
			return XListBox_SetItemFloatEx(getEleHandle(), iItem, name.c_str(), fFloat);
		}

		//@参数 iItem 
		//@参数 iColumn 
		//@返回 返回文本内容
		//@别名  取项文本()
		std::wstring GetItemText(int iItem, int iColumn) {
			auto pText = XListBox_GetItemText(getEleHandle(), iItem, iColumn);
			if (!pText) return L"";
			return pText;
		}

		//@参数 iItem 
		//@参数 name.c_str() 
		//@返回 返回文本内容
		//@别名  取项文本扩展()
		std::wstring GetItemTextEx(int iItem, const std::wstring& name) {
			auto pText = XListBox_GetItemTextEx(getEleHandle(), iItem, name.c_str());
			if (!pText) return L"";
			return pText;
		}

		//@参数 iItem 
		//@参数 iColumn 
		//@别名  取项图片()
		HIMAGE GetItemImage(int iItem, int iColumn) {
			return XListBox_GetItemImage(getEleHandle(), iItem, iColumn);
		}

		//@参数 iItem 
		//@参数 name.c_str() 
		//@别名  取项图片扩展()
		HIMAGE GetItemImageEx(int iItem, const std::wstring& name) {
			return XListBox_GetItemImageEx(getEleHandle(), iItem, name.c_str());
		}

		//@参数 iItem 
		//@参数 iColumn 
		//@参数 pOutValue 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  取项整数值()
		bool GetItemInt(int iItem, int iColumn, int* pOutValue) {
			return XListBox_GetItemInt(getEleHandle(), iItem, iColumn, pOutValue);
		}

		//@参数 iItem 
		//@参数 name.c_str() 
		//@参数 pOutValue 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  取项整数值扩展()
		bool GetItemIntEx(int iItem, const std::wstring& name, int* pOutValue) {
			return XListBox_GetItemIntEx(getEleHandle(), iItem, name.c_str(), pOutValue);
		}

		//@参数 iItem 
		//@参数 iColumn 
		//@参数 pOutValue 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  取项浮点值()
		bool GetItemFloat(int iItem, int iColumn, float* pOutValue) {
			return XListBox_GetItemFloat(getEleHandle(), iItem, iColumn, pOutValue);
		}

		//@参数 iItem 
		//@参数 name.c_str() 
		//@参数 pOutValue 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  取项浮点值扩展()
		bool GetItemFloatEx(int iItem, const std::wstring& name, float* pOutValue) {
			return XListBox_GetItemFloatEx(getEleHandle(), iItem, name.c_str(), pOutValue);
		}

		//@参数 iItem 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  删除项()
		bool DeleteItem(int iItem) {
			return XListBox_DeleteItem(getEleHandle(), iItem);
		}

		//@参数 iItem 
		//@参数 nCount 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  删除项扩展()
		bool DeleteItemEx(int iItem, int nCount) {
			return XListBox_DeleteItemEx(getEleHandle(), iItem, nCount);
		}

		//@别名  删除项全部()
		void DeleteItemAll() {
			XListBox_DeleteItemAll(getEleHandle());
		}

		//@别名  删除列全部()
		void DeleteColumnAll() {
			XListBox_DeleteColumnAll(getEleHandle());
		}

		//@别名  取项数量AD()
		int GetCount_AD() {
			return XListBox_GetCount_AD(getEleHandle());
		}

		//@别名  取列数量AD()
		int GetCountColumn_AD() {
			return XListBox_GetCountColumn_AD(getEleHandle());
		}


	};
}