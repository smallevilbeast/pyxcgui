#pragma once
#include "pch.h"
#include "xcgui/element/XCScrollView.hpp"

namespace xcgui {


	class XCList : public XCScrollView
	{

	public:
		XCList(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCList() = default;

		XCList(int x, int y, int width, int height, HXCGUI parent = NULL) {

			m_handle = XList_Create(x, y, width, height, parent);
		}

		//@备注 增加列.  
		//@参数 width 列宽度.
		//@返回 返回位置索引.
		//@别名  增加列()
		int AddColumn(int width) {
			return XList_AddColumn(getEleHandle(), width);
		}

		//@备注 插入列.  
		//@参数 width 列宽度.
		//@参数 iRow 插入位置索引.
		//@返回 返回插入位置索引.
		//@别名  插入列()
		int InsertColumn(int width, int iRow) {
			return XList_InsertColumn(getEleHandle(), width, iRow);
		}

		//@备注 启用或关闭多选功能.  
		//@参数 bEnable 是否启用.
		//@别名  启用多选()
		void EnableMultiSel(bool bEnable) {
			XList_EnableMultiSel(getEleHandle(), bEnable);
		}

		//@备注 启用拖动改变列宽度.  
		//@参数 bEnable 是否启用.
		//@别名  启用拖动更改列宽()
		void EnableDragChangeColumnWidth(bool bEnable) {
			XList_EnableDragChangeColumnWidth(getEleHandle(), bEnable);
		}

		//@备注 启用垂直滚动条顶部对齐.  
		//@参数 bTop 是否启用.
		//@别名  启用垂直滚动条顶部对齐()
		void EnableVScrollBarTop(bool bTop) {
			XList_EnableVScrollBarTop(getEleHandle(), bTop);
		}

		//@备注 启用项背景全行填充模式.  
		//@参数 bFull 是否启用.
		//@别名  启用项背景全行模式()
		void EnableItemBkFullRow(bool bFull) {
			XList_EnableItemBkFullRow(getEleHandle(), bFull);
		}

		//@参数 bEnable 是否启用
		//@别名  启用固定行高()
		void EnableFixedRowHeight(bool bEnable) {
			XList_EnableFixedRowHeight(getEleHandle(), bEnable);
		}

		//@参数 bEnable 是否启用
		//@别名  启用模板复用()
		void EnableTemplateReuse(bool bEnable) {
			XList_EnableTemplateReuse(getEleHandle(), bEnable);
		}

		//@参数 bEnable 是否启用
		//@别名  启用虚表()
		void EnableVirtualTable(bool bEnable) {
			XList_EnableVirtualTable(getEleHandle(), bEnable);
		}

		//@参数 nRowCount 行数
		//@别名  置虚表行数()
		void SetVirtualRowCount(int nRowCount) {
			XList_SetVirtualRowCount(getEleHandle(), nRowCount);
		}

		//@备注 设置排序属性.  
		//@参数 iColumn 列索引.
		//@参数 iColumnAdapter 需要排序的数据在数据适配器中的列索引.
		//@参数 bEnable 是否启用排序功能.
		//@别名  置排序()
		void SetSort(int iColumn, int iColumnAdapter, bool bEnable) {
			XList_SetSort(getEleHandle(), iColumn, iColumnAdapter, bEnable);
		}

		//@备注 设置是否绘制指定状态下项的背景.  
		//@参数 nFlags 标志位 @ref list_drawItemBk_flag_.
		//@别名  置绘制项背景标志()
		void SetDrawItemBkFlags(int style) {
			XList_SetDrawItemBkFlags(getEleHandle(), style);
		}

		//@参数 color 颜色值, 请使用宏: RGBA()
		//@别名  置分割线颜色()
		void SetSplitLineColor(COLORREF color) {
			XList_SetSplitLineColor(getEleHandle(), color);
		}

		//@备注 设置列宽度.  
		//@参数 iRow 列索引.
		//@参数 width 宽度.
		//@别名  置列宽()
		void SetColumnWidth(int iRow, int width) {
			XList_SetColumnWidth(getEleHandle(), iRow, width);
		}

		//@备注 设置列最小宽度.  
		//@参数 iRow 列索引.
		//@参数 width 宽度.
		//@别名  置列最小宽度()
		void SetColumnMinWidth(int iRow, int width) {
			XList_SetColumnMinWidth(getEleHandle(), iRow, width);
		}

		//@备注 设置指定列宽度固定.  
		//@参数 iColumn 列索引.
		//@参数 bFixed 是否固定宽度.
		//@别名  置列宽度固定()
		void SetColumnWidthFixed(int iColumn, bool bFixed) {
			XList_SetColumnWidthFixed(getEleHandle(), iColumn, bFixed);
		}

		//@备注 获取指定列宽度.  
		//@参数 iColumn 列索引.
		//@返回 返回指定列宽度.
		//@别名  取列宽度()
		int GetColumnWidth(int iColumn) {
			return XList_GetColumnWidth(getEleHandle(), iColumn);
		}

		//@备注 获取列数量.  
		//@返回 返回列数量.
		//@别名  取列数量()
		int GetColumnCount() {
			return XList_GetColumnCount(getEleHandle());
		}

		//@备注 设置项用户数据.  
		//@参数 iRow 行索引.
		//@参数 iColumn 列索引.
		//@参数 data 用户数据.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置项数据()
		bool SetItemData(int iRow, int iColumn, vint data) {
			return XList_SetItemData(getEleHandle(), iRow, iColumn, data);
		}

		//@备注 获取项用户数据.
		//@参数 iRow 行索引.
		//@参数 iColumn 列索引.
		//@返回 返回用户数据.
		//@别名  取项数据()
		vint GetItemData(int iRow, int iColumn) {
			return XList_GetItemData(getEleHandle(), iRow, iColumn);
		}

		//@备注 设置选择项.  
		//@参数 iRow 行索引.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置选择项()
		bool SetSelectItem(int iRow) {
			return XList_SetSelectItem(getEleHandle(), iRow);
		}

		//@备注 获取选择项.  
		//@返回 行索引.
		//@别名  取选择项()
		int GetSelectItem() {
			return XList_GetSelectItem(getEleHandle());
		}

		//@备注 获取选择项数量.  
		//@返回 返回选择项数量.
		//@别名  取选择项数量()
		int GetSelectItemCount() {
			return XList_GetSelectItemCount(getEleHandle());
		}

		//@参数 iRow 行索引
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  添加选择项()
		bool AddSelectItem(int iRow) {
			return XList_AddSelectItem(getEleHandle(), iRow);
		}

		//@备注 选择全部行.  
		//@别名  置选择全部()
		void SetSelectAll() {
			XList_SetSelectAll(getEleHandle());
		}

		//@备注 获取全部选择的行.  
		//@参数 pArray 接收行索引数组.
		//@参数 nArraySize 数组大小.
		//@返回 返回行数量.
		//@别名  取全部选择()
		int GetSelectAll(int* pArray, int nArraySize) {
			return XList_GetSelectAll(getEleHandle(), pArray, nArraySize);
		}

		//@备注 滚动视图让指定项可见  
		//@参数 iRow 行索引.
		//@别名  显示指定项()
		void VisibleItem(int iRow) {
			XList_VisibleItem(getEleHandle(), iRow);
		}

		//@备注 取消选择指定项(这里的项可以理解为行).  
		//@参数 iRow 行索引.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  取消选择项()
		bool CancelSelectItem(int iRow) {
			return XList_CancelSelectItem(getEleHandle(), iRow);
		}

		//@备注 取消选择所有项(这里的项可以理解为行).  
		//@别名  取消全部选择项()
		void CancelSelectAll() {
			XList_CancelSelectAll(getEleHandle());
		}

		//@备注 获取列表头元素.  
		//@返回 返回列表头元素句柄.
		//@别名  取列表头()
		HELE GetHeaderHELE() {
			return XList_GetHeaderHELE(getEleHandle());
		}

		//@备注 删除列.  
		//@参数 iRow 行索引.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  删除列()
		bool DeleteColumn(int iRow) {
			return XList_DeleteColumn(getEleHandle(), iRow);
		}

		//@备注 删除所有的列,仅删除List的, 数据适配器的列不变.   
		//@别名  删除全部列()
		void DeleteColumnAll() {
			XList_DeleteColumnAll(getEleHandle());
		}

		//@备注 绑定数据适配器.  
		//@参数 hAdapter 数据适配器句柄 XAdTable.
		//@别名  绑定数据适配器()
		void BindAdapter(HXCGUI hAdapter) {
			XList_BindAdapter(getEleHandle(), hAdapter);
		}

		//@备注 列表头绑定数据适配器.  
		//@参数 hAdapter 数据适配器句柄 XAdMap.
		//@别名  列表头绑定数据适配器()
		void BindAdapterHeader(HXCGUI hAdapter) {
			XList_BindAdapterHeader(getEleHandle(), hAdapter);
		}

		//@备注 创建数据适配器，根据绑定的项模板初始化数据适配器的列.  
		//@返回 返回适配器句柄.
		//@别名  创建数据适配器()
		HXCGUI CreateAdapter(int colExtendCount=0) {
			return XList_CreateAdapter(getEleHandle(), colExtendCount);
		}

		//@备注 创建数据适配器，根据绑定的项模板初始化数据适配器的列.  
		//@返回 返回适配器句柄.
		//@别名  列表头创建数据适配器()
		HXCGUI CreateAdapterHeader() {
			return XList_CreateAdapterHeader(getEleHandle());
		}

		//@备注 获取数据适配器.  
		//@返回 数据适配器句柄.
		//@别名  取数据适配器()
		HXCGUI GetAdapter() {
			return XList_GetAdapter(getEleHandle());
		}

		//@备注 获取列表头数据适配器.  
		//@返回 返回数据适配器句柄.
		//@别名  列表头获取数据适配器()
		HXCGUI GetAdapterHeader() {
			return XList_GetAdapterHeader(getEleHandle());
		}

		//@备注 设置项布局模板文件.  
		//@参数 pXmlFile 文件名.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置项模板文件()
		bool SetItemTemplateXML(const std::wstring& xmlFile) {
			return XList_SetItemTemplateXML(getEleHandle(), xmlFile.c_str());
		}

		//@备注 设置项布局模板文件.  
		//@参数 pStringXML 字符串指针.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置项模板从字符串()
		bool SetItemTemplateXMLFromString(const std::string& xmlData) {
			return XList_SetItemTemplateXMLFromString(getEleHandle(), xmlData.c_str());
		}

		//@备注 设置列表项模板.  
		//@参数 hTemp 模板句柄.
		//@返回 如果成功返回TRUE,否则返回FALSE.
		//@别名  置项模板()
		bool SetItemTemplate(HTEMP hTemp) {
			return XList_SetItemTemplate(getEleHandle(), hTemp);
		}

		//@备注 获取列表项模板句柄
		//@返回 返回列表项模板句柄
		//@别名  取项模板()
		HTEMP GetItemTemplate() {
			return XList_GetItemTemplate(getEleHandle());
		}

		//@备注 获取列表头项模板句柄
		//@返回 返回列表头项模板句柄
		//@别名  取项模板列表头()
		HTEMP GetItemTemplateHeader() {
			return XList_GetItemTemplateHeader(getEleHandle());
		}

		//@备注 通过模板项ID,获取实例化模板项ID对应的对象句柄.  
		//@参数 iRow 行索引.
		//@参数 iColumn 列索引.
		//@参数 nTempItemID 模板项itemID.
		//@返回 成功返回对象句柄,否则返回NULL.
		//@别名  取项模板对象()
		HXCGUI GetTemplateObject(int iRow, int iColumn, int nTempItemID) {
			return XList_GetTemplateObject(getEleHandle(), iRow, iColumn, nTempItemID);
		}

		//@备注 获取当前对象所在模板实例,属于列表中哪一个项.  
		//@参数 hXCGUI 对象句柄, UI元素句柄或形状对象句柄.
		//@返回 成功返回行索引, 否则返回@ref XC_ID_ERROR.
		//@别名  取对象所在行()
		int GetItemIndexFromHXCGUI(HXCGUI hXCGUI) {
			return XList_GetItemIndexFromHXCGUI(getEleHandle(), hXCGUI);
		}

		//@备注 列表头,通过模板项ID,获取实例化模板项ID对应的对象句柄.  
		//@参数 iColumn 列表头 列索引.
		//@参数 nTempItemID 模板项ID.
		//@返回 成功返回对象句柄,否则返回NULL.
		//@别名  取列表头模板对象()
		HXCGUI GetHeaderTemplateObject(int iColumn, int nTempItemID) {
			return XList_GetHeaderTemplateObject(getEleHandle(), iColumn, nTempItemID);
		}

		//@备注 列表头,获取当前对象所在模板实例,属于列表头中哪一个项.  
		//@参数 hXCGUI 对象句柄.
		//@返回 成功返回行索引, 否则返回@ref XC_ID_ERROR.
		//@别名  取列表头对象所在行()
		int GetHeaderItemIndexFromHXCGUI(HXCGUI hXCGUI) {
			return XList_GetHeaderItemIndexFromHXCGUI(getEleHandle(), hXCGUI);
		}

		//@备注 设置列表头高度.  
		//@参数 height 高度.
		//@别名  置列表头高度()
		void SetHeaderHeight(int height) {
			XList_SetHeaderHeight(getEleHandle(), height);
		}

		//@备注 获取列表头高度.  
		//@返回 返回列表头高度.
		//@别名  取列表头高度()
		int GetHeaderHeight() {
			return XList_GetHeaderHeight(getEleHandle());
		}

		//@备注 获取当前可见行范围.  
		//@参数 piStart 开始行索引.
		//@参数 piEnd 结束行索引.
		//@别名  取可视行范围()
		void GetVisibleRowRange(int* piStart, int* piEnd) {
			XList_GetVisibleRowRange(getEleHandle(), piStart, piEnd);
		}

		//@备注 设置项默认高度.  
		//@参数 nHeight 高度.
		//@参数 nSelHeight 选中时高度.
		//@别名  置项默认高度()
		void SetItemHeightDefault(int nHeight, int nSelHeight) {
			XList_SetItemHeightDefault(getEleHandle(), nHeight, nSelHeight);
		}

		//@备注 获取项默认高度.  
		//@参数 pHeight 高度.
		//@参数 pSelHeight 选中时高度.
		//@别名  取项默认高度()
		void GetItemHeightDefault(int* pHeight, int* pSelHeight) {
			XList_GetItemHeightDefault(getEleHandle(), pHeight, pSelHeight);
		}

		//@备注 设置项高度.  
		//@参数 iRow 行索引
		//@参数 nHeight 高度.
		//@参数 nSelHeight 选中时高度.
		//@别名  置项高度()
		void SetItemHeight(int iRow, int nHeight, int nSelHeight) {
			XList_SetItemHeight(getEleHandle(), iRow, nHeight, nSelHeight);
		}

		//@备注 获取项高度.  
		//@参数 iRow 行索引
		//@参数 pHeight 高度.
		//@参数 pSelHeight 选中时高度.
		//@别名  取项高度()
		void GetItemHeight(int iRow, int* pHeight, int* pSelHeight) {
			XList_GetItemHeight(getEleHandle(), iRow, pHeight, pSelHeight);
		}

		//@备注 设置行间距.  
		//@参数 nSpace 行间距大小.
		//@别名  置行间距()
		void SetRowSpace(int nSpace) {
			XList_SetRowSpace(getEleHandle(), nSpace);
		}

		//@备注 获取行间距大小.  
		//@返回 返回行间距大小.
		//@别名  取行间距()
		int GetRowSpace() {
			return XList_GetRowSpace(getEleHandle());
		}

		//@备注 锁定列,设置左侧锁定列分界列索引.  
		//@参数 iColumn 列索引,-1代表不锁定.
		//@别名  置锁定列左侧()
		void SetLockColumnLeft(int iColumn) {
			XList_SetLockColumnLeft(getEleHandle(), iColumn);
		}

		//@备注 锁定列,设置右侧锁定列分界列索引  
		//@参数 iColumn 列索引, -1代表不锁定. 暂时只支持锁定末尾列 
		//@别名  置锁定列右侧()
		void SetLockColumnRight(int iColumn) {
			XList_SetLockColumnRight(getEleHandle(), iColumn);
		}

		//@备注 设置是否锁定末尾行.  
		//@参数 bLock 是否锁定.
		//@别名  置锁定行底部()
		void SetLockRowBottom(bool bLock) {
			XList_SetLockRowBottom(getEleHandle(), bLock);
		}

		//@参数 bOverlap 是否重叠
		//@别名  置锁定行底部重叠()
		void SetLockRowBottomOverlap(bool bOverlap) {
			XList_SetLockRowBottomOverlap(getEleHandle(), bOverlap);
		}

		//@备注 检测坐标点所在项.  
		//@参数 pPt 坐标点.
		//@参数 piRow 行索引.
		//@参数 piColumn 列索引.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  测试点击项()
		bool HitTest(POINT* pPt, int* piRow, int* piColumn) {
			return XList_HitTest(getEleHandle(), pPt, piRow, piColumn);
		}

		//@备注 检查坐标点所在项,自动添加滚动视图偏移量.  
		//@参数 pPt 坐标点.
		//@参数 piRow 行索引.
		//@参数 piColumn 列索引.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  测试点击项扩展()
		bool HitTestOffset(POINT* pPt, int* piRow, int* piColumn) {
			return XList_HitTestOffset(getEleHandle(), pPt, piRow, piColumn);
		}

		//@备注 修改数据后,刷新所有项模板,以便更新数据到模板(如果项可见).  
		//@别名  刷新项数据()
		void RefreshData() {
			XList_RefreshData(getEleHandle());
		}

		//@备注 刷新列表头数据
		//@别名  刷新数据列表头()
		void RefreshDataHeader() {
			XList_RefreshDataHeader(getEleHandle());
		}

		//@备注 修改数据后,刷新指定项模板,以便更新数据到模板(如果当前项可见).  
		//@参数 iRow 行索引.
		//@别名  刷新指定项()
		void RefreshItem(int iRow) {
			XList_RefreshItem(getEleHandle(), iRow);
		}

		//@参数 nWidth 
		//@参数 name.c_str() 
		//@参数 text.c_str() 
		//@返回 列索引
		//@别名  添加列文本()
		int AddColumnText(int nWidth, const std::wstring& name, const std::wstring& text) {
			return XList_AddColumnText(getEleHandle(), nWidth, name.c_str(), text.c_str());
		}

		//@参数 nWidth 
		//@参数 name.c_str() 
		//@参数 hImage 
		//@返回 列索引
		//@别名  添加列图片()
		int AddColumnImage(int nWidth, const std::wstring& name, HIMAGE hImage) {
			return XList_AddColumnImage(getEleHandle(), nWidth, name.c_str(), hImage);
		}

		//@参数 text.c_str() 
		//@别名  添加项文本()
		int AddItemText(const std::wstring& text) {
			return XList_AddItemText(getEleHandle(), text.c_str());
		}

		//@参数 name.c_str() 
		//@参数 text.c_str() 
		//@别名  添加项文本扩展()
		int AddItemTextEx(const std::wstring& name, const std::wstring& text) {
			return XList_AddItemTextEx(getEleHandle(), name.c_str(), text.c_str());
		}

		//@参数 hImage 
		//@别名  添加项图片()
		int AddItemImage(HIMAGE hImage) {
			return XList_AddItemImage(getEleHandle(), hImage);
		}

		//@参数 name.c_str() 
		//@参数 hImage 
		//@别名  添加项图片扩展()
		int AddItemImageEx(const std::wstring& name, HIMAGE hImage) {
			return XList_AddItemImageEx(getEleHandle(), name.c_str(), hImage);
		}

		//@参数 iRow 
		//@参数 value.c_str() 
		//@别名  插入项文本()
		int InsertItemText(int iRow, const std::wstring& value) {
			return XList_InsertItemText(getEleHandle(), iRow, value.c_str());
		}

		//@参数 iRow 
		//@参数 name.c_str() 
		//@参数 value.c_str() 
		//@别名  插入项文本扩展()
		int InsertItemTextEx(int iRow, const std::wstring& name, const std::wstring& value) {
			return XList_InsertItemTextEx(getEleHandle(), iRow, name.c_str(), value.c_str());
		}

		//@参数 iRow 
		//@参数 hImage 
		//@别名  插入项图片()
		int InsertItemImage(int iRow, HIMAGE hImage) {
			return XList_InsertItemImage(getEleHandle(), iRow, hImage);
		}

		//@参数 iRow 
		//@参数 name.c_str() 
		//@参数 hImage 
		//@别名  插入项图片扩展()
		int InsertItemImageEx(int iRow, const std::wstring& name, HIMAGE hImage) {
			return XList_InsertItemImageEx(getEleHandle(), iRow, name.c_str(), hImage);
		}

		//@参数 iRow 
		//@参数 iColumn 
		//@参数 text.c_str() 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项文本()
		bool SetItemText(int iRow, int iColumn, const std::wstring& text) {
			return XList_SetItemText(getEleHandle(), iRow, iColumn, text.c_str());
		}

		//@参数 iRow 
		//@参数 name.c_str() 
		//@参数 text.c_str() 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项文本扩展()
		bool SetItemTextEx(int iRow, const std::wstring& name, const std::wstring& text) {
			return XList_SetItemTextEx(getEleHandle(), iRow, name.c_str(), text.c_str());
		}

		//@参数 iRow 
		//@参数 iColumn 
		//@参数 hImage 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项图片()
		bool SetItemImage(int iRow, int iColumn, HIMAGE hImage) {
			return XList_SetItemImage(getEleHandle(), iRow, iColumn, hImage);
		}

		//@参数 iRow 
		//@参数 name.c_str() 
		//@参数 hImage 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项图片扩展()
		bool SetItemImageEx(int iRow, const std::wstring& name, HIMAGE hImage) {
			return XList_SetItemImageEx(getEleHandle(), iRow, name.c_str(), hImage);
		}

		//@参数 iRow 
		//@参数 iColumn 
		//@参数 nValue 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项指数值()
		bool SetItemInt(int iRow, int iColumn, int nValue) {
			return XList_SetItemInt(getEleHandle(), iRow, iColumn, nValue);
		}

		//@参数 iRow 
		//@参数 name.c_str() 
		//@参数 nValue 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项整数值扩展()
		bool SetItemIntEx(int iRow, const std::wstring& name, int nValue) {
			return XList_SetItemIntEx(getEleHandle(), iRow, name.c_str(), nValue);
		}

		//@参数 iRow 
		//@参数 iColumn 
		//@参数 fFloat 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项浮点值()
		bool SetItemFloat(int iRow, int iColumn, float fFloat) {
			return XList_SetItemFloat(getEleHandle(), iRow, iColumn, fFloat);
		}

		//@参数 iRow 
		//@参数 name.c_str() 
		//@参数 fFloat 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项浮点值扩展()
		bool SetItemFloatEx(int iRow, const std::wstring& name, float fFloat) {
			return XList_SetItemFloatEx(getEleHandle(), iRow, name.c_str(), fFloat);
		}

		//@参数 iRow 
		//@参数 iColumn 
		//@返回 返回文本内容
		//@别名  取项文本()
		std::wstring GetItemText(int iRow, int iColumn) {
			auto pText = XList_GetItemText(getEleHandle(), iRow, iColumn);
			if (!pText) return L"";
			return pText;
		}

		//@参数 iRow 
		//@参数 name.c_str() 
		//@返回 返回文本内容
		//@别名  取项文本扩展()
		std::wstring GetItemTextEx(int iRow, const std::wstring& name) {
			auto pText =  XList_GetItemTextEx(getEleHandle(), iRow, name.c_str());
			if (!pText) return L"";
			return pText;
		}

		//@参数 iRow 
		//@参数 iColumn 
		//@别名  取项图片()
		HIMAGE GetItemImage(int iRow, int iColumn) {
			return XList_GetItemImage(getEleHandle(), iRow, iColumn);
		}

		//@参数 iRow 
		//@参数 name.c_str() 
		//@别名  取项图片扩展()
		HIMAGE GetItemImageEx(int iRow, const std::wstring& name) {
			return XList_GetItemImageEx(getEleHandle(), iRow, name.c_str());
		}

		//@参数 iRow 
		//@参数 iColumn 
		//@参数 pOutValue 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  取项整数值()
		bool GetItemInt(int iRow, int iColumn, int* pOutValue) {
			return XList_GetItemInt(getEleHandle(), iRow, iColumn, pOutValue);
		}

		//@参数 iRow 
		//@参数 name.c_str() 
		//@参数 pOutValue 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  取项整数值扩展()
		bool GetItemIntEx(int iRow, const std::wstring& name, int* pOutValue) {
			return XList_GetItemIntEx(getEleHandle(), iRow, name.c_str(), pOutValue);
		}

		//@参数 iRow 
		//@参数 iColumn 
		//@参数 pOutValue 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  取项浮点值()
		bool GetItemFloat(int iRow, int iColumn, float* pOutValue) {
			return XList_GetItemFloat(getEleHandle(), iRow, iColumn, pOutValue);
		}

		//@参数 iRow 
		//@参数 name.c_str() 
		//@参数 pOutValue 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  取项浮点值扩展()
		bool GetItemFloatEx(int iRow, const std::wstring& name, float* pOutValue) {
			return XList_GetItemFloatEx(getEleHandle(), iRow, name.c_str(), pOutValue);
		}

		//@参数 iRow 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  删除项()
		bool DeleteItem(int iRow) {
			return XList_DeleteItem(getEleHandle(), iRow);
		}

		//@参数 iRow 
		//@参数 nCount 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  删除项扩展()
		bool DeleteItemEx(int iRow, int nCount) {
			return XList_DeleteItemEx(getEleHandle(), iRow, nCount);
		}

		//@别名  删除项全部()
		void DeleteItemAll() {
			XList_DeleteItemAll(getEleHandle());
		}

		//@别名  删除列全部AD()
		void DeleteColumnAll_AD() {
			XList_DeleteColumnAll_AD(getEleHandle());
		}

		//@别名  取项数量AD()
		int GetCount_AD() {
			return XList_GetCount_AD(getEleHandle());
		}

		//@别名  取列数量AD()
		int GetCountColumn_AD() {
			return XList_GetCountColumn_AD(getEleHandle());
		}


		// 列表视_置拖动矩形颜色
		void SetDragRectColor(COLORREF color, int width) {
			return XList_SetDragRectColor(getEleHandle(), color, width);
		}

	};
}