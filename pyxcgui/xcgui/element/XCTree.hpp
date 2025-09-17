#pragma once
#include "pch.h"
#include "xcgui/element/XCScrollView.hpp"

namespace xcgui {


	class XCTree : public XCScrollView
	{

	public:
		XCTree(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCTree() = default;

		XCTree(int x, int y, int width, int height, HXCGUI parent = NULL) {

			m_handle = XTree_Create(x, y, width, height, parent);
		}

		//@备注 启用拖动项功能.  
		 //@参数 bEnable 是否启用.
		 //@别名  启用拖动项()
		void EnableDragItem(bool bEnable) {
			XTree_EnableDragItem(getEleHandle(), bEnable);
		}

		//@备注 启用或禁用显示项的连接线.  
		//@参数 bEnable 是否启用.
		//@参数 bSolid 实线或虚线; TRUE:实线, FALSE:虚线.
		//@别名  启用连接线()
		void EnableConnectLine(bool bEnable, bool bSolid) {
			XTree_EnableConnectLine(getEleHandle(), bEnable, bSolid);
		}

		//@备注 启动或关闭默认展开功能,如果开启新插入的项将自动展开.  
		//@参数 bEnable 是否启用.
		//@别名  启用展开()
		void EnableExpand(bool bEnable) {
			XTree_EnableExpand(getEleHandle(), bEnable);
		}

		//@参数 bEnable 是否启用
		//@别名  启用模板复用()
		void EnablemTemplateReuse(bool bEnable) {
			XTree_EnablemTemplateReuse(getEleHandle(), bEnable);
		}

		//@备注 设置项连接线颜色.  
		//@参数 color 颜色值, 请使用宏: RGBA()
		//@别名  置连接线颜色()
		void SetConnectLineColor(COLORREF color) {
			XTree_SetConnectLineColor(getEleHandle(), color);
		}

		//@备注 设置展开按钮占用空间大小.  
		//@参数 nWidth 宽度.
		//@参数 nHeight 高度.
		//@别名  置展开按钮大小()
		void SetExpandButtonSize(int nWidth, int nHeight) {
			XTree_SetExpandButtonSize(getEleHandle(), nWidth, nHeight);
		}

		//@备注 设置连线绘制长度,展开按钮与项内容之间的连线.  
		//@参数 nLength 连线绘制长度.
		//@别名  置连接线长度()
		void SetConnectLineLength(int nLength) {
			XTree_SetConnectLineLength(getEleHandle(), nLength);
		}

		//@备注 设置拖动项插入位置颜色提示.  
		//@参数 color 颜色值, 请使用宏: RGBA()
		//@别名  置拖动项插入位置颜色()
		void SetDragInsertPositionColor(COLORREF color) {
			XTree_SetDragInsertPositionColor(getEleHandle(), color);
		}

		//@备注 设置项模板文件.  
		//@参数 pXmlFile 文件名.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置项模板文件()
		bool SetItemTemplateXML(const std::wstring& xmlFile) {
			return XTree_SetItemTemplateXML(getEleHandle(), xmlFile.c_str());
		}

		//@备注 设置项模板文件,项选中状态.  
		//@参数 pXmlFile 文件名.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置选择项模板文件()
		bool SetItemTemplateXMLSel(const std::wstring& xmlFile) {
			return XTree_SetItemTemplateXMLSel(getEleHandle(), xmlFile.c_str());
		}

		//@备注 设置列表项模板.  
		//@参数 hTemp 模板句柄.
		//@返回 如果成功返回TRUE,否则返回FALSE.
		//@别名  置项模板()
		bool SetItemTemplate(HTEMP hTemp) {
			return XTree_SetItemTemplate(getEleHandle(), hTemp);
		}

		//@备注 设置列表项模板,项选中状态.  
		//@参数 hTemp 模板句柄.
		//@返回 如果成功返回TRUE,否则返回FALSE.
		//@别名  置选择项模板()
		bool SetItemTemplateSel(HTEMP hTemp) {
			return XTree_SetItemTemplateSel(getEleHandle(), hTemp);
		}

		//@备注 设置项模板文件.  
		//@参数 pStringXML 字符串指针.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置项模板从字符串()
		bool SetItemTemplateXMLFromString(const std::string& xmlData) {
			return XTree_SetItemTemplateXMLFromString(getEleHandle(), xmlData.c_str());
		}

		//@备注 设置项模板文件,项选中状态.  
		//@参数 pStringXML 字符串指针.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置选择项模板从字符串()
		bool SetItemTemplateXMLSelFromString(const std::string& xmlData) {
			return XTree_SetItemTemplateXMLSelFromString(getEleHandle(), xmlData.c_str());
		}

		//@备注 通过模板项ID,获取实例化模板项ID对应的对象句柄.  
		//@参数 nID 树项ID.
		//@参数 nTempItemID 模板项ID.
		//@返回 成功返回对象句柄,否则返回NULL.
		//@别名  取模板对象()
		HXCGUI GetTemplateObject(int nID, int nTempItemID) {
			return XTree_GetTemplateObject(getEleHandle(), nID, nTempItemID);
		}

		//@备注 获取当前对象所在模板实例,属于列表树中哪一个项.  
		//@参数 hXCGUI 对象句柄, UI元素句柄或形状对象句柄..
		//@返回 成功返回项ID, 否则返回@ref XC_ID_ERROR.
		//@别名  取对象所在项()
		int GetItemIDFromHXCGUI(HXCGUI hXCGUI) {
			return XTree_GetItemIDFromHXCGUI(getEleHandle(), hXCGUI);
		}


		//@备注 设置是否绘制指定状态下项的背景.  
		//@参数 nFlags 标志位 @ref list_drawItemBk_flag_.
		//@别名  置项背景绘制标志()
		void SetDrawItemBkFlags(int nFlags) {
			XTree_SetDrawItemBkFlags(getEleHandle(), nFlags);
		}

		//@参数 color 颜色值, 请使用宏: RGBA()
		//@别名  置分割线颜色()
		void SetSplitLineColor(COLORREF color) {
			XTree_SetSplitLineColor(getEleHandle(), color);
		}

		//@备注 设置项用户数据.  
		//@参数 nID 项ID.
		//@参数 nUserData 用户数据.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置项数据()
		bool SetItemData(int nID, vint nUserData) {
			return XTree_SetItemData(getEleHandle(), nID, nUserData);
		}

		//@备注 获取项用户数据.  
		//@参数 nID 项ID.
		//@返回 项用户数据.
		//@别名  取项数据()
		vint GetItemData(int nID) {
			return XTree_GetItemData(getEleHandle(), nID);
		}

		//@备注 设置选择项.  
		//@参数 nID 项ID.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  置选择项()
		bool SetSelectItem(int nID) {
			return XTree_SetSelectItem(getEleHandle(), nID);
		}

		//@备注 获取选择项.  
		//@返回 项ID.
		//@别名  取选择项()
		int GetSelectItem() {
			return XTree_GetSelectItem(getEleHandle());
		}

		//@备注 滚动视图让指定项可见  
		//@参数 nID 项索引.
		//@别名  可视指定项()
		void VisibleItem(int nID) {
			XTree_VisibleItem(getEleHandle(), nID);
		}

		//@备注 判断项是否展开.  
		//@参数 nID 项ID.
		//@返回 如果展开返回TRUE否则返回FALSE.
		//@别名  是否展开()
		bool IsExpand(int nID) {
			return XTree_IsExpand(getEleHandle(), nID);
		}

		//@备注 展开项.  
		//@参数 nID 项ID.
		//@参数 bExpand 是否展开.
		//@返回 成功返回TRUE,如果项已经展开或失败返回FALSE.
		//@别名  展开项()
		bool ExpandItem(int nID, bool bExpand) {
			return XTree_ExpandItem(getEleHandle(), nID, bExpand);
		}

		//@备注 展开所有的子项.  
		//@参数 nID 项ID.
		//@参数 bExpand 是否展开.
		//@返回 成功返回TRUE,失败返回FALSE.
		//@别名  展开全部子项()
		bool ExpandAllChildItem(int nID, bool bExpand) {
			return XTree_ExpandAllChildItem(getEleHandle(), nID, bExpand);
		}

		//@备注 检测坐标点所在项.  
		//@参数 pPt 坐标点.
		//@返回 项ID.
		//@别名  测试点击项()
		int HitTest(POINT* pPt) {
			return XTree_HitTest(getEleHandle(), pPt);
		}

		//@备注 检测坐标点所在项,自动添加滚动视图偏移坐标.  
		//@参数 pPt 坐标点.
		//@返回 项ID.
		//@别名  测试点击项扩展()
		int HitTestOffset(POINT* pPt) {
			return XTree_HitTestOffset(getEleHandle(), pPt);
		}

		//@备注 获取第一个子项.  
		//@参数 nID 项ID.
		//@返回 返回项ID,失败返回XC_ID_ERROR.
		//@别名  取第一个子项()
		int GetFirstChildItem(int nID) {
			return XTree_GetFirstChildItem(getEleHandle(), nID);
		}

		//@备注 获取末尾子项.  
		//@参数 nID 项ID.
		//@返回 返回末尾子项ID,失败返回XC_ID_ERROR.
		//@别名  取末尾子项()
		int GetEndChildItem(int nID) {
			return XTree_GetEndChildItem(getEleHandle(), nID);
		}

		//@备注 获取上一个兄弟项.  
		//@参数 nID 项ID.
		//@返回 返回上一个兄弟项ID, 失败返回 XC_ID_ERROR.
		//@别名  取上一个兄弟项()
		int GetPrevSiblingItem(int nID) {
			return XTree_GetPrevSiblingItem(getEleHandle(), nID);
		}

		//@备注 获取下一个兄弟项.  
		//@参数 nID 项ID.
		//@返回 返回下一个兄弟项ID.
		//@别名  取下一个兄弟项()
		int GetNextSiblingItem(int nID) {
			return XTree_GetNextSiblingItem(getEleHandle(), nID);
		}

		//@备注 获取父项.  
		//@参数 nID 项ID.
		//@返回 返回父项ID,错误返回-1.
		//@别名  取父项()
		int GetParentItem(int nID) {
			return XTree_GetParentItem(getEleHandle(), nID);
		}

		//@备注 创建数据适配器，根据绑定的项模板初始化数据适配器的列.  
		//@返回 返回适配器句柄.
		//@别名  创建数据适配器()
		HXCGUI CreateAdapter() {
			return XTree_CreateAdapter(getEleHandle());
		}

		//@备注 绑定数据适配器.  
		//@参数 hAdapter 数据适配器句柄, XAdTree.
		//@别名  绑定数据适配器()
		void BindAdapter(HXCGUI hAdapter) {
			XTree_BindAdapter(getEleHandle(), hAdapter);
		}

		//@备注 获取数据适配器.  
		//@返回 返回数据适配器句柄.
		//@别名  取数据视频器()
		HXCGUI GetAdapter() {
			return XTree_GetAdapter(getEleHandle());
		}

		//@备注 修改数据后,刷新所有项模板,以便更新数据到模板(如果项可见).  
		//@别名  刷新数据()
		void RefreshData() {
			XTree_RefreshData(getEleHandle());
		}

		//@备注 修改数据后,刷新指定项模板,以便更新数据到模板(如果当前项可见).  
		//@参数 nID 项ID.
		//@别名  刷新指定项()
		void RefreshItem(int nID) {
			XTree_RefreshItem(getEleHandle(), nID);
		}

		//@备注 设置缩进大小.  
		//@参数 nWidth 缩进宽度.
		//@别名  置缩进()
		void SetIndentation(int nWidth) {
			XTree_SetIndentation(getEleHandle(), nWidth);
		}

		//@备注 获取缩进值.  
		//@返回 返回缩进值大小.
		//@别名  取缩进()
		int GetIndentation() {
			return XTree_GetIndentation(getEleHandle());
		}

		//@备注 设置项默认高度.  
		//@参数 nHeight 高度.
		//@参数 nSelHeight 选中时高度.
		//@别名  置项默认高度()
		void SetItemHeightDefault(int nHeight, int nSelHeight) {
			XTree_SetItemHeightDefault(getEleHandle(), nHeight, nSelHeight);
		}

		//@备注 获取项默认高度.  
		//@参数 pHeight 接收返回高度.
		//@参数 pSelHeight 接收返回值,当项选中时的高度.
		//@别名  取项默认高度()
		void GetItemHeightDefault(int* pHeight, int* pSelHeight) {
			XTree_GetItemHeightDefault(getEleHandle(), pHeight, pSelHeight);
		}

		//@备注 设置指定项高度.  
		//@参数 nID 项ID.
		//@参数 nHeight 高度.
		//@参数 nSelHeight 选中时高度.
		//@别名  置项高度()
		void SetItemHeight(int nID, int nHeight, int nSelHeight) {
			XTree_SetItemHeight(getEleHandle(), nID, nHeight, nSelHeight);
		}

		//@备注 获取指定项高度.  
		//@参数 nID 项ID.
		//@参数 pHeight 接收返回高度.
		//@参数 pSelHeight 接收返回值,当项选中时的高度.
		//@别名  取项高度()
		void GetItemHeight(int nID, int* pHeight, int* pSelHeight) {
			XTree_GetItemHeight(getEleHandle(), nID, pHeight, pSelHeight);
		}

		//@备注 设置行间隔大小.  
		//@参数 nSpace 行间隔大小.
		//@别名  置行间距()
		void SetRowSpace(int nSpace) {
			XTree_SetRowSpace(getEleHandle(), nSpace);
		}

		//@备注 获取行间距大小.  
		//@返回 返回行间距大小.
		//@别名  取行间距()
		int GetRowSpace() {
			return XTree_GetRowSpace(getEleHandle());
		}

		//@备注 移动项的位置.  
		//@参数 nMoveItem 要移动的项ID.
		//@参数 nDestItem 目标项ID, 参照位置.
		//@参数 nFlag 0:目标前面, 1:目标后面, 2:目标子项首, 3:目标子项尾
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  移动项()
		bool MoveItem(int nMoveItem, int nDestItem, int nFlag) {
			return XTree_MoveItem(getEleHandle(), nMoveItem, nDestItem, nFlag);
		}


		//@参数 value.c_str() 
		//@参数 nParentID 
		//@参数 insertID 
		//@别名  插入项文本()
		int InsertItemText(const std::wstring& value, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST) {
			return XTree_InsertItemText(getEleHandle(), value.c_str(), nParentID, insertID);
		}

		//@参数 name.c_str() 
		//@参数 value.c_str() 
		//@参数 nParentID 
		//@参数 insertID 
		//@别名  插入项文本扩展()
		int InsertItemTextEx(const std::wstring& name, const std::wstring& value, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST) {
			return XTree_InsertItemTextEx(getEleHandle(), name.c_str(), value.c_str(), nParentID, insertID);
		}

		//@参数 hImage 
		//@参数 nParentID 
		//@参数 insertID 
		//@别名  插入项图片()
		int InsertItemImage(HIMAGE hImage, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST) {
			return XTree_InsertItemImage(getEleHandle(), hImage, nParentID, insertID);
		}

		//@参数 name.c_str() 
		//@参数 hImage 
		//@参数 nParentID 
		//@参数 insertID 
		//@别名  插入项图片扩展()
		int InsertItemImageEx(const std::wstring& name, HIMAGE hImage, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST) {
			return XTree_InsertItemImageEx(getEleHandle(), name.c_str(), hImage, nParentID, insertID);
		}

		//@别名  取项数量()
		int GetCount() {
			return XTree_GetCount(getEleHandle());
		}

		//@别名  取列数量()
		int GetCountColumn() {
			return XTree_GetCountColumn(getEleHandle());
		}

		//@参数 nID 
		//@参数 iColumn 
		//@参数 value.c_str() 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项文本()
		bool SetItemText(int nID, int iColumn, const std::wstring& value) {
			return XTree_SetItemText(getEleHandle(), nID, iColumn, value.c_str());
		}

		//@参数 nID 
		//@参数 name.c_str() 
		//@参数 value.c_str() 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项文本扩展()
		bool SetItemTextEx(int nID, const std::wstring& name, const std::wstring& value) {
			return XTree_SetItemTextEx(getEleHandle(), nID, name.c_str(), value.c_str());
		}

		//@参数 nID 
		//@参数 iColumn 
		//@参数 hImage 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项图片()
		bool SetItemImage(int nID, int iColumn, HIMAGE hImage) {
			return XTree_SetItemImage(getEleHandle(), nID, iColumn, hImage);
		}

		//@参数 nID 
		//@参数 name.c_str() 
		//@参数 hImage 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  置项图片扩展()
		bool SetItemImageEx(int nID, const std::wstring& name, HIMAGE hImage) {
			return XTree_SetItemImageEx(getEleHandle(), nID, name.c_str(), hImage);
		}

		//@参数 nID 
		//@参数 iColumn 
		//@返回 返回文本内容
		//@别名  取项文本()
		std::wstring GetItemText(int nID, int iColumn) {
			auto pText =  XTree_GetItemText(getEleHandle(), nID, iColumn);
			if (!pText) return L"";
			return pText;
		}

		//@参数 nID 
		//@参数 name.c_str() 
		//@返回 返回文本内容
		//@别名  取项文本扩展()
		std::wstring GetItemTextEx(int nID, const std::wstring& name) {
			auto pText = XTree_GetItemTextEx(getEleHandle(), nID, name.c_str());
			if (!pText) return L"";
			return pText;
		}

		//@参数 nID 
		//@参数 iColumn 
		//@别名  取项图片()
		HIMAGE GetItemImage(int nID, int iColumn) {
			return XTree_GetItemImage(getEleHandle(), nID, iColumn);
		}

		//@参数 nID 
		//@参数 name.c_str() 
		//@别名  取项图片扩展()
		HIMAGE GetItemImageEx(int nID, const std::wstring& name) {
			return XTree_GetItemImageEx(getEleHandle(), nID, name.c_str());
		}

		//@备注 XAdTree_DeleteItem  
		//@参数 nID 
		//@返回 成功返回TRUE,否则返回FALSE
		//@别名  删除项()
		bool DeleteItem(int nID) {
			return XTree_DeleteItem(getEleHandle(), nID);
		}

		//@备注 XAdTree_DeleteItemAll  
		//@别名  删除全部项()
		void DeleteItemAll() {
			XTree_DeleteItemAll(getEleHandle());
		}

		//@备注 XAdTree_DeleteColumnAll  
		//@别名  删除列全部()
		void DeleteColumnAll() {
			XTree_DeleteColumnAll(getEleHandle());
		}

	};
}