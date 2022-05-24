#ifndef  XCGUI_CLASS_H
#define  XCGUI_CLASS_H
//@模块名称  炫彩界面库-类
//@版本  3.3.4
//@日期  2022-05-17
//@作者  XCGUI  
//@模块备注  炫彩界面库-class 

//@别名  界面库基类
class CXBase
{
public:
	CXBase(){}
//@备注 获取对象最终类型.  
//@返回 返回对象类型.
//@别名  取类型()
	XC_OBJECT_TYPE GetType(HXCGUI hXCGUI){return XObj_GetType(hXCGUI);}
//@备注 获取对象的基础类型,  
//@返回 返回对象类型, 以下类型之一:
//@别名  取基础类型()
	XC_OBJECT_TYPE GetTypeBase(HXCGUI hXCGUI){return XObj_GetTypeBase(hXCGUI);}
//@备注 获取对象扩展类型.  
//@返回 返回对象扩展类型.
//@别名  取类型扩展()
	XC_OBJECT_TYPE_EX GetTypeEx(HXCGUI hXCGUI){return XObj_GetTypeEx(hXCGUI);}
//@备注 如果是按钮, 请使用按钮的增强接口 XBtn_SetTypeEx()
//@参数 nType 扩展类型,参见宏定义.
//@别名  置类型扩展()
	void SetTypeEx(HXCGUI hXCGUI, XC_OBJECT_TYPE_EX nType){XObj_SetTypeEx(hXCGUI, nType);}
};
//@备注  继承: CXBase
//@别名  可视对象类
class CXObjectUI: public CXBase
{
public:
	CXObjectUI(){}
//@备注 设置UI对象样式
//@参数 nStyle 样式值.
//@别名  置样式()
	void SetStyle(HXCGUI hXCGUI, XC_OBJECT_STYLE nStyle){XUI_SetStyle(hXCGUI, nStyle);}
//@备注 获取UI对象样式
//@返回 返回UI对象样式.
//@别名  取样式()
	XC_OBJECT_STYLE GetStyle(HXCGUI hXCGUI){return XUI_GetStyle(hXCGUI);}
//@备注 启用或禁用样式
//@参数 bEnable 是否启用.
//@别名  启用CSS()
	void EnableCSS(HXCGUI hXCGUI, BOOL bEnable){XUI_EnableCSS(hXCGUI, bEnable);}
//@备注 设置CSS[套用样式]名称
//@参数 pName 套用样式名称.
//@别名  置CSS名称()
	void SetCssName(HXCGUI hXCGUI, const wchar_t* pName){XUI_SetCssName(hXCGUI, pName);}
//@备注 获取CSS样式名称
//@返回 返回CSS样式名称.
//@别名  取CSS名称()
	const wchar_t* GetCssName(HXCGUI hXCGUI){return XUI_GetCssName(hXCGUI);}
};
//@备注  继承: CXObjectUI, CXBase
//@别名  窗口组件类
class CXWidgetUI: public CXObjectUI
{
public:
	CXWidgetUI(){}
//@备注 判断UI对象是否显示
//@返回 显示返回TRUE,否则返回FALSE.
//@别名  是否显示()
	BOOL IsShow(HXCGUI hXCGUI){return XWidget_IsShow(hXCGUI);}
//@参数 bShow 是否显示
//@别名  显示()
	void Show(HXCGUI hXCGUI, BOOL bShow){XWidget_Show(hXCGUI, bShow);}
//@备注 该对象是否受布局控制
//@参数 bEnable 是否启用
//@别名  启用布局控制()
	void EnableLayoutControl(HXCGUI hXCGUI, BOOL bEnable){XWidget_EnableLayoutControl(hXCGUI, bEnable);}
//@返回 如果成功返回TRUE,否则返回FALSE
//@别名  是否布局控制()
	BOOL IsLayoutControl(HXCGUI hXCGUI){return XWidget_IsLayoutControl(hXCGUI);}
//@返回 元素句柄.
//@别名  取父元素()
	HELE GetParentEle(HXCGUI hXCGUI){return XWidget_GetParentEle(hXCGUI);}
//@备注 获取父对象,父可能是元素或窗口,通过此函数可以检查是否有父
//@返回 对象句柄.
//@别名  取父句柄()
	HXCGUI GetParent(HXCGUI hXCGUI){return XWidget_GetParent(hXCGUI);}
//@备注 获取HWND句柄
//@返回 HWND句柄.
//@别名  取窗口句柄系统()
	HWND GetHWND(HXCGUI hXCGUI){return XWidget_GetHWND(hXCGUI);}
//@备注 获取HWINDOW句柄
//@返回 HWINDOW句柄.
//@别名  取窗口句柄()
	HWINDOW GetHWINDOW(HXCGUI hXCGUI){return XWidget_GetHWINDOW(hXCGUI);}
//@备注 设置元素ID
//@参数 nID ID值.
//@别名  置ID()
	void SetID(HXCGUI hXCGUI, int nID){XWidget_SetID(hXCGUI, nID);}
//@备注 获取元素ID
//@返回 返回元素ID.
//@别名  取ID()
	int GetID(HXCGUI hXCGUI){return XWidget_GetID(hXCGUI);}
//@备注 设置元素UID, 全局唯一标识符
//@参数 nUID UID值.
//@别名  置UID()
	void SetUID(HXCGUI hXCGUI, int nUID){XWidget_SetUID(hXCGUI, nUID);}
//@备注 获取元素UID,全局唯一标识符
//@返回 返回元素UID.
//@别名  取UID()
	int GetUID(HXCGUI hXCGUI){return XWidget_GetUID(hXCGUI);}
//@备注 设置元素name
//@参数 pName name值,字符串指针.
//@别名  置名称()
	void SetName(HXCGUI hXCGUI, const wchar_t* pName){XWidget_SetName(hXCGUI, pName);}
//@备注 获取元素name
//@返回 返回name.
//@别名  取名称()
	const wchar_t* GetName(HXCGUI hXCGUI){return XWidget_GetName(hXCGUI);}
//@备注 强制换行
//@参数 bWrap 是否换行
//@别名  布局项_启用换行()
	void LayoutItem_EnableWrap(HXCGUI hXCGUI, BOOL bWrap){XWidget_LayoutItem_EnableWrap(hXCGUI, bWrap);}
//@备注 根据水平垂直布局变换, 交换属性(宽度,高度,最小宽度,最小高度)
//@参数 bEnable 是否启用
//@别名  布局项_启用交换()
	void LayoutItem_EnableSwap(HXCGUI hXCGUI, BOOL bEnable){XWidget_LayoutItem_EnableSwap(hXCGUI, bEnable);}
//@备注 向反方向对齐
//@参数 bFloat 是否浮动
//@别名  布局项_启用浮动()
	void LayoutItem_EnableFloat(HXCGUI hXCGUI, BOOL bFloat){XWidget_LayoutItem_EnableFloat(hXCGUI, bFloat);}
//@参数 nType 类型
//@参数 nWidth 宽度
//@别名  布局项_置宽度()
	void LayoutItem_SetWidth(HXCGUI hXCGUI, layout_size_ nType, int nWidth){XWidget_LayoutItem_SetWidth(hXCGUI, nType, nWidth);}
//@参数 nType 类型
//@参数 nHeight 高度
//@别名  布局项_置高度()
	void LayoutItem_SetHeight(HXCGUI hXCGUI, layout_size_ nType, int nHeight){XWidget_LayoutItem_SetHeight(hXCGUI, nType, nHeight);}
//@参数 pType 类型
//@参数 pWidth 返回值
//@别名  布局项_取宽度()
	void LayoutItem_GetWidth(HXCGUI hXCGUI, layout_size_* pType, int* pWidth){XWidget_LayoutItem_GetWidth(hXCGUI, pType, pWidth);}
//@参数 pType 类型
//@参数 pHeight 返回值
//@别名  布局项_取高度()
	void LayoutItem_GetHeight(HXCGUI hXCGUI, layout_size_* pType, int* pHeight){XWidget_LayoutItem_GetHeight(hXCGUI, pType, pHeight);}
//@备注 根据水平垂直轴变化对齐
//@参数 nAlign 对齐方式
//@别名  布局项_置对齐()
	void LayoutItem_SetAlign(HXCGUI hXCGUI, layout_align_axis_ nAlign){XWidget_LayoutItem_SetAlign(hXCGUI, nAlign);}
//@参数 left 左边大小
//@参数 top 上边大小
//@参数 right 右边大小
//@参数 bottom 下边大小
//@别名  布局项_置外间距()
	void LayoutItem_SetMargin(HXCGUI hXCGUI, int left, int top, int right, int bottom){XWidget_LayoutItem_SetMargin(hXCGUI, left, top, right, bottom);}
//@参数 pMargin 接收返回
//@别名  布局项_取外间距()
	void LayoutItem_GetMargin(HXCGUI hXCGUI, marginSize_* pMargin){XWidget_LayoutItem_GetMargin(hXCGUI, pMargin);}
//@备注 限制大小仅针对缩放有效(自动, 填充父, 比例, 百分比)
//@参数 width 最小宽度
//@参数 height 最小高度
//@别名  布局项_置最小大小()
	void LayoutItem_SetMinSize(HXCGUI hXCGUI, int width, int height){XWidget_LayoutItem_SetMinSize(hXCGUI, width, height);}
//@备注 相对位置, 值大于等于0有效
//@参数 left 左边距离
//@参数 top 上边距离
//@参数 right 右边距离
//@参数 bottom 下边距离
//@别名  布局项_置位置()
	void LayoutItem_SetPosition(HXCGUI hXCGUI, int left, int top, int right, int bottom){XWidget_LayoutItem_SetPosition(hXCGUI, left, top, right, bottom);}
};
//@备注  继承: CXObjectUI, CXObjectUI, CXBase
//@别名  窗口类
class CXWindow: public CXObjectUI
{
public:
	//@别名  句柄
	HWINDOW m_hWindow;
	CXWindow(){}
//@备注 创建窗口  
//@参数 x 窗口左上角x坐标.
//@参数 y 窗口左上角y坐标.
//@参数 cx 窗口宽度.
//@参数 cy 窗口高度.
//@参数 pTitle 窗口标题.
//@参数 hWndParent 父窗口.
//@参数 XCStyle GUI库窗口样式,样式请参见宏定义 @ref window_style_.
//@返回 GUI库窗口资源句柄.
//@别名  创建()
	HWINDOW Create(int x, int y, int cx, int cy, const wchar_t* pTitle, HWND hWndParent=NULL, int XCStyle=window_style_default){m_hWindow = XWnd_Create(x, y, cx, cy, pTitle, hWndParent, XCStyle);return m_hWindow;}
//@备注 创建窗口  
//@参数 x 窗口左上角x坐标.
//@参数 y 窗口左上角y坐标.
//@参数 cx 窗口宽度.
//@参数 cy 窗口高度.
//@参数 pTitle 窗口标题.
//@参数 hWndParent 父窗口.
//@参数 XCStyle GUI库窗口样式,样式请参见宏定义 @ref window_style_.
//@返回 GUI库窗口资源句柄.
CXWindow(int x, int y, int cx, int cy, const wchar_t* pTitle, HWND hWndParent=NULL, int XCStyle=window_style_default){m_hWindow = XWnd_Create(x, y, cx, cy, pTitle, hWndParent, XCStyle);}
//@备注 创建窗口,增强功能.   
//@参数 dwExStyle 窗口扩展样式.
//@参数 dwStyle 窗口样式
//@参数 lpClassName 窗口类名.
//@参数 x 窗口左上角x坐标.
//@参数 y 窗口左上角y坐标.
//@参数 cx 窗口宽度.
//@参数 cy 窗口高度.
//@参数 pTitle 窗口名.
//@参数 hWndParent 父窗口.
//@参数 XCStyle GUI库窗口样式,样式请参见宏定义 @ref window_style_.
//@返回 GUI库窗口资源句柄.
//@别名  创建扩展()
	HWINDOW CreateEx(DWORD dwExStyle, DWORD dwStyle, const wchar_t* lpClassName, int x, int y, int cx, int cy, const wchar_t* pTitle, HWND hWndParent=NULL, int XCStyle=window_style_default){m_hWindow = XWnd_CreateEx(dwExStyle, dwStyle, lpClassName, x, y, cx, cy, pTitle, hWndParent, XCStyle);return m_hWindow;}
//@参数 hWnd 要附加的外部窗口句柄
//@参数 XCStyle GUI库窗口样式,样式请参见宏定义 @ref window_style_
//@返回 返回窗口句柄
//@别名  附加窗口()
	HWINDOW Attach(HWND hWnd, int XCStyle){m_hWindow = XWnd_Attach(hWnd, XCStyle);return m_hWindow;}
//@备注 注册事件函数C方式,事件函数省略自身HWINDOW句柄. 
//@参数 nEvent 事件类型.
//@参数 pFun 事件函数.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  注册事件C()
	BOOL RegEventC(int nEvent, void* pFun){return XWnd_RegEventC(m_hWindow, nEvent, pFun);}
//@备注 注册事件函数C方式,事件函数不省略自身HWINDOW句柄.   
//@参数 nEvent 事件类型.
//@参数 pFun 事件函数.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  注册事件C1()
	BOOL RegEventC1(int nEvent, void* pFun){return XWnd_RegEventC1(m_hWindow, nEvent, pFun);}
//@备注 移除事件函数.   
//@参数 nEvent 事件类型.
//@参数 pFun 事件函数.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  移除事件C()
	BOOL RemoveEventC(int nEvent, void* pFun){return XWnd_RemoveEventC(m_hWindow, nEvent, pFun);}
//@备注 添加子对象到窗口   
//@参数 hChild 要添加的对象句柄.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  添加子对象()
	BOOL AddChild(HXCGUI hChild){return XWnd_AddChild(m_hWindow, hChild);}
//@备注 插入子对象到指定位置.  
//@参数 hChild 要插入的对象句柄.
//@参数 index 插入位置索引.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  插入子对象()
	BOOL InsertChild(HXCGUI hChild, int index){return XWnd_InsertChild(m_hWindow, hChild, index);}
//@备注 重绘窗口. 
//@参数 bUpdate 是否立即重绘,默认为否.
//@别名  重绘()
	void Redraw(BOOL bUpdate=FALSE){XWnd_Redraw(m_hWindow, bUpdate);}
//@备注 重绘窗口指定区域. 
//@参数 pRect 需要重绘的区域坐标.
//@参数 bUpdate TRUE立即重绘,FALSE放入消息队列延迟重绘.
//@别名  重绘指定区域()
	void RedrawRect(RECT* pRect, BOOL bUpdate=FALSE){XWnd_RedrawRect(m_hWindow, pRect, bUpdate);}
//@备注 设置焦点元素. 
//@参数 hFocusEle 将获得焦点的元素.
//@别名  置焦点()
	void SetFocusEle(HELE hFocusEle){XWnd_SetFocusEle(m_hWindow, hFocusEle);}
//@备注 获得拥有输入焦点的元素.  
//@返回 元素句柄.
//@别名  取焦点()
	HELE GetFocusEle(){return XWnd_GetFocusEle(m_hWindow);}
//@备注 获取当前鼠标所停留元素.  
//@返回 返回鼠标停留元素句柄.
//@别名  取鼠标停留元素()
	HELE GetStayEle(){return XWnd_GetStayEle(m_hWindow);}
//@备注 在自绘事件函数中,用户手动调用绘制窗口,以便控制绘制顺序.  
//@参数 hDraw 图形绘制句柄.
//@别名  绘制()
	void DrawWindow(HDRAW hDraw){XWnd_DrawWindow(m_hWindow, hDraw);}
//@备注 居中窗口. 
//@别名  居中()
	void Center(){XWnd_Center(m_hWindow);}
//@备注 居中窗口. 
//@参数 width 窗口宽度
//@参数 height 窗口高度
//@别名  居中扩展()
	void CenterEx(int width, int height){XWnd_CenterEx(m_hWindow, width, height);}
//@备注 设置窗口鼠标光标. 
//@参数 hCursor 鼠标光标句柄.
//@别名  置光标()
	void SetCursor(HCURSOR hCursor){XWnd_SetCursor(m_hWindow, hCursor);}
//@备注 获取窗口的鼠标光标. 
//@返回 鼠标光标句柄.
//@别名  取光标()
	HCURSOR GetCursor(){return XWnd_GetCursor(m_hWindow);}
//@备注 获取HWND句柄. 
//@返回 HWND句柄.
//@别名  取HWND()
	HWND GetHWND(){return XWnd_GetHWND(m_hWindow);}
//@备注 启用拖动窗口边框. 
//@参数 bEnable 是否启用.
//@别名  启用拖动边框()
	void EnableDragBorder(BOOL bEnable){XWnd_EnableDragBorder(m_hWindow, bEnable);}
//@备注 启用拖动窗口. 
//@参数 bEnable 是否启用.
//@别名  启用拖动窗口()
	void EnableDragWindow(BOOL bEnable){XWnd_EnableDragWindow(m_hWindow, bEnable);}
//@备注 启用拖动窗口标题栏. 
//@参数 bEnable 是否启用.
//@别名  启用拖动标题栏()
	void EnableDragCaption(BOOL bEnable){XWnd_EnableDragCaption(m_hWindow, bEnable);}
//@备注 是否绘制窗口背景.  
//@参数 bEnable 是否启用.
//@别名  启用绘制背景()
	void EnableDrawBk(BOOL bEnable){XWnd_EnableDrawBk(m_hWindow, bEnable);}
//@备注 当鼠标左键按下是否获得焦点. 
//@参数 bEnable 是否启用.
//@别名  启用自动焦点()
	void EnableAutoFocus(BOOL bEnable){XWnd_EnableAutoFocus(m_hWindow, bEnable);}
//@备注 允许窗口最大化.  
//@参数 bEnable 是否启用.
//@别名  启用允许最大化()
	void EnableMaxWindow(BOOL bEnable){XWnd_EnableMaxWindow(m_hWindow, bEnable);}
//@备注 限制窗口最小和最大尺寸
//@参数 bEnable 是否启用
//@别名  启用限制窗口大小()
	void EnablemLimitWindowSize(BOOL bEnable){XWnd_EnablemLimitWindowSize(m_hWindow, bEnable);}
//@参数 bEnable 是否启用
//@别名  启用拖放文件()
	void EnableDragFiles(BOOL bEnable){XWnd_EnableDragFiles(m_hWindow, bEnable);}
//@备注 启用布局功能.   
//@参数 bEnable 是否启用.
//@别名  启用布局()
	void EnableLayout(BOOL bEnable){XWnd_EnableLayout(m_hWindow, bEnable);}
//@参数 bEnable 是否启用
//@别名  启用布局覆盖边框()
	void EnableLayoutOverlayBorder(BOOL bEnable){XWnd_EnableLayoutOverlayBorder(m_hWindow, bEnable);}
//@备注 显示布局边界.  
//@参数 bEnable 是否启用.
//@别名  显示布局边界()
	void ShowLayoutFrame(BOOL bEnable){XWnd_ShowLayoutFrame(m_hWindow, bEnable);}
//@备注 判断是否启用布局. 
//@返回 如果成功返回TRUE,否则返回FALSE.
//@别名  是否启用布局()
	BOOL IsEnableLayout(){return XWnd_IsEnableLayout(m_hWindow);}
//@返回 如果窗口最大化返回TRUE,否则返回FALSE
//@别名  是否最大化()
	BOOL IsMaxWindow(){return XWnd_IsMaxWindow(m_hWindow);}
//@返回 窗口边框可拖动返回TRUE,否则返回FALSE
//@别名  是否可拖动边框()
	BOOL IsDragBorder(){return XWnd_IsDragBorder(m_hWindow);}
//@返回 窗口内容区可拖动返回TRUE,否则返回FALSE
//@别名  是否可拖动窗口()
	BOOL IsDragWindow(){return XWnd_IsDragWindow(m_hWindow);}
//@返回 窗口标题可拖动返回TRUE,否则返回FALSE
//@别名  是否可拖动标题栏()
	BOOL IsDragCaption(){return XWnd_IsDragCaption(m_hWindow);}
//@备注 设置鼠标捕获元素. 
//@参数 hEle 元素句柄.
//@别名  置鼠标捕获元素()
	void SetCaptureEle(HELE hEle){XWnd_SetCaptureEle(m_hWindow, hEle);}
//@备注 获取当前鼠标捕获元素. 
//@返回 元素句柄.
//@别名  取鼠标捕获元素()
	HELE GetCaptureEle(){return XWnd_GetCaptureEle(m_hWindow);}
//@备注 获取重绘区域. 
//@参数 pRcPaint 重绘区域坐标.
//@别名  取绘制矩形()
	void GetDrawRect(RECT* pRcPaint){XWnd_GetDrawRect(m_hWindow, pRcPaint);}
//@备注 显示隐藏窗口
//@参数 bShow 是否显示
//@别名  显示()
	void Show(BOOL bShow){XWnd_Show(m_hWindow, bShow);}
//@备注 显示隐藏及控制窗口最大化还原等
//@参数 nCmdShow 参见MSDN.
//@返回 参见MSDN.
//@别名  显示扩展()
	BOOL ShowWindow(int nCmdShow){return XWnd_ShowWindow(m_hWindow, nCmdShow);}
//@备注 系统函数,设置窗口类光标句柄. 
//@参数 hCursor 光标句柄.
//@返回 返回先前的光标句柄.
//@别名  置系统光标()
	HCURSOR SetCursorSys(HCURSOR hCursor){return XWnd_SetCursorSys(m_hWindow, hCursor);}
//@备注 设置窗口字体.  
//@参数 hFontx 炫彩字体句柄.
//@别名  置字体()
	void SetFont(HFONTX hFontx){XWnd_SetFont(m_hWindow, hFontx);}
//@备注 设置文本颜色. 
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置文本颜色()
	void SetTextColor(COLORREF color){XWnd_SetTextColor(m_hWindow, color);}
//@备注 获取文本颜色. 
//@返回 文本颜色值.
//@别名  取文件颜色()
	COLORREF GetTextColor(){return XWnd_GetTextColor(m_hWindow);}
//@备注 获取文本颜色,优先从资源中获取.  
//@返回 文本颜色值.
//@别名  取文本颜色扩展()
	COLORREF GetTextColorEx(){return XWnd_GetTextColorEx(m_hWindow);}
//@备注 设置窗口ID. 
//@参数 nID ID值.
//@别名  置ID()
	void SetID(int nID){XWnd_SetID(m_hWindow, nID);}
//@备注 获取窗口ID. 
//@返回 返回窗口ID值.
//@别名  取ID()
	int GetID(){return XWnd_GetID(m_hWindow);}
//@备注 设置窗口name 
//@参数 pName name值,字符串指针.
//@别名  置名称()
	void SetName(const wchar_t* pName){XWnd_SetName(m_hWindow, pName);}
//@备注 获取窗口name 
//@返回 返回name
//@别名  取名称()
	const wchar_t* GetName(){return XWnd_GetName(m_hWindow);}
//@备注 设置边大小. 
//@参数 left 窗口左边大小.
//@参数 top 窗口上边大小.
//@参数 right 窗口右边大小.
//@参数 bottom 窗口底部大小.
//@别名  置边大小()
	void SetBorderSize(int left, int top, int right, int bottom){XWnd_SetBorderSize(m_hWindow, left, top, right, bottom);}
//@备注 获取边大小. 
//@参数 pBorder 接收返回边大小.
//@别名  取边大小()
	void GetBorderSize(borderSize_* pBorder){XWnd_GetBorderSize(m_hWindow, pBorder);}
//@参数 left 左边大小.
//@参数 top 上边大小.
//@参数 right 右边大小.
//@参数 bottom 下边大小.
//@别名  置内填充大小()
	void SetPadding(int left, int top, int right, int bottom){XWnd_SetPadding(m_hWindow, left, top, right, bottom);}
//@备注 设置窗口拖动边框大小.  
//@参数 left 窗口左边大小.
//@参数 top 窗口上边大小.
//@参数 right 窗口右边大小.
//@参数 bottom 窗口底边大小.
//@别名  置拖动边框大小()
	void SetDragBorderSize(int left, int top, int right, int bottom){XWnd_SetDragBorderSize(m_hWindow, left, top, right, bottom);}
//@备注 获取窗口拖动边框大小.  
//@参数 pSize 拖动边框大小.
//@别名  取拖动边框大小()
	void GetDragBorderSize(borderSize_* pSize){XWnd_GetDragBorderSize(m_hWindow, pSize);}
//@备注 设置标题内容(图标,标题,控制按钮)外间距
//@参数 left 左边间距
//@参数 top 上边间距
//@参数 right 右边间距
//@参数 bottom 下边间距
//@别名  置标题外间距()
	void SetCaptionMargin(int left, int top, int right, int bottom){XWnd_SetCaptionMargin(m_hWindow, left, top, right, bottom);}
//@备注 设置窗口的最小宽度和高度.  
//@参数 width 最小宽度.
//@参数 height 最小高度.
//@别名  置最小大小()
	void SetMinimumSize(int width, int height){XWnd_SetMinimumSize(m_hWindow, width, height);}
//@备注 检测所在元素.  
//@参数 pPt 左边点.
//@返回 元素句柄.
//@别名  测试点击子元素()
	HELE HitChildEle(POINT* pPt){return XWnd_HitChildEle(m_hWindow, pPt);}
//@备注 获取当前层子对象数量,不包含子元素的子元素.  
//@返回 子元素数量.
//@别名  取子对象数量()
	int GetChildCount(){return XWnd_GetChildCount(m_hWindow);}
//@备注 获取当前层子元素通过索引.  
//@参数 index 元素索引.
//@返回 元素句柄.
//@别名  取子对象从索引()
	HXCGUI GetChildByIndex(int index){return XWnd_GetChildByIndex(m_hWindow, index);}
//@备注 获取当前层子对象通过对象ID.  
//@参数 nID 元素ID,ID必须大于0.
//@返回 对象句柄.
//@别名  取子对象从ID()
	HXCGUI GetChildByID(int nID){return XWnd_GetChildByID(m_hWindow, nID);}
//@备注 获取子对象通过对象ID,如果对象不在该窗口上无效.  
//@参数 nID 对象ID,ID必须大于0.
//@返回 元素句柄.
//@别名  取子对象()
	HXCGUI GetChild(int nID){return XWnd_GetChild(m_hWindow, nID);}
//@参数 hImage 图标句柄
//@别名  置图标()
	void SetIcon(HIMAGE hImage){XWnd_SetIcon(m_hWindow, hImage);}
//@参数 pTitle 标题文本
//@别名  置标题()
	void SetTitle(const wchar_t* pTitle){XWnd_SetTitle(m_hWindow, pTitle);}
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置标题颜色()
	void SetTitleColor(COLORREF color){XWnd_SetTitleColor(m_hWindow, color);}
//@参数 nFlag 可用值: @ref window_style_btn_min , @ref window_style_btn_max , @ref window_style_btn_close
//@返回 返回按钮句柄
//@别名  取控制按钮()
	HELE GetButton(int nFlag){return XWnd_GetButton(m_hWindow, nFlag);}
//@返回 返回图标句柄
//@别名  取图标()
	HIMAGE GetIcon(){return XWnd_GetIcon(m_hWindow);}
//@返回 返回标题文本
//@别名  取标题()
	const wchar_t* GetTitle(){return XWnd_GetTitle(m_hWindow);}
//@返回 返回颜色值
//@别名  取标题颜色()
	COLORREF GetTitleColor(){return XWnd_GetTitleColor(m_hWindow);}
//@备注 关闭窗口. 
//@别名  关闭()
	void CloseWindow(){XWnd_CloseWindow(m_hWindow);}
//@备注 调整窗口布局.  
//@别名  调整布局()
	void AdjustLayout(){XWnd_AdjustLayout(m_hWindow);}
//@备注 调整窗口布局.   
//@参数 nFlags 调整标识, @ref adjustLayout_
//@返回 如果成功返回TRUE,否则返回FALSE.
//@别名  调整布局扩展()
	void AdjustLayoutEx(int nFlags=adjustLayout_self){XWnd_AdjustLayoutEx(m_hWindow, nFlags);}
//@备注 创建插入符,基于元素坐标.  
//@参数 hEle 元素句柄.
//@参数 x x坐标.
//@参数 y y坐标.
//@参数 width 宽度.
//@参数 height 高度.
//@别名  创建插入符()
	void CreateCaret(HELE hEle, int x, int y, int width, int height){XWnd_CreateCaret(m_hWindow, hEle, x, y, width, height);}
//@备注 设置插入符位置. 
//@参数 x x坐标.
//@参数 y y坐标.
//@参数 width 宽度.
//@参数 height 高度.
//@参数 bUpdate 是否立即更新UI
//@别名  置插入符位置()
	void SetCaretPos(int x, int y, int width, int height, BOOL bUpdate=FALSE){XWnd_SetCaretPos(m_hWindow, x, y, width, height, bUpdate);}
//@备注 设置插入符颜色.  
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置插入符颜色()
	void SetCaretColor(COLORREF color){XWnd_SetCaretColor(m_hWindow, color);}
//@备注 显示插入符. 
//@参数 bShow 是否显示.
//@别名  显示插入符()
	void ShowCaret(BOOL bShow){XWnd_ShowCaret(m_hWindow, bShow);}
//@返回 返回插入符元素
//@别名  取插入符元素()
	HELE GetCaretHELE(){return XWnd_GetCaretHELE(m_hWindow);}
//@备注 获取插入符信息
//@参数 pX 接收返回x坐标
//@参数 pY 接收返回y坐标
//@参数 pWidth 接收返回宽度
//@参数 pHeight 接收返回高度
//@返回 插入符元素句柄
//@别名  取插入符信息()
	HELE GetCaretInfo(int* pX, int* pY, int* pWidth, int* pHeight){return XWnd_GetCaretInfo(m_hWindow, pX, pY, pWidth, pHeight);}
//@备注 销毁插入符.  
//@别名  销毁插入符()
	void DestroyCaret(){XWnd_DestroyCaret(m_hWindow);}
//@备注 获取窗口客户区坐标;如果是阴影窗口,那么不包含阴影部分.  
//@参数 pRect 坐标.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  取客户区坐标()
	BOOL GetClientRect(RECT* pRect){return XWnd_GetClientRect(m_hWindow, pRect);}
//@备注 获取body坐标.  
//@参数 pRect 坐标.
//@别名  取Body坐标()
	void GetBodyRect(RECT* pRect){XWnd_GetBodyRect(m_hWindow, pRect);}
//@参数 pRect 接收返回坐标
//@别名  取布局坐标()
	void GetLayoutRect(RECT* pRect){XWnd_GetLayoutRect(m_hWindow, pRect);}
//@备注 移动窗口
//@参数 x X坐标
//@参数 y Y坐标
//@别名  置位置()
	void SetPosition(int x, int y){XWnd_SetPosition(m_hWindow, x, y);}
//@参数 pRect 坐标
//@别名  取坐标()
	void GetRect(RECT* pRect){XWnd_GetRect(m_hWindow, pRect);}
//@参数 pRect 坐标
//@别名  置坐标()
	void SetRect(RECT* pRect){XWnd_SetRect(m_hWindow, pRect);}
//@别名  置顶()
	void SetTop(){XWnd_SetTop(m_hWindow);}
//@参数 bMaximize 是否最大化
//@别名  最大化()
	void MaxWindow(BOOL bMaximize){XWnd_MaxWindow(m_hWindow, bMaximize);}
//@备注 设置窗口定时器.  
//@参数 nIDEvent 定时器ID.
//@参数 uElapse 间隔值,单位毫秒.
//@返回 参见MSDN.
//@别名  置定时器()
	UINT SetTimer(UINT nIDEvent, UINT uElapse){return XWnd_SetTimer(m_hWindow, nIDEvent, uElapse);}
//@备注 关闭定时器.  
//@参数 nIDEvent 定时器ID.
//@返回 参见MSDN.
//@别名  关闭定时器()
	BOOL KillTimer(UINT nIDEvent){return XWnd_KillTimer(m_hWindow, nIDEvent);}
//@备注 设置炫彩窗口定时器.  
//@参数 nIDEvent 定时器ID.
//@参数 uElapse 间隔值,单位毫秒.
//@返回 成功返回TURE,否则返回FALSE.
//@别名  置炫彩定时器()
	BOOL SetXCTimer(UINT nIDEvent, UINT uElapse){return XWnd_SetXCTimer(m_hWindow, nIDEvent, uElapse);}
//@备注 关闭炫彩窗口定时器.  
//@参数 nIDEvent 定时器ID.
//@返回 成功返回TURE,否则返回FALSE.
//@别名  关闭炫彩定时器()
	BOOL KillXCTimer(UINT nIDEvent){return XWnd_KillXCTimer(m_hWindow, nIDEvent);}
//@备注 添加背景内容边框
//@参数 nState 组合状态
//@参数 color 颜色.
//@参数 width 线宽.
//@别名  添加背景边框()
	void AddBkBorder(int nState, COLORREF color, int width){XWnd_AddBkBorder(m_hWindow, nState, color, width);}
//@备注 添加背景内容填充
//@参数 nState 组合状态
//@参数 color 颜色.
//@别名  添加背景填充()
	void AddBkFill(int nState, COLORREF color){XWnd_AddBkFill(m_hWindow, nState, color);}
//@备注 添加背景内容图片
//@参数 nState 组合状态
//@参数 hImage 图片句柄.
//@别名  添加背景图片()
	void AddBkImage(int nState, HIMAGE hImage){XWnd_AddBkImage(m_hWindow, nState, hImage);}
//@参数 pText 背景内容字符串
//@返回 返回设置的背景对象数量
//@别名  置背景()
	int SetBkInfo(const wchar_t* pText){return XWnd_SetBkInfo(m_hWindow, pText);}
//@备注 获取背景内容数量
//@返回 返回背景内容数量.
//@别名  取背景对象数量()
	int GetBkInfoCount(){return XWnd_GetBkInfoCount(m_hWindow);}
//@备注 清空背景内容; 如果背景没有内容,将使用系统默认内容,以便保证背景正确
//@别名  清空背景对象()
	void ClearBkInfo(){XWnd_ClearBkInfo(m_hWindow);}
//@备注 获取背景管理器.  
//@返回 背景管理器.
//@别名  取背景管理器()
	HBKM GetBkManager(){return XWnd_GetBkManager(m_hWindow);}
//@备注 获取背景管理器,优先从资源中获取.  
//@返回 背景管理器.
//@别名  取背景管理器扩展()
	HBKM GetBkManagerEx(){return XWnd_GetBkManagerEx(m_hWindow);}
//@参数 hBkInfoM 背景管理器
//@别名  置背景管理器()
	void SetBkMagager(HBKM hBkInfoM){XWnd_SetBkMagager(m_hWindow, hBkInfoM);}
//@备注 设置透明窗口,同时可以通过该函数关闭透明窗口;  
//@参数 nType 窗口透明类型.
//@别名  置透明类型()
	void SetTransparentType(window_transparent_ nType){XWnd_SetTransparentType(m_hWindow, nType);}
//@备注 设置透明窗口的透明度,设置后调用重绘窗口API来更新. 
//@参数 alpha 窗口透明度,范围0-255之间,0透明,255不透明.
//@别名  置透明度()
	void SetTransparentAlpha(BYTE alpha){XWnd_SetTransparentAlpha(m_hWindow, alpha);}
//@备注 设置透明窗口的透明色.  
//@参数 color 窗口透明色.
//@别名  置透明色()
	void SetTransparentColor(COLORREF color){XWnd_SetTransparentColor(m_hWindow, color);}
//@备注 设置窗口阴影信息.   
//@参数 nSize 阴影大小
//@参数 nDepth 阴影深度,0-255.
//@参数 nAngeleSize 圆角阴影内收大小.
//@参数 bRightAngle 是否强制直角.
//@参数 color 阴影颜色. 
//@别名  置阴影信息()
	void SetShadowInfo(int nSize, int nDepth, int nAngeleSize, BOOL bRightAngle, COLORREF color){XWnd_SetShadowInfo(m_hWindow, nSize, nDepth, nAngeleSize, bRightAngle, color);}
//@备注 获取窗口阴影信息.  
//@参数 pnSize 阴影大小.
//@参数 pnDepth 阴影深度.
//@参数 pnAngeleSize 圆角阴影内收大小 .
//@参数 pbRightAngle 是否强制直角.
//@参数 pColor 阴影颜色.
//@别名  取阴影信息()
	void GetShadowInfo(int* pnSize, int* pnDepth, int* pnAngeleSize, BOOL* pbRightAngle, COLORREF* pColor){XWnd_GetShadowInfo(m_hWindow, pnSize, pnDepth, pnAngeleSize, pbRightAngle, pColor);}
//@备注 获取窗口透明类型  
//@返回 返回窗口透明类型.
//@别名  取透明类型()
	window_transparent_ GetTransparentType(){return XWnd_GetTransparentType(m_hWindow);}
};
//@备注  继承: CXWindow, CXObjectUI, CXBase
//@别名  模态窗口类
class CXModalWindow: public CXWindow
{
public:
	CXModalWindow(){}
//@备注 创建模态窗口;当模态窗口关闭时,会自动销毁模态窗口资源句柄.  
//@参数 nWidth 宽度.
//@参数 nHeight 高度.
//@参数 pTitle 窗口标题内容.
//@参数 hWndParent 父窗口句柄.
//@参数 XCStyle GUI库窗口样式,样式请参见宏定义 @ref window_style_.
//@返回 模态窗口句柄.
//@别名  创建()
	HWINDOW Create(int nWidth, int nHeight, const wchar_t* pTitle, HWND hWndParent, int XCStyle=window_style_modal){m_hWindow = XModalWnd_Create(nWidth, nHeight, pTitle, hWndParent, XCStyle);return m_hWindow;}
//@备注 创建模态窗口;当模态窗口关闭时,会自动销毁模态窗口资源句柄.  
//@参数 nWidth 宽度.
//@参数 nHeight 高度.
//@参数 pTitle 窗口标题内容.
//@参数 hWndParent 父窗口句柄.
//@参数 XCStyle GUI库窗口样式,样式请参见宏定义 @ref window_style_.
//@返回 模态窗口句柄.
CXModalWindow(int nWidth, int nHeight, const wchar_t* pTitle, HWND hWndParent, int XCStyle=window_style_modal){m_hWindow = XModalWnd_Create(nWidth, nHeight, pTitle, hWndParent, XCStyle);}
//@备注 创建模态窗口,增强功能.  
//@参数 dwExStyle 窗口扩展样式.
//@参数 dwStyle 窗口样式.
//@参数 lpClassName 窗口类名.
//@参数 x 窗口左上角x坐标.
//@参数 y 窗口左上角y坐标.
//@参数 cx 窗口宽度.
//@参数 cy 窗口高度.
//@参数 pTitle 窗口名.
//@参数 hWndParent 父窗口.
//@参数 XCStyle GUI库窗口样式,样式请参见宏定义 @ref window_style_.
//@返回 GUI库窗口资源句柄.
//@别名  创建扩展()
	HWINDOW CreateEx(DWORD dwExStyle, DWORD dwStyle, const wchar_t* lpClassName, int x, int y, int cx, int cy, const wchar_t* pTitle, HWND hWndParent, int XCStyle=window_style_modal){m_hWindow = XModalWnd_CreateEx(dwExStyle, dwStyle, lpClassName, x, y, cx, cy, pTitle, hWndParent, XCStyle);return m_hWindow;}
//@参数 hWnd 要附加的外部窗口句柄
//@参数 XCStyle GUI库窗口样式,样式请参见宏定义 @ref window_style_
//@返回 返回窗口句柄
//@别名  附加窗口()
	HWINDOW Attach(HWND hWnd, int XCStyle){m_hWindow = XModalWnd_Attach(hWnd, XCStyle);return m_hWindow;}
//@备注 是否自动关闭窗口,当窗口失去焦点时.  
//@参数 bEnable 开启开关.
//@别名  启用自动关闭()
	void EnableAutoClose(BOOL bEnable){XModalWnd_EnableAutoClose(m_hWindow, bEnable);}
//@备注 当用户按ESC键时自动关闭模态窗口.  
//@参数 bEnable 是否启用
//@别名  启用ESC关闭()
	void EnableEscClose(BOOL bEnable){XModalWnd_EnableEscClose(m_hWindow, bEnable);}
//@备注 启动显示模态窗口,当窗口关闭时返回.  
//@返回 messageBox_flag_ok:点击确定按钮退出.messageBox_flag_cancel:点击取消按钮退出.messageBox_flag_other:其他方式退出.
//@别名  启动()
	int DoModal(){return XModalWnd_DoModal(m_hWindow);}
//@备注 结束模态窗口.  
//@参数 nResult XModalWnd_DoModal() 返回值.
//@别名  结束()
	void EndModal(int nResult){XModalWnd_EndModal(m_hWindow, nResult);}
};
//@备注  继承: CXWindow, CXObjectUI, CXBase
//@别名  框架窗口类
class CXFrameWindow: public CXWindow
{
public:
	CXFrameWindow(){}
//@备注 创建框架窗口  
//@参数 x 窗口左上角x坐标.
//@参数 y 窗口左上角y坐标.
//@参数 cx 窗口宽度.
//@参数 cy 窗口高度.
//@参数 pTitle 窗口标题.
//@参数 hWndParent 父窗口.
//@参数 XCStyle GUI库窗口样式,样式请参见宏定义 @ref window_style_.
//@返回 GUI库窗口资源句柄.
//@别名  创建()
	HWINDOW Create(int x, int y, int cx, int cy, const wchar_t* pTitle, HWND hWndParent, int XCStyle){m_hWindow = XFrameWnd_Create(x, y, cx, cy, pTitle, hWndParent, XCStyle);return m_hWindow;}
//@备注 创建框架窗口  
//@参数 x 窗口左上角x坐标.
//@参数 y 窗口左上角y坐标.
//@参数 cx 窗口宽度.
//@参数 cy 窗口高度.
//@参数 pTitle 窗口标题.
//@参数 hWndParent 父窗口.
//@参数 XCStyle GUI库窗口样式,样式请参见宏定义 @ref window_style_.
//@返回 GUI库窗口资源句柄.
CXFrameWindow(int x, int y, int cx, int cy, const wchar_t* pTitle, HWND hWndParent, int XCStyle){m_hWindow = XFrameWnd_Create(x, y, cx, cy, pTitle, hWndParent, XCStyle);}
//@备注 创建框架窗口,增强功能.  
//@参数 dwExStyle 窗口扩展样式.
//@参数 dwStyle 窗口样式
//@参数 lpClassName 窗口类名.
//@参数 x 窗口左上角x坐标.
//@参数 y 窗口左上角y坐标.
//@参数 cx 窗口宽度.
//@参数 cy 窗口高度.
//@参数 pTitle 窗口名.
//@参数 hWndParent 父窗口.
//@参数 XCStyle GUI库窗口样式,样式请参见宏定义 @ref window_style_.
//@返回 GUI库窗口资源句柄.
//@别名  创建扩展()
	HWINDOW CreateEx(DWORD dwExStyle, DWORD dwStyle, const wchar_t* lpClassName, int x, int y, int cx, int cy, const wchar_t* pTitle, HWND hWndParent, int XCStyle){m_hWindow = XFrameWnd_CreateEx(dwExStyle, dwStyle, lpClassName, x, y, cx, cy, pTitle, hWndParent, XCStyle);return m_hWindow;}
//@参数 hWnd 要附加的外部窗口句柄
//@参数 XCStyle GUI库窗口样式,样式请参见宏定义 @ref window_style_
//@返回 返回窗口句柄
//@别名  附加窗口()
	HWINDOW Attach(HWND hWnd, int XCStyle){m_hWindow = XFrameWnd_Attach(hWnd, XCStyle);return m_hWindow;}
//@备注 用来布局窗格的区域坐标,不包含码头.  
//@参数 pRect 返回坐标.
//@别名  取布局区域坐标()
	void GetLayoutAreaRect(RECT* pRect){XFrameWnd_GetLayoutAreaRect(m_hWindow, pRect);}
//@备注 设置主视图元素.  
//@参数 hEle 元素句柄.
//@别名  置视图()
	void SetView(HELE hEle){XFrameWnd_SetView(m_hWindow, hEle);}
//@备注 设置窗格分隔条颜色.  
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置窗格分隔条颜色()
	void SetPaneSplitBarColor(COLORREF color){XFrameWnd_SetPaneSplitBarColor(m_hWindow, color);}
//@备注 设置窗格组TabBar高度
//@参数 nHeight 高度
//@别名  置TabBar条高度()
	void SetTabBarHeight(int nHeight){XFrameWnd_SetTabBarHeight(m_hWindow, nHeight);}
//@返回 返回 拖动窗格 所处框架窗口单元格标识
//@别名  取拖动浮动窗格停留位置标识()
	frameWnd_cell_type_ GetDragFloatWndTopFlag(){return XFrameWnd_GetDragFloatWndTopFlag(m_hWindow);}
//@备注 保存布局信息到文件.  
//@参数 pFileName 文件名，如果文件名为空，将使用默认文件名frameWnd_layout.xml.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  保存布局到文件()
	BOOL SaveLayoutToFile(const wchar_t* pFileName){return XFrameWnd_SaveLayoutToFile(m_hWindow, pFileName);}
//@备注 加载布局信息文件.  
//@参数 aPaneList 窗格句柄数组.
//@参数 nPaneCount 窗格数量.
//@参数 pFileName 文件名，如果文件名为空，将使用默认文件名frameWnd_layout.xml.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  加载布局信息文件()
	BOOL LoadLayoutFile(HELE* aPaneList, int nEleCount, const wchar_t* pFileName){return XFrameWnd_LoadLayoutFile(m_hWindow, aPaneList, nEleCount, pFileName);}
//@备注 添加窗格到框架窗口.  
//@参数 hPaneDest 目标窗格.
//@参数 hPaneNew 当前窗格.
//@参数 align 对齐方式.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  添加窗格()
	BOOL AddPane(HELE hPaneDest, HELE hPaneNew, pane_align_ align){return XFrameWnd_AddPane(m_hWindow, hPaneDest, hPaneNew, align);}
//@备注 合并窗格.  
//@参数 hPaneDest 目标窗格.
//@参数 hPaneNew 当前窗格.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  合并窗格()
	BOOL MergePane(HELE hPaneDest, HELE hPaneNew){return XFrameWnd_MergePane(m_hWindow, hPaneDest, hPaneNew);}
};
//@备注  继承: CXBase
//@别名  弹出菜单类
class CXMenu: public CXBase
{
public:
	//@别名  句柄
	HMENUX m_hMenu;
	CXMenu(){}
//@备注 创建菜单.默认弹出菜单窗口关闭后自动销毁.  
//@返回 菜单句柄.
//@别名  创建()
	HMENUX Create(){m_hMenu = XMenu_Create();return m_hMenu;}
//@备注 添加菜单项.  
//@参数 nID 项ID.
//@参数 pText 文本内容.
//@参数 nParentID 父项ID.
//@参数 nFlags 标识参见宏定义 @ref menu_item_flag_.
//@别名  添加项()
	void AddItem(int nID, const wchar_t* pText, int parentId=XC_ID_ROOT, int nFlags=0){XMenu_AddItem(m_hMenu, nID, pText, parentId, nFlags);}
//@备注 添加菜单项.  
//@参数 nID 项ID.
//@参数 pText 文本内容.
//@参数 nParentID 父项ID.
//@参数 hIcon 菜单项图标句柄.
//@参数 nFlags 标识参见宏定义 @ref menu_item_flag_.
//@别名  添加项图标()
	void AddItemIcon(int nID, const wchar_t* pText, int nParentID, HIMAGE hImage, int nFlags=0){XMenu_AddItemIcon(m_hMenu, nID, pText, nParentID, hImage, nFlags);}
//@备注 插入菜单项.  
//@参数 nID 项ID.
//@参数 pText 文本内容.
//@参数 nFlags 标识参见宏定义 @ref menu_item_flag_.
//@参数 insertID 插入位置ID.
//@别名  插入项()
	void InsertItem(int nID, const wchar_t* pText, int nFlags, int insertID){XMenu_InsertItem(m_hMenu, nID, pText, nFlags, insertID);}
//@备注 插入菜单项.  
//@参数 nID 项ID.
//@参数 pText 文本内容.
//@参数 hIcon 菜单项图标句柄.
//@参数 nFlags 标识参见宏定义 @ref menu_item_flag_.
//@参数 insertID 插入位置ID.
//@别名  插入项图标()
	void InsertItemIcon(int nID, const wchar_t* pText, HIMAGE hIcon, int nFlags, int insertID){XMenu_InsertItemIcon(m_hMenu, nID, pText, hIcon, nFlags, insertID);}
//@备注 获取第一个子项.  
//@参数 nID 项ID.
//@返回 返回项ID.
//@别名  取第一个子项()
	int GetFirstChildItem(int nID){return XMenu_GetFirstChildItem(m_hMenu, nID);}
//@备注 获取末尾子项.  
//@参数 nID 项ID.
//@返回 返回项ID.
//@别名  取末尾子项()
	int GetEndChildItem(int nID){return XMenu_GetEndChildItem(m_hMenu, nID);}
//@备注 获取上一个兄弟项.  
//@参数 nID 项ID.
//@返回 返回项ID.
//@别名  取上一个兄弟项()
	int GetPrevSiblingItem(int nID){return XMenu_GetPrevSiblingItem(m_hMenu, nID);}
//@备注 获取下一个兄弟项.  
//@参数 nID 项ID.
//@返回 返回项ID.
//@别名  取下一个兄弟项()
	int GetNextSiblingItem(int nID){return XMenu_GetNextSiblingItem(m_hMenu, nID);}
//@备注 获取父项.  
//@参数 nID 项ID.
//@返回 返回项ID.
//@别名  取父项()
	int GetParentItem(int nID){return XMenu_GetParentItem(m_hMenu, nID);}
//@备注 设置是否自动销毁菜单.  
//@参数 bAuto 是否自动销毁.
//@别名  置自动销毁()
	void SetAutoDestroy(BOOL bAuto){XMenu_SetAutoDestroy(m_hMenu, bAuto);}
//@备注 是否有用户绘制菜单背景,如果启用XWM_MENU_DRAW_BACKGROUND和XE_MENU_DRAW_BACKGROUND事件有效.  
//@参数 bEnable 是否启用.
//@别名  启用用户绘制背景()
	void EnableDrawBackground(BOOL bEnable){XMenu_EnableDrawBackground(m_hMenu, bEnable);}
//@备注 是否有用户绘制菜单项,如果启用XWM_MENU_DRAWITEM和XE_MENU_DRAWITEM事件有效.  
//@参数 bEnable 是否启用.
//@别名  启用用户绘制项()
	void EnableDrawItem(BOOL bEnable){XMenu_EnableDrawItem(m_hMenu, bEnable);}
//@备注 弹出菜单.  
//@参数 hParentWnd 父窗口句柄.
//@参数 x x坐标.
//@参数 y y坐标.
//@参数 hParentEle 父元素句柄,如果该值不为NULL,hParentEle元素将接收菜单消息事件,
//@参数 nPosition 弹出位置,参见宏定义.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  弹出()
	BOOL Popup(HWND hParentWnd, int x, int y, HELE hParentEle=NULL, menu_popup_position_ nPosition=menu_popup_position_left_top){return XMenu_Popup(m_hMenu, hParentWnd, x, y, hParentEle, nPosition);}
//@备注 销毁菜单.  
//@别名  销毁()
	void DestroyMenu(){XMenu_DestroyMenu(m_hMenu);}
//@备注 关闭菜单.  
//@别名  关闭()
	void CloseMenu(){XMenu_CloseMenu(m_hMenu);}
//@备注 设置菜单背景图片.  
//@参数 hImage 图片句柄.
//@别名  置背景图片()
	void SetBkImage(HIMAGE hImage){XMenu_SetBkImage(m_hMenu, hImage);}
//@备注 设置项文本.  
//@参数 nID 项ID.
//@参数 pText 文本内容.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项文本()
	BOOL SetItemText(int nID, const wchar_t* pText){return XMenu_SetItemText(m_hMenu, nID, pText);}
//@备注 获取项文本.  
//@参数 nID 项ID.
//@返回 返回文本内容
//@别名  取项文本()
	const wchar_t* GetItemText(int nID){return XMenu_GetItemText(m_hMenu, nID);}
//@备注 获取项文本长度,不包含字符串空终止符.  
//@参数 nID 项ID.
//@返回 长度,字符为单位.
//@别名  取项文本长度()
	int GetItemTextLength(int nID){return XMenu_GetItemTextLength(m_hMenu, nID);}
//@备注 设置菜单项图标.  
//@参数 nID 项ID.
//@参数 hIcon 菜单项图标句柄.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项图标()
	BOOL SetItemIcon(int nID, HIMAGE hIcon){return XMenu_SetItemIcon(m_hMenu, nID, hIcon);}
//@备注 设置项标识.  
//@参数 nID 项ID.
//@参数 uFlags 标识参见宏定义 @ref menu_item_flag_.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项标志()
	BOOL SetItemFlags(int nID, int uFlags){return XMenu_SetItemFlags(m_hMenu, nID, uFlags);}
//@备注 设置项高度.  
//@参数 height 高度.
//@别名  置项高度()
	void SetItemHeight(int height){XMenu_SetItemHeight(m_hMenu, height);}
//@备注 获取项高度.  
//@返回 返回项高度.
//@别名  取项高度()
	int GetItemHeight(){return XMenu_GetItemHeight(m_hMenu);}
//@备注 此宽度为文本显示区域宽度, 不包含侧边条和与文本间隔
//@参数 nID 项ID
//@参数 nWidth 指定文本区域宽度
//@返回 如果成功返回TRUE,否则返回FALSE
//@别名  置项宽度()
	BOOL SetItemWidth(int nID, int nWidth){return XMenu_SetItemWidth(m_hMenu, nID, nWidth);}
//@备注 设置菜单边框颜色.  
//@参数 crColor 颜色值, 请使用宏: RGBA()
//@别名  置边框颜色()
	void SetBorderColor(COLORREF crColor){XMenu_SetBorderColor(m_hMenu, crColor);}
//@备注 设置弹出菜单窗口边框大小.  
//@参数 nLeft 边大小.
//@参数 nTop 边大小.
//@参数 nRight 边大小.
//@参数 nBottom 边大小.
//@别名  置边框大小()
	void SetBorderSize(int nLeft, int nTop, int nRight, int nBottom){XMenu_SetBorderSize(m_hMenu, nLeft, nTop, nRight, nBottom);}
//@备注 获取左侧区域宽度.  
//@返回 返回左侧区域宽度.
//@别名  取左侧宽度()
	int GetLeftWidth(){return XMenu_GetLeftWidth(m_hMenu);}
//@备注 获取菜单项文本左间隔.  
//@返回 返回菜单项文件左间隔大小.
//@别名  取左侧文本间隔()
	int GetLeftSpaceText(){return XMenu_GetLeftSpaceText(m_hMenu);}
//@备注 获取菜单项数量,包含子菜单项.  
//@返回 菜单项数量.
//@别名  取项数量()
	int GetItemCount(){return XMenu_GetItemCount(m_hMenu);}
//@备注 设置菜单项勾选状态.  
//@参数 nID 菜单项ID
//@参数 bCheck 勾选TRUE,非勾选FALSE
//@返回 如果勾选返回TRUE,否则返回FALSE.
//@别名  置项勾选()
	BOOL SetItemCheck(int nID, BOOL bCheck){return XMenu_SetItemCheck(m_hMenu, nID, bCheck);}
//@备注 判断菜单项是否勾选.  
//@参数 nID 菜单项ID
//@返回 如果勾选返回TRUE,否则返回FALSE.
//@别名  是否项勾选()
	BOOL IsItemCheck(int nID){return XMenu_IsItemCheck(m_hMenu, nID);}
};
//@备注  继承: CXWidgetUI, CXObjectUI, CXBase
//@别名  基础元素类
class CXEle: public CXWidgetUI
{
public:
	//@别名  句柄
	HELE m_hEle;
	CXEle(){}
//@备注 创建基础元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父为窗口句柄或元素句柄.
//@返回 元素句柄.
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XEle_Create(x, y, cx, cy, hParent);return m_hEle;}
//@备注 创建基础元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父为窗口句柄或元素句柄.
//@返回 元素句柄.
CXEle(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XEle_Create(x, y, cx, cy, hParent);}
//@备注 注册事件C方式,事件函数省略自身句柄.  
//@参数 nEvent 事件类型.
//@参数 pFun 事件函数指针.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  注册事件C()
	BOOL RegEventC(int nEvent, void* pFun){return XEle_RegEventC(m_hEle, nEvent, pFun);}
//@备注 注册事件C1方式,事件函数包含自身句柄.  
//@参数 nEvent 事件类型.
//@参数 pFun 事件函数指针.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  注册事件C1()
	BOOL RegEventC1(int nEvent, void* pFun){return XEle_RegEventC1(m_hEle, nEvent, pFun);}
//@备注 移除事件函数C方式.  
//@参数 nEvent 事件类型.
//@参数 pFun 事件函数指针.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  移除事件C()
	BOOL RemoveEventC(int nEvent, void* pFun){return XEle_RemoveEventC(m_hEle, nEvent, pFun);}
//@备注 发送事件.  
//@参数 nEvent 事件类型.
//@参数 wParam 参数.
//@参数 lParam 参数.
//@返回 事件返回值.
//@别名  发送事件()
	int SendEvent(int nEvent, WPARAM wParam, LPARAM lParam){return XEle_SendEvent(m_hEle, nEvent, wParam, lParam);}
//@备注 POST事件.  
//@参数 nEvent 事件类型.
//@参数 wParam 参数.
//@参数 lParam 参数.
//@返回 事件返回值.
//@别名  投递事件()
	BOOL PostEvent(int nEvent, WPARAM wParam, LPARAM lParam){return XEle_PostEvent(m_hEle, nEvent, wParam, lParam);}
//@备注 获取元素坐标.  
//@参数 pRect 坐标.
//@别名  取坐标()
	void GetRect(RECT* pRect){XEle_GetRect(m_hEle, pRect);}
//@备注 获取元素坐标,逻辑坐标,包含滚动视图偏移.  
//@参数 pRect 坐标.
//@别名  取逻辑坐标()
	void GetRectLogic(RECT* pRect){XEle_GetRectLogic(m_hEle, pRect);}
//@备注 获取元素客户区坐标. 
//@参数 pRect 坐标.
//@别名  取客户区坐标()
	void GetClientRect(RECT* pRect){XEle_GetClientRect(m_hEle, pRect);}
//@备注 设置宽度  
//@参数 nWidth 宽度
//@别名  置宽度()
	void SetWidth(int nWidth){XEle_SetWidth(m_hEle, nWidth);}
//@备注 设置高度   
//@参数 nHeight 高度
//@别名  置高度()
	void SetHeight(int nHeight){XEle_SetHeight(m_hEle, nHeight);}
//@备注 获取元素宽度.  
//@返回 宽度.
//@别名  取宽度()
	int GetWidth(){return XEle_GetWidth(m_hEle);}
//@备注 获取元素高度.  
//@返回 高度.
//@别名  取高度()
	int GetHeight(){return XEle_GetHeight(m_hEle);}
//@备注 窗口客户区坐标转换到元素客户区坐标.  
//@参数 pRect 坐标.
//@别名  窗口客户区坐标到元素客户区坐标()
	void RectWndClientToEleClient(RECT* pRect){XEle_RectWndClientToEleClient(m_hEle, pRect);}
//@备注 窗口客户区坐标转换到元素客户区坐标.  
//@参数 pPt 坐标.
//@别名  窗口客户区点到元素客户区()
	void PointWndClientToEleClient(POINT* pPt){XEle_PointWndClientToEleClient(m_hEle, pPt);}
//@备注 元素客户区坐标转换到窗口客户区坐标.  
//@参数 pRect 坐标.
//@别名  客户区坐标到窗口客户区()
	void RectClientToWndClient(RECT* pRect){XEle_RectClientToWndClient(m_hEle, pRect);}
//@备注 元素客户区坐标转换到窗口客户区坐标.  
//@参数 pPt 坐标.
//@别名  客户区点到窗口客户区()
	void PointClientToWndClient(POINT* pPt){XEle_PointClientToWndClient(m_hEle, pPt);}
//@备注 元素基于窗口客户区坐标.  
//@参数 pRect 坐标.
//@别名  基于窗口客户区坐标()
	void GetWndClientRect(RECT* pRect){XEle_GetWndClientRect(m_hEle, pRect);}
//@备注 获取元素鼠标光标.  
//@返回 返回光标句柄.
//@别名  取光标()
	HCURSOR GetCursor(){return XEle_GetCursor(m_hEle);}
//@备注 设置元素鼠标光标.  
//@参数 hCursor 光标句柄.
//@别名  置光标()
	void SetCursor(HCURSOR hCursor){XEle_SetCursor(m_hEle, hCursor);}
//@备注 添加子对象. 
//@参数 hChild 要添加的子元素句柄或形状对象句柄.
//@返回 如果成功返回TRUE,否则相反.
//@别名  添加子对象()
	BOOL AddChild(HXCGUI hChild){return XEle_AddChild(m_hEle, hChild);}
//@备注 插入子对象到指定位置.  
//@参数 hChild 要插入的元素句柄或形状对象句柄.
//@参数 index 插入位置索引.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  插入子对象()
	BOOL InsertChild(HXCGUI hChild, int index){return XEle_InsertChild(m_hEle, hChild, index);}
//@备注 设置元素坐标.  
//@参数 pRect 坐标.
//@参数 bRedraw 是否重绘.
//@参数 nFlags 调整布局标识位, @ref adjustLayout_
//@参数 nAdjustNo 调整布局流水号
//@返回 如果返回0坐标没有改变,如果大小改变返回2(触发XE_SIZE), 否则返回1(仅改变left,top,没有改变大小).
//@别名  置坐标()
	int SetRect(RECT* pRect, BOOL bRedraw=FALSE, int nFlags=adjustLayout_all, UINT nAdjustNo=0){return XEle_SetRect(m_hEle, pRect, bRedraw, nFlags, nAdjustNo);}
//@备注 设置元素坐标.  
//@参数 x X坐标.
//@参数 y Y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 bRedraw 是否重绘.
//@参数 nFlags 调整布局标识位, @ref adjustLayout_
//@参数 nAdjustNo 调整布局流水号
//@返回 如果坐标未改变返回0,如果大小改变返回2(触发XE_SIZE), 否则返回1.
//@别名  置坐标扩展()
	int SetRectEx(int x, int y, int cx, int cy, BOOL bRedraw=FALSE, int nFlags=adjustLayout_all, UINT nAdjustNo=0){return XEle_SetRectEx(m_hEle, x, y, cx, cy, bRedraw, nFlags, nAdjustNo);}
//@备注 设置元素坐标,逻辑坐标,包含滚动视图偏移.  
//@参数 pRect 坐标.
//@参数 bRedraw 是否重绘.
//@参数 nFlags 参数将被带入 XE_SIZE ,XE_ADJUSTLAYOUT 事件回调.@ref adjustLayout_
//@参数 nAdjustNo 调整布局流水号
//@返回 如果坐标未改变返回0,如果大小改变返回2(触发XE_SIZE), 否则返回1.
//@别名  置逻辑坐标()
	int SetRectLogic(RECT* pRect, BOOL bRedraw=FALSE, int nFlags=adjustLayout_all, UINT nAdjustNo=0){return XEle_SetRectLogic(m_hEle, pRect, bRedraw, nFlags, nAdjustNo);}
//@备注 移动元素坐标
//@参数 x X坐标.
//@参数 y Y坐标.
//@参数 bRedraw 是否重绘.
//@参数 nFlags 调整布局标识位, @ref adjustLayout_
//@参数 nAdjustNo 调整布局流水号
//@返回 如果坐标未改变返回0,如果大小改变返回2(触发XE_SIZE), 否则返回1.
//@别名  置位置()
	int SetPosition(int x, int y, BOOL bRedraw=FALSE, int nFlags=adjustLayout_all, UINT nAdjustNo=0){return XEle_SetPosition(m_hEle, x, y, bRedraw, nFlags, nAdjustNo);}
//@备注 移动元素坐标;  逻辑坐标,包含滚动视图偏移
//@参数 x X坐标.
//@参数 y Y坐标.
//@参数 bRedraw 是否重绘.
//@参数 nFlags 调整布局标识位, @ref adjustLayout_
//@参数 nAdjustNo 调整布局流水号
//@返回 如果坐标未改变返回0,如果大小改变返回2(触发XE_SIZE), 否则返回1.
//@别名  置位置逻辑()
	int SetPositionLogic(int x, int y, BOOL bRedraw=FALSE, int nFlags=adjustLayout_all, UINT nAdjustNo=0){return XEle_SetPositionLogic(m_hEle, x, y, bRedraw, nFlags, nAdjustNo);}
//@参数 pOutX 返回X坐标
//@参数 pOutY 返回Y坐标
//@别名  取位置()
	void GetPosition(int* pOutX, int* pOutY){XEle_GetPosition(m_hEle, pOutX, pOutY);}
//@参数 nWidth 宽度
//@参数 nHeight 高度
//@参数 bRedraw 是否重绘
//@参数 nFlags 调整布局标识位, @ref adjustLayout_
//@参数 nAdjustNo 调整布局流水号
//@别名  置大小()
	int SetSize(int nWidth, int nHeight, BOOL bRedraw=FALSE, int nFlags=adjustLayout_all, UINT nAdjustNo=0){return XEle_SetSize(m_hEle, nWidth, nHeight, bRedraw, nFlags, nAdjustNo);}
//@参数 pOutWidth 返回宽度
//@参数 pOutHeight 返回高度
//@别名  取大小()
	void GetSize(int* pOutWidth, int* pOutHeight){XEle_GetSize(m_hEle, pOutWidth, pOutHeight);}
//@备注 元素是否绘制焦点.  
//@返回 如果绘制焦点返回TRUE否则返回FALSE.
//@别名  是否绘制焦点()
	BOOL IsDrawFocus(){return XEle_IsDrawFocus(m_hEle);}
//@备注 元素是否为启用状态.  
//@返回 如果启用状态返回TRUE否则返回FALSE.
//@别名  是否启用()
	BOOL IsEnable(){return XEle_IsEnable(m_hEle);}
//@备注 元素是否启用焦点.  
//@返回 成功返回TRUE否则返回FALSE.
//@别名  是否启用焦点()
	BOOL IsEnableFocus(){return XEle_IsEnableFocus(m_hEle);}
//@备注 元素是否启用鼠标穿透.  
//@返回 成功返回TRUE否则返回FALSE.
//@别名  是否鼠标穿透()
	BOOL IsMouseThrough(){return XEle_IsMouseThrough(m_hEle);}
//@备注 检测坐标点所在元素,包含子元素的子元素.  
//@参数 pPt 坐标点.
//@返回 成功返回元素句柄,否则返回NULL.
//@别名  测试点击元素()
	HELE HitChildEle(POINT* pPt){return XEle_HitChildEle(m_hEle, pPt);}
//@备注 是否背景透明. 
//@返回 成功返回TRUE否则返回FALSE.
//@别名  是否背景透明()
	BOOL IsBkTransparent(){return XEle_IsBkTransparent(m_hEle);}
//@备注 是否启XE_PAINT_END用事件.  
//@返回 成功返回TRUE否则返回FALSE.
//@别名  是否启用事件_XE_PAINT_END()
	BOOL IsEnableEvent_XE_PAINT_END(){return XEle_IsEnableEvent_XE_PAINT_END(m_hEle);}
//@备注 是否接受Tab键输入; 例如: XRichEdit, XEdit  
//@返回 是返回TRUE否则返回FALSE
//@别名  是否接受TAB()
	BOOL IsKeyTab(){return XEle_IsKeyTab(m_hEle);}
//@备注 是否接受通过键盘切换焦点(方向键,TAB键).  
//@返回 是返回TRUE否则返回FALSE.
//@别名  是否接受切换焦点()
	BOOL IsSwitchFocus(){return XEle_IsSwitchFocus(m_hEle);}
//@备注 判断是否启用鼠标滚动事件,如果禁用那么事件会发送给他的父元素.  
//@返回 是返回TRUE否则返回FALSE.
//@别名  是否启用_XE_MOUSEWHEEL()
	BOOL IsEnable_XE_MOUSEWHEEL(){return XEle_IsEnable_XE_MOUSEWHEEL(m_hEle);}
//@备注 判断hChildEle是否为hEle的子元素,   
//@参数 hChildEle 子元素句柄
//@返回 是返回TRUE否则返回FALSE.
//@别名  是否为子元素()
	BOOL IsChildEle(HELE hChildEle){return XEle_IsChildEle(m_hEle, hChildEle);}
//@备注 判断是否启用画布,  
//@返回 是返回TRUE否则返回FALSE.
//@别名  是否启用画布()
	BOOL IsEnableCanvas(){return XEle_IsEnableCanvas(m_hEle);}
//@备注 判断是否拥有焦点.  
//@返回 如果拥有焦点返回TRUE,否则返回FALSE.
//@别名  是否焦点()
	BOOL IsFocus(){return XEle_IsFocus(m_hEle);}
//@备注 判断该元素或该元素的子元素是否拥有焦点  
//@返回 如果拥有焦点返回TRUE,否则返回FALSE.
//@别名  是否焦点扩展()
	BOOL IsFocusEx(){return XEle_IsFocusEx(m_hEle);}
//@备注 启用或禁用元素.  
//@参数 bEnable 启用或禁用.
//@别名  启用()
	void Enable(BOOL bEnable){XEle_Enable(m_hEle, bEnable);}
//@备注 启用焦点.  
//@参数 bEnable 是否启用.
//@别名  启用焦点()
	void EnableFocus(BOOL bEnable){XEle_EnableFocus(m_hEle, bEnable);}
//@备注 启用绘制焦点.  
//@参数 bEnable 是否启用.
//@别名  启用绘制焦点()
	void EnableDrawFocus(BOOL bEnable){XEle_EnableDrawFocus(m_hEle, bEnable);}
//@备注 启用或禁用绘制默认边框.  
//@参数 bEnable 是否启用.
//@别名  启用绘制边框()
	void EnableDrawBorder(BOOL bEnable){XEle_EnableDrawBorder(m_hEle, bEnable);}
//@备注 启用或禁用背景画布;如果禁用那么将绘制在父的画布之上,也就是说他没有自己的画布.  
//@参数 bEnable 是否启用.
//@别名  启用画布()
	void EnableCanvas(BOOL bEnable){XEle_EnableCanvas(m_hEle, bEnable);}
//@备注 启用XE_PAINT_END事件.  
//@参数 bEnable 是否启用.
//@别名  启用事件_XE_PAINT_END()
	void EnableEvent_XE_PAINT_END(BOOL bEnable){XEle_EnableEvent_XE_PAINT_END(m_hEle, bEnable);}
//@备注 启用背景透明.  
//@参数 bEnable 是否启用.
//@别名  启用背景透明()
	void EnableBkTransparent(BOOL bEnable){XEle_EnableBkTransparent(m_hEle, bEnable);}
//@备注 启用鼠标穿透, 如果启用,那么该元素不能接收到鼠标事件,但是他的子元素不受影响,任然可以接收鼠标事件.  
//@参数 bEnable 是否启用.
//@别名  启用鼠标穿透()
	void EnableMouseThrough(BOOL bEnable){XEle_EnableMouseThrough(m_hEle, bEnable);}
//@备注 启用接收Tab输入.  
//@参数 bEnable 是否启用.
//@别名  启用接收TAB()
	void EnableKeyTab(BOOL bEnable){XEle_EnableKeyTab(m_hEle, bEnable);}
//@备注 启用接受通过键盘切换焦点.  
//@参数 bEnable 是否启用.
//@别名  启用切换焦点()
	void EnableSwitchFocus(BOOL bEnable){XEle_EnableSwitchFocus(m_hEle, bEnable);}
//@备注 启用接收鼠标滚动事件,如果禁用那么事件会传递给父元素.  
//@参数 bEnable 是否启用.
//@别名  启用事件_XE_MOUSEWHEEL()
	void EnableEvent_XE_MOUSEWHEEL(BOOL bEnable){XEle_EnableEvent_XE_MOUSEWHEEL(m_hEle, bEnable);}
//@备注 移除元素,但不销毁.  
//@别名  移除()
	void Remove(){XEle_Remove(m_hEle);}
//@备注 设置元素Z序.  
//@参数 index 位置索引.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置Z序()
	BOOL SetZOrder(int index){return XEle_SetZOrder(m_hEle, index);}
//@备注 设置元素Z序.  
//@参数 hDestEle 目标元素.
//@参数 nType 类型.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置Z序扩展()
	BOOL SetZOrderEx(HELE hDestEle, zorder_ nType){return XEle_SetZOrderEx(m_hEle, hDestEle, nType);}
//@备注 获取元素Z序索引, 位置索引.  
//@返回 成功返回索引值,否则返回 XC_ID_ERROR.
//@别名  取Z序()
	int GetZOrder(){return XEle_GetZOrder(m_hEle);}
//@备注 设置元素置顶.  
//@参数 bTopmost 是否置顶显示
//@返回 成功返回TRUE否则返回FALSE.
//@别名  启用置顶()
	BOOL EnableTopmost(BOOL bTopmost){return XEle_EnableTopmost(m_hEle, bTopmost);}
//@备注 重绘元素.  
//@参数 bImmediate 是否立即重绘,默认为否.
//@别名  重绘()
	void Redraw(BOOL bImmediate=FALSE){XEle_Redraw(m_hEle, bImmediate);}
//@备注 重绘元素指定区域.  
//@参数 pRect 相对于元素客户区坐标.
//@参数 bImmediate 是否立即重绘,默认为否.
//@别名  重绘指定区域()
	void RedrawRect(RECT* pRect, BOOL bImmediate=FALSE){XEle_RedrawRect(m_hEle, pRect, bImmediate);}
//@备注 获取子对象(UI元素和形状对象)数量,只检测当前层子对象.  
//@返回 子元素数量.
//@别名  取子对象数量()
	int GetChildCount(){return XEle_GetChildCount(m_hEle);}
//@备注 获取子对象通过索引,只检测当前层子对象.  
//@参数 index 索引.
//@返回 对象句柄.
//@别名  取子对象从索引()
	HXCGUI GetChildByIndex(int index){return XEle_GetChildByIndex(m_hEle, index);}
//@备注 获取子对象通过ID,只检测当前层子对象.  
//@参数 nID 元素ID.
//@返回 对象句柄.
//@别名  取子对象从ID()
	HXCGUI GetChildByID(int nID){return XEle_GetChildByID(m_hEle, nID);}
//@备注 设置边框大小.  
//@参数 left 左边大小.
//@参数 top 上边大小.
//@参数 right 右边大小.
//@参数 bottom 下边大小.
//@别名  置边框大小()
	void SetBorderSize(int left, int top, int right, int bottom){XEle_SetBorderSize(m_hEle, left, top, right, bottom);}
//@备注 获取边框大小.  
//@参数 pBorder 大小.
//@别名  取边框大小()
	void GetBorderSize(borderSize_* pBorder){XEle_GetBorderSize(m_hEle, pBorder);}
//@备注 设置被填充大小.  
//@参数 left 左边大小.
//@参数 top 上边大小.
//@参数 right 右边大小.
//@参数 bottom 下边大小.
//@别名  置内填充大小()
	void SetPadding(int left, int top, int right, int bottom){XEle_SetPadding(m_hEle, left, top, right, bottom);}
//@备注 获取内填充大小.  
//@参数 pPadding 大小.
//@别名  取内填充大小()
	void GetPadding(paddingSize_* pPadding){XEle_GetPadding(m_hEle, pPadding);}
//@备注 设置拖动边框.  
//@参数 nFlags 边框位置组合. element_position_
//@别名  置拖动边框()
	void SetDragBorder(int nFlags){XEle_SetDragBorder(m_hEle, nFlags);}
//@备注 设置拖动边框绑定元素,当拖动边框时, 自动调整绑定元素的大小.  
//@参数 nFlags 边框位置标识,不可组合.  element_position_
//@参数 hBindEle 绑定元素.
//@参数 nSpace 元素间隔大小
//@别名  置拖动边框绑定元素()
	void SetDragBorderBindEle(int nFlags, HELE hBindEle, int nSpace){XEle_SetDragBorderBindEle(m_hEle, nFlags, hBindEle, nSpace);}
//@备注 设置元素最小大小  
//@参数 nWidth 最小宽度
//@参数 nHeight 最小高度.
//@别名  置最小大小()
	void SetMinSize(int nWidth, int nHeight){XEle_SetMinSize(m_hEle, nWidth, nHeight);}
//@备注 设置元素最大大小.  
//@参数 nWidth 最大宽度.
//@参数 nHeight 最大高度.
//@别名  置最大大小()
	void SetMaxSize(int nWidth, int nHeight){XEle_SetMaxSize(m_hEle, nWidth, nHeight);}
//@备注 设置锁定元素在滚动视图中跟随滚动,如果设置TRUE将不跟随滚动.  
//@参数 bHorizon 是否锁定水平滚动.
//@参数 bVertical 是否锁定垂直滚动.
//@别名  置锁定滚动()
	void SetLockScroll(BOOL bHorizon, BOOL bVertical){XEle_SetLockScroll(m_hEle, bHorizon, bVertical);}
//@备注 设置文本颜色.  
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置文本颜色()
	void SetTextColor(COLORREF color){XEle_SetTextColor(m_hEle, color);}
//@备注 获取文本颜色.  
//@返回 文本颜色值.
//@别名  取文本颜色()
	COLORREF GetTextColor(){return XEle_GetTextColor(m_hEle);}
//@备注 获取文本颜色,优先从资源中获取.  
//@返回 文本颜色值.
//@别名  取文本颜色扩展()
	COLORREF GetTextColorEx(){return XEle_GetTextColorEx(m_hEle);}
//@备注 设置焦点边框颜色.  
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置焦点边框颜色()
	void SetFocusBorderColor(COLORREF color){XEle_SetFocusBorderColor(m_hEle, color);}
//@备注 获取焦点边框颜色.  
//@返回 返回颜色值
//@别名  取焦点边框颜色()
	COLORREF GetFocusBorderColor(){return XEle_GetFocusBorderColor(m_hEle);}
//@备注 设置元素字体.  
//@参数 hFontx 炫彩字体.
//@别名  置字体()
	void SetFont(HFONTX hFontx){XEle_SetFont(m_hEle, hFontx);}
//@备注 获取元素字体.  
//@返回 返回炫彩字体句柄.
//@别名  取字体()
	HFONTX GetFont(){return XEle_GetFont(m_hEle);}
//@备注 获取元素字体,优先从资源中获取.  
//@返回 返回炫彩字体句柄.
//@别名  取字体扩展()
	HFONTX GetFontEx(){return XEle_GetFontEx(m_hEle);}
//@备注 设置元素透明度.  
//@参数 alpha 透明度.
//@别名  置透明度()
	void SetAlpha(BYTE alpha){XEle_SetAlpha(m_hEle, alpha);}
//@返回 返回透明度
//@别名  取透明度()
	BYTE GetAlpha(){return XEle_GetAlpha(m_hEle);}
//@备注 销毁元素.  
//@别名  销毁()
	void Destroy(){XEle_Destroy(m_hEle);}
//@备注 添加背景内容边框.  
//@参数 nState 组合状态
//@参数 color 颜色.
//@参数 width 线宽.
//@别名  添加背景边框()
	void AddBkBorder(int nState, COLORREF color, int width){XEle_AddBkBorder(m_hEle, nState, color, width);}
//@备注 添加背景内容填充.  
//@参数 nState 组合状态
//@参数 color 颜色.
//@别名  添加背景填充()
	void AddBkFill(int nState, COLORREF color){XEle_AddBkFill(m_hEle, nState, color);}
//@备注 添加背景内容图片.  
//@参数 nState 组合状态
//@参数 hImage 图片句柄.
//@别名  添加背景图片()
	void AddBkImage(int nState, HIMAGE hImage){XEle_AddBkImage(m_hEle, nState, hImage);}
//@备注 设置背景内容
//@参数 pText 背景内容字符串
//@返回 返回设置的背景对象数量
//@别名  置背景()
	int SetBkInfo(const wchar_t* pText){return XEle_SetBkInfo(m_hEle, pText);}
//@备注 获取背景内容数量.  
//@返回 返回背景内容数量.
//@别名  取背景对象数量()
	int GetBkInfoCount(){return XEle_GetBkInfoCount(m_hEle);}
//@备注 清空背景内容; 如果背景没有内容,将使用系统默认内容,以便保证背景正确.  
//@别名  清空背景对象()
	void ClearBkInfo(){XEle_ClearBkInfo(m_hEle);}
//@备注 获取元素背景管理器.  
//@返回 背景管理器.
//@别名  取背景管理器()
	HBKM GetBkManager(){return XEle_GetBkManager(m_hEle);}
//@备注 获取元素背景管理器,优先从资源中获取.  
//@返回 背景管理器.
//@别名  取背景管理器扩展()
	HBKM GetBkManagerEx(){return XEle_GetBkManagerEx(m_hEle);}
//@参数 hBkInfoM 背景管理器
//@别名  置背景管理器()
	void SetBkManager(HBKM hBkInfoM){XEle_SetBkManager(m_hEle, hBkInfoM);}
//@备注 获取组合状态.  
//@返回 返回组合状态.
//@别名  取状态()
	int GetStateFlags(){return XEle_GetStateFlags(m_hEle);}
//@备注 绘制元素焦点.  
//@参数 hDraw 图形绘制句柄.
//@参数 pRect 区域坐标.
//@返回 绘制成功返回TRUE,如果不需要绘制焦点返回FALSE.
//@别名  绘制焦点()
	BOOL DrawFocus(HDRAW hDraw, RECT* pRect){return XEle_DrawFocus(m_hEle, hDraw, pRect);}
//@备注 在自绘事件函数中,用户手动调用绘制元素,以便控制绘制顺序.  
//@参数 hDraw 图形绘制句柄.
//@别名  绘制()
	void DrawEle(HDRAW hDraw){XEle_DrawEle(m_hEle, hDraw);}
//@备注 设置用户数据.  
//@参数 nData 用户数据.
//@别名  置用户数据()
	void SetUserData(vint nData){XEle_SetUserData(m_hEle, nData);}
//@备注 获取用户数据.  
//@返回 用户数据.
//@别名  取用户数据()
	vint GetUserData(){return XEle_GetUserData(m_hEle);}
//@备注 获取内容大小.  
//@参数 bHorizon 水平或垂直,  布局属性交换依赖
//@参数 cx 宽度
//@参数 cy 高度
//@参数 pSize 返回大小.
//@别名  取内容大小()
	void GetContentSize(BOOL bHorizon, int cx, int cy, SIZE* pSize){XEle_GetContentSize(m_hEle, bHorizon, cx, cy, pSize);}
//@备注 设置鼠标捕获.  
//@参数 b TRUE设置,FALSE取消.
//@别名  置鼠标捕获()
	void SetCapture(BOOL b){XEle_SetCapture(m_hEle, b);}
//@备注 启用或关闭元素透明通道,如果启用,将强制设置元素背景不透明,默认为启用,此功能是为了兼容GDI不支持透明通道问题.  
//@参数 bEnable 启用或关闭.
//@别名  启用透明通道()
	void EnableTransparentChannel(BOOL bEnable){XEle_EnableTransparentChannel(m_hEle, bEnable);}
//@备注 设置元素定时器.  
//@参数 nIDEvent 事件ID.
//@参数 uElapse 延时毫秒.
//@返回 如果成功返回TRUE,否则返回FALSE.
//@别名  置炫彩定时器()
	BOOL SetXCTimer(UINT nIDEvent, UINT uElapse){return XEle_SetXCTimer(m_hEle, nIDEvent, uElapse);}
//@备注 关闭元素定时器.  
//@参数 nIDEvent 事件ID.
//@返回 如果成功返回TRUE,否则返回FALSE.
//@别名  关闭炫彩定时器()
	BOOL KillXCTimer(UINT nIDEvent){return XEle_KillXCTimer(m_hEle, nIDEvent);}
//@备注 设置工具提示内容.  
//@参数 pText 工具提示内容.
//@别名  置工具提示()
	void SetToolTip(const wchar_t* pText){XEle_SetToolTip(m_hEle, pText);}
//@备注 设置工具提示内容.  
//@参数 pText 工具提示内容.
//@参数 nTextAlign 文本对齐方式 @ref textFormatFlag_
//@别名  置工具提示扩展()
	void SetToolTipEx(const wchar_t* pText, int nTextAlign){XEle_SetToolTipEx(m_hEle, pText, nTextAlign);}
//@备注 获取工具提示内容.  
//@返回 返回文本内容
//@别名  取工具提示()
	const wchar_t* GetToolTip(){return XEle_GetToolTip(m_hEle);}
//@备注 弹出工具提示.  
//@参数 x X坐标.
//@参数 y Y坐标.
//@别名  弹出工具提示()
	void PopupToolTip(int x, int y){XEle_PopupToolTip(m_hEle, x, y);}
//@备注 调整布局.  
//@参数 nAdjustNo 调整布局流水号
//@别名  调整布局()
	void AdjustLayout(UINT nAdjustNo=0){XEle_AdjustLayout(m_hEle, nAdjustNo);}
//@备注 调整布局.    
//@参数 nFlags 调整标识,  adjustLayout_
//@参数 nAdjustNo 调整布局流水号
//@别名  调整布局扩展()
	void AdjustLayoutEx(int nFlags=adjustLayout_self, UINT nAdjustNo=0){XEle_AdjustLayoutEx(m_hEle, nFlags, nAdjustNo);}
};
//@备注  继承: CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  按钮类
class CXButton: public CXEle
{
public:
	CXButton(){}
//@备注 创建按钮元素  
//@参数 x 按钮x坐标
//@参数 y 按钮y坐标
//@参数 cx 宽度
//@参数 cy 高度
//@参数 pName 标题
//@参数 hParent 父为窗口句柄或元素句柄.
//@返回 按钮元素句柄.
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, const wchar_t* pName, HXCGUI hParent=NULL){m_hEle = XBtn_Create(x, y, cx, cy, pName, hParent);return m_hEle;}
//@备注 创建按钮元素  
//@参数 x 按钮x坐标
//@参数 y 按钮y坐标
//@参数 cx 宽度
//@参数 cy 高度
//@参数 pName 标题
//@参数 hParent 父为窗口句柄或元素句柄.
//@返回 按钮元素句柄.
CXButton(int x, int y, int cx, int cy, const wchar_t* pName, HXCGUI hParent=NULL){m_hEle = XBtn_Create(x, y, cx, cy, pName, hParent);}
//@备注 是否选中状态.  
//@返回 成功返回TRUE否则返回FALSE.
//@别名  是否选中()
	BOOL IsCheck(){return XBtn_IsCheck(m_hEle);}
//@备注 设置选中状态.  
//@参数 bCheck 是否选中.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置选中()
	BOOL SetCheck(BOOL bCheck){return XBtn_SetCheck(m_hEle, bCheck);}
//@备注 设置按钮状态.  
//@参数 nState 按钮状态见宏定义.
//@别名  置状态()
	void SetState(common_state3_ nState){XBtn_SetState(m_hEle, nState);}
//@备注 获取按钮状态
//@返回 返回按钮状态.
//@别名  取三态()
	common_state3_ GetState(){return XBtn_GetState(m_hEle);}
//@备注 获取按钮状态
//@返回 返回按钮状态.
//@别名  取按钮状态()
	button_state_ GetStateEx(){return XBtn_GetStateEx(m_hEle);}
//@备注 设置按钮类型并自动修改样式和文本对齐方式.  
//@参数 nType 按钮类型,参见宏定义.
//@别名  置类型扩展()
	void SetTypeEx(XC_OBJECT_TYPE_EX nType){XBtn_SetTypeEx(m_hEle, nType);}
//@备注 设置组ID.  
//@参数 nID 组ID.
//@别名  置组ID()
	void SetGroupID(int nID){XBtn_SetGroupID(m_hEle, nID);}
//@备注 获取组ID.  
//@返回 组ID.
//@别名  取组ID()
	int GetGroupID(){return XBtn_GetGroupID(m_hEle);}
//@备注 设置绑定元素.  
//@参数 hBindEle 将要绑定的元素.
//@别名  置绑定元素()
	void SetBindEle(HELE hBindEle){XBtn_SetBindEle(m_hEle, hBindEle);}
//@备注 获取绑定的元素.  
//@返回 绑定的元素句柄.
//@别名  取绑定元素()
	HELE GetBindEle(){return XBtn_GetBindEle(m_hEle);}
//@备注 设置文本对齐方式.  
//@参数 nFlags 对齐方式  @ref textFormatFlag_ .
//@别名  置文本对齐()
	void SetTextAlign(int nFlags){XBtn_SetTextAlign(m_hEle, nFlags);}
//@备注 获取文本对齐方式.  
//@返回 文本对齐方式 @ref textFormatFlag_ .
//@别名  取文本对齐()
	int GetTextAlign(){return XBtn_GetTextAlign(m_hEle);}
//@备注 设置图标对齐.  
//@参数 align 对齐方式.
//@别名  置图标对齐()
	void SetIconAlign(button_icon_align_ align){XBtn_SetIconAlign(m_hEle, align);}
//@备注 设置按钮文本坐标偏移量.  
//@参数 x 偏移量.
//@参数 y 偏移量.
//@别名  置偏移()
	void SetOffset(int x, int y){XBtn_SetOffset(m_hEle, x, y);}
//@备注 设置按钮图标坐标偏移量.  
//@参数 x 偏移量.
//@参数 y 偏移量.
//@别名  置图标偏移()
	void SetOffsetIcon(int x, int y){XBtn_SetOffsetIcon(m_hEle, x, y);}
//@备注 设置图标与文本间隔大小.  
//@参数 size 间隔大小.
//@别名  置图标间隔()
	void SetIconSpace(int size){XBtn_SetIconSpace(m_hEle, size);}
//@备注 设置文本内容.  
//@参数 pName 文本内容.
//@别名  置文本()
	void SetText(const wchar_t* pName){XBtn_SetText(m_hEle, pName);}
//@备注 获取文本内容.  
//@返回 返回文本
//@别名  取文本()
	const wchar_t* GetText(){return XBtn_GetText(m_hEle);}
//@备注 设置图标.  
//@参数 hImage 图片句柄.
//@别名  置图标()
	void SetIcon(HIMAGE hImage){XBtn_SetIcon(m_hEle, hImage);}
//@备注 设置图标禁用状态.  
//@参数 hImage 图片句柄.
//@别名  置禁用图标()
	void SetIconDisable(HIMAGE hImage){XBtn_SetIconDisable(m_hEle, hImage);}
//@备注 获取用户设置的图标.  
//@参数 nType 图标类型, 0:默认图标,1:禁用状态图标.
//@返回 返回图标句柄.
//@别名  取图标()
	HIMAGE GetIcon(int nType){return XBtn_GetIcon(m_hEle, nType);}
//@备注 添加动画帧.  
//@参数 hImage 图片句柄
//@参数 uElapse 图片帧延时,单位毫秒.
//@别名  添加动画帧()
	void AddAnimationFrame(HIMAGE hImage, UINT uElapse){XBtn_AddAnimationFrame(m_hEle, hImage, uElapse);}
//@备注 开始或关闭图片动画的播放.  
//@参数 bEnable 开始播放动画TRUE,关闭播放动画FALSE.
//@参数 bLoopPlay 是否循环播放.
//@别名  启用动画()
	void EnableAnimation(BOOL bEnable, BOOL bLoopPlay=FALSE){XBtn_EnableAnimation(m_hEle, bEnable, bLoopPlay);}
};
//@备注  继承: CXButton, CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  文本链接类
class CXTextLink: public CXButton
{
public:
	CXTextLink(){}
//@备注 创建静态文本连接元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 pName 文本内容.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, const wchar_t* pName, HXCGUI hParent=NULL){m_hEle = XTextLink_Create(x, y, cx, cy, pName, hParent);return m_hEle;}
//@备注 创建静态文本连接元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 pName 文本内容.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
CXTextLink(int x, int y, int cx, int cy, const wchar_t* pName, HXCGUI hParent=NULL){m_hEle = XTextLink_Create(x, y, cx, cy, pName, hParent);}
//@备注 启用下划线,鼠标离开状态.  
//@参数 bEnable 是否启用.
//@别名  启用离开状态下划线()
	void EnableUnderlineLeave(BOOL bEnable){XTextLink_EnableUnderlineLeave(m_hEle, bEnable);}
//@备注 启用下划线,鼠标停留状态.  
//@参数 bEnable 是否启用.
//@别名  停留状态下划线()
	void EnableUnderlineStay(BOOL bEnable){XTextLink_EnableUnderlineStay(m_hEle, bEnable);}
//@备注 设置文本颜色,鼠标停留状态.  
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置停留状态文本颜色()
	void SetTextColorStay(COLORREF color){XTextLink_SetTextColorStay(m_hEle, color);}
//@备注 设置下划线颜色,鼠标离开状态.  
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置离开状态下划线颜色()
	void SetUnderlineColorLeave(COLORREF color){XTextLink_SetUnderlineColorLeave(m_hEle, color);}
//@备注 设置下划线颜色,鼠标停留状态.  
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置停留状态下划线颜色()
	void SetUnderlineColorStay(COLORREF color){XTextLink_SetUnderlineColorStay(m_hEle, color);}
};
//@备注  继承: CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  布局类
class CXLayout: public CXEle
{
public:
	CXLayout(){}
//@备注 创建布局元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父为窗口句柄或元素句柄.
//@返回 元素句柄.
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, HXCGUI hParent){m_hEle = XLayout_Create(x, y, cx, cy, hParent);return m_hEle;}
//@备注 创建布局元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父为窗口句柄或元素句柄.
//@返回 元素句柄.
CXLayout(int x, int y, int cx, int cy, HXCGUI hParent){m_hEle = XLayout_Create(x, y, cx, cy, hParent);}
//@备注 创建布局元素.  
//@参数 hParent 父为窗口句柄或元素句柄.
//@返回 元素句柄.
//@别名  创建扩展()
	HELE CreateEx(HXCGUI hParent){m_hEle = XLayout_CreateEx(hParent);return m_hEle;}
//@备注 启用布局功能.  
//@参数 bEnable 是否启用.
//@别名  启用()
	void EnableLayout(BOOL bEnable){XLayout_EnableLayout(m_hEle, bEnable);}
//@备注 是否已经启用布局功能  
//@返回 如果启用布局返回TRUE,否则返回FALSE
//@别名  是否启用()
	BOOL IsEnableLayout(){return XLayout_IsEnableLayout(m_hEle);}
//@备注 显示布局边界.  
//@参数 bEnable 是否显示
//@别名  显示布局边界()
	void ShowLayoutFrame(BOOL bEnable){XLayout_ShowLayoutFrame(m_hEle, bEnable);}
//@备注 获取宽度,不包含内边距大小  
//@返回 返回宽度
//@别名  取内宽度()
	int GetWidthIn(){return XLayout_GetWidthIn(m_hEle);}
//@备注 获取高度,不包含内边距大小  
//@返回 返回高度
//@别名  取内高度()
	int GetHeightIn(){return XLayout_GetHeightIn(m_hEle);}
};
//@备注  继承: CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  滚动视图类
class CXScrollView: public CXEle
{
public:
	CXScrollView(){}
//@备注 创建滚动视图元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XSView_Create(x, y, cx, cy, hParent);return m_hEle;}
//@备注 创建滚动视图元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
CXScrollView(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XSView_Create(x, y, cx, cy, hParent);}
//@备注 设置内容大小.  
//@参数 cx 宽度.
//@参数 cy 高度.
//@返回 如果内容改变返回TRUE否则返回FALSE.
//@别名  置视图大小()
	BOOL SetTotalSize(int cx, int cy){return XSView_SetTotalSize(m_hEle, cx, cy);}
//@备注 获取内容总大小.  
//@参数 pSize 大小.
//@别名  取视图大小()
	void GetTotalSize(SIZE* pSize){XSView_GetTotalSize(m_hEle, pSize);}
//@备注 设置滚动单位大小.  
//@参数 nWidth 宽度.
//@参数 nHeight 高度.
//@返回 如果内容改变返回TRUE否则返回FALSE.
//@别名  置滚动单位大小()
	BOOL SetLineSize(int nWidth, int nHeight){return XSView_SetLineSize(m_hEle, nWidth, nHeight);}
//@备注 获取滚动单位大小.  
//@参数 pSize 返回大小.
//@别名  取滚动单位大小()
	void GetLineSize(SIZE* pSize){XSView_GetLineSize(m_hEle, pSize);}
//@备注 设置滚动条大小.  
//@参数 size 滚动条大小.
//@别名  置滚动条大小()
	void SetScrollBarSize(int size){XSView_SetScrollBarSize(m_hEle, size);}
//@备注 获取视口原点X坐标.  
//@返回 视口原点X坐标.
//@别名  取视口原点X()
	int GetViewPosH(){return XSView_GetViewPosH(m_hEle);}
//@备注 获取视口原点Y坐标.  
//@返回 视口原点Y坐标.
//@别名  取视口原点Y()
	int GetViewPosV(){return XSView_GetViewPosV(m_hEle);}
//@备注 获取视口宽度.  
//@返回 返回视口宽度.
//@别名  取视口宽度()
	int GetViewWidth(){return XSView_GetViewWidth(m_hEle);}
//@备注 获取视口高度.  
//@返回 返回视口高度.
//@别名  取视口高度()
	int GetViewHeight(){return XSView_GetViewHeight(m_hEle);}
//@备注 获取视口坐标.  
//@参数 pRect 坐标.
//@别名  取视口坐标()
	void GetViewRect(RECT* pRect){XSView_GetViewRect(m_hEle, pRect);}
//@备注 获取水平滚动条.  
//@返回 滚动条句柄.
//@别名  取水平滚动条()
	HELE GetScrollBarH(){return XSView_GetScrollBarH(m_hEle);}
//@备注 获取垂直滚动条.  
//@返回 垂直滚动条句柄.
//@别名  取垂直滚动条()
	HELE GetScrollBarV(){return XSView_GetScrollBarV(m_hEle);}
//@备注 水平滚动条,滚动到指定位置点.  
//@参数 pos 位置点.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  水平滚动()
	BOOL ScrollPosH(int pos){return XSView_ScrollPosH(m_hEle, pos);}
//@备注 垂直滚动条,滚动到指定位置点.  
//@参数 pos 位置点.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  垂直滚动()
	BOOL ScrollPosV(int pos){return XSView_ScrollPosV(m_hEle, pos);}
//@备注 水平滚动条,滚动到指定坐标.  
//@参数 posX X坐标.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  水平滚动到X()
	BOOL ScrollPosXH(int posX){return XSView_ScrollPosXH(m_hEle, posX);}
//@备注 垂直滚动条,滚动到指定坐标.  
//@参数 posY Y坐标.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  垂直滚动到Y()
	BOOL ScrollPosYV(int posY){return XSView_ScrollPosYV(m_hEle, posY);}
//@备注 显示水平滚动条.  
//@参数 bShow 是否显示.
//@别名  显示水平滚动条()
	void ShowSBarH(BOOL bShow){XSView_ShowSBarH(m_hEle, bShow);}
//@备注 显示垂直滚动条.  
//@参数 bShow 是否显示.
//@别名  显示垂直滚动条()
	void ShowSBarV(BOOL bShow){XSView_ShowSBarV(m_hEle, bShow);}
//@备注 启用自动显示滚动条.  
//@参数 bEnable 是否启用.
//@别名  启用自动显示滚动条()
	void EnableAutoShowScrollBar(BOOL bEnable){XSView_EnableAutoShowScrollBar(m_hEle, bEnable);}
//@备注 向左滚动.  
//@返回 如果成功返回TRUE,否则相反.
//@别名  向左滚动()
	BOOL ScrollLeftLine(){return XSView_ScrollLeftLine(m_hEle);}
//@备注 向右滚动.  
//@返回 如果成功返回TRUE,否则相反.
//@别名  向右滚动()
	BOOL ScrollRightLine(){return XSView_ScrollRightLine(m_hEle);}
//@备注 向上滚动.  
//@返回 如果成功返回TRUE,否则相反.
//@别名  向上滚动()
	BOOL ScrollTopLine(){return XSView_ScrollTopLine(m_hEle);}
//@备注 向下滚动.  
//@返回 如果成功返回TRUE,否则相反.
//@别名  向下滚动()
	BOOL ScrollBottomLine(){return XSView_ScrollBottomLine(m_hEle);}
//@备注 水平滚动到左侧.  
//@返回 如果成功返回TRUE,否则相反.
//@别名  滚动到左侧()
	BOOL ScrollLeft(){return XSView_ScrollLeft(m_hEle);}
//@备注 水平滚动到右侧.  
//@返回 如果成功返回TRUE,否则相反.
//@别名  滚动到右侧()
	BOOL ScrollRight(){return XSView_ScrollRight(m_hEle);}
//@备注 垂直滚动到顶部.  
//@返回 如果成功返回TRUE,否则相反.
//@别名  滚动到顶部()
	BOOL ScrollTop(){return XSView_ScrollTop(m_hEle);}
//@备注 垂直滚动到底部.  
//@返回 如果成功返回TRUE,否则相反.
//@别名  滚动到底部()
	BOOL ScrollBottom(){return XSView_ScrollBottom(m_hEle);}
};
//@备注  继承: CXScrollView, CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  布局框架类
class CXLayoutFrame: public CXScrollView
{
public:
	CXLayoutFrame(){}
//@参数 x 元素x坐标
//@参数 y 元素y坐标
//@参数 cx 宽度
//@参数 cy 高度
//@参数 hParent 父为窗口句柄或元素句柄.
//@返回 元素句柄
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, HXCGUI hParent){m_hEle = XLayoutFrame_Create(x, y, cx, cy, hParent);return m_hEle;}
//@参数 x 元素x坐标
//@参数 y 元素y坐标
//@参数 cx 宽度
//@参数 cy 高度
//@参数 hParent 父为窗口句柄或元素句柄.
//@返回 元素句柄
CXLayoutFrame(int x, int y, int cx, int cy, HXCGUI hParent){m_hEle = XLayoutFrame_Create(x, y, cx, cy, hParent);}
//@参数 hParent 父为窗口句柄或元素句柄
//@返回 元素句柄.
//@别名  创建扩展()
	HELE CreateEx(HXCGUI hParent){m_hEle = XLayoutFrame_CreateEx(hParent);return m_hEle;}
//@备注 启用布局功能
//@参数 bEnable 是否启用
//@别名  启用()
	void EnableLayout(BOOL bEnable){XLayoutFrame_EnableLayout(m_hEle, bEnable);}
//@备注 是否已经启用布局功能
//@返回 如果启用布局返回TRUE,否则返回FALSE
//@别名  是否启用()
	BOOL IsEnableLayout(){return XLayoutFrame_IsEnableLayout(m_hEle);}
//@参数 bEnable 是否显示
//@别名  显示布局边界()
	void ShowLayoutFrame(BOOL bEnable){XLayoutFrame_ShowLayoutFrame(m_hEle, bEnable);}
//@备注 获取宽度,不包含内边距大小
//@返回 返回宽度
//@别名  取内宽度()
	int GetWidthIn(){return XLayoutFrame_GetWidthIn(m_hEle);}
//@备注 获取高度,不包含内边距大小
//@返回 返回高度
//@别名  取内高度()
	int GetHeightIn(){return XLayoutFrame_GetHeightIn(m_hEle);}
};
//@备注  继承: CXScrollView, CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  列表框类
class CXListBox: public CXScrollView
{
public:
	CXListBox(){}
//@备注 创建列表框元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XListBox_Create(x, y, cx, cy, hParent);return m_hEle;}
//@备注 创建列表框元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
CXListBox(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XListBox_Create(x, y, cx, cy, hParent);}
//@参数 bEnable 是否启用
//@别名  启用固定行高()
	void EnableFixedRowHeight(BOOL bEnable){XListBox_EnableFixedRowHeight(m_hEle, bEnable);}
//@参数 bEnable 是否启用
//@别名  启用模板复用()
	void EnablemTemplateReuse(BOOL bEnable){XListBox_EnablemTemplateReuse(m_hEle, bEnable);}
//@参数 bEnable 是否启用
//@别名  启用虚表()
	void EnableVirtualTable(BOOL bEnable){XListBox_EnableVirtualTable(m_hEle, bEnable);}
//@参数 nRowCount 行数
//@别名  置虚表行数()
	void SetVirtualRowCount(int nRowCount){XListBox_SetVirtualRowCount(m_hEle, nRowCount);}
//@备注 设置是否绘制指定状态下项的背景.  
//@参数 nFlags 标志位 @ref list_drawItemBk_flag_.
//@别名  置绘制项背景标志()
	void SetDrawItemBkFlags(int nFlags){XListBox_SetDrawItemBkFlags(m_hEle, nFlags);}
//@参数 color 颜色值
//@别名  置分割线颜色()
	void SetSplitLineColor(COLORREF color){XListBox_SetSplitLineColor(m_hEle, color);}
//@备注 设置项用户数据.  
//@参数 iItem 想索引.
//@参数 nUserData 用户数据.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项数据()
	BOOL SetItemData(int iItem, vint nUserData){return XListBox_SetItemData(m_hEle, iItem, nUserData);}
//@备注 获取项用户数据.  
//@参数 iItem 项索引.
//@返回 用户数据.
//@别名  取项数据()
	vint GetItemData(int iItem){return XListBox_GetItemData(m_hEle, iItem);}
//@备注 设置项信息.  
//@参数 iItem 项索引.
//@参数 pItem 项信息.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项信息()
	BOOL SetItemInfo(int iItem, listBox_item_info_* pItem){return XListBox_SetItemInfo(m_hEle, iItem, pItem);}
//@备注 获取项信息.  
//@参数 iItem 项索引.
//@参数 pItem 项信息.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  取项背景信息()
	BOOL GetItemInfo(int iItem, listBox_item_info_* pItem){return XListBox_GetItemInfo(m_hEle, iItem, pItem);}
//@备注 设置选择选.  
//@参数 iItem 项索引.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置选择项()
	BOOL SetSelectItem(int iItem){return XListBox_SetSelectItem(m_hEle, iItem);}
//@备注 获取选择项.  
//@返回 项索引.
//@别名  取选择项()
	int GetSelectItem(){return XListBox_GetSelectItem(m_hEle);}
//@参数 iItem 项索引
//@返回 成功返回TRUE,否则返回FALSE
//@别名  添加选择项()
	BOOL AddSelectItem(int iItem){return XListBox_AddSelectItem(m_hEle, iItem);}
//@备注 取消选择指定项.  
//@参数 iItem 项索引.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  取消选择项()
	BOOL CancelSelectItem(int iItem){return XListBox_CancelSelectItem(m_hEle, iItem);}
//@备注 取消所有选中的项.  
//@返回 如果之前有选择状态的项返回TRUE,此时可以更新UI,否则返回FALSE.
//@别名  取消选择全部()
	BOOL CancelSelectAll(){return XListBox_CancelSelectAll(m_hEle);}
//@备注 获取所有选择项.  
//@参数 pArray 数组缓冲区.
//@参数 nArraySize 数组大小.
//@返回 返回接收数量.
//@别名  取全部选择()
	int GetSelectAll(int* pArray, int nArraySize){return XListBox_GetSelectAll(m_hEle, pArray, nArraySize);}
//@备注 获取选择项数量.  
//@返回 返回数量.
//@别名  取选择项数量()
	int GetSelectCount(){return XListBox_GetSelectCount(m_hEle);}
//@备注 获取鼠标停留项.  
//@返回 返回鼠标所在项.
//@别名  取鼠标停留项()
	int GetItemMouseStay(){return XListBox_GetItemMouseStay(m_hEle);}
//@备注 选择所有项.  
//@返回 成功返回TRUE否则返回FALSE.
//@别名  选择全部项()
	BOOL SelectAll(){return XListBox_SelectAll(m_hEle);}
//@备注 滚动视图让指定项可见  
//@参数 iItem 项索引.
//@别名  显示指定项()
	void VisibleItem(int iItem){XListBox_VisibleItem(m_hEle, iItem);}
//@备注 获取当前可见行范围.  
//@参数 piStart 开始行索引
//@参数 piEnd 结束行索引
//@别名  取可视行范围()
	void GetVisibleRowRange(int* piStart, int* piEnd){XListBox_GetVisibleRowRange(m_hEle, piStart, piEnd);}
//@备注 设置项默认高度.  
//@参数 nHeight 项高度.
//@参数 nSelHeight 选中项高度.
//@别名  置项默认高度()
	void SetItemHeightDefault(int nHeight, int nSelHeight){XListBox_SetItemHeightDefault(m_hEle, nHeight, nSelHeight);}
//@备注 获取项默认高度.  
//@参数 pHeight 高度.
//@参数 pSelHeight 选中时高度.
//@别名  取项默认高度()
	void GetItemHeightDefault(int* pHeight, int* pSelHeight){XListBox_GetItemHeightDefault(m_hEle, pHeight, pSelHeight);}
//@备注 获取当前对象所在模板实例,属于列表中哪一个项(行).  
//@参数 hXCGUI 对象句柄, UI元素句柄或形状对象句柄.
//@返回 成功返回项索引, 否则返回@ref XC_ID_ERROR.
//@别名  取所在行索引()
	int GetItemIndexFromHXCGUI(HXCGUI hXCGUI){return XListBox_GetItemIndexFromHXCGUI(m_hEle, hXCGUI);}
//@备注 设置行间距.  
//@参数 nSpace 间距大小.
//@别名  置行间距()
	void SetRowSpace(int nSpace){XListBox_SetRowSpace(m_hEle, nSpace);}
//@备注 获取行间距大小.  
//@返回 返回行间距大小.
//@别名  取行间距()
	int GetRowSpace(){return XListBox_GetRowSpace(m_hEle);}
//@备注 检测坐标点所在项.  
//@参数 pPt 坐标点.
//@返回 返回项索引.
//@别名  测试点击项()
	int HitTest(POINT* pPt){return XListBox_HitTest(m_hEle, pPt);}
//@备注 检测坐标点所在项,自动添加滚动视图偏移量.  
//@参数 pPt 坐标点.
//@返回 项索引.
//@别名  测试点击项扩展()
	int HitTestOffset(POINT* pPt){return XListBox_HitTestOffset(m_hEle, pPt);}
//@备注 设置列表项模板文件.  
//@参数 pXmlFile 文件名.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项模板文件()
	BOOL SetItemTemplateXML(const wchar_t* pXmlFile){return XListBox_SetItemTemplateXML(m_hEle, pXmlFile);}
//@备注 设置列表项模板.  
//@参数 hTemp 模板句柄
//@返回 如果成功返回TRUE,否则返回FALSE.
//@别名  置项模板()
	BOOL SetItemTemplate(HTEMP hTemp){return XListBox_SetItemTemplate(m_hEle, hTemp);}
//@备注 设置项布局模板文件.  
//@参数 pStringXML 字符串指针.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项模板从字符串()
	BOOL SetItemTemplateXMLFromString(const char* pStringXML){return XListBox_SetItemTemplateXMLFromString(m_hEle, pStringXML);}
//@备注 通过模板项ID,获取实例化模板项ID对应的对象句柄.  
//@参数 iItem 项索引.
//@参数 nTempItemID 模板项ID.
//@返回 成功返回对象句柄,否则返回NULL.
//@别名  取模板对象()
	HXCGUI GetTemplateObject(int iItem, int nTempItemID){return XListBox_GetTemplateObject(m_hEle, iItem, nTempItemID);}
//@备注 是否启用多行选择功能.  
//@参数 bEnable 是否启用.
//@别名  启用多选()
	void EnableMultiSel(BOOL bEnable){XListBox_EnableMultiSel(m_hEle, bEnable);}
//@备注 创建数据适配器并绑定,根据绑定的项模板初始化数据适配器的列.  
//@返回 返回适配器句柄.
//@别名  创建数据适配器()
	HXCGUI CreateAdapter(){return XListBox_CreateAdapter(m_hEle);}
//@备注 绑定数据适配器.  
//@参数 hAdapter 数据适配器句柄 XAdTable.
//@别名  绑定数据适配器()
	void BindAdapter(HXCGUI hAdapter){XListBox_BindAdapter(m_hEle, hAdapter);}
//@备注 获取绑定的数据适配器.  
//@返回 返回数据适配器句柄.
//@别名  取数据适配器()
	HXCGUI GetAdapter(){return XListBox_GetAdapter(m_hEle);}
//@备注 排序.  
//@参数 iColumnAdapter 需要排序的数据在数据适配器中所属列索引.
//@参数 bAscending 升序(TRUE)或降序(FALSE).
//@别名  排序()
	void Sort(int iColumnAdapter, BOOL bAscending){XListBox_Sort(m_hEle, iColumnAdapter, bAscending);}
//@备注 修改数据后,刷新所有项模板,以便更新数据到模板(如果项可见).  
//@别名  刷新数据()
	void RefreshData(){XListBox_RefreshData(m_hEle);}
//@备注 修改数据后,刷新指定项模板,以便更新数据到模板(如果当前项可见).  
//@参数 iItem 项索引.
//@别名  刷新指定项()
	void RefreshItem(int iItem){XListBox_RefreshItem(m_hEle, iItem);}
//@备注 XAdTable_AddItemText  
//@参数 pText 
//@返回 返回项索引
//@别名  添加项文本()
	int AddItemText(const wchar_t* pText){return XListBox_AddItemText(m_hEle, pText);}
//@备注 XAdTable_AddItemTextEx  
//@参数 pName 
//@参数 pText 
//@别名  添加项文本扩展()
	int AddItemTextEx(const wchar_t* pName, const wchar_t* pText){return XListBox_AddItemTextEx(m_hEle, pName, pText);}
//@备注 XAdTable_AddItemImage  
//@参数 hImage 
//@别名  添加项图片()
	int AddItemImage(HIMAGE hImage){return XListBox_AddItemImage(m_hEle, hImage);}
//@备注 XAdTable_AddItemImageEx  
//@参数 pName 
//@参数 hImage 
//@别名  添加项图片扩展()
	int AddItemImageEx(const wchar_t* pName, HIMAGE hImage){return XListBox_AddItemImageEx(m_hEle, pName, hImage);}
//@参数 iItem 
//@参数 pValue 
//@别名  插入项文本()
	int InsertItemText(int iItem, const wchar_t* pValue){return XListBox_InsertItemText(m_hEle, iItem, pValue);}
//@参数 iItem 
//@参数 pName 
//@参数 pValue 
//@别名  插入项文本扩展()
	int InsertItemTextEx(int iItem, const wchar_t* pName, const wchar_t* pValue){return XListBox_InsertItemTextEx(m_hEle, iItem, pName, pValue);}
//@参数 iItem 
//@参数 hImage 
//@别名  插入项图片()
	int InsertItemImage(int iItem, HIMAGE hImage){return XListBox_InsertItemImage(m_hEle, iItem, hImage);}
//@参数 iItem 
//@参数 pName 
//@参数 hImage 
//@别名  插入项图片扩展()
	int InsertItemImageEx(int iItem, const wchar_t* pName, HIMAGE hImage){return XListBox_InsertItemImageEx(m_hEle, iItem, pName, hImage);}
//@参数 iItem 
//@参数 iColumn 
//@参数 pText 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项文本()
	BOOL SetItemText(int iItem, int iColumn, const wchar_t* pText){return XListBox_SetItemText(m_hEle, iItem, iColumn, pText);}
//@参数 iItem 
//@参数 pName 
//@参数 pText 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项文本扩展()
	BOOL SetItemTextEx(int iItem, const wchar_t* pName, const wchar_t* pText){return XListBox_SetItemTextEx(m_hEle, iItem, pName, pText);}
//@参数 iItem 
//@参数 iColumn 
//@参数 hImage 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项图片()
	BOOL SetItemImage(int iItem, int iColumn, HIMAGE hImage){return XListBox_SetItemImage(m_hEle, iItem, iColumn, hImage);}
//@参数 iItem 
//@参数 pName 
//@参数 hImage 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项图片扩展()
	BOOL SetItemImageEx(int iItem, const wchar_t* pName, HIMAGE hImage){return XListBox_SetItemImageEx(m_hEle, iItem, pName, hImage);}
//@参数 iItem 
//@参数 iColumn 
//@参数 nValue 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项整数值()
	BOOL SetItemInt(int iItem, int iColumn, int nValue){return XListBox_SetItemInt(m_hEle, iItem, iColumn, nValue);}
//@参数 iItem 
//@参数 pName 
//@参数 nValue 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项整数值扩展()
	BOOL SetItemIntEx(int iItem, const wchar_t* pName, int nValue){return XListBox_SetItemIntEx(m_hEle, iItem, pName, nValue);}
//@参数 iItem 
//@参数 iColumn 
//@参数 fFloat 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项浮点值()
	BOOL SetItemFloat(int iItem, int iColumn, float fFloat){return XListBox_SetItemFloat(m_hEle, iItem, iColumn, fFloat);}
//@参数 iItem 
//@参数 pName 
//@参数 fFloat 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项浮点值扩展()
	BOOL SetItemFloatEx(int iItem, const wchar_t* pName, float fFloat){return XListBox_SetItemFloatEx(m_hEle, iItem, pName, fFloat);}
//@参数 iItem 
//@参数 iColumn 
//@返回 返回文本内容
//@别名  取项文本()
	const wchar_t* GetItemText(int iItem, int iColumn){return XListBox_GetItemText(m_hEle, iItem, iColumn);}
//@参数 iItem 
//@参数 pName 
//@返回 返回文本内容
//@别名  取项文本扩展()
	const wchar_t* GetItemTextEx(int iItem, const wchar_t* pName){return XListBox_GetItemTextEx(m_hEle, iItem, pName);}
//@参数 iItem 
//@参数 iColumn 
//@别名  取项图片()
	HIMAGE GetItemImage(int iItem, int iColumn){return XListBox_GetItemImage(m_hEle, iItem, iColumn);}
//@参数 iItem 
//@参数 pName 
//@别名  取项图片扩展()
	HIMAGE GetItemImageEx(int iItem, const wchar_t* pName){return XListBox_GetItemImageEx(m_hEle, iItem, pName);}
//@参数 iItem 
//@参数 iColumn 
//@参数 pOutValue 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  取项整数值()
	BOOL GetItemInt(int iItem, int iColumn, int* pOutValue){return XListBox_GetItemInt(m_hEle, iItem, iColumn, pOutValue);}
//@参数 iItem 
//@参数 pName 
//@参数 pOutValue 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  取项整数值扩展()
	BOOL GetItemIntEx(int iItem, const wchar_t* pName, int* pOutValue){return XListBox_GetItemIntEx(m_hEle, iItem, pName, pOutValue);}
//@参数 iItem 
//@参数 iColumn 
//@参数 pOutValue 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  取项浮点值()
	BOOL GetItemFloat(int iItem, int iColumn, float* pOutValue){return XListBox_GetItemFloat(m_hEle, iItem, iColumn, pOutValue);}
//@参数 iItem 
//@参数 pName 
//@参数 pOutValue 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  取项浮点值扩展()
	BOOL GetItemFloatEx(int iItem, const wchar_t* pName, float* pOutValue){return XListBox_GetItemFloatEx(m_hEle, iItem, pName, pOutValue);}
//@参数 iItem 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  删除项()
	BOOL DeleteItem(int iItem){return XListBox_DeleteItem(m_hEle, iItem);}
//@参数 iItem 
//@参数 nCount 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  删除项扩展()
	BOOL DeleteItemEx(int iItem, int nCount){return XListBox_DeleteItemEx(m_hEle, iItem, nCount);}
//@别名  删除项全部()
	void DeleteItemAll(){XListBox_DeleteItemAll(m_hEle);}
//@别名  删除列全部()
	void DeleteColumnAll(){XListBox_DeleteColumnAll(m_hEle);}
//@别名  取项数量AD()
	int GetCount_AD(){return XListBox_GetCount_AD(m_hEle);}
//@别名  取列数量AD()
	int GetCountColumn_AD(){return XListBox_GetCountColumn_AD(m_hEle);}
};
//@备注  继承: CXScrollView, CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  列表类
class CXList: public CXScrollView
{
public:
	CXList(){}
//@备注 创建列表元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XList_Create(x, y, cx, cy, hParent);return m_hEle;}
//@备注 创建列表元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
CXList(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XList_Create(x, y, cx, cy, hParent);}
//@备注 增加列.  
//@参数 width 列宽度.
//@返回 返回位置索引.
//@别名  增加列()
	int AddColumn(int width){return XList_AddColumn(m_hEle, width);}
//@备注 插入列.  
//@参数 width 列宽度.
//@参数 iRow 插入位置索引.
//@返回 返回插入位置索引.
//@别名  插入列()
	int InsertColumn(int width, int iRow){return XList_InsertColumn(m_hEle, width, iRow);}
//@备注 启用或关闭多选功能.  
//@参数 bEnable 是否启用.
//@别名  启用多选()
	void EnableMultiSel(BOOL bEnable){XList_EnableMultiSel(m_hEle, bEnable);}
//@备注 启用拖动改变列宽度.  
//@参数 bEnable 是否启用.
//@别名  启用拖动更改列宽()
	void EnableDragChangeColumnWidth(BOOL bEnable){XList_EnableDragChangeColumnWidth(m_hEle, bEnable);}
//@备注 启用垂直滚动条顶部对齐.  
//@参数 bTop 是否启用.
//@别名  启用垂直滚动条顶部对齐()
	void EnableVScrollBarTop(BOOL bTop){XList_EnableVScrollBarTop(m_hEle, bTop);}
//@备注 启用项背景全行填充模式.  
//@参数 bFull 是否启用.
//@别名  启用项背景全行模式()
	void EnableItemBkFullRow(BOOL bFull){XList_EnableItemBkFullRow(m_hEle, bFull);}
//@参数 bEnable 是否启用
//@别名  启用固定行高()
	void EnableFixedRowHeight(BOOL bEnable){XList_EnableFixedRowHeight(m_hEle, bEnable);}
//@参数 bEnable 是否启用
//@别名  启用模板复用()
	void EnablemTemplateReuse(BOOL bEnable){XList_EnablemTemplateReuse(m_hEle, bEnable);}
//@参数 bEnable 是否启用
//@别名  启用虚表()
	void EnableVirtualTable(BOOL bEnable){XList_EnableVirtualTable(m_hEle, bEnable);}
//@参数 nRowCount 行数
//@别名  置虚表行数()
	void SetVirtualRowCount(int nRowCount){XList_SetVirtualRowCount(m_hEle, nRowCount);}
//@备注 设置排序属性.  
//@参数 iColumn 列索引.
//@参数 iColumnAdapter 需要排序的数据在数据适配器中的列索引.
//@参数 bEnable 是否启用排序功能.
//@别名  置排序()
	void SetSort(int iColumn, int iColumnAdapter, BOOL bEnable){XList_SetSort(m_hEle, iColumn, iColumnAdapter, bEnable);}
//@备注 设置是否绘制指定状态下项的背景.  
//@参数 nFlags 标志位 @ref list_drawItemBk_flag_.
//@别名  置绘制项背景标志()
	void SetDrawItemBkFlags(int style){XList_SetDrawItemBkFlags(m_hEle, style);}
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置分割线颜色()
	void SetSplitLineColor(COLORREF color){XList_SetSplitLineColor(m_hEle, color);}
//@备注 设置列宽度.  
//@参数 iRow 列索引.
//@参数 width 宽度.
//@别名  置列宽()
	void SetColumnWidth(int iRow, int width){XList_SetColumnWidth(m_hEle, iRow, width);}
//@备注 设置列最小宽度.  
//@参数 iRow 列索引.
//@参数 width 宽度.
//@别名  置列最小宽度()
	void SetColumnMinWidth(int iRow, int width){XList_SetColumnMinWidth(m_hEle, iRow, width);}
//@备注 设置指定列宽度固定.  
//@参数 iColumn 列索引.
//@参数 bFixed 是否固定宽度.
//@别名  置列宽度固定()
	void SetColumnWidthFixed(int iColumn, BOOL bFixed){XList_SetColumnWidthFixed(m_hEle, iColumn, bFixed);}
//@备注 获取指定列宽度.  
//@参数 iColumn 列索引.
//@返回 返回指定列宽度.
//@别名  取列宽度()
	int GetColumnWidth(int iColumn){return XList_GetColumnWidth(m_hEle, iColumn);}
//@备注 获取列数量.  
//@返回 返回列数量.
//@别名  取列数量()
	int GetColumnCount(){return XList_GetColumnCount(m_hEle);}
//@备注 设置项用户数据.  
//@参数 iRow 行索引.
//@参数 iColumn 列索引.
//@参数 data 用户数据.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项数据()
	BOOL SetItemData(int iRow, int iColumn, int data){return XList_SetItemData(m_hEle, iRow, iColumn, data);}
//@备注 获取项用户数据.  
//@参数 iRow 行索引.
//@参数 iColumn 列索引.
//@返回 返回用户数据.
//@别名  取项数据()
	int GetItemData(int iRow, int iColumn){return XList_GetItemData(m_hEle, iRow, iColumn);}
//@备注 设置选择项.  
//@参数 iRow 行索引.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置选择项()
	BOOL SetSelectItem(int iRow){return XList_SetSelectItem(m_hEle, iRow);}
//@备注 获取选择项.  
//@返回 行索引.
//@别名  取选择项()
	int GetSelectItem(){return XList_GetSelectItem(m_hEle);}
//@备注 获取选择项数量.  
//@返回 返回选择项数量.
//@别名  取选择项数量()
	int GetSelectItemCount(){return XList_GetSelectItemCount(m_hEle);}
//@参数 iRow 行索引
//@返回 成功返回TRUE,否则返回FALSE
//@别名  添加选择项()
	BOOL AddSelectItem(int iRow){return XList_AddSelectItem(m_hEle, iRow);}
//@备注 选择全部行.  
//@别名  置选择全部()
	void SetSelectAll(){XList_SetSelectAll(m_hEle);}
//@备注 获取全部选择的行.  
//@参数 pArray 接收行索引数组.
//@参数 nArraySize 数组大小.
//@返回 返回行数量.
//@别名  取全部选择()
	int GetSelectAll(int* pArray, int nArraySize){return XList_GetSelectAll(m_hEle, pArray, nArraySize);}
//@备注 滚动视图让指定项可见  
//@参数 iRow 行索引.
//@别名  显示指定项()
	void VisibleItem(int iRow){XList_VisibleItem(m_hEle, iRow);}
//@备注 取消选择指定项(这里的项可以理解为行).  
//@参数 iRow 行索引.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  取消选择项()
	BOOL CancelSelectItem(int iRow){return XList_CancelSelectItem(m_hEle, iRow);}
//@备注 取消选择所有项(这里的项可以理解为行).  
//@别名  取消全部选择项()
	void CancelSelectAll(){XList_CancelSelectAll(m_hEle);}
//@备注 获取列表头元素.  
//@返回 返回列表头元素句柄.
//@别名  取列表头()
	HELE GetHeaderHELE(){return XList_GetHeaderHELE(m_hEle);}
//@备注 删除列.  
//@参数 iRow 行索引.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  删除列()
	BOOL DeleteColumn(int iRow){return XList_DeleteColumn(m_hEle, iRow);}
//@备注 删除所有的列,仅删除List的, 数据适配器的列不变.   
//@别名  删除全部列()
	void DeleteColumnAll(){XList_DeleteColumnAll(m_hEle);}
//@备注 绑定数据适配器.  
//@参数 hAdapter 数据适配器句柄 XAdTable.
//@别名  绑定数据适配器()
	void BindAdapter(HXCGUI hAdapter){XList_BindAdapter(m_hEle, hAdapter);}
//@备注 列表头绑定数据适配器.  
//@参数 hAdapter 数据适配器句柄 XAdMap.
//@别名  列表头绑定数据适配器()
	void BindAdapterHeader(HXCGUI hAdapter){XList_BindAdapterHeader(m_hEle, hAdapter);}
//@备注 创建数据适配器，根据绑定的项模板初始化数据适配器的列.  
//@返回 返回适配器句柄.
//@别名  创建数据适配器()
	HXCGUI CreateAdapter(){return XList_CreateAdapter(m_hEle);}
//@备注 创建数据适配器，根据绑定的项模板初始化数据适配器的列.  
//@返回 返回适配器句柄.
//@别名  列表头创建数据适配器()
	HXCGUI CreateAdapterHeader(){return XList_CreateAdapterHeader(m_hEle);}
//@备注 获取数据适配器.  
//@返回 数据适配器句柄.
//@别名  取数据适配器()
	HXCGUI GetAdapter(){return XList_GetAdapter(m_hEle);}
//@备注 获取列表头数据适配器.  
//@返回 返回数据适配器句柄.
//@别名  列表头获取数据适配器()
	HXCGUI GetAdapterHeader(){return XList_GetAdapterHeader(m_hEle);}
//@备注 设置项布局模板文件.  
//@参数 pXmlFile 文件名.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项模板文件()
	BOOL SetItemTemplateXML(const wchar_t* pXmlFile){return XList_SetItemTemplateXML(m_hEle, pXmlFile);}
//@备注 设置项布局模板文件.  
//@参数 pStringXML 字符串指针.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项模板从字符串()
	BOOL SetItemTemplateXMLFromString(const char* pStringXML){return XList_SetItemTemplateXMLFromString(m_hEle, pStringXML);}
//@备注 设置列表项模板.  
//@参数 hTemp 模板句柄.
//@返回 如果成功返回TRUE,否则返回FALSE.
//@别名  置项模板()
	BOOL SetItemTemplate(HTEMP hTemp){return XList_SetItemTemplate(m_hEle, hTemp);}
//@备注 通过模板项ID,获取实例化模板项ID对应的对象句柄.  
//@参数 iRow 行索引.
//@参数 iColumn 列索引.
//@参数 nTempItemID 模板项itemID.
//@返回 成功返回对象句柄,否则返回NULL.
//@别名  取项模板对象()
	HXCGUI GetTemplateObject(int iRow, int iColumn, int nTempItemID){return XList_GetTemplateObject(m_hEle, iRow, iColumn, nTempItemID);}
//@备注 获取当前对象所在模板实例,属于列表中哪一个项.  
//@参数 hXCGUI 对象句柄, UI元素句柄或形状对象句柄.
//@返回 成功返回行索引, 否则返回@ref XC_ID_ERROR.
//@别名  取对象所在行()
	int GetItemIndexFromHXCGUI(HXCGUI hXCGUI){return XList_GetItemIndexFromHXCGUI(m_hEle, hXCGUI);}
//@备注 列表头,通过模板项ID,获取实例化模板项ID对应的对象句柄.  
//@参数 iColumn 列表头 列索引.
//@参数 nTempItemID 模板项ID.
//@返回 成功返回对象句柄,否则返回NULL.
//@别名  取列表头模板对象()
	HXCGUI GetHeaderTemplateObject(int iColumn, int nTempItemID){return XList_GetHeaderTemplateObject(m_hEle, iColumn, nTempItemID);}
//@备注 列表头,获取当前对象所在模板实例,属于列表头中哪一个项.  
//@参数 hXCGUI 对象句柄.
//@返回 成功返回行索引, 否则返回@ref XC_ID_ERROR.
//@别名  取列表头对象所在行()
	int GetHeaderItemIndexFromHXCGUI(HXCGUI hXCGUI){return XList_GetHeaderItemIndexFromHXCGUI(m_hEle, hXCGUI);}
//@备注 设置列表头高度.  
//@参数 height 高度.
//@别名  置列表头高度()
	void SetHeaderHeight(int height){XList_SetHeaderHeight(m_hEle, height);}
//@备注 获取列表头高度.  
//@返回 返回列表头高度.
//@别名  取列表头高度()
	int GetHeaderHeight(){return XList_GetHeaderHeight(m_hEle);}
//@备注 获取当前可见行范围.  
//@参数 piStart 开始行索引.
//@参数 piEnd 结束行索引.
//@别名  取可视行范围()
	void GetVisibleRowRange(int* piStart, int* piEnd){XList_GetVisibleRowRange(m_hEle, piStart, piEnd);}
//@备注 设置项默认高度.  
//@参数 nHeight 高度.
//@参数 nSelHeight 选中时高度.
//@别名  置项默认高度()
	void SetItemHeightDefault(int nHeight, int nSelHeight){XList_SetItemHeightDefault(m_hEle, nHeight, nSelHeight);}
//@备注 获取项默认高度.  
//@参数 pHeight 高度.
//@参数 pSelHeight 选中时高度.
//@别名  取项默认高度()
	void GetItemHeightDefault(int* pHeight, int* pSelHeight){XList_GetItemHeightDefault(m_hEle, pHeight, pSelHeight);}
//@备注 设置项高度.  
//@参数 iRow 行索引
//@参数 nHeight 高度.
//@参数 nSelHeight 选中时高度.
//@别名  置项高度()
	void SetItemHeight(int iRow, int nHeight, int nSelHeight){XList_SetItemHeight(m_hEle, iRow, nHeight, nSelHeight);}
//@备注 获取项高度.  
//@参数 iRow 行索引
//@参数 pHeight 高度.
//@参数 pSelHeight 选中时高度.
//@别名  取项高度()
	void GetItemHeight(int iRow, int* pHeight, int* pSelHeight){XList_GetItemHeight(m_hEle, iRow, pHeight, pSelHeight);}
//@备注 设置行间距.  
//@参数 nSpace 行间距大小.
//@别名  置行间距()
	void SetRowSpace(int nSpace){XList_SetRowSpace(m_hEle, nSpace);}
//@备注 获取行间距大小.  
//@返回 返回行间距大小.
//@别名  取行间距()
	int GetRowSpace(){return XList_GetRowSpace(m_hEle);}
//@备注 锁定列,设置左侧锁定列分界列索引.  
//@参数 iColumn 列索引,-1代表不锁定.
//@别名  置锁定列左侧()
	void SetLockColumnLeft(int iColumn){XList_SetLockColumnLeft(m_hEle, iColumn);}
//@备注 锁定列,设置右侧锁定列分界列索引  
//@参数 iColumn 列索引, -1代表不锁定. 暂时只支持锁定末尾列 
//@别名  置锁定列右侧()
	void SetLockColumnRight(int iColumn){XList_SetLockColumnRight(m_hEle, iColumn);}
//@备注 设置是否锁定末尾行.  
//@参数 bLock 是否锁定.
//@别名  置锁定行底部()
	void SetLockRowBottom(BOOL bLock){XList_SetLockRowBottom(m_hEle, bLock);}
//@参数 bOverlap 是否重叠
//@别名  置锁定行底部重叠()
	void SetLockRowBottomOverlap(BOOL bOverlap){XList_SetLockRowBottomOverlap(m_hEle, bOverlap);}
//@备注 检测坐标点所在项.  
//@参数 pPt 坐标点.
//@参数 piRow 行索引.
//@参数 piColumn 列索引.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  测试点击项()
	BOOL HitTest(POINT* pPt, int* piRow, int* piColumn){return XList_HitTest(m_hEle, pPt, piRow, piColumn);}
//@备注 检查坐标点所在项,自动添加滚动视图偏移量.  
//@参数 pPt 坐标点.
//@参数 piRow 行索引.
//@参数 piColumn 列索引.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  测试点击项扩展()
	BOOL HitTestOffset(POINT* pPt, int* piRow, int* piColumn){return XList_HitTestOffset(m_hEle, pPt, piRow, piColumn);}
//@备注 修改数据后,刷新所有项模板,以便更新数据到模板(如果项可见).  
//@别名  刷新项数据()
	void RefreshData(){XList_RefreshData(m_hEle);}
//@备注 修改数据后,刷新指定项模板,以便更新数据到模板(如果当前项可见).  
//@参数 iRow 行索引.
//@别名  刷新指定项()
	void RefreshItem(int iRow){XList_RefreshItem(m_hEle, iRow);}
//@参数 nWidth 
//@参数 pName 
//@参数 pText 
//@返回 列索引
//@别名  添加列文本()
	int AddColumnText(int nWidth, const wchar_t* pName, const wchar_t* pText){return XList_AddColumnText(m_hEle, nWidth, pName, pText);}
//@参数 nWidth 
//@参数 pName 
//@参数 hImage 
//@返回 列索引
//@别名  添加列图片()
	int AddColumnImage(int nWidth, const wchar_t* pName, HIMAGE hImage){return XList_AddColumnImage(m_hEle, nWidth, pName, hImage);}
//@参数 pText 
//@别名  添加项文本()
	int AddItemText(const wchar_t* pText){return XList_AddItemText(m_hEle, pText);}
//@参数 pName 
//@参数 pText 
//@别名  添加项文本扩展()
	int AddItemTextEx(const wchar_t* pName, const wchar_t* pText){return XList_AddItemTextEx(m_hEle, pName, pText);}
//@参数 hImage 
//@别名  添加项图片()
	int AddItemImage(HIMAGE hImage){return XList_AddItemImage(m_hEle, hImage);}
//@参数 pName 
//@参数 hImage 
//@别名  添加项图片扩展()
	int AddItemImageEx(const wchar_t* pName, HIMAGE hImage){return XList_AddItemImageEx(m_hEle, pName, hImage);}
//@参数 iRow 
//@参数 pValue 
//@别名  插入项文本()
	int InsertItemText(int iRow, const wchar_t* pValue){return XList_InsertItemText(m_hEle, iRow, pValue);}
//@参数 iRow 
//@参数 pName 
//@参数 pValue 
//@别名  插入项文本扩展()
	int InsertItemTextEx(int iRow, const wchar_t* pName, const wchar_t* pValue){return XList_InsertItemTextEx(m_hEle, iRow, pName, pValue);}
//@参数 iRow 
//@参数 hImage 
//@别名  插入项图片()
	int InsertItemImage(int iRow, HIMAGE hImage){return XList_InsertItemImage(m_hEle, iRow, hImage);}
//@参数 iRow 
//@参数 pName 
//@参数 hImage 
//@别名  插入项图片扩展()
	int InsertItemImageEx(int iRow, const wchar_t* pName, HIMAGE hImage){return XList_InsertItemImageEx(m_hEle, iRow, pName, hImage);}
//@参数 iRow 
//@参数 iColumn 
//@参数 pText 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项文本()
	BOOL SetItemText(int iRow, int iColumn, const wchar_t* pText){return XList_SetItemText(m_hEle, iRow, iColumn, pText);}
//@参数 iRow 
//@参数 pName 
//@参数 pText 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项文本扩展()
	BOOL SetItemTextEx(int iRow, const wchar_t* pName, const wchar_t* pText){return XList_SetItemTextEx(m_hEle, iRow, pName, pText);}
//@参数 iRow 
//@参数 iColumn 
//@参数 hImage 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项图片()
	BOOL SetItemImage(int iRow, int iColumn, HIMAGE hImage){return XList_SetItemImage(m_hEle, iRow, iColumn, hImage);}
//@参数 iRow 
//@参数 pName 
//@参数 hImage 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项图片扩展()
	BOOL SetItemImageEx(int iRow, const wchar_t* pName, HIMAGE hImage){return XList_SetItemImageEx(m_hEle, iRow, pName, hImage);}
//@参数 iRow 
//@参数 iColumn 
//@参数 nValue 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项指数值()
	BOOL SetItemInt(int iRow, int iColumn, int nValue){return XList_SetItemInt(m_hEle, iRow, iColumn, nValue);}
//@参数 iRow 
//@参数 pName 
//@参数 nValue 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项整数值扩展()
	BOOL SetItemIntEx(int iRow, const wchar_t* pName, int nValue){return XList_SetItemIntEx(m_hEle, iRow, pName, nValue);}
//@参数 iRow 
//@参数 iColumn 
//@参数 fFloat 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项浮点值()
	BOOL SetItemFloat(int iRow, int iColumn, float fFloat){return XList_SetItemFloat(m_hEle, iRow, iColumn, fFloat);}
//@参数 iRow 
//@参数 pName 
//@参数 fFloat 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项浮点值扩展()
	BOOL SetItemFloatEx(int iRow, const wchar_t* pName, float fFloat){return XList_SetItemFloatEx(m_hEle, iRow, pName, fFloat);}
//@参数 iRow 
//@参数 iColumn 
//@返回 返回文本内容
//@别名  取项文本()
	const wchar_t* GetItemText(int iRow, int iColumn){return XList_GetItemText(m_hEle, iRow, iColumn);}
//@参数 iRow 
//@参数 pName 
//@返回 返回文本内容
//@别名  取项文本扩展()
	const wchar_t* GetItemTextEx(int iRow, const wchar_t* pName){return XList_GetItemTextEx(m_hEle, iRow, pName);}
//@参数 iRow 
//@参数 iColumn 
//@别名  取项图片()
	HIMAGE GetItemImage(int iRow, int iColumn){return XList_GetItemImage(m_hEle, iRow, iColumn);}
//@参数 iRow 
//@参数 pName 
//@别名  取项图片扩展()
	HIMAGE GetItemImageEx(int iRow, const wchar_t* pName){return XList_GetItemImageEx(m_hEle, iRow, pName);}
//@参数 iRow 
//@参数 iColumn 
//@参数 pOutValue 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  取项整数值()
	BOOL GetItemInt(int iRow, int iColumn, int* pOutValue){return XList_GetItemInt(m_hEle, iRow, iColumn, pOutValue);}
//@参数 iRow 
//@参数 pName 
//@参数 pOutValue 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  取项整数值扩展()
	BOOL GetItemIntEx(int iRow, const wchar_t* pName, int* pOutValue){return XList_GetItemIntEx(m_hEle, iRow, pName, pOutValue);}
//@参数 iRow 
//@参数 iColumn 
//@参数 pOutValue 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  取项浮点值()
	BOOL GetItemFloat(int iRow, int iColumn, float* pOutValue){return XList_GetItemFloat(m_hEle, iRow, iColumn, pOutValue);}
//@参数 iRow 
//@参数 pName 
//@参数 pOutValue 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  取项浮点值扩展()
	BOOL GetItemFloatEx(int iRow, const wchar_t* pName, float* pOutValue){return XList_GetItemFloatEx(m_hEle, iRow, pName, pOutValue);}
//@参数 iRow 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  删除项()
	BOOL DeleteItem(int iRow){return XList_DeleteItem(m_hEle, iRow);}
//@参数 iRow 
//@参数 nCount 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  删除项扩展()
	BOOL DeleteItemEx(int iRow, int nCount){return XList_DeleteItemEx(m_hEle, iRow, nCount);}
//@别名  删除项全部()
	void DeleteItemAll(){XList_DeleteItemAll(m_hEle);}
//@别名  删除列全部AD()
	void DeleteColumnAll_AD(){XList_DeleteColumnAll_AD(m_hEle);}
//@别名  取项数量AD()
	int GetCount_AD(){return XList_GetCount_AD(m_hEle);}
//@别名  取列数量AD()
	int GetCountColumn_AD(){return XList_GetCountColumn_AD(m_hEle);}
};
//@备注  继承: CXScrollView, CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  列表视图类
class CXListView: public CXScrollView
{
public:
	CXListView(){}
//@备注 创建列表视图元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或U I元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XListView_Create(x, y, cx, cy, hParent);return m_hEle;}
//@备注 创建列表视图元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或U I元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
CXListView(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XListView_Create(x, y, cx, cy, hParent);}
//@备注 创建数据适配器，根据绑定的项模板初始化数据适配器的列.  
//@返回 返回适配器句柄.
//@别名  创建数据适配器()
	HXCGUI CreateAdapter(){return XListView_CreateAdapter(m_hEle);}
//@备注 绑定数据适配器.  
//@参数 hAdapter 数据适配器 XAdListView.
//@别名  绑定数据适配器()
	void BindAdapter(HXCGUI hAdapter){XListView_BindAdapter(m_hEle, hAdapter);}
//@备注 获取数据适配器.  
//@返回 返回数据适配器.
//@别名  取数据适配器()
	HXCGUI GetAdapter(){return XListView_GetAdapter(m_hEle);}
//@备注 置项模板文件.  
//@参数 pXmlFile 文件名.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项模板文件()
	BOOL SetItemTemplateXML(const wchar_t* pXmlFile){return XListView_SetItemTemplateXML(m_hEle, pXmlFile);}
//@备注 置项布局模板.  
//@参数 pStringXML 字符串指针.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项模板从字符串()
	BOOL SetItemTemplateXMLFromString(const char* pStringXML){return XListView_SetItemTemplateXMLFromString(m_hEle, pStringXML);}
//@备注 置列表项模板.  
//@参数 hTemp 模板句柄.
//@返回 如果成功返回TRUE,否则返回FALSE.
//@别名  置项模板()
	BOOL SetItemTemplate(HTEMP hTemp){return XListView_SetItemTemplate(m_hEle, hTemp);}
//@备注 通过模板项ID,获取实例化模板项ID对应的对象句柄.  
//@参数 iGroup 组索引.
//@参数 iItem 项索引.
//@参数 nTempItemID 模板项ID.
//@返回 成功返回对象句柄,否则返回NULL.
//@别名  取模板对象()
	HXCGUI GetTemplateObject(int iGroup, int iItem, int nTempItemID){return XListView_GetTemplateObject(m_hEle, iGroup, iItem, nTempItemID);}
//@备注 通过模板项ID,获取实例化模板项ID对应的对象句柄.  
//@参数 iGroup 组索引.
//@参数 nTempItemID 模板项ID.
//@返回 成功返回对象句柄,否则返回NULL.
//@别名  取模板对象组()
	HXCGUI GetTemplateObjectGroup(int iGroup, int nTempItemID){return XListView_GetTemplateObjectGroup(m_hEle, iGroup, nTempItemID);}
//@备注 获取当前对象所在模板实例,属于列表视中哪一个项.  
//@参数 hXCGUI 对象句柄, UI元素句柄或形状对象句柄.
//@参数 piGroup 接收组索引.
//@参数 piItem 接收项索引.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  取对象所在项()
	BOOL GetItemIDFromHXCGUI(HXCGUI hXCGUI, int* piGroup, int* piItem){return XListView_GetItemIDFromHXCGUI(m_hEle, hXCGUI, piGroup, piItem);}
//@备注 检查坐标点所在项.  
//@参数 pPt 坐标点.
//@参数 pOutGroup 接收组索引.
//@参数 pOutItem 接收项索引.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  测试点击项()
	BOOL HitTest(POINT* pPt, int* pOutGroup, int* pOutItem){return XListView_HitTest(m_hEle, pPt, pOutGroup, pOutItem);}
//@备注 检查坐标点所在项,自动添加滚动视图偏移量.  
//@参数 pPt 坐标点.
//@参数 pOutGroup 接收做索引.
//@参数 pOutItem 接收项索引.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  测试点击项扩展()
	BOOL HitTestOffset(POINT* pPt, int* pOutGroup, int* pOutItem){return XListView_HitTestOffset(m_hEle, pPt, pOutGroup, pOutItem);}
//@备注 启用多选.  
//@参数 bEnable 是否启用.
//@别名  启用多选()
	void EnableMultiSel(BOOL bEnable){XListView_EnableMultiSel(m_hEle, bEnable);}
//@参数 bEnable 是否启用
//@别名  启用模板复用()
	void EnablemTemplateReuse(BOOL bEnable){XListView_EnablemTemplateReuse(m_hEle, bEnable);}
//@参数 bEnable 是否启用
//@别名  启用虚表()
	void EnableVirtualTable(BOOL bEnable){XListView_EnableVirtualTable(m_hEle, bEnable);}
//@参数 iGroup 组索引
//@参数 nCount 项数量
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置虚表项数量()
	BOOL SetVirtualItemCount(int iGroup, int nCount){return XListView_SetVirtualItemCount(m_hEle, iGroup, nCount);}
//@备注 置是否绘制指定状态下项的背景.  
//@参数 nFlags 标志位  @ref list_drawItemBk_flag_.
//@别名  置项背景绘制标志()
	void SetDrawItemBkFlags(int nFlags){XListView_SetDrawItemBkFlags(m_hEle, nFlags);}
//@备注 置选择项.  
//@参数 iGroup 组索引.
//@参数 iItem 项索引.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置选择项()
	BOOL SetSelectItem(int iGroup, int iItem){return XListView_SetSelectItem(m_hEle, iGroup, iItem);}
//@备注 获取选择项.  
//@参数 piGroup 接收组索引.
//@参数 piItem 接收项索引.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  取选择项()
	BOOL GetSelectItem(int* piGroup, int* piItem){return XListView_GetSelectItem(m_hEle, piGroup, piItem);}
//@参数 iGroup 组索引
//@参数 iItem 项索引
//@返回 成功返回TRUE,否则返回FALSE
//@别名  添加选择项()
	BOOL AddSelectItem(int iGroup, int iItem){return XListView_AddSelectItem(m_hEle, iGroup, iItem);}
//@备注 滚动视图让指定项可见  
//@参数 iGroup 组索引.
//@参数 iItem 项索引.
//@别名  显示指定项()
	void VisibleItem(int iGroup, int iItem){XListView_VisibleItem(m_hEle, iGroup, iItem);}
//@备注 获取当前可见项范围.  
//@参数 piGroup1 可视开始组, 组可见
//@参数 piGroup2 可视结束组, 组可见
//@参数 piStartGroup 可视开始组
//@参数 piStartItem 可视开始项
//@参数 piEndGroup 可视结束组
//@参数 piEndItem 可视结束项
//@别名  取可视项范围()
	void GetVisibleItemRange(int* piGroup1, int* piGroup2, int* piStartGroup, int* piStartItem, int* piEndGroup, int* piEndItem){XListView_GetVisibleItemRange(m_hEle, piGroup1, piGroup2, piStartGroup, piStartItem, piEndGroup, piEndItem);}
//@备注 获取选择项数量.  
//@返回 返回选择项数量.
//@别名  取选择项数量()
	int GetSelectItemCount(){return XListView_GetSelectItemCount(m_hEle);}
//@备注 获取选择的项ID.  
//@参数 pArray 数组,用来接收选择项ID.
//@参数 nArraySize 数组大小.
//@返回 返回接收项数量.
//@别名  取选择项全部()
	int GetSelectAll(listView_item_id_* pArray, int nArraySize){return XListView_GetSelectAll(m_hEle, pArray, nArraySize);}
//@备注 选择所有的项.  
//@别名  置选择项全部()
	void SetSelectAll(){XListView_SetSelectAll(m_hEle);}
//@备注 取消选择所有项.  
//@别名  取消选择项全部()
	void CancelSelectAll(){XListView_CancelSelectAll(m_hEle);}
//@备注 置列间隔大小.  
//@参数 space 间隔大小.
//@别名  置列间隔()
	void SetColumnSpace(int space){XListView_SetColumnSpace(m_hEle, space);}
//@备注 置行间隔大小.  
//@参数 space 间隔大小.
//@别名  置行间隔()
	void SetRowSpace(int space){XListView_SetRowSpace(m_hEle, space);}
//@备注 置项大小.  
//@参数 width 宽度.
//@参数 height 高度.
//@别名  置项大小()
	void SetItemSize(int width, int height){XListView_SetItemSize(m_hEle, width, height);}
//@备注 获取项大小.  
//@参数 pSize 接收返回大小.
//@别名  取项大小()
	void GetItemSize(SIZE* pSize){XListView_GetItemSize(m_hEle, pSize);}
//@备注 置组高度.  
//@参数 height 高度.
//@别名  置组高度()
	void SetGroupHeight(int height){XListView_SetGroupHeight(m_hEle, height);}
//@备注 获取组高度.  
//@返回 返回组高度.
//@别名  取组高度()
	int GetGroupHeight(){return XListView_GetGroupHeight(m_hEle);}
//@备注 置组用户数据.  
//@参数 iGroup 组索引.
//@参数 nData 数据.
//@别名  置组用户数据()
	void SetGroupUserData(int iGroup, vint nData){XListView_SetGroupUserData(m_hEle, iGroup, nData);}
//@备注 设置项用户数据.  
//@参数 iGroup 组索引.
//@参数 iItem 项索引.
//@参数 nData 数据.
//@别名  置项用户数据()
	void SetItemUserData(int iGroup, int iItem, vint nData){XListView_SetItemUserData(m_hEle, iGroup, iItem, nData);}
//@备注 获取组用户数据.  
//@参数 iGroup 组索引.
//@返回 返回用户数据.
//@别名  取组用户数据()
	vint GetGroupUserData(int iGroup){return XListView_GetGroupUserData(m_hEle, iGroup);}
//@备注 获取项用户数据.  
//@参数 iGroup 组索引.
//@参数 iItem 项索引.
//@返回 返回用户数据.
//@别名  取项用户数据()
	vint GetItemUserData(int iGroup, int iItem){return XListView_GetItemUserData(m_hEle, iGroup, iItem);}
//@备注 修改数据后,刷新所有项模板,以便更新数据到模板(如果项可见).  
//@别名  刷新项数据()
	void RefreshData(){XListView_RefreshData(m_hEle);}
//@备注 修改数据后,刷新指定项模板,以便更新数据到模板(如果当前项可见).  
//@参数 iGroup 组索引.
//@参数 iItem 项索引, 如果为-1,代表为组.
//@别名  刷新指定项()
	void RefreshItem(int iGroup, int iItem){XListView_RefreshItem(m_hEle, iGroup, iItem);}
//@备注 展开组.  
//@参数 iGroup 组索引.
//@参数 bExpand 是否展开.
//@返回 成功返回TRUE否则返回FALSE,如果状态没有改变返回FALSE.
//@别名  展开组()
	BOOL ExpandGroup(int iGroup, BOOL bExpand){return XListView_ExpandGroup(m_hEle, iGroup, bExpand);}
//@参数 pName 字段称
//@返回 返回列索引
//@别名  组添加列()
	int Group_AddColumn(const wchar_t* pName){return XListView_Group_AddColumn(m_hEle, pName);}
//@参数 pValue 值
//@参数 iPos 插入位置, -1添加到末尾
//@返回 返回组索引
//@别名  组添加项文本()
	int Group_AddItemText(const wchar_t* pValue, int iPos){return XListView_Group_AddItemText(m_hEle, pValue, iPos);}
//@参数 pName 字段称
//@参数 pValue 值
//@参数 iPos 插入位置, -1添加到末尾
//@返回 返回组索引
//@别名  组添加项文本扩展()
	int Group_AddItemTextEx(const wchar_t* pName, const wchar_t* pValue, int iPos){return XListView_Group_AddItemTextEx(m_hEle, pName, pValue, iPos);}
//@参数 hImage 图片句柄
//@参数 iPos 插入位置, -1添加到末尾
//@返回 返回组索引
//@别名  组添加项图片()
	int Group_AddItemImage(HIMAGE hImage, int iPos){return XListView_Group_AddItemImage(m_hEle, hImage, iPos);}
//@参数 pName 字段称
//@参数 hImage 图片句柄
//@参数 iPos 插入位置, -1添加到末尾
//@返回 返回组索引
//@别名  组添加项图片扩展()
	int Group_AddItemImageEx(const wchar_t* pName, HIMAGE hImage, int iPos){return XListView_Group_AddItemImageEx(m_hEle, pName, hImage, iPos);}
//@参数 iGroup 组索引
//@参数 iColumn 列索引
//@参数 pValue 值
//@返回 成功返回TRUE,否则返回FALSE
//@别名  组置文本()
	BOOL Group_SetText(int iGroup, int iColumn, const wchar_t* pValue){return XListView_Group_SetText(m_hEle, iGroup, iColumn, pValue);}
//@参数 iGroup 组索引
//@参数 pName 字段名
//@参数 pValue 值
//@返回 成功返回TRUE,否则返回FALSE
//@别名  组置文本扩展()
	BOOL Group_SetTextEx(int iGroup, const wchar_t* pName, const wchar_t* pValue){return XListView_Group_SetTextEx(m_hEle, iGroup, pName, pValue);}
//@参数 iGroup 组索引
//@参数 iColumn 列索引
//@参数 hImage 图片句柄
//@返回 成功返回TRUE,否则返回FALSE
//@别名  组置图片()
	BOOL Group_SetImage(int iGroup, int iColumn, HIMAGE hImage){return XListView_Group_SetImage(m_hEle, iGroup, iColumn, hImage);}
//@参数 iGroup 组索引
//@参数 pName 字段名
//@参数 hImage 图片句柄
//@返回 成功返回TRUE,否则返回FALSE
//@别名  组置图片扩展()
	BOOL Group_SetImageEx(int iGroup, const wchar_t* pName, HIMAGE hImage){return XListView_Group_SetImageEx(m_hEle, iGroup, pName, hImage);}
//@参数 iGroup 组索引
//@参数 iColumn 列索引
//@返回 返回文本内容
//@别名  组取文本()
	const wchar_t* Group_GetText(int iGroup, int iColumn){return XListView_Group_GetText(m_hEle, iGroup, iColumn);}
//@参数 iGroup 组索引
//@参数 pName 字段名称
//@返回 返回文本内容
//@别名  组取文本扩展()
	const wchar_t* Group_GetTextEx(int iGroup, const wchar_t* pName){return XListView_Group_GetTextEx(m_hEle, iGroup, pName);}
//@参数 iGroup 组索引
//@参数 iColumn 列索引
//@返回 返回图片句柄
//@别名  组取图片()
	HIMAGE Group_GetImage(int iGroup, int iColumn){return XListView_Group_GetImage(m_hEle, iGroup, iColumn);}
//@参数 iGroup 组索引
//@参数 pName 字段名称
//@返回 返回图片句柄
//@别名  组取图片扩展()
	HIMAGE Group_GetImageEx(int iGroup, const wchar_t* pName){return XListView_Group_GetImageEx(m_hEle, iGroup, pName);}
//@返回 返回组数量
//@别名  组获取数量()
	int Group_GetCount(){return XListView_Group_GetCount(m_hEle);}
//@参数 iGroup 组索引
//@返回 成功返回项数量,否则返回 @ref XC_ID_ERROR.
//@别名  项取数量()
	int Item_GetCount(int iGroup){return XListView_Item_GetCount(m_hEle, iGroup);}
//@参数 pName 字段名
//@返回 返回列索引
//@别名  项添加列()
	int Item_AddColumn(const wchar_t* pName){return XListView_Item_AddColumn(m_hEle, pName);}
//@参数 iGroup 组索引
//@参数 pValue 值
//@参数 iPos 插入位置, -1添加到末尾
//@返回 返回项索引
//@别名  项添加文本()
	int Item_AddItemText(int iGroup, const wchar_t* pValue, int iPos){return XListView_Item_AddItemText(m_hEle, iGroup, pValue, iPos);}
//@参数 iGroup 组索引
//@参数 pName 字段名
//@参数 pValue 值
//@参数 iPos 插入位置, -1添加到末尾
//@返回 返回项索引
//@别名  项添加文本扩展()
	int Item_AddItemTextEx(int iGroup, const wchar_t* pName, const wchar_t* pValue, int iPos){return XListView_Item_AddItemTextEx(m_hEle, iGroup, pName, pValue, iPos);}
//@参数 iGroup 组索引
//@参数 hImage 图片句柄
//@参数 iPos 插入位置, -1添加到末尾
//@返回 返回项索引
//@别名  项添加图片()
	int Item_AddItemImage(int iGroup, HIMAGE hImage, int iPos){return XListView_Item_AddItemImage(m_hEle, iGroup, hImage, iPos);}
//@参数 iGroup 组索引
//@参数 pName 字段名
//@参数 hImage 图片句柄
//@参数 iPos 插入位置, -1添加到末尾
//@返回 返回项索引
//@别名  项添加图片扩展()
	int Item_AddItemImageEx(int iGroup, const wchar_t* pName, HIMAGE hImage, int iPos){return XListView_Item_AddItemImageEx(m_hEle, iGroup, pName, hImage, iPos);}
//@参数 iGroup 组索引
//@参数 iItem 项索引
//@参数 iColumn 列索引
//@参数 pValue 值
//@返回 成功返回TRUE,否则返回FALSE
//@别名  项置文本()
	BOOL Item_SetText(int iGroup, int iItem, int iColumn, const wchar_t* pValue){return XListView_Item_SetText(m_hEle, iGroup, iItem, iColumn, pValue);}
//@参数 iGroup 组索引
//@参数 iItem 项索引
//@参数 pName 字段名
//@参数 pValue 值
//@返回 成功返回TRUE,否则返回FALSE
//@别名  项置文本扩展()
	BOOL Item_SetTextEx(int iGroup, int iItem, const wchar_t* pName, const wchar_t* pValue){return XListView_Item_SetTextEx(m_hEle, iGroup, iItem, pName, pValue);}
//@参数 iGroup 组索引
//@参数 iItem 项索引
//@参数 iColumn 列索引
//@参数 hImage 图片句柄
//@返回 成功返回TRUE,否则返回FALSE
//@别名  项置图片()
	BOOL Item_SetImage(int iGroup, int iItem, int iColumn, HIMAGE hImage){return XListView_Item_SetImage(m_hEle, iGroup, iItem, iColumn, hImage);}
//@参数 iGroup 组索引
//@参数 iItem 项索引
//@参数 pName 列名称
//@参数 hImage 图片句柄
//@返回 成功返回TRUE,否则返回FALSE
//@别名  项置图片扩展()
	BOOL Item_SetImageEx(int iGroup, int iItem, const wchar_t* pName, HIMAGE hImage){return XListView_Item_SetImageEx(m_hEle, iGroup, iItem, pName, hImage);}
//@参数 iGroup 组索引
//@返回 成功返回TRUE,否则返回FALSE
//@别名  组删除项()
	BOOL Group_DeleteItem(int iGroup){return XListView_Group_DeleteItem(m_hEle, iGroup);}
//@参数 iGroup 组索引
//@别名  组删除全部子项()
	void Group_DeleteAllChildItem(int iGroup){XListView_Group_DeleteAllChildItem(m_hEle, iGroup);}
//@参数 iGroup 组索引
//@参数 iItem 项索引
//@返回 成功返回TRUE,否则返回FALSE
//@别名  项删除()
	BOOL Item_DeleteItem(int iGroup, int iItem){return XListView_Item_DeleteItem(m_hEle, iGroup, iItem);}
//@别名  删除全部()
	void DeleteAll(){XListView_DeleteAll(m_hEle);}
//@别名  删除全部组()
	void DeleteAllGroup(){XListView_DeleteAllGroup(m_hEle);}
//@别名  删除全部项()
	void DeleteAllItem(){XListView_DeleteAllItem(m_hEle);}
//@参数 iColumn 列索引
//@别名  组删除列()
	void DeleteColumnGroup(int iColumn){XListView_DeleteColumnGroup(m_hEle, iColumn);}
//@参数 iColumn 列索引
//@别名  项删除列()
	void DeleteColumnItem(int iColumn){XListView_DeleteColumnItem(m_hEle, iColumn);}
//@参数 iGroup 组索引
//@参数 iItem 项索引
//@参数 iColumn 列索引
//@返回 返回文本内容
//@别名  项取文本()
	const wchar_t* Item_GetText(int iGroup, int iItem, int iColumn){return XListView_Item_GetText(m_hEle, iGroup, iItem, iColumn);}
//@参数 iGroup 组索引
//@参数 iItem 项索引
//@参数 pName 字段称
//@返回 返回文本内容
//@别名  项取文本扩展()
	const wchar_t* Item_GetTextEx(int iGroup, int iItem, const wchar_t* pName){return XListView_Item_GetTextEx(m_hEle, iGroup, iItem, pName);}
//@参数 iGroup 组索引
//@参数 iItem 项索引
//@参数 iColumn 列索引
//@返回 返回图片句柄
//@别名  项取图片()
	HIMAGE Item_GetImage(int iGroup, int iItem, int iColumn){return XListView_Item_GetImage(m_hEle, iGroup, iItem, iColumn);}
//@参数 iGroup 组索引
//@参数 iItem 项索引
//@参数 pName 字段称
//@返回 返回图片句柄
//@别名  项取图片扩展()
	HIMAGE Item_GetImageEx(int iGroup, int iItem, const wchar_t* pName){return XListView_Item_GetImageEx(m_hEle, iGroup, iItem, pName);}
};
//@备注  继承: CXScrollView, CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  列表树类
class CXTree: public CXScrollView
{
public:
	CXTree(){}
//@备注 创建树元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XTree_Create(x, y, cx, cy, hParent);return m_hEle;}
//@备注 创建树元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
CXTree(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XTree_Create(x, y, cx, cy, hParent);}
//@备注 启用拖动项功能.  
//@参数 bEnable 是否启用.
//@别名  启用拖动项()
	void EnableDragItem(BOOL bEnable){XTree_EnableDragItem(m_hEle, bEnable);}
//@备注 启用或禁用显示项的连接线.  
//@参数 bEnable 是否启用.
//@参数 bSolid 实线或虚线; TRUE:实线, FALSE:虚线.
//@别名  启用连接线()
	void EnableConnectLine(BOOL bEnable, BOOL bSolid){XTree_EnableConnectLine(m_hEle, bEnable, bSolid);}
//@备注 启动或关闭默认展开功能,如果开启新插入的项将自动展开.  
//@参数 bEnable 是否启用.
//@别名  启用展开()
	void EnableExpand(BOOL bEnable){XTree_EnableExpand(m_hEle, bEnable);}
//@参数 bEnable 是否启用
//@别名  启用模板复用()
	void EnablemTemplateReuse(BOOL bEnable){XTree_EnablemTemplateReuse(m_hEle, bEnable);}
//@备注 设置项连接线颜色.  
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置连接线颜色()
	void SetConnectLineColor(COLORREF color){XTree_SetConnectLineColor(m_hEle, color);}
//@备注 设置展开按钮占用空间大小.  
//@参数 nWidth 宽度.
//@参数 nHeight 高度.
//@别名  置展开按钮大小()
	void SetExpandButtonSize(int nWidth, int nHeight){XTree_SetExpandButtonSize(m_hEle, nWidth, nHeight);}
//@备注 设置连线绘制长度,展开按钮与项内容之间的连线.  
//@参数 nLength 连线绘制长度.
//@别名  置连接线长度()
	void SetConnectLineLength(int nLength){XTree_SetConnectLineLength(m_hEle, nLength);}
//@备注 设置拖动项插入位置颜色提示.  
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置拖动项插入位置颜色()
	void SetDragInsertPositionColor(COLORREF color){XTree_SetDragInsertPositionColor(m_hEle, color);}
//@备注 设置项模板文件.  
//@参数 pXmlFile 文件名.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项模板文件()
	BOOL SetItemTemplateXML(const wchar_t* pXmlFile){return XTree_SetItemTemplateXML(m_hEle, pXmlFile);}
//@备注 设置项模板文件,项选中状态.  
//@参数 pXmlFile 文件名.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置选择项模板文件()
	BOOL SetItemTemplateXMLSel(const wchar_t* pXmlFile){return XTree_SetItemTemplateXMLSel(m_hEle, pXmlFile);}
//@备注 设置列表项模板.  
//@参数 hTemp 模板句柄.
//@返回 如果成功返回TRUE,否则返回FALSE.
//@别名  置项模板()
	BOOL SetItemTemplate(HTEMP hTemp){return XTree_SetItemTemplate(m_hEle, hTemp);}
//@备注 设置列表项模板,项选中状态.  
//@参数 hTemp 模板句柄.
//@返回 如果成功返回TRUE,否则返回FALSE.
//@别名  置选择项模板()
	BOOL SetItemTemplateSel(HTEMP hTemp){return XTree_SetItemTemplateSel(m_hEle, hTemp);}
//@备注 设置项模板文件.  
//@参数 pStringXML 字符串指针.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项模板从字符串()
	BOOL SetItemTemplateXMLFromString(const char* pStringXML){return XTree_SetItemTemplateXMLFromString(m_hEle, pStringXML);}
//@备注 设置项模板文件,项选中状态.  
//@参数 pStringXML 字符串指针.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置选择项模板从字符串()
	BOOL SetItemTemplateXMLSelFromString(const char* pStringXML){return XTree_SetItemTemplateXMLSelFromString(m_hEle, pStringXML);}
//@备注 设置是否绘制指定状态下项的背景.  
//@参数 nFlags 标志位 @ref list_drawItemBk_flag_.
//@别名  置项背景绘制标志()
	void SetDrawItemBkFlags(int nFlags){XTree_SetDrawItemBkFlags(m_hEle, nFlags);}
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置分割线颜色()
	void SetSplitLineColor(COLORREF color){XTree_SetSplitLineColor(m_hEle, color);}
//@备注 设置项用户数据.  
//@参数 nID 项ID.
//@参数 nUserData 用户数据.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项数据()
	BOOL SetItemData(int nID, vint nUserData){return XTree_SetItemData(m_hEle, nID, nUserData);}
//@备注 获取项用户数据.  
//@参数 nID 项ID.
//@返回 项用户数据.
//@别名  取项数据()
	vint GetItemData(int nID){return XTree_GetItemData(m_hEle, nID);}
//@备注 设置选择项.  
//@参数 nID 项ID.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置选择项()
	BOOL SetSelectItem(int nID){return XTree_SetSelectItem(m_hEle, nID);}
//@备注 获取选择项.  
//@返回 项ID.
//@别名  取选择项()
	int GetSelectItem(){return XTree_GetSelectItem(m_hEle);}
//@备注 滚动视图让指定项可见  
//@参数 nID 项索引.
//@别名  可视指定项()
	void VisibleItem(int nID){XTree_VisibleItem(m_hEle, nID);}
//@备注 判断项是否展开.  
//@参数 nID 项ID.
//@返回 如果展开返回TRUE否则返回FALSE.
//@别名  是否展开()
	BOOL IsExpand(int nID){return XTree_IsExpand(m_hEle, nID);}
//@备注 展开项.  
//@参数 nID 项ID.
//@参数 bExpand 是否展开.
//@返回 成功返回TRUE,如果项已经展开或失败返回FALSE.
//@别名  展开项()
	BOOL ExpandItem(int nID, BOOL bExpand){return XTree_ExpandItem(m_hEle, nID, bExpand);}
//@备注 展开所有的子项.  
//@参数 nID 项ID.
//@参数 bExpand 是否展开.
//@返回 成功返回TRUE,失败返回FALSE.
//@别名  展开全部子项()
	BOOL ExpandAllChildItem(int nID, BOOL bExpand){return XTree_ExpandAllChildItem(m_hEle, nID, bExpand);}
//@备注 检测坐标点所在项.  
//@参数 pPt 坐标点.
//@返回 项ID.
//@别名  测试点击项()
	int HitTest(POINT* pPt){return XTree_HitTest(m_hEle, pPt);}
//@备注 检测坐标点所在项,自动添加滚动视图偏移坐标.  
//@参数 pPt 坐标点.
//@返回 项ID.
//@别名  测试点击项扩展()
	int HitTestOffset(POINT* pPt){return XTree_HitTestOffset(m_hEle, pPt);}
//@备注 获取第一个子项.  
//@参数 nID 项ID.
//@返回 返回项ID,失败返回XC_ID_ERROR.
//@别名  取第一个子项()
	int GetFirstChildItem(int nID){return XTree_GetFirstChildItem(m_hEle, nID);}
//@备注 获取末尾子项.  
//@参数 nID 项ID.
//@返回 返回末尾子项ID,失败返回XC_ID_ERROR.
//@别名  取末尾子项()
	int GetEndChildItem(int nID){return XTree_GetEndChildItem(m_hEle, nID);}
//@备注 获取上一个兄弟项.  
//@参数 nID 项ID.
//@返回 返回上一个兄弟项ID, 失败返回 XC_ID_ERROR.
//@别名  取上一个兄弟项()
	int GetPrevSiblingItem(int nID){return XTree_GetPrevSiblingItem(m_hEle, nID);}
//@备注 获取下一个兄弟项.  
//@参数 nID 项ID.
//@返回 返回下一个兄弟项ID.
//@别名  取下一个兄弟项()
	int GetNextSiblingItem(int nID){return XTree_GetNextSiblingItem(m_hEle, nID);}
//@备注 获取父项.  
//@参数 nID 项ID.
//@返回 返回父项ID,错误返回-1.
//@别名  取父项()
	int GetParentItem(int nID){return XTree_GetParentItem(m_hEle, nID);}
//@备注 创建数据适配器，根据绑定的项模板初始化数据适配器的列.  
//@返回 返回适配器句柄.
//@别名  创建数据适配器()
	HXCGUI CreateAdapter(){return XTree_CreateAdapter(m_hEle);}
//@备注 绑定数据适配器.  
//@参数 hAdapter 数据适配器句柄, XAdTree.
//@别名  绑定数据适配器()
	void BindAdapter(HXCGUI hAdapter){XTree_BindAdapter(m_hEle, hAdapter);}
//@备注 获取数据适配器.  
//@返回 返回数据适配器句柄.
//@别名  取数据视频器()
	HXCGUI GetAdapter(){return XTree_GetAdapter(m_hEle);}
//@备注 修改数据后,刷新所有项模板,以便更新数据到模板(如果项可见).  
//@别名  刷新数据()
	void RefreshData(){XTree_RefreshData(m_hEle);}
//@备注 修改数据后,刷新指定项模板,以便更新数据到模板(如果当前项可见).  
//@参数 nID 项ID.
//@别名  刷新指定项()
	void RefreshItem(int nID){XTree_RefreshItem(m_hEle, nID);}
//@备注 设置缩进大小.  
//@参数 nWidth 缩进宽度.
//@别名  置缩进()
	void SetIndentation(int nWidth){XTree_SetIndentation(m_hEle, nWidth);}
//@备注 获取缩进值.  
//@返回 返回缩进值大小.
//@别名  取缩进()
	int GetIndentation(){return XTree_GetIndentation(m_hEle);}
//@备注 设置项默认高度.  
//@参数 nHeight 高度.
//@参数 nSelHeight 选中时高度.
//@别名  置项默认高度()
	void SetItemHeightDefault(int nHeight, int nSelHeight){XTree_SetItemHeightDefault(m_hEle, nHeight, nSelHeight);}
//@备注 获取项默认高度.  
//@参数 pHeight 接收返回高度.
//@参数 pSelHeight 接收返回值,当项选中时的高度.
//@别名  取项默认高度()
	void GetItemHeightDefault(int* pHeight, int* pSelHeight){XTree_GetItemHeightDefault(m_hEle, pHeight, pSelHeight);}
//@备注 设置指定项高度.  
//@参数 nID 项ID.
//@参数 nHeight 高度.
//@参数 nSelHeight 选中时高度.
//@别名  置项高度()
	void SetItemHeight(int nID, int nHeight, int nSelHeight){XTree_SetItemHeight(m_hEle, nID, nHeight, nSelHeight);}
//@备注 获取指定项高度.  
//@参数 nID 项ID.
//@参数 pHeight 接收返回高度.
//@参数 pSelHeight 接收返回值,当项选中时的高度.
//@别名  取项高度()
	void GetItemHeight(int nID, int* pHeight, int* pSelHeight){XTree_GetItemHeight(m_hEle, nID, pHeight, pSelHeight);}
//@备注 设置行间隔大小.  
//@参数 nSpace 行间隔大小.
//@别名  置行间距()
	void SetRowSpace(int nSpace){XTree_SetRowSpace(m_hEle, nSpace);}
//@备注 获取行间距大小.  
//@返回 返回行间距大小.
//@别名  取行间距()
	int GetRowSpace(){return XTree_GetRowSpace(m_hEle);}
//@备注 移动项的位置.  
//@参数 nMoveItem 要移动的项ID.
//@参数 nDestItem 目标项ID, 参照位置.
//@参数 nFlag 0:目标前面, 1:目标后面, 2:目标子项首, 3:目标子项尾
//@返回 成功返回TRUE否则返回FALSE.
//@别名  移动项()
	BOOL MoveItem(int nMoveItem, int nDestItem, int nFlag){return XTree_MoveItem(m_hEle, nMoveItem, nDestItem, nFlag);}
//@备注 通过模板项ID,获取实例化模板项ID对应的对象句柄.  
//@参数 nID 树项ID.
//@参数 nTempItemID 模板项ID.
//@返回 成功返回对象句柄,否则返回NULL.
//@别名  取模板对象()
	HXCGUI GetTemplateObject(int nID, int nTempItemID){return XTree_GetTemplateObject(m_hEle, nID, nTempItemID);}
//@备注 获取当前对象所在模板实例,属于列表树中哪一个项.  
//@参数 hXCGUI 对象句柄, UI元素句柄或形状对象句柄..
//@返回 成功返回项ID, 否则返回@ref XC_ID_ERROR.
//@别名  取对象所在项()
	int GetItemIDFromHXCGUI(HXCGUI hXCGUI){return XTree_GetItemIDFromHXCGUI(m_hEle, hXCGUI);}
//@参数 pValue 
//@参数 nParentID 
//@参数 insertID 
//@别名  插入项文本()
	int InsertItemText(const wchar_t* pValue, int nParentID=XC_ID_ROOT, int insertID=XC_ID_LAST){return XTree_InsertItemText(m_hEle, pValue, nParentID, insertID);}
//@参数 pName 
//@参数 pValue 
//@参数 nParentID 
//@参数 insertID 
//@别名  插入项文本扩展()
	int InsertItemTextEx(const wchar_t* pName, const wchar_t* pValue, int nParentID=XC_ID_ROOT, int insertID=XC_ID_LAST){return XTree_InsertItemTextEx(m_hEle, pName, pValue, nParentID, insertID);}
//@参数 hImage 
//@参数 nParentID 
//@参数 insertID 
//@别名  插入项图片()
	int InsertItemImage(HIMAGE hImage, int nParentID=XC_ID_ROOT, int insertID=XC_ID_LAST){return XTree_InsertItemImage(m_hEle, hImage, nParentID, insertID);}
//@参数 pName 
//@参数 hImage 
//@参数 nParentID 
//@参数 insertID 
//@别名  插入项图片扩展()
	int InsertItemImageEx(const wchar_t* pName, HIMAGE hImage, int nParentID=XC_ID_ROOT, int insertID=XC_ID_LAST){return XTree_InsertItemImageEx(m_hEle, pName, hImage, nParentID, insertID);}
//@别名  取项数量()
	int GetCount(){return XTree_GetCount(m_hEle);}
//@别名  取列数量()
	int GetCountColumn(){return XTree_GetCountColumn(m_hEle);}
//@参数 nID 
//@参数 iColumn 
//@参数 pValue 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项文本()
	BOOL SetItemText(int nID, int iColumn, const wchar_t* pValue){return XTree_SetItemText(m_hEle, nID, iColumn, pValue);}
//@参数 nID 
//@参数 pName 
//@参数 pValue 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项文本扩展()
	BOOL SetItemTextEx(int nID, const wchar_t* pName, const wchar_t* pValue){return XTree_SetItemTextEx(m_hEle, nID, pName, pValue);}
//@参数 nID 
//@参数 iColumn 
//@参数 hImage 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项图片()
	BOOL SetItemImage(int nID, int iColumn, HIMAGE hImage){return XTree_SetItemImage(m_hEle, nID, iColumn, hImage);}
//@参数 nID 
//@参数 pName 
//@参数 hImage 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项图片扩展()
	BOOL SetItemImageEx(int nID, const wchar_t* pName, HIMAGE hImage){return XTree_SetItemImageEx(m_hEle, nID, pName, hImage);}
//@参数 nID 
//@参数 iColumn 
//@返回 返回文本内容
//@别名  取项文本()
	const wchar_t* GetItemText(int nID, int iColumn){return XTree_GetItemText(m_hEle, nID, iColumn);}
//@参数 nID 
//@参数 pName 
//@返回 返回文本内容
//@别名  取项文本扩展()
	const wchar_t* GetItemTextEx(int nID, const wchar_t* pName){return XTree_GetItemTextEx(m_hEle, nID, pName);}
//@参数 nID 
//@参数 iColumn 
//@别名  取项图片()
	HIMAGE GetItemImage(int nID, int iColumn){return XTree_GetItemImage(m_hEle, nID, iColumn);}
//@参数 nID 
//@参数 pName 
//@别名  取项图片扩展()
	HIMAGE GetItemImageEx(int nID, const wchar_t* pName){return XTree_GetItemImageEx(m_hEle, nID, pName);}
//@备注 XAdTree_DeleteItem  
//@参数 nID 
//@返回 成功返回TRUE,否则返回FALSE
//@别名  删除项()
	BOOL DeleteItem(int nID){return XTree_DeleteItem(m_hEle, nID);}
//@备注 XAdTree_DeleteItemAll  
//@别名  删除全部项()
	void DeleteItemAll(){XTree_DeleteItemAll(m_hEle);}
//@备注 XAdTree_DeleteColumnAll  
//@别名  删除列全部()
	void DeleteColumnAll(){XTree_DeleteColumnAll(m_hEle);}
};
//@备注  继承: CXScrollView, CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  属性网格类
class CPGrid: public CXScrollView
{
public:
	CPGrid(){}
};
//@备注  继承: CXScrollView, CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  编辑框类
class CXEdit: public CXScrollView
{
public:
	CXEdit(){}
//@备注 创建
//@参数 x 元素x坐标
//@参数 y 元素y坐标
//@参数 cx 宽度
//@参数 cy 高度
//@参数 hParent 父为窗口句柄或元素句柄
//@返回 元素句柄
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XEdit_Create(x, y, cx, cy, hParent);return m_hEle;}
//@备注 创建
//@参数 x 元素x坐标
//@参数 y 元素y坐标
//@参数 cx 宽度
//@参数 cy 高度
//@参数 hParent 父为窗口句柄或元素句柄
//@返回 元素句柄
CXEdit(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XEdit_Create(x, y, cx, cy, hParent);}
//@备注 创建
//@参数 x 元素x坐标
//@参数 y 元素y坐标
//@参数 cx 宽度
//@参数 cy 高度
//@参数 type 类型
//@参数 hParent 父为窗口句柄或元素句柄
//@返回 元素句柄
//@别名  创建扩展()
	HELE CreateEx(int x, int y, int cx, int cy, edit_type_ type, HXCGUI hParent=NULL){m_hEle = XEdit_CreateEx(x, y, cx, cy, type, hParent);return m_hEle;}
//@备注 启用自动换行  
//@参数 bEnable 是否启用
//@别名  启用自动换行()
	void EnableAutoWrap(BOOL bEnable){XEdit_EnableAutoWrap(m_hEle, bEnable);}
//@参数 bEnable 是否启用
//@别名  启用只读()
	void EnableReadOnly(BOOL bEnable){XEdit_EnableReadOnly(m_hEle, bEnable);}
//@参数 bEnable 
//@别名  启用多行()
	void EnableMultiLine(BOOL bEnable){XEdit_EnableMultiLine(m_hEle, bEnable);}
//@备注 启用密码模式(只支持默认类型编辑框
//@参数 bEnable 是否启用
//@别名  启用密码()
	void EnablePassword(BOOL bEnable){XEdit_EnablePassword(m_hEle, bEnable);}
//@备注 当获得焦点时,自动选择所有内容
//@参数 bEnable 是否启用
//@别名  启用自动选择()
	void EnableAutoSelAll(BOOL bEnable){XEdit_EnableAutoSelAll(m_hEle, bEnable);}
//@备注 当失去焦点时自动取消选择
//@参数 bEnable 是否启用
//@别名  启用自动取消选择()
	void EnableAutoCancelSel(BOOL bEnable){XEdit_EnableAutoCancelSel(m_hEle, bEnable);}
//@返回 成功返回TRUE,否则返回FALSE
//@别名  是否只读()
	BOOL IsReadOnly(){return XEdit_IsReadOnly(m_hEle);}
//@返回 成功返回TRUE,否则返回FALSE
//@别名  是否多行()
	BOOL IsMultiLine(){return XEdit_IsMultiLine(m_hEle);}
//@返回 成功返回TRUE,否则返回FALSE
//@别名  是否密码()
	BOOL IsPassword(){return XEdit_IsPassword(m_hEle);}
//@返回 成功返回TRUE,否则返回FALSE
//@别名  是否自动换行()
	BOOL IsAutoWrap(){return XEdit_IsAutoWrap(m_hEle);}
//@返回 如果为空返回TRUE否则返回FALSE.
//@别名  是否为空()
	BOOL IsEmpty(){return XEdit_IsEmpty(m_hEle);}
//@参数 iRow 行索引
//@参数 iCol 列索引
//@返回 如果在选择区域内返回TRUE,否则返回FALSE
//@别名  是否在选择区域()
	BOOL IsInSelect(int iRow, int iCol){return XEdit_IsInSelect(m_hEle, iRow, iCol);}
//@返回 返回从行数
//@别名  取总行数()
	int GetRowCount(){return XEdit_GetRowCount(m_hEle);}
//@备注 包含文本或非文本内容
//@返回 返回数据结构
//@别名  取数据()
	edit_data_copy_* GetData(){return XEdit_GetData(m_hEle);}
//@参数 pData 数据结构
//@参数 styleTable 样式表
//@参数 nStyleCount 样式数量
//@别名  添加数据()
	void AddData(edit_data_copy_* pData, USHORT* styleTable, int nStyleCount){XEdit_AddData(m_hEle, pData, styleTable, nStyleCount);}
//@别名  释放数据()
//@参数 pData 数据结构
	void FreeData(edit_data_copy_* pData){XEdit_FreeData(pData);}
//@备注 当内容为空时,显示默认文本
//@参数 pString 文本内容
//@别名  置默认文本()
	void SetDefaultText(const wchar_t* pString){XEdit_SetDefaultText(m_hEle, pString);}
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置默认文本颜色()
	void SetDefaultTextColor(COLORREF color){XEdit_SetDefaultTextColor(m_hEle, color);}
//@参数 ch 字符
//@别名  置密码字符()
	void SetPasswordCharacter(wchar_t ch){XEdit_SetPasswordCharacter(m_hEle, ch);}
//@备注 单行模式下有效
//@参数 align 对齐方式 @ref edit_textAlign_flag_
//@别名  置文本对齐()
	void SetTextAlign(int align){XEdit_SetTextAlign(m_hEle, align);}
//@参数 nSpace 空格数量
//@别名  置TAB空格()
	void SetTabSpace(int nSpace){XEdit_SetTabSpace(m_hEle, nSpace);}
//@备注 置中文字体;  如果已设置, 当遇到中文字符时使用后备字体, 解决不支持中文的字体问题
//@参数 hFont 字体
//@别名  置后备字体()
	void SetBackFont(HFONTX hFont){XEdit_SetBackFont(m_hEle, hFont);}
//@参数 size 空格大小
//@别名  置空格大小()
	void SetSpaceSize(int size){XEdit_SetSpaceSize(m_hEle, size);}
//@参数 size 英文字符间距大小
//@参数 sizeZh 中文字符间距大小
//@别名  置字符间距()
	void SetCharSpaceSize(int size, int sizeZh){XEdit_SetCharSpaceSize(m_hEle, size, sizeZh);}
//@参数 pString 字符串
//@别名  置文本()
	void SetText(const wchar_t* pString){XEdit_SetText(m_hEle, pString);}
//@参数 nValue 整数值
//@别名  置文本整数()
	void SetTextInt(int nValue){XEdit_SetTextInt(m_hEle, nValue);}
//@备注 不包含非文本内容
//@参数 pOut 接收文本内存指针
//@参数 nOutlen 内存大小, 字符为单位
//@返回 返回实际接收文本长度
//@别名  取文本()
	int GetText(wchar_t* pOut, int nOutlen){return XEdit_GetText(m_hEle, pOut, nOutlen);}
//@备注 获取指定行文本内容
//@参数 iRow 行索引
//@参数 pOut 接收文本内存指针
//@参数 nOutlen 接收文本内存块长度,字符为单位
//@返回 返回实际接收文本长度
//@别名  取文本行()
	int GetTextRow(int iRow, wchar_t* pOut, int nOutlen){return XEdit_GetTextRow(m_hEle, iRow, pOut, nOutlen);}
//@备注 包含非文本内容
//@返回 返回内容长度
//@别名  取内容长度()
	int GetLength(){return XEdit_GetLength(m_hEle);}
//@备注 包含非文本内容
//@参数 iRow 行索引
//@返回 返回内容长度
//@别名  取内容长度行()
	int GetLengthRow(int iRow){return XEdit_GetLengthRow(m_hEle, iRow);}
//@参数 iRow 行索引
//@参数 iCol 列索引
//@返回 返回指定位置字符
//@别名  取字符()
	wchar_t GetAt(int iRow, int iCol){return XEdit_GetAt(m_hEle, iRow, iCol);}
//@参数 iRow 行索引
//@参数 iCol 列索引
//@参数 pString 字符串
//@别名  插入文本()
	void InsertText(int iRow, int iCol, const wchar_t* pString){XEdit_InsertText(m_hEle, iRow, iCol, pString);}
//@参数 pString 字符串
//@别名  添加文本()
	void AddText(const wchar_t* pString){XEdit_AddText(m_hEle, pString);}
//@备注 自动刷新UI, 支持撤销/恢复
//@参数 pString 字符串
//@别名  添加文本模拟用户操作()
	void AddTextUser(const wchar_t* pString){XEdit_AddTextUser(m_hEle, pString);}
//@参数 pString 字符串
//@参数 iStyle 样式索引
//@别名  添加文本扩展()
	void AddTextEx(const wchar_t* pString, int iStyle){XEdit_AddTextEx(m_hEle, pString, iStyle);}
//@备注 例如: 字体, 图片, UI对象
//@参数 hObj 对象句柄
//@返回 返回样式索引
//@别名  添加对象()
	int AddObject(HXCGUI hObj){return XEdit_AddObject(m_hEle, hObj);}
//@备注 当样式为图片时有效
//@参数 iStyle 样式索引
//@别名  添加对象从样式()
	void AddByStyle(int iStyle){XEdit_AddByStyle(m_hEle, iStyle);}
//@参数 hFont_image_Obj 字体,图片或UI对象
//@参数 color 颜色
//@参数 bColor 是否使用颜色
//@返回 返回样式索引
//@别名  添加样式()
	int AddStyle(HXCGUI hFont_image_Obj, COLORREF color, BOOL bColor){return XEdit_AddStyle(m_hEle, hFont_image_Obj, color, bColor);}
//@参数 fontName 字体名称
//@参数 fontSize 字体大小
//@参数 fontStyle 字体样式 @ref fontStyle_
//@参数 color 颜色
//@参数 bColor 是否使用颜色
//@返回 返回样式索引
//@别名  添加样式扩展()
	int AddStyleEx(const wchar_t* fontName, int fontSize, int fontStyle, COLORREF color, BOOL bColor){return XEdit_AddStyleEx(m_hEle, fontName, fontSize, fontStyle, color, bColor);}
//@参数 iStyle 样式索引
//@参数 hFont 字体句柄
//@参数 color 颜色
//@参数 bColor 是否使用颜色
//@返回 如果成功返回TRUE,否则返回FALSE
//@别名  修改样式()
	BOOL ModifyStyle(int iStyle, HFONTX hFont, COLORREF color, BOOL bColor){return XEdit_ModifyStyle(m_hEle, iStyle, hFont, color, bColor);}
//@参数 iStyle 样式
//@返回 如果成功返回TRUE,否则返回FALSE 
//@别名  释放样式()
	BOOL ReleaseStyle(int iStyle){return XEdit_ReleaseStyle(m_hEle, iStyle);}
//@参数 iStyle 样式索引
//@参数 info 返回样式信息
//@返回 成功返回TRUE,否则返回FALSE
//@别名  取样式信息()
	BOOL GetStyleInfo(int iStyle, edit_style_info_* info){return XEdit_GetStyleInfo(m_hEle, iStyle, info);}
//@参数 iStyle 样式索引
//@别名  置当前样式()
	void SetCurStyle(int iStyle){XEdit_SetCurStyle(m_hEle, iStyle);}
//@参数 iStyle 样式索引
//@别名  置选择文本样式()
	void SetSelectTextStyle(int iStyle){XEdit_SetSelectTextStyle(m_hEle, iStyle);}
//@参数 color 颜色
//@别名  置插入符颜色()
	void SetCaretColor(COLORREF color){XEdit_SetCaretColor(m_hEle, color);}
//@参数 nWidth 宽度
//@别名  置插入符宽度()
	void SetCaretWidth(int nWidth){XEdit_SetCaretWidth(m_hEle, nWidth);}
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置选择背景颜色()
	void SetSelectBkColor(COLORREF color){XEdit_SetSelectBkColor(m_hEle, color);}
//@参数 nHeight 行高
//@别名  置默认行高()
	void SetRowHeight(int nHeight){XEdit_SetRowHeight(m_hEle, nHeight);}
//@备注 当类型为 edit_type_richedit 支持指定不同行高
//@参数 iRow 行索引
//@参数 nHeight 高度
//@别名  置指定行高度()
	void SetRowHeightEx(int iRow, int nHeight){XEdit_SetRowHeightEx(m_hEle, iRow, nHeight);}
//@备注 设置行间隔大小,多行模式有效
//@参数 nSpace 行间隔大小
//@别名  置行间隔()
	void SetRowSpace(int nSpace){XEdit_SetRowSpace(m_hEle, nSpace);}
//@参数 pos 位置
//@返回 如果成功返回TRUE,否则返回FALSE
//@别名  置当前位置()
	BOOL SetCurPos(int pos){return XEdit_SetCurPos(m_hEle, pos);}
//@返回 返回位置
//@别名  取当前位置()
	int GetCurPos(){return XEdit_GetCurPos(m_hEle);}
//@参数 iRow 行索引
//@参数 iCol 列索引
//@别名  置当前位置扩展()
	void SetCurPosEx(int iRow, int iCol){XEdit_SetCurPosEx(m_hEle, iRow, iCol);}
//@参数 iRow 返回行索引
//@参数 iCol 返回列索引
//@别名  取当前位置扩展()
	void GetCurPosEx(int* iRow, int* iCol){XEdit_GetCurPosEx(m_hEle, iRow, iCol);}
//@返回 返回行索引
//@别名  取当前行()
	int GetCurRow(){return XEdit_GetCurRow(m_hEle);}
//@返回 返回列索引
//@别名  取当前列()
	int GetCurCol(){return XEdit_GetCurCol(m_hEle);}
//@别名  移动到末尾()
	void MoveEnd(){XEdit_MoveEnd(m_hEle);}
//@参数 iRow 行索引
//@参数 iCol 列索引
//@参数 pOut 接收返回坐标点
//@别名  取坐标点()
	void GetPoint(int iRow, int iCol, POINT* pOut){XEdit_GetPoint(m_hEle, iRow, iCol, pOut);}
//@备注 视图自动滚动到当前插入符位置
//@返回 成功返回TRUE,否则返回FALSE
//@别名  自动滚动()
	BOOL AutoScroll(){return XEdit_AutoScroll(m_hEle);}
//@备注 视图自动滚动到指定位置
//@参数 iRow 行索引
//@参数 iCol 列索引
//@返回 成功返回TRUE,否则返回FALSE
//@别名  自动滚动扩展()
	BOOL AutoScrollEx(int iRow, int iCol){return XEdit_AutoScrollEx(m_hEle, iRow, iCol);}
//@备注 转换位置点到行列
//@参数 iPos 位置点
//@参数 pInfo 行列
//@别名  位置到行列()
	void PosToRowCol(int iPos, position_* pInfo){XEdit_PosToRowCol(m_hEle, iPos, pInfo);}
//@参数 iRow 行索引
//@参数 iCol 列索引
//@返回 位置点
//@别名  行列到位置()
	int RowColToPos(int iRow, int iCol){return XEdit_RowColToPos(m_hEle, iRow, iCol);}
//@返回 成功返回TRUE,否则返回FALSE
//@别名  选择全部()
	BOOL SelectAll(){return XEdit_SelectAll(m_hEle);}
//@返回 成功返回TRUE,否则返回FALSE
//@别名  取消选择()
	BOOL CancelSelect(){return XEdit_CancelSelect(m_hEle);}
//@返回 成功返回TRUE,否则返回FALSE
//@别名  删除选择内容()
	BOOL DeleteSelect(){return XEdit_DeleteSelect(m_hEle);}
//@参数 iStartRow 起始行索引
//@参数 iStartCol 起始行列索引
//@参数 iEndRow 结束行索引
//@参数 iEndCol 结束行列索引
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置选择()
	BOOL SetSelect(int iStartRow, int iStartCol, int iEndRow, int iEndCol){return XEdit_SetSelect(m_hEle, iStartRow, iStartCol, iEndRow, iEndCol);}
//@备注 不包括非文本内容
//@参数 pOut 接收返回文本内容
//@参数 nOutLen 接收内存大小,字符为单位
//@返回 返回接收文本内容实际长度
//@别名  取选择文本()
	int GetSelectText(wchar_t* pOut, int nOutLen){return XEdit_GetSelectText(m_hEle, pOut, nOutLen);}
//@备注 不包括非文本内容
//@返回 返回文本内容长度
//@别名  取选择文本长度()
	int GetSelectTextLength(){return XEdit_GetSelectTextLength(m_hEle);}
//@参数 pBegin 起始位置
//@参数 pEnd 结束位置
//@返回 成功返回TRUE,否则返回FALSE
//@别名  取选择内容范围()
	BOOL GetSelectRange(position_* pBegin, position_* pEnd){return XEdit_GetSelectRange(m_hEle, pBegin, pEnd);}
//@参数 piStart 起始行索引
//@参数 piEnd 结束行索引
//@别名  取可视行范围()
	void GetVisibleRowRange(int* piStart, int* piEnd){XEdit_GetVisibleRowRange(m_hEle, piStart, piEnd);}
//@备注 删除指定范围内容; 删除全部请使用 XEdit_SetText(hEdit,L"")
//@参数 iStartRow 起始行索引
//@参数 iStartCol 起始行列索引
//@参数 iEndRow 结束行索引
//@参数 iEndCol 结束行列索引
//@返回 成功返回TRUE,否则返回FALSE
//@别名  删除()
	BOOL Delete(int iStartRow, int iStartCol, int iEndRow, int iEndCol){return XEdit_Delete(m_hEle, iStartRow, iStartCol, iEndRow, iEndCol);}
//@参数 iRow 行索引
//@返回 成功返回TRUE,否则返回FALSE
//@别名  删除行()
	BOOL DeleteRow(int iRow){return XEdit_DeleteRow(m_hEle, iRow);}
//@返回 成功返回TRUE,否则返回FALSE
//@别名  剪贴板剪切()
	BOOL ClipboardCut(){return XEdit_ClipboardCut(m_hEle);}
//@返回 成功返回TRUE,否则返回FALSE
//@别名  剪贴板复制()
	BOOL ClipboardCopy(){return XEdit_ClipboardCopy(m_hEle);}
//@返回 成功返回TRUE,否则返回FALSE
//@别名  剪贴板粘贴()
	BOOL ClipboardPaste(){return XEdit_ClipboardPaste(m_hEle);}
//@返回 成功返回TRUE,否则返回FALSE
//@别名  撤销()
	BOOL Undo(){return XEdit_Undo(m_hEle);}
//@备注 恢复/重做
//@返回 成功返回TRUE,否则返回FALSE
//@别名  恢复()
	BOOL Redo(){return XEdit_Redo(m_hEle);}
//@备注 当前行开始
//@参数 hImageAvatar 头像
//@参数 hImageBubble 气泡背景
//@参数 nFlag 标志 @ref chat_flag_
//@别名  添加气泡开始()
	void AddChatBegin(HIMAGE hImageAvatar, HIMAGE hImageBubble, int nFlag){XEdit_AddChatBegin(m_hEle, hImageAvatar, hImageBubble, nFlag);}
//@备注 当前行结束
//@别名  添加气泡结束()
	void AddChatEnd(){XEdit_AddChatEnd(m_hEle);}
//@备注 设置聊天气泡内容缩进
//@参数 nIndentation 缩进值
//@别名  置气泡缩进()
	void SetChatIndentation(int nIndentation){XEdit_SetChatIndentation(m_hEle, nIndentation);}
};
//@备注  继承: CXEdit, CXScrollView,CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  组合框类
class CXComboBox: public CXEdit
{
public:
	CXComboBox(){}
//@备注 创建下拉组合框元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XComboBox_Create(x, y, cx, cy, hParent);return m_hEle;}
//@备注 创建下拉组合框元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
CXComboBox(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XComboBox_Create(x, y, cx, cy, hParent);}
//@备注 设置选择项.  
//@参数 iIndex 项索引.
//@返回 成功返回否则返回FALSE.
//@别名  置选择项()
	BOOL SetSelItem(int iIndex){return XComboBox_SetSelItem(m_hEle, iIndex);}
//@返回 返回数据适配器句柄
//@别名  创建数据适配器()
	HXCGUI CreateAdapter(){return XComboBox_CreateAdapter(m_hEle);}
//@备注 绑定数据适配器.  
//@参数 hAdapter 适配器句柄.
//@别名  绑定数据适配器()
	void BindAdapter(HXCGUI hAdapter){XComboBox_BindAdapter(m_hEle, hAdapter);}
//@备注 获取绑定的数据适配器.  
//@返回 返回数据适配器.
//@别名  取数据适配器()
	HXCGUI GetAdapter(){return XComboBox_GetAdapter(m_hEle);}
//@备注 设置绑定数据适配器字段名.  
//@参数 pName 字段名
//@别名  置绑定名称()
	void SetBindName(const wchar_t* pName){XComboBox_SetBindName(m_hEle, pName);}
//@备注 获取下拉按钮坐标.  
//@参数 pRect 坐标.
//@别名  取下拉按钮坐标()
	void GetButtonRect(RECT* pRect){XComboBox_GetButtonRect(m_hEle, pRect);}
//@备注 设置下拉按钮大小.  
//@参数 size 大小.
//@别名  置下拉按钮大小()
	void SetButtonSize(int size){XComboBox_SetButtonSize(m_hEle, size);}
//@备注 设置下拉列表允许的最大高度, 
//@参数 height 高度, -1自动计算高度
//@别名  置下拉列表高度()
	void SetDropHeight(int height){XComboBox_SetDropHeight(m_hEle, height);}
//@备注 获取下拉列表高度.  
//@返回 下拉列表高度.
//@别名  取下拉列表高度()
	int GetDropHeight(){return XComboBox_GetDropHeight(m_hEle);}
//@备注 设置下拉列表项模板文件
//@参数 pXmlFile 项模板文件.
//@别名  置项模板文件()
	void SetItemTemplateXML(const wchar_t* pXmlFile){XComboBox_SetItemTemplateXML(m_hEle, pXmlFile);}
//@备注 设置下拉列表项模板.  
//@参数 pStringXML 字符串指针.
//@别名  置项模板从字符串()
	void SetItemTemplateXMLFromString(const char* pStringXML){XComboBox_SetItemTemplateXMLFromString(m_hEle, pStringXML);}
//@参数 hTemp 项模板句柄
//@返回 如果成功返回TRUE,否则返回FALSE
//@别名  置项模板()
	BOOL SetItemTemplate(HTEMP hTemp){return XComboBox_SetItemTemplate(m_hEle, hTemp);}
//@备注 是否绘制下拉按钮.  
//@参数 bEnable 是否绘制.
//@别名  启用绘制下拉按钮()
	void EnableDrawButton(BOOL bEnable){XComboBox_EnableDrawButton(m_hEle, bEnable);}
//@备注 启用可编辑显示的文本内容.  
//@参数 bEdit TRUE可编辑,否则相反.
//@别名  启用编辑()
	void EnableEdit(BOOL bEdit){XComboBox_EnableEdit(m_hEle, bEdit);}
//@备注 启用/关闭下拉列表高度固定大小.  
//@参数 bEnable 是否启用
//@别名  启用下拉列表高度固定大小()
	void EnableDropHeightFixed(BOOL bEnable){XComboBox_EnableDropHeightFixed(m_hEle, bEnable);}
//@返回 如果成功返回TRUE,否则返回FALSE
//@别名  弹出下拉列表()
	void PopupDropList(){XComboBox_PopupDropList(m_hEle);}
//@备注 获取组合框下拉列表中选择项索引.  
//@返回 返回项索引.
//@别名  取选择项()
	int GetSelItem(){return XComboBox_GetSelItem(m_hEle);}
//@备注 获取状态.  
//@返回 状态.
//@别名  取状态()
	comboBox_state_ GetState(){return XComboBox_GetState(m_hEle);}
//@参数 pText 
//@返回 返回项索引
//@别名  添加项文本()
	int AddItemText(const wchar_t* pText){return XComboBox_AddItemText(m_hEle, pText);}
//@参数 pName 字段名
//@参数 pText 文本
//@返回 返回项索引
//@别名  添加项文本扩展()
	int AddItemTextEx(const wchar_t* pName, const wchar_t* pText){return XComboBox_AddItemTextEx(m_hEle, pName, pText);}
//@参数 hImage 图片句柄
//@返回 返回项索引
//@别名  添加项图片()
	int AddItemImage(HIMAGE hImage){return XComboBox_AddItemImage(m_hEle, hImage);}
//@参数 pName 字段名
//@参数 hImage 图片句柄
//@返回 返回项索引
//@别名  添加项图片扩展()
	int AddItemImageEx(const wchar_t* pName, HIMAGE hImage){return XComboBox_AddItemImageEx(m_hEle, pName, hImage);}
//@参数 iItem 项索引
//@参数 pText 文本
//@返回 返回项索引
//@别名  插入项文本()
	int InsertItemText(int iItem, const wchar_t* pValue){return XComboBox_InsertItemText(m_hEle, iItem, pValue);}
//@参数 iItem 项索引
//@参数 pName 字段名
//@参数 pText 文本
//@返回 返回项索引
//@别名  插入项文本扩展()
	int InsertItemTextEx(int iItem, const wchar_t* pName, const wchar_t* pValue){return XComboBox_InsertItemTextEx(m_hEle, iItem, pName, pValue);}
//@参数 iItem 项索引
//@参数 hImage 图片句柄
//@返回 返回项索引
//@别名  插入项图片()
	int InsertItemImage(int iItem, HIMAGE hImage){return XComboBox_InsertItemImage(m_hEle, iItem, hImage);}
//@参数 iItem 项索引
//@参数 pName 字段名
//@参数 hImage 图片句柄
//@返回 返回项索引
//@别名  插入项图片扩展()
	int InsertItemImageEx(int iItem, const wchar_t* pName, HIMAGE hImage){return XComboBox_InsertItemImageEx(m_hEle, iItem, pName, hImage);}
//@参数 iItem 项索引
//@参数 iColumn 列索引
//@参数 pText 文本
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项文本()
	BOOL SetItemText(int iItem, int iColumn, const wchar_t* pText){return XComboBox_SetItemText(m_hEle, iItem, iColumn, pText);}
//@参数 iItem 项索引
//@参数 pName 字段名
//@参数 pText 文本
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项文本扩展()
	BOOL SetItemTextEx(int iItem, const wchar_t* pName, const wchar_t* pText){return XComboBox_SetItemTextEx(m_hEle, iItem, pName, pText);}
//@参数 iItem 项索引
//@参数 iColumn 列索引
//@参数 hImage 图片句柄
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项图片()
	BOOL SetItemImage(int iItem, int iColumn, HIMAGE hImage){return XComboBox_SetItemImage(m_hEle, iItem, iColumn, hImage);}
//@参数 iItem 项索引
//@参数 pName 字段名
//@参数 hImage 图片句柄
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项图片扩展()
	BOOL SetItemImageEx(int iItem, const wchar_t* pName, HIMAGE hImage){return XComboBox_SetItemImageEx(m_hEle, iItem, pName, hImage);}
//@参数 iItem 项索引
//@参数 iColumn 列索引
//@参数 nValue 整数值
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项整数值()
	BOOL SetItemInt(int iItem, int iColumn, int nValue){return XComboBox_SetItemInt(m_hEle, iItem, iColumn, nValue);}
//@参数 iItem 项索引
//@参数 pName 字段名
//@参数 nValue 整数值
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项指数值扩展()
	BOOL SetItemIntEx(int iItem, const wchar_t* pName, int nValue){return XComboBox_SetItemIntEx(m_hEle, iItem, pName, nValue);}
//@参数 iItem 项索引
//@参数 iColumn 列索引
//@参数 fFloat 浮点数
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项浮点值()
	BOOL SetItemFloat(int iItem, int iColumn, float fFloat){return XComboBox_SetItemFloat(m_hEle, iItem, iColumn, fFloat);}
//@参数 iItem 项索引
//@参数 pName 字段名
//@参数 fFloat 浮点数
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置项浮点值扩展()
	BOOL SetItemFloatEx(int iItem, const wchar_t* pName, float fFloat){return XComboBox_SetItemFloatEx(m_hEle, iItem, pName, fFloat);}
//@参数 iItem 项索引
//@参数 iColumn 列索引
//@返回 返回文本内容
//@别名  取项文本()
	const wchar_t* GetItemText(int iItem, int iColumn){return XComboBox_GetItemText(m_hEle, iItem, iColumn);}
//@参数 iItem 项索引
//@参数 pName 字段名
//@返回 返回文本内容
//@别名  取项文本扩展()
	const wchar_t* GetItemTextEx(int iItem, const wchar_t* pName){return XComboBox_GetItemTextEx(m_hEle, iItem, pName);}
//@参数 iItem 项索引
//@参数 iColumn 列索引
//@返回 返回图片句柄
//@别名  取项图片()
	HIMAGE GetItemImage(int iItem, int iColumn){return XComboBox_GetItemImage(m_hEle, iItem, iColumn);}
//@参数 iItem 项索引
//@参数 pName 字段名
//@返回 返回图片句柄
//@别名  取项图片扩展()
	HIMAGE GetItemImageEx(int iItem, const wchar_t* pName){return XComboBox_GetItemImageEx(m_hEle, iItem, pName);}
//@参数 iItem 项索引
//@参数 iColumn 列索引
//@参数 pOutValue 接收返回整数值
//@返回 成功返回TRUE,否则返回FALSE
//@别名  取项整数值()
	BOOL GetItemInt(int iItem, int iColumn, int* pOutValue){return XComboBox_GetItemInt(m_hEle, iItem, iColumn, pOutValue);}
//@参数 iItem 项索引
//@参数 pName 字段名
//@参数 pOutValue 接收返回整数值
//@返回 成功返回TRUE,否则返回FALSE
//@别名  取项整数值扩展()
	BOOL GetItemIntEx(int iItem, const wchar_t* pName, int* pOutValue){return XComboBox_GetItemIntEx(m_hEle, iItem, pName, pOutValue);}
//@参数 iItem 项索引
//@参数 iColumn 列索引
//@参数 pOutValue 接收返回浮点值
//@返回 成功返回TRUE,否则返回FALSE
//@别名  取项浮点值()
	BOOL GetItemFloat(int iItem, int iColumn, float* pOutValue){return XComboBox_GetItemFloat(m_hEle, iItem, iColumn, pOutValue);}
//@参数 iItem 项索引
//@参数 pName 字段名
//@参数 pOutValue 接收返回浮点值
//@返回 成功返回TRUE,否则返回FALSE
//@别名  取项浮点值扩展()
	BOOL GetItemFloatEx(int iItem, const wchar_t* pName, float* pOutValue){return XComboBox_GetItemFloatEx(m_hEle, iItem, pName, pOutValue);}
//@参数 iItem 项索引
//@返回 成功返回TRUE,否则返回FALSE
//@别名  删除项()
	BOOL DeleteItem(int iItem){return XComboBox_DeleteItem(m_hEle, iItem);}
//@参数 iItem 项索引
//@参数 nCount 删除数量
//@返回 成功返回TRUE,否则返回FALSE
//@别名  删除项扩展()
	BOOL DeleteItemEx(int iItem, int nCount){return XComboBox_DeleteItemEx(m_hEle, iItem, nCount);}
//@别名  删除项全部()
	void DeleteItemAll(){XComboBox_DeleteItemAll(m_hEle);}
//@别名  删除列全部()
	void DeleteColumnAll(){XComboBox_DeleteColumnAll(m_hEle);}
//@返回 返回项数量
//@别名  取项数量()
	int GetCount(){return XComboBox_GetCount(m_hEle);}
//@返回 返回列数量
//@别名  取列数量()
	int GetCountColumn(){return XComboBox_GetCountColumn(m_hEle);}
};
//@备注  继承: CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  菜单条类
class CXMenuBar: public CXEle
{
public:
	CXMenuBar(){}
//@备注 创建菜单条元素;如果指定了父为窗口,默认调用XWnd_AddMenuBar()函数,将菜单条添加到窗口非客户区.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或U I元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XMenuBar_Create(x, y, cx, cy, hParent);return m_hEle;}
//@备注 创建菜单条元素;如果指定了父为窗口,默认调用XWnd_AddMenuBar()函数,将菜单条添加到窗口非客户区.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或U I元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
CXMenuBar(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XMenuBar_Create(x, y, cx, cy, hParent);}
//@备注 添加弹出菜单按钮.  
//@参数 pText 文本内容.
//@返回 返回菜单按钮索引.
//@别名  添加按钮()
	int AddButton(const wchar_t* pText){return XMenuBar_AddButton(m_hEle, pText);}
//@备注 设置菜单按钮高度.  
//@参数 height 高度.
//@别名  置按钮高度()
	void SetButtonHeight(int height){XMenuBar_SetButtonHeight(m_hEle, height);}
//@备注 获取菜单.  
//@参数 nIndex 菜单条上菜单按钮的索引.
//@返回 返回菜单句柄.
//@别名  取菜单()
	HMENUX GetMenu(int nIndex){return XMenuBar_GetMenu(m_hEle, nIndex);}
//@参数 nIndex 菜单条上菜单按钮的索引
//@返回 返回按钮句柄
//@别名  取菜单按钮()
	HELE GetButton(int nIndex){return XMenuBar_GetButton(m_hEle, nIndex);}
//@备注 删除菜单条上的菜单按钮,同时该按钮下的弹出菜单也被销毁.  
//@参数 nIndex 菜单条按钮索引.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  删除按钮()
	BOOL DeleteButton(int nIndex){return XMenuBar_DeleteButton(m_hEle, nIndex);}
//@备注 根据内容自动调整宽度
//@参数 bEnable 是否启用.
//@别名  启用自动宽度()
	void EnableAutoWidth(BOOL bEnable){XMenuBar_EnableAutoWidth(m_hEle, bEnable);}
};
//@备注  继承: CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  窗格类
class CXPane: public CXEle
{
public:
	CXPane(){}
//@备注 创建窗格元素.  
//@参数 pName 窗格标题.
//@参数 nWidth 宽度.
//@参数 nHeight 高度.
//@参数 hFrameWnd 框架窗口.
//@返回 元素句柄.
//@别名  创建()
	HELE Create(const wchar_t* pName, int nWidth, int nHeight, HWINDOW hFrameWnd=NULL){m_hEle = XPane_Create(pName, nWidth, nHeight, hFrameWnd);return m_hEle;}
//@备注 创建窗格元素.  
//@参数 pName 窗格标题.
//@参数 nWidth 宽度.
//@参数 nHeight 高度.
//@参数 hFrameWnd 框架窗口.
//@返回 元素句柄.
CXPane(const wchar_t* pName, int nWidth, int nHeight, HWINDOW hFrameWnd=NULL){m_hEle = XPane_Create(pName, nWidth, nHeight, hFrameWnd);}
//@备注 设置窗格视图元素.  
//@参数 hView 绑定视图元素.
//@别名  置视图()
	void SetView(HELE hView){XPane_SetView(m_hEle, hView);}
//@备注 设置标题文本.  
//@参数 pTitle 文本内容.
//@别名  置标题()
	void SetTitle(wchar_t* pTitle){XPane_SetTitle(m_hEle, pTitle);}
//@备注 获取标题文本.  
//@返回 返回文本内容
//@别名  取标题()
	const wchar_t* GetTitle(){return XPane_GetTitle(m_hEle);}
//@备注 设置标题栏高度.  
//@参数 nHeight 高度.
//@别名  置标题栏高度()
	void SetCaptionHeight(int nHeight){XPane_SetCaptionHeight(m_hEle, nHeight);}
//@备注 获取标题栏高度.  
//@返回 返回标题栏高度.
//@别名  取标题栏高度()
	int GetCaptionHeight(){return XPane_GetCaptionHeight(m_hEle);}
//@备注 判断窗格是否显示.  
//@返回 如果显示返回TRUE否则返回FALSE.
//@别名  是否显示()
	BOOL IsShowPane(){return XPane_IsShowPane(m_hEle);}
//@备注 判断窗格是否激活, 当为组成员时有效
//@返回 如果为窗格组显示项返回TRUE,否则返回FALSE
//@别名  是否激活()
	BOOL IsGroupActivate(){return XPane_IsGroupActivate(m_hEle);}
//@备注 设置窗格大小.  
//@参数 nWidth 宽度.
//@参数 nHeight 高度.
//@别名  置大小()
	void SetSize(int nWidth, int nHeight){XPane_SetSize(m_hEle, nWidth, nHeight);}
//@备注 获取窗格停靠状态.  
//@返回 返回状态标识 @ref pane_state_.
//@别名  取状态()
	pane_state_ GetState(){return XPane_GetState(m_hEle);}
//@备注 获取窗格视图坐标.  
//@参数 pRect 接收返回的坐标值.
//@别名  取视图坐标()
	void GetViewRect(RECT* pRect){XPane_GetViewRect(m_hEle, pRect);}
//@备注 隐藏窗格.  
//@参数 bGroupDelay 当为窗格组成员时, 延迟处理窗格组成员激活的切换
//@别名  隐藏()
	void HidePane(BOOL bGroupDelay=FALSE){XPane_HidePane(m_hEle, bGroupDelay);}
//@备注 显示窗格.  
//@参数 bGroupActivate 如果是窗格组成员,那么窗格组切换当前窗格为显示状态
//@别名  显示()
	void ShowPane(BOOL bGroupActivate){XPane_ShowPane(m_hEle, bGroupActivate);}
//@备注 窗格停靠到码头.  
//@别名  停靠()
	void DockPane(){XPane_DockPane(m_hEle);}
//@备注 锁定窗格.  
//@别名  锁定()
	void LockPane(){XPane_LockPane(m_hEle);}
//@备注 浮动窗格.  
//@别名  浮动()
	void FloatPane(){XPane_FloatPane(m_hEle);}
//@备注 手动调用该函数绘制窗格, 以便控制绘制顺序.  
//@参数 hDraw 图形绘制句柄.
//@别名  绘制()
	void DrawPane(HDRAW hDraw){XPane_DrawPane(m_hEle, hDraw);}
//@备注 如果窗格是组成员,设置选中当前窗格可见
//@返回 成功返回TRUE,否则返回FALSE
//@别名  置选中()
	BOOL SetSelect(){return XPane_SetSelect(m_hEle);}
};
//@备注  继承: CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  进度条类
class CXProgressBar: public CXEle
{
public:
	CXProgressBar(){}
//@备注 创建进度条元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XProgBar_Create(x, y, cx, cy, hParent);return m_hEle;}
//@备注 创建进度条元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
CXProgressBar(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XProgBar_Create(x, y, cx, cy, hParent);}
//@备注 显示进度值文本
//@参数 bShow 是否启用
//@别名  启用进度文本()
	void EnableShowText(BOOL bShow){XProgBar_EnableShowText(m_hEle, bShow);}
//@备注 缩放进度贴图为当前进度区域(当前进度所显示区域),否则为整体100%进度区域
//@参数 bStretch 缩放
//@返回 如果成功返回TRUE,否则返回FALSE
//@别名  启用缩放()
	void EnableStretch(BOOL bStretch){XProgBar_EnableStretch(m_hEle, bStretch);}
//@备注 设置范围.  
//@参数 range 范围.
//@别名  置范围()
	void SetRange(int range){XProgBar_SetRange(m_hEle, range);}
//@备注 获取范围.  
//@返回 返回范围.
//@别名  取范围()
	int GetRange(){return XProgBar_GetRange(m_hEle);}
//@备注 设置进度贴图.  
//@参数 hImage 图片句柄.
//@别名  置进度图片()
	void SetImageLoad(HIMAGE hImage){XProgBar_SetImageLoad(m_hEle, hImage);}
//@备注 设置位置点.  
//@参数 pos 位置点.
//@别名  置进度()
	void SetPos(int pos){XProgBar_SetPos(m_hEle, pos);}
//@备注 获取当前位置点.  
//@返回 返回当前位置点.
//@别名  取进度()
	int GetPos(){return XProgBar_GetPos(m_hEle);}
//@备注 设置水平或垂直.  
//@参数 bHorizon 水平或垂直.
//@别名  启用水平()
	void EnableHorizon(BOOL bHorizon){XProgBar_EnableHorizon(m_hEle, bHorizon);}
};
//@备注  继承: CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  滚动条类
class CXScrollBar: public CXEle
{
public:
	CXScrollBar(){}
//@备注 创建滚动条元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XSBar_Create(x, y, cx, cy, hParent);return m_hEle;}
//@备注 创建滚动条元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
CXScrollBar(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XSBar_Create(x, y, cx, cy, hParent);}
//@备注 设置滚动范围.  
//@参数 range 范围.
//@别名  置范围()
	void SetRange(int range){XSBar_SetRange(m_hEle, range);}
//@备注 获取滚动范围.  
//@返回 滚动范围.
//@别名  取范围()
	int GetRange(){return XSBar_GetRange(m_hEle);}
//@备注 显示隐藏滚动条上下按钮.  
//@参数 bShow 是否显示.
//@别名  显示上下按钮()
	void ShowButton(BOOL bShow){XSBar_ShowButton(m_hEle, bShow);}
//@备注 设置滑块长度.  
//@参数 length 长度.
//@别名  置滑块长度()
	void SetSliderLength(int length){XSBar_SetSliderLength(m_hEle, length);}
//@备注 设置滑块最小长度.  
//@参数 minLength 长度.
//@别名  置滑块最小长度()
	void SetSliderMinLength(int minLength){XSBar_SetSliderMinLength(m_hEle, minLength);}
//@备注 设置滑块两边的间隔大小.  
//@参数 nPadding 间隔大小.
//@别名  置滑块两边间隔()
	void SetSliderPadding(int nPadding){XSBar_SetSliderPadding(m_hEle, nPadding);}
//@备注 设置水平或者垂直.  
//@参数 bEnable 水平或垂直.
//@返回 如果改变返回TRUE否则返回FALSE.
//@别名  启用水平()
	BOOL EnableHorizon(BOOL bHorizon){return XSBar_EnableHorizon(m_hEle, bHorizon);}
//@备注 获取滑块最大长度.  
//@返回 长度.
//@别名  取滑块最大长度()
	int GetSliderMaxLength(){return XSBar_GetSliderMaxLength(m_hEle);}
//@备注 向上滚动.  
//@返回 成功返回TRUE否则返回FALSE.
//@别名  向上滚动()
	BOOL ScrollUp(){return XSBar_ScrollUp(m_hEle);}
//@备注 向下滚动.  
//@返回 成功返回TRUE否则返回FALSE.
//@别名  向下滚动()
	BOOL ScrollDown(){return XSBar_ScrollDown(m_hEle);}
//@备注 滚动到顶部.  
//@返回 成功返回TRUE否则返回FALSE.
//@别名  滚动到顶部()
	BOOL ScrollTop(){return XSBar_ScrollTop(m_hEle);}
//@备注 滚动到底部.  
//@返回 成功返回TRUE否则返回FALSE.
//@别名  滚动到底部()
	BOOL ScrollBottom(){return XSBar_ScrollBottom(m_hEle);}
//@备注 滚动到指定位置点 ,触发事件 
//@参数 pos 位置点.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  滚动到指定位置()
	BOOL ScrollPos(int pos){return XSBar_ScrollPos(m_hEle, pos);}
//@备注 获取上按钮.  
//@返回 返回按钮句柄.
//@别名  取上按钮()
	HELE GetButtonUp(){return XSBar_GetButtonUp(m_hEle);}
//@备注 获取下按钮.  
//@返回 返回按钮句柄.
//@别名  取下按钮()
	HELE GetButtonDown(){return XSBar_GetButtonDown(m_hEle);}
//@备注 获取滑动按钮.  
//@返回 返回按钮句柄.
//@别名  取滑块()
	HELE GetButtonSlider(){return XSBar_GetButtonSlider(m_hEle);}
};
//@备注  继承: CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  滑动条类
class CXSliderBar: public CXEle
{
public:
	CXSliderBar(){}
//@备注 创建滑动条元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XSliderBar_Create(x, y, cx, cy, hParent);return m_hEle;}
//@备注 创建滑动条元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
CXSliderBar(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XSliderBar_Create(x, y, cx, cy, hParent);}
//@备注 设置滑动范围.  
//@参数 range 范围.
//@别名  置范围()
	void SetRange(int range){XSliderBar_SetRange(m_hEle, range);}
//@备注 获取滚动范围.  
//@返回 返回滚动范围.
//@别名  取范围()
	int GetRange(){return XSliderBar_GetRange(m_hEle);}
//@备注 设置进度贴图.  
//@参数 hImage 图片句柄.
//@别名  置进度图片()
	void SetImageLoad(HIMAGE hImage){XSliderBar_SetImageLoad(m_hEle, hImage);}
//@备注 设置滑块按钮宽度.  
//@参数 width 宽度.
//@别名  置滑块宽度()
	void SetButtonWidth(int width){XSliderBar_SetButtonWidth(m_hEle, width);}
//@备注 设置滑块按钮高度.  
//@参数 height 高度.
//@别名  置滑块高度()
	void SetButtonHeight(int height){XSliderBar_SetButtonHeight(m_hEle, height);}
//@备注 设置当前进度点.  
//@参数 pos 进度点.
//@别名  置当前位置()
	void SetPos(int pos){XSliderBar_SetPos(m_hEle, pos);}
//@备注 获取当前进度点.  
//@返回 返回当前进度点.
//@别名  取当前位置()
	int GetPos(){return XSliderBar_GetPos(m_hEle);}
//@备注 获取滑块按钮.  
//@返回 按钮句柄.
//@别名  取滑块()
	HELE GetButton(){return XSliderBar_GetButton(m_hEle);}
//@备注 设置水平或垂直.  
//@参数 bHorizon 水平或垂直.
//@别名  启用水平()
	void EnableHorizon(BOOL bHorizon){XSliderBar_EnableHorizon(m_hEle, bHorizon);}
};
//@备注  继承: CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  Tab条类
class CXTabBar: public CXEle
{
public:
	CXTabBar(){}
//@备注 创建tabBar元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XTabBar_Create(x, y, cx, cy, hParent);return m_hEle;}
//@备注 创建tabBar元素.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
CXTabBar(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XTabBar_Create(x, y, cx, cy, hParent);}
//@备注 添加一个标签.  
//@参数 pName 标签文本内容.
//@返回 标签索引.
//@别名  添加标签()
	int AddLabel(const wchar_t* pName){return XTabBar_AddLabel(m_hEle, pName);}
//@备注 插入一个标签.  
//@参数 index 插入位置.
//@参数 pName 标签文本内容.
//@返回 标签索引.
//@别名  标签()
	int InsertLabel(int index, const wchar_t* pName){return XTabBar_InsertLabel(m_hEle, index, pName);}
//@参数 iSrc 源位置索引
//@参数 iDest 目标位置索引
//@返回 成功返回TRUE否则FALSE.
//@别名  移动标签()
	BOOL MoveLabel(int iSrc, int iDest){return XTabBar_MoveLabel(m_hEle, iSrc, iDest);}
//@备注 删除一个标签.  
//@参数 index 位置索引.
//@返回 成功返回TRUE否则FALSE.
//@别名  删除标签()
	BOOL DeleteLabel(int index){return XTabBar_DeleteLabel(m_hEle, index);}
//@备注 删除所有标签.  
//@别名  删除全部()
	void DeleteLabelAll(){XTabBar_DeleteLabelAll(m_hEle);}
//@备注 获取标签按钮Button.  
//@参数 index 位置索引.
//@返回 按钮句柄.
//@别名  取标签()
	HELE GetLabel(int index){return XTabBar_GetLabel(m_hEle, index);}
//@备注 获取标签上关闭按钮.  
//@参数 index 位置索引.
//@返回 按钮句柄.
//@别名  取标签上的关闭按钮()
	HELE GetLabelClose(int index){return XTabBar_GetLabelClose(m_hEle, index);}
//@备注 获取左滚动按钮.  
//@返回 返回按钮句柄.
//@别名  取左滚动按钮()
	HELE GetButtonLeft(){return XTabBar_GetButtonLeft(m_hEle);}
//@备注 获取右滚动按钮.  
//@返回 返回按钮句柄.
//@别名  取右滚动按钮()
	HELE GetButtonRight(){return XTabBar_GetButtonRight(m_hEle);}
//@返回 返回按钮句柄.
//@别名  取下拉菜单按钮句柄()
	HELE GetButtonDropMenu(){return XTabBar_GetButtonDropMenu(m_hEle);}
//@备注 获取选择的标签索引.  
//@返回 标签位置索引.
//@别名  取当前选择()
	int GetSelect(){return XTabBar_GetSelect(m_hEle);}
//@备注 获取标签间距, 0没有间距.  
//@返回 标签间隔大小.
//@别名  取间隔()
	int GetLabelSpacing(){return XTabBar_GetLabelSpacing(m_hEle);}
//@备注 获取标签项数量.  
//@返回 标签项数量.
//@别名  取标签数量()
	int GetLabelCount(){return XTabBar_GetLabelCount(m_hEle);}
//@备注 获取标签按钮位置索引.  
//@参数 hLabel 标签按钮句柄.
//@返回 成功返回索引值,否则返回 @ref XC_ID_ERROR.
//@别名  取标签位置索引()
	int GetindexByEle(HELE hLabel){return XTabBar_GetindexByEle(m_hEle, hLabel);}
//@备注 设置标签间距, 0没有间距.  
//@参数 spacing 标签间隔大小.
//@别名  置间隔()
	void SetLabelSpacing(int spacing){XTabBar_SetLabelSpacing(m_hEle, spacing);}
//@备注 设置内容与边框的间隔大小.  
//@参数 left 左边间隔大小.
//@参数 top 上边间隔大小.
//@参数 right 右边间隔大小.
//@参数 bottom 下边间隔大小.
//@别名  置边距()
	void SetPadding(int left, int top, int right, int bottom){XTabBar_SetPadding(m_hEle, left, top, right, bottom);}
//@备注 设置选择标签.  
//@参数 index 标签位置索引.
//@别名  置选择()
	void SetSelect(int index){XTabBar_SetSelect(m_hEle, index);}
//@备注 左按钮滚动.  
//@别名  左滚动()
	void SetUp(){XTabBar_SetUp(m_hEle);}
//@备注 右按钮滚动.  
//@别名  右滚动()
	void SetDown(){XTabBar_SetDown(m_hEle);}
//@备注 平铺标签,每个标签显示相同大小.  
//@参数 bTile 是否启用.
//@别名  启用平铺()
	void EnableTile(BOOL bTile){XTabBar_EnableTile(m_hEle, bTile);}
//@参数 bEnable 是否启用.
//@别名  启用下拉菜单按钮()
	void EnableDropMenu(BOOL bEnable){XTabBar_EnableDropMenu(m_hEle, bEnable);}
//@备注 启用关闭标签功能.  
//@参数 bEnable 是否启用.
//@别名  启用标签带关闭按钮()
	void EnableClose(BOOL bEnable){XTabBar_EnableClose(m_hEle, bEnable);}
//@备注 设置关闭按钮大小.  
//@参数 pSize 大小值, 宽度和高度可以为-1,-1代表默认值.
//@别名  置关闭按钮大小()
	void SetCloseSize(SIZE* pSize){XTabBar_SetCloseSize(m_hEle, pSize);}
//@备注 设置翻滚按钮大小.  
//@参数 pSize 大小值, 宽度和高度可以为-1,-1代表默认值.
//@别名  置滚动按钮大小()
	void SetTurnButtonSize(SIZE* pSize){XTabBar_SetTurnButtonSize(m_hEle, pSize);}
//@备注 设置指定标签为固定宽度.  
//@参数 index 索引.
//@参数 nWidth 宽度, 如果值为-1,那么自动计算宽度.
//@别名  置指定标签固定宽度()
	void SetLabelWidth(int index, int nWidth){XTabBar_SetLabelWidth(m_hEle, index, nWidth);}
//@备注 显示或隐藏指定标签.  
//@参数 index 标签索引.
//@参数 bShow 是否显示.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  显示标签()
	BOOL ShowLabel(int index, BOOL bShow){return XTabBar_ShowLabel(m_hEle, index, bShow);}
};
//@备注  继承: CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  工具条类
class CXToolBar: public CXEle
{
public:
	CXToolBar(){}
//@备注 创建工具条元素;如果指定了父为窗口,默认调用XWnd_AddToolBar()函数,将工具条添加到窗口非客户区.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XToolBar_Create(x, y, cx, cy, hParent);return m_hEle;}
//@备注 创建工具条元素;如果指定了父为窗口,默认调用XWnd_AddToolBar()函数,将工具条添加到窗口非客户区.  
//@参数 x 元素x坐标.
//@参数 y 元素y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父是窗口资源句柄或UI元素资源句柄.如果是窗口资源句柄将被添加到窗口,
//@返回 元素句柄.
CXToolBar(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hEle = XToolBar_Create(x, y, cx, cy, hParent);}
//@备注 插入元素到工具条.  
//@参数 hNewEle 将要插入的元素.
//@参数 index 插入位置索引, (-1)插入末尾..
//@返回 返回插入位置索引.
//@别名  插入元素()
	int InsertEle(HELE hNewEle, int index=-1){return XToolBar_InsertEle(m_hEle, hNewEle, index);}
//@备注 插入分隔符到工具条.  
//@参数 index 插入位置索引, (-1)插入末尾.
//@参数 color 颜色值, 请使用宏: RGBA()
//@返回 返回插入位置索引.
//@别名  插入分割栏()
	int InsertSeparator(int index=-1, COLORREF color=COLORREF_MAKE(128,128,128,255)){return XToolBar_InsertSeparator(m_hEle, index, color);}
//@备注 启用下拉菜单,显示隐藏的项.  
//@参数 bEnable 是否启用.
//@别名  启用下拉菜单()
	void EnableButtonMenu(BOOL bEnable){XToolBar_EnableButtonMenu(m_hEle, bEnable);}
//@备注 获取工具条上指定元素.  
//@参数 index 索引值.
//@返回 返回元素句柄.
//@别名  取元素()
	HELE GetEle(int index){return XToolBar_GetEle(m_hEle, index);}
//@备注 获取左滚动按钮.  
//@返回 返回按钮句柄.
//@别名  取左滚动按钮()
	HELE GetButtonLeft(){return XToolBar_GetButtonLeft(m_hEle);}
//@备注 获取右滚动按钮.  
//@返回 返回按钮句柄.
//@别名  取右滚动按钮()
	HELE GetButtonRight(){return XToolBar_GetButtonRight(m_hEle);}
//@备注 获取菜单按钮.  
//@返回 返回菜单按钮句柄.
//@别名  取菜单按钮()
	HELE GetButtonMenu(){return XToolBar_GetButtonMenu(m_hEle);}
//@备注 设置对象之间的间距.  
//@参数 nSize 间距大小.
//@别名  置间距()
	void SetSpace(int nSize){XToolBar_SetSpace(m_hEle, nSize);}
//@备注 删除元素,并且销毁.  
//@参数 index 索引值.
//@别名  删除元素()
	void DeleteEle(int index){XToolBar_DeleteEle(m_hEle, index);}
//@备注 删除所有元素,并且销毁.  
//@别名  删除全部()
	void DeleteAllEle(){XToolBar_DeleteAllEle(m_hEle);}
};
//@备注  继承: CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  日期时间类
class CXDateTime: public CXEle
{
public:
	CXDateTime(){}
//@备注 创建日期时间元素  
//@参数 x x坐标
//@参数 y y坐标
//@参数 cx 宽度
//@参数 cy 高度
//@参数 hParent 父为窗口句柄或元素句柄.
//@返回 元素句柄.
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, HXCGUI hParent){m_hEle = XDateTime_Create(x, y, cx, cy, hParent);return m_hEle;}
//@备注 创建日期时间元素  
//@参数 x x坐标
//@参数 y y坐标
//@参数 cx 宽度
//@参数 cy 高度
//@参数 hParent 父为窗口句柄或元素句柄.
//@返回 元素句柄.
CXDateTime(int x, int y, int cx, int cy, HXCGUI hParent){m_hEle = XDateTime_Create(x, y, cx, cy, hParent);}
//@备注 设置样式.  
//@参数 nStyle 样式, 0为日期元素,1为时间元素.
//@别名  置样式()
	void SetStyle(int nStyle){XDateTime_SetStyle(m_hEle, nStyle);}
//@备注 获取样式.  
//@返回 元素样式.
//@别名  取样式()
	int GetStyle(){return XDateTime_GetStyle(m_hEle);}
//@备注 切换分割栏为:斜线或横线.  
//@参数 bSlash TRUE:斜线, FALSE:横线.
//@别名  启用分割栏为斜线()
	void EnableSplitSlash(BOOL bSlash){XDateTime_EnableSplitSlash(m_hEle, bSlash);}
//@备注 获取内部按钮元素.  
//@参数 nType 按钮类型, 0:日历下拉按钮, 1:上箭头按钮, 2:下箭头按钮
//@返回 元素样式.
//@别名  取内部按钮()
	HELE GetButton(int nType){return XDateTime_GetButton(m_hEle, nType);}
//@备注 获取被选择文字的背景颜色.  
//@返回 元素样式.
//@别名  取选择日期背景颜色()
	COLORREF GetSelBkColor(){return XDateTime_GetSelBkColor(m_hEle);}
//@备注 设置被选择文字的背景颜色.  
//@参数 crSelectBk 文字被选中背景色, 颜色值, 请使用宏: RGBA()
//@别名  置选择日期背景颜色()
	void SetSelBkColor(COLORREF crSelectBk){XDateTime_SetSelBkColor(m_hEle, crSelectBk);}
//@备注 获取当前日期.  
//@参数 pnYear 年.[OUT]
//@参数 pnMonth 月.[OUT]
//@参数 pnDay 日.[OUT]
//@别名  取当前日期()
	void GetDate(int* pnYear, int* pnMonth, int* pnDay){XDateTime_GetDate(m_hEle, pnYear, pnMonth, pnDay);}
//@备注 设置当前日期.  
//@参数 nYear 年.
//@参数 nMonth 月.
//@参数 nDay 日.
//@别名  置当前日期()
	void SetDate(int nYear, int nMonth, int nDay){XDateTime_SetDate(m_hEle, nYear, nMonth, nDay);}
//@备注 获取当前时间.  
//@参数 pnHour 时.[OUT]
//@参数 pnMinute 分.[OUT]
//@参数 pnSecond 秒.[OUT]
//@别名  取当前时间()
	void GetTime(int* pnHour, int* pnMinute, int* pnSecond){XDateTime_GetTime(m_hEle, pnHour, pnMinute, pnSecond);}
//@备注 设置当前时分秒.  
//@参数 nHour 时.
//@参数 nMinute 分.
//@参数 nSecond 秒.
//@别名  置当前时间()
	void SetTime(int nHour, int nMinute, int nSecond){XDateTime_SetTime(m_hEle, nHour, nMinute, nSecond);}
//@备注 弹出月历卡片
//@别名  弹出()
	void Popup(){XDateTime_Popup(m_hEle);}
};
//@备注  继承: CXEle, CXWidgetUI, CXObjectUI, CXBase
//@别名  月历卡片类
class CXMonthCal: public CXEle
{
public:
	CXMonthCal(){}
//@备注 创建日期时间元素  
//@参数 x x坐标
//@参数 y y坐标
//@参数 cx 宽度
//@参数 cy 高度
//@参数 hParent 父为窗口句柄或元素句柄.
//@返回 元素句柄.
//@别名  创建()
	HELE Create(int x, int y, int cx, int cy, HXCGUI hParent){m_hEle = XMonthCal_Create(x, y, cx, cy, hParent);return m_hEle;}
//@备注 创建日期时间元素  
//@参数 x x坐标
//@参数 y y坐标
//@参数 cx 宽度
//@参数 cy 高度
//@参数 hParent 父为窗口句柄或元素句柄.
//@返回 元素句柄.
CXMonthCal(int x, int y, int cx, int cy, HXCGUI hParent){m_hEle = XMonthCal_Create(x, y, cx, cy, hParent);}
//@备注 获取内部按钮元素.  
//@参数 nType 按钮类型.
//@返回 元素样式.
//@别名  取内部按钮()
	HELE GetButton(monthCal_button_type_ nType){return XMonthCal_GetButton(m_hEle, nType);}
//@备注 设置月历当前年月日.  
//@参数 nYear 年.
//@参数 nMonth 月.
//@参数 nDay 日.
//@别名  置当前日期()
	void SetToday(int nYear, int nMonth, int nDay){XMonthCal_SetToday(m_hEle, nYear, nMonth, nDay);}
//@备注 获取月历当前年月日.  
//@参数 pnYear 年.[INT,OUT]
//@参数 pnMonth 月.[INT,OUT]
//@参数 pnDay 日.[INT,OUT]
//@别名  取当前日期()
	void GetToday(int* pnYear, int* pnMonth, int* pnDay){XMonthCal_GetToday(m_hEle, pnYear, pnMonth, pnDay);}
//@备注 获取月历选中的年月日.  
//@参数 pnYear 年.[INT,OUT]
//@参数 pnMonth 月.[INT,OUT]
//@参数 pnDay 日.[INT,OUT]
//@别名  取选择日期()
	void GetSelDate(int* pnYear, int* pnMonth, int* pnDay){XMonthCal_GetSelDate(m_hEle, pnYear, pnMonth, pnDay);}
//@参数 nFlag 1:周六,周日文字颜色, 2:日期文字的颜色;  其它周文字颜色, 使用元素自身颜色
//@参数 color 颜色值
//@别名  置文本颜色()
	void SetTextColor(int nFlag, COLORREF color){XMonthCal_SetTextColor(m_hEle, nFlag, color);}
};
//@备注  继承: CXWidgetUI, CXObjectUI, CXBase
//@别名  形状对象类
class CXShape: public CXWidgetUI
{
public:
	//@别名  句柄
	HXCGUI m_hShape;
	CXShape(){}
//@备注 从父UI元素或窗口,和父布局对象中移除.  
//@别名  移除()
	void RemoveShape(){XShape_RemoveShape(m_hShape);}
//@备注 获取形状对象Z序.  
//@返回 成功返回索引值,否则返回 XC_ID_ERROR.
//@别名  取Z序()
	int GetZOrder(){return XShape_GetZOrder(m_hShape);}
//@备注 重绘形状对象.  
//@别名  重绘()
	void Redraw(){XShape_Redraw(m_hShape);}
//@备注 获取内容宽度.  
//@返回 返回内容宽度.
//@别名  取宽度()
	int GetWidth(){return XShape_GetWidth(m_hShape);}
//@备注 获取内容高度.  
//@返回 返回内容高度.
//@别名  取高度()
	int GetHeight(){return XShape_GetHeight(m_hShape);}
//@备注 移动位置
//@参数 x x坐标
//@参数 y y坐标
//@别名  置位置()
	void SetPosition(int x, int y){XShape_SetPosition(m_hShape, x, y);}
//@参数 pOutX 返回X坐标
//@参数 pOutY 返回Y坐标
//@别名  取位置()
	void GetPosition(int* pOutX, int* pOutY){XShape_GetPosition(m_hShape, pOutX, pOutY);}
//@参数 nWidth 宽度
//@参数 nHeight 高度
//@别名  置大小()
	void SetSize(int nWidth, int nHeight){XShape_SetSize(m_hShape, nWidth, nHeight);}
//@参数 pOutWidth 返回宽度
//@参数 pOutHeight 返回高度
//@别名  取大小()
	void GetSize(int* pOutWidth, int* pOutHeight){XShape_GetSize(m_hShape, pOutWidth, pOutHeight);}
//@参数 alpha 透明度
//@别名  置透明度()
	void SetAlpha(BYTE alpha){XShape_SetAlpha(m_hShape, alpha);}
//@返回 返回透明度
//@别名  取透明度()
	BYTE GetAlpha(){return XShape_GetAlpha(m_hShape);}
//@备注 获取坐标.  
//@参数 pRect 接收返回坐标.
//@别名  取坐标()
	void GetRect(RECT* pRect){XShape_GetRect(m_hShape, pRect);}
//@备注 设置坐标.  
//@参数 pRect 坐标.
//@别名  置坐标()
	void SetRect(RECT* pRect){XShape_SetRect(m_hShape, pRect);}
//@备注 设置元素坐标,逻辑坐标,包含滚动视图偏移.  
//@参数 pRect 坐标.
//@参数 bRedraw 是否重绘.
//@返回 如果成功返回TRUE, 否则返回FALSE.
//@别名  置逻辑坐标()
	BOOL SetRectLogic(RECT* pRect, BOOL bRedraw){return XShape_SetRectLogic(m_hShape, pRect, bRedraw);}
//@备注 获取元素坐标,逻辑坐标,包含滚动视图偏移.  
//@参数 pRect 坐标.
//@别名  取逻辑坐标()
	void GetRectLogic(RECT* pRect){XShape_GetRectLogic(m_hShape, pRect);}
//@备注 基于窗口客户区坐标.  
//@参数 pRect 坐标.
//@别名  取基于窗口客户区坐标()
	void GetWndClientRect(RECT* pRect){XShape_GetWndClientRect(m_hShape, pRect);}
//@备注 仅计算有效内容, 填充父, 权重依赖父级所以无法计算.  
//@参数 pSize 接收返回内容大小值.
//@别名  取内容大小()
	void GetContentSize(SIZE* pSize){XShape_GetContentSize(m_hShape, pSize);}
//@备注 是否显示布局边界.  
//@参数 bShow 是否显示.
//@别名  显示布局边界()
	void ShowLayout(BOOL bShow){XShape_ShowLayout(m_hShape, bShow);}
//@备注 调整布局.  
//@别名  调整布局()
	void AdjustLayout(){XShape_AdjustLayout(m_hShape);}
//@备注 销毁形状对象.  
//@别名  销毁()
	void Destroy(){XShape_Destroy(m_hShape);}
};
//@备注  继承: CXShape, CXWidgetUI, CXObjectUI, CXBase
//@别名  形状文本类
class CXShapeText: public CXShape
{
public:
	CXShapeText(){}
//@备注 创建形状对象文本.  
//@参数 x X坐标.
//@参数 y Y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 pName 文本内容.
//@参数 hParent 父对象句柄.
//@返回 返回文本块句柄.
//@别名  创建()
	HXCGUI Create(int x, int y, int cx, int cy, const wchar_t* pName, HXCGUI hParent=NULL){m_hShape = XShapeText_Create(x, y, cx, cy, pName, hParent);return m_hShape;}
//@备注 创建形状对象文本.  
//@参数 x X坐标.
//@参数 y Y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 pName 文本内容.
//@参数 hParent 父对象句柄.
//@返回 返回文本块句柄.
CXShapeText(int x, int y, int cx, int cy, const wchar_t* pName, HXCGUI hParent=NULL){m_hShape = XShapeText_Create(x, y, cx, cy, pName, hParent);}
//@备注 设置文本内容.  
//@参数 pName 文本内容.
//@别名  置文本()
	void SetText(const wchar_t* pName){XShapeText_SetText(m_hShape, pName);}
//@备注 获取文本内容.  
//@别名  取文本()
	const wchar_t* GetText(){return XShapeText_GetText(m_hShape);}
//@备注 获取文本长度.  
//@返回 文本长度.
//@别名  取文本长度()
	int GetTextLength(){return XShapeText_GetTextLength(m_hShape);}
//@备注 设置字体.  
//@参数 hFontx 字体句柄.
//@别名  置字体()
	void SetFont(HFONTX hFontx){XShapeText_SetFont(m_hShape, hFontx);}
//@备注 获取字体.  
//@返回 返回字体句柄.
//@别名  取字体()
	HFONTX GetFont(){return XShapeText_GetFont(m_hShape);}
//@备注 设置文本颜色.  
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置文本颜色()
	void SetTextColor(COLORREF color){XShapeText_SetTextColor(m_hShape, color);}
//@备注 获取文本颜色.  
//@返回 颜色值.
//@别名  取文本颜色()
	COLORREF GetTextColor(){return XShapeText_GetTextColor(m_hShape);}
//@备注 设置文本对齐方式.  
//@参数 align 文本对齐方式; @ref textFormatFlag_ .
//@别名  置文本对齐()
	void SetTextAlign(int align){XShapeText_SetTextAlign(m_hShape, align);}
//@备注 设置内容偏移.  
//@参数 x X坐标.
//@参数 y Y坐标.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置偏移()
	void SetOffset(int x, int y){XShapeText_SetOffset(m_hShape, x, y);}
};
//@备注  继承: CXShape, CXWidgetUI, CXObjectUI, CXBase
//@别名  形状图片类
class CXShapePicture: public CXShape
{
public:
	CXShapePicture(){}
//@备注 创建形状对象-图片.  
//@参数 x x坐标.
//@参数 y y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父对象句柄.
//@返回 成功返回图片对象句柄,否则返回NULL.
//@别名  创建()
	HXCGUI Create(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hShape = XShapePic_Create(x, y, cx, cy, hParent);return m_hShape;}
//@备注 创建形状对象-图片.  
//@参数 x x坐标.
//@参数 y y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父对象句柄.
//@返回 成功返回图片对象句柄,否则返回NULL.
CXShapePicture(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hShape = XShapePic_Create(x, y, cx, cy, hParent);}
//@备注 设置图片.  
//@参数 hImage 图片句柄.
//@别名  置图片()
	void SetImage(HIMAGE hImage){XShapePic_SetImage(m_hShape, hImage);}
//@备注 获取图片句柄  
//@返回 返回图片句柄.
//@别名  取图片()
	HIMAGE GetImage(){return XShapePic_GetImage(m_hShape);}
};
//@备注  继承: CXShape, CXWidgetUI, CXObjectUI, CXBase
//@别名  形状GIF类
class CXShapeGif: public CXShape
{
public:
	CXShapeGif(){}
//@备注 创建形状对象GIF.  
//@参数 x X坐标.
//@参数 y Y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父对象句柄.
//@返回 成功返回形状对象GIF句柄,否则返回NULL.
//@别名  创建()
	HXCGUI Create(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hShape = XShapeGif_Create(x, y, cx, cy, hParent);return m_hShape;}
//@备注 创建形状对象GIF.  
//@参数 x X坐标.
//@参数 y Y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父对象句柄.
//@返回 成功返回形状对象GIF句柄,否则返回NULL.
CXShapeGif(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hShape = XShapeGif_Create(x, y, cx, cy, hParent);}
//@备注 设置GIF图片.  
//@参数 hImage 图片句柄.
//@别名  置图片()
	void SetImage(HIMAGE hImage){XShapeGif_SetImage(m_hShape, hImage);}
//@备注 获取图片句柄.  
//@返回 返回图片句柄.
//@别名  取图片()
	HIMAGE GetImage(){return XShapeGif_GetImage(m_hShape);}
};
//@备注  继承: CXShape, CXWidgetUI, CXObjectUI, CXBase
//@别名  形状矩形类
class CXShapeRect: public CXShape
{
public:
	CXShapeRect(){}
//@备注 创建矩形形状对象.  
//@参数 x X坐标.
//@参数 y Y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父对象句柄.
//@返回 返回句柄.
//@别名  创建()
	HXCGUI Create(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hShape = XShapeRect_Create(x, y, cx, cy, hParent);return m_hShape;}
//@备注 创建矩形形状对象.  
//@参数 x X坐标.
//@参数 y Y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父对象句柄.
//@返回 返回句柄.
CXShapeRect(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hShape = XShapeRect_Create(x, y, cx, cy, hParent);}
//@备注 设置边框颜色.  
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置边框色()
	void SetBorderColor(COLORREF color){XShapeRect_SetBorderColor(m_hShape, color);}
//@备注 设置填充颜色.  
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置填充色()
	void SetFillColor(COLORREF color){XShapeRect_SetFillColor(m_hShape, color);}
//@备注 设置圆角大小.  
//@参数 nWidth 圆角宽度.
//@参数 nHeight 圆角高度.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置圆角大小()
	void SetRoundAngle(int nWidth, int nHeight){XShapeRect_SetRoundAngle(m_hShape, nWidth, nHeight);}
//@备注 获取圆角大小.  
//@参数 pWidth 圆角宽度.
//@参数 pHeight 圆角高度.
//@别名  取圆角大小()
	void GetRoundAngle(int* pWidth, int* pHeight){XShapeRect_GetRoundAngle(m_hShape, pWidth, pHeight);}
//@备注 启用绘制矩形边框.  
//@参数 bEnable 是否启用.
//@别名  启用边框()
	void EnableBorder(BOOL bEnable){XShapeRect_EnableBorder(m_hShape, bEnable);}
//@备注 启用填充矩形.  
//@参数 bEnable 是否启用.
//@别名  启用填充()
	void EnableFill(BOOL bEnable){XShapeRect_EnableFill(m_hShape, bEnable);}
//@备注 启用圆角.  
//@参数 bEnable 是否启用.
//@别名  启用圆角()
	void EnableRoundAngle(BOOL bEnable){XShapeRect_EnableRoundAngle(m_hShape, bEnable);}
};
//@备注  继承: CXShape, CXWidgetUI, CXObjectUI, CXBase
//@别名  形状圆类
class CXShapeEllipse: public CXShape
{
public:
	CXShapeEllipse(){}
//@备注 创建圆形形状对象.  
//@参数 x X坐标.
//@参数 y Y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父对象句柄.
//@返回 返回句柄.
//@别名  创建()
	HXCGUI Create(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hShape = XShapeEllipse_Create(x, y, cx, cy, hParent);return m_hShape;}
//@备注 创建圆形形状对象.  
//@参数 x X坐标.
//@参数 y Y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 hParent 父对象句柄.
//@返回 返回句柄.
CXShapeEllipse(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hShape = XShapeEllipse_Create(x, y, cx, cy, hParent);}
//@备注 设置边框颜色.  
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置边框色()
	void SetBorderColor(COLORREF color){XShapeEllipse_SetBorderColor(m_hShape, color);}
//@备注 设置填充颜色.  
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置填充色()
	void SetFillColor(COLORREF color){XShapeEllipse_SetFillColor(m_hShape, color);}
//@备注 启用绘制圆边框.  
//@参数 bEnable 是否启用.
//@别名  启用边框()
	void EnableBorder(BOOL bEnable){XShapeEllipse_EnableBorder(m_hShape, bEnable);}
//@备注 启用填充圆.  
//@参数 bEnable 是否启用.
//@别名  启用填充()
	void EnableFill(BOOL bEnable){XShapeEllipse_EnableFill(m_hShape, bEnable);}
};
//@备注  继承: CXShape, CXWidgetUI, CXObjectUI, CXBase
//@别名  形状组框类
class CXShapeGroupBox: public CXShape
{
public:
	CXShapeGroupBox(){}
//@备注 创建组框形状对象.  
//@参数 x X坐标.
//@参数 y Y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 pName 名称.
//@参数 hParent 父对象句柄.
//@返回 返回句柄.
//@别名  创建()
	HXCGUI Create(int x, int y, int cx, int cy, const wchar_t* pName, HXCGUI hParent=NULL){m_hShape = XShapeGroupBox_Create(x, y, cx, cy, pName, hParent);return m_hShape;}
//@备注 创建组框形状对象.  
//@参数 x X坐标.
//@参数 y Y坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@参数 pName 名称.
//@参数 hParent 父对象句柄.
//@返回 返回句柄.
CXShapeGroupBox(int x, int y, int cx, int cy, const wchar_t* pName, HXCGUI hParent=NULL){m_hShape = XShapeGroupBox_Create(x, y, cx, cy, pName, hParent);}
//@备注 设置边框颜色.  
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置边框颜色()
	void SetBorderColor(COLORREF color){XShapeGroupBox_SetBorderColor(m_hShape, color);}
//@备注 设置文本颜色.  
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置文本颜色()
	void SetTextColor(COLORREF color){XShapeGroupBox_SetTextColor(m_hShape, color);}
//@备注 设置字体.  
//@参数 hFontX 炫彩字体.
//@别名  置字体()
	void SetFontX(HFONTX hFontX){XShapeGroupBox_SetFontX(m_hShape, hFontX);}
//@备注 设置文本偏移量.  
//@参数 offsetX 水平偏移.
//@参数 offsetY 垂直偏移.
//@别名  置文本偏移()
	void SetTextOffset(int offsetX, int offsetY){XShapeGroupBox_SetTextOffset(m_hShape, offsetX, offsetY);}
//@备注 设置圆角大小.  
//@参数 nWidth 圆角宽度.
//@参数 nHeight 圆角高度.
//@别名  置圆角大小()
	void SetRoundAngle(int nWidth, int nHeight){XShapeGroupBox_SetRoundAngle(m_hShape, nWidth, nHeight);}
//@备注 设置文本内容.  
//@参数 pText 文本内容.
//@别名  置文本()
	void SetText(const wchar_t* pText){XShapeGroupBox_SetText(m_hShape, pText);}
//@备注 获取文本偏移量.  
//@参数 pOffsetX X坐标偏移量.
//@参数 pOffsetY Y坐标偏移量.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  取文本偏移()
	void GetTextOffset(int* pOffsetX, int* pOffsetY){XShapeGroupBox_GetTextOffset(m_hShape, pOffsetX, pOffsetY);}
//@备注 获取圆角大小.  
//@参数 pWidth 返回圆角宽度.
//@参数 pHeight 返回圆角高度.
//@别名  取圆角大小()
	void GetRoundAngle(int* pWidth, int* pHeight){XShapeGroupBox_GetRoundAngle(m_hShape, pWidth, pHeight);}
//@备注 启用圆角.  
//@参数 bEnable 是否启用.
//@别名  启用圆角()
	void EnableRoundAngle(BOOL bEnable){XShapeGroupBox_EnableRoundAngle(m_hShape, bEnable);}
};
//@备注  继承: CXShape, CXWidgetUI, CXObjectUI, CXBase
//@别名  表格类
class CXTable: public CXShape
{
public:
	CXTable(){}
//@参数 x 按钮x坐标
//@参数 y 按钮y坐标
//@参数 cx 宽度
//@参数 cy 高度
//@参数 hParent 父为窗口句柄或元素句柄.
//@返回 表格句柄.
//@别名  创建()
	HXCGUI Create(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hShape = XTable_Create(x, y, cx, cy, hParent);return m_hShape;}
//@参数 x 按钮x坐标
//@参数 y 按钮y坐标
//@参数 cx 宽度
//@参数 cy 高度
//@参数 hParent 父为窗口句柄或元素句柄.
//@返回 表格句柄.
CXTable(int x, int y, int cx, int cy, HXCGUI hParent=NULL){m_hShape = XTable_Create(x, y, cx, cy, hParent);}
//@参数 nRow 行数量
//@参数 nCol 列数量
//@别名  重置()
	void Reset(int nRow, int nCol){XTable_Reset(m_hShape, nRow, nCol);}
//@参数 iRow 行索引
//@参数 iCol 列索引
//@参数 count 数量
//@别名  组合行()
	void ComboRow(int iRow, int iCol, int count){XTable_ComboRow(m_hShape, iRow, iCol, count);}
//@参数 iRow 行索引
//@参数 iCol 列索引
//@参数 count 数量
//@别名  组合列()
	void ComboCol(int iRow, int iCol, int count){XTable_ComboCol(m_hShape, iRow, iCol, count);}
//@参数 iCol 列索引
//@参数 width 宽度
//@别名  置列宽()
	void SetColWidth(int iCol, int width){XTable_SetColWidth(m_hShape, iCol, width);}
//@参数 iRow 行索引
//@参数 height 高度
//@别名  置行高()
	void SetRowHeight(int iRow, int height){XTable_SetRowHeight(m_hShape, iRow, height);}
//@参数 color 颜色
//@别名  置边颜色()
	void SetBorderColor(COLORREF color){XTable_SetBorderColor(m_hShape, color);}
//@参数 color 颜色
//@别名  置文本颜色()
	void SetTextColor(COLORREF color){XTable_SetTextColor(m_hShape, color);}
//@参数 hFont 字体句柄
//@别名  置字体()
	void SetFont(HFONTX hFont){XTable_SetFont(m_hShape, hFont);}
//@参数 leftSize 内填充大小
//@参数 topSize 内填充大小
//@参数 rightSize 内填充大小
//@参数 bottomSize 内填充大小
//@别名  置项内填充()
	void SetItemPadding(int leftSize, int topSize, int rightSize, int bottomSize){XTable_SetItemPadding(m_hShape, leftSize, topSize, rightSize, bottomSize);}
//@参数 iRow 行索引
//@参数 iCol 列索引
//@参数 pText 文本
//@别名  置项文本()
	void SetItemText(int iRow, int iCol, const wchar_t* pText){XTable_SetItemText(m_hShape, iRow, iCol, pText);}
//@参数 iRow 行索引
//@参数 iCol 列索引
//@参数 hFont 字体句柄
//@别名  置项字体()
	void SetItemFont(int iRow, int iCol, HFONTX hFont){XTable_SetItemFont(m_hShape, iRow, iCol, hFont);}
//@参数 iRow 行索引
//@参数 iCol 列索引
//@参数 nAlign 对齐方式  @ref textFormatFlag_
//@别名  置项文本对齐()
	void SetItemTextAlign(int iRow, int iCol, int nAlign){XTable_SetItemTextAlign(m_hShape, iRow, iCol, nAlign);}
//@参数 iRow 行索引
//@参数 iCol 列索引
//@参数 color 颜色
//@参数 bColor 是否使用
//@别名  置项文本色()
	void SetItemTextColor(int iRow, int iCol, COLORREF color, BOOL bColor){XTable_SetItemTextColor(m_hShape, iRow, iCol, color, bColor);}
//@参数 iRow 行索引
//@参数 iCol 列索引
//@参数 color 颜色
//@参数 bColor 是否使用
//@别名  置项背景色()
	void SetItemBkColor(int iRow, int iCol, COLORREF color, BOOL bColor){XTable_SetItemBkColor(m_hShape, iRow, iCol, color, bColor);}
//@参数 iRow1 行索引1
//@参数 iCol1 列索引1
//@参数 iRow2 行索引2
//@参数 iCol2 列索引2
//@参数 nFlag 标识  @ref  table_line_flag_
//@参数 color 颜色
//@别名  置项线()
	void SetItemLine(int iRow1, int iCol1, int iRow2, int iCol2, int nFlag, COLORREF color){XTable_SetItemLine(m_hShape, iRow1, iCol1, iRow2, iCol2, nFlag, color);}
//@参数 iRow 行索引
//@参数 iCol 列索引
//@参数 flag 标识   @ref table_flag_
//@别名  置项标识()
	void SetItemFlag(int iRow, int iCol, int flag){XTable_SetItemFlag(m_hShape, iRow, iCol, flag);}
//@参数 iRow 行索引
//@参数 iCol 列索引
//@参数 pRect 接收返回坐标
//@返回 成功返回TRUE,否则返回FALSE
//@别名  取项坐标()
	BOOL GetItemRect(int iRow, int iCol, RECT* pRect){return XTable_GetItemRect(m_hShape, iRow, iCol, pRect);}
};
//@备注  继承: CXBase
//@别名  数据适配器类
class CXAdapter: public CXBase
{
public:
	//@别名  句柄
	HXCGUI m_hAdapter;
	CXAdapter(){}
//@返回 返回当前引用计数
//@别名  增加引用计数()
	int AddRef(){return XAd_AddRef(m_hAdapter);}
//@返回 返回当前引用计数
//@别名  释放引用计数()
	int Release(){return XAd_Release(m_hAdapter);}
//@返回 返回当前引用计数
//@别名  取引用计数()
	int GetRefCount(){return XAd_GetRefCount(m_hAdapter);}
//@备注 数据适配器销毁 
//@别名  销毁()
	void Destroy(){XAd_Destroy(m_hAdapter);}
//@参数 bEnable 是否启用
//@别名  启用自动销毁()
	void EnableAutoDestroy(BOOL bEnable){XAd_EnableAutoDestroy(m_hAdapter, bEnable);}
};
//@备注  继承: CXAdapter, CXBase
//@别名  数据适配器列表视图类
class CXAdapterListView: public CXAdapter
{
public:
	CXAdapterListView(){}
//@备注 创建列表视元素数据适配器.  
//@返回 返回数据适配器句柄.
//@别名  创建()
	HXCGUI Create(){m_hAdapter = XAdListView_Create();return m_hAdapter;}
//@备注 组操作,添加数据列.  
//@参数 pName 字段名称.
//@返回 返回列索引.
//@别名  组添加列()
	int Group_AddColumn(const wchar_t* pName){return XAdListView_Group_AddColumn(m_hAdapter, pName);}
//@备注 组操作,添加组,数据默认填充到第一列.  
//@参数 pValue 值.
//@参数 iPos 插入位置, -1添加到末尾
//@返回 返回组索引.
//@别名  添加组文本()
	int Group_AddItemText(const wchar_t* pValue, int iPos=-1){return XAdListView_Group_AddItemText(m_hAdapter, pValue, iPos);}
//@备注 组操作,添加组,数据填充指定列.  
//@参数 pName 字段名称.
//@参数 pValue 值.
//@参数 iPos 插入位置, -1添加到末尾
//@返回 返回组索引.
//@别名  添加组文本扩展()
	int Group_AddItemTextEx(const wchar_t* pName, const wchar_t* pValue, int iPos=-1){return XAdListView_Group_AddItemTextEx(m_hAdapter, pName, pValue, iPos);}
//@备注 组操作,添加组,数据默认填充第一列.  
//@参数 hImage 图片句柄.
//@参数 iPos 插入位置, -1添加到末尾
//@返回 返回组索引.
//@别名  添加组图片()
	int Group_AddItemImage(HIMAGE hImage, int iPos=-1){return XAdListView_Group_AddItemImage(m_hAdapter, hImage, iPos);}
//@备注 组操作,添加组,数据填充指定列.  
//@参数 pName 字段名称.
//@参数 hImage 图片句柄.
//@参数 iPos 插入位置, -1添加到末尾
//@返回 返回组索引.
//@别名  添加组图片扩展()
	int Group_AddItemImageEx(const wchar_t* pName, HIMAGE hImage, int iPos=-1){return XAdListView_Group_AddItemImageEx(m_hAdapter, pName, hImage, iPos);}
//@备注 组操作,设置指定项数据.  
//@参数 iGroup 组索引.
//@参数 iColumn 列索引.
//@参数 pValue 值.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  组设置文本()
	BOOL Group_SetText(int iGroup, int iColumn, const wchar_t* pValue){return XAdListView_Group_SetText(m_hAdapter, iGroup, iColumn, pValue);}
//@备注 组操作,设置指定项数据.  
//@参数 iGroup 组索引.
//@参数 pName 字段名.
//@参数 pValue 值.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  组设置文本扩展()
	BOOL Group_SetTextEx(int iGroup, const wchar_t* pName, const wchar_t* pValue){return XAdListView_Group_SetTextEx(m_hAdapter, iGroup, pName, pValue);}
//@备注 组操作,设置指定项数据.  
//@参数 iGroup 组索引.
//@参数 iColumn 列索引.
//@参数 hImage 图片句柄.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  组设置图片()
	BOOL Group_SetImage(int iGroup, int iColumn, HIMAGE hImage){return XAdListView_Group_SetImage(m_hAdapter, iGroup, iColumn, hImage);}
//@备注 组操作,设置指定项数据.  
//@参数 iGroup 组索引.
//@参数 pName 字段名.
//@参数 hImage 图片句柄.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  组设置图片扩展()
	BOOL Group_SetImageEx(int iGroup, const wchar_t* pName, HIMAGE hImage){return XAdListView_Group_SetImageEx(m_hAdapter, iGroup, pName, hImage);}
//@参数 iGroup 组索引
//@参数 iColumn 列索引
//@返回 返回文本内容
//@别名  组取文本()
	const wchar_t* Group_GetText(int iGroup, int iColumn){return XAdListView_Group_GetText(m_hAdapter, iGroup, iColumn);}
//@参数 iGroup 组索引
//@参数 pName 字段名称
//@返回 返回文本内容
//@别名  组取文本扩展()
	const wchar_t* Group_GetTextEx(int iGroup, const wchar_t* pName){return XAdListView_Group_GetTextEx(m_hAdapter, iGroup, pName);}
//@参数 iGroup 组索引
//@参数 iColumn 列索引
//@返回 返回图片句柄
//@别名  组取图片()
	HIMAGE Group_GetImage(int iGroup, int iColumn){return XAdListView_Group_GetImage(m_hAdapter, iGroup, iColumn);}
//@参数 iGroup 组索引
//@参数 pName 字段名称
//@返回 返回图片句柄
//@别名  组取图片扩展()
	HIMAGE Group_GetImageEx(int iGroup, const wchar_t* pName){return XAdListView_Group_GetImageEx(m_hAdapter, iGroup, pName);}
//@备注 项操作,添加列.  
//@参数 pName 字段名称.
//@返回 返回列索引.
//@别名  项添加列()
	int Item_AddColumn(const wchar_t* pName){return XAdListView_Item_AddColumn(m_hAdapter, pName);}
//@备注 组操作,获取组数量.  
//@返回 返回组数量.
//@别名  取组数量()
	int Group_GetCount(){return XAdListView_Group_GetCount(m_hAdapter);}
//@备注 项操作,获取指定组中项数量.  
//@参数 iGroup 组索引.
//@返回 成功返回项数量,否则返回 @ref XC_ID_ERROR.
//@别名  取组中项数量()
	int Item_GetCount(int iGroup){return XAdListView_Item_GetCount(m_hAdapter, iGroup);}
//@备注 项操作,添加项.  
//@参数 iGroup 组索引.
//@参数 pValue 值.
//@参数 iPos 插入位置, -1添加到末尾
//@返回 返回项索引.
//@别名  添加项文本()
	int Item_AddItemText(int iGroup, const wchar_t* pValue, int iPos=-1){return XAdListView_Item_AddItemText(m_hAdapter, iGroup, pValue, iPos);}
//@备注 项操作,添加项,数据填充指定列.  
//@参数 iGroup 组索引.
//@参数 pName 字段名称.
//@参数 pValue 值.
//@参数 iPos 插入位置, -1添加到末尾
//@返回 返回项索引.
//@别名  添加项文本扩展()
	int Item_AddItemTextEx(int iGroup, const wchar_t* pName, const wchar_t* pValue, int iPos=-1){return XAdListView_Item_AddItemTextEx(m_hAdapter, iGroup, pName, pValue, iPos);}
//@备注 项操作,添加项.  
//@参数 iGroup 组索引.
//@参数 hImage 图片句柄.
//@参数 iPos 插入位置, -1添加到末尾
//@返回 返回项索引.
//@别名  添加项图片()
	int Item_AddItemImage(int iGroup, HIMAGE hImage, int iPos=-1){return XAdListView_Item_AddItemImage(m_hAdapter, iGroup, hImage, iPos);}
//@备注 项操作,添加项,填充指定列数据.  
//@参数 iGroup 组索引.
//@参数 pName 字段名称.
//@参数 hImage 图片句柄.
//@参数 iPos 插入位置, -1添加到末尾
//@返回 返回项索引.
//@别名  添加项图片扩展()
	int Item_AddItemImageEx(int iGroup, const wchar_t* pName, HIMAGE hImage, int iPos=-1){return XAdListView_Item_AddItemImageEx(m_hAdapter, iGroup, pName, hImage, iPos);}
//@备注 删除组,自动删除子项.  
//@参数 iGroup 组索引.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  组删除项()
	BOOL Group_DeleteItem(int iGroup){return XAdListView_Group_DeleteItem(m_hAdapter, iGroup);}
//@备注 删除指定组的所有子项.  
//@参数 iGroup 组索引.
//@别名  删除全部子项()
	void Group_DeleteAllChildItem(int iGroup){XAdListView_Group_DeleteAllChildItem(m_hAdapter, iGroup);}
//@备注 删除项.  
//@参数 iGroup 组索引.
//@参数 iItem 项索引.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  删除项()
	BOOL Item_DeleteItem(int iGroup, int iItem){return XAdListView_Item_DeleteItem(m_hAdapter, iGroup, iItem);}
//@备注 删除所有(组,项,列).  
//@别名  删除全部()
	void DeleteAll(){XAdListView_DeleteAll(m_hAdapter);}
//@备注 删除所有的组.  
//@别名  删除全部组()
	void DeleteAllGroup(){XAdListView_DeleteAllGroup(m_hAdapter);}
//@备注 删除所有的项.  
//@别名  删除全部项()
	void DeleteAllItem(){XAdListView_DeleteAllItem(m_hAdapter);}
//@备注 删除组的列.  
//@参数 iColumn 列索引.
//@别名  组删除列()
	void DeleteColumnGroup(int iColumn){XAdListView_DeleteColumnGroup(m_hAdapter, iColumn);}
//@备注 删除项的列.  
//@参数 iColumn 列索引.
//@别名  项删除列()
	void DeleteColumnItem(int iColumn){XAdListView_DeleteColumnItem(m_hAdapter, iColumn);}
//@备注 项操作,获取项文本内容.  
//@参数 iGroup 组索引.
//@参数 iItem 项索引.
//@参数 iColumn 列索引.
//@返回 返回文本内容
//@别名  项取文本()
	const wchar_t* Item_GetText(int iGroup, int iItem, int iColumn){return XAdListView_Item_GetText(m_hAdapter, iGroup, iItem, iColumn);}
//@备注 项操作,获取项文本内容.  
//@参数 iGroup 组索引.
//@参数 iItem 项索引.
//@参数 pName 字段名称.
//@返回 返回文本内容
//@别名  项取文本扩展()
	const wchar_t* Item_GetTextEx(int iGroup, int iItem, const wchar_t* pName){return XAdListView_Item_GetTextEx(m_hAdapter, iGroup, iItem, pName);}
//@备注 项操作,获取项图片句柄.  
//@参数 iGroup 组索引.
//@参数 iItem 项索引.
//@参数 iColumn 列索引.
//@返回 返回图片句柄.
//@别名  项取图片()
	HIMAGE Item_GetImage(int iGroup, int iItem, int iColumn){return XAdListView_Item_GetImage(m_hAdapter, iGroup, iItem, iColumn);}
//@备注 项操作,获取项图片句柄.  
//@参数 iGroup 组索引.
//@参数 iItem 项索引.
//@参数 pName 字段称.
//@返回 返回图片句柄.
//@别名  项取图片扩展()
	HIMAGE Item_GetImageEx(int iGroup, int iItem, const wchar_t* pName){return XAdListView_Item_GetImageEx(m_hAdapter, iGroup, iItem, pName);}
//@备注 项操作,数据填充指定列.  
//@参数 iGroup 组索引.
//@参数 iItem 项索引.
//@参数 iColumn 列索引.
//@参数 pValue 值.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  项置文本()
	BOOL Item_SetText(int iGroup, int iItem, int iColumn, const wchar_t* pValue){return XAdListView_Item_SetText(m_hAdapter, iGroup, iItem, iColumn, pValue);}
//@备注 项操作,数据填充指定列.  
//@参数 iGroup 组索引.
//@参数 iItem 项索引.
//@参数 pName 字段称.
//@参数 pValue 值.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  项置文本扩展()
	BOOL Item_SetTextEx(int iGroup, int iItem, const wchar_t* pName, const wchar_t* pValue){return XAdListView_Item_SetTextEx(m_hAdapter, iGroup, iItem, pName, pValue);}
//@备注 项操作,数据填充指定列.  
//@参数 iGroup 组索引.
//@参数 iItem 项索引.
//@参数 iColumn 列索引.
//@参数 hImage 图片句柄.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  项置图片()
	BOOL Item_SetImage(int iGroup, int iItem, int iColumn, HIMAGE hImage){return XAdListView_Item_SetImage(m_hAdapter, iGroup, iItem, iColumn, hImage);}
//@备注 项操作,数据填充指定列.  
//@参数 iGroup 组索引.
//@参数 iItem 项索引.
//@参数 pName 字段称.
//@参数 hImage 图片句柄.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  项置图片扩展()
	BOOL Item_SetImageEx(int iGroup, int iItem, const wchar_t* pName, HIMAGE hImage){return XAdListView_Item_SetImageEx(m_hAdapter, iGroup, iItem, pName, hImage);}
};
//@备注  继承: CXAdapter, CXBase
//@别名  数据适配器表格类
class CXAdapterTable: public CXAdapter
{
public:
	CXAdapterTable(){}
//@备注 创建列表框元素数据适配器.  
//@返回 返回数据适配器句柄.
//@别名  创建()
	HXCGUI Create(){m_hAdapter = XAdTable_Create();return m_hAdapter;}
//@备注 对内容进行排序.  
//@参数 iColumn 要排序的列索引。
//@参数 bAscending 是否按照升序方式排序.
//@别名  排序()
	void Sort(int iColumn, BOOL bAscending){XAdTable_Sort(m_hAdapter, iColumn, bAscending);}
//@备注 获取项数据类型.  
//@参数 iItem 项索引.
//@参数 iColumn 列索引.
//@返回 返还项数据类型 @ref adapter_date_type_ .
//@别名  取项数据类型()
	adapter_date_type_ GetItemDataType(int iItem, int iColumn){return XAdTable_GetItemDataType(m_hAdapter, iItem, iColumn);}
//@备注 获取项数据类型.  
//@参数 iItem 项索引.
//@参数 pName 字段称.
//@返回 返还项数据类型 @ref adapter_date_type_ .
//@别名  取项数据类型扩展()
	adapter_date_type_ GetItemDataTypeEx(int iItem, const wchar_t* pName){return XAdTable_GetItemDataTypeEx(m_hAdapter, iItem, pName);}
//@备注 添加数据列.  
//@参数 pName 字段称.
//@返回 返回列索引.
//@别名  添加列()
	int AddColumn(const wchar_t* pName){return XAdTable_AddColumn(m_hAdapter, pName);}
//@备注 设置列.  
//@参数 pColName 列名,多个列名用逗号分开.
//@返回 返回列数量.
//@别名  置列()
	int SetColumn(const wchar_t* pColName){return XAdTable_SetColumn(m_hAdapter, pColName);}
//@备注 添加数据项,默认值放到第一列.  
//@参数 pValue 值.
//@返回 返回项索引值.
//@别名  添加项文本()
	int AddItemText(const wchar_t* pValue){return XAdTable_AddItemText(m_hAdapter, pValue);}
//@备注 添加数据项,填充指定列数据.  
//@参数 pName 字段称.
//@参数 pValue 值.
//@返回 返回项索引.
//@别名  添加项文本扩展()
	int AddItemTextEx(const wchar_t* pName, const wchar_t* pValue){return XAdTable_AddItemTextEx(m_hAdapter, pName, pValue);}
//@备注 添加数据项,默认值放到第一列.  
//@参数 hImage 图片句柄.
//@返回 返回项索引值.
//@别名  添加项图片()
	int AddItemImage(HIMAGE hImage){return XAdTable_AddItemImage(m_hAdapter, hImage);}
//@备注 添加数据项,并填充指定列数据.  
//@参数 pName 字段称.
//@参数 hImage 图片句柄.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  添加项图片扩展()
	int AddItemImageEx(const wchar_t* pName, HIMAGE hImage){return XAdTable_AddItemImageEx(m_hAdapter, pName, hImage);}
//@备注 插入数据项,填充第一列数据.  
//@参数 iItem 插入位置索引.
//@参数 pValue 值.
//@返回 返回项索引.
//@别名  插入项文本()
	int InsertItemText(int iItem, const wchar_t* pValue){return XAdTable_InsertItemText(m_hAdapter, iItem, pValue);}
//@备注 插入数据项,并填充指定列数据.  
//@参数 iItem 插入位置索引.
//@参数 pName 字段称.
//@参数 pValue 值.
//@返回 返回项索引.
//@别名  插入项文本扩展()
	int InsertItemTextEx(int iItem, const wchar_t* pName, const wchar_t* pValue){return XAdTable_InsertItemTextEx(m_hAdapter, iItem, pName, pValue);}
//@备注 插入数据项,填充第一列数据.  
//@参数 iItem 插入位置索引.
//@参数 hImage 图片句柄.
//@返回 返回项索引.
//@别名  插入项图片()
	int InsertItemImage(int iItem, HIMAGE hImage){return XAdTable_InsertItemImage(m_hAdapter, iItem, hImage);}
//@备注 插入数据项,并填充指定列数据.  
//@参数 iItem 插入位置索引.
//@参数 pName 字段称.
//@参数 hImage 图片句柄.
//@返回 返回项索引.
//@别名  插入项图片扩展()
	int InsertItemImageEx(int iItem, const wchar_t* pName, HIMAGE hImage){return XAdTable_InsertItemImageEx(m_hAdapter, iItem, pName, hImage);}
//@备注 设置项数据.  
//@参数 iItem 项索引.
//@参数 iColumn 列索引.
//@参数 pValue 值.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项文本()
	BOOL SetItemText(int iItem, int iColumn, const wchar_t* pValue){return XAdTable_SetItemText(m_hAdapter, iItem, iColumn, pValue);}
//@备注 设置项数据.  
//@参数 iItem 项索引.
//@参数 pName 字段称.
//@参数 pValue 值.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项文本扩展()
	BOOL SetItemTextEx(int iItem, const wchar_t* pName, const wchar_t* pValue){return XAdTable_SetItemTextEx(m_hAdapter, iItem, pName, pValue);}
//@备注 设置项数据.  
//@参数 iItem 项索引.
//@参数 iColumn 列索引.
//@参数 nValue 值.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项整数值()
	BOOL SetItemInt(int iItem, int iColumn, int nValue){return XAdTable_SetItemInt(m_hAdapter, iItem, iColumn, nValue);}
//@备注 设置项数据.  
//@参数 iItem 项索引.
//@参数 pName 字段称.
//@参数 nValue 值.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项整数值扩展()
	BOOL SetItemIntEx(int iItem, const wchar_t* pName, int nValue){return XAdTable_SetItemIntEx(m_hAdapter, iItem, pName, nValue);}
//@备注 设置项数据.  
//@参数 iItem 项索引.
//@参数 iColumn 列索引.
//@参数 fValue 值.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项浮点值()
	BOOL SetItemFloat(int iItem, int iColumn, float nValue){return XAdTable_SetItemFloat(m_hAdapter, iItem, iColumn, nValue);}
//@备注 设置项数据.  
//@参数 iItem 项索引.
//@参数 pName 字段称.
//@参数 fValue 值.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项浮点值扩展()
	BOOL SetItemFloatEx(int iItem, const wchar_t* pName, float nValue){return XAdTable_SetItemFloatEx(m_hAdapter, iItem, pName, nValue);}
//@备注 设置项数据.  
//@参数 iItem 项索引.
//@参数 iColumn 列索引.
//@参数 hImage 图片句柄.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项图片()
	BOOL SetItemImage(int iItem, int iColumn, HIMAGE hImage){return XAdTable_SetItemImage(m_hAdapter, iItem, iColumn, hImage);}
//@备注 设置项数据.  
//@参数 iItem 项索引.
//@参数 pName 字段称.
//@参数 hImage 图片句柄.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项图片扩展()
	BOOL SetItemImageEx(int iItem, const wchar_t* pName, HIMAGE hImage){return XAdTable_SetItemImageEx(m_hAdapter, iItem, pName, hImage);}
//@备注 删除项.  
//@参数 iItem 项索引.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  删除项()
	BOOL DeleteItem(int iItem){return XAdTable_DeleteItem(m_hAdapter, iItem);}
//@备注 删除多个项.  
//@参数 iItem 项起始索引.
//@参数 nCount 删除项数量.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  删除项扩展()
	BOOL DeleteItemEx(int iItem, int nCount){return XAdTable_DeleteItemEx(m_hAdapter, iItem, nCount);}
//@备注 删除所有项.  
//@别名  删除项全部()
	void DeleteItemAll(){XAdTable_DeleteItemAll(m_hAdapter);}
//@备注 删除所有列,并且清空所有数据.  
//@别名  删除列全部()
	void DeleteColumnAll(){XAdTable_DeleteColumnAll(m_hAdapter);}
//@备注 获取项数量.  
//@返回 返回数量.
//@别名  取项数量()
	int GetCount(){return XAdTable_GetCount(m_hAdapter);}
//@备注 获取列数量.  
//@返回 返回列数量.
//@别名  取列数量()
	int GetCountColumn(){return XAdTable_GetCountColumn(m_hAdapter);}
//@备注 获取项文本内容.  
//@参数 iItem 项索引
//@参数 iColumn 列索引
//@返回 返回文本内容
//@别名  取项文本()
	const wchar_t* GetItemText(int iItem, int iColumn){return XAdTable_GetItemText(m_hAdapter, iItem, iColumn);}
//@备注 获取项文本内容.  
//@参数 iItem 项索引.
//@参数 pName 字段称.
//@返回 返回文本内容
//@别名  取项文本扩展()
	const wchar_t* GetItemTextEx(int iItem, const wchar_t* pName){return XAdTable_GetItemTextEx(m_hAdapter, iItem, pName);}
//@备注 获取项图片句柄.  
//@参数 iItem 项索引.
//@参数 iColumn 列索引.
//@返回 返回图片句柄.
//@别名  取项图片()
	HIMAGE GetItemImage(int iItem, int iColumn){return XAdTable_GetItemImage(m_hAdapter, iItem, iColumn);}
//@备注 获取项图片句柄.  
//@参数 iItem 项索引.
//@参数 pName 字段称.
//@返回 返回图片句柄.
//@别名  取项图片扩展()
	HIMAGE GetItemImageEx(int iItem, const wchar_t* pName){return XAdTable_GetItemImageEx(m_hAdapter, iItem, pName);}
//@备注 获取项值.  
//@参数 iItem 项索引.
//@参数 iColumn 列索引.
//@参数 pOutValue 接收返还值.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  取项整数值()
	BOOL GetItemInt(int iItem, int iColumn, int* pOutValue){return XAdTable_GetItemInt(m_hAdapter, iItem, iColumn, pOutValue);}
//@备注 获取项值.  
//@参数 iItem 项索引.
//@参数 pName 字段称.
//@参数 pOutValue 接收返还值.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  取项整数值扩展()
	BOOL GetItemIntEx(int iItem, const wchar_t* pName, int* pOutValue){return XAdTable_GetItemIntEx(m_hAdapter, iItem, pName, pOutValue);}
//@备注 获取项值.  
//@参数 iItem 项索引.
//@参数 iColumn 列索引.
//@参数 pOutValue 接收返还值.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  取项浮点值()
	BOOL GetItemFloat(int iItem, int iColumn, float* pOutValue){return XAdTable_GetItemFloat(m_hAdapter, iItem, iColumn, pOutValue);}
//@备注 获取项值.  
//@参数 iItem 项索引.
//@参数 pName 字段称.
//@参数 pOutValue 接收返还值.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  取项浮点值扩展()
	BOOL GetItemFloatEx(int iItem, const wchar_t* pName, float* pOutValue){return XAdTable_GetItemFloatEx(m_hAdapter, iItem, pName, pOutValue);}
};
//@备注  继承: CXAdapter, CXBase
//@别名  数据适配器MAP类
class CXAdapterMap: public CXAdapter
{
public:
	CXAdapterMap(){}
//@备注 创建数据适配器,单列数据.  
//@返回 返回数据适配器句柄.
//@别名  创建()
	HXCGUI Create(){m_hAdapter = XAdMap_Create();return m_hAdapter;}
//@备注 增加数据项.  
//@参数 pName 字段名称.
//@参数 pValue 值.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  添加项文本()
	BOOL AddItemText(const wchar_t* pName, const wchar_t* pValue){return XAdMap_AddItemText(m_hAdapter, pName, pValue);}
//@备注 增加数据项.  
//@参数 pName 字段名称.
//@参数 hImage 图片句柄.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  添加项图片()
	BOOL AddItemImage(const wchar_t* pName, HIMAGE hImage){return XAdMap_AddItemImage(m_hAdapter, pName, hImage);}
//@备注 删除数据项.  
//@参数 pName 字段名称.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  删除项()
	BOOL DeleteItem(const wchar_t* pName){return XAdMap_DeleteItem(m_hAdapter, pName);}
//@备注 获取项数量.  
//@返回 返回项数量.
//@别名  取项数量()
	int GetCount(){return XAdMap_GetCount(m_hAdapter);}
//@备注 获取项内容,如果内容为文本.  
//@参数 pName 字段名称.
//@返回 返回文本内容.
//@别名  取项文本()
	const wchar_t* GetItemText(const wchar_t* pName){return XAdMap_GetItemText(m_hAdapter, pName);}
//@备注 获取项内容,如果内容为图片句柄.  
//@参数 pName 字段名称.
//@返回 返回图片句柄.
//@别名  取项图片()
	HIMAGE GetItemImage(const wchar_t* pName){return XAdMap_GetItemImage(m_hAdapter, pName);}
//@备注 设置项内容.  
//@参数 pName 字段名称.
//@参数 pValue 值.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项文本()
	BOOL SetItemText(const wchar_t* pName, const wchar_t* pValue){return XAdMap_SetItemText(m_hAdapter, pName, pValue);}
//@备注 设置项内容.  
//@参数 pName 字段名称.
//@参数 hImage 值.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项图片()
	BOOL SetItemImage(const wchar_t* pName, HIMAGE hImage){return XAdMap_SetItemImage(m_hAdapter, pName, hImage);}
};
//@备注  继承: CXAdapter, CXBase
//@别名  数据适配器树类
class CXAdapterTree: public CXAdapter
{
public:
	CXAdapterTree(){}
//@备注 创建树元素数据适配器.  
//@返回 返回数据适配器句柄.
//@别名  创建()
	HXCGUI Create(){m_hAdapter = XAdTree_Create();return m_hAdapter;}
//@备注 添加列.  
//@参数 pName 字段名称.
//@返回 返回索引值.
//@别名  添加列()
	int AddColumn(const wchar_t* pName){return XAdTree_AddColumn(m_hAdapter, pName);}
//@备注 设置列.  
//@参数 pColName 列名,多个列名用逗号分开.
//@返回 返回列数量.
//@别名  置列()
	int SetColumn(const wchar_t* pColName){return XAdTree_SetColumn(m_hAdapter, pColName);}
//@备注 插入项,数据填充到第一列.  
//@参数 pValue 值.
//@参数 nParentID 父ID.
//@参数 insertID 插入位置ID.
//@返回 返回项ID值.
//@别名  插入项文本()
	int InsertItemText(const wchar_t* pValue, int nParentID=XC_ID_ROOT, int insertID=XC_ID_LAST){return XAdTree_InsertItemText(m_hAdapter, pValue, nParentID, insertID);}
//@备注 插入项,数据填充到指定列.  
//@参数 pName 字段名称.
//@参数 pValue 值.
//@参数 nParentID 父ID.
//@参数 insertID 插入位置ID.
//@返回 返回项ID值.
//@别名  插入项文本扩展()
	int InsertItemTextEx(const wchar_t* pName, const wchar_t* pValue, int nParentID=XC_ID_ROOT, int insertID=XC_ID_LAST){return XAdTree_InsertItemTextEx(m_hAdapter, pName, pValue, nParentID, insertID);}
//@备注 插入项,数据填充到第一列.  
//@参数 hImage 图片句柄.
//@参数 nParentID 父ID.
//@参数 insertID 插入位置ID.
//@返回 返回项ID值.
//@别名  插入项图片()
	int InsertItemImage(HIMAGE hImage, int nParentID=XC_ID_ROOT, int insertID=XC_ID_LAST){return XAdTree_InsertItemImage(m_hAdapter, hImage, nParentID, insertID);}
//@备注 插入项,数据填充到指定列.  
//@参数 pName 字段名称.
//@参数 hImage 图片句柄.
//@参数 nParentID 父ID.
//@参数 insertID 插入位置ID.
//@返回 返回项ID值.
//@别名  插入项图片扩展()
	int InsertItemImageEx(const wchar_t* pName, HIMAGE hImage, int nParentID=XC_ID_ROOT, int insertID=XC_ID_LAST){return XAdTree_InsertItemImageEx(m_hAdapter, pName, hImage, nParentID, insertID);}
//@备注 获取项数量.  
//@返回 返回数量.
//@别名  取项数量()
	int GetCount(){return XAdTree_GetCount(m_hAdapter);}
//@备注 获取列数量.  
//@返回 返回列数量.
//@别名  取列数量()
	int GetCountColumn(){return XAdTree_GetCountColumn(m_hAdapter);}
//@备注 设置项数据.  
//@参数 nID 项ID.
//@参数 iColumn 列索引.
//@参数 pValue 值.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项文本()
	BOOL SetItemText(int nID, int iColumn, const wchar_t* pValue){return XAdTree_SetItemText(m_hAdapter, nID, iColumn, pValue);}
//@备注 设置项文件内容.  
//@参数 nID 项ID.
//@参数 pName 字段名称.
//@参数 pValue 值.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项文本扩展()
	BOOL SetItemTextEx(int nID, const wchar_t* pName, const wchar_t* pValue){return XAdTree_SetItemTextEx(m_hAdapter, nID, pName, pValue);}
//@备注 设置项数据.  
//@参数 nID 项ID.
//@参数 iColumn 列索引.
//@参数 hImage 图片句柄.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项图片()
	BOOL SetItemImage(int nID, int iColumn, HIMAGE hImage){return XAdTree_SetItemImage(m_hAdapter, nID, iColumn, hImage);}
//@备注 设置项内容.  
//@参数 nID 项ID.
//@参数 pName 字段名称.
//@参数 hImage 图片句柄.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  置项图片扩展()
	BOOL SetItemImageEx(int nID, const wchar_t* pName, HIMAGE hImage){return XAdTree_SetItemImageEx(m_hAdapter, nID, pName, hImage);}
//@备注 获取项文本内容.  
//@参数 nID 项ID.
//@参数 iColumn 列索引.
//@返回 返回文本内容
//@别名  取项文本()
	const wchar_t* GetItemText(int nID, int iColumn){return XAdTree_GetItemText(m_hAdapter, nID, iColumn);}
//@备注 获取项文本内容.  
//@参数 nID 项ID.
//@参数 pName 字段名称.
//@返回 返回文本内容
//@别名  取项文本扩展()
	const wchar_t* GetItemTextEx(int nID, const wchar_t* pName){return XAdTree_GetItemTextEx(m_hAdapter, nID, pName);}
//@备注 获取项内容.  
//@参数 nID 项ID.
//@参数 iColumn 列索引.
//@返回 返回图片句柄.
//@别名  取项图片()
	HIMAGE GetItemImage(int nID, int iColumn){return XAdTree_GetItemImage(m_hAdapter, nID, iColumn);}
//@备注 获取项内容.  
//@参数 nID 项ID.
//@参数 pName 字段名称.
//@返回 返回图片句柄.
//@别名  取项图片扩展()
	HIMAGE GetItemImageEx(int nID, const wchar_t* pName){return XAdTree_GetItemImageEx(m_hAdapter, nID, pName);}
//@备注 删除项.  
//@参数 nID 项ID.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  删除项()
	BOOL DeleteItem(int nID){return XAdTree_DeleteItem(m_hAdapter, nID);}
//@备注 删除所有项.  
//@别名  删除项全部()
	void DeleteItemAll(){XAdTree_DeleteItemAll(m_hAdapter);}
//@备注 删除所有列,并且清空数据.  
//@返回 成功返回TRUE否则返回FALSE.
//@别名  删除列全部()
	void DeleteColumnAll(){XAdTree_DeleteColumnAll(m_hAdapter);}
};
//@备注  继承: CXBase
//@别名  背景管理器类
class CXBkManager: public CXBase
{
public:
	//@别名  句柄
	HBKM m_hBkM;
	CXBkManager(){}
//@备注 创建背景管理器.  
//@返回 背景管理器句柄.
//@别名  创建()
	HBKM Create(){m_hBkM = XBkM_Create();return m_hBkM;}
//@备注 销毁.  
//@别名  销毁()
	void Destroy(){XBkM_Destroy(m_hBkM);}
//@备注 废弃函数, 保留为了兼容旧版; 请使用 
//@参数 pText 背景内容字符串.
//@返回 返回设置的背景对象数量.
//@别名  置内容old()
	int SetBkInfo(const wchar_t* pText){return XBkM_SetBkInfo(m_hBkM, pText);}
//@备注 设置背景内容.  
//@参数 pText 背景内容字符串.
//@返回 返回设置的背景对象数量.
//@别名  置内容()
	int SetInfo(const wchar_t* pText){return XBkM_SetInfo(m_hBkM, pText);}
//@备注 添加背景内容.  
//@参数 pText 背景内容字符串.
//@返回 返回添加的背景对象数量.
//@别名  添加内容()
	int AddInfo(const wchar_t* pText){return XBkM_AddInfo(m_hBkM, pText);}
//@备注 添加背景内容边框.  
//@参数 nState 组合状态
//@参数 color 颜色.
//@参数 width 线宽.
//@参数 id 背景对象ID, 可忽略(0)
//@别名  添加边框()
	void AddBorder(int nState, COLORREF color, int width, int id=0){XBkM_AddBorder(m_hBkM, nState, color, width, id);}
//@备注 添加背景内容填充.  
//@参数 nState 组合状态
//@参数 color 颜色值, 请使用宏: RGBA()
//@参数 id 背景对象ID, 可忽略(0)
//@别名  添加填充()
	void AddFill(int nState, COLORREF color, int id=0){XBkM_AddFill(m_hBkM, nState, color, id);}
//@备注 添加背景内容图片.  
//@参数 nState 组合状态
//@参数 hImage 图片句柄.
//@参数 id 背景对象ID, 可忽略(0)
//@别名  添加图片()
	void AddImage(int nState, HIMAGE hImage, int id=0){XBkM_AddImage(m_hBkM, nState, hImage, id);}
//@备注 获取背景内容数量.  
//@返回 背景内容数量.
//@别名  取数量()
	int GetCount(){return XBkM_GetCount(m_hBkM);}
//@备注 清空背景内容.  
//@别名  清空()
	void Clear(){XBkM_Clear(m_hBkM);}
//@备注 绘制背景内容.  
//@参数 nState 组合状态
//@参数 hDraw 图形绘制句柄.
//@参数 pRect 区域坐标.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  绘制()
	BOOL Draw(int nState, HDRAW hDraw, RECT* pRect){return XBkM_Draw(m_hBkM, nState, hDraw, pRect);}
//@备注 绘制背景内容, 设置条件.  
//@参数 nState 组合状态.
//@参数 hDraw 图形绘制句柄.
//@参数 pRect 区域坐标.
//@参数 nStateEx 当(nState)中包含(nStateEx)中的一个或多个状态时有效.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  绘制扩展()
	BOOL DrawEx(int nState, HDRAW hDraw, RECT* pRect, int nStateEx){return XBkM_DrawEx(m_hBkM, nState, hDraw, pRect, nStateEx);}
//@备注 是否自动销毁
//@参数 bEnable 是否启用
//@别名  启用自动销毁()
	void EnableAutoDestroy(BOOL bEnable){XBkM_EnableAutoDestroy(m_hBkM, bEnable);}
//@别名  增加引用计数()
	void AddRef(){XBkM_AddRef(m_hBkM);}
//@备注 释放引用计数,当引用计数为0时,自动销毁
//@别名  释放引用计数()
	void Release(){XBkM_Release(m_hBkM);}
//@备注 获取引用计数
//@返回 返回引用计数.
//@别名  取引用计数()
	int GetRefCount(){return XBkM_GetRefCount(m_hBkM);}
//@参数 nState 状态
//@参数 color 接收返回颜色
//@返回 如果成功返回TRUE,否则返回FALSE
//@别名  取指定状态文本颜色()
	BOOL GetStateTextColor(int nState, COLORREF* color){return XBkM_GetStateTextColor(m_hBkM, nState, color);}
//@参数 id 背景对象ID
//@返回 返回对象句柄
//@别名  取背景对象()
	vint GetObject(int id){return XBkM_GetObject(m_hBkM, id);}
};
//@备注  继承: CXBase
//@别名  绘图类
class CXDraw: public CXBase
{
public:
	//@别名  句柄
	HDRAW m_hDraw;
	CXDraw(){}
//@备注 创建图形绘制模块实例.  
//@参数 hWindow 窗口句柄
//@返回 图形绘制模块实例句柄.
//@别名  创建()
	HDRAW Create(HWINDOW hWindow){m_hDraw = XDraw_Create(hWindow);return m_hDraw;}
//@备注 创建图形绘制模块实例.  
//@参数 hWindow 窗口句柄
//@返回 图形绘制模块实例句柄.
CXDraw(HWINDOW hWindow){m_hDraw = XDraw_Create(hWindow);}
//@备注 创建图形绘制模块实例
//@参数 hWindow 窗口句柄
//@参数 hdc hdc句柄
//@返回 图形绘制模块实例句柄.
//@别名  创建GDI()
	HDRAW CreateGDI(HWINDOW hWindow, HDC hdc){m_hDraw = XDraw_CreateGDI(hWindow, hdc);return m_hDraw;}
//@备注 销毁图形绘制模块实例句柄.  
//@别名  销毁()
	void Destroy(){XDraw_Destroy(m_hDraw);}
//@备注 设置坐标偏移量,X向左偏移为负数,向右偏移为正数.  
//@参数 x X轴偏移量.
//@参数 y Y轴偏移量.
//@别名  置偏移()
	void SetOffset(int x, int y){XDraw_SetOffset(m_hDraw, x, y);}
//@备注 获取坐标偏移量,X向左偏移为负数,向右偏移为正数.  
//@参数 pX 接收X轴偏移量.
//@参数 pY 接收Y轴偏移量.
//@别名  取偏移()
	void GetOffset(int* pX, int* pY){XDraw_GetOffset(m_hDraw, pX, pY);}
//@备注 还原状态,释放用户绑定的GDI对象,例如画刷,画笔
//@别名  GDI_还原状态()
	void GDI_RestoreGDIOBJ(){XDraw_GDI_RestoreGDIOBJ(m_hDraw);}
//@备注 SetBkMode() 参见MSDN
//@参数 bTransparent 参见MSDN.
//@返回 参见MSDN.
//@别名  GDI_置背景模式()
	int GDI_SetBkMode(BOOL bTransparent){return XDraw_GDI_SetBkMode(m_hDraw, bTransparent);}
//@备注 选择一个区域作为当前裁剪区域,注意:该函数只对GDI有效
//@参数 hRgn 区域句柄.
//@返回 返回值指定地区的复杂性，可以是下列值之一.\n
//@别名  GDI_选择裁剪区域()
	int GDI_SelectClipRgn(HRGN hRgn){return XDraw_GDI_SelectClipRgn(m_hDraw, hRgn);}
//@备注 GDI创建具有指定的纯色逻辑刷
//@参数 crColor 画刷颜色.
//@返回 如果函数成功,返回值标识一个逻辑刷,如果函数失败,返回值是NULL.
//@别名  GDI_创建实心画刷()
	HBRUSH GDI_CreateSolidBrush(COLORREF crColor){return XDraw_GDI_CreateSolidBrush(m_hDraw, crColor);}
//@备注 GDI创建一个逻辑笔,指定的样式,宽度和颜色,随后的笔可以选择到设备上下文,用于绘制线条和曲线
//@参数 fnPenStyle 画笔样式, PS_SOLID:实线 PS_DASH:段线 PS_DOT:点线  PS_DASHDOT:段线_点线 PS_DASHDOTDOT:段线_点_点 PS_NULL:空  PS_INSIDEFRAME:实线_笔宽是向里扩展
//@参数 width 画笔宽度
//@参数 crColor 颜色
//@返回 如果函数成功,返回值是一个句柄,标识一个逻辑笔,如果函数失败,返回值是NULL.
//@别名  GDI_创建画笔()
	HPEN GDI_CreatePen(int fnPenStyle, int width, COLORREF crColor){return XDraw_GDI_CreatePen(m_hDraw, fnPenStyle, width, crColor);}
//@备注 GDI创建矩形区域
//@参数 nLeftRect 左上角X坐标.
//@参数 nTopRect 左上角Y坐标.
//@参数 nRightRect 右下角X坐标.
//@参数 nBottomRect 右下角Y坐标.
//@返回 成功返回区域句柄,失败返回NULL.
//@别名  GDI_创建矩形区域()
	HRGN GDI_CreateRectRgn(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect){return XDraw_GDI_CreateRectRgn(m_hDraw, nLeftRect, nTopRect, nRightRect, nBottomRect);}
//@备注 GDI创建一个圆角的矩形区域
//@参数 nLeftRect X-坐标的左上角.
//@参数 nTopRect Y-坐标左上角坐标
//@参数 nRightRect X-坐标右下角
//@参数 nBottomRect Y-坐标右下角
//@参数 nWidthEllipse 椭圆的宽度.
//@参数 nHeightEllipse 椭圆的高度.
//@返回 如果函数成功,返回值是该区域的句柄,如果函数失败,返回值是NULL.
//@别名  GDI_创建圆角矩形区域()
	HRGN GDI_CreateRoundRectRgn(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, int nWidthEllipse, int nHeightEllipse){return XDraw_GDI_CreateRoundRectRgn(m_hDraw, nLeftRect, nTopRect, nRightRect, nBottomRect, nWidthEllipse, nHeightEllipse);}
//@备注 GDI创建一个多边形区域
//@参数 pPt POINT数组.
//@参数 cPoints 数组大小.
//@参数 fnPolyFillMode 多边形填充模式,指定用于确定在该地区的像素填充模式,这个参数可以是下列值之一.\n
//@返回 如果函数成功,返回值是该区域的句柄,如果函数失败,返回值是NULL.
//@别名  GDI_创建多边形区域()
	HRGN GDI_CreatePolygonRgn(POINT* pPt, int cPoints, int fnPolyFillMode){return XDraw_GDI_CreatePolygonRgn(m_hDraw, pPt, cPoints, fnPolyFillMode);}
//@备注 绘制矩形,使用当前的画刷和画笔
//@参数 nLeftRect 左上角X坐标.
//@参数 nTopRect 左上角Y坐标.
//@参数 nRightRect 右下角X坐标.
//@参数 nBottomRect 右下角Y坐标.
//@返回 如果函数成功,返回非零值,如果函数失败,返回值是零.
//@别名  GDI_矩形()
	BOOL GDI_Rectangle(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect){return XDraw_GDI_Rectangle(m_hDraw, nLeftRect, nTopRect, nRightRect, nBottomRect);}
//@备注 通过使用指定的画刷填充一个区域
//@参数 hrgn 区域句柄.
//@参数 hbr 画刷句柄.
//@返回 如果函数成功,返回非零值,如果函数失败,返回值是零.
//@别名  GID_填充区域()
	BOOL GDI_FillRgn(HRGN hrgn, HBRUSH hbr){return XDraw_GDI_FillRgn(m_hDraw, hrgn, hbr);}
//@参数 pRect 矩形区域
//@返回 如果成功返回TRUE,否则返回FALSE
//@别名  GDI_椭圆()
	BOOL GDI_Ellipse(RECT* pRect){return XDraw_GDI_Ellipse(m_hDraw, pRect);}
//@备注 绘制边框,使用指定的画刷绘制指定的区域的边框
//@参数 hrgn 区域句柄.
//@参数 hbr 画刷句柄.
//@参数 width 边框宽度,垂直边.
//@参数 height 边框高度,水平边.
//@返回 如果函数成功,返回非零值,如果函数失败,返回值是零.
//@别名  GDI_边框区域()
	BOOL GDI_FrameRgn(HRGN hrgn, HBRUSH hbr, int width, int nHeight){return XDraw_GDI_FrameRgn(m_hDraw, hrgn, hbr, width, nHeight);}
//@备注 更新当前位置到指定点，并返回以前的位置
//@参数 X 坐标.
//@参数 Y 坐标.
//@参数 pPoint 接收以前的当前位置到一个POINT结构的指针,如果这个参数是NULL指针,没有返回原来的位置.
//@返回 如果函数成功,返回非零值,如果函数失败,返回值是零.
//@别名  GDI_移动到起点()
	BOOL GDI_MoveToEx(int X, int Y, POINT* pPoint=NULL){return XDraw_GDI_MoveToEx(m_hDraw, X, Y, pPoint);}
//@备注 函数绘制一条线从当前位置到,但不包括指定点
//@参数 nXEnd X坐标,线结束点.
//@参数 nYEnd Y坐标,线结束点.
//@返回 如果函数成功,返回非零值,如果函数失败,返回值是零.
//@别名  GDI_线终点()
	BOOL GDI_LineTo(int nXEnd, int nYEnd){return XDraw_GDI_LineTo(m_hDraw, nXEnd, nYEnd);}
//@备注 Polyline() 参见MSDN
//@参数 pArrayPt 参见MSDN.
//@参数 arrayPtSize 参见MSDN.
//@返回 参见MSDN.
//@别名  GDI_折线()
	BOOL GDI_Polyline(POINT* pArrayPt, int arrayPtSize){return XDraw_GDI_Polyline(m_hDraw, pArrayPt, arrayPtSize);}
//@备注 绘制图标,DrawIconEx()参见MSDN
//@参数 xLeft .
//@参数 yTop .
//@参数 hIcon .
//@参数 cxWidth .
//@参数 cyWidth .
//@参数 istepIfAniCur .
//@参数 hbrFlickerFreeDraw .
//@参数 diFlags .
//@返回 .
//@别名  GDI_图标扩展()
	BOOL GDI_DrawIconEx(int xLeft, int yTop, HICON hIcon, int cxWidth, int cyWidth, UINT istepIfAniCur, HBRUSH hbrFlickerFreeDraw, UINT diFlags){return XDraw_GDI_DrawIconEx(m_hDraw, xLeft, yTop, hIcon, cxWidth, cyWidth, istepIfAniCur, hbrFlickerFreeDraw, diFlags);}
//@备注 BitBlt() 参见MSDN
//@参数 nXDest XX.
//@参数 nYDest XX.
//@参数 width XX.
//@参数 height XX.
//@参数 hdcSrc XX.
//@参数 nXSrc XX.
//@参数 nYSrc XX.
//@参数 dwRop XX.
//@返回 .
//@别名  GDI_复制()
	BOOL GDI_BitBlt(int nXDest, int nYDest, int width, int nHeight, HDC hdcSrc, int nXSrc, int nYSrc, DWORD dwRop){return XDraw_GDI_BitBlt(m_hDraw, nXDest, nYDest, width, nHeight, hdcSrc, nXSrc, nYSrc, dwRop);}
//@备注 BitBlt() 参见MSDN
//@参数 nXDest XX.
//@参数 nYDest XX.
//@参数 width XX.
//@参数 height XX.
//@参数 hDrawSrc XX.
//@参数 nXSrc XX.
//@参数 nYSrc XX.
//@参数 dwRop XX.
//@返回 .
//@别名  GDI_复制2()
	BOOL GDI_BitBlt2(int nXDest, int nYDest, int width, int nHeight, HDRAW hDrawSrc, int nXSrc, int nYSrc, DWORD dwRop){return XDraw_GDI_BitBlt2(m_hDraw, nXDest, nYDest, width, nHeight, hDrawSrc, nXSrc, nYSrc, dwRop);}
//@备注 AlphaBlend() 参见MSDN
//@参数 nXOriginDest XX.
//@参数 nYOriginDest XX.
//@参数 nWidthDest XX.
//@参数 nHeightDest XX.
//@参数 hdcSrc XX.
//@参数 nXOriginSrc XX.
//@参数 nYOriginSrc XX.
//@参数 nWidthSrc XX.
//@参数 nHeightSrc XX.
//@参数 alpha XX.
//@返回 成功返回TRUE否则返回FALSE.
//@别名  GDI_带透明复制()
	BOOL GDI_AlphaBlend(int nXOriginDest, int nYOriginDest, int nWidthDest, int nHeightDest, HDC hdcSrc, int nXOriginSrc, int nYOriginSrc, int nWidthSrc, int nHeightSrc, int alpha){return XDraw_GDI_AlphaBlend(m_hDraw, nXOriginDest, nYOriginDest, nWidthDest, nHeightDest, hdcSrc, nXOriginSrc, nYOriginSrc, nWidthSrc, nHeightSrc, alpha);}
//@备注 函数设置在指定的坐标到指定的颜色的像素
//@参数 X 坐标
//@参数 Y 坐标
//@参数 crColor 颜色值, 请使用宏: RGBA()
//@返回 如果函数成功返回RGB值,如果失败返回-1.
//@别名  GDI_置像素颜色()
	COLORREF GDI_SetPixel(int X, int Y, COLORREF crColor){return XDraw_GDI_SetPixel(m_hDraw, X, Y, crColor);}
//@备注 获取绑定的设备上下文HDC.  
//@返回 返回HDC句柄. 
//@别名  取HDC()
	HDC GetHDC(){return XDraw_GetHDC(m_hDraw);}
//@返回 返回 ID2D1RenderTarget*
//@别名  取D2D渲染目标()
	vint GetD2dRenderTarget(){return XDraw_GetD2dRenderTarget(m_hDraw);}
//@参数 mode 渲染模式  @ref XC_DWRITE_RENDERING_MODE
//@别名  置D2D文本渲染模式()
	void SetD2dTextRenderingMode(XC_DWRITE_RENDERING_MODE mode){XDraw_SetD2dTextRenderingMode(m_hDraw, mode);}
//@备注 设置文本渲染质量GDI+
//@参数 nType 参见GDI+ TextRenderingHint 定义.
//@别名  置文本炫彩质量()
	void SetTextRenderingHint(int nType){XDraw_SetTextRenderingHint(m_hDraw, nType);}
//@备注 使用指定颜色清理画布
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  D2D_清理()
	void D2D_Clear(COLORREF color){XDraw_D2D_Clear(m_hDraw, color);}
//@备注 设置画刷颜色.  
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置画刷颜色()
	void SetBrushColor(COLORREF color){XDraw_SetBrushColor(m_hDraw, color);}
//@备注 设置文本垂直显示.  
//@参数 bVertical 是否垂直显示文本.
//@别名  置文本垂直()
	void SetTextVertical(BOOL bVertical){XDraw_SetTextVertical(m_hDraw, bVertical);}
//@备注 设置文本对齐.  
//@参数 nFlags 对齐标识 @ref textFormatFlag_ .
//@别名  置文本对齐()
	void SetTextAlign(int nFlag){XDraw_SetTextAlign(m_hDraw, nFlag);}
//@备注 设置字体.  
//@参数 hFontx 炫彩字体.
//@别名  置字体()
	void SetFont(HFONTX hFontx){XDraw_SetFont(m_hDraw, hFontx);}
//@备注 设置线宽.  
//@参数 width 宽度.
//@别名  置线宽()
	void SetLineWidth(int width){XDraw_SetLineWidth(m_hDraw, width);}
//@备注 设置线宽
//@参数 width 宽度.
//@别名  置线宽F()
	void SetLineWidthF(float width){XDraw_SetLineWidthF(m_hDraw, width);}
//@备注 设置裁剪区域.  
//@参数 pRect 区域坐标.
//@别名  置裁剪区域()
	void SetClipRect(RECT* pRect){XDraw_SetClipRect(m_hDraw, pRect);}
//@备注 清除裁剪区域.  
//@别名  清除裁剪区域()
	void ClearClip(){XDraw_ClearClip(m_hDraw);}
//@备注 启用平滑模式.  
//@参数 bEnable 是否启用.
//@别名  启用平滑模式()
	void EnableSmoothingMode(BOOL bEnable){XDraw_EnableSmoothingMode(m_hDraw, bEnable);}
//@备注 当启用之后,调用GDI+函数时, 如果参数alpha=255,将自动修改为254, 应对GDI+的bug, 否则透明通道异常
//@参数 bTransparent 是否启用
//@别名  启用窗口透明判断()
	void EnableWndTransparent(BOOL bTransparent){XDraw_EnableWndTransparent(m_hDraw, bTransparent);}
//@参数 pRect 矩形区域.
//@别名  填充矩形()
	void FillRect(RECT* pRect){XDraw_FillRect(m_hDraw, pRect);}
//@参数 pRect 矩形区域
//@别名  填充矩形F()
	void FillRectF(RECTF* pRect){XDraw_FillRectF(m_hDraw, pRect);}
//@参数 pRect 矩形区域.
//@参数 color 颜色.
//@别名  填充矩形指定颜色()
	void FillRectColor(RECT* pRect, COLORREF color){XDraw_FillRectColor(m_hDraw, pRect, color);}
//@参数 pRect 矩形区域.
//@参数 color 颜色.
//@别名  填充矩形指定颜色F()
	void FillRectColorF(RECTF* pRect, COLORREF color){XDraw_FillRectColorF(m_hDraw, pRect, color);}
//@参数 pRect 矩形区域
//@别名  填充椭圆()
	void FillEllipse(RECT* pRect){XDraw_FillEllipse(m_hDraw, pRect);}
//@参数 pRect 矩形区域
//@别名  填充椭圆F()
	void FillEllipseF(RECTF* pRect){XDraw_FillEllipseF(m_hDraw, pRect);}
//@备注 绘制椭圆边框
//@参数 pRect 矩形区域.
//@别名  椭圆()
	void DrawEllipse(RECT* pRect){XDraw_DrawEllipse(m_hDraw, pRect);}
//@备注 绘制椭圆边框
//@参数 pRect 矩形区域.
//@别名  椭圆F()
	void DrawEllipseF(RECTF* pRect){XDraw_DrawEllipseF(m_hDraw, pRect);}
//@备注 填充圆角矩形
//@参数 pRect 矩形坐标.
//@参数 width 圆角宽度.
//@参数 height 圆角高度.
//@别名  填充圆角矩形()
	void FillRoundRect(RECT* pRect, int width, int nHeight){XDraw_FillRoundRect(m_hDraw, pRect, width, nHeight);}
//@备注 填充圆角矩形
//@参数 pRect 矩形坐标.
//@参数 width 圆角宽度.
//@参数 height 圆角高度.
//@别名  填充圆角矩形F()
	void FillRoundRectF(RECTF* pRect, float width, float height){XDraw_FillRoundRectF(m_hDraw, pRect, width, height);}
//@备注 绘制圆角矩形边框.  
//@参数 pRect 矩形坐标.
//@参数 width 圆角宽度.
//@参数 height 圆角高度.
//@别名  圆角矩形()
	void DrawRoundRect(RECT* pRect, int width, int nHeight){XDraw_DrawRoundRect(m_hDraw, pRect, width, nHeight);}
//@备注 绘制圆角矩形边框
//@参数 pRect 矩形坐标.
//@参数 width 圆角宽度.
//@参数 height 圆角高度.
//@别名  圆角矩形F()
	void DrawRoundRectF(RECTF* pRect, float width, float height){XDraw_DrawRoundRectF(m_hDraw, pRect, width, height);}
//@备注 填充圆角矩形.  
//@参数 pRect 坐标.
//@参数 leftTop 圆角大小.
//@参数 rightTop 圆角大小.
//@参数 rightBottom 圆角大小.
//@参数 leftBottom 圆角大小.
//@别名  填充圆角矩形扩展()
	void FillRoundRectEx(RECT* pRect, int leftTop, int rightTop, int rightBottom, int leftBottom){XDraw_FillRoundRectEx(m_hDraw, pRect, leftTop, rightTop, rightBottom, leftBottom);}
//@备注 填充圆角矩形
//@参数 pRect 坐标.
//@参数 leftTop 圆角大小.
//@参数 rightTop 圆角大小.
//@参数 rightBottom 圆角大小.
//@参数 leftBottom 圆角大小.
//@别名  填充圆角矩形扩展F()
	void FillRoundRectExF(RECTF* pRect, float leftTop, float rightTop, float rightBottom, float leftBottom){XDraw_FillRoundRectExF(m_hDraw, pRect, leftTop, rightTop, rightBottom, leftBottom);}
//@备注 绘制圆角矩形边框  
//@参数 pRect 坐标.
//@参数 leftTop 圆角大小.
//@参数 rightTop 圆角大小.
//@参数 rightBottom 圆角大小.
//@参数 leftBottom 圆角大小.
//@别名  圆角矩形扩展()
	void DrawRoundRectEx(RECT* pRect, int leftTop, int rightTop, int rightBottom, int leftBottom){XDraw_DrawRoundRectEx(m_hDraw, pRect, leftTop, rightTop, rightBottom, leftBottom);}
//@备注 绘制圆角矩形边框
//@参数 pRect 坐标.
//@参数 leftTop 圆角大小.
//@参数 rightTop 圆角大小.
//@参数 rightBottom 圆角大小.
//@参数 leftBottom 圆角大小.
//@别名  圆角矩形扩展F()
	void DrawRoundRectExF(RECTF* pRect, float leftTop, float rightTop, float rightBottom, float leftBottom){XDraw_DrawRoundRectExF(m_hDraw, pRect, leftTop, rightTop, rightBottom, leftBottom);}
//@备注 渐变填充,从一种颜色过渡到另一种颜色.  
//@参数 pRect 矩形坐标.
//@参数 color1 开始颜色.
//@参数 color2 结束颜色.
//@参数 mode 模式.
//@别名  渐变填充2()
	void GradientFill2(RECT* pRect, COLORREF color1, COLORREF color2, int mode){XDraw_GradientFill2(m_hDraw, pRect, color1, color2, mode);}
//@备注 渐变填充,从一种颜色过渡到另一种颜色
//@参数 pRect 矩形坐标.
//@参数 color1 开始颜色.
//@参数 color2 结束颜色.
//@参数 mode 模式.
//@别名  渐变填充2F()
	void GradientFill2F(RECTF* pRect, COLORREF color1, COLORREF color2, int mode){XDraw_GradientFill2F(m_hDraw, pRect, color1, color2, mode);}
//@备注 渐变填充,从一种颜色过渡到另一种颜色.  
//@参数 pRect 矩形坐标.
//@参数 color1 开始颜色.
//@参数 color2 结束颜色,中间.
//@参数 color3 开始颜色,中间.
//@参数 color4 结束颜色.
//@参数 mode 模式.
//@别名  渐变填充4()
	void GradientFill4(RECT* pRect, COLORREF color1, COLORREF color2, COLORREF color3, COLORREF color4, int mode){XDraw_GradientFill4(m_hDraw, pRect, color1, color2, color3, color4, mode);}
//@备注 渐变填充,从一种颜色过渡到另一种颜色
//@参数 pRect 矩形坐标.
//@参数 color1 开始颜色.
//@参数 color2 结束颜色,中间.
//@参数 color3 开始颜色,中间.
//@参数 color4 结束颜色.
//@参数 mode 模式.
//@别名  渐变填充4F()
	void GradientFill4F(RECTF* pRect, COLORREF color1, COLORREF color2, COLORREF color3, COLORREF color4, int mode){XDraw_GradientFill4F(m_hDraw, pRect, color1, color2, color3, color4, mode);}
//@备注 绘制矩形边框  
//@参数 pRect 矩形坐标
//@别名  矩形()
	void DrawRect(RECT* pRect){XDraw_DrawRect(m_hDraw, pRect);}
//@备注 绘制矩形边框
//@参数 pRect 矩形坐标
//@别名  矩形F()
	void DrawRectF(RECTF* pRect){XDraw_DrawRectF(m_hDraw, pRect);}
//@备注 绘制线条.  
//@参数 x1 坐标.
//@参数 y1 坐标.
//@参数 x2 坐标.
//@参数 y2 坐标.
//@别名  线条()
	void DrawLine(int x1, int y1, int x2, int y2){XDraw_DrawLine(m_hDraw, x1, y1, x2, y2);}
//@备注 绘制线条
//@参数 x1 坐标.
//@参数 y1 坐标.
//@参数 x2 坐标.
//@参数 y2 坐标.
//@别名  线条F()
	void DrawLineF(float x1, float y1, float x2, float y2){XDraw_DrawLineF(m_hDraw, x1, y1, x2, y2);}
//@备注 D2D暂时留空
//@参数 points 坐标点数组
//@参数 count 数组大小
//@参数 tension 大于或等于0.0F的值，指定曲线的张力。D2D 忽略此参数
//@别名  曲线()
	void DrawCurve(POINT* points, int count, float tension){XDraw_DrawCurve(m_hDraw, points, count, tension);}
//@备注 D2D暂时留空
//@参数 points 坐标点数组
//@参数 count 数组大小
//@参数 tension 大于或等于0.0F的值，指定曲线的张力。D2D 忽略此参数
//@别名  曲线F()
	void DrawCurveF(POINTF* points, int count, float tension){XDraw_DrawCurveF(m_hDraw, points, count, tension);}
//@参数 x 坐标
//@参数 y 坐标
//@参数 width 宽度
//@参数 height 高度
//@参数 startAngle 起始角度
//@参数 sweepAngle 绘制角度, 从起始角度开始计算
//@别名  圆弧()
	void DrawArc(int x, int y, int width, int nHeight, float startAngle, float sweepAngle){XDraw_DrawArc(m_hDraw, x, y, width, nHeight, startAngle, sweepAngle);}
//@参数 x 坐标
//@参数 y 坐标
//@参数 width 宽度
//@参数 height 高度
//@参数 startAngle 起始角度
//@参数 sweepAngle 绘制角度, 从起始角度开始计算
//@别名  圆弧F()
	void DrawArcF(float x, float y, float width, float height, float startAngle, float sweepAngle){XDraw_DrawArcF(m_hDraw, x, y, width, height, startAngle, sweepAngle);}
//@备注 绘制焦点矩形.  
//@参数 pRect 矩形坐标.
//@别名  焦点矩形()
	void FocusRect(RECT* pRect){XDraw_FocusRect(m_hDraw, pRect);}
//@备注 绘制焦点矩形
//@参数 pRect 矩形坐标.
//@别名  焦点矩形F()
	void FocusRectF(RECTF* pRect){XDraw_FocusRectF(m_hDraw, pRect);}
//@备注 绘制水平或垂直虚线.  
//@参数 x1 起点x坐标.
//@参数 y1 起点y坐标.
//@参数 x2 结束点x坐标.
//@参数 y2 结束点y坐标.
//@别名  虚线()
	void Dottedline(int x1, int y1, int x2, int y2){XDraw_Dottedline(m_hDraw, x1, y1, x2, y2);}
//@备注 绘制水平或垂直虚线
//@参数 x1 起点x坐标.
//@参数 y1 起点y坐标.
//@参数 x2 结束点x坐标.
//@参数 y2 结束点y坐标.
//@别名  虚线F()
	void DottedlineF(float x1, float y1, float x2, float y2){XDraw_DottedlineF(m_hDraw, x1, y1, x2, y2);}
//@备注 绘制多边形.  
//@参数 points 顶点坐标数组.
//@参数 nCount 顶点数量.
//@别名  多边形()
	void DrawPolygon(POINT* points, int nCount){XDraw_DrawPolygon(m_hDraw, points, nCount);}
//@备注 绘制多边形
//@参数 points 顶点坐标数组.
//@参数 nCount 顶点数量.
//@别名  多边形F()
	void DrawPolygonF(POINTF* points, int nCount){XDraw_DrawPolygonF(m_hDraw, points, nCount);}
//@备注 填充多边形.  
//@参数 points 顶点坐标数组.
//@参数 nCount 顶点数量.
//@别名  填充多边形()
	void FillPolygon(POINT* points, int nCount){XDraw_FillPolygon(m_hDraw, points, nCount);}
//@备注 填充多边形
//@参数 points 顶点坐标数组.
//@参数 nCount 顶点数量.
//@别名  填充多边形F()
	void FillPolygonF(POINTF* points, int nCount){XDraw_FillPolygonF(m_hDraw, points, nCount);}
//@备注 绘制图片.  
//@参数 hImageFrame 图片句柄.
//@参数 x x坐标.
//@参数 y y坐标.
//@别名  图片()
	void Image(HIMAGE hImageFrame, int x, int y){XDraw_Image(m_hDraw, hImageFrame, x, y);}
//@备注 绘制图片
//@参数 hImageFrame 图片句柄.
//@参数 x x坐标.
//@参数 y y坐标.
//@别名  图片F()
	void ImageF(HIMAGE hImageFrame, float x, float y){XDraw_ImageF(m_hDraw, hImageFrame, x, y);}
//@备注 绘制图片
//@参数 hImageFrame 图片句柄.
//@参数 x x坐标.
//@参数 y y坐标.
//@参数 width 宽度.
//@参数 height 高度.
//@别名  图片扩展()
	void ImageEx(HIMAGE hImageFrame, int x, int y, int width, int height){XDraw_ImageEx(m_hDraw, hImageFrame, x, y, width, height);}
//@备注 绘制图片
//@参数 hImageFrame 图片句柄.
//@参数 x x坐标.
//@参数 y y坐标.
//@参数 width 宽度.
//@参数 height 高度.
//@别名  图片扩展F()
	void ImageExF(HIMAGE hImageFrame, float x, float y, float width, float height){XDraw_ImageExF(m_hDraw, hImageFrame, x, y, width, height);}
//@备注 绘制图片.  
//@参数 hImageFrame 图片句柄.
//@参数 pRect 坐标.
//@参数 bOnlyBorder 是否只绘制边缘区域.
//@别名  图片自适应()
	void ImageAdaptive(HIMAGE hImageFrame, RECT* pRect, BOOL bOnlyBorder=FALSE){XDraw_ImageAdaptive(m_hDraw, hImageFrame, pRect, bOnlyBorder);}
//@备注 绘制图片
//@参数 hImageFrame 图片句柄.
//@参数 pRect 坐标.
//@参数 bOnlyBorder 是否只绘制边缘区域.
//@别名  图片自适应F()
	void ImageAdaptiveF(HIMAGE hImageFrame, RECTF* pRect, BOOL bOnlyBorder=FALSE){XDraw_ImageAdaptiveF(m_hDraw, hImageFrame, pRect, bOnlyBorder);}
//@备注 绘制图片.  
//@参数 hImageFrame 图片句柄.
//@参数 pRect 坐标.
//@参数 flag 标识, 0:从左上角开始平铺,1:从左下角开始平铺.
//@别名  图片平铺()
	void ImageTile(HIMAGE hImageFrame, RECT* pRect, int flag=0){XDraw_ImageTile(m_hDraw, hImageFrame, pRect, flag);}
//@备注 绘制图片
//@参数 hImageFrame 图片句柄.
//@参数 pRect 坐标.
//@参数 flag 标识, 0:从左上角开始平铺,1:从左下角开始平铺.
//@别名  图片平铺F()
	void ImageTileF(HIMAGE hImageFrame, RECTF* pRect, int flag=0){XDraw_ImageTileF(m_hDraw, hImageFrame, pRect, flag);}
//@备注 绘制图片.  
//@参数 hImageFrame 图片句柄.
//@参数 pRect 坐标.
//@参数 bClip 是否裁剪区域.
//@别名  图片增强()
	void ImageSuper(HIMAGE hImageFrame, RECT* pRect, BOOL bClip=FALSE){XDraw_ImageSuper(m_hDraw, hImageFrame, pRect, bClip);}
//@备注 绘制图片
//@参数 hImageFrame 图片句柄.
//@参数 pRect 坐标.
//@参数 bClip 是否裁剪区域.
//@别名  图片增强F()
	void ImageSuperF(HIMAGE hImageFrame, RECTF* pRect, BOOL bClip=FALSE){XDraw_ImageSuperF(m_hDraw, hImageFrame, pRect, bClip);}
//@备注 绘制图片.  
//@参数 hImageFrame 图片句柄.
//@参数 pRcDest 目标坐标.
//@参数 pRcSrc 源坐标.
//@别名  图片增强2()
	void ImageSuperEx(HIMAGE hImageFrame, RECT* pRcDest, RECT* pRcSrc){XDraw_ImageSuperEx(m_hDraw, hImageFrame, pRcDest, pRcSrc);}
//@备注 绘制图片
//@参数 hImageFrame 图片句柄.
//@参数 pRcDest 目标坐标.
//@参数 pRcSrc 源坐标.
//@别名  图片增强扩展F()
	void ImageSuperExF(HIMAGE hImageFrame, RECTF* pRcDest, RECTF* pRcSrc){XDraw_ImageSuperExF(m_hDraw, hImageFrame, pRcDest, pRcSrc);}
//@备注 绘制带遮盖的图片. D2D留空  
//@参数 hImageFrame 图片句柄.
//@参数 hImageFrameMask 图片句柄,遮盖.
//@参数 pRect 坐标.
//@参数 pRectMask 坐标,遮盖.
//@参数 bClip 是否裁剪区域.
//@别名  图片增强遮盖()
	void ImageSuperMask(HIMAGE hImageFrame, HIMAGE hImageFrameMask, RECT* pRect, RECT* pRectMask, BOOL bClip=FALSE){XDraw_ImageSuperMask(m_hDraw, hImageFrame, hImageFrameMask, pRect, pRectMask, bClip);}
//@备注 绘制带遮盖的图片.D2D留空  
//@参数 hImageFrame 图片句柄.
//@参数 hImageFrameMask 图片句柄,遮盖.
//@参数 x hImageFrame X坐标.
//@参数 y hImageFrame Y坐标.
//@参数 x2 hImageFrameMask X坐标.
//@参数 y2 hImageFrameMask Y坐标.
//@别名  图片遮盖()
	void ImageMask(HIMAGE hImageFrame, HIMAGE hImageFrameMask, RECT* pRect, int x2, int y2){XDraw_ImageMask(m_hDraw, hImageFrame, hImageFrameMask, pRect, x2, y2);}
//@参数 pString 字符串.
//@参数 nCount 字符串长度.
//@参数 pRect 坐标.
//@别名  文本指定矩形()
	void DrawText(const wchar_t* pString, int nCount, RECT* pRect){XDraw_DrawText(m_hDraw, pString, nCount, pRect);}
//@参数 pString 字符串.
//@参数 nCount 字符串长度.
//@参数 pRect 坐标.
//@别名  文本指定矩形F()
	void DrawTextF(const wchar_t* pString, int nCount, RECTF* pRect){XDraw_DrawTextF(m_hDraw, pString, nCount, pRect);}
//@备注 参见MSDN.  
//@参数 pString 字符串.
//@参数 nCount 字符串长度.
//@参数 pRect 坐标.
//@参数 colorLine 下划线颜色.
//@别名  文本下划线()
	void DrawTextUnderline(const wchar_t* pString, int nCount, RECT* pRect, COLORREF colorLine){XDraw_DrawTextUnderline(m_hDraw, pString, nCount, pRect, colorLine);}
//@参数 pString 字符串.
//@参数 nCount 字符串长度.
//@参数 pRect 坐标.
//@参数 colorLine 下划线颜色.
//@别名  文本下划线F()
	void DrawTextUnderlineF(const wchar_t* pString, int nCount, RECTF* pRect, COLORREF colorLine){XDraw_DrawTextUnderlineF(m_hDraw, pString, nCount, pRect, colorLine);}
//@参数 xStart XX.
//@参数 yStart XX.
//@参数 pString XX.
//@参数 cbString XX.
//@别名  文本()
	void TextOut(int xStart, int yStart, const wchar_t* pString, int cbString){XDraw_TextOut(m_hDraw, xStart, yStart, pString, cbString);}
//@参数 xStart XX.
//@参数 yStart XX.
//@参数 pString XX.
//@参数 cbString XX.
//@别名  文本F()
	void TextOutF(float xStart, float yStart, const wchar_t* pString, int cbString){XDraw_TextOutF(m_hDraw, xStart, yStart, pString, cbString);}
//@参数 xStart XX.
//@参数 yStart XX.
//@参数 pString XX.
//@别名  文本扩展()
	void TextOutEx(int xStart, int yStart, const wchar_t* pString){XDraw_TextOutEx(m_hDraw, xStart, yStart, pString);}
//@参数 xStart XX.
//@参数 yStart XX.
//@参数 pString XX.
//@别名  文本扩展F()
	void TextOutExF(float xStart, float yStart, const wchar_t* pString){XDraw_TextOutExF(m_hDraw, xStart, yStart, pString);}
//@参数 xStart XX.
//@参数 yStart XX.
//@参数 pString XX.
//@别名  文本A()
	void TextOutA(int xStart, int yStart, const char* pString){XDraw_TextOutA(m_hDraw, xStart, yStart, pString);}
//@参数 xStart XX.
//@参数 yStart XX.
//@参数 pString XX.
//@别名  文本AF()
	void TextOutAF(float xStart, float yStart, const char* pString){XDraw_TextOutAF(m_hDraw, xStart, yStart, pString);}
//@参数 hSvg SVG句柄
//@别名  SVG源()
	void DrawSvgSrc(HSVG hSvg){XDraw_DrawSvgSrc(m_hDraw, hSvg);}
//@参数 hSvg SVG句柄
//@参数 x x坐标
//@参数 y y坐标
//@别名  SVG()
	void DrawSvg(HSVG hSvg, int x, int y){XDraw_DrawSvg(m_hDraw, hSvg, x, y);}
//@参数 hSvg SVG句柄
//@参数 x x坐标
//@参数 y y坐标
//@参数 nWidth 宽度
//@参数 nHeight 高度
//@别名  SVG扩展()
	void DrawSvgEx(HSVG hSvg, int x, int y, int nWidth, int nHeight){XDraw_DrawSvgEx(m_hDraw, hSvg, x, y, nWidth, nHeight);}
//@参数 hSvg SVG句柄
//@参数 nWidth 宽度
//@参数 nHeight 高度
//@别名  SVG大小()
	void DrawSvgSize(HSVG hSvg, int nWidth, int nHeight){XDraw_DrawSvgSize(m_hDraw, hSvg, nWidth, nHeight);}
};
//@备注  继承: CXBase
//@别名  字体类
class CXFont: public CXBase
{
public:
	//@别名  句柄
	HFONTX m_hFont;
	CXFont(){}
//@备注 创建炫彩字体,当字体句柄与元素关联后,会自动释放.  
//@参数 size 字体大小,字体大小,单位(pt,磅).
//@返回 字体句柄.
//@别名  创建()
	HFONTX Create(int size){m_hFont = XFont_Create(size);return m_hFont;}
//@备注 创建炫彩字体,当字体句柄与元素关联后,会自动释放.  
//@参数 size 字体大小,字体大小,单位(pt,磅).
//@返回 字体句柄.
CXFont(int size){m_hFont = XFont_Create(size);}
//@备注 创建炫彩字体
//@参数 pName 字体名称.
//@参数 size 字体大小,单位(pt,磅).
//@参数 style 字体样式 @ref fontStyle_ .
//@返回 字体句柄.
//@别名  创建扩展()
	HFONTX CreateEx(const wchar_t* pName=L"宋体", int size=12, int style=fontStyle_regular){m_hFont = XFont_CreateEx(pName, size, style);return m_hFont;}
//@备注 创建炫彩字体 D2D不支持此接口
//@参数 pFontInfo 字体信息.
//@返回 字体句柄.
//@别名  创建从LOGFONT()
	HFONTX CreateFromLOGFONTW(LOGFONTW* pFontInfo){m_hFont = XFont_CreateFromLOGFONTW(pFontInfo);return m_hFont;}
//@备注 创建炫彩字体从现有HFONT字体,  D2D不支持此接口  
//@参数 hFont 字体句柄.
//@返回 返回炫彩字体.
//@别名  创建从HFONT()
	HFONTX CreateFromHFONT(HFONT hFont){m_hFont = XFont_CreateFromHFONT(hFont);return m_hFont;}
//@备注 创建炫彩字体从GDI+字体(Font), D2D不支持此接口  
//@参数 pFont GDI+字体指针(Font*).
//@返回 返回炫彩字体句柄.
//@别名  创建从Font()
	HFONTX CreateFromFont(void* pFont){m_hFont = XFont_CreateFromFont(pFont);return m_hFont;}
//@备注 创建字体从文件.  
//@参数 pFontFile 字体文件名.
//@参数 size 字体大小.
//@参数 style 样式, @ref fontStyle_
//@返回 返回炫彩字体句柄.
//@别名  创建从文件()
	HFONTX CreateFromFile(const wchar_t* pFontFile, int size=12, int style=fontStyle_regular){m_hFont = XFont_CreateFromFile(pFontFile, size, style);return m_hFont;}
//@参数 length 长度
//@参数 fontSize 字体大小
//@参数 style 字体样式,  @ref fontStyle_
//@返回 返回炫彩字体句柄.
//@别名  创建从内存()
	HFONTX CreateFromMem(UINT length, int fontSize=12, int style=fontStyle_regular){return XFont_CreateFromMem(m_hFont, length, fontSize, style);}
//@参数 id 资源ID
//@参数 pType 资源类型. 在rc资源文件中,资源的类型,例如:xcgui.rc,用记事本打开可以看见资源类型; 例如:BITMAP, PNG, FONT; 参见MSDN
//@参数 fontSize 字体大小
//@参数 style 字体样式,  @ref fontStyle_
//@参数 hModule 从指定模块加载, 例如:DLL, EXE; 如果为空, 从当前EXE加载
//@返回 返回炫彩字体句柄.
//@别名  创建从资源()
	HFONTX CreateFromRes(int id, const wchar_t* pType, int fontSize, int style, HMODULE hModule=NULL){m_hFont = XFont_CreateFromRes(id, pType, fontSize, style, hModule);return m_hFont;}
//@备注 是否自动销毁.  
//@参数 bEnable 是否启用.
//@别名  启用自动销毁()
	void EnableAutoDestroy(BOOL bEnable){XFont_EnableAutoDestroy(m_hFont, bEnable);}
//@备注 获取字体,返回GDI+ Font指针.  
//@返回 返回GDI+ Font指针.
//@别名  取Font()
	void* GetFont(){XFont_GetFont(m_hFont);}
//@备注 获取字体信息.  
//@参数 pInfo 接收返回的字体信息.
//@别名  取信息()
	void GetFontInfo(font_info_* pInfo){XFont_GetFontInfo(m_hFont, pInfo);}
//@备注 获取字体LOGFONTW  
//@参数 hdc hdc句柄
//@参数 pOut 接收返回信息
//@返回 成功返回TRUE,否则返回FALSE
//@别名  取LOGFONTW()
	BOOL GetLOGFONTW(HDC hdc, LOGFONTW* pOut){return XFont_GetLOGFONTW(m_hFont, hdc, pOut);}
//@备注 强制销毁炫彩字体,谨慎使用, 建议使用 
//@别名  销毁()
	void Destroy(){XFont_Destroy(m_hFont);}
//@备注 增加引用计数.  
//@别名  增加引用计数()
	void AddRef(){XFont_AddRef(m_hFont);}
//@备注 获取引用计数.  
//@返回 返回引用计数.
//@别名  取引用计数()
	int GetRefCount(){return XFont_GetRefCount(m_hFont);}
//@备注 释放引用计数,当引用计数为0时,自动销毁.  
//@别名  释放引用计数()
	void Release(){XFont_Release(m_hFont);}
};
//@备注  继承: CXBase
//@别名  图片源类
class CXImageSrc: public CXBase
{
public:
	//@别名  句柄
	HIMAGE m_hImageSrc;
	CXImageSrc(){}
//@备注 加载图片从文件.  
//@参数 pFileName 图片文件.
//@返回 图片句柄.
//@别名  加载从文件()
	HIMAGE LoadFile(const wchar_t* pFileName){m_hImageSrc = XImgSrc_LoadFile(pFileName);return m_hImageSrc;}
//@备注 加载图片,指定区位置及大小.  
//@参数 pFileName 图片文件.
//@参数 x 坐标.
//@参数 y 坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@返回 图片句柄.
//@别名  加载从文件指定区域()
	HIMAGE LoadFileRect(const wchar_t* pFileName, int x, int y, int cx, int cy){m_hImageSrc = XImgSrc_LoadFileRect(pFileName, x, y, cx, cy);return m_hImageSrc;}
//@备注 加载图片从资源.  
//@参数 id 资源ID.
//@参数 pType 资源类型, 在rc资源文件中,资源的类型, 例如:xcgui.rc, 用记事本打开可以看见资源类型; 例如:BITMAP, PNG; 参见MSDN
//@参数 hModule 从指定模块加载, 如果为空从当前EXE加载
//@返回 图片句柄.
//@别名  加载从资源()
	HIMAGE LoadRes(int id, const wchar_t* pType, HMODULE hModule){m_hImageSrc = XImgSrc_LoadRes(id, pType, hModule);return m_hImageSrc;}
//@备注 加载图片从ZIP压缩包.  
//@参数 pZipFileName ZIP压缩包文件名.
//@参数 pFileName 图片文件名.
//@参数 pPassword ZIP压缩包密码.
//@返回 图片句柄.
//@别名  加载从ZIP()
	HIMAGE LoadZip(const wchar_t* pZipFileName, const wchar_t* pFileName, const wchar_t* pPassword=NULL){m_hImageSrc = XImgSrc_LoadZip(pZipFileName, pFileName, pPassword);return m_hImageSrc;}
//@备注 加载ZIP图片,指定区位置及大小.  
//@参数 pZipFileName ZIP文件.
//@参数 pFileName 图片名称
//@参数 pPassword 密码
//@参数 x 坐标.
//@参数 y 坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@返回 图片句柄.
//@别名  加载从ZIP指定区域()
	HIMAGE LoadZipRect(const wchar_t* pZipFileName, const wchar_t* pFileName, const wchar_t* pPassword, int x, int y, int cx, int cy){m_hImageSrc = XImgSrc_LoadZipRect(pZipFileName, pFileName, pPassword, x, y, cx, cy);return m_hImageSrc;}
//@参数 data 内存块指针
//@参数 length 内存块大小,字节为单位
//@参数 pFileName 图片名称
//@参数 pPassword zip压缩包密码
//@返回 图片句柄
//@别名  加载从内存ZIP()
	HIMAGE LoadZipMem(void* data, int length, const wchar_t* pFileName, const wchar_t* pPassword=NULL){m_hImageSrc = XImgSrc_LoadZipMem(data, length, pFileName, pPassword);return m_hImageSrc;}
//@备注 加载流图片,指定区位置及大小.  
//@参数 pBuffer 图片缓冲区
//@参数 nSize 图片缓冲区大小
//@返回 图片句柄.
//@别名  加载从内存()
	HIMAGE LoadMemory(void* pBuffer, int nSize){m_hImageSrc = XImgSrc_LoadMemory(pBuffer, nSize);return m_hImageSrc;}
//@备注 加载流图片,指定区位置及大小.  
//@参数 pBuffer 图片缓冲区
//@参数 nSize 图片缓冲区大小
//@参数 x 坐标.
//@参数 y 坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@返回 图片句柄.
//@别名  加载从内存指定区域()
	HIMAGE LoadMemoryRect(void* pBuffer, int nSize, int x, int y, int cx, int cy){m_hImageSrc = XImgSrc_LoadMemoryRect(pBuffer, nSize, x, y, cx, cy);return m_hImageSrc;}
//@备注 加载图片从GDI+的Image对象.  
//@参数 pImage GDI图片对象指针 Bitmap*.
//@返回 成功返回炫彩图片句柄,失败返回FALSE.
//@别名  加载从Image()
	HIMAGE LoadFromImage(void* pImage){m_hImageSrc = XImgSrc_LoadFromImage(pImage);return m_hImageSrc;}
//@备注 加载文件图标,从一个EXE文件或DLL文件或图标文件;例如:*.exe文件的图标.  
//@参数 pFileName 文件名.
//@返回 成功返回炫彩图片句柄,失败返回FALSE.
//@别名  加载从模块()
	HIMAGE LoadFromExtractIcon(const wchar_t* pFileName){m_hImageSrc = XImgSrc_LoadFromExtractIcon(pFileName);return m_hImageSrc;}
//@备注 创建一个炫彩图片句柄,从一个现有的图标句柄HICON.  
//@参数 hIcon 图标句柄,如果你不使用可以释放 DestroyIcon().
//@返回 成功返回炫彩图片句柄,失败返回FALSE.
//@别名  加载从HICON()
	HIMAGE LoadFromHICON(HICON hIcon){m_hImageSrc = XImgSrc_LoadFromHICON(hIcon);return m_hImageSrc;}
//@备注 创建一个炫彩图片句柄,从一个现有的位图句柄HBITMAP.  
//@参数 hBitmap 位图句柄,如果你不使用可以释放 DeleteObject().
//@返回 成功返回炫彩图片句柄,失败返回FALSE.
//@别名  加载从HBITMAP()
	HIMAGE LoadFromHBITMAP(HBITMAP hBitmap){m_hImageSrc = XImgSrc_LoadFromHBITMAP(hBitmap);return m_hImageSrc;}
//@备注 启用或关闭自动销毁,当与UI元素关联时有效  
//@参数 bEnable 启用自动销毁TRUE,关闭自动销毁FALSE.
//@别名  启用自动销毁()
	void EnableAutoDestroy(BOOL bEnable){XImgSrc_EnableAutoDestroy(m_hImageSrc, bEnable);}
//@备注 获取图片宽度.  
//@返回 图片宽度.
//@别名  取宽度()
	int GetWidth(){return XImgSrc_GetWidth(m_hImageSrc);}
//@备注 获取图片高度.  
//@返回 图片高度.
//@别名  取高度()
	int GetHeight(){return XImgSrc_GetHeight(m_hImageSrc);}
//@备注 获取图片文件名  
//@返回 返回文件名
//@别名  取文件名()
	const wchar_t* GetFile(){return XImgSrc_GetFile(m_hImageSrc);}
//@备注 增加引用计数.  
//@别名  增加引用计数()
	void AddRef(){XImgSrc_AddRef(m_hImageSrc);}
//@备注 释放引用计数,当引用计数为0时,自动销毁.  
//@别名  释放引用计数()
	void Release(){XImgSrc_Release(m_hImageSrc);}
//@备注 获取引用计数.  
//@返回 返回引用计数.
//@别名  取引用计数()
	int GetRefCount(){return XImgSrc_GetRefCount(m_hImageSrc);}
//@备注 强制销毁图片, 谨慎使用, 建议使用 
//@别名  销毁()
	void Destroy(){XImgSrc_Destroy(m_hImageSrc);}
};
//@备注  继承: CXBase
//@别名  图片类
class CXImage: public CXBase
{
public:
	//@别名  句柄
	HIMAGE m_hImage;
	CXImage(){}
//@参数 hImageSrc 图片源句柄
//@返回 返回图片句柄
//@别名  加载从图片源()
	HIMAGE LoadSrc(HIMAGE hImageSrc){m_hImage = XImage_LoadSrc(hImageSrc);return m_hImage;}
//@备注 加载图片从文件.  
//@参数 pFileName 图片文件.
//@返回 图片句柄.
//@别名  加载从文件()
	HIMAGE LoadFile(const wchar_t* pFileName){m_hImage = XImage_LoadFile(pFileName);return m_hImage;}
//@备注 加载图片从文件,自适应图片.  
//@参数 pFileName 图片文件.
//@参数 leftSize 坐标.
//@参数 topSize 坐标.
//@参数 rightSize 坐标.
//@参数 bottomSize 坐标.
//@返回 图片句柄.
//@别名  加载从文件自适应()
	HIMAGE LoadFileAdaptive(const wchar_t* pFileName, int leftSize, int topSize, int rightSize, int bottomSize){m_hImage = XImage_LoadFileAdaptive(pFileName, leftSize, topSize, rightSize, bottomSize);return m_hImage;}
//@备注 加载图片,指定区位置及大小.  
//@参数 pFileName 图片文件.
//@参数 x 坐标.
//@参数 y 坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@返回 图片句柄.
//@别名  加载从文件指定区域()
	HIMAGE LoadFileRect(const wchar_t* pFileName, int x, int y, int cx, int cy){m_hImage = XImage_LoadFileRect(pFileName, x, y, cx, cy);return m_hImage;}
//@备注 加载图片从资源,自适应图片.  
//@参数 id 资源ID.
//@参数 pType 资源类型. 在rc资源文件中,资源的类型, 例如:xcgui.rc, 用记事本打开可以看见资源类型; 例如:BITMAP, PNG; 参见MSDN
//@参数 leftSize 坐标.
//@参数 topSize 坐标.
//@参数 rightSize 坐标.
//@参数 bottomSize 坐标.
//@参数 hModule 从指定模块加载, 例如:DLL, EXE; 如果为空, 从当前EXE加载
//@返回 图片句柄.
//@别名  加载从资源自适应()
	HIMAGE LoadResAdaptive(int id, const wchar_t* pType, int leftSize, int topSize, int rightSize, int bottomSize, HMODULE hModule=NULL){m_hImage = XImage_LoadResAdaptive(id, pType, leftSize, topSize, rightSize, bottomSize, hModule);return m_hImage;}
//@备注 加载图片从资源.  
//@参数 id 资源ID.
//@参数 pType 资源类型. 在rc资源文件中,资源的类型, 例如:xcgui.rc, 用记事本打开可以看见资源类型; 例如:BITMAP, PNG; 参见MSDN
//@参数 hModule 从指定模块加载, 例如:DLL, EXE; 如果为空, 从当前EXE加载
//@返回 图片句柄.
//@别名  加载从资源()
	HIMAGE LoadRes(int id, const wchar_t* pType, HMODULE hModule=NULL){m_hImage = XImage_LoadRes(id, pType, hModule);return m_hImage;}
//@备注 加载图片从ZIP压缩包.  
//@参数 pZipFileName ZIP压缩包文件名.
//@参数 pFileName 图片文件名.
//@参数 pPassword ZIP压缩包密码.
//@返回 图片句柄.
//@别名  加载从ZIP()
	HIMAGE LoadZip(const wchar_t* pZipFileName, const wchar_t* pFileName, const wchar_t* pPassword=NULL){m_hImage = XImage_LoadZip(pZipFileName, pFileName, pPassword);return m_hImage;}
//@备注 加载图片从ZIP压缩包,自适应图片.  
//@参数 pZipFileName ZIP压缩包文件名.
//@参数 pFileName 图片文件名.
//@参数 pPassword ZIP压缩包密码,如果没有填NULL.
//@参数 x1 坐标.
//@参数 x2 坐标.
//@参数 y1 坐标.
//@参数 y2 坐标.
//@返回 图片句柄.
//@别名  加载从ZIP自适应()
	HIMAGE LoadZipAdaptive(const wchar_t* pZipFileName, const wchar_t* pFileName, const wchar_t* pPassword, int x1, int x2, int y1, int y2){m_hImage = XImage_LoadZipAdaptive(pZipFileName, pFileName, pPassword, x1, x2, y1, y2);return m_hImage;}
//@备注 加载ZIP图片,指定区位置及大小.  
//@参数 pZipFileName ZIP文件.
//@参数 pFileName 图片名称
//@参数 pPassword 密码
//@参数 x 坐标.
//@参数 y 坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@返回 图片句柄.
//@别名  加载从ZIP指定区域()
	HIMAGE LoadZipRect(const wchar_t* pZipFileName, const wchar_t* pFileName, const wchar_t* pPassword, int x, int y, int cx, int cy){m_hImage = XImage_LoadZipRect(pZipFileName, pFileName, pPassword, x, y, cx, cy);return m_hImage;}
//@参数 data 内存块指针
//@参数 length 内存块大小,字节为单位
//@参数 pFileName 图片名称
//@参数 pPassword zip压缩包密码
//@返回 图片句柄
//@别名  加载从内存ZIP()
	HIMAGE LoadZipMem(void* data, int length, const wchar_t* pFileName, const wchar_t* pPassword=NULL){m_hImage = XImage_LoadZipMem(data, length, pFileName, pPassword);return m_hImage;}
//@备注 加载流图片,指定区位置及大小.  
//@参数 pBuffer 图片缓冲区
//@参数 nSize 图片缓冲区大小
//@返回 图片句柄.
//@别名  加载从内存()
	HIMAGE LoadMemory(void* pBuffer, int nSize){m_hImage = XImage_LoadMemory(pBuffer, nSize);return m_hImage;}
//@备注 加载流图片,指定区位置及大小.  
//@参数 pBuffer 图片缓冲区
//@参数 nSize 图片缓冲区大小
//@参数 x 坐标.
//@参数 y 坐标.
//@参数 cx 宽度.
//@参数 cy 高度.
//@返回 图片句柄.
//@别名  加载从内存指定区域()
	HIMAGE LoadMemoryRect(void* pBuffer, int nSize, int x, int y, int cx, int cy){m_hImage = XImage_LoadMemoryRect(pBuffer, nSize, x, y, cx, cy);return m_hImage;}
//@备注 加载流图片压缩包,自适应图片(九宫格).  
//@参数 pBuffer 图片缓冲区
//@参数 nSize 图片缓冲区大小
//@参数 leftSize 坐标.
//@参数 topSize 坐标.
//@参数 rightSize 坐标.
//@参数 bottomSize 坐标.
//@返回 图片句柄
//@别名  加载从内存自适应()
	HIMAGE LoadMemoryAdaptive(void* pBuffer, int nSize, int leftSize, int topSize, int rightSize, int bottomSize){m_hImage = XImage_LoadMemoryAdaptive(pBuffer, nSize, leftSize, topSize, rightSize, bottomSize);return m_hImage;}
//@备注 加载图片从GDI+的Image对象.  
//@参数 pImage GDI图片对象指针 Image*.
//@返回 图片句柄
//@别名  加载从Image()
	HIMAGE LoadFromImage(void* pImage){m_hImage = XImage_LoadFromImage(pImage);return m_hImage;}
//@备注 加载文件图标,从一个EXE文件或DLL文件或图标文件;例如:*.exe文件的图标.  
//@参数 pFileName 文件名.
//@返回 图片句柄
//@别名  加载文件图标()
	HIMAGE LoadFromExtractIcon(const wchar_t* pFileName){m_hImage = XImage_LoadFromExtractIcon(pFileName);return m_hImage;}
//@备注 创建一个炫彩图片句柄,从一个现有的图标句柄HICON.  
//@参数 hIcon 图标句柄,如果你不使用可以释放 DestroyIcon().
//@返回 图片句柄
//@别名  加载从HICON()
	HIMAGE LoadFromHICON(HICON hIcon){m_hImage = XImage_LoadFromHICON(hIcon);return m_hImage;}
//@备注 创建一个炫彩图片句柄,从一个现有的位图句柄HBITMAP.  
//@参数 hBitmap 位图句柄,如果你不使用可以释放 DeleteObject().
//@返回 图片句柄
//@别名  加载从HBITMAP()
	HIMAGE LoadFromHBITMAP(HBITMAP hBitmap){m_hImage = XImage_LoadFromHBITMAP(hBitmap);return m_hImage;}
//@备注 是否为拉伸图片句柄  
//@返回 是否缩放.
//@别名  是否缩放()
	BOOL IsStretch(){return XImage_IsStretch(m_hImage);}
//@备注 是否为自适应图片句柄  
//@返回 是否自适应
//@别名  是否自适应()
	BOOL IsAdaptive(){return XImage_IsAdaptive(m_hImage);}
//@备注 是否为平铺图片  
//@返回 是否平铺
//@别名  是否平铺()
	BOOL IsTile(){return XImage_IsTile(m_hImage);}
//@参数 hSvg SVG句柄
//@返回 图片句柄
//@别名  加载从SVG()
	HIMAGE LoadSvg(HSVG hSvg){m_hImage = XImage_LoadSvg(hSvg);return m_hImage;}
//@备注 UTF8文件
//@参数 pFileName 文件名
//@返回 图片句柄
//@别名  加载从SVG文件()
	HIMAGE LoadSvgFile(const wchar_t* pFileName){m_hImage = XImage_LoadSvgFile(pFileName);return m_hImage;}
//@备注 多字节字符串ANSI
//@参数 pString 字符串指针
//@返回 图片句柄
//@别名  加载从SVG字符串()
	HIMAGE LoadSvgString(const char* pString){m_hImage = XImage_LoadSvgString(pString);return m_hImage;}
//@备注 UNICODE字符串
//@参数 pString 字符串指针
//@返回 图片句柄
//@别名  加载从SVG字符串W()
	HIMAGE LoadSvgStringW(const wchar_t* pString){m_hImage = XImage_LoadSvgStringW(pString);return m_hImage;}
//@备注 UTF8字符串
//@参数 pString 字符串指针
//@返回 图片句柄
//@别名  加载从SVG字符串UTF8()
	HIMAGE LoadSvgStringUtf8(const char* pString){m_hImage = XImage_LoadSvgStringUtf8(pString);return m_hImage;}
//@返回 SVG句柄
//@别名  取SVG()
	HSVG GetSvg(){return XImage_GetSvg(m_hImage);}
//@备注 设置图片绘制类型  
//@参数 nType 图片绘制类型.
//@返回 如果成功返回TRUE,否则相反.
//@别名  置绘制类型()
	BOOL SetDrawType(image_draw_type_ nType){return XImage_SetDrawType(m_hImage, nType);}
//@备注 设置图片自适应(九宫格)  
//@参数 leftSize 坐标.
//@参数 topSize 坐标.
//@参数 rightSize 坐标.
//@参数 bottomSize 坐标.
//@返回 如果成功返回TRUE,否则相反.
//@别名  置绘制类型自适应()
	BOOL SetDrawTypeAdaptive(int leftSize, int topSize, int rightSize, int bottomSize){return XImage_SetDrawTypeAdaptive(m_hImage, leftSize, topSize, rightSize, bottomSize);}
//@备注 指定图片透明颜色.  
//@参数 color 颜色值, 请使用宏: RGBA()
//@别名  置透明色()
	void SetTranColor(COLORREF color){XImage_SetTranColor(m_hImage, color);}
//@备注 指定图片透明颜色及透明度.  
//@参数 color 颜色值, 请使用宏: RGBA()
//@参数 tranColor 透明色的透明度.
//@别名  置透明色扩展()
	void SetTranColorEx(COLORREF color, BYTE tranColor){XImage_SetTranColorEx(m_hImage, color, tranColor);}
//@备注 设置旋转角度.  
//@参数 fAngle 选择角度.
//@返回 返回先前角度.
//@别名  置旋转角度()
	float SetRotateAngle(float fAngle){return XImage_SetRotateAngle(m_hImage, fAngle);}
//@参数 nCount 等分数量
//@参数 iIndex 索引
//@别名  置等分()
	void SetSplitEqual(int nCount, int iIndex){XImage_SetSplitEqual(m_hImage, nCount, iIndex);}
//@备注 启用或关闭图片透明色.  
//@参数 bEnable 启用TRUE,关闭FALSE.
//@别名  启用透明色()
	void EnableTranColor(BOOL bEnable){XImage_EnableTranColor(m_hImage, bEnable);}
//@备注 启用或关闭自动销毁,当与UI元素关联时有效  
//@参数 bEnable 启用自动销毁TRUE,关闭自动销毁FALSE.
//@别名  启用自动销毁()
	void EnableAutoDestroy(BOOL bEnable){XImage_EnableAutoDestroy(m_hImage, bEnable);}
//@备注 启用或关闭图片居中显示，默认属性图片有效。  
//@参数 bCenter 是否居中显示.
//@别名  启用居中()
	void EnableCenter(BOOL bCenter){XImage_EnableCenter(m_hImage, bCenter);}
//@备注 判断图片是否居中显示  
//@返回 如果居中显示返回TRUE，否则相反.
//@别名  是否居中()
	BOOL IsCenter(){return XImage_IsCenter(m_hImage);}
//@备注 获取图片绘制类型  
//@返回 图片绘制类型.
//@别名  取绘制类型()
	image_draw_type_ GetDrawType(){return XImage_GetDrawType(m_hImage);}
//@备注 获取图片宽度.  
//@返回 图片宽度.
//@别名  取宽度()
	int GetWidth(){return XImage_GetWidth(m_hImage);}
//@备注 获取图片高度.  
//@返回 图片高度.
//@别名  取高度()
	int GetHeight(){return XImage_GetHeight(m_hImage);}
//@返回 返回图片源句柄
//@别名  取图片源()
	HIMAGE GetImageSrc(){return XImage_GetImageSrc(m_hImage);}
//@备注 增加引用计数.  
//@别名  增加引用计数()
	void AddRef(){XImage_AddRef(m_hImage);}
//@备注 释放引用计数,当引用计数为0时,自动销毁.  
//@别名  释放引用计数()
	void Release(){XImage_Release(m_hImage);}
//@备注 获取引用计数.  
//@返回 返回引用计数.
//@别名  取引用计数()
	int GetRefCount(){return XImage_GetRefCount(m_hImage);}
//@备注 强制销毁图片, 谨慎使用, 建议使用 
//@别名  销毁()
	void Destroy(){XImage_Destroy(m_hImage);}
};
#endif
