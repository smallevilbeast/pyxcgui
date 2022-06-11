/**************************************************************************\
*
* Copyright (c)  �Ųʽ����. All Rights Reserved.
*
* �Ųʽ���� - �ٷ���վ : http://www.xcgui.com
*
\**************************************************************************/
#pragma once

//v3.3.4
////////////�������///////////////////
#define  in_
#define  out_
#define  in_out_
#define  in_buffer_  //��ʶΪ�ڴ�ָ��, �Ǳ���ָ��
#define  out_buffer_

#define  XC_API extern "C"

#define  XC_NAME1   _T("name1")
#define  XC_NAME2   _T("name2")
#define  XC_NAME3   _T("name3")
#define  XC_NAME4   _T("name4")
#define  XC_NAME5   _T("name5")
#define  XC_NAME6   _T("name6")

#ifndef  GetAValue
#define  GetAValue(rgba)         (LOBYTE((rgba)>>24))
#endif

#ifndef  RGBA
#define  RGBA(r, g, b, a)        ((BYTE)a<<24 | (BYTE)r | (BYTE)g<<8 | (BYTE)b<<16)
#endif

#define  COLOR_MAKE(r,g,b,a)     ((BYTE)a<<24 | (BYTE)r | (BYTE)g<<8 | (BYTE)b<<16)
#define  COLORREF_MAKE(r,g,b,a)  ((BYTE)a<<24 | (BYTE)r | (BYTE)g<<8 | (BYTE)b<<16)

#define  COLORREF_MAKE2(rgb,a)        ((BYTE)a<<24 | GetRValue(rgb) | GetGValue(rgb)<<8 | GetBValue(rgb)<<16)
#define  COLORREF_SET_RGB(color,rgb)  ((color & 0xFF000000) | (rgb & 0xFFFFFF))
#define  COLORREF_SET_A(color,a)      ((color & 0xFFFFFF) | ((BYTE)a<<24))
#define  COLORREF_GET_A(color)        ((BYTE)(color>>24))

#ifdef _WIN64
typedef  __int64  vint;
#else
typedef  int      vint;
#endif

//��������ظ�����POINTF,��ע�͵����涨��POINTF
#ifndef __IOleControlSite_INTERFACE_DEFINED__
struct POINTF
{
	float x;
	float y;
};
#endif

typedef   void  bkInfo_i;  //������Ϣ

/*@����
#define  WM_LBUTTONDOWN
#define  SW_SHOW
#define  WM_PAINT
#define  WM_CLOSE
#define  WM_DESTROY
#define  WM_NCDESTROY
#define  WM_MOUSEMOVE
#define  WM_LBUTTONUP
#define  WM_RBUTTONDOWN
#define  WM_RBUTTONUP
#define  WM_LBUTTONDBLCLK
#define  WM_RBUTTONDBLCLK
#define  WM_MOUSEWHEEL
#define  WM_EXITSIZEMOVE
#define  WM_MOUSEHOVER
#define  WM_MOUSELEAVE
#define  WM_SIZE
#define  WM_TIMER
#define  WM_SETFOCUS
#define  WM_KILLFOCUS
#define  WM_KEYDOWN
#define  WM_CAPTURECHANGE
#define  WM_SETCURSOR
#define  WM_CHAR
#define  WM_DROPFILES
*/

/////////////////////////////////////////////////////////////////////
/////////////////////������Ͷ���//////////////////////////////////////
/////////////////////////////////////////////////////////////////////
#define DECLARE_HANDLEX(name) struct name##__ { int unused; }; typedef struct name##__ *name

/// @defgroup groupHandle   �������
/// @{

//@����  �Ųʾ��
typedef void* HXCGUI;       ///<��Դ���
//@����  ���ھ��
DECLARE_HANDLEX(HWINDOW);     ///<������Դ���
//@����  Ԫ�ؾ��
DECLARE_HANDLEX(HELE);        ///<Ԫ����Դ���
//@����  �˵����
DECLARE_HANDLEX(HMENUX);      ///<�˵���Դ���
//@����  ��ͼ���
DECLARE_HANDLEX(HDRAW);       ///<ͼ�λ�����Դ���
//@����  ͼƬ���
DECLARE_HANDLEX(HIMAGE);      ///<ͼƬ��Դ���
//@����  ������
DECLARE_HANDLEX(HFONTX);      ///<�Ų�������
//@����  �������
DECLARE_HANDLEX(HBKM);        ///<�������ݹ��������
//@����  ģ����
DECLARE_HANDLEX(HTEMP);       ///<ģ����
//@����  SVG���
DECLARE_HANDLEX(HSVG);        ///<SVG���
///@}

#ifndef _INC_SHELLAPI
DECLARE_HANDLEX(HDROP);
#endif

/////////////////////////////////////////////////////////////////////
/////////////////////�Ųʶ������ͼ���ʽ/////////////////////////////////
/////////////////////////////////////////////////////////////////////

//�������;�������
//������ʽ�������
/// @defgroup group_type_style_  �������ͼ���ʽ
/// @{

/// @defgroup group_ObjectType ����������(XC_OBJECT_TYPE)
/// @{
enum XC_OBJECT_TYPE
{
	XC_ERROR                 =-1,   ///<��������
	XC_NOTHING               =0,    ///<ɶҲ����
	XC_WINDOW                =1,    ///<����
	XC_MODALWINDOW           =2,    ///<ģ̬����
	XC_FRAMEWND              =3,    ///<��ܴ���
	XC_FLOATWND              =4,    ///<��������
	XC_COMBOBOXWINDOW        =11,   ///<��Ͽ򵯳������б��� comboBoxWindow_        
	XC_POPUPMENUWINDOW       =12 ,  ///<�����˵������� popupMenuWindow_       
	XC_POPUPMENUCHILDWINDOW  =13,   ///<�����˵��Ӵ��� popupMenuChildWindow_  
	XC_OBJECT_UI      =19,   ///<���Ӷ���
	XC_WIDGET_UI      =20,   ///<�������
	//Ԫ��
	XC_ELE            =21,   ///<����Ԫ��
	XC_ELE_LAYOUT     =53,   ///<����Ԫ��
	XC_LAYOUT_FRAME   =54,   ///<��ʽ����
	XC_BUTTON         =22,   ///<��ť
	XC_EDIT           =45,   ///<�༭��
	XC_EDITOR         =46,   ///<����༭��

	XC_RICHEDIT       =23,   ///<���ı��༭��(�ѷ���), ��ʹ��XC_EDIT
	XC_COMBOBOX       =24,   ///<������Ͽ�
	XC_SCROLLBAR      =25,   ///<������
	XC_SCROLLVIEW     =26,   ///<������ͼ
	XC_LIST           =27,   ///<�б�
	XC_LISTBOX        =28,   ///<�б��
	XC_LISTVIEW       =29,   ///<�б���ͼ,��ͼ��
	XC_TREE           =30,   ///<�б���
	XC_MENUBAR        =31,   ///<�˵���
	XC_SLIDERBAR      =32,   ///<������
	XC_PROGRESSBAR    =33,   ///<������
	XC_TOOLBAR        =34,   ///<������
	XC_MONTHCAL       =35,   ///<������Ƭ
	XC_DATETIME       =36,   ///<����ʱ��
	XC_PROPERTYGRID   =37,   ///<��������
	XC_EDIT_COLOR     =38,   ///<��ɫѡ���
	XC_EDIT_SET       =39,   ///<���ñ༭��
	XC_TABBAR         =40,   ///<tab��
	XC_TEXTLINK       =41,   ///<�ı����Ӱ�ť

	XC_PANE                 =42,   ///<����
	XC_PANE_SPLIT           =43,   ///<�����϶��ָ���
	XC_MENUBAR_BUTTON       =44,   ///<�˵����ϵİ�ť
//	XC_TOOLBAR_BUTTON       =45,   ///<�������ϰ�ť
//	XC_PROPERTYPAGE_LABEL   =46,   ///<����ҳ��ǩ��ť
//	XC_PIER                 =47,   ///<����ͣ����ͷ
//	XC_BUTTON_MENU          =48,   ///<�����˵���ť
//	XC_VIRTUAL_ELE          =49,   ///<����Ԫ��
	XC_EDIT_FILE            =50,   ///<EditFile �ļ�ѡ��༭��
	XC_EDIT_FOLDER          =51,   ///<EditFolder  �ļ���ѡ��༭��
	XC_LIST_HEADER          =52,   ///<�б�ͷԪ��

	XC_SHAPE             =61,    ///<��״����
	XC_SHAPE_TEXT        =62,    ///<��״����-�ı�
	XC_SHAPE_PICTURE     =63,    ///<��״����-ͼƬ
	XC_SHAPE_RECT        =64,    ///<��״����-����
	XC_SHAPE_ELLIPSE     =65,    ///<��״����-Բ
	XC_SHAPE_LINE        =66,    ///<��״����-ֱ��
	XC_SHAPE_GROUPBOX    =67,    ///<��״����-���
	XC_SHAPE_GIF         =68,    ///<��״����-GIF
	XC_SHAPE_TABLE       =69,    ///<��״����-���

	//��������
	XC_MENU              =81,   ///<�����˵�
	XC_IMAGE             =82,         ///<ͼƬ
	XC_IMAGE_TEXTURE     =XC_IMAGE,   ///<ͼƬ����,ͼƬԴ,ͼƬ�ز�
	XC_HDRAW             =83,   ///<��ͼ����
	XC_FONT              =84,   ///<�Ų�����
//	XC_FLASH             =85,   ///<flash   
//	XC_PANE_CELL         =86,   ///<...
//	XC_WEB               =87,   ///<...
	XC_IMAGE_FRAME       =88,   ///<ͼƬ֡,ָ��ͼƬ����Ⱦ����
	XC_SVG               =89,   ///<SVGʸ��ͼ��

	XC_LAYOUT_OBJECT      =101, ///<���ֶ���LayoutObject, �ѷ���
	XC_ADAPTER            =102, ///<����������Adapter
	XC_ADAPTER_TABLE      =103, ///<����������AdapterTable
	XC_ADAPTER_TREE       =104, ///<����������AdapterTree
	XC_ADAPTER_LISTVIEW   =105, ///<����������AdapterListView
	XC_ADAPTER_MAP        =106, ///<����������AdapterMap
	XC_BKINFOM            =116, ///<����������

	//��ʵ�����,ֻ�������жϲ���
	XC_LAYOUT_LISTVIEW     = 111,  ///<�ڲ�ʹ��
	XC_LAYOUT_LIST         = 112,  ///<�ڲ�ʹ��
	XC_LAYOUT_OBJECT_GROUP = 113,  ///<�ڲ�ʹ��
	XC_LAYOUT_OBJECT_ITEM  = 114,  ///<�ڲ�ʹ��
	XC_LAYOUT_PANEL        = 115,  ///<�ڲ�ʹ��

	//��ʵ�����,ֻ�������ж�����
//	XC_LIST_ITEM       =121,     //�б���ģ�� list_item
//	XC_LISTVIEW_GROUP  =122,
//	XC_LISTVIEW_ITEM   =123,
	XC_LAYOUT_BOX      =124,      ///<���ֺ���,��������

	XC_ANIMATION_SEQUENCE =131,   ///<��������
	XC_ANIMATION_GROUP    =132,   ///<����ͬ����
	XC_ANIMATION_ITEM     =133,   ///<������
};
///@}


/// @defgroup group_ObjectTypeEx   ������չ����(XC_OBJECT_TYPE_EX,������չ)
/// @{
enum XC_OBJECT_TYPE_EX
{
	xc_ex_error=-1,        ///<��������
	button_type_default=0, ///<Ĭ������
	button_type_radio,     ///<��ѡ��ť
	button_type_check,     ///<��ѡ��ť
	button_type_close,     ///<���ڹرհ�ť
	button_type_min,       ///<������С����ť
	button_type_max,       ///<������󻯻�ԭ��ť

	element_type_layout,   ///<����Ԫ��,���ò��ֹ��ܵ�Ԫ��
};
///@}


/// @defgroup group_ObjectStyle ������ʽ(XC_OBJECT_STYLE,�����������)
/// @{
enum  XC_OBJECT_STYLE
{
	xc_style_default     =0,
	button_style_default = xc_style_default,  ///<Ĭ�Ϸ��
	button_style_radio,                 ///<��ѡ��ť
	button_style_check,                 ///<��ѡ��ť
	button_style_icon,                  ///<ͼ�갴ť		   
	button_style_expand,                ///<չ����ť
	
	button_style_close,			        ///<�رհ�ť
	button_style_max,			        ///<��󻯰�ť
	button_style_min,			        ///<��С����ť

	button_style_scrollbar_left,         ///<ˮƽ������-��ť
	button_style_scrollbar_right,        ///<ˮƽ������-�Ұ�ť
	button_style_scrollbar_up,           ///<��ֱ������-�ϰ�ť
	button_style_scrollbar_down,         ///<��ֱ������-�°�ť
	button_style_scrollbar_slider_h,     ///<ˮƽ������-����
	button_style_scrollbar_slider_v,     ///<��ֱ������-����

	button_style_tabBar,                 ///<Tab��-��ť
	button_style_slider,                 ///<������-����

	button_style_toolBar,                ///<������-��ť
	button_style_toolBar_left,           ///<������-�������ť
	button_style_toolBar_right,          ///<������-�ҹ�����ť

	button_style_pane_close,             ///<����-�رհ�ť
	button_style_pane_lock,              ///<����-������ť
	button_style_pane_menu,              ///<����-�˵���ť

	button_style_pane_dock_left,         ///<����-��ͷ��ť��
	button_style_pane_dock_top,          ///<����-��ͷ��ť��
	button_style_pane_dock_right,        ///<����-��ͷ��ť��
	button_style_pane_dock_bottom,       ///<����-��ͷ��ť��

	element_style_frameWnd_dock_left,    ///<��ܴ���-ͣ����ͷ��
	element_style_frameWnd_dock_top,     ///<��ܴ���-ͣ����ͷ��
	element_style_frameWnd_dock_right,   ///<��ܴ���-ͣ����ͷ��
	element_style_frameWnd_dock_bottom,  ///<��ܴ���-ͣ����ͷ��

	element_style_toolBar_separator,     ///<������-�ָ���
	listBox_style_comboBox,              ///<��Ͽ�-�����б��  ,������Ͽ򵯳���ListBox
};
///@}

/// @defgroup group_WindowStyle  ������ʽ(window_style_)
/// @{
enum  window_style_
{
	window_style_nothing         = 0x0000,   ///<ʲôҲû��
	window_style_caption         = 0x0001,   ///<������
	window_style_border          = 0x0002,   ///<�߿�,���û��ָ��,��ô�߿��СΪ0
	window_style_center          = 0x0004,   ///<���ھ���
	window_style_drag_border     = 0x0008,   ///<�϶����ڱ߿�
	window_style_drag_window     = 0x0010,   ///<�϶�����
	window_style_allow_maxWindow = 0x0020,   ///<���������

	window_style_icon            = 0x0040,   ///<ͼ��
	window_style_title           = 0x0080,   ///<����
	window_style_btn_min         = 0x0100,   ///<���ư�ť-��С��
	window_style_btn_max         = 0x0200,   ///<���ư�ť-���
	window_style_btn_close       = 0x0400,   ///<���ư�ť-�ر�

	///������ʽ-���ư�ť: ���� ͼ��, ����, �رհ�ť, ��󻯰�ť, ��С����ť
	window_style_default=(window_style_caption | window_style_border | window_style_center |\
		window_style_drag_border | window_style_allow_maxWindow | window_style_icon |\
		window_style_title | window_style_btn_min | window_style_btn_max | window_style_btn_close),

	///������ʽ-��: ����
	window_style_simple=(window_style_caption | window_style_border | window_style_center | window_style_drag_border | window_style_allow_maxWindow),

	///������ʽ-��������: ͼ��, ����, �رհ�ť
	window_style_pop = (window_style_caption | window_style_border | window_style_center | \
		window_style_drag_border | window_style_allow_maxWindow | window_style_icon | \
		window_style_title | window_style_btn_close),

	///ģ̬������ʽ-���ư�ť: ����, ͼ��, ����, �رհ�ť
	window_style_modal=(window_style_caption | window_style_border | window_style_center |\
		window_style_icon | window_style_title | window_style_btn_close),
	
	///ģ̬������ʽ-��: ����
	window_style_modal_simple = (window_style_caption | window_style_border | window_style_center),
};

///@}
///@}

/////////////////////////////////////////////////////////////////////
/////////////////////�궨��///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/// @defgroup group_macro_def  �궨��
/// @{

#ifdef _DEBUG
#define XTRACEA   _xtrace
#define XTRACE    _xtracew
#define XERRORA   XTRACEA 
#define XERROR    XTRACE
#else
#define XTRACEA
#define XTRACE
#define XERROR 
#define XERRORW
#endif

#define  XC_GetObjectByUID_(T)  XC_GetObjectByUID(XRes_GetIDValue(L#T))
#define  GetLayoutFile()        GetLayoutFile()
#define  XC_LAYOUT_FILE(file)   const wchar_t*  GetLayoutFile(){ return file; };
#define  XC_EVENT_DECLARE_MARK
#define  XC_EVENT_REGISTER_MARK
#define  XC_EVENT_IMPLEMENT_MARK(T)

#define  CLOUDUI_flag_openUrl       1
#define  CLOUDUI_flag_downloadFile  2
#define  CLOUDUI_flag_downloadFileComplete      3
#define  CLOUDUI_flag_complete      4

/// @name  ����λ��
/// @{
#define  WINDOW_TOP            1 //��
#define  WINDOW_BOTTOM         2 //��
#define  WINDOW_LEFT           3 //��
#define  WINDOW_RIGHT          4 //��
#define  WINDOW_TOPLEFT        5 //���Ͻ�
#define  WINDOW_TOPRIGHT       6 //���Ͻ�
#define  WINDOW_BOTTOMLEFT     7 //���½�
#define  WINDOW_BOTTOMRIGHT    8 //���½�
#define  WINDOW_CAPTION        9 //�������ƶ���������
#define  WINDOW_BODY           10
/// @}

/// @name  ����ID
/// @{
#define  XC_ID_ROOT            0   ///<���ڵ�
#define  XC_ID_ERROR          -1   ///<ID����
#define  XC_ID_FIRST          -2   ///<���뿪ʼλ��
#define  XC_ID_LAST           -3   ///<����ĩβλ��
/// @}

///@name �˵�ID , ��ǰδʹ��
///@{
#define  IDM_CLIP          1000000000    ///<����
#define  IDM_COPY          1000000001    ///<����
#define  IDM_PASTE         1000000002    ///<ճ��
#define  IDM_DELETE        1000000003    ///<ɾ��
#define  IDM_SELECTALL     1000000004    ///<ȫѡ
#define  IDM_DELETEALL     1000000005    ///<���
///@}


//����˵� ��ǰδʹ��
#define  IDM_LOCK          1000000006    ///<����
#define  IDM_DOCK          1000000007    ///<ͣ��
#define  IDM_FLOAT         1000000008    ///<����
#define  IDM_HIDE          1000000009    ///<����

//#define  edit_style_no        0  ///<��Ч��ʽ
#define  edit_style_default   1  ///<edit Ĭ����ʽ

/// @}

/////////////////////////////////////////////////////////////////////
/////////////////////�����¼�/////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

//������Ϣ
/**
@addtogroup wndMSG

<hr>
<h2>Windows ��׼��Ϣ</h2>
- @ref WM_PAINT ���ڻ�����Ϣ
- @ref WM_CLOSE ���ڹر���Ϣ.
- @ref WM_DESTROY ����������Ϣ.
- @ref WM_NCDESTROY ���ڷǿͻ���������Ϣ.
- @ref WM_LBUTTONDOWN ����������������Ϣ
- @ref WM_LBUTTONUP ����������������Ϣ.
- @ref WM_RBUTTONDOWN ��������Ҽ�������Ϣ.
- @ref WM_RBUTTONUP ��������Ҽ�������Ϣ.
- @ref WM_LBUTTONDBLCLK ����������˫����Ϣ.
- @ref WM_RBUTTONDBLCLK ��������Ҽ�˫����Ϣ.
- @ref WM_MOUSEMOVE ��������ƶ���Ϣ.
- @ref WM_MOUSEHOVER ���������ͣ��Ϣ
- @ref WM_MOUSELEAVE ��������뿪��Ϣ.
- @ref WM_MOUSEWHEEL ���������ֹ�����Ϣ.
- @ref WM_CAPTURECHANGED ������겶��ı���Ϣ.
- @ref WM_KEYDOWN ���ڼ��̰�����Ϣ.
- @ref WM_KEYUP ���ڼ��̵�����Ϣ.
- @ref WM_CHAR       �����ַ���Ϣ.
- @ref WM_SIZE ���ڴ�С�ı���Ϣ.
- @ref WM_EXITSIZEMOVE �����˳��ƶ��������Сģʽѭ���ģ�����μ�MSDN.
- @ref WM_TIMER ���ڶ�ʱ����Ϣ.
- @ref WM_SETFOCUS ���ڻ�ý���.
- @ref WM_KILLFOCUS ����ʧȥ����.
- @ref WM_SETCURSOR  �������������.
- @ref WM_DROPFILES  �϶��ļ�������.
- @ref other ����Windowsϵͳ��Ϣ,�������Զ����Windows��Ϣ.

<hr>
@anchor WM_PAINT WM_PAINT ���ڻ�����Ϣ
@code   int CALLBACK OnWndDrawWindow(HDRAW hDraw,BOOL *pbHandled) @endcode
@param  hDraw   ͼ�λ��ƾ��.

<hr>
@anchor WM_CLOSE WM_CLOSE ���ڹر���Ϣ.
@code   int CALLBACK OnWndClose(BOOL *pbHandled) @endcode

<hr>
@anchor WM_DESTROY WM_DESTROY ����������Ϣ.
@code   int CALLBACK OnWndDestroy(BOOL *pbHandled)  @endcode

<hr>
@anchor WM_NCDESTROY WM_NCDESTROY ���ڷǿͻ���������Ϣ.
@code   int CALLBACK OnWndNCDestroy(BOOL *pbHandled) @endcode

<hr>
@anchor WM_LBUTTONDOWN WM_LBUTTONDOWN ����������������Ϣ
@code   int CALLBACK OnWndLButtonDown(UINT nFlags,POINT *pPt,BOOL *pbHandled) @endcode
@param  flags   ��μ�MSDN WM_LBUTTONDOWN.
@param  pPt     ��������.

<hr>
@anchor WM_LBUTTONUP WM_LBUTTONUP ����������������Ϣ.
@code   int CALLBACK OnWndLButtonUp(UINT nFlags,POINT *pPt,BOOL *pbHandled) @endcode
@param  flags   ��μ�MSDN WM_LBUTTONUP.
@param  pPt     ��������.

<hr>
@anchor WM_RBUTTONDOWN WM_RBUTTONDOWN ��������Ҽ�������Ϣ.
@code   int CALLBACK OnWndRButtonDown(UINT nFlags,POINT *pPt,BOOL *pbHandled) @endcode
@param  flags   ��μ�MSDN WM_RBUTTONDOWN.
@param  pPt     ��������.

<hr>
@anchor WM_RBUTTONUP WM_RBUTTONUP ��������Ҽ�������Ϣ.
@code   int CALLBACK OnWndRButtonUp(UINT nFlags,POINT *pPt,BOOL *pbHandled) @endcode
@param  flags   ��μ�MSDN WM_RBUTTONUP.
@param  pPt     ��������.

<hr>
@anchor WM_LBUTTONDBLCLK WM_LBUTTONDBLCLK ����������˫����Ϣ.
@code   int CALLBACK OnWndLButtonDBClick(UINT nFlags,POINT *pPt,BOOL *pbHandled) @endcode
@param  flags   ��μ�MSDN WM_LBUTTONDBLCLK.
@param  pPt     ��������.

<hr>
@anchor WM_RBUTTONDBLCLK WM_RBUTTONDBLCLK ��������Ҽ�˫����Ϣ.
@code   int CALLBACK OnWndRButtonDBClick(UINT nFlags,POINT *pPt,BOOL *pbHandled) @endcode
@param  flags   ��μ�MSDN WM_RBUTTONDBLCLK.
@param  pPt     ��������.

<hr>
@anchor WM_MOUSEMOVE WM_MOUSEMOVE ��������ƶ���Ϣ.
@code   int CALLBACK OnWndMouseMove(UINT nFlags,POINT *pPt,BOOL *pbHandled)  @endcode
@param  flags   ��μ�MSDN WM_MOUSEMOVE wParam����.
@param  pPt     ��������.

<hr>
@anchor WM_MOUSEHOVER WM_MOUSEHOVER ���������ͣ��Ϣ.
@code   int CALLBACK OnWndMouseHover(UINT nFlags,POINT *pPt,BOOL *pbHandled) @endcode
@param  flags  ��μ�MSDN WM_MOUSEHOVER��ϢwParam����.
@param  pPt    ���λ��

<hr>
@anchor WM_MOUSELEAVE WM_MOUSELEAVE ��������뿪��Ϣ.
@code   int CALLBACK OnWndMouseLeave(BOOL *pbHandled) @endcode

<hr>
@anchor WM_MOUSEWHEEL WM_MOUSEWHEEL ���������ֹ�����Ϣ.
@code   int CALLBACK OnWndMouseWheel(UINT nFlags,POINT *pPt,BOOL *pbHandled) @endcode
@param  flags   ��μ�MSDN WM_MOUSEWHEEL��ϢwParam����.
@param  pPt     ��������.

<hr>
@anchor WM_CAPTURECHANGED WM_CAPTURECHANGED ������겶��ı���Ϣ.
@code   int CALLBACK OnWndCaptureChanged(HWND hWnd,BOOL *pbHandled) @endcode
@param  hWnd    �����겶��Ĵ��ھ��.

<hr>
@anchor WM_KEYDOWN WM_KEYDOWN ���ڼ��̰�����Ϣ.
@code   int CALLBACK OnWndKeyDown(WPARAM wParam,LPARAM lParam,BOOL *pbHandled) @endcode
@note   wParam,lParam:��μ�MSDN WM_KEYDOWN.
<hr>
@anchor WM_KEYUP WM_KEYUP ���ڼ��̵�����Ϣ.
@code   int CALLBACK OnWndKeyUp(WPARAM wParam,LPARAM lParam,BOOL *pbHandled) @endcode
@note   wParam,lParam:��μ�MSDN WM_KEYUP.

<hr>
@anchor  WM_CHAR WM_CHAR �����ַ�������Ϣ.
@code    int CALLBACK OnWndChar(WPARAM wParam,LPARAM lParam,BOOL *pbHandled) @endcode
@note    wParam,lParam:��μ�MSDN WM_CHAR.

<hr>
@anchor WM_SIZE WM_SIZE ���ڴ�С�ı���Ϣ.
@code   int CALLBACK OnWndSize(UINT nFlags,SIZE *pSize,BOOL *pbHandled) @endcode
@param  flags   ��μ�MSDN WM_SIZE��ϢwParam����.
@param  pSize   ���ڴ�С.

<hr>
@anchor WM_EXITSIZEMOVE WM_EXITSIZEMOVE �����˳��ƶ��������Сģʽѭ��������μ�MSDN.
@code   int CALLBACK OnWndExitSizeMove(BOOL *pbHandled) @endcode

<hr>
@anchor WM_TIMER WM_TIMER ���ڶ�ʱ����Ϣ.
@code   int CALLBACK OnWndTimer(UINT nIDEvent,BOOL *pbHandled) @endcode
@param  nIDEnent ��ʱ����ʾ��.
@param  uElapse  ָ����������ϵͳ���������ĺ�����,������GetTickCount�����ķ���ֵ.

<hr>
@anchor WM_SETFOCUS WM_SETFOCUS ���ڻ�ý���.
@code   int CALLBACK OnWndSetFocus(BOOL *pbHandled) @endcode

<hr>
@anchor WM_KILLFOCUS WM_KILLFOCUS ����ʧȥ����.
@code   int CALLBACK OnWndKillFocus(BOOL *pbHandled) @endcode

<hr>
@anchor  WM_SETCURSOR WM_SETCURSOR �������������.
@code    int CALLBACK OnWndSetCursor(WPARAM wParam,LPARAM lParam,BOOL *pbHandled) @endcode
@note    wParam,lParam:��μ�MSDN WM_SETCURSOR.

<hr>
@anchor  WM_DROPFILES WM_DROPFILES �϶��ļ���������Ϣ,������:XWnd_EnableDragFiles()
@code    int CALLBACK OnDropFiles(HDROP hDropInfo , BOOL *pbHandled) @endcode
@note    ��μ�MSDN WM_DROPFILES.

<hr>
@anchor other ����Windowsϵͳ��Ϣ,�������Զ����Windows��Ϣ.
@code   int CALLBACK OnWndOther(WPARAM wParam,LPARAM lParam,BOOL *pbHandled) @endcode
@param  wParam  ��Ϣ����.
@param  lParam  ��Ϣ����.
@note   ������Ϣ��μ�MSDN.
@{
*/

//������Ϣ-����ϵͳ�ǿͻ�����Ϣ
#define  XWM_EVENT_ALL        WM_APP+1000 //�¼�Ͷ�� -------������-------����Ҫע��

//wParam:left-top�������; lParam:right-bottom�������; �����2������Ϊ��,��ô�ػ���������
//#define  XWM_REDRAW           WM_APP+1007  //�����ػ���ʱ ----������-----�ڲ��Զ�����Ϣ

//�ػ�Ԫ��,�ڲ�ʹ��
#define  XWM_REDRAW_ELE       0x7000+1 //�ػ�Ԫ�� wParam:Ԫ�ؾ��, lParam:RECT*���ڴ�������

///@brief ������Ϣ����
///@code  int CALLBACK OnWndProc(UINT message, WPARAM wParam, LPARAM lParam, BOOL *pbHandled)  @endcode
#define  XWM_WINDPROC         0x7000+2    //ע�ᴰ�ڴ������

#define  XWM_DRAW_T           0x7000+3    //���ڻ���,�ڲ�ʹ��, wParam:0, lParam:0

#define  XWM_TIMER_T          0x7000+4    //�ڲ�ʹ��, wParam:hXCGUI, lParam:ID

#define  XWM_CLOUDUI_DOWNLOADFILE_COMPLETE   0x7000+6  //�ڲ�ʹ��

#define  XWM_CLOUNDUI_OPENURL_WAIT    0x7000+7 //�ڲ�ʹ��

#define  XWM_CALL_UI_THREAD   0x7000+8     //�ڲ�ʹ��

/// @brief  �Ųʶ�ʱ��,��ϵͳ��ʱ��,ע����ϢXWM_TIMER����
/// @code  int CALLBACK OnWndXCTimer(UINT nTimerID,BOOL *pbHandled)  @endcode
/// @param nTimerID   ��ʱ��ID
#define  XWM_XC_TIMER         0x7000+5 //wParam:��ʱ��ID, lParam:0

///@brief �˵�����
///@code  int CALLBACK OnWndMenuPopup(HMENUX hMenu, BOOL *pbHandled) @endcode
#define  XWM_MENU_POPUP       0x7000+11

///@brief �˵���������
///@code  int CALLBACK OnWndMenuPopupWnd(HMENUX hMenu,menu_popupWnd_ *pInfo,BOOL *pbHandled) @endcode
#define  XWM_MENU_POPUP_WND     0x7000+12    

///@brief �˵�ѡ��
///@code  int CALLBACK OnWndMenuSelect(int nID,BOOL *pbHandled) @endcode
#define  XWM_MENU_SELECT       0x7000+13 //�˵�ѡ�� wParam:�˵���ID, lParam:0

///@brief �˵��˳�
///@code  int CALLBACK OnWndMenuExit(BOOL *pbHandled) @endcode
#define  XWM_MENU_EXIT         0x7000+14 //�˵��˳� wParam:0, lParam:0

///@brief ���Ʋ˵�����, ���øù�����Ҫ����XMenu_EnableDrawBackground().
///@code  int CALLBACK OnWndMenuDrawBackground(HDRAW hDraw,menu_drawBackground_ *pInfo,BOOL *pbHandled) @endcode
#define  XWM_MENU_DRAW_BACKGROUND   0x7000+15 //���Ʋ˵�����

/// @brief ���Ʋ˵����¼�, ���øù�����Ҫ����XMenu_EnableDrawItem().
/// @code  int CALLBACK OnMenuDrawItem(HDRAW hDraw,menu_drawItem_* pInfo,BOOL *pbHandled) @endcode
#define  XWM_MENU_DRAWITEM             0x7000+16  //���Ʋ˵��� 

#define  XWM_COMBOBOX_POPUP_DROPLIST   0x7000+17  //������������б�,�ڲ�ʹ��

///@brief ��������
///@code  int CALLBACK OnWndFloatPane(HWINDOW hFloatWnd, HELE hPane, BOOL *pbHandled) @endcode
#define  XWM_FLOAT_PANE               0x7000+18 //��������, ����ӿ�ܴ����е���,��ɸ�������

///@brief ���ڻ��������Ϣ
///@code   int CALLBACK OnWndDrawWindowEnd(HDRAW hDraw,BOOL *pbHandled) @endcode
#define  XWM_PAINT_END               0x7000+19

///@brief ���ڻ�����ɲ����Ѿ���ʾ����Ļ
///@code   int CALLBACK OnWndDrawWindowDisplay(BOOL *pbHandled) @endcode
#define  XWM_PAINT_DISPLAY           0x7000+20

///@brief  ��ܴ�����ͷ��������  ���û������ͷ�ϵİ�ťʱ,��ʾ��Ӧ�Ĵ���,��ʧȥ����ʱ�Զ����ش���
///@param  hWindowDock �������񴰿ھ��
///@param  hPane       ������
///@code   int CALLBACK OnWndDocPopup(HWINDOW hWindowDock,  HELE hPane, BOOL *pbHandled) @endcode
#define  XWM_DOCK_POPUP              0x7000+21

///@brief  ���������϶�   �û��϶����������ƶ�,��ʾͣ����ʾ
///@param  hFloatWnd �϶��ĸ������ھ��
///@param  hArray    HWINDOW array[6],����ͣ����ʾ���ھ������,��6����Ա,�ֱ�Ϊ:[0]�м�ʮ��, [1]���,[2]����,[3]�Ҳ�,[4]�ײ�, [5]ͣ��λ��Ԥ�� 
///@code   int CALLBACK OnWndFloatWndDrag(HWINDOW hFloatWnd, HWINDOW* hArray, BOOL *pbHandled) @endcode
#define  XWM_FLOATWND_DRAG           0x7000+22


//������ʾ����
//int CALLBACK OnWndPaneShow(HELE hPane, BOOL bShow, BOOL *pbHandled);
#define  XWM_PANE_SHOW              0x7000+23
///@}

/////////////////////////////////////////////////////////////////////
/////////////////Ԫ���¼�/////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//Ԫ���¼�
/// @addtogroup eleEvents
/// @{


/// @brief Ԫ�ش�������¼�.
/// @code  int CALLBACK OnEventProc(UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL *pbHandled) @endcode
#define  XE_ELEPROCE         1     ///Ԫ���¼��������

/// @brief Ԫ�ػ����¼�
/// @code  int CALLBACK OnDraw(HDRAW hDraw,BOOL *pbHandled)  @endcode
#define  XE_PAINT            2

/// @brief ��Ԫ�ؼ���Ԫ�ػ�������¼�.���øù�����Ҫ����XEle_EnableEvent_XE_PAINT_END()
/// @code  int CALLBACK OnPaintEnd(HDRAW hDraw,BOOL *pbHandled) @endcode
#define  XE_PAINT_END        3     //Ԫ�ؼ���Ԫ�ػ�����ɺ󴥷�,��Ҫ���øù���,XEle_EnableEvent_XE_PAINT_END()

/// @brief ������ͼ�����¼�.
/// @code int CALLBACK OnDrawScrollView(HDRAW hDraw,BOOL *pbHandled) @endcode
#define  XE_PAINT_SCROLLVIEW   4

/// @brief Ԫ������ƶ��¼�.
/// @code  int CALLBACK OnMouseMove(UINT nFlags, POINT *pPt, BOOL *pbHandled)  @endcode
#define  XE_MOUSEMOVE        5

/// @brief Ԫ���������¼�.
/// @code  int CALLBACK OnMouseStay(BOOL *pbHandled) @endcode
#define  XE_MOUSESTAY        6   ///ͣ��

/// @brief Ԫ�������ͣ�¼�.
/// @code  int CALLBACK OnMouseHover(UINT nFlags, POINT *pPt, BOOL *pbHandled) @endcode
#define  XE_MOUSEHOVER       7   ///��ͣ

/// @brief Ԫ������뿪�¼�.
/// @param  hEleStay ��������ͣ��״̬��Ԫ��.
/// @code  int CALLBACK OnMouseLeave(HELE hEleStay,BOOL *pbHandled) @endcode
#define  XE_MOUSELEAVE       8   ///�뿪

/// @brief Ԫ�������ֹ����¼�. ����ǹ�����ͼ��Ҫ���� XEle_EnableEvent_XE_MOUSEWHEEL()
/// @code  int CALLBACK OnMouseWheel(UINT nFlags,POINT *pPt,BOOL *pbHandled) @endcode
/// @param flags      ��MSDN��WM_MOUSEWHEEL��ϢwParam����˵��.
#define  XE_MOUSEWHEEL         9  //������  wParam:��ʶ,lParam:POINT����

/// @brief �����������¼�.
/// @code  int CALLBACK OnLButtonDown(UINT nFlags, POINT *pPt,BOOL *pbHandled)  @endcode
#define  XE_LBUTTONDOWN        10

/// @brief �����������¼�.
/// @code  int CALLBACK OnLButtonUp(UINT nFlags, POINT *pPt,BOOL *pbHandled) @endcode
#define  XE_LBUTTONUP          11

/// @brief ����Ҽ������¼�.
/// @code  int CALLBACK OnRButtonDown(UINT nFlags, POINT *pPt,BOOL *pbHandled)  @endcode
#define  XE_RBUTTONDOWN        12

/// @brief ����Ҽ������¼�.
/// @code int CALLBACK OnRButtonUp(UINT nFlags, POINT *pPt,BOOL *pbHandled)  @endcode
#define  XE_RBUTTONUP          13

/// @brief ������˫���¼�.
/// @code   int CALLBACK OnLButtonDBClick(UINT nFlags, POINT *pPt,BOOL *pbHandled) @endcode
#define  XE_LBUTTONDBCLICK     14


//#define  XE_RBUTTONDBCLICK     15


/// @brief �Ųʶ�ʱ��,��ϵͳ��ʱ��,��ʱ����Ϣ XM_TIMER.
/// @code int CALLBACK OnEleXCTimer(UINT nTimerID,BOOL *pbHandled) @endcode
/// @param hEle        Ԫ�ؾ��.
/// @param nTimerID    ��ʱ��ID.
#define  XE_XC_TIMER             16  //wParam:��ʱ��ID, lParam:0

/// @brief ���������¼�. ��ͣʹ��
/// @code int CALLBACK OnAdjustLayout(int nFlags, UINT nAdjustNo, BOOL *pbHandled) @endcode
#define  XE_ADJUSTLAYOUT         17

/// @brief ������������¼�.
/// @code int CALLBACK OnAdjustLayoutEnd(int nFlags, UINT nAdjustNo, BOOL *pbHandled) @endcode
#define  XE_ADJUSTLAYOUT_END     18

/// @brief Ԫ�ػ�ý����¼�.
/// @code int CALLBACK OnSetFocus(BOOL *pbHandled) @endcode
#define  XE_SETFOCUS           31

/// @brief Ԫ��ʧȥ�����¼�.
/// @code int CALLBACK OnKillFocus(BOOL *pbHandled) @endcode
#define  XE_KILLFOCUS          32

/// @brief Ԫ�ؼ��������¼�. �������Ӷ���֮ǰ����
/// @code int CALLBACK OnDestroy(BOOL *pbHandled) @endcode
#define  XE_DESTROY            33   //Ԫ������

/// @brief Ԫ����������¼�. �������Ӷ���֮�󴥷�
/// @code int CALLBACK OnDestroyeEnd(BOOL *pbHandled) @endcode
#define  XE_DESTROY_END        42   //Ԫ������

/// @brief Ԫ�ش�С�ı��¼�.
/// @code int CALLBACK OnSize(int nFlags, UINT nAdjustNo, BOOL *pbHandled) @endcode
/// @param  nFlags  adjustLayout_
#define  XE_SIZE               36

/// @brief Ԫ����ʾ�����¼�.
/// @code  int CALLBACK OnShow(BOOL bShow,BOOL *pbHandled) @endcode
#define  XE_SHOW               37  //wParam:TRUE��FALSE, lParam:0

/// @brief Ԫ�����������¼�.
/// @code  int CALLBACK OnSetFont(BOOL *pbHandled) @endcode
#define  XE_SETFONT           38

/// @brief Ԫ�ذ����¼�.
/// @code  int CALLBACK OnEventKeyDown(WPARAM wParam,LPARAM lParam,BOOL *pbHandled) @endcode
/// @note  wParam,lParam:��μ�MSDN WM_KEYDOWN. 
#define  XE_KEYDOWN            39 //wParam��lParam�������׼��Ϣ��ͬ

/// @brief Ԫ�ذ����¼�.
/// @code  int CALLBACK OnEventKeyUp(WPARAM wParam,LPARAM lParam,BOOL *pbHandled) @endcode
/// @note  wParam,lParam:��μ�MSDN WM_KEYDOWN. 
#define  XE_KEYUP             40 //wParam��lParam�������׼��Ϣ��ͬ

/// @brief ͨ��TranslateMessage����������ַ��¼�.
/// @code  int CALLBACK OnEventChar(WPARAM wParam,LPARAM lParam,BOOL *pbHandled) @endcode
/// @note   wParam,lParam:��μ�MSDN WM_KEYDOWN. 
#define  XE_CHAR               41  //wParam��lParam�μ�MSDN

#define  XE_SYSKEYDOWN     42

#define  XE_SYSKEYUP       43

/// @brief Ԫ��������겶��.
/// @code int CALLBACK OnSetCapture(BOOL *pbHandled) @endcode
#define  XE_SETCAPTURE      51

/// @brief Ԫ��ʧȥ��겶��.
/// @code int CALLBACK OnKillCapture(BOOL *pbHandled) @endcode
#define  XE_KILLCAPTURE     52

/// @brief ���������
/// @code int CALLBACK OnSetCursor(WPARAM wParam,LPARAM lParam,BOOL *pbHandled) @endcode
#define  XE_SETCURSOR            53  // SetCursor

///@brief �˵�����
///@code  int CALLBACK OnMenuPopup(HMENUX hMenu, BOOL *pbHandled) @endcode
#define  XE_MENU_POPUP       57

///@brief �˵���������
///@code  int CALLBACK OnMenuPopupWnd(HMENUX hMenu,menu_popupWnd_* pInfo,BOOL *pbHandled) @endcode
#define  XE_MENU_POPUP_WND     58

/// @brief �����˵���ѡ���¼�.
/// @code  int CALLBACK OnMenuSelect(int nItem,BOOL *pbHandled) @endcode
/// @param nItem          �˵���id.
#define  XE_MENU_SELECT      59  //�˵���ѡ�� wParam:�˵�ID,lParam:0

///@brief ���Ʋ˵�����, ���øù�����Ҫ����XMenu_EnableDrawBackground().
///@code  int CALLBACK OnMenuDrawBackground(HDRAW hDraw,menu_drawBackground_ *pInfo,BOOL *pbHandled) @endcode
#define  XE_MENU_DRAW_BACKGROUND   60 //���Ʋ˵�����

/// @brief ���Ʋ˵����¼�, ���øù�����Ҫ����XMenu_EnableDrawItem().
/// @code  int CALLBACK OnMenuDrawItem(HDRAW hDraw,menu_drawItem_* pInfo,BOOL *pbHandled) @endcode
#define  XE_MENU_DRAWITEM    61  //���Ʋ˵��� 

/// @brief �����˵��˳��¼�.
/// @code  int CALLBACK OnMenuExit(BOOL *pbHandled) @endcode
#define  XE_MENU_EXIT        62 //�˵��˳�

/// @brief ��ť����¼�.
/// @code int CALLBACK OnBtnClick(BOOL *pbHandled) @endcode
#define  XE_BNCLICK            34

/// @brief ��ťѡ���¼�.
/// @code int CALLBACK OnButtonCheck(BOOL bCheck,BOOL *pbHandled) @endcode
#define  XE_BUTTON_CHECK       35  //��ťѡ���¼�

/// @brief ������ͼԪ��ˮƽ�����¼�,������ͼ����.
/// @code  int CALLBACK OnScrollViewScrollH(int pos,BOOL *pbHandled) @endcode
/// @param pos         ��ǰ������.
#define  XE_SCROLLVIEW_SCROLL_H    54  //������ͼ �����¼� wParam:������,lParam:0 (������ͼ����,����������ͼ�ѹ������)

/// @brief ������ͼԪ�ش�ֱ�����¼�,������ͼ����.
/// @code  int CALLBACK OnScrollViewScrollV(int pos,BOOL *pbHandled) @endcode
/// @param pos         ��ǰ������.
#define  XE_SCROLLVIEW_SCROLL_V    55  //������ͼ �����¼� wParam:������,lParam:0 (������ͼ����,����������ͼ�ѹ������)

/// @brief ������Ԫ�ع����¼�,����������.
/// @code  int CALLBACK OnSBarScroll(int pos,BOOL *pbHandled) @endcode
/// @param pos   ��ǰ������.
#define  XE_SBAR_SCROLL        56   //�����������¼� wParam:������,lParam:0 (����������)

/// @brief ������Ԫ��,����λ�øı��¼�.
/// @code  int CALLBACK OnSliderBarChange(int pos,BOOL *pbHandled) @endcode
#define  XE_SLIDERBAR_CHANGE   63

/// @brief ������Ԫ��,���ȸı��¼�.
/// @code  int CALLBACK OnProgressBarChange(int pos,BOOL *pbHandled) @endcode
#define  XE_PROGRESSBAR_CHANGE  64

/// @brief ��Ͽ������б���ѡ���¼�.
/// @code  int CALLBACK OnComboBoxSelect(int iItem,BOOL *pbHandled)  @endcode
#define  XE_COMBOBOX_SELECT       71   //��Ͽ���ѡ��  

/// @brief ��Ͽ������б���ѡ������¼�,�༭�������Ѿ��ı�.
/// @code  int CALLBACK OnComboBoxSelectEnd(int iItem,BOOL *pbHandled)  @endcode
#define  XE_COMBOBOX_SELECT_END   74   //��Ͽ���ѡ��  

/// @brief ��Ͽ������б����¼�.
/// @code  int CALLBACK OnComboBoxPopupList(HWINDOW hWindow,HELE hListBox,BOOL *pbHandled)  @endcode
#define  XE_COMBOBOX_POPUP_LIST   72

/// @brief ��Ͽ������б��˳��¼�.
/// @code  int CALLBACK OnComboBoxExitList(BOOL *pbHandled)  @endcode
#define  XE_COMBOBOX_EXIT_LIST    73

/// @brief �б��Ԫ��-��ģ�崴���¼�, ģ�帴�û�����������; �滻ģ����Ч�ж�nFlag,��Ϊ�ڲ�����ģ���Ƿ�ı�,���õ����ظ�
/// @code int CALLBACK OnListBoxTemplateCreate(listBox_item_* pItem, int nFlag, BOOL *pbHandled) @endcode
/// @param nFlag  0:״̬�ı�; 1:��ģ��ʵ��; 2:��ģ�帴�� 
#define  XE_LISTBOX_TEMP_CREATE     81

/// @brief �б��Ԫ��-��ģ�崴������¼�,ģ�帴�û�����������;�������½����Ǹ���,����Ҫ��������, ��Ϊ����ʱ��Ҫע���¼������ظ�ע��
/// @code int CALLBACK OnListBoxTemplateCreateEnd(listBox_item_* pItem, int nFlag, BOOL *pbHandled) @endcode
/// @param nFlag  0:״̬�ı�(����); 1:��ģ��ʵ��; 2:��ģ�帴��
#define  XE_LISTBOX_TEMP_CREATE_END     82
#define  XE_LISTBOX_TEMP_UPDATE   XE_LISTBOX_TEMP_CREATE_END

/// @brief �б��Ԫ��,��ģ������.
/// @code int CALLBACK OnListBoxTemplateDestroy(listBox_item_* pItem, int nFlag, BOOL *pbHandled) @endcode
/// @param  nFlag   0:��������;  1:�ƶ�������(���ᱻ����,��ʱ���汸��,����Ҫʱ������)
#define  XE_LISTBOX_TEMP_DESTROY    83

/// @brief �б��Ԫ��,��ģ���������. ��ͣ��
/// @code  int CALLBACK OnListBoxTemplateAdjustCoordinate(listBox_item_* pItem, BOOL *pbHandled) @endcode
#define  XE_LISTBOX_TEMP_ADJUST_COORDINATE  84

/// @brief �б��Ԫ��,������¼�.
/// @code  int CALLBACK OnListBoxDrawItem(HDRAW hDraw,listBox_item_* pItem,BOOL *pbHandled) @endcode
#define  XE_LISTBOX_DRAWITEM     85

/// @brief �б��Ԫ��,��ѡ���¼�.
/// @code  int CALLBACK OnListBoxSelect(int iItem,BOOL *pbHandled)  @endcode
#define  XE_LISTBOX_SELECT       86

/// @brief �б�Ԫ��-��ģ�崴���¼�,ģ�帴�û�����������;�滻ģ����Ч�ж�nFlag,��Ϊ�ڲ�����ģ���Ƿ�ı�,���õ����ظ�
/// @code  int CALLBACK OnListTemplateCreate(list_item_* pItem,int nFlag, BOOL *pbHandled) @endcode
/// @param nFlag  0:״̬�ı�; 1:��ģ��ʵ��; 2:��ģ�帴�� 
#define  XE_LIST_TEMP_CREATE     101

/// @brief �б�Ԫ��-��ģ�崴������¼�,ģ�帴�û�����������;�������½����Ǹ���,����Ҫ��������, ��Ϊ����ʱ��Ҫע���¼������ظ�ע��
/// @code  int CALLBACK OnListTemplateCreateEnd(list_item_* pItem, int nFlag, BOOL *pbHandled) @endcode
/// @param nFlag  0:״̬�ı�(����); 1:��ģ��ʵ��; 2:��ģ�帴��
#define  XE_LIST_TEMP_CREATE_END     102
#define  XE_LIST_TEMP_UPDATE  XE_LIST_TEMP_CREATE_END 

/// @brief �б�Ԫ��,��ģ������.
/// @code int CALLBACK OnListTemplateDestroy(list_item_* pItem, int nFlag, BOOL *pbHandled) @endcode
/// @param  nFlag   0:��������;  1:�ƶ�������(���ᱻ����,��ʱ���汸��,����Ҫʱ������)
#define  XE_LIST_TEMP_DESTROY    103

/// @brief �б�Ԫ��,��ģ���������. ��ͣ��
/// @code  typedef int CALLBACK OnListTemplateAdjustCoordinate(list_item_* pItem,BOOL *pbHandled) @endcode
#define  XE_LIST_TEMP_ADJUST_COORDINATE  104

/// @brief �б�Ԫ��,������.
/// @code  int CALLBACK OnListDrawItem(HDRAW hDraw,list_item_* pItem,BOOL *pbHandled) @endcode
#define  XE_LIST_DRAWITEM                105

/// @brief �б�Ԫ��,��ѡ���¼�.
/// @code  int CALLBACK OnListSelect(int iItem,BOOL *pbHandled) @endcode
#define  XE_LIST_SELECT                  106

/// @brief �б�Ԫ�ػ����б�ͷ��.
/// @code  int CALLBACK OnListHeaderDrawItem(HDRAW hDraw, list_header_item_* pItem, BOOL *pbHandled) @endcode
#define  XE_LIST_HEADER_DRAWITEM         107

/// @brief �б�Ԫ��,�б�ͷ�����¼�.
/// @code  int CALLBACK OnListHeaderClick(int iItem, BOOL *pbHandled) @endcode
#define  XE_LIST_HEADER_CLICK            108

/// @brief �б�Ԫ��,�б�ͷ���ȸı��¼�.
/// @code  int CALLBACK OnListHeaderItemWidthChange(int iItem, int nWidth BOOL *pbHandled) @endcode
#define  XE_LIST_HEADER_WIDTH_CHANGE     109

/// @brief �б�Ԫ��,�б�ͷ��ģ�崴��.
/// @code  int CALLBACK OnListHeaderTemplateCreate(list_header_item_* pItem,BOOL *pbHandled) @endcode
#define  XE_LIST_HEADER_TEMP_CREATE          110

/// @brief �б�Ԫ��,�б�ͷ��ģ�崴������¼�.
/// @code  int CALLBACK OnListHeaderTemplateCreateEnd(list_header_item_* pItem,BOOL *pbHandled) @endcode
#define  XE_LIST_HEADER_TEMP_CREATE_END      111

/// @brief �б�Ԫ��,�б�ͷ��ģ������.
/// @code int CALLBACK OnListHeaderTemplateDestroy(list_header_item_* pItem,BOOL *pbHandled) @endcode
#define  XE_LIST_HEADER_TEMP_DESTROY          112

/// @brief �б�Ԫ��,�б�ͷ��ģ���������. ��ͣ��
/// @code  typedef int CALLBACK OnListHeaderTemplateAdjustCoordinate(list_header_item_* pItem,BOOL *pbHandled) @endcode
#define  XE_LIST_HEADER_TEMP_ADJUST_COORDINATE  113


/// @brief �б���Ԫ��-��ģ�崴��,ģ�帴�û�����������; �滻ģ����Ч�ж�nFlag,��Ϊ�ڲ�����ģ���Ƿ�ı�,���õ����ظ�
/// @code  int CALLBACK OnTreeTemplateCreate(tree_item_* pItem,int nFlag, BOOL *pbHandled) @endcode
/// @param nFlag  0:״̬�ı�; 1:��ģ��ʵ��; 2:��ģ�帴�� 
#define  XE_TREE_TEMP_CREATE             121  

/// @brief �б���Ԫ��-��ģ�崴�����,ģ�帴�û�����������; �������½����Ǹ���,����Ҫ��������, ��Ϊ����ʱ��Ҫע���¼������ظ�ע��
/// @code  int CALLBACK OnTreeTemplateCreateEnd(tree_item_* pItem, int nFlag, BOOL *pbHandled) @endcode
/// @param nFlag  0:״̬�ı�(����); 1:��ģ��ʵ��; 2:��ģ�帴��
#define  XE_TREE_TEMP_CREATE_END         122
#define  XE_TREE_TEMP_UPDATE   XE_TREE_TEMP_CREATE_END

/// @brief �б���Ԫ��-��ģ������,ģ�帴�û�����������;
/// @code  int CALLBACK OnTreeTemplateDestroy(tree_item_* pItem, int nFlag, BOOL *pbHandled) @endcode
/// @param  nFlag   0:��������;  1:�ƶ�������(���ᱻ����,��ʱ���汸��,����Ҫʱ������)
#define  XE_TREE_TEMP_DESTROY            123 

/// @brief ��Ԫ��,��ģ��,����������. ��ͣ��
/// @code  int CALLBACK OnTreeTemplateAdjustCoordinate(tree_item_* pItem,BOOL *pbHandled) @endcode
#define  XE_TREE_TEMP_ADJUST_COORDINATE  124  

/// @brief ��Ԫ��,������.
/// @code  int CALLBACK OnTreeDrawItem(HDRAW hDraw,tree_item_* pItem,BOOL *pbHandled) @endcode
#define  XE_TREE_DRAWITEM                125  

/// @brief ��Ԫ��,��ѡ���¼�.
/// @code  int CALLBACK OnTreeSelect(int nItemID,BOOL *pbHandled) @endcode
/// @param nItemID  ��ID.
#define  XE_TREE_SELECT                 126

/// @brief ��Ԫ��,��չ�������¼�.
/// @code int CALLBACK OnTreeExpand(int id,BOOL bExpand,BOOL *pbHandled) @endcode
#define  XE_TREE_EXPAND                 127

/// @brief ��Ԫ��,�û������϶���, �ɶԲ���ֵ�޸�.
/// @code int CALLBACK OnTreeDragItemIng(tree_drag_item_* pInfo, BOOL *pbHandled) @endcode 
#define  XE_TREE_DRAG_ITEM_ING           128

/// @brief ��Ԫ��,�϶����¼�.
/// @code int CALLBACK OnTreeDragItem(tree_drag_item_* pInfo, BOOL *pbHandled) @endcode 
#define  XE_TREE_DRAG_ITEM               129

/// @brief �б���Ԫ��-��ģ�崴���¼�,ģ�帴�û�����������; �滻ģ����Ч�ж�nFlag,��Ϊ�ڲ�����ģ���Ƿ�ı�,���õ����ظ�
/// @code  int CALLBACK OnListViewTemplateCreate(listView_item_* pItem,int nFlag, BOOL *pbHandled) @endcode
/// @param nFlag  0:״̬�ı�(��ǰδʹ��); 1��ģ��ʵ��; 2��ģ�帴�� 
#define  XE_LISTVIEW_TEMP_CREATE           141

/// @brief �б���Ԫ��-��ģ�崴������¼�,ģ�帴�û�����������; �������½����Ǹ���,����Ҫ��������, ��Ϊ����ʱ��Ҫע���¼������ظ�ע��
/// @code  int CALLBACK OnListViewTemplateCreateEnd(listView_item_* pItem,int nFlag, BOOL *pbHandled) @endcode
/// @param nFlag  0:״̬�ı�(����,��ǰδʹ��); 1:��ģ��ʵ��; 2:��ģ�帴�� 
#define  XE_LISTVIEW_TEMP_CREATE_END           142
#define  XE_LISTVIEW_TEMP_UPDATE     XE_LISTVIEW_TEMP_CREATE_END

/// @brief �б���Ԫ��-��ģ������, ģ�帴�û�����������;
/// @code  int CALLBACK OnListViewTemplateDestroy(listView_item_* pItem, int nFlag, BOOL *pbHandled) @endcode
/// @param  nFlag   0:��������;  1:�ƶ��������б�(���ᱻ����, ��ʱ���汸��, ����Ҫʱ������)
#define  XE_LISTVIEW_TEMP_DESTROY           143

/// @brief �б���Ԫ��,��ģ���������.��ͣ��
/// @code  int CALLBACK OnListViewTemplateAdjustCoordinate(listView_item_* pItem,BOOL *pbHandled) @endcode
#define  XE_LISTVIEW_TEMP_ADJUST_COORDINATE   144

/// @brief �б���Ԫ��,�Ի���.
/// @code int CALLBACK OnListViewDrawItem(HDRAW hDraw,listView_item_* pItem,BOOL *pbHandled)  @endcode
#define  XE_LISTVIEW_DRAWITEM              145

/// @brief �б���Ԫ��,��ѡ���¼�.
/// @code int CALLBACK OnListViewSelect(int iGroup,int iItem,BOOL *pbHandled) @endcode
#define  XE_LISTVIEW_SELECT            146

/// @brief �б���Ԫ��,��չ�������¼�.
/// @code int CALLBACK OnListViewExpand(int iGroup,BOOL bExpand,BOOL *pbHandled) @endcode
#define  XE_LISTVIEW_EXPAND         147

/// @brief ��������Ԫ�� ��ֵ�ı��¼�
/// @code   int CALLBACK OnPGridValueChange(int nItemID,BOOL *pbHandled) @endcode
/// @param  nItemID  ��ID.
#define  XE_PGRID_VALUE_CHANGE     151

/// @code int CALLBACK OnPGridItemSet(int nItemID, BOOL *pbHandled)  @endcode
#define  XE_PGRID_ITEM_SET          152

/// @code int CALLBACK OnPGridItemSelect(int nItemID, BOOL *pbHandled)  @endcode
#define  XE_PGRID_ITEM_SELECT         153  //��ѡ��

/// @code int CALLBACK OnPGridItemAdjustCoordinate(propertyGrid_item_* pItem, BOOL *pbHandled)  @endcode
#define  XE_PGRID_ITEM_ADJUST_COORDINATE  154

/// @code int CALLBACK OnPGridItemDestroy(int nItemID, BOOL *pbHandled)  @endcode
#define  XE_PGRID_ITEM_DESTROY   155

/// @code int CALLBACK OnPGridItemExpand(int nItemID, BOOL bExpand, BOOL *pbHandled) @endcode
#define  XE_PGRID_ITEM_EXPAND    156


/// @code int CALLBACK OnEditSet(BOOL *pbHandled)  @endcode
#define  XE_EDIT_SET           180

/// @code int CALLBACK OnEditDrawRow(HDRAW hDraw, int iRow, BOOL *pbHandled)  @endcode
#define  XE_EDIT_DRAWROW    181   //��δʹ��

/// @code int CALLBACK OnEditChanged(BOOL *pbHandled)  @endcode
#define  XE_EDIT_CHANGED   182  //���ݱ�����

/// @code int CALLBACK OnEditPosChanged(int iPos, BOOL *pbHandled)  @endcode
#define  XE_EDIT_POS_CHANGED    183  //λ�øı�

/// @code int CALLBACK OnEditStyleChanged(int iStyle, BOOL *pbHandled)  @endcode
#define  XE_EDIT_STYLE_CHANGED  184  //��ʽ�ı�

/// @code int CALLBACK OnEditEnterGetTabAlign(BOOL *pbHandled)  @endcode
#define  XE_EDIT_ENTER_GET_TABALIGN    185  //�س�TAB����,������ҪTAB����

/// @code int CALLBACK OnEditSwapRow(int iRow, int bArrowUp, BOOL *pbHandled)  @endcode
#define  XE_EDIT_SWAPROW     186     //������

/// @brief �������ݸı��¼� ����:����ע�Ͳ���, ������������, �����ʽ��
/// @code int CALLBACK OnEditChangeRows(int iRow, int nRows, BOOL *pbHandled)  @endcode
/// @param iRow   ��ʼ��
/// @param nRows  �ı�������
#define  XE_EDITOR_MODIFY_ROWS         190  //���������޸��¼�

/// @code int CALLBACK OnEditorSetBreakpoint(int iRow, BOOL bCheck, BOOL *pbHandled)  @endcode
#define  XE_EDITOR_SETBREAKPOINT       191 //���öϵ�

/// @code int CALLBACK OnEditorRemoveBreakpoint(int iRow, BOOL *pbHandled)  @endcode
#define  XE_EDITOR_REMOVEBREAKPOINT    192 //�Ƴ��ϵ�

// iRow: �����п�ʼλ������,  if(nChangeRows>0) iEnd= iRow + nChangeRows
// nChangeRows: �ı�����, ���������, ����ɾ����
/// @code int CALLBACK OnEditorBreakpointChanged(int iRow, int nChangeRows, BOOL *pbHandled)  @endcode
#define  XE_EDIT_ROW_CHANGED  193 //�ɶԶϵ�λ���޸�

/// @code int CALLBACK OnEditorAutoMatchSelect(int iRow, int nRows, BOOL *pbHandled)  @endcode
#define  XE_EDITOR_AUTOMATCH_SELECT  194

/// @brief  TabBar��ǩ��ťѡ��ı��¼�
/// @code   int CALLBACK OnTabBarSelect(int iItem, BOOL *pbHandled) @endcode
/// @param  iItem  ��ǩλ������.
#define  XE_TABBAR_SELECT    221

/// @brief  TabBar��ǩ��ťɾ���¼�
/// @code   int CALLBACK OnTabBarDelete(int iItem, BOOL *pbHandled) @endcode
/// @param  iItem  ��ǩλ������.
#define  XE_TABBAR_DELETE    222

/// @brief  ����Ԫ�����ڸı��¼�
/// @code   int CALLBACK OnCalendarChange(BOOL *pbHandled) @endcode
#define  XE_MONTHCAL_CHANGE   231   //���� ���ڸı��¼�

/// @brief  ����ʱ��Ԫ��,���ݸı��¼�
/// @code   int CALLBACK OnDateTimeChange(BOOL *pbHandled) @endcode
#define  XE_DATETIME_CHANGE    241   //����ʱ��Ԫ��  �ı��¼�

/// @brief  ����ʱ��Ԫ��,����������Ƭ�¼�
/// @code   int CALLBACK OnDateTimePopupMonthCal(HWINDOW hMonthCalWnd,HELE hMonthCal,BOOL *pbHandled) @endcode
#define  XE_DATETIME_POPUP_MONTHCAL     242   //����ʱ��Ԫ��  ���������¼�

/// @brief  ����ʱ��Ԫ��,������������Ƭ�˳��¼�
/// @code   int CALLBACK OnDateTimeExitMonthCal(HWINDOW hMonthCalWnd,HELE hMonthCal,BOOL *pbHandled) @endcode
#define  XE_DATETIME_EXIT_MONTHCAL      243   //����ʱ��Ԫ��  �˳������¼�

/// @brief  �ļ��Ϸ��¼�, ��������:XWnd_EnableDragFiles()
/// @code   int CALLBACK OnDropFiles(HDROP hDropInfo, BOOL *pbHandled) @endcode
#define  XE_DROPFILES                 250  

//#define  XE_LISTVIEW_DRAG_INSERT
//#define  XE_PANE_LOACK
//#define  XE_PANE_DOCK
//#define  XE_PANE_FLOAT

/// @code   int CALLBACK OnEditColorChange(COLORREF color, BOOL *pbHandled) @endcode
#define  XE_EDIT_COLOR_CHANGE        260
///@}


//////////////////////////////////////////////////////////////////
//////////////////ö�ٶ���/////////////////////////////////////////
//////////////////////////////////////////////////////////////////

/// @defgroup  group_enum   ö������
/// @{

/// @defgroup groupWindow_position ����λ��(window_position_)
/// @{
enum   window_position_
{
	window_position_error=-1,  ///<����
	window_position_top=0,     ///<top
	window_position_bottom,    ///<bottom
	window_position_left,      ///<left
	window_position_right,     ///<right
	window_position_body,      ///<body
	window_position_window,    ///<window �������� 
};
///@}

/// @defgroup groupElement_position UIԪ��λ��(element_position_)
/// @{
enum element_position_
{
	element_position_no     = 0x00,     ///<��Ч
	element_position_left   = 0x01,     ///<���
	element_position_top    = 0x02,		///<�ϱ�
	element_position_right  = 0x04,		///<�ұ�
	element_position_bottom = 0X08,		///<�±�
};
///@}

/// @defgroup group_position λ�ñ�ʶ(element_position_)
/// @{
enum position_flag_
{
	position_flag_left,          ///<��
	position_flag_top,           ///<��
	position_flag_right,         ///<��
	position_flag_bottom,        ///<��
	position_flag_leftTop,       ///<���Ͻ�
	position_flag_leftBottom,    ///<���½�
	position_flag_rightTop,      ///<���Ͻ�
	position_flag_rightBottom,   ///<���½�
	position_flag_center,        ///<����
};
///@}

//͸������
/// @defgroup groupWindowTransparent �Ųʴ���͸����ʶ(window_transparent_)
/// @{
enum  window_transparent_
{
	window_transparent_false=0,   ///<Ĭ�ϴ���,��͸��
	window_transparent_shaped,    ///<͸������,��͸��ͨ��,����
	window_transparent_shadow,    ///<��Ӱ����,��͸��ͨ��,�߿���Ӱ,����͸�����͸��
	window_transparent_simple,    ///<͸������,����͸��ͨ��,ָ����͸����,ָ��͸��ɫ
	window_transparent_win7,      ///<WIN7��������,��ҪWIN7������Ч,��ǰδ����,��ǰδ����.
};
///@}


/// @defgroup groupMenu �����˵�(menu)
/// @{

///@name �����˵����ʶ(menu_item_flag_)
///@{
enum   menu_item_flag_
{
	menu_item_flag_normal=   0x00,   ///<����
	menu_item_flag_select=   0x01,   ///<ѡ������ͣ��
	menu_item_flag_stay =    0x01,   ///<ѡ������ͣ�� ���� menu_item_flag_select
	menu_item_flag_check=    0x02,   ///<��ѡ
	menu_item_flag_popup=    0x04,   ///<����
	menu_item_flag_separator=0x08,   ///<�ָ��� ID������,ID�ű�����
	menu_item_flag_disable=  0x10,   ///<����
};
///@}

///@name �����˵�����(menu_popup_position_)
///@{
enum  menu_popup_position_
{
	menu_popup_position_left_top=0,      ///<���Ͻ�
	menu_popup_position_left_bottom,     ///<���½�
	menu_popup_position_right_top,       ///<���Ͻ�
	menu_popup_position_right_bottom,    ///<���½�
	menu_popup_position_center_left,     ///<�����
	menu_popup_position_center_top,      ///<�Ͼ���
	menu_popup_position_center_right,    ///<�Ҿ���
	menu_popup_position_center_bottom,   ///<�¾���
};
///@}
///@}

/// @defgroup groupImageDrawType ͼƬ��������(image_draw_type_)
/// @{
enum  image_draw_type_
{
	image_draw_type_default=0,     ///<Ĭ��
	image_draw_type_stretch,       ///<����
	image_draw_type_adaptive,      ///<����Ӧ,�Ź���
	image_draw_type_tile,          ///<ƽ��
	image_draw_type_fixed_ratio,   ///<�̶�����,��ͼƬ������ʾ��Χʱ,����ԭʼ����ѹ����ʾͼƬ
	image_draw_type_adaptive_border,  ///<�Ź��񲻻����м�����
};
///@}


//״̬--------------------------------------
/// @defgroup groupCommonState3 ��ͨ����״̬(common_state3_)
/// @{
enum  common_state3_
{
	common_state3_leave=0,  ///<�뿪
	common_state3_stay,     ///<ͣ��
	common_state3_down,     ///<����
};

///@}

/// @defgroup groupButtonStateFlag ��ť״̬(button_state_)
/// @{
enum  button_state_
{
	button_state_leave=0,   ///<�뿪״̬
	button_state_stay,      ///<ͣ��״̬
	button_state_down,      ///<����״̬
	button_state_check,     ///<ѡ��״̬
	button_state_disable,   ///<����״̬
};
///@}

/// @defgroup   groupComboBoxState ��Ͽ�״̬(comboBox_state_)
/// @{
enum  comboBox_state_
{
	comboBox_state_leave=0,   ///<����뿪״̬
	comboBox_state_stay=1,    ///<���ͣ��״̬
	comboBox_state_down=2,    ///<����״̬
};
///@}

/// @defgroup groupListItemState �б���״̬(list_item_state_)
/// ������(�б�,�б��,�б���ͼ)
/// @{
enum  list_item_state_
{
	list_item_state_leave=0,   ///<������뿪״̬
	list_item_state_stay=1,    ///<�����ͣ��״̬
	list_item_state_select=2,  ///<��ѡ��״̬
	list_item_state_cache=3,   ///<�������
};
///@}


/// @defgroup groupTreeItemState  �б�����״̬(tree_item_state_)
/// @{
enum  tree_item_state_
{
	tree_item_state_leave=0,   ///<������뿪״̬
	tree_item_state_stay=1,    ///<�����ͣ��״̬
	tree_item_state_select=2,  ///<��ѡ��״̬
};
///@}


//��ťͼ����뷽ʽ
/// @defgroup groupButtonIconAlign ��ťͼ����뷽ʽ(button_icon_align_)
/// @{
enum  button_icon_align_
{
	button_icon_align_left=0,  ///<ͼ�������
	button_icon_align_top,     ///<ͼ���ڶ���
	button_icon_align_right,   ///<ͼ�����ұ�
	button_icon_align_bottom,  ///<ͼ���ڵײ�
};
///@}

/// @defgroup  groupListDrawItemBkFlag  ������Ʊ�־λ(List,ListBox,ListView,Tree)
/// @{
enum  list_drawItemBk_flag_
{
	list_drawItemBk_flag_nothing = 0x000,     ///<������
	list_drawItemBk_flag_leave = 0x001,       ///<��������뿪״̬���
	list_drawItemBk_flag_stay = 0x002,        ///<�������ѡ��״̬���
	list_drawItemBk_flag_select = 0x004,      ///<�������ͣ��״̬�����
	list_drawItemBk_flag_group_leave = 0x008, ///<��������뿪״̬�鱳��,����Ϊ��ʱ
	list_drawItemBk_flag_group_stay = 0x010,  ///<�������ͣ��״̬�鱳��,����Ϊ��ʱ

	list_drawItemBk_flag_line  =0x020,        ///<�б����ˮƽ�ָ���
	list_drawItemBk_flag_lineV =0x040,        ///<�б���ƴ�ֱ�ָ���

};
/// @}

//������Ϣ������
/// @defgroup groupMessageBox ������Ϣ��(messageBox_flag_)
/// @{
enum  messageBox_flag_
{
	messageBox_flag_other= 0x00,    ///<����
	messageBox_flag_ok=    0x01,    ///<ȷ����ť
	messageBox_flag_cancel=0x02,    ///<ȡ����ť
	
	messageBox_flag_icon_appicon =0x01000,  ///<ͼ�� Ӧ�ó���  IDI_APPLICATION
	messageBox_flag_icon_info    =0x02000,  ///<ͼ�� ��Ϣ     IDI_ASTERISK
	messageBox_flag_icon_qustion =0x04000,  ///<ͼ�� ��ѯ/����/����   IDI_QUESTION
	messageBox_flag_icon_error   =0x08000,  ///<ͼ�� ����/�ܾ�/��ֹ  IDI_ERROR
	messageBox_flag_icon_warning =0x10000,  ///<ͼ�� ����       IDI_WARNING
	messageBox_flag_icon_shield  =0x20000,  ///<ͼ�� ����/��ȫ   IDI_SHIELD
};
///@}

///@defgroup GroupPropertyGrid_item_type    ��������������(propertyGrid_item_type_)
///@{
enum  propertyGrid_item_type_
{
	propertyGrid_item_type_text=0,      ///<Ĭ��,�ַ�������
	propertyGrid_item_type_edit,        ///<�༭��
	propertyGrid_item_type_edit_color,  ///<��ɫѡ��Ԫ��
	propertyGrid_item_type_edit_file,   ///<�ļ�ѡ��༭��
	propertyGrid_item_type_edit_set,    ///<����
	propertyGrid_item_type_comboBox,    ///<��Ͽ�
	propertyGrid_item_type_group,       ///<��
	propertyGrid_item_type_panel,       ///<���
};
///@}

///@defgroup  GroupZOrder    Z��λ��(zorder_)
///@{
enum zorder_
{
	zorder_top,    ///<������
	zorder_bottom, ///<������
	zorder_before, ///<ָ��Ŀ������
	zorder_after,  ///<ָ��Ŀ������
};
///@}

///@defgroup Group_pane_align_  �������(pane_align_)
///@{
enum pane_align_
{
	pane_align_error=-1,  ///<����
	pane_align_left=0,    ///<���
	pane_align_top,       ///<����
	pane_align_right,     ///<�Ҳ�
	pane_align_bottom,    ///<�ײ�
	pane_align_center,    ///<����
};
///@}

///@defgroup Group_layout_align_  ���ֶ���(layout_align_)
///@{
enum  layout_align_
{
	layout_align_left = 0,		  ///<���
	layout_align_top,			  ///<����
	layout_align_right,			  ///<�Ҳ�
	layout_align_bottom,		  ///<�ײ�
	layout_align_center,		  ///<����
	layout_align_equidistant,     ///<�Ⱦ�
};
///@}

/// @defgroup groupLayoutSize ���ִ�С����(layout_size_)
/// @{
enum  layout_size_
{
	layout_size_fixed = 0, ///<�̶���С
	layout_size_fill,      ///<fill ��丸
	layout_size_auto,      ///<auto �Զ���С,�������ݼ����С
	layout_size_weight,    ///<weight ����,���ձ�������ʣ��ռ�
	layout_size_percent,   ///<�ٷֱ�
	layout_size_disable,   ///<disable ��ʹ��
};
///@}

/// @defgroup  groupLayoutAlignAxis ���������(layout_align_axis_)
/// @{
enum layout_align_axis_
{
	layout_align_axis_auto = 0,   ///<��
	layout_align_axis_start,      ///<ˮƽ����(����), ��ֱ����(���)
	layout_align_axis_center,     ///<����
	layout_align_axis_end,        ///<ˮƽ����(�ײ�), ��ֱ����(�Ҳ�)
};
///@}

///@defgroup Group_edit_textAlign_flag_  �༭���ı�����(edit_textAlign_flag_)
///@{
enum edit_textAlign_flag_
{
	edit_textAlign_flag_left    = 0x0,   ///<���
	edit_textAlign_flag_right   = 0x1,   ///<�Ҳ�
	edit_textAlign_flag_center  = 0x2,   ///<ˮƽ����

	edit_textAlign_flag_top      = 0x0,  ///<����
	edit_textAlign_flag_bottom   = 0x4,  ///<�ײ�
	edit_textAlign_flag_center_v = 0x8,  ///<��ֱ����
};
///@}

///@defgroup Group_pane_state_  ����״̬(pane_state_)
///@{
enum pane_state_
{
	pane_state_error=-1,
	pane_state_any=0,
	pane_state_lock,   ///<����
	pane_state_dock,   ///<ͣ����ͷ
	pane_state_float,  ///<��������
};
///@}

///@defgroup Group_textFormatFlag_    �ı�����(textFormatFlag_)
///@{
enum  textFormatFlag_
{
	textAlignFlag_left     =0,      ///<�����
	textAlignFlag_top      =0,      ///<��ֱ������
	textAlignFlag_left_top =0x4000, ///<�ڲ�����
	textAlignFlag_center   =0x1,    ///<ˮƽ����
	textAlignFlag_right    =0x2,    ///<�Ҷ���.

	textAlignFlag_vcenter  =0x4,    ///<��ֱ����
	textAlignFlag_bottom   =0x8,    ///<��ֱ�׶���

	textFormatFlag_DirectionRightToLeft=0x10,   ///<��������˳����ʾ�ı�
	textFormatFlag_NoWrap              =0x20,   ///<��ֹ����
	textFormatFlag_DirectionVertical   =0x40,   ///<��ֱ��ʾ�ı�
	textFormatFlag_NoFitBlackBox       =0x80,   ///<�������ַ�������ַ����Ĳ��־��Ρ�Ĭ������£������¶�λ�ַ��Ա����κ�����
	textFormatFlag_DisplayFormatControl=0x100,  ///<�����ַ���������ұ�ǣ�����д����Եı�־����һ����ʾ������С�
	textFormatFlag_NoFontFallback  =0x200,      ///<��������������в�֧�ֵ��ַ������û��˵���ѡ���塣ȱʧ���κ��ַ�����ȱʧ��־���ŵ�������ʾ��ͨ����һ���յķ���
	textFormatFlag_MeasureTrailingSpaces=0x400, ///<����ÿһ�н�β����β��ո���Ĭ������£�MeasureString �������صı߿򶼽��ų�ÿһ�н�β���Ŀո����ô˱���Ա��ڲⶨʱ���ո������ȥ
	textFormatFlag_LineLimit       =0x800,      ///<���������ʾ�߶Ȳ���һ��,��ô����ʾ
	textFormatFlag_NoClip          =0x1000,     ///<������ʾ��־���ŵ�������ֺ����쵽�߿����δ�����ı�����Ĭ������£����쵽�߿����������ı��ͱ�־���Ų��ֶ�������

	textTrimming_None              = 0,        ///<��ʹ��ȥβ
	textTrimming_Character         = 0x40000,  ///<���ַ�Ϊ��λȥβ
	textTrimming_Word              = 0x80000,  ///<�Ե���Ϊ��λȥβ
	textTrimming_EllipsisCharacter = 0x8000,   ///<���ַ�Ϊ��λȥβ,ʡ�Բ���ʹ�����Ժű�ʾ
	textTrimming_EllipsisWord      = 0x10000,  ///<�Ե���Ϊ��λȥβ,
	textTrimming_EllipsisPath      = 0x20000,  ///<��ȥ�ַ����м䲿�֣���֤�ַ�����β���ܹ���ʾ  
};
///@}

///@defgroup Group_textFormatFlag_dwrite_    D2D�ı���Ⱦģʽ(XC_DWRITE_RENDERING_MODE)
///@{
enum XC_DWRITE_RENDERING_MODE
{
	XC_DWRITE_RENDERING_MODE_DEFAULT = 0,                    ///<ָ����������ʹ�С�Զ�ȷ������ģʽ��
	XC_DWRITE_RENDERING_MODE_ALIASED,						 ///<ָ����ִ�п���ݡ� ÿ������Ҫô����Ϊ�ı���ǰ��ɫ��Ҫô������������ɫ��
	XC_DWRITE_RENDERING_MODE_CLEARTYPE_GDI_CLASSIC,			 ///<ʹ��������ı���ͬ�Ķ���ָ�� ClearType ���֡� ����ֻ�ܶ�λ���������صı߽��ϡ�
	XC_DWRITE_RENDERING_MODE_CLEARTYPE_GDI_NATURAL,			 ///<ʹ��ʹ�� CLEARTYPE_NATURAL_QUALITY ���������壬ʹ����ʹ�� GDI ���ı�������ͬ��ָ��ָ�� ClearType ���֡� ��ʹ�ñ����ı���ȣ����ζ������ӽ�������ֵ����������Ȼλ���������صı߽��ϡ�
	XC_DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL,				 ///<����ˮƽά����ָ�����п���ݹ��ܵ� ClearType ��Ⱦ����ͨ��������С�����С����� 16 ppem����
	XC_DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL_SYMMETRIC,	 ///<ָ����ˮƽ�ʹ�ֱά���Ͼ��п���ݵ� ClearType ��Ⱦ����ͨ�����ڽϴ�ĳߴ磬��ʹ���ߺͶԽ��߿�������ƽ������������һЩ��Ͷȡ�
	XC_DWRITE_RENDERING_MODE_OUTLINE,                        ///<ָ����ȾӦ�ƹ���դ������ֱ��ʹ�������� ��ͨ�����ڷǳ���ĳߴ硣
};
///@}

///@defgroup Group_listItemTemp_type_    �б���ģ������(listItemTemp_type_)
///@{
enum listItemTemp_type_
{
	listItemTemp_type_tree = 0x01,					  ///<tree
	listItemTemp_type_listBox = 0x02,				  ///<listBox
	listItemTemp_type_list_head = 0x04,				  ///<list �б�ͷ
	listItemTemp_type_list_item = 0x08,				  ///<list �б���
	listItemTemp_type_listView_group = 0x10,		  ///<listView �б�����
	listItemTemp_type_listView_item = 0x20,			  ///<listView �б�����
	listItemTemp_type_list = listItemTemp_type_list_head | listItemTemp_type_list_item,  ///<list (�б�ͷ)��(�б���)���
	listItemTemp_type_listView = listItemTemp_type_listView_group | listItemTemp_type_listView_item, ///<listView (�б�����)��(�б�����)���
};
///@}

///@defgroup Group_adjustLayout    �������ֱ�ʶλ(adjustLayout_)
///@{
enum adjustLayout_
{
	adjustLayout_no   = 0x00,  ///<����������
	adjustLayout_all  = 0x01,  ///<ǿ�Ƶ���������Ӷ��󲼾�.
	adjustLayout_self = 0x02,  ///<ֻ����������,�������Ӷ��󲼾�.
	//xc_adjustLayout_free = 0x03   ��������,��ǿ����, ֻ��������ı�Ķ���
};
///@}

/// @defgroup group_edit_macro �༭������(edit_type_)
/// @{
enum edit_type_ 
{
	edit_type_none = 0,   ///<��ͨ�༭��,   ÿ�еĸ߶���ͬ
	edit_type_editor,     ///<����༭
	edit_type_richedit,   ///<���ı��༭��, ÿ�еĸ߶ȿ��ܲ�ͬ
	edit_type_chat,       ///<��������, ÿ�еĸ߶ȿ��ܲ�ͬ
	edit_type_codeTable,  ///<������,�ڲ�ʹ��,  ÿ�еĸ߶���ͬ
};

enum edit_style_type_
{
	edit_style_type_font_color = 1,  ///<����
	edit_style_type_image,           ///<ͼƬ
	edit_style_type_obj,             ///<UI����
};

///Edit �������ݶ��뷽ʽ
enum chat_flag_
{
	chat_flag_left = 0x1,    ///<���
	chat_flag_right = 0x2,   ///<�Ҳ�
	chat_flag_center = 0x4,  ///<�м�
	chat_flag_next_row_bubble = 0x8,   ///<��һ����ʾ����
};
///@}

/// @defgroup group_table  ��״����ʶ(table_flag_)
/// @{

///@name  ��״����ʶ(table_flag_)
///@{
enum  table_flag_
{
	table_flag_full = 0,   ///<������ϵ�Ԫ��
	table_flag_none,       ///<������С��Ԫ��
};
///@}

///@name  ��״����߱�ʶ(table_line_flag_)
///@{
enum  table_line_flag_  
{
	table_line_flag_left    = 0x1,   ///<������
	table_line_flag_top     = 0x2,   ///<������
	table_line_flag_right   = 0x4,	 ///<������
	table_line_flag_bottom  = 0x8,   ///<������
	table_line_flag_left2   = 0x10,  ///<������
	table_line_flag_top2    = 0x20,	 ///<������
	table_line_flag_right2  = 0x40,	 ///<������
	table_line_flag_bottom2 = 0x80,	 ///<������
};
///@}
///@}

/// @defgroup group_monthCal_button_type_    ����Ԫ���ϵİ�ť����(monthCal_button_type_)
/// @{
enum monthCal_button_type_
{
	monthCal_button_type_today = 0,  ///< ���찴ť
	monthCal_button_type_last_year,  ///< ��һ��
	monthCal_button_type_next_year,  ///< ��һ��
	monthCal_button_type_last_month, ///< ��һ��
	monthCal_button_type_next_month, ///< ��һ��
};
///@}

///@defgroup  group_fontStyle_  ������ʽ(fontStyle_)
///@{
enum fontStyle_
{
	fontStyle_regular = 0,     ///<����
	fontStyle_bold = 1,        ///<����
	fontStyle_italic = 2,      ///<б��
	fontStyle_boldItalic = 3,  ///<��б��
	fontStyle_underline = 4,   ///<�»���
	fontStyle_strikeout = 8    ///<ɾ����
};
///@}

///@defgroup  group_adapter_date_type_    ������������������(adapter_date_type_)
///@{
enum  adapter_date_type_
{
	adapter_date_type_error = -1,
	adapter_date_type_int = 0,     ///<����
	adapter_date_type_float = 1,   ///<������
	adapter_date_type_string = 2,  ///<�ַ���
	adapter_date_type_image = 3,   ///<ͼƬ
};
///@}

/// @defgroup group_ease_type_  ��������(ease_type_)
/// @{
enum ease_type_
{
	easeIn,      ///<��������
	easeOut,     ///<�ӿ쵽��
	easeInOut,   ///<���������ٵ���
};
///@}

///@defgroup   group_ease_flag_  ������ʶ(ease_flag_)
///@{
enum ease_flag_
{
	ease_flag_linear,			///<����, ֱ��
	ease_flag_quad,			    ///<���η�����
	ease_flag_cubic,			///<���η�����, Բ��
	ease_flag_quart,			///<�Ĵη�����
	ease_flag_quint,			///<��η�����

	ease_flag_sine,				///<����, ��ĩ�˱仯
	ease_flag_expo,			    ///<ͻ��, ͻȻһ��
	ease_flag_circ,		        ///<Բ��, �ñ��ƹ�һ��Բ��
	ease_flag_elastic,		    ///<ǿ���ص�
	ease_flag_back,				///<�ص�, �Ƚϻ���
	ease_flag_bounce,		    ///<����, ģ��С����ص���

	ease_flag_in    = 0x010000, ///<��������
	ease_flag_out   = 0x020000, ///<�ӿ쵽��
	ease_flag_inOut = 0x030000, ///<���������ٵ���
};
///@}

///@defgroup   group_notifyMsg_skin_  ֪ͨ��Ϣ���(notifyMsg_skin_)
///@{
enum  notifyMsg_skin_
{
	notifyMsg_skin_no,         ///<Ĭ��
	notifyMsg_skin_success,    ///<�ɹ�
	notifyMsg_skin_warning,	   ///<����
	notifyMsg_skin_message,	   ///<��Ϣ
	notifyMsg_skin_error,	   ///<����
};
///@}

///@defgroup group_animation_move_  �����ƶ���ʶ(animation_move_)
///@{
enum animation_move_
{
	animation_move_x = 0x01,   ///<X���ƶ�
	animation_move_y = 0x02,   ///<Y���ƶ�
};
///@}

///@defgroup group_bkInfo_align_flag_  ����������뷽ʽ(bkObject_align_flag_)
///@{
enum bkObject_align_flag_  //����������뷽ʽ
{
	bkObject_align_flag_no     = 0x000,    ///<��
	bkObject_align_flag_left   = 0x001,    ///<�����, �����ô˱�ʶʱ,����(margin.left)���������; ��rightδ����ʱ,��ô����(margin.right)������;
	bkObject_align_flag_top    = 0x002,    ///<������, �����ô˱�ʶʱ,����(margin.top)���������; ��bottomδ����ʱ,��ô����(margin.bottom)����߶�;
	bkObject_align_flag_right  = 0x004,    ///<�Ҷ���, �����ô˱�ʶʱ,����(margin.right)�����Ҳ���; ��leftδ����ʱ,��ô����(margin.left)������;
	bkObject_align_flag_bottom = 0x008,    ///<�׶���, �����ô˱�ʶʱ,����(margin.bottom)����ײ����; ��topδ����ʱ,��ô����(margin.top)����߶�;
	bkObject_align_flag_center = 0x010,    ///<ˮƽ����, �����ô˱�ʶʱ,����(margin.left)������;
	bkObject_align_flag_center_v = 0x020,  ///<��ֱ����, �����ô˱�ʶʱ,����(margin.top)����߶�; 
};
///@}


///@defgroup group_frameWnd_cell_type_  ��ܴ��ڵ�Ԫ������(frameWnd_cell_type_)
enum frameWnd_cell_type_
{
	frameWnd_cell_type_no          = 0,   ///<��
	frameWnd_cell_type_pane        = 1,   ///<����
	frameWnd_cell_type_group       = 2,   ///<������
	frameWnd_cell_type_bodyView    = 3,   ///<����ͼ��
	frameWnd_cell_type_top_bottom  = 4,   ///<���²���
	frameWnd_cell_type_left_right  = 5,   ///<���Ҳ���
};


///@}

/////////////////////////////////////////////////////////////////////
//////////////�Ų����״̬/////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

/// @defgroup group_combo_StateFlag  ���״̬
/// @{

///@defgroup group_window_state_flag_  ����״̬(window_state_flag_)
///@{
enum  window_state_flag_
{
	window_state_flag_nothing       =0x0000,  ///<��
	window_state_flag_leave         =0x0001,  ///<��������
	window_state_flag_body_leave    =0x0002,  ///<����-body
	window_state_flag_top_leave     =0x0004,  ///<����-top
	window_state_flag_bottom_leave  =0x0008,  ///<����-bottom
	window_state_flag_left_leave    =0x0010,  ///<����-left
	window_state_flag_right_leave   =0x0020,  ///<����-right

	window_state_flag_layout_body   =0x20000000, ///<����������
};
///@}

///@defgroup  group_element_state_flag_ Ԫ��״̬(element_state_flag_)
///@{
enum  element_state_flag_
{
	element_state_flag_nothing   =window_state_flag_nothing,  ///<��
	element_state_flag_enable    =0x0001,  ///<����
	element_state_flag_disable   =0x0002,  ///<����
	element_state_flag_focus     =0x0004,  ///<����
	element_state_flag_focus_no  =0x0008,  ///<�޽���
	element_state_flag_focusEx   =0x40000000,  ///<��Ԫ�ػ��Ԫ�ص���Ԫ��ӵ�н���
	element_state_flag_focusEx_no=0x80000000,  ///<�޽���Ex

	layout_state_flag_layout_body  =window_state_flag_layout_body, ///<����������

	element_state_flag_leave     =0x0010,  ///<����뿪
	element_state_flag_stay      =0x0020,  ///<Ϊ��չģ�鱣��
	element_state_flag_down      =0x0040,  ///<Ϊ��չģ�鱣��
};
///@}

///@defgroup  group_button_state_flag_ ��ť״̬(button_state_flag_)
///@{
enum  button_state_flag_
{
	button_state_flag_leave     =element_state_flag_leave,  ///<����뿪
	button_state_flag_stay      =element_state_flag_stay,   ///<���ͣ��
	button_state_flag_down      =element_state_flag_down,   ///<��갴��

	button_state_flag_check     =0x0080, ///<ѡ��
	button_state_flag_check_no  =0x0100, ///<δѡ��
	
	button_state_flag_WindowRestore  =0x0200, ///<���ڻ�ԭ
	button_state_flag_WindowMaximize =0x0400, ///<�������
};
///@}

///@defgroup   group_comboBox_state_flag_  ��Ͽ�״̬(comboBox_state_flag_)
///@{
enum comboBox_state_flag_
{
	comboBox_state_flag_leave   =element_state_flag_leave, ///<����뿪
	comboBox_state_flag_stay    =element_state_flag_stay,  ///<���ͣ��
	comboBox_state_flag_down    =element_state_flag_down,  ///<��갴��
};
///@}

///@defgroup   group_listBox_state_flag_  �б��״̬(listBox_state_flag_)
///@{
enum listBox_state_flag_
{
	listBox_state_flag_item_leave     =0x0080, ///<������뿪
	listBox_state_flag_item_stay      =0x0100, ///<�����ͣ��

	listBox_state_flag_item_select    =0x0200, ///<��ѡ��
	listBox_state_flag_item_select_no =0x0400, ///<��δѡ��
};
///@}

///@defgroup   group_list_state_flag_  �б�״̬(list_state_flag_)
///@{
enum list_state_flag_
{
	list_state_flag_item_leave      =0x0080, ///<������뿪
	list_state_flag_item_stay       =0x0100, ///<�����ͣ��

	list_state_flag_item_select     =0x0200, ///<��ѡ��
	list_state_flag_item_select_no  =0x0400, ///<��δѡ��
};
///@}

///@defgroup   group_listHeader_state_flag_  �б�ͷ״̬(listHeader_state_flag_)
///@{
enum listHeader_state_flag_
{
	listHeader_state_flag_item_leave  =0x0080, ///<������뿪
	listHeader_state_flag_item_stay   =0x0100, ///<�����ͣ��
	listHeader_state_flag_item_down   =0x0200, ///<����갴��
};
///@}

///@defgroup   group_listView_state_flag_ �б���ͼ״̬(listView_state_flag_)
///@{
enum listView_state_flag_
{
	listView_state_flag_item_leave       =0x0080,  ///<������뿪
	listView_state_flag_item_stay        =0x0100,  ///<�����ͣ��

	listView_state_flag_item_select      =0x0200,  ///<��ѡ��
	listView_state_flag_item_select_no   =0x0400,  ///<��δѡ��

	listView_state_flag_group_leave      =0x0800,  ///<������뿪
	listView_state_flag_group_stay       =0x1000,  ///<�����ͣ��

	listView_state_flag_group_select     =0x2000,  ///<��ѡ��
	listView_state_flag_group_select_no  =0x4000,  ///<��δѡ��
};
///@}

///@defgroup   group_tree_state_flag_ �б���״̬(tree_state_flag_)
///@{
enum tree_state_flag_
{
	tree_state_flag_item_leave      =0x0080,  ///<������뿪
	tree_state_flag_item_stay       =0x0100,  ///<�����ͣ��,����ֵ, ��δʹ��

	tree_state_flag_item_select     =0x0200,  ///<��ѡ��
	tree_state_flag_item_select_no  =0x0400,  ///<��δѡ��

	tree_state_flag_group           =0x0800,  ///<��Ϊ��
	tree_state_flag_group_no        =0x1000,  ///<�Ϊ��
};
///@}

///@defgroup   group_monthCal_state_flag_  ������Ƭ״̬(monthCal_state_flag_)
///@{
enum monthCal_state_flag_     
{
	monthCal_state_flag_leave = element_state_flag_leave,  ///<�뿪״̬

	monthCal_state_flag_item_leave      = 0x0080,     ///< ��-�뿪
	monthCal_state_flag_item_stay       = 0x0100,     ///< ��-ͣ��
	monthCal_state_flag_item_down       = 0x0200,     ///< ��-����

	monthCal_state_flag_item_select     = 0x0400,     ///< ��-ѡ��
	monthCal_state_flag_item_select_no  = 0x0800,     ///< ��-δѡ��

	monthCal_state_flag_item_today      = 0x1000,     ///< ��-����
//	monthCal_state_flag_item_other      = 0x2000,     ///< ��-���¼�����
	monthCal_state_flag_item_last_month = 0x2000,     ///< ��-����
	monthCal_state_flag_item_cur_month  = 0x4000,     ///< ��-����
	monthCal_state_flag_item_next_month = 0x8000,     ///< ��-����
};
///@}

///@defgroup   group_propertyGrid_state_flag_  ��������״̬(propertyGrid_state_flag_)
///@{
enum propertyGrid_state_flag_     
{
	propertyGrid_state_flag_item_leave     = 0x0080,  	 ///<�뿪
	propertyGrid_state_flag_item_stay      = 0x0100,	 ///<ͣ��

	propertyGrid_state_flag_item_select    = 0x0200,	 ///<ѡ��
	propertyGrid_state_flag_item_select_no = 0x0400,	 ///<δѡ��

	propertyGrid_state_flag_group_leave      = 0x0800,	 ///<���뿪
	propertyGrid_state_flag_group_expand     = 0x1000,	 ///<��չ��
	propertyGrid_state_flag_group_expand_no  = 0x2000,	 ///<��δչ��
};
///@}

///@defgroup   group_pane_state_flag_  ����״̬(pane_state_flag_)
///@{
enum pane_state_flag_     
{
	pane_state_flag_leave     = element_state_flag_leave,  ///<�뿪
	pane_state_flag_stay      = element_state_flag_stay,   ///<ͣ��

	pane_state_flag_caption   = 0x0080,  ///<����
	pane_state_flag_body      = 0x0100,  ///<������
};
///@}

///@defgroup   group_layout_state_flag_  ����״̬(layout_state_flag_)
///@{
enum layout_state_flag_
{
	layout_state_flag_nothing   =window_state_flag_nothing,  ///<��
	layout_state_flag_full      = 0x0001,   ///<��������
	layout_state_flag_body      = 0x0002,   ///<��������, �������ߴ�С
};
///@}
///@}

/////////////////////////////////////////////////////////////////////
//////////////����ṹ��///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

///@defgroup  group_struct_  �ṹ�嶨��
///@{

typedef   struct lua_State lua_State;

struct  RECTF
{
	float  left;
	float  top;
	float  right;
	float  bottom;
};

///�ߴ�С
struct borderSize_  //4���ߵĴ�С
{
	int  leftSize;   ///<��ߴ�С
	int  topSize;    ///<�ϱߴ�С
	int  rightSize;  ///<�ұߴ�С
	int  bottomSize; ///<�±ߴ�С
};
typedef  borderSize_  spaceSize_, paddingSize_, marginSize_;

///λ�õ�
struct  position_
{
	int  iRow;    ///<������
	int  iColumn; ///<������
};

///ListBox �б������Ϣ
struct listBox_item_
{
	int     index;      ///<������
	vint    nUserData;  ///<�û�������
	int     nHeight;    ///<��Ĭ�ϸ߶�
	int     nSelHeight; ///<��ѡ��ʱ�߶�
	list_item_state_  nState;  ///<״̬
	RECT    rcItem;     ///<������
	HXCGUI  hLayout;    ///<���ֶ���
	HTEMP   hTemp;      ///<�б���ģ��
};

///ListBox �б������Ϣ2
struct listBox_item_info_
{
	vint    nUserData;  ///<�û�������
	int     nHeight;    ///<��߶�, -1ʹ��Ĭ�ϸ߶�
	int     nSelHeight; ///<��ѡ��ʱ�߶�, -1ʹ��Ĭ�ϸ߶�
};

///ListView �б�����ID
struct  listView_item_id_
{
	int  iGroup;   ///<������
	int  iItem;    ///<������
};

///List �б�����Ϣ
struct list_item_
{
	int     index;             ///<������(������)
	int     iSubItem;          ///<��������(������)
	vint    nUserData;         ///<�û�����
	list_item_state_  nState;  ///<״̬
	RECT    rcItem;     ///<δʹ��
	HXCGUI  hLayout;    ///<���ֶ���
	HTEMP   hTemp;      ///<�б���ģ��
};

///List �б�ͷ����Ϣ
struct list_header_item_
{
	int     index;           ///<������
	vint    nUserData;       ///<�û�����

	BOOL    bSort;           ///<�Ƿ�֧������
	int     nSortType;       ///<����ʽ,0��Ч,1����,2����
	int     iColumnAdapter;  ///<��Ӧ�����������е�������

	common_state3_  nState;  ///<״̬
	RECT      rcItem;        ///<����
	HXCGUI    hLayout;       ///<���ֶ���
	HTEMP     hTemp;         ///<�б���ģ��
};

///Tree ������Ϣ
struct tree_item_
{
	int     nID;				 ///<��ID
	int     nDepth;				 ///<���
	int     nHeight;			 ///<��߶�
	int     nSelHeight;			 ///<��ѡ��״̬�߶�
	vint    nUserData;			 ///<�û�����
	BOOL    bExpand;			 ///<չ��
	tree_item_state_  nState;	 ///<״̬
	RECT    rcItem;              ///<����
	HXCGUI  hLayout;             ///<���ֶ���
	HTEMP   hTemp;               ///<�б���ģ��
};

///ListView �б�������Ϣ
struct listView_item_
{
	int     iGroup;            ///<������������ -1û����
	int     iItem;             ///<����������λ������,�������Ϊ-1,��ôΪ��
	vint    nUserData;         ///<�û�������
	list_item_state_  nState;  ///<״̬  
	RECT    rcItem;            ///<��������,�����߿�
	HXCGUI  hLayout;           ///<���ֶ���
	HTEMP   hTemp;             ///<�б���ģ�� 
};

/// @defgroup group_menu_macro Menu�˵�
/// @{

///�˵�-����������Ϣ
struct  menu_popupWnd_
{
	HWINDOW hWindow;    ///<���ھ��
	int     nParentID;  ///<����ID
};

///�˵������Ի�ṹ
struct menu_drawBackground_
{
	HMENUX  hMenu;      ///<�˵����
	HWINDOW hWindow;    ///<��ǰ�����˵���Ĵ��ھ��
	int     nParentID;  ///<����ID
};

///�˵����Ի�ṹ
struct  menu_drawItem_
{
	HMENUX     hMenu;       ///<�˵����
	HWINDOW    hWindow;     ///<��ǰ�����˵���Ĵ��ھ��
	int        nID;         ///<ID
	int        nState;	    ///<״̬ @ref menu_item_flag_
	RECT       rcItem;      ///<����
	HIMAGE     hIcon;       ///<�˵���ͼ��
	const wchar_t* pText;   ///<�ı�
};
///@}

///��UIԪ���϶���
struct tree_drag_item_
{
	int  nDragItem;  ///< �϶���ID
	int  nDestItem;  ///< Ŀ����ID
	int  nType;      ///< ͣ�����Ŀ��λ��,0:(��)ͣ�ŵ�Ŀ�������, 1:(��)ͣ�ŵ�Ŀ�������, 3:(��)ͣ�ŵ�Ŀ��ĵ�����, 
};

///������Ϣ
struct  font_info_
{
	int   nSize;                 ///<�����С,��λ(pt,��).
	int   nStyle;                ///<������ʽ fontStyle_
	wchar_t  name[LF_FACESIZE];  ///<��������
};

///PGrid ������������Ϣ
struct propertyGrid_item_
{
	propertyGrid_item_type_ nType; ///<����
	int   nID;           ///<��ID
	int   nDepth;        ///<���
	vint  nUserData;     ///<�û�����
	int   nNameColWidth; ///<�����п��

	RECT  rcItem;   ///<����
	RECT  rcExpand; ///<չ��
	BOOL  bExpand;  ///<�Ƿ�չ��
	BOOL  bShow;    ///<�Ƿ�ɼ�
};


///Edit ��ʽ��Ϣ
struct edit_style_info_
{
	USHORT   type;    ///<��ʽ����
	USHORT   nRef;              ///<���ü���
	HXCGUI   hFont_image_obj;   ///<����,ͼƬ,UI����
	COLORREF color;             ///<��ɫ
	BOOL     bColor;            ///<�Ƿ�ʹ����ɫ
};

///Edit ���ݸ���-��ʽ
struct edit_data_copy_style_
{
	HIMAGE   hFont_image_obj; ///<����,ͼƬ,UI����
	COLORREF color;           ///<��ɫ
	BOOL     bColor;          ///<�Ƿ�ʹ����ɫ
};

///Edit ���ݸ���
struct edit_data_copy_
{
	int  nCount;       ///<��������
	int  nStyleCount;  ///<��ʽ����
	edit_data_copy_style_* pStyle; ///<��ʽ����
	UINT* pData;       ///<�������� ��λ2�ֽ�:��ʽ����, ��λ2�ֽ�:ֵ
};

///Editor ��ɫ��Ϣ
struct editor_color_
{
	BOOL       bAlignLineArrow;            ///<������ - �Ƿ���ʾ��ͷ
	COLORREF   clrMargin1;                 ///<����� - ����ɫ1, ��ʾ�ϵ�
	COLORREF   clrMargin2;                 ///<����� - ����ɫ2, ��ʾ�к�
	COLORREF   clrMargin_text;             ///<����� - �ı�ɫ - �к���ɫ
	COLORREF   clrMargin_breakpoint;       ///<����� - �ϵ�ɫ
	COLORREF   clrMargin_breakpointBorder; ///<����� - �ϵ����ɫ
	COLORREF   clrMargin_runRowArrow;      ///<����� - ����λ�ü�ͷ
	COLORREF   clrMargin_curRow;           ///<����� - ��ǰ��ָʾɫ,���������
	COLORREF   clrMargin_error;            ///<����� - ����ָʾɫ

	COLORREF   clrCurRowFull;       ///<ͻ����ʾ��ǰ����ɫ
	COLORREF   clrMatchSel;         ///<ƥ��ѡ���ı�����ɫ
	COLORREF   clrAlignLine;        ///<������
	COLORREF   clrAlignLineSel;     ///<������ - ѡ�����ݿ�
	COLORREF   clrFunSplitLine;     ///<�����ָ�����ɫ new
	//ѡ���ı����� ͨ��API����
	//�������ɫ   ͨ��API����

	int       styleSys;             ///<ϵͳ�ؼ���  return, break, for
	int       styleFunction;        ///<����
	int       styleVar;             ///<����
	int       styleDataType;        ///<������������  int, byte, char
	int       styleClass;           ///<��  class
	int       styleMacro;           ///<��
	int       styleEnum;            ///<ö��   new
	int       styleNumber;          ///<����
	int       styleString;          ///<�ַ���
	int       styleComment;         ///<ע��
	int       StylePunctuation;     ///<������  new
};

/// ����Ԫ��������
struct monthCal_item_
{
	int  nDay;     ///< ����
	int  nType;    ///< 1����,2����,3����
	int  nState;   ///< ���״̬ monthCal_state_flag_
	RECT rcItem;   ///< ������
};

///@}


///@defgroup  group_func_  �Ųʻص���������
///@{

typedef void (CALLBACK* funDebugError)(const char* pInfo);       //����ص�
typedef BOOL (CALLBACK* funLoadFile)(const wchar_t* pFileName);  //ͼƬ��Դ�ļ����ػص�
typedef void (CALLBACK* funCloudEvent)(const wchar_t* pFileName, int nEvent, HXCGUI hXCGUI);  //��UI�¼��ص�

typedef vint (CALLBACK* funCallUiThread)(vint data);
typedef void (CALLBACK* funIdle)();
typedef void (CALLBACK* funExit)();

typedef  void(CALLBACK* funAnimation)(HXCGUI hAnimation, int flag);
typedef  void(CALLBACK* funAnimationItem)(HXCGUI hAnimation, float pos);

///@}


///////////////////////////////////////////////////////////////////////////////////
/////////////�¼�ע��//////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

class bind_event_cpp
{
public:
	virtual BOOL  Equal(bind_event_cpp* p)=0;
	virtual void* GetThis()=0;
	virtual void* GetMFun(int &nSize)=0;
	virtual int HandleEvent(HELE hEle, BOOL bHnadle, UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL *pbHandled)=0;
	virtual int HandleEventWnd(HWINDOW hWindow, BOOL bHnadle, UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL *pbHandled)=0;
};

template<class R, class C, class F>
class bind_event_cpp_ : public bind_event_cpp
{
public:
	bind_event_cpp_(C* c,F f) :_c(c), _f(f){ }
	virtual BOOL Equal(bind_event_cpp* p){
		if(_c!=p->GetThis())
			return FALSE;
		int size=0;
		void*  f=p->GetMFun(size);
		if(sizeof(F)==size)
		{
			if(0==memcmp(f,&_f, size))
				return TRUE;
		}
		return FALSE;
	}
	virtual void* GetThis(){ return (void*)_c;}
	virtual void* GetMFun(int &nSize){ nSize=sizeof(F); return &_f; }

	template<class H, class A1>
	int CallT(int (C::* f)(A1), H hEleOrWindow, BOOL bHnadle, UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL* pbHandled)
	{	
		if(!bHnadle)
			return (_c->*f)(pbHandled);
		MessageBoxA(NULL, "HandleEvent_cpp_Call a1", "error", 0);
		return 0;
	}
	template<class H, class A1, class A2>
	int CallT(int (C::* f)(A1, A2), H hEleOrWindow, BOOL bHnadle, UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL* pbHandled)
	{
		if(!bHnadle)
			return (_c->*f)((A1)wParam, pbHandled);
		return (_c->*f)((A1)hEleOrWindow, pbHandled);
	}
	template<class H, class A1, class A2, class A3>
	int CallT(int (C::* f)(A1, A2, A3), H hEleOrWindow, BOOL bHnadle, UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL* pbHandled)
	{
		if (!bHnadle)
			return (_c->*f)((A1)wParam, (A2)lParam, pbHandled);
		return (_c->*f)((A1)hEleOrWindow, (A2)wParam, pbHandled);
	}
	template<class H, class A1, class A2, class A3, class A4>
	int CallT(int (C::* f)(A1, A2, A3, A4), H hEleOrWindow, BOOL bHnadle, UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL* pbHandled)
	{
		if (!bHnadle)
			return (_c->*f)((A1)nEvent, (A2)wParam, (A3)lParam, pbHandled);
		return (_c->*f)((A1)hEleOrWindow, (A2)wParam, (A3)lParam, pbHandled);
	}
	template<class H, class A1, class A2, class A3, class A4, class A5>
	int CallT(int (C::* f)(A1, A2, A3, A4, A5), H hEleOrWindow, BOOL bHnadle, UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL* pbHandled)
	{
		if (bHnadle)
			return (_c->*f)((A1)hEleOrWindow, (A2)nEvent, (A3)wParam, (A4)lParam, pbHandled);
		MessageBoxA(NULL, "HandleEvent_cpp_Call a5", "error", 0);
		return 0;
	}
	virtual int HandleEvent(HELE hEle, BOOL bHnadle, UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL* pbHandled)
	{
		return CallT(_f, hEle, bHnadle, nEvent, wParam, lParam, pbHandled);
	}
	virtual int HandleEventWnd(HWINDOW hWindow, BOOL bHnadle, UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL* pbHandled)
	{
		return CallT(_f, hWindow, bHnadle, nEvent, wParam, lParam, pbHandled);
	}
	C*  _c;
	F   _f;
};

struct bind_event_c
{
	enum MyEnum
	{
		event_c_ex,
		event_lua_ex,
		event_js_ex,
	} type;
	virtual ~bind_event_c() {}
	virtual BOOL Equal(bind_event_c* p) { return FALSE; };
	virtual void*  GetFunc() { return NULL; };
	virtual int HandleEvent(HELE hEle, BOOL bHandle, UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL *pbHandled) { return 0;  };
	virtual int HandleEventWnd(HWINDOW hWindow,BOOL bHandle ,UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL *pbHandled) { return 0; };
};

struct xc_event
{
	xc_event(int regType,const char* pFunName){
		m_pBind=0;
		m_pFunC=0;
		m_name[0]=0;
		m_regType=regType;
		if(pFunName) strcpy_s(m_name,pFunName);
	}
	int            m_regType;   //ע������, 0:CPP,1:CPP1,2:CPP2
	bind_event_cpp*  m_pBind;     //C++�¼��ص�
	bind_event_c*    m_pFunC;     //C�¼��ص�
	char           m_name[MAX_PATH]; //������

	BOOL Equal(xc_event* pEvent){
		if(m_pBind && pEvent->m_pBind)
			return (m_pBind->Equal(pEvent->m_pBind));
		if(m_pFunC && pEvent->m_pFunC)
			return (m_pFunC->Equal(pEvent->m_pFunC));
		return FALSE;
	}
	BOOL Equal(void* pFunc){
		if(m_pFunC){
			if(m_pFunC->GetFunc()==pFunc)
				return TRUE;
		}
		return FALSE;
	}
	int HandleEvent(HELE hEle,UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL *pbHandled)
	{
		if(m_pBind)
			return m_pBind->HandleEvent(hEle, m_regType, nEvent, wParam,lParam,pbHandled);
		if(m_pFunC)
			return m_pFunC->HandleEvent(hEle, m_regType, nEvent, wParam, lParam, pbHandled);
		MessageBoxA(NULL,"HandleEvent()","error",0);
		return 0;
	}
	int HandleEventWnd(HWINDOW hWindow, UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL *pbHandled)
	{
		if(m_pBind)
			return m_pBind->HandleEventWnd(hWindow, m_regType, nEvent,wParam,lParam,pbHandled);
		if(m_pFunC)
			return m_pFunC->HandleEventWnd(hWindow, m_regType, nEvent, wParam, lParam, pbHandled);
		MessageBoxA(NULL,"HandleEventWnd()","error",0);
		return 0;
	}
	char* GetFunName(){ return m_name; }
	virtual void Release(){
		if(m_pBind) delete m_pBind;
		if(m_pFunC) delete m_pFunC;
		delete this;
	}
};

XC_API BOOL WINAPI _XWnd_RegEvent(HWINDOW hWindow, UINT nEvent, xc_event* pEvent);
XC_API BOOL WINAPI _XWnd_RemoveEvent(HWINDOW hWindow, UINT nEvent, xc_event* pEvent);
XC_API BOOL WINAPI _XEle_RegEvent(HELE hEle, UINT nEvent, xc_event* pEvent);
XC_API BOOL WINAPI _XEle_RemoveEvent(HELE hEle, UINT nEvent, xc_event* pEvent);

template<class R,class C,class F>
BOOL XEle_RegEventCPP_tt(HXCGUI hXCGUI, UINT nEvent,int regType, BOOL bEle, C* c, F f,const char* pFunName){
	BOOL bResult=TRUE;
	bind_event_cpp*  pBind=new bind_event_cpp_<R,C, F>(c, f);
	xc_event*  pEvent=new xc_event(regType,pFunName);
	pEvent->m_pBind=pBind;
	if(-1==regType){
		if (bEle)
			bResult = _XEle_RemoveEvent((HELE)hXCGUI, nEvent, pEvent);
		else
			bResult = _XWnd_RemoveEvent((HWINDOW)hXCGUI, nEvent, pEvent);
		pEvent->Release();
	}else{
		if(bEle){
			if(FALSE==_XEle_RegEvent((HELE)hXCGUI, nEvent, pEvent))
			{
				pEvent->Release();
				bResult=FALSE;
			}
		}else{
			if(FALSE==_XWnd_RegEvent((HWINDOW)hXCGUI, nEvent, pEvent))
			{
				pEvent->Release();
				bResult=FALSE;
			}
		}
	}
	return bResult;
}

template<class R, class C, class CT, class A1>
BOOL XCGUI_RegEventCPP_t(HXCGUI hXCGUI, UINT nEvent, int type, BOOL bEle, C* c, R (CT::*f)(A1), const char* pFunName){
	return XEle_RegEventCPP_tt<R>(hXCGUI,nEvent,type,bEle,(CT*)c,f, pFunName);}

template<class R, class C, class CT, class A1, class A2> 
BOOL XCGUI_RegEventCPP_t(HXCGUI hXCGUI, UINT nEvent, int type, BOOL bEle, C* c, R (CT::*f)(A1,A2), const char* pFunName){
	return XEle_RegEventCPP_tt<R>(hXCGUI,nEvent,type,bEle,(CT*)c,f, pFunName);}

template<class R, class C, class CT, class A1, class A2, class A3> 
BOOL XCGUI_RegEventCPP_t(HXCGUI hXCGUI, UINT nEvent, int type, BOOL bEle, C* c, R (CT::*f)(A1,A2,A3), const char* pFunName){
	return XEle_RegEventCPP_tt<R>(hXCGUI,nEvent,type,bEle,(CT*)c,f, pFunName);}

template<class R, class C, class CT, class A1, class A2, class A3,class A4> 
BOOL XCGUI_RegEventCPP_t(HXCGUI hXCGUI, UINT nEvent, int type, BOOL bEle, C* c, R (CT::*f)(A1,A2,A3,A4), const char* pFunName){
	return XEle_RegEventCPP_tt<R>(hXCGUI,nEvent,type,bEle,(CT*)c,f, pFunName);}

template<class R, class C, class CT,class A1, class A2, class A3, class A4, class A5> 
BOOL XCGUI_RegEventCPP_t(HXCGUI hXCGUI, UINT nEvent, int type, BOOL bEle, C* c, R (CT::*f)(A1,A2,A3,A4,A5), const char* pFunName){
	return XEle_RegEventCPP_tt<R>(hXCGUI,nEvent,type,bEle,(CT*)c,f, pFunName);}


//@���� Ԫ��_ע���¼�CPP(���, �¼�����, �¼�����)
#define XEle_RegEventCPP(hXCGUI,Event,mFun)  XCGUI_RegEventCPP_t(hXCGUI,Event,FALSE,TRUE,this,mFun,#mFun)
//@���� Ԫ��_ע���¼�CPP1(���, �¼�����, �¼�����)
#define XEle_RegEventCPP1(hXCGUI,Event,mFun)  XCGUI_RegEventCPP_t(hXCGUI,Event,TRUE,TRUE,this,mFun,#mFun)
//@���� Ԫ��_�Ƴ��¼�CPP(���, �¼�����, �¼�����)
#define XEle_RemoveEventCPP(hXCGUI,Event,mFun) XCGUI_RegEventCPP_t(hXCGUI,Event,-1,TRUE,this,mFun,#mFun)

//@���� ����_ע���¼�CPP(���, �¼�����, �¼�����)
#define XWnd_RegEventCPP(hXCGUI,Event,mFun)  XCGUI_RegEventCPP_t(hXCGUI,Event,FALSE,FALSE,this,mFun,#mFun)
//@���� ����_ע���¼�CPP1(���, �¼�����, �¼�����)
#define XWnd_RegEventCPP1(hXCGUI,Event,mFun)  XCGUI_RegEventCPP_t(hXCGUI,Event,TRUE,FALSE,this,mFun,#mFun)
//@���� ����_�Ƴ��¼�CPP(���, �¼�����, �¼�����)
#define XWnd_RemoveEventCPP(hXCGUI,Event,mFun) XCGUI_RegEventCPP_t(hXCGUI,Event,-1,FALSE,this,mFun,#mFun)


//////////////////////////////////////////////////////////////////////
/////////////////////API//////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


XC_API int WINAPI XC_UnicodeToAnsi(const wchar_t* pIn, int inLen, out_ char* pOut, int outLen);
XC_API int WINAPI XC_AnsiToUnicode(const char* pIn, int inLen, out_ wchar_t* pOut, int outLen);

XC_API LRESULT WINAPI XC_SendMessage(HWINDOW hWindow, UINT msg, WPARAM wParam, LPARAM lParam);
XC_API BOOL    WINAPI XC_PostMessage(HWINDOW hWindow, UINT msg, WPARAM wParam, LPARAM lParam);
XC_API vint WINAPI XC_CallUiThread(funCallUiThread pCall, vint data);
XC_API void WINAPI XC_DebugToFileInfo(const char* pInfo);//��ӡ������Ϣ���ļ� xcgui_debug.txt
XC_API BOOL WINAPI XC_IsHELE(HXCGUI hEle); //�����
XC_API BOOL WINAPI XC_IsHWINDOW(HXCGUI hWindow); //�����
XC_API BOOL WINAPI XC_IsShape(HXCGUI hShape); //�����
XC_API BOOL WINAPI XC_IsHXCGUI(HXCGUI hXCGUI, XC_OBJECT_TYPE nType);
XC_API HWINDOW WINAPI XC_hWindowFromHWnd(HWND hWnd);
XC_API BOOL    WINAPI XC_SetActivateTopWindow();
XC_API BOOL WINAPI XC_SetProperty(HXCGUI hXCGUI, const wchar_t* pName, const wchar_t* pValue);
XC_API const wchar_t* WINAPI XC_GetProperty(HXCGUI hXCGUI, const wchar_t* pName);
XC_API BOOL WINAPI XC_RegisterWindowClassName(const wchar_t* pClassName); //ע�ᴰ������
XC_API BOOL WINAPI XC_IsSViewExtend(HELE hEle);  //�ж�Ԫ���Ƿ�ӹ�����ͼԪ����չ����Ԫ��,����������ͼԪ��
XC_API XC_OBJECT_TYPE WINAPI XC_GetObjectType(HXCGUI hXCGUI);
XC_API HXCGUI WINAPI XC_GetObjectByID(HWINDOW hWindow, int nID); //ͨ��ID��ȡ������
XC_API HXCGUI WINAPI XC_GetObjectByIDName(HWINDOW hWindow, const wchar_t* pName);
XC_API HXCGUI WINAPI XC_GetObjectByUID(int nUID);
XC_API HXCGUI WINAPI XC_GetObjectByUIDName(const wchar_t* pName);
XC_API HXCGUI WINAPI XC_GetObjectByName(const wchar_t* pName);
XC_API void WINAPI XC_SetPaintFrequency(int nMilliseconds); //����UI����Ƶ��
XC_API void WINAPI XC_SetTextRenderingHint(int  nType);   //�����ı���Ⱦ����
XC_API void WINAPI XC_EnableGdiDrawText(BOOL bEnable);
XC_API BOOL WINAPI XC_RectInRect(RECT* pRect1, RECT* pRect2);
XC_API void WINAPI XC_CombineRect(RECT* pDest, RECT* pSrc1, RECT* pSrc2);
XC_API void WINAPI XC_ShowLayoutFrame(BOOL bShow);
XC_API void WINAPI XC_EnableDebugFile(BOOL bEnable);
XC_API void WINAPI XC_EnableResMonitor(BOOL bEnable);
XC_API void WINAPI XC_SetLayoutFrameColor(COLORREF color);
XC_API void WINAPI XC_EnableErrorMessageBox(BOOL bEnabel);
XC_API void WINAPI XC_EnableAutoExitApp(BOOL bEnabel);
XC_API BOOL WINAPI XC_LoadResource(const wchar_t* pFileName);
XC_API BOOL WINAPI XC_LoadResourceZip(const wchar_t* pZipFileName, const wchar_t* pFileName, const wchar_t* pPassword = NULL);
XC_API BOOL WINAPI XC_LoadResourceZipMem(void* data, int length, const wchar_t* pFileName, const wchar_t* pPassword = NULL);
XC_API BOOL WINAPI XC_LoadResourceFromString(const char* pStringXML, const wchar_t* pFileName);
XC_API BOOL WINAPI XC_LoadResourceFromStringUtf8(const char* pStringXML, const wchar_t* pFileName);
XC_API BOOL WINAPI XC_LoadStyle(const wchar_t* pFileName);
XC_API BOOL WINAPI XC_LoadStyleZip(const wchar_t* pZipFile, const wchar_t* pFileName, const wchar_t* pPassword = NULL);
XC_API BOOL WINAPI XC_LoadStyleZipMem(void* data, int length, const wchar_t* pFileName, const wchar_t* pPassword = NULL);
XC_API void WINAPI XC_GetTextSize(const wchar_t* pString, int length, HFONTX hFontX, out_ SIZE* pOutSize);
XC_API void WINAPI XC_GetTextShowSize(const wchar_t* pString, int length, HFONTX hFontX, out_ SIZE* pOutSize);
XC_API void WINAPI XC_GetTextShowSizeEx(const wchar_t* pString, int length, HFONTX hFontX, int nTextAlign, out_ SIZE* pOutSize);
//XC_API void WINAPI XC_GetTextShowRect(const wchar_t* pString, int length, HFONTX hFontX, int width, out_ SIZE* pOutSize);
XC_API HFONTX WINAPI XC_GetDefaultFont(); //��ȡĬ������
XC_API void   WINAPI XC_SetDefaultFont(HFONTX hFontX); //����Ĭ������
XC_API void  WINAPI XC_AddFileSearchPath(const wchar_t* pPath);
XC_API void  WINAPI XC_InitFont(LOGFONTW* pFont, wchar_t* pName, int size, BOOL bBold = FALSE, BOOL bItalic = FALSE, BOOL bUnderline = FALSE, BOOL bStrikeOut = FALSE);
XC_API  void* WINAPI XC_Malloc(int size);
XC_API  void  WINAPI XC_Free(void* p);
XC_API void WINAPI _XC_SetType(HXCGUI hXCGUI, XC_OBJECT_TYPE nType);
XC_API void WINAPI _XC_AddType(HXCGUI hXCGUI, XC_OBJECT_TYPE nType);
XC_API void WINAPI _XC_BindData(HXCGUI hXCGUI, vint data);
XC_API vint WINAPI _XC_GetBindData(HXCGUI hXCGUI);
XC_API void WINAPI  XC_Alert(const wchar_t* pTitle, const wchar_t* pText);
XC_API HINSTANCE WINAPI XC_Sys_ShellExecute(HWND hwnd, const wchar_t* lpOperation, const wchar_t* lpFile, const wchar_t* lpParameters, const wchar_t* lpDirectory, int nShowCmd);
XC_API HMODULE WINAPI XC_LoadLibrary(const wchar_t* lpFileName);
XC_API FARPROC WINAPI XC_GetProcAddress(HMODULE hModule, const char* lpProcName);
XC_API BOOL    WINAPI XC_FreeLibrary(HMODULE hModule);
XC_API HMODULE WINAPI XC_LoadDll(const wchar_t* pDllFileName);
XC_API BOOL WINAPI XInitXCGUI(BOOL bD2D);
XC_API void WINAPI XRunXCGUI();
XC_API void WINAPI XExitXCGUI();
XC_API void WINAPI XC_PostQuitMessage(int nExitCode);
XC_API XC_OBJECT_TYPE    WINAPI XObj_GetType(HXCGUI hXCGUI);
XC_API XC_OBJECT_TYPE    WINAPI XObj_GetTypeBase(HXCGUI hXCGUI);
XC_API XC_OBJECT_TYPE_EX WINAPI XObj_GetTypeEx(HXCGUI hXCGUI);
XC_API void              WINAPI XUI_SetStyle(HXCGUI hXCGUI, XC_OBJECT_STYLE nStyle);
XC_API XC_OBJECT_STYLE   WINAPI XUI_GetStyle(HXCGUI hXCGUI);
XC_API void WINAPI XUI_EnableCSS(HXCGUI hXCGUI, BOOL bEnable);
XC_API void WINAPI XUI_SetCssName(HXCGUI hXCGUI, const wchar_t* pName);
XC_API const wchar_t* WINAPI XUI_GetCssName(HXCGUI hXCGUI);
XC_API BOOL   WINAPI XWidget_IsShow(HXCGUI hXCGUI);
XC_API void   WINAPI XWidget_Show(HXCGUI hXCGUI, BOOL bShow);
XC_API void   WINAPI XWidget_EnableLayoutControl(HXCGUI hXCGUI, BOOL bEnable);
XC_API BOOL   WINAPI XWidget_IsLayoutControl(HXCGUI hXCGUI);
XC_API HELE   WINAPI XWidget_GetParentEle(HXCGUI hXCGUI);
XC_API HXCGUI WINAPI XWidget_GetParent(HXCGUI hXCGUI);
XC_API HWND   WINAPI XWidget_GetHWND(HXCGUI hXCGUI);
XC_API HWINDOW WINAPI XWidget_GetHWINDOW(HXCGUI hXCGUI);
XC_API  void WINAPI _XC_RegJsBind(const char* pName, int func);
XC_API  void WINAPI XC_RegFunExit(funExit func);
XC_API HBKM WINAPI XBkM_Create();
XC_API void WINAPI XBkM_Destroy(HBKM hBkInfoM);
XC_API int  WINAPI XBkM_SetBkInfo(HBKM hBkInfoM, const wchar_t* pText);
XC_API int  WINAPI XBkM_AddInfo(HBKM hBkInfoM, const wchar_t* pText);
XC_API void WINAPI XBkM_AddBorder(HBKM hBkInfoM, int nState, COLORREF color, int width, int id);
XC_API void WINAPI XBkM_AddFill(HBKM hBkInfoM, int nState, COLORREF color, int id);
XC_API void WINAPI XBkM_AddImage(HBKM hBkInfoM, int nState, HIMAGE hImage, int id);
XC_API int  WINAPI XBkM_GetCount(HBKM hBkInfoM);
XC_API void WINAPI XBkM_Clear(HBKM hBkInfoM);
XC_API BOOL WINAPI XBkM_Draw(HBKM hBkInfoM, int nState, HDRAW hDraw, RECT* pRect);
XC_API BOOL WINAPI XBkM_DrawEx(HBKM hBkInfoM, int nState, HDRAW hDraw, RECT* pRect, int nStateEx);
XC_API void WINAPI XBkM_EnableAutoDestroy(HBKM hBkInfoM, BOOL bEnable);
XC_API void WINAPI XBkM_AddRef(HBKM hBkInfoM);
XC_API void WINAPI XBkM_Release(HBKM hBkInfoM);
XC_API int  WINAPI XBkM_GetRefCount(HBKM hBkInfoM);
XC_API HELE WINAPI XBtn_Create(int x, int y, int cx, int cy, const wchar_t* pName, HXCGUI hParent = NULL);
XC_API BOOL WINAPI XBtn_IsCheck(HELE hEle); //��ť�Ƿ�ѡ��
XC_API BOOL WINAPI XBtn_SetCheck(HELE hEle, BOOL bCheck);
XC_API void WINAPI XBtn_SetState(HELE hEle, common_state3_ nState);
XC_API common_state3_  WINAPI XBtn_GetState(HELE hEle);
XC_API button_state_   WINAPI XBtn_GetStateEx(HELE hEle);

XC_API void WINAPI XBtn_SetTypeEx(HELE hEle, XC_OBJECT_TYPE_EX nType);
XC_API void WINAPI XBtn_SetGroupID(HELE hEle, int nID);
XC_API int  WINAPI XBtn_GetGroupID(HELE hEle);
XC_API void WINAPI XBtn_SetBindEle(HELE hEle, HELE hBindEle);
XC_API HELE WINAPI XBtn_GetBindEle(HELE hEle);
XC_API void WINAPI XBtn_SetTextAlign(HELE hEle, int nFlags);
XC_API int  WINAPI XBtn_GetTextAlign(HELE hEle);
XC_API void WINAPI XBtn_SetIconAlign(HELE hEle, button_icon_align_ align);
XC_API void WINAPI XBtn_SetOffset(HELE hEle, int x, int y);
XC_API void WINAPI XBtn_SetOffsetIcon(HELE hEle, int x, int y);
XC_API void WINAPI XBtn_SetIconSpace(HELE hEle, int size);
XC_API void WINAPI XBtn_SetText(HELE hEle, const wchar_t* pName);
XC_API const wchar_t* WINAPI XBtn_GetText(HELE hEle);
XC_API void WINAPI XBtn_SetIcon(HELE hEle, HIMAGE hImage);
XC_API void WINAPI XBtn_SetIconDisable(HELE hEle, HIMAGE hImage);
XC_API HIMAGE WINAPI XBtn_GetIcon(HELE hEle, int nType);
XC_API void WINAPI XBtn_AddAnimationFrame(HELE hEle, HIMAGE hImage, UINT uElapse);
XC_API void WINAPI XBtn_EnableAnimation(HELE hEle, BOOL bEnable, BOOL bLoopPlay = FALSE);


XC_API HELE WINAPI XComboBox_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API BOOL  WINAPI XComboBox_SetSelItem(HELE hEle, int iIndex);
XC_API void WINAPI XComboBox_GetButtonRect(HELE hEle, out_ RECT* pRect);
XC_API void WINAPI XComboBox_SetButtonSize(HELE hEle, int size);
XC_API void WINAPI XComboBox_SetDropHeight(HELE hEle, int height); //���������б�߶�
XC_API int  WINAPI XComboBox_GetDropHeight(HELE hEle);
XC_API HXCGUI WINAPI XComboBox_CreateAdapter(HELE hEle);
XC_API void WINAPI XComboBox_BindAdapter(HELE hEle, HXCGUI hAdapter);
XC_API HXCGUI WINAPI XComboBox_GetAdapter(HELE hEle);
XC_API void WINAPI XComboBox_SetBindName(HELE hEle, const wchar_t* pName);
XC_API void WINAPI XComboBox_SetItemTemplateXML(HELE hEle, const wchar_t* pXmlFile);
XC_API void WINAPI XComboBox_SetItemTemplateXMLFromString(HELE hEle, const char* pStringXML);
XC_API void WINAPI XComboBox_EnableDrawButton(HELE hEle, BOOL bEnable);
XC_API void WINAPI XComboBox_EnableEdit(HELE hEle, BOOL bEdit);  //�����༭����
XC_API void WINAPI XComboBox_EnableDropHeightFixed(HELE hEle, BOOL bEnable);

XC_API int WINAPI XComboBox_GetSelItem(HELE hEle);
XC_API comboBox_state_ WINAPI XComboBox_GetState(HELE hEle);
XC_API int WINAPI XComboBox_AddItemText(HELE hEle, const wchar_t* pText);
XC_API int WINAPI XComboBox_AddItemTextEx(HELE hEle, const wchar_t* pName, const wchar_t* pText);
XC_API int WINAPI XComboBox_AddItemImage(HELE hEle, HIMAGE hImage);
XC_API int WINAPI XComboBox_AddItemImageEx(HELE hEle, const wchar_t* pName, HIMAGE hImage);
XC_API int WINAPI XComboBox_InsertItemText(HELE hEle, int iItem, const wchar_t* pValue);
XC_API int WINAPI XComboBox_InsertItemTextEx(HELE hEle, int iItem, const wchar_t* pName, const wchar_t* pValue);
XC_API int WINAPI XComboBox_InsertItemImage(HELE hEle, int iItem, HIMAGE hImage);
XC_API int WINAPI XComboBox_InsertItemImageEx(HELE hEle, int iItem, const wchar_t* pName, HIMAGE hImage);
XC_API BOOL WINAPI XComboBox_SetItemText(HELE hEle, int iItem, int iColumn, const wchar_t* pText);
XC_API BOOL WINAPI XComboBox_SetItemTextEx(HELE hEle, int iItem, const wchar_t* pName, const wchar_t* pText);
XC_API BOOL WINAPI XComboBox_SetItemImage(HELE hEle, int iItem, int iColumn, HIMAGE hImage);
XC_API BOOL WINAPI XComboBox_SetItemImageEx(HELE hEle, int iItem, const wchar_t* pName, HIMAGE hImage);
XC_API BOOL WINAPI XComboBox_SetItemInt(HELE hEle, int iItem, int iColumn, int nValue);
XC_API BOOL WINAPI XComboBox_SetItemIntEx(HELE hEle, int iItem, const wchar_t* pName, int nValue);
XC_API BOOL WINAPI XComboBox_SetItemFloat(HELE hEle, int iItem, int iColumn, float fFloat);
XC_API BOOL WINAPI XComboBox_SetItemFloatEx(HELE hEle, int iItem, const wchar_t* pName, float fFloat);
XC_API const wchar_t* WINAPI XComboBox_GetItemText(HELE hEle, int iItem, int iColumn);
XC_API const wchar_t* WINAPI XComboBox_GetItemTextEx(HELE hEle, int iItem, const wchar_t* pName);
XC_API HIMAGE WINAPI XComboBox_GetItemImage(HELE hEle, int iItem, int iColumn);
XC_API HIMAGE WINAPI XComboBox_GetItemImageEx(HELE hEle, int iItem, const wchar_t* pName);
XC_API BOOL WINAPI XComboBox_GetItemInt(HELE hEle, int iItem, int iColumn, out_ int* pOutValue);
XC_API BOOL WINAPI XComboBox_GetItemIntEx(HELE hEle, int iItem, const wchar_t* pName, out_ int* pOutValue);
XC_API BOOL WINAPI XComboBox_GetItemFloat(HELE hEle, int iItem, int iColumn, out_ float* pOutValue);
XC_API BOOL WINAPI XComboBox_GetItemFloatEx(HELE hEle, int iItem, const wchar_t* pName, out_ float* pOutValue);
XC_API BOOL WINAPI XComboBox_DeleteItem(HELE hEle, int iItem);
XC_API BOOL WINAPI XComboBox_DeleteItemEx(HELE hEle, int iItem, int nCount);
XC_API void WINAPI XComboBox_DeleteItemAll(HELE hEle);
XC_API void WINAPI XComboBox_DeleteColumnAll(HELE hEle);
XC_API int WINAPI XComboBox_GetCount(HELE hEle);
XC_API int WINAPI XComboBox_GetCountColumn(HELE hEle);
XC_API HELE WINAPI XDateTime_Create(int x, int y, int cx, int cy, HXCGUI hParent);
XC_API void WINAPI XDateTime_SetStyle(HELE hEle, int nStyle);
XC_API int WINAPI XDateTime_GetStyle(HELE hEle);
XC_API void WINAPI XDateTime_EnableSplitSlash(HELE hEle, BOOL bSlash);
XC_API void WINAPI XDateTime_GetTime(HELE hEle, out_ int* pnHour, out_ int* pnMinute, out_ int* pnSecond);
XC_API void WINAPI XDateTime_SetTime(HELE hEle, int nHour, int nMinute, int nSecond);
XC_API void WINAPI XDateTime_GetDate(HELE hEle, out_ int* pnYear, out_ int* pnMonth, out_ int* pnDay);
XC_API void WINAPI XDateTime_SetDate(HELE hEle, int nYear, int nMonth, int nDay);
XC_API COLORREF WINAPI XDateTime_GetSelBkColor(HELE hEle);
XC_API void WINAPI XDateTime_SetSelBkColor(HELE hEle, COLORREF crSelectBk);
XC_API HELE WINAPI XDateTime_GetButton(HELE hEle, int nType);
XC_API HELE WINAPI XMonthCal_Create(int x, int y, int cx, int cy, HXCGUI hParent);
XC_API void WINAPI XMonthCal_SetToday(HELE hEle, int nYear, int nMonth, int nDay);
XC_API void WINAPI XMonthCal_GetToday(HELE hEle, out_ int* pnYear, out_ int* pnMonth, out_ int* pnDay);
XC_API void WINAPI XMonthCal_SeSelDate(HELE hEle, int nYear, int nMonth, int nDay);
XC_API void WINAPI XMonthCal_GetSelDate(HELE hEle, out_ int* pnYear, out_ int* pnMonth, out_ int* pnDay);
XC_API HELE WINAPI XMonthCal_GetButton(HELE hEle, monthCal_button_type_ nType);
XC_API int  WINAPI XAd_AddRef(HXCGUI hAdapter);
XC_API int  WINAPI XAd_Release(HXCGUI hAdapter);
XC_API int  WINAPI XAd_GetRefCount(HXCGUI hAdapter);
XC_API void WINAPI XAd_Destroy(HXCGUI hAdapter);
XC_API void WINAPI XAd_EnableAutoDestroy(HXCGUI hAdapter, BOOL bEnable);
XC_API HXCGUI WINAPI XAdListView_Create();
XC_API int  WINAPI XAdListView_Group_AddColumn(HXCGUI hAdapter, const wchar_t* pName);
XC_API int  WINAPI XAdListView_Group_AddItemText(HXCGUI hAdapter, const wchar_t* pValue, int iPos = -1);
XC_API int  WINAPI XAdListView_Group_AddItemTextEx(HXCGUI hAdapter, const wchar_t* pName, const wchar_t* pValue, int iPos = -1);
XC_API int  WINAPI XAdListView_Group_AddItemImage(HXCGUI hAdapter, HIMAGE hImage, int iPos = -1);
XC_API int  WINAPI XAdListView_Group_AddItemImageEx(HXCGUI hAdapter, const wchar_t* pName, HIMAGE hImage, int iPos = -1);
XC_API BOOL WINAPI XAdListView_Group_SetText(HXCGUI hAdapter, int iGroup, int iColumn, const wchar_t* pValue);
XC_API BOOL WINAPI XAdListView_Group_SetTextEx(HXCGUI hAdapter, int iGroup, const wchar_t* pName, const wchar_t* pValue);
XC_API BOOL WINAPI XAdListView_Group_SetImage(HXCGUI hAdapter, int iGroup, int iColumn, HIMAGE hImage);
XC_API BOOL WINAPI XAdListView_Group_SetImageEx(HXCGUI hAdapter, int iGroup, const wchar_t* pName, HIMAGE hImage);
XC_API int  WINAPI XAdListView_Group_GetCount(HXCGUI hAdapter);
XC_API int  WINAPI XAdListView_Item_GetCount(HXCGUI hAdapter, int iGroup);
XC_API int  WINAPI XAdListView_Item_AddColumn(HXCGUI hAdapter, const wchar_t* pName);  //������
XC_API int  WINAPI XAdListView_Item_AddItemText(HXCGUI hAdapter, int iGroup, const wchar_t* pValue, int iPos = -1);
XC_API int  WINAPI XAdListView_Item_AddItemTextEx(HXCGUI hAdapter, int iGroup, const wchar_t* pName, const wchar_t* pValue, int iPos = -1);
XC_API int  WINAPI XAdListView_Item_AddItemImage(HXCGUI hAdapter, int iGroup, HIMAGE hImage, int iPos = -1);
XC_API int  WINAPI XAdListView_Item_AddItemImageEx(HXCGUI hAdapter, int iGroup, const wchar_t* pName, HIMAGE hImage, int iPos = -1);
XC_API BOOL WINAPI XAdListView_Item_SetText(HXCGUI hAdapter, int iGroup, int iItem, int iColumn, const wchar_t* pValue);
XC_API BOOL WINAPI XAdListView_Item_SetTextEx(HXCGUI hAdapter, int iGroup, int iItem, const wchar_t* pName, const wchar_t* pValue);
XC_API BOOL WINAPI XAdListView_Item_SetImage(HXCGUI hAdapter, int iGroup, int iItem, int iColumn, HIMAGE hImage);
XC_API BOOL WINAPI XAdListView_Item_SetImageEx(HXCGUI hAdapter, int iGroup, int iItem, const wchar_t* pName, HIMAGE hImage);
XC_API BOOL WINAPI XAdListView_Group_DeleteItem(HXCGUI hAdapter, int iGroup);
XC_API void WINAPI XAdListView_Group_DeleteAllChildItem(HXCGUI hAdapter, int iGroup);
XC_API BOOL WINAPI XAdListView_Item_DeleteItem(HXCGUI hAdapter, int iGroup, int iItem);
XC_API void WINAPI XAdListView_DeleteAll(HXCGUI hAdapter);
XC_API void WINAPI XAdListView_DeleteAllGroup(HXCGUI hAdapter);
XC_API void WINAPI XAdListView_DeleteAllItem(HXCGUI hAdapter);
XC_API void WINAPI XAdListView_DeleteColumnGroup(HXCGUI hAdapter, int iColumn);
XC_API void WINAPI XAdListView_DeleteColumnItem(HXCGUI hAdapter, int iColumn);
XC_API const wchar_t* WINAPI XAdListView_Item_GetTextEx(HXCGUI hAdapter, int iGroup, int iItem, const wchar_t* pName);
XC_API HIMAGE WINAPI XAdListView_Item_GetImageEx(HXCGUI hAdapter, int iGroup, int iItem, const wchar_t* pName);
XC_API HXCGUI WINAPI XAdTable_Create();
XC_API void   WINAPI XAdTable_Sort(HXCGUI hAdapter, int iColumn, BOOL bAscending);  //����
XC_API adapter_date_type_  WINAPI XAdTable_GetItemDataType(HXCGUI hAdapter, int iItem, int iColumn);
XC_API adapter_date_type_  WINAPI XAdTable_GetItemDataTypeEx(HXCGUI hAdapter, int iItem, const wchar_t* pName);
XC_API int WINAPI XAdTable_AddColumn(HXCGUI hAdapter, const wchar_t* pName);
XC_API int WINAPI XAdTable_SetColumn(HXCGUI hAdapter, const wchar_t* pColName);
XC_API int WINAPI XAdTable_AddItemText(HXCGUI hAdapter, const wchar_t* pValue);
XC_API int WINAPI XAdTable_AddItemTextEx(HXCGUI hAdapter, const wchar_t* pName, const wchar_t* pValue);
XC_API int WINAPI XAdTable_AddItemImage(HXCGUI hAdapter, HIMAGE hImage);
XC_API int WINAPI XAdTable_AddItemImageEx(HXCGUI hAdapter, const wchar_t* pName, HIMAGE hImage);
XC_API int WINAPI XAdTable_InsertItemText(HXCGUI hAdapter, int iItem, const wchar_t* pValue);
XC_API int WINAPI XAdTable_InsertItemTextEx(HXCGUI hAdapter, int iItem, const wchar_t* pName, const wchar_t* pValue);
XC_API int WINAPI XAdTable_InsertItemImage(HXCGUI hAdapter, int iItem, HIMAGE hImage);
XC_API int WINAPI XAdTable_InsertItemImageEx(HXCGUI hAdapter, int iItem, const wchar_t* pName, HIMAGE hImage);
XC_API BOOL WINAPI XAdTable_SetItemText(HXCGUI hAdapter, int iItem, int iColumn, const wchar_t* pValue);
XC_API BOOL WINAPI XAdTable_SetItemTextEx(HXCGUI hAdapter, int iItem, const wchar_t* pName, const wchar_t* pValue);
XC_API BOOL WINAPI XAdTable_SetItemInt(HXCGUI hAdapter, int iItem, int iColumn, int nValue);
XC_API BOOL WINAPI XAdTable_SetItemIntEx(HXCGUI hAdapter, int iItem, const wchar_t* pName, int nValue);
XC_API BOOL WINAPI XAdTable_SetItemFloat(HXCGUI hAdapter, int iItem, int iColumn, float nValue);
XC_API BOOL WINAPI XAdTable_SetItemFloatEx(HXCGUI hAdapter, int iItem, const wchar_t* pName, float nValue);
XC_API BOOL WINAPI XAdTable_SetItemImage(HXCGUI hAdapter, int iItem, int iColumn, HIMAGE hImage);
XC_API BOOL WINAPI XAdTable_SetItemImageEx(HXCGUI hAdapter, int iItem, const wchar_t* pName, HIMAGE hImage);
XC_API BOOL WINAPI XAdTable_DeleteItem(HXCGUI hAdapter, int iItem);
XC_API BOOL WINAPI XAdTable_DeleteItemEx(HXCGUI hAdapter, int iItem, int nCount);
XC_API void WINAPI XAdTable_DeleteItemAll(HXCGUI hAdapter);
XC_API void WINAPI XAdTable_DeleteColumnAll(HXCGUI hAdapter);
XC_API int WINAPI XAdTable_GetCount(HXCGUI hAdapter);
XC_API int WINAPI XAdTable_GetCountColumn(HXCGUI hAdapter);
XC_API const wchar_t* WINAPI XAdTable_GetItemText(HXCGUI hAdapter, int iItem, int iColumn);
XC_API const wchar_t* WINAPI XAdTable_GetItemTextEx(HXCGUI hAdapter, int iItem, const wchar_t* pName);
XC_API HIMAGE WINAPI XAdTable_GetItemImage(HXCGUI hAdapter, int iItem, int iColumn);
XC_API HIMAGE WINAPI XAdTable_GetItemImageEx(HXCGUI hAdapter, int iItem, const wchar_t* pName);
XC_API BOOL WINAPI XAdTable_GetItemInt(HXCGUI hAdapter, int iItem, int iColumn, out_ int* pOutValue);
XC_API BOOL WINAPI XAdTable_GetItemIntEx(HXCGUI hAdapter, int iItem, const wchar_t* pName, out_ int* pOutValue);
XC_API BOOL WINAPI XAdTable_GetItemFloat(HXCGUI hAdapter, int iItem, int iColumn, out_ float* pOutValue);
XC_API BOOL WINAPI XAdTable_GetItemFloatEx(HXCGUI hAdapter, int iItem, const wchar_t* pName, out_ float* pOutValue);
XC_API HXCGUI WINAPI XAdTree_Create();
XC_API int WINAPI XAdTree_AddColumn(HXCGUI hAdapter, const wchar_t* pName);
XC_API int WINAPI XAdTree_SetColumn(HXCGUI hAdapter, const wchar_t* pColName);
XC_API int WINAPI XAdTree_InsertItemText(HXCGUI hAdapter, const wchar_t* pValue, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST);
XC_API int WINAPI XAdTree_InsertItemTextEx(HXCGUI hAdapter, const wchar_t* pName, const wchar_t* pValue, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST);
XC_API int WINAPI XAdTree_InsertItemImage(HXCGUI hAdapter, HIMAGE hImage, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST);
XC_API int WINAPI XAdTree_InsertItemImageEx(HXCGUI hAdapter, const wchar_t* pName, HIMAGE hImage, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST);
XC_API int WINAPI XAdTree_GetCount(HXCGUI hAdapter);
XC_API int WINAPI XAdTree_GetCountColumn(HXCGUI hAdapter);
XC_API BOOL WINAPI XAdTree_SetItemText(HXCGUI hAdapter, int nID, int iColumn, const wchar_t* pValue);
XC_API BOOL WINAPI XAdTree_SetItemTextEx(HXCGUI hAdapter, int nID, const wchar_t* pName, const wchar_t* pValue);
XC_API BOOL WINAPI XAdTree_SetItemImage(HXCGUI hAdapter, int nID, int iColumn, HIMAGE hImage);
XC_API BOOL WINAPI XAdTree_SetItemImageEx(HXCGUI hAdapter, int nID, const wchar_t* pName, HIMAGE hImage);
XC_API const wchar_t* WINAPI XAdTree_GetItemText(HXCGUI hAdapter, int nID, int iColumn);
XC_API const wchar_t* WINAPI XAdTree_GetItemTextEx(HXCGUI hAdapter, int nID, const wchar_t* pName);
XC_API HIMAGE WINAPI XAdTree_GetItemImage(HXCGUI hAdapter, int nID, int iColumn);
XC_API HIMAGE WINAPI XAdTree_GetItemImageEx(HXCGUI hAdapter, int nID, const wchar_t* pName);
XC_API BOOL WINAPI XAdTree_DeleteItem(HXCGUI hAdapter, int nID);
XC_API void WINAPI XAdTree_DeleteItemAll(HXCGUI hAdapter);
XC_API void WINAPI XAdTree_DeleteColumnAll(HXCGUI hAdapter);
XC_API HXCGUI WINAPI XAdMap_Create();
XC_API BOOL WINAPI XAdMap_AddItemText(HXCGUI hAdapter, const wchar_t* pName, const wchar_t* pValue);
XC_API BOOL WINAPI XAdMap_AddItemImage(HXCGUI hAdapter, const wchar_t* pName, HIMAGE hImage);
XC_API BOOL WINAPI XAdMap_DeleteItem(HXCGUI hAdapter, const wchar_t* pName);
XC_API int  WINAPI XAdMap_GetCount(HXCGUI hAdapter);
XC_API const wchar_t* WINAPI XAdMap_GetItemText(HXCGUI hAdapter, const wchar_t* pName);
XC_API HIMAGE WINAPI XAdMap_GetItemImage(HXCGUI hAdapter, const wchar_t* pName);
XC_API BOOL WINAPI XAdMap_SetItemText(HXCGUI hAdapter, const wchar_t* pName, const wchar_t* pValue);
XC_API BOOL WINAPI XAdMap_SetItemImage(HXCGUI hAdapter, const wchar_t* pName, HIMAGE hImage);
XC_API void WINAPI XDebug_Print(int  level, const char* pInfo);
XC_API void WINAPI _xtrace(const char* pFormat, ...); //֧�ֶ��߳�
XC_API void WINAPI _xtracew(const wchar_t* pFormat, ...); //֧�ֶ��߳�
XC_API void WINAPI XDebug_OutputDebugStringA(const char* pString); //OutputDebugStringA
XC_API void WINAPI XDebug_OutputDebugStringW(const wchar_t* pString); //OutputDebugStringW
XC_API void WINAPI XDebug_Set_OutputDebugString_UTF8(BOOL bUTF8); //����debug������뷽ʽ encoding_utf8

XC_API float WINAPI XEase_Linear(float p);
XC_API float WINAPI XEase_Quad(float p, ease_type_ flag);
XC_API float WINAPI XEase_Cubic(float p, ease_type_ flag);
XC_API float WINAPI XEase_Quart(float p, ease_type_ flag);
XC_API float WINAPI XEase_Quint(float p, ease_type_ flag);
XC_API float WINAPI XEase_Sine(float p, ease_type_ flag);
XC_API float WINAPI XEase_Expo(float p, ease_type_ flag);
XC_API float WINAPI XEase_Circ(float p, ease_type_ flag);
XC_API float WINAPI XEase_Elastic(float p, ease_type_ flag);
XC_API float WINAPI XEase_Back(float p, ease_type_ flag);
XC_API float WINAPI XEase_Bounce(float p, ease_type_ flag);
XC_API HELE WINAPI XEditor_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API void WINAPI XEidtor_EnableAutoMatchSpaseSelect(HELE hEle, BOOL bEnable);
XC_API BOOL WINAPI XEditor_IsBreakpoint(HELE hEle, int iRow);
XC_API BOOL WINAPI XEditor_SetBreakpoint(HELE hEle, int iRow, BOOL bActivate = TRUE);
XC_API int  WINAPI XEditor_GetBreakpointCount(HELE hEle);
XC_API int  WINAPI XEditor_GetBreakpoints(HELE hEle, out_buffer_ int* aPoints, int nCount);
XC_API void WINAPI XEditor_SetTipsDelay(HELE hEle, int nDelay);
XC_API void WINAPI XEditor_SetAutoMatchSelectModel(HELE hEle, int model);
XC_API BOOL WINAPI XEditor_RemoveBreakpoint(HELE hEle, int iRow);
XC_API void WINAPI XEditor_ClearBreakpoint(HELE hEle);
XC_API BOOL WINAPI XEditor_SetRunRow(HELE hEle, int iRow);
XC_API void WINAPI XEditor_GetColor(HELE hEle, out_ editor_color_* pInfo);
XC_API void WINAPI XEditor_SetColor(HELE hEle, editor_color_* pInfo);
XC_API void WINAPI XEditor_SetStyleKeyword(HELE hEle, int iStyle);
XC_API void WINAPI XEditor_SetStyleFunction(HELE hEle, int iStyle);
XC_API void WINAPI XEditor_SetStyleVar(HELE hEle, int iStyle);
XC_API void WINAPI XEditor_SetStyleDataType(HELE hEle, int iStyle);
XC_API void WINAPI XEditor_SetStyleClass(HELE hEle, int iStyle);
XC_API void WINAPI XEditor_SetStyleMacro(HELE hEle, int iStyle);
XC_API void WINAPI XEditor_SetStyleString(HELE hEle, int iStyle);
XC_API void WINAPI XEditor_SetStyleComment(HELE hEle, int iStyle);
XC_API void WINAPI XEditor_SetStyleNumber(HELE hEle, int iStyle);
XC_API void WINAPI XEditor_SetCurRow(HELE hEle, int iRow);
XC_API int  WINAPI XEditor_GetDepth(HELE hEle, int iRow);
XC_API int  WINAPI XEditor_ToExpandRow(HELE hEle, int iRow);
XC_API void WINAPI XEditor_ExpandAll(HELE hEle, BOOL bExpand);
XC_API void WINAPI XEditor_Expand(HELE hEle, int iRow, BOOL bExpand);
XC_API void WINAPI XEditor_ExpandEx(HELE hEle, int iRow);
XC_API void WINAPI XEditor_AddKeyword(HELE hEle, const wchar_t* pKey, int iStyle);
XC_API void WINAPI XEditor_AddConst(HELE hEle, const wchar_t* pKey);
XC_API void WINAPI XEditor_AddFunction(HELE hEle, const wchar_t* pKey);
XC_API void WINAPI XEditor_AddExcludeDefVarKeyword(HELE hEle, const wchar_t* pKeyword);
XC_API void WINAPI XEditor_FunArgsExpand_AddArg(HELE hEle, const wchar_t* pTypeName, const wchar_t* pArgName, const wchar_t* pText);
XC_API void WINAPI XEditor_FunArgsExpand_Expand(HELE hEle, const wchar_t* pFunName, int iRow, int iCol, int iCol2, int nDepth);
XC_API HELE WINAPI XEdit_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API HELE WINAPI XEdit_CreateEx(int x, int y, int cx, int cy, edit_type_ type, HXCGUI hParent = NULL);
XC_API void WINAPI XEdit_EnableAutoWrap(HELE hEle, BOOL bEnable);
XC_API void WINAPI XEdit_EnableReadOnly(HELE hEle, BOOL bEnable);
XC_API void WINAPI XEdit_EnableMultiLine(HELE hEle, BOOL bEnable);
XC_API void WINAPI XEdit_EnablePassword(HELE hEle, BOOL bEnable);
XC_API void WINAPI XEdit_EnableAutoSelAll(HELE hEle, BOOL bEnable);
XC_API void WINAPI XEdit_EnableAutoCancelSel(HELE hEle, BOOL bEnable);
XC_API BOOL WINAPI XEdit_IsReadOnly(HELE hEle);
XC_API BOOL WINAPI XEdit_IsMultiLine(HELE hEle);
XC_API BOOL WINAPI XEdit_IsPassword(HELE hEle);
XC_API BOOL WINAPI XEdit_IsAutoWrap(HELE hEle);
XC_API BOOL WINAPI XEdit_IsEmpty(HELE hEle);
XC_API BOOL WINAPI XEdit_IsInSelect(HELE hEle, int iRow, int iCol);
XC_API int  WINAPI XEdit_GetRowCount(HELE hEle);
XC_API edit_data_copy_* WINAPI XEdit_GetData(HELE hEle);
XC_API void WINAPI XEdit_AddData(HELE hEle, edit_data_copy_* pData, in_buffer_ USHORT* styleTable, int nStyleCount);
XC_API void WINAPI XEdit_FreeData(edit_data_copy_* pData);
XC_API void WINAPI XEdit_SetDefaultText(HELE hEle, const wchar_t* pString);
XC_API void WINAPI XEdit_SetDefaultTextColor(HELE hEle, COLORREF color);
XC_API void WINAPI XEdit_SetPasswordCharacter(HELE hEle, wchar_t  ch);
XC_API void WINAPI XEdit_SetTextAlign(HELE hEle, int  align);
XC_API void WINAPI XEdit_SetTabSpace(HELE hEle, int  nSpace);
XC_API void WINAPI XEdit_SetText(HELE hEle, const wchar_t* pString);
XC_API void WINAPI XEdit_SetTextInt(HELE hEle, int nValue);
XC_API int  WINAPI XEdit_GetText(HELE hEle, out_ wchar_t* pOut, int nOutlen);
XC_API int  WINAPI XEdit_GetTextRow(HELE hEle, int iRow, out_ wchar_t* pOut, int nOutlen);
XC_API int  WINAPI XEdit_GetLength(HELE hEle);
XC_API int  WINAPI XEdit_GetLengthRow(HELE hEle, int iRow);
XC_API wchar_t WINAPI XEdit_GetAt(HELE hEle, int iRow, int iCol);
XC_API void WINAPI XEdit_InsertText(HELE hEle, int iRow, int iCol, const wchar_t* pString);

//XC_API void WINAPI XEdit_InsertTextUser(HELE hEle, const wchar_t* pString);
XC_API void WINAPI XEdit_AddText(HELE hEle, const wchar_t* pString);
XC_API void WINAPI XEdit_AddTextEx(HELE hEle, const wchar_t* pString, int iStyle);
XC_API int  WINAPI XEdit_AddObject(HELE hEle, HXCGUI hObj);
XC_API void WINAPI XEdit_AddByStyle(HELE hEle, int iStyle);
XC_API int  WINAPI XEdit_AddStyle(HELE hEle, HXCGUI hFont_image_Obj, COLORREF color, BOOL bColor);
XC_API int  WINAPI XEdit_AddStyleEx(HELE hEle, const wchar_t* fontName, int fontSize, int fontStyle, COLORREF color, BOOL bColor);
XC_API BOOL WINAPI XEdit_GetStyleInfo(HELE hEle, int iStyle, out_ edit_style_info_* info);
XC_API void WINAPI XEdit_SetCurStyle(HELE hEle, int iStyle);
XC_API void WINAPI XEdit_SetCaretColor(HELE hEle, COLORREF  color);
XC_API void WINAPI XEdit_SetCaretWidth(HELE hEle, int nWidth);
XC_API void WINAPI XEdit_SetSelectBkColor(HELE hEle, COLORREF color);

XC_API void WINAPI XEdit_SetRowHeight(HELE hEle, int nHeight);
XC_API void WINAPI XEdit_SetRowHeightEx(HELE hEle, int iRow, int nHeight);
//XC_API void WINAPI XEdit_SetCurPos(HELE hEle, int iRow, int iCol);
XC_API int  WINAPI XEdit_GetCurPos(HELE hEle);
XC_API int  WINAPI XEdit_GetCurRow(HELE hEle);
XC_API int  WINAPI XEdit_GetCurCol(HELE hEle);
XC_API void WINAPI XEdit_GetPoint(HELE hEle, int iRow, int iCol, out_ POINT* pOut);
XC_API BOOL WINAPI XEdit_AutoScroll(HELE hEle);
XC_API BOOL WINAPI XEdit_AutoScrollEx(HELE hEle, int iRow, int iCol);
//XC_API void WINAPI XEdit_PositionToInfo(HELE hEle, int iPos, position_* pInfo);
XC_API BOOL WINAPI XEdit_SelectAll(HELE hEle);
XC_API BOOL WINAPI XEdit_CancelSelect(HELE hEle);
XC_API BOOL WINAPI XEdit_DeleteSelect(HELE hEle);
XC_API BOOL WINAPI XEdit_SetSelect(HELE hEle, int iStartRow, int iStartCol, int iEndRow, int iEndCol);
XC_API int  WINAPI XEdit_GetSelectText(HELE hEle, out_ wchar_t* pOut, int nOutLen);
XC_API BOOL WINAPI XEdit_GetSelectRange(HELE hEle, out_ position_* pBegin, out_ position_* pEnd);
XC_API void WINAPI XEdit_GetVisibleRowRange(HELE hEle, out_ int* piStart, out_ int* piEnd);
XC_API BOOL WINAPI XEdit_Delete(HELE hEle, int iStartRow, int iStartCol, int iEndRow, int iEndCol);
XC_API BOOL WINAPI XEdit_DeleteRow(HELE hEle, int iRow);
XC_API BOOL WINAPI XEdit_ClipboardCut(HELE hEle);
XC_API BOOL WINAPI XEdit_ClipboardCopy(HELE hEle);
XC_API BOOL WINAPI XEdit_ClipboardPaste(HELE hEle);
XC_API BOOL WINAPI XEdit_Undo(HELE hEle);
XC_API BOOL WINAPI XEdit_Redo(HELE hEle);
XC_API void WINAPI XEdit_AddChatBegin(HELE hEle, HIMAGE hImageAvatar, HIMAGE hImageBubble, int nFlag);
XC_API void WINAPI XEdit_AddChatEnd(HELE hEle);
XC_API void WINAPI XEdit_SetChatIndentation(HELE hEle, int nIndentation);
XC_API BOOL WINAPI XEdit_CommentSelect(HELE hEle);
XC_API BOOL WINAPI XEdit_IndentationSelect(HELE hEle, int bAdd);
XC_API HELE WINAPI XEle_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API BOOL WINAPI _XEle_RegEvent(HELE hEle, UINT nEvent, xc_event* pEvent);
XC_API BOOL WINAPI _XEle_RemoveEvent(HELE hEle, UINT nEvent, xc_event* pEvent);
XC_API BOOL WINAPI XEle_RegEventC(HELE hEle, int nEvent, void* pFun); //ע���¼�C��ʽ
XC_API BOOL WINAPI XEle_RegEventC1(HELE hEle, int nEvent, void* pFun);
XC_API BOOL WINAPI XEle_RegEventC2(HELE hEle, int nEvent, void* pFun);
XC_API BOOL WINAPI XEle_RemoveEventC(HELE hEle, int nEvent, void* pFun); //�Ƴ��¼�����C��ʽ
XC_API int  WINAPI XEle_SendEvent(HELE hEle, int nEvent, WPARAM wParam, LPARAM lParam);
XC_API BOOL WINAPI XEle_PostEvent(HELE hEle, int nEvent, WPARAM wParam, LPARAM lParam);
XC_API BOOL WINAPI XEle_IsShow(HELE hEle);
XC_API BOOL WINAPI XEle_IsEnable(HELE hEle);
XC_API BOOL WINAPI XEle_IsEnableFocus(HELE hEle);
XC_API BOOL WINAPI XEle_IsDrawFocus(HELE hEle);
XC_API BOOL WINAPI XEle_IsEnableEvent_XE_PAINT_END(HELE hEle);
XC_API BOOL WINAPI XEle_IsMouseThrough(HELE hEle);
XC_API BOOL WINAPI XEle_IsBkTransparent(HELE hEle);
XC_API BOOL WINAPI XEle_IsKeyTab(HELE hEle);
XC_API BOOL WINAPI XEle_IsSwitchFocus(HELE hEle);
XC_API BOOL WINAPI XEle_IsEnable_XE_MOUSEWHEEL(HELE hEle);
XC_API BOOL WINAPI XEle_IsChildEle(HELE hEle, HELE hChildEle);
XC_API BOOL WINAPI XEle_IsEnableCanvas(HELE hEle);
XC_API BOOL WINAPI XEle_IsFocus(HELE hEle);
XC_API BOOL WINAPI XEle_IsFocusEx(HELE hEle);
XC_API void WINAPI XEle_Enable(HELE hEle, BOOL bEnable);
XC_API void WINAPI XEle_EnableFocus(HELE hEle, BOOL bEnable);
XC_API void WINAPI XEle_EnableDrawFocus(HELE hEle, BOOL bEnable);
XC_API void WINAPI XEle_EnableDrawBorder(HELE hEle, BOOL bEnable);
XC_API void WINAPI XEle_EnableCanvas(HELE hEle, BOOL bEnable);
XC_API void WINAPI XEle_EnableBkTransparent(HELE hEle, BOOL bEnable);
XC_API void WINAPI XEle_EnableMouseThrough(HELE hEle, BOOL bEnable);
XC_API void WINAPI XEle_EnableKeyTab(HELE hEle, BOOL bEnable);
XC_API void WINAPI XEle_EnableSwitchFocus(HELE hEle, BOOL bEnable);
XC_API void WINAPI XEle_EnableEvent_XE_PAINT_END(HELE hEle, BOOL bEnable);
XC_API void WINAPI XEle_EnableEvent_XE_MOUSEWHEEL(HELE hEle, BOOL bEnable);
XC_API int  WINAPI XEle_SetRect(HELE hEle, RECT* pRect, BOOL bRedraw = FALSE, int nFlags = adjustLayout_all, UINT nAdjustNo = 0);
XC_API int  WINAPI XEle_SetRectEx(HELE hEle, int x, int y, int cx, int cy, BOOL bRedraw = FALSE, int nFlags = adjustLayout_all, UINT nAdjustNo = 0);
XC_API int  WINAPI XEle_SetRectLogic(HELE hEle, RECT* pRect, BOOL bRedraw = FALSE, int nFlags = adjustLayout_all, UINT nAdjustNo = 0); //�߼�ģʽ����
XC_API void WINAPI XEle_GetRect(HELE hEle, out_ RECT* pRect);   //����븸����,���۹۲�ģʽ
XC_API void WINAPI XEle_GetRectLogic(HELE hEle, out_ RECT* pRect); //����븸����,�߼�ģʽ
XC_API void WINAPI XEle_GetClientRect(HELE hEle, out_ RECT* pRect);  //���Ͻ�Ϊ0��0����
XC_API void WINAPI XEle_GetWndClientRect(HELE hEle, out_ RECT* pRect);
XC_API void WINAPI XEle_SetWidth(HELE hEle, int nWidth);
XC_API void WINAPI XEle_SetHeight(HELE hEle, int nHeight);
XC_API int  WINAPI XEle_GetWidth(HELE hEle);
XC_API int  WINAPI XEle_GetHeight(HELE hEle);
XC_API void WINAPI XEle_RectWndClientToEleClient(HELE hEle, in_out_ RECT* pRect);
XC_API void WINAPI XEle_PointWndClientToEleClient(HELE hEle, in_out_ POINT* pPt);
XC_API void WINAPI XEle_RectClientToWndClient(HELE hEle, in_out_ RECT* pRect);
XC_API void WINAPI XEle_PointClientToWndClient(HELE hEle, in_out_ POINT* pPt);
XC_API BOOL WINAPI XEle_AddChild(HELE hEle, HXCGUI hChild);
XC_API BOOL WINAPI XEle_InsertChild(HELE hEle, HXCGUI hChild, int index);  //���뵽ָ��λ��
XC_API void WINAPI XEle_Remove(HELE hEle);
XC_API BOOL WINAPI XEle_SetZOrder(HELE hEle, int index);
XC_API BOOL WINAPI XEle_SetZOrderEx(HELE hEle, HELE hDestEle, zorder_ nType);
XC_API int  WINAPI XEle_GetZOrder(HELE hEle);
XC_API BOOL WINAPI XEle_EnableTopmost(HELE hEle, BOOL bTopmost);


XC_API void WINAPI XEle_SetCursor(HELE hEle, HCURSOR hCursor);
XC_API HCURSOR WINAPI XEle_GetCursor(HELE hEle);

XC_API void WINAPI XEle_SetTextColor(HELE hEle, COLORREF color);
XC_API COLORREF WINAPI XEle_GetTextColor(HELE hEle);
XC_API COLORREF WINAPI XEle_GetTextColorEx(HELE hEle);
XC_API void WINAPI XEle_SetFocusBorderColor(HELE hEle, COLORREF color);
XC_API COLORREF WINAPI XEle_GetFocusBorderColor(HELE hEle);
XC_API void WINAPI XEle_SetFont(HELE hEle, HFONTX hFontx);
XC_API HFONTX WINAPI XEle_GetFont(HELE hEle);
XC_API HFONTX WINAPI XEle_GetFontEx(HELE hEle);
XC_API void WINAPI XEle_SetAlpha(HELE hEle, BYTE alpha);
XC_API BYTE WINAPI XEle_GetAlpha(HELE hEle);

XC_API int  WINAPI XEle_GetChildCount(HELE hEle);
XC_API HXCGUI WINAPI XEle_GetChildByIndex(HELE hEle, int index);
XC_API HXCGUI WINAPI XEle_GetChildByID(HELE hEle, int nID);
XC_API void WINAPI XEle_SetBorderSize(HELE hEle, int left, int top, int right, int bottom);
XC_API void WINAPI XEle_GetBorderSize(HELE hEle, out_ borderSize_* pBorder);
XC_API void WINAPI XEle_SetPadding(HELE hEle, int left, int top, int right, int bottom);
XC_API void WINAPI XEle_GetPadding(HELE hEle, out_ paddingSize_* pPadding);
XC_API void WINAPI XEle_SetDragBorder(HELE hEle, int nFlags);
XC_API void WINAPI XEle_SetDragBorderBindEle(HELE hEle, int nFlags, HELE hBindEle, int nSpace);
XC_API void WINAPI XEle_SetMinSize(HELE hEle, int nWidth, int nHeight);
XC_API void WINAPI XEle_SetMaxSize(HELE hEle, int nWidth, int nHeight);
XC_API void WINAPI XEle_SetLockScroll(HELE hEle, BOOL bHorizon, BOOL bVertical);
XC_API HELE WINAPI XEle_HitChildEle(HELE hEle, in_ POINT* pPt);
XC_API void WINAPI XEle_SetUserData(HELE hEle, vint nData);
XC_API vint WINAPI XEle_GetUserData(HELE hEle);
XC_API void WINAPI XEle_GetContentSize(HELE hEle, BOOL bHorizon, int cx, int cy, out_ SIZE* pSize);
XC_API void WINAPI XEle_SetCapture(HELE hEle, BOOL b);
XC_API void WINAPI XEle_Redraw(HELE hEle, BOOL bImmediate = FALSE);
XC_API void WINAPI XEle_RedrawRect(HELE hEle, RECT* pRect, BOOL bImmediate = FALSE);
XC_API void WINAPI XEle_Destroy(HELE hEle);  //����
XC_API void WINAPI XEle_AddBkBorder(HELE hEle,int nState, COLORREF color, int width);
XC_API void WINAPI XEle_AddBkFill(HELE hEle, int nState, COLORREF color);
XC_API void WINAPI XEle_AddBkImage(HELE hEle, int nState, HIMAGE hImage);
XC_API int  WINAPI XEle_GetBkInfoCount(HELE hEle);
XC_API void WINAPI XEle_ClearBkInfo(HELE hEle);
XC_API HBKM WINAPI XEle_GetBkManager(HELE hEle);
XC_API HBKM WINAPI XEle_GetBkManagerEx(HELE hEle);
XC_API void WINAPI XEle_SetBkManager(HELE hEle, HBKM hBkInfoM);
XC_API int  WINAPI XEle_GetStateFlags(HELE hEle); //��ȡ���״̬
XC_API BOOL WINAPI XEle_DrawFocus(HELE hEle, HDRAW hDraw, RECT* pRect);
XC_API void WINAPI XEle_DrawEle(HELE hEle, HDRAW hDraw);
XC_API void WINAPI XEle_EnableTransparentChannel(HELE hEle, BOOL bEnable);
XC_API BOOL WINAPI XEle_SetXCTimer(HELE hEle, UINT nIDEvent, UINT uElapse);
XC_API BOOL WINAPI XEle_KillXCTimer(HELE hEle, UINT nIDEvent);
XC_API void WINAPI XEle_SetToolTip(HELE hEle, const wchar_t* pText);
XC_API void WINAPI XEle_SetToolTipEx(HELE hEle, const wchar_t* pText, int nTextAlign);
XC_API const wchar_t* WINAPI XEle_GetToolTip(HELE hEle);
XC_API void WINAPI XEle_PopupToolTip(HELE hEle, int x, int y);
XC_API void WINAPI XEle_AdjustLayout(HELE hEle, UINT nAdjustNo = 0);
XC_API void WINAPI XEle_AdjustLayoutEx(HELE hEle, int nFlags = adjustLayout_self, UINT nAdjustNo = 0);

XC_API HFONTX WINAPI XFont_Create(int size);//��������
XC_API HFONTX WINAPI XFont_CreateEx(const wchar_t* pName = L"����", int size = 12, int style = fontStyle_regular);
XC_API HFONTX WINAPI XFont_CreateFromLOGFONTW(LOGFONTW* pFontInfo);
XC_API HFONTX WINAPI XFont_CreateFromHFONT(HFONT hFont);
XC_API HFONTX WINAPI XFont_CreateFromFont(void* pFont);
XC_API HFONTX WINAPI XFont_CreateFromFile(const wchar_t* pFontFile, int size = 12, int style =fontStyle_regular);
XC_API void   WINAPI XFont_EnableAutoDestroy(HFONTX hFontX, BOOL bEnable);
XC_API void* WINAPI XFont_GetFont(HFONTX hFontX);
XC_API void  WINAPI XFont_GetFontInfo(HFONTX hFontX, out_ font_info_* pInfo);
XC_API BOOL  WINAPI XFont_GetLOGFONTW(HFONTX hFontX, HDC hdc, out_ LOGFONTW* pOut);
XC_API void  WINAPI XFont_AddRef(HFONTX hFontX);   //�������ü���
XC_API void  WINAPI XFont_Release(HFONTX hFontX);  //�ͷ����ü���
XC_API int   WINAPI XFont_GetRefCount(HFONTX hFontX);
XC_API void  WINAPI XFont_Destroy(HFONTX hFontX);  //��������
XC_API HWINDOW WINAPI XFrameWnd_Create(int x, int y, int cx, int cy, const wchar_t* pTitle, HWND hWndParent, int XCStyle);  //��������
XC_API void WINAPI XFrameWnd_GetLayoutAreaRect(HWINDOW hWindow, out_ RECT* pRect); //��ȡ�ͻ���������������
XC_API void WINAPI XFrameWnd_SetView(HWINDOW hWindow, HELE hEle);
XC_API void WINAPI XFrameWnd_SetPaneSplitBarColor(HWINDOW hWindow, COLORREF color);
XC_API void WINAPI XFrameWnd_SetTabBarHeight(HWINDOW hWindow, int nHeight);
XC_API BOOL WINAPI XFrameWnd_SaveLayoutToFile(HWINDOW hWindow, const wchar_t* pFileName);
XC_API BOOL WINAPI XFrameWnd_LoadLayoutFile(HWINDOW hWindow, in_buffer_ HELE* aPaneList, int nEleCount, const wchar_t* pFileName);
XC_API BOOL WINAPI XFrameWnd_AddPane(HWINDOW hWindow, HELE hPaneDest, HELE hPaneNew, pane_align_ align);
XC_API BOOL WINAPI XFrameWnd_MergePane(HWINDOW hWindow, HELE hPaneDest, HELE hPaneNew);
XC_API HIMAGE WINAPI XImgSrc_LoadFile(const wchar_t* pFileName);//���ļ��м���ͼƬ
XC_API HIMAGE WINAPI XImgSrc_LoadFileRect(const wchar_t* pFileName, int x, int y, int cx, int cy);  //����ͼƬ,ָ������
XC_API HIMAGE WINAPI XImgSrc_LoadRes(int id, const wchar_t* pType, HMODULE hModule);//����Դ�м���ͼƬ
XC_API HIMAGE WINAPI XImgSrc_LoadZip(const wchar_t* pZipFileName, const wchar_t* pFileName, const wchar_t* pPassword = NULL);//��ZIP�м���ͼƬ
XC_API HIMAGE WINAPI XImgSrc_LoadZipRect(const wchar_t* pZipFileName, const wchar_t* pFileName, const wchar_t* pPassword, int x, int y, int cx, int cy);
XC_API HIMAGE WINAPI XImgSrc_LoadZipMem(void* data, int length, const wchar_t* pFileName, const wchar_t* pPassword = NULL);
XC_API HIMAGE WINAPI XImgSrc_LoadMemory(void* pBuffer, int nSize);
XC_API HIMAGE WINAPI XImgSrc_LoadMemoryRect(void* pBuffer, int nSize, int x, int y, int cx, int cy);
XC_API HIMAGE WINAPI XImgSrc_LoadFromImage(void* pImage);
XC_API HIMAGE WINAPI XImgSrc_LoadFromExtractIcon(const wchar_t* pFileName);
XC_API HIMAGE WINAPI XImgSrc_LoadFromHICON(HICON hIcon);
XC_API HIMAGE WINAPI XImgSrc_LoadFromHBITMAP(HBITMAP hBitmap);
XC_API void WINAPI XImgSrc_EnableAutoDestroy(HIMAGE hImage, BOOL bEnable); //���û�ر��Զ�����,����UIԪ�ع���ʱ��Ч
XC_API int WINAPI XImgSrc_GetWidth(HIMAGE hImage);
XC_API int WINAPI XImgSrc_GetHeight(HIMAGE hImage);
XC_API const wchar_t* WINAPI XImgSrc_GetFile(HIMAGE hImage);
XC_API void WINAPI XImgSrc_AddRef(HIMAGE hImage);
XC_API void WINAPI XImgSrc_Release(HIMAGE hImage);
XC_API int  WINAPI XImgSrc_GetRefCount(HIMAGE hImage);
XC_API void WINAPI XImgSrc_Destroy(HIMAGE hImage);
XC_API HIMAGE WINAPI XImage_LoadSrc(HIMAGE hImageSrc);
XC_API HIMAGE WINAPI XImage_LoadFile(const wchar_t* pFileName);
XC_API HIMAGE WINAPI XImage_LoadFileAdaptive(const wchar_t* pFileName, int leftSize, int topSize, int rightSize, int bottomSize);
XC_API HIMAGE WINAPI XImage_LoadFileRect(const wchar_t* pFileName, int x, int y, int cx, int cy);
XC_API HIMAGE WINAPI XImage_LoadResAdaptive(int id, const wchar_t* pType, int leftSize, int topSize, int rightSize, int bottomSize, HMODULE hInst = NULL);
XC_API HIMAGE WINAPI XImage_LoadRes(int id, const wchar_t* pType, HMODULE hInst = NULL);
XC_API HIMAGE WINAPI XImage_LoadZip(const wchar_t* pZipFileName, const wchar_t* pFileName, const wchar_t* pPassword = NULL);
XC_API HIMAGE WINAPI XImage_LoadZipAdaptive(const wchar_t* pZipFileName, const wchar_t* pFileName, const wchar_t* pPassword, int x1, int x2, int y1, int y2);
XC_API HIMAGE WINAPI XImage_LoadZipRect(const wchar_t* pZipFileName, const wchar_t* pFileName, const wchar_t* pPassword, int x, int y, int cx, int cy);
XC_API HIMAGE WINAPI XImage_LoadZipMem(void* data, int length, const wchar_t* pFileName, const wchar_t* pPassword = NULL);
XC_API HIMAGE WINAPI XImage_LoadMemory(void* pBuffer, int nSize);
XC_API HIMAGE WINAPI XImage_LoadMemoryRect(void* pBuffer, int nSize, int x, int y, int cx, int cy);
XC_API HIMAGE WINAPI XImage_LoadMemoryAdaptive(void* pBuffer, int nSize, int leftSize, int topSize, int rightSize, int bottomSize);
XC_API HIMAGE WINAPI XImage_LoadFromImage(void* pImage);
XC_API HIMAGE WINAPI XImage_LoadFromExtractIcon(const wchar_t* pFileName);
XC_API HIMAGE WINAPI XImage_LoadFromHICON(HICON hIcon);
XC_API HIMAGE WINAPI XImage_LoadFromHBITMAP(HBITMAP hBitmap);
XC_API BOOL WINAPI XImage_IsStretch(HIMAGE hImage);   //�Ƿ�����ͼƬ
XC_API BOOL WINAPI XImage_IsAdaptive(HIMAGE hImage);  //�Ƿ�Ϊ����ӦͼƬ
XC_API BOOL WINAPI XImage_IsTile(HIMAGE hImage);      //�Ƿ�Ϊƽ��ͼƬ
XC_API BOOL WINAPI XImage_SetDrawType(HIMAGE hImage, image_draw_type_ nType);//����ͼƬ��������
XC_API BOOL WINAPI XImage_SetDrawTypeAdaptive(HIMAGE hImage, int leftSize, int topSize, int rightSize, int bottomSize);//����ͼƬ����Ӧ
XC_API void WINAPI XImage_SetTranColor(HIMAGE hImage, COLORREF color); //����͸��ɫ
XC_API void WINAPI XImage_SetTranColorEx(HIMAGE hImage, COLORREF color, BYTE tranColor); //����͸��ɫ
XC_API float WINAPI XImage_SetRotateAngle(HIMAGE hImage, float  fAngle);
XC_API void WINAPI XImage_SetSplitEqual(HIMAGE hImage, int nCount, int iIndex);
XC_API void WINAPI XImage_EnableTranColor(HIMAGE hImage, BOOL bEnable); //����͸��ɫ
XC_API void WINAPI XImage_EnableAutoDestroy(HIMAGE hImage, BOOL bEnable); //���û�ر��Զ�����,����UIԪ�ع���ʱ��Ч
XC_API void WINAPI XImage_EnableCenter(HIMAGE hImage, BOOL bCenter); //bCenter
XC_API BOOL WINAPI XImage_IsCenter(HIMAGE hImage);
XC_API image_draw_type_ WINAPI XImage_GetDrawType(HIMAGE hImage); //��ȡͼƬ��������
XC_API int WINAPI XImage_GetWidth(HIMAGE hImage);
XC_API int WINAPI XImage_GetHeight(HIMAGE hImage);
XC_API HIMAGE WINAPI XImage_GetImageSrc(HIMAGE hImage);
XC_API void WINAPI XImage_AddRef(HIMAGE hImage);
XC_API void WINAPI XImage_Release(HIMAGE hImage);
XC_API int  WINAPI XImage_GetRefCount(HIMAGE hImage);
XC_API void WINAPI XImage_Destroy(HIMAGE hImage);
XC_API HELE WINAPI XLayout_Create(int x, int y, int cx, int cy, HXCGUI hParent);
XC_API HELE WINAPI XLayout_CreateEx(HXCGUI hParent);
XC_API BOOL WINAPI XLayout_IsEnableLayout(HELE hEle);
XC_API void WINAPI XLayout_EnableLayout(HELE hEle, BOOL bEnable);
XC_API void WINAPI XLayout_ShowLayoutFrame(HELE hEle, BOOL bEnable);
XC_API int  WINAPI XLayout_GetWidthIn(HELE hEle);
XC_API int  WINAPI XLayout_GetHeightIn(HELE hEle);
XC_API void WINAPI XLayoutBox_EnableHorizon(HXCGUI hLayoutBox, BOOL bEnable);
XC_API void WINAPI XLayoutBox_EnableAutoWrap(HXCGUI hLayoutBox, BOOL bEnable);
XC_API void WINAPI XLayoutBox_EnableOverflowHide(HXCGUI hLayoutBox, BOOL bEnable);
XC_API void WINAPI XLayoutBox_SetAlignH(HXCGUI hLayoutBox, layout_align_ nAlign);
XC_API void WINAPI XLayoutBox_SetAlignV(HXCGUI hLayoutBox, layout_align_ nAlign);
XC_API void WINAPI XLayoutBox_SetAlignBaseline(HXCGUI hLayoutBox, layout_align_axis_ nAlign);
XC_API void WINAPI XLayoutBox_SetSpace(HXCGUI hLayoutBox, int nSpace);
XC_API void WINAPI XLayoutBox_SetSpaceRow(HXCGUI hLayoutBox, int nSpace);

XC_API HELE WINAPI XLayoutFrame_Create(int x, int y, int cx, int cy, HXCGUI hParent);
XC_API void WINAPI XLayoutFrame_ShowLayoutFrame(HELE hEle, BOOL bEnable);
XC_API HELE WINAPI XListBox_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API void WINAPI XListBox_EnableFixedRowHeight(HELE hEle, BOOL bEnable);
XC_API void WINAPI XListBox_EnablemTemplateReuse(HELE hEle, BOOL bEnable);
XC_API void WINAPI XListBox_EnableVirtualTable(HELE hEle, BOOL bEnable);
XC_API void WINAPI XListBox_SetVirtualRowCount(HELE hEle, int nRowCount);
XC_API void WINAPI XListBox_SetDrawItemBkFlags(HELE hEle, int nFlags);
XC_API BOOL WINAPI XListBox_SetItemData(HELE hEle, int iItem, vint nUserData);
XC_API vint  WINAPI XListBox_GetItemData(HELE hEle, int iItem);
XC_API BOOL WINAPI XListBox_SetItemInfo(HELE hEle, int iItem, in_ listBox_item_info_* pItem);
XC_API BOOL WINAPI XListBox_GetItemInfo(HELE hEle, int iItem, out_ listBox_item_info_* pItem);

XC_API BOOL WINAPI XListBox_SetSelectItem(HELE hEle, int iItem);
XC_API int  WINAPI XListBox_GetSelectItem(HELE hEle);
XC_API BOOL WINAPI XListBox_AddSelectItem(HELE hEle, int iItem);
XC_API BOOL WINAPI XListBox_CancelSelectItem(HELE hEle, int iItem);
XC_API BOOL WINAPI XListBox_CancelSelectAll(HELE hEle);
XC_API int  WINAPI XListBox_GetSelectAll(HELE hEle, out_buffer_ int* pArray, int nArraySize);
XC_API int  WINAPI XListBox_GetSelectCount(HELE hEle);
XC_API int  WINAPI XListBox_GetItemMouseStay(HELE hEle);
XC_API BOOL WINAPI XListBox_SelectAll(HELE hEle);
XC_API void WINAPI XListBox_VisibleItem(HELE hEle, int iItem);
XC_API void WINAPI XListBox_GetVisibleRowRange(HELE hEle, out_ int* piStart, out_ int* piEnd);
XC_API void WINAPI XListBox_SetItemHeightDefault(HELE hEle, int nHeight, int nSelHeight);
XC_API void WINAPI XListBox_GetItemHeightDefault(HELE hEle, out_ int* pHeight, out_ int* pSelHeight);
XC_API int  WINAPI XListBox_GetItemIndexFromHXCGUI(HELE hEle, HXCGUI hXCGUI);
XC_API void WINAPI XListBox_SetRowSpace(HELE hEle, int nSpace);
XC_API int WINAPI  XListBox_GetRowSpace(HELE hEle);
XC_API int  WINAPI XListBox_HitTest(HELE hEle, POINT* pPt);
XC_API int  WINAPI XListBox_HitTestOffset(HELE hEle, POINT* pPt); //�Զ���ӹ�����ͼƫ����
XC_API BOOL WINAPI XListBox_SetItemTemplateXML(HELE hEle, const wchar_t* pXmlFile);
XC_API BOOL WINAPI XListBox_SetItemTemplateXMLFromString(HELE hEle, const char* pStringXML);
XC_API BOOL WINAPI XListBox_SetItemTemplate(HELE hEle, HTEMP hTemp);
XC_API HXCGUI WINAPI XListBox_GetTemplateObject(HELE hEle, int iItem, int nTempItemID);
XC_API void WINAPI XListBox_EnableMultiSel(HELE hEle, BOOL bEnable);
XC_API HXCGUI WINAPI XListBox_CreateAdapter(HELE hEle);
XC_API void   WINAPI XListBox_BindAdapter(HELE hEle, HXCGUI hAdapter);
XC_API HXCGUI WINAPI XListBox_GetAdapter(HELE hEle);
XC_API void WINAPI XListBox_Sort(HELE hEle, int iColumnAdapter, BOOL bAscending);  //��������
XC_API void WINAPI XListBox_RefreshData(HELE hEle);
XC_API void WINAPI XListBox_RefreshItem(HELE hEle, int iItem);
XC_API int WINAPI XListBox_AddItemText(HELE hEle, const wchar_t* pText);
XC_API int WINAPI XListBox_AddItemTextEx(HELE hEle, const wchar_t* pName, const wchar_t* pText);
XC_API int WINAPI XListBox_AddItemImage(HELE hEle, HIMAGE hImage);
XC_API int WINAPI XListBox_AddItemImageEx(HELE hEle, const wchar_t* pName, HIMAGE hImage);
XC_API int WINAPI XListBox_InsertItemText(HELE hEle, int iItem, const wchar_t* pValue);
XC_API int WINAPI XListBox_InsertItemTextEx(HELE hEle, int iItem, const wchar_t* pName, const wchar_t* pValue);
XC_API int WINAPI XListBox_InsertItemImage(HELE hEle, int iItem, HIMAGE hImage);
XC_API int WINAPI XListBox_InsertItemImageEx(HELE hEle, int iItem, const wchar_t* pName, HIMAGE hImage);
XC_API BOOL WINAPI XListBox_SetItemText(HELE hEle, int iItem, int iColumn, const wchar_t* pText);
XC_API BOOL WINAPI XListBox_SetItemTextEx(HELE hEle, int iItem, const wchar_t* pName, const wchar_t* pText);
XC_API BOOL WINAPI XListBox_SetItemImage(HELE hEle, int iItem, int iColumn, HIMAGE hImage);
XC_API BOOL WINAPI XListBox_SetItemImageEx(HELE hEle, int iItem, const wchar_t* pName, HIMAGE hImage);
XC_API BOOL WINAPI XListBox_SetItemInt(HELE hEle, int iItem, int iColumn, int nValue);
XC_API BOOL WINAPI XListBox_SetItemIntEx(HELE hEle, int iItem, const wchar_t* pName, int nValue);
XC_API BOOL WINAPI XListBox_SetItemFloat(HELE hEle, int iItem, int iColumn, float fFloat);
XC_API BOOL WINAPI XListBox_SetItemFloatEx(HELE hEle, int iItem, const wchar_t* pName, float fFloat);
XC_API const wchar_t* WINAPI XListBox_GetItemText(HELE hEle, int iItem, int iColumn);
XC_API const wchar_t* WINAPI XListBox_GetItemTextEx(HELE hEle, int iItem, const wchar_t* pName);
XC_API HIMAGE WINAPI XListBox_GetItemImage(HELE hEle, int iItem, int iColumn);
XC_API HIMAGE WINAPI XListBox_GetItemImageEx(HELE hEle, int iItem, const wchar_t* pName);
XC_API BOOL WINAPI XListBox_GetItemInt(HELE hEle, int iItem, int iColumn, out_ int* pOutValue);
XC_API BOOL WINAPI XListBox_GetItemIntEx(HELE hEle, int iItem, const wchar_t* pName, out_ int* pOutValue);
XC_API BOOL WINAPI XListBox_GetItemFloat(HELE hEle, int iItem, int iColumn, out_ float* pOutValue);
XC_API BOOL WINAPI XListBox_GetItemFloatEx(HELE hEle, int iItem, const wchar_t* pName, out_ float* pOutValue);
XC_API BOOL WINAPI XListBox_DeleteItem(HELE hEle, int iItem);
XC_API BOOL WINAPI XListBox_DeleteItemEx(HELE hEle, int iItem, int nCount);
XC_API void WINAPI XListBox_DeleteItemAll(HELE hEle);
XC_API void WINAPI XListBox_DeleteColumnAll(HELE hEle);
XC_API int WINAPI XListBox_GetCount_AD(HELE hEle);
XC_API int WINAPI XListBox_GetCountColumn_AD(HELE hEle);
XC_API HTEMP WINAPI XTemp_Load(listItemTemp_type_ nType, const wchar_t* pFileName);  //����ģ�� ����ģ�����
XC_API HTEMP WINAPI XTemp_LoadZip(listItemTemp_type_ nType, const wchar_t* pZipFile, const wchar_t* pFileName, const wchar_t* pPassword = NULL);
XC_API HTEMP WINAPI XTemp_LoadZipMem(listItemTemp_type_ nType, void* data, int length, const wchar_t* pFileName, const wchar_t* pPassword = NULL);
XC_API BOOL  WINAPI XTemp_LoadEx(listItemTemp_type_ nType, const wchar_t* pFileName, out_ HTEMP* pOutTemp1, out_ HTEMP* pOutTemp2);
XC_API BOOL  WINAPI XTemp_LoadZipEx(listItemTemp_type_ nType, const wchar_t* pZipFile, const wchar_t* pFileName, const wchar_t* pPassword, out_ HTEMP* pOutTemp1, out_ HTEMP* pOutTemp2);
XC_API BOOL  WINAPI XTemp_LoadZipMemEx(listItemTemp_type_ nType, void* data, int length, const wchar_t* pFileName, const wchar_t* pPassword, out_ HTEMP* pOutTemp1, out_ HTEMP* pOutTemp2);
XC_API HTEMP WINAPI XTemp_LoadFromString(listItemTemp_type_ nType, const char* pStringXML);  //����ģ��,���ڴ�, ����ģ�����
XC_API BOOL  WINAPI XTemp_LoadFromStringEx(listItemTemp_type_ nType, const char* pStringXML, out_ HTEMP* pOutTemp1, out_ HTEMP* pOutTemp2);
XC_API listItemTemp_type_ WINAPI XTemp_GetType(HTEMP hTemp);
XC_API BOOL  WINAPI XTemp_Destroy(HTEMP hTemp);
XC_API HTEMP WINAPI XTemp_Create(listItemTemp_type_ nType);
XC_API BOOL  WINAPI XTemp_AddNodeRoot(HTEMP hTemp, void* pNode);
XC_API BOOL  WINAPI XTemp_AddNode(void* pParentNode, void* pNode);
XC_API void* WINAPI XTemp_CreateNode(XC_OBJECT_TYPE nType);
XC_API BOOL  WINAPI XTemp_SetNodeAttribute(void* pNode, const wchar_t* pName, const wchar_t* pAttr);
XC_API BOOL  WINAPI XTemp_SetNodeAttributeEx(void* pNode, int itemID, const wchar_t* pName, const wchar_t* pAttr);
XC_API void* WINAPI XTemp_List_GetNode(HTEMP hTemp, int index);
XC_API void* WINAPI XTemp_GetNode(void* pNode, int itemID);
XC_API void* WINAPI XTemp_CloneNode(void* pNode);
XC_API HELE WINAPI XList_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API int WINAPI XList_AddColumn(HELE hEle, int width); //������
XC_API int WINAPI XList_InsertColumn(HELE hEle, int width, int iItem);
XC_API void WINAPI XList_EnableMultiSel(HELE hEle, BOOL bEnable);
XC_API void WINAPI XList_EnableDragChangeColumnWidth(HELE hEle, BOOL bEnable);
XC_API void WINAPI XList_EnableVScrollBarTop(HELE hEle, BOOL bTop);
XC_API void WINAPI XList_EnableItemBkFullRow(HELE hEle, BOOL bFull);
XC_API void WINAPI XList_EnableFixedRowHeight(HELE hEle, BOOL bEnable);
XC_API void WINAPI XList_EnablemTemplateReuse(HELE hEle, BOOL bEnable);
XC_API void WINAPI XList_EnableVirtualTable(HELE hEle, BOOL bEnable);
XC_API void WINAPI XList_SetVirtualRowCount(HELE hEle, int nRowCount);
XC_API void WINAPI XList_SetSort(HELE hEle, int iColumn, int iColumnAdapter, BOOL bEnable);//��������
XC_API void WINAPI XList_SetDrawItemBkFlags(HELE hEle, int style);
XC_API void WINAPI XList_SetColumnWidth(HELE hEle, int iItem, int width);
XC_API void WINAPI XList_SetColumnMinWidth(HELE hEle, int iItem, int width);
XC_API void WINAPI XList_SetColumnWidthFixed(HELE hEle, int iColumn, BOOL bFixed);
XC_API int  WINAPI XList_GetColumnWidth(HELE hEle, int iColumn);  //��ȡ�п�
XC_API int  WINAPI XList_GetColumnCount(HELE hEle);  //��ȡ������
XC_API BOOL WINAPI XList_DeleteColumn(HELE hEle, int iItem);
XC_API void WINAPI XList_DeleteColumnAll(HELE hEle);
XC_API BOOL WINAPI XList_SetItemData(HELE hEle, int iItem, int iSubItem, int data);
XC_API int  WINAPI XList_GetItemData(HELE hEle, int iItem, int iSubItem);
XC_API BOOL WINAPI XList_SetSelectItem(HELE hEle, int iItem);
XC_API int  WINAPI XList_GetSelectItem(HELE hEle);
XC_API int  WINAPI XList_GetSelectItemCount(HELE hEle);
XC_API BOOL WINAPI XList_AddSelectItem(HELE hEle, int iItem);
XC_API void WINAPI XList_SetSelectAll(HELE hEle);
XC_API int  WINAPI XList_GetSelectAll(HELE hEle, out_buffer_ int* pArray, int nArraySize);
XC_API void WINAPI XList_VisibleItem(HELE hEle, int iItem);
XC_API BOOL WINAPI XList_CancelSelectItem(HELE hEle, int iItem);
XC_API void WINAPI XList_CancelSelectAll(HELE hEle);
XC_API HELE WINAPI XList_GetHeaderHELE(HELE hEle);
XC_API void WINAPI XList_BindAdapter(HELE hEle, HXCGUI hAdapter);
XC_API void WINAPI XList_BindAdapterHeader(HELE hEle, HXCGUI hAdapter);
XC_API HXCGUI WINAPI XList_CreateAdapter(HELE hEle);
XC_API HXCGUI WINAPI XList_CreateAdapterHeader(HELE hEle);
XC_API HXCGUI WINAPI XList_GetAdapter(HELE hEle);
XC_API HXCGUI WINAPI XList_GetAdapterHeader(HELE hEle);
XC_API BOOL WINAPI XList_SetItemTemplateXML(HELE hEle, const wchar_t* pXmlFile);
XC_API BOOL WINAPI XList_SetItemTemplateXMLFromString(HELE hEle, const char* pStringXML);
XC_API BOOL WINAPI XList_SetItemTemplate(HELE hEle, HTEMP hTemp);
XC_API HXCGUI WINAPI XList_GetTemplateObject(HELE hEle, int iItem, int iSubItem, int nTempItemID); //ͨ��ģ����ID,��ȡʵ����ģ����ID��Ӧ�Ķ���.
XC_API int    WINAPI XList_GetItemIndexFromHXCGUI(HELE hEle, HXCGUI hXCGUI);
XC_API HXCGUI WINAPI XList_GetHeaderTemplateObject(HELE hEle, int iItem, int nTempItemID);
XC_API int    WINAPI XList_GetHeaderItemIndexFromHXCGUI(HELE hEle, HXCGUI hXCGUI);
XC_API void WINAPI XList_SetHeaderHeight(HELE hEle, int height);
XC_API int  WINAPI XList_GetHeaderHeight(HELE hEle);
XC_API void WINAPI XList_GetVisibleRowRange(HELE hEle, out_ int* piStart, out_ int* piEnd);

XC_API void WINAPI XList_SetItemHeightDefault(HELE hEle, int nHeight, int nSelHeight);
XC_API void WINAPI XList_GetItemHeightDefault(HELE hEle, out_ int* pHeight, out_ int* pSelHeight);
XC_API void WINAPI XList_SetRowSpace(HELE hEle, int nSpace);
XC_API int  WINAPI XList_GetRowSpace(HELE hEle);
XC_API void WINAPI XList_SetLockColumnLeft(HELE hEle, int iColumn);
XC_API void WINAPI XList_SetLockColumnRight(HELE hEle, int iColumn);
XC_API void WINAPI XList_SetLockRowBottom(HELE hEle, BOOL bLock);
XC_API void WINAPI XList_SetLockRowBottomOverlap(HELE hEle, BOOL bOverlap); //���������п��ص�
XC_API BOOL WINAPI XList_HitTest(HELE hEle, POINT* pPt, out_ int* piItem, out_ int* piSubItem);
XC_API BOOL WINAPI XList_HitTestOffset(HELE hEle, POINT* pPt, out_ int* piItem, out_ int* piSubItem);
XC_API void WINAPI XList_RefreshData(HELE hEle);
XC_API void WINAPI XList_RefreshItem(HELE hEle, int iItem);
XC_API int WINAPI XList_AddColumnText(HELE hEle, int nWidth, const wchar_t* pName, const wchar_t* pText);
XC_API int WINAPI XList_AddColumnImage(HELE hEle, int nWidth, const wchar_t* pName, HIMAGE hImage);
XC_API int WINAPI XList_AddItemText(HELE hEle, const wchar_t* pText);
XC_API int WINAPI XList_AddItemTextEx(HELE hEle, const wchar_t* pName, const wchar_t* pText);
XC_API int WINAPI XList_AddItemImage(HELE hEle, HIMAGE hImage);
XC_API int WINAPI XList_AddItemImageEx(HELE hEle, const wchar_t* pName, HIMAGE hImage);
XC_API int WINAPI XList_InsertItemText(HELE hEle, int iItem, const wchar_t* pValue);
XC_API int WINAPI XList_InsertItemTextEx(HELE hEle, int iItem, const wchar_t* pName, const wchar_t* pValue);
XC_API int WINAPI XList_InsertItemImage(HELE hEle, int iItem, HIMAGE hImage);
XC_API int WINAPI XList_InsertItemImageEx(HELE hEle, int iItem, const wchar_t* pName, HIMAGE hImage);
XC_API BOOL WINAPI XList_SetItemText(HELE hEle, int iItem, int iColumn, const wchar_t* pText);
XC_API BOOL WINAPI XList_SetItemTextEx(HELE hEle, int iItem, const wchar_t* pName, const wchar_t* pText);
XC_API BOOL WINAPI XList_SetItemImage(HELE hEle, int iItem, int iColumn, HIMAGE hImage);
XC_API BOOL WINAPI XList_SetItemImageEx(HELE hEle, int iItem, const wchar_t* pName, HIMAGE hImage);
XC_API BOOL WINAPI XList_SetItemInt(HELE hEle, int iItem, int iColumn, int nValue);
XC_API BOOL WINAPI XList_SetItemIntEx(HELE hEle, int iItem, const wchar_t* pName, int nValue);
XC_API BOOL WINAPI XList_SetItemFloat(HELE hEle, int iItem, int iColumn, float fFloat);
XC_API BOOL WINAPI XList_SetItemFloatEx(HELE hEle, int iItem, const wchar_t* pName, float fFloat);
XC_API const wchar_t* WINAPI XList_GetItemText(HELE hEle, int iItem, int iColumn);
XC_API const wchar_t* WINAPI XList_GetItemTextEx(HELE hEle, int iItem, const wchar_t* pName);
XC_API HIMAGE WINAPI XList_GetItemImage(HELE hEle, int iItem, int iColumn);
XC_API HIMAGE WINAPI XList_GetItemImageEx(HELE hEle, int iItem, const wchar_t* pName);
XC_API BOOL WINAPI XList_GetItemInt(HELE hEle, int iItem, int iColumn, out_ int* pOutValue);
XC_API BOOL WINAPI XList_GetItemIntEx(HELE hEle, int iItem, const wchar_t* pName, out_ int* pOutValue);
XC_API BOOL WINAPI XList_GetItemFloat(HELE hEle, int iItem, int iColumn, out_ float* pOutValue);
XC_API BOOL WINAPI XList_GetItemFloatEx(HELE hEle, int iItem, const wchar_t* pName, out_ float* pOutValue);
XC_API BOOL WINAPI XList_DeleteItem(HELE hEle, int iItem);
XC_API BOOL WINAPI XList_DeleteItemEx(HELE hEle, int iItem, int nCount);
XC_API void WINAPI XList_DeleteItemAll(HELE hEle);
XC_API void WINAPI XList_DeleteColumnAll_AD(HELE hEle);
XC_API int  WINAPI XList_GetCount_AD(HELE hEle);
XC_API int  WINAPI XList_GetCountColumn_AD(HELE hEle);
XC_API HELE WINAPI XListView_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API HXCGUI WINAPI XListView_CreateAdapter(HELE hEle);
XC_API void   WINAPI XListView_BindAdapter(HELE hEle, HXCGUI hAdapter);
XC_API HXCGUI WINAPI XListView_GetAdapter(HELE hEle);
XC_API BOOL WINAPI XListView_SetItemTemplateXML(HELE hEle, const wchar_t* pXmlFile);
XC_API BOOL WINAPI XListView_SetItemTemplateXMLFromString(HELE hEle, const char* pStringXML);
XC_API BOOL WINAPI XListView_SetItemTemplate(HELE hEle, HTEMP hTemp);
XC_API HXCGUI WINAPI XListView_GetTemplateObject(HELE hEle, int iGroup, int iItem, int nTempItemID);
XC_API HXCGUI WINAPI XListView_GetTemplateObjectGroup(HELE hEle, int iGroup, int nTempItemID);
XC_API BOOL  WINAPI XListView_GetItemIDFromHXCGUI(HELE hEle, HXCGUI hXCGUI, out_ int* piGroup, out_ int* piItem);
XC_API BOOL WINAPI XListView_HitTest(HELE hEle, in_ POINT* pPt, out_ int* pOutGroup, out_ int* pOutItem);
XC_API BOOL WINAPI XListView_HitTestOffset(HELE hEle, in_ POINT* pPt, out_ int* pOutGroup, out_ int* pOutItem); //�Զ���ӹ�����ͼƫ����
XC_API void WINAPI XListView_EnableMultiSel(HELE hEle, BOOL bEnable);
XC_API void WINAPI XListView_EnablemTemplateReuse(HELE hEle, BOOL bEnable);
XC_API void WINAPI XListView_EnableVirtualTable(HELE hEle, BOOL bEnable);
XC_API BOOL WINAPI XListView_SetVirtualItemCount(HELE hEle, int iGroup, int nCount);
XC_API void WINAPI XListView_SetDrawItemBkFlags(HELE hEle, int nFlags);
XC_API BOOL WINAPI XListView_SetSelectItem(HELE hEle, int iGroup, int iItem);
XC_API BOOL WINAPI XListView_GetSelectItem(HELE hEle, out_ int* piGroup, out_ int* piItem);
XC_API BOOL WINAPI XListView_AddSelectItem(HELE hEle, int iGroup, int iItem);
XC_API void WINAPI XListView_VisibleItem(HELE hEle, int iGroup, int iItem);
XC_API void WINAPI XListView_GetVisibleItemRange(HELE hEle, out_ int* piGroup1, out_ int* piGroup2, out_ int* piStartGroup, out_ int* piStartItem, out_ int* piEndGroup, out_ int* piEndItem);
XC_API int  WINAPI XListView_GetSelectItemCount(HELE hEle);
XC_API int  WINAPI XListView_GetSelectAll(HELE hEle, out_buffer_ listView_item_id_* pArray, int nArraySize);
XC_API void WINAPI XListView_SetSelectAll(HELE hEle);
XC_API void WINAPI XListView_CancelSelectAll(HELE hEle);
XC_API void WINAPI XListView_SetColumnSpace(HELE hEle, int space); //�����м��
XC_API void WINAPI XListView_SetRowSpace(HELE hEle, int space); //�����м��
XC_API void WINAPI XListView_SetItemSize(HELE hEle, int width, int height);
XC_API void WINAPI XListView_GetItemSize(HELE hEle, SIZE* pSize);
XC_API void WINAPI XListView_SetGroupHeight(HELE hEle, int height);
XC_API int  WINAPI XListView_GetGroupHeight(HELE hEle);
XC_API void WINAPI XListView_SetGroupUserData(HELE hEle, int iGroup, vint nData);
XC_API void WINAPI XListView_SetItemUserData(HELE hEle, int iGroup, int iItem, vint nData);
XC_API vint WINAPI XListView_GetGroupUserData(HELE hEle, int iGroup);
XC_API vint WINAPI XListView_GetItemUserData(HELE hEle, int iGroup, int iItem);

XC_API void WINAPI XListView_RefreshData(HELE hEle);
XC_API void WINAPI XListView_RefreshItem(HELE hEle, int iGroup, int iItem);
XC_API BOOL WINAPI XListView_ExpandGroup(HELE hEle, int iGroup, BOOL bExpand);
XC_API int  WINAPI XListView_Group_AddColumn(HELE hEle, const wchar_t* pName);
XC_API int  WINAPI XListView_Group_AddItemText(HELE hEle, const wchar_t* pValue, int iPos);
XC_API int  WINAPI XListView_Group_AddItemTextEx(HELE hEle, const wchar_t* pName, const wchar_t* pValue, int iPos);
XC_API int  WINAPI XListView_Group_AddItemImage(HELE hEle, HIMAGE hImage, int iPos);
XC_API int  WINAPI XListView_Group_AddItemImageEx(HELE hEle, const wchar_t* pName, HIMAGE hImage, int iPos);
XC_API BOOL WINAPI XListView_Group_SetText(HELE hEle, int iGroup, int iColumn, const wchar_t* pValue);
XC_API BOOL WINAPI XListView_Group_SetTextEx(HELE hEle, int iGroup, const wchar_t* pName, const wchar_t* pValue);
XC_API BOOL WINAPI XListView_Group_SetImage(HELE hEle, int iGroup, int iColumn, HIMAGE hImage);
XC_API BOOL WINAPI XListView_Group_SetImageEx(HELE hEle, int iGroup, const wchar_t* pName, HIMAGE hImage);
XC_API int  WINAPI XListView_Group_GetCount(HELE hEle);
XC_API int  WINAPI XListView_Item_GetCount(HELE hEle, int iGroup);
XC_API int  WINAPI XListView_Item_AddColumn(HELE hEle, const wchar_t* pName);  //������
XC_API int  WINAPI XListView_Item_AddItemText(HELE hEle, int iGroup, const wchar_t* pValue, int iPos);
XC_API int  WINAPI XListView_Item_AddItemTextEx(HELE hEle, int iGroup, const wchar_t* pName, const wchar_t* pValue, int iPos);
XC_API int  WINAPI XListView_Item_AddItemImage(HELE hEle, int iGroup, HIMAGE hImage, int iPos);
XC_API int  WINAPI XListView_Item_AddItemImageEx(HELE hEle, int iGroup, const wchar_t* pName, HIMAGE hImage, int iPos);
XC_API BOOL WINAPI XListView_Item_SetText(HELE hEle, int iGroup, int iItem, int iColumn, const wchar_t* pValue);
XC_API BOOL WINAPI XListView_Item_SetTextEx(HELE hEle, int iGroup, int iItem, const wchar_t* pName, const wchar_t* pValue);
XC_API BOOL WINAPI XListView_Item_SetImage(HELE hEle, int iGroup, int iItem, int iColumn, HIMAGE hImage);
XC_API BOOL WINAPI XListView_Item_SetImageEx(HELE hEle, int iGroup, int iItem, const wchar_t* pName, HIMAGE hImage);
XC_API BOOL WINAPI XListView_Group_DeleteItem(HELE hEle, int iGroup);
XC_API void WINAPI XListView_Group_DeleteAllChildItem(HELE hEle, int iGroup);
XC_API BOOL WINAPI XListView_Item_DeleteItem(HELE hEle, int iGroup, int iItem);
XC_API void WINAPI XListView_DeleteAll(HELE hEle);
XC_API void WINAPI XListView_DeleteAllGroup(HELE hEle);
XC_API void WINAPI XListView_DeleteAllItem(HELE hEle);
XC_API void WINAPI XListView_DeleteColumnGroup(HELE hEle, int iColumn);
XC_API void WINAPI XListView_DeleteColumnItem(HELE hEle, int iColumn);
XC_API const wchar_t* WINAPI XListView_Item_GetTextEx(HELE hEle, int iGroup, int iItem, const wchar_t* pName);
XC_API HIMAGE WINAPI XListView_Item_GetImageEx(HELE hEle, int iGroup, int iItem, const wchar_t* pName);
XC_API HELE WINAPI XMenuBar_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API int  WINAPI XMenuBar_AddButton(HELE hEle, const wchar_t* pText);     //���ӵ����˵���ť
XC_API void WINAPI XMenuBar_SetButtonHeight(HELE hEle, int height);
XC_API HMENUX WINAPI XMenuBar_GetMenu(HELE hEle, int nIndex);
XC_API BOOL WINAPI XMenuBar_DeleteButton(HELE hEle, int nIndex); //ɾ���˵��������,ͬʱ�ð�ť�µĵ����˵�Ҳ������
XC_API void WINAPI XMenuBar_EnableAutoWidth(HELE hEle, BOOL bEnable);
XC_API HMENUX WINAPI XMenu_Create();
XC_API void WINAPI XMenu_AddItem(HMENUX hMenu, int nID, const wchar_t* pText, int parentId = XC_ID_ROOT, int nFlags = 0); //��Ӳ˵���
XC_API void WINAPI XMenu_AddItemIcon(HMENUX hMenu, int nID, const wchar_t* pText, int nParentID, HIMAGE hImage, int nFlags = 0);
XC_API void WINAPI XMenu_InsertItem(HMENUX hMenu, int nID, const wchar_t* pText, int nFlags, int insertID);
XC_API void WINAPI XMenu_InsertItemIcon(HMENUX hMenu, int nID, const wchar_t* pText, HIMAGE hIcon, int nFlags, int insertID);
XC_API int  WINAPI XMenu_GetFirstChildItem(HMENUX hMenu, int nID);
XC_API int  WINAPI XMenu_GetEndChildItem(HMENUX hMenu, int nID);
XC_API int  WINAPI XMenu_GetPrevSiblingItem(HMENUX hMenu, int nID);
XC_API int  WINAPI XMenu_GetNextSiblingItem(HMENUX hMenu, int nID);
XC_API int  WINAPI XMenu_GetParentItem(HMENUX hMenu, int nID);
XC_API void WINAPI XMenu_SetAutoDestroy(HMENUX hMenu, BOOL bAuto); //�Ƿ��Զ����ٶ���,Ĭ�ϵ����˵��رպ��Զ�����
XC_API void WINAPI XMenu_EnableDrawBackground(HMENUX hMenu, BOOL bEnable); //�Ƿ����û����Ʋ˵�����
XC_API void WINAPI XMenu_EnableDrawItem(HMENUX hMenu, BOOL bEnable);
XC_API BOOL WINAPI XMenu_Popup(HMENUX hMenu, HWND hParentWnd, int x, int y, HELE hParentEle = NULL, menu_popup_position_ nPosition = menu_popup_position_left_top); //�����˵�
XC_API void WINAPI XMenu_DestroyMenu(HMENUX hMenu);
XC_API void WINAPI XMenu_CloseMenu(HMENUX hMenu);
XC_API void WINAPI XMenu_SetBkImage(HMENUX hMenu, HIMAGE hImage);
XC_API BOOL WINAPI XMenu_SetItemText(HMENUX hMenu, int nID, const wchar_t* pText); //�������ı�
XC_API const wchar_t* WINAPI XMenu_GetItemText(HMENUX hMenu, int nID);
XC_API int  WINAPI XMenu_GetItemTextLength(HMENUX hMenu, int nID);
XC_API BOOL WINAPI XMenu_SetItemIcon(HMENUX hMenu, int nID, HIMAGE hIcon);
XC_API BOOL WINAPI XMenu_SetItemFlags(HMENUX hMenu, int nID, int uFlags);   //����������
XC_API void WINAPI XMenu_SetItemHeight(HMENUX hMenu, int height); //���ò˵���߶�
XC_API int  WINAPI XMenu_GetItemHeight(HMENUX hMenu);
XC_API void WINAPI XMenu_SetBorderColor(HMENUX hMenu, COLORREF crColor);
XC_API void WINAPI XMenu_SetBorderSize(HMENUX hMenu, int nLeft, int nTop, int nRight, int nBottom);
XC_API int  WINAPI XMenu_GetLeftWidth(HMENUX hMenu); //��ȡ�����
XC_API int  WINAPI XMenu_GetLeftSpaceText(HMENUX hMenu);  //��ȡ�˵����ı�����
XC_API int  WINAPI XMenu_GetItemCount(HMENUX hMenu); //��ȡ�˵�������,�����Ӳ˵���
XC_API BOOL WINAPI XMenu_SetItemCheck(HMENUX hMenu, int nID, BOOL bCheck);
XC_API BOOL WINAPI XMenu_IsItemCheck(HMENUX hMenu, int nID);
XC_API HWINDOW WINAPI XModalWnd_Create(int nWidth, int nHeight, const wchar_t* pTitle, HWND hWndParent, int XCStyle = window_style_modal);
XC_API void WINAPI XModalWnd_EnableAutoClose(HWINDOW hWindow, BOOL bEnable);
XC_API void WINAPI XModalWnd_EnableEscClose(HWINDOW hWindow, BOOL bEnable);
XC_API int  WINAPI XModalWnd_DoModal(HWINDOW hWindow);     //����ģ̬����
XC_API void WINAPI XModalWnd_EndModal(HWINDOW hWindow, int nResult); //��ֹ
XC_API HELE WINAPI XPane_Create(const wchar_t* pName, int nWidth, int nHeight, HWINDOW hFrameWnd = NULL);
XC_API void WINAPI XPane_SetView(HELE hEle, HELE hView);
XC_API BOOL WINAPI XPane_IsShowPane(HELE hEle); //�жϴ����Ƿ�����
XC_API void WINAPI XPane_SetSize(HELE hEle, int nWidth, int nHeight);
XC_API pane_state_ WINAPI XPane_GetState(HELE hEle);
XC_API void WINAPI XPane_GetViewRect(HELE hEle, out_ RECT* pRect);
XC_API void WINAPI XPane_SetTitle(HELE hEle, wchar_t* pTitle);
XC_API const wchar_t* WINAPI XPane_GetTitle(HELE hEle);
XC_API void WINAPI XPane_SetCaptionHeight(HELE hEle, int nHeight);
XC_API int  WINAPI XPane_GetCaptionHeight(HELE hEle);
//XC_API void  WINAPI XPane_HidePane(HELE hEle);     //���ش���
//XC_API void  WINAPI XPane_ShowPane(HELE hEle);     //����-��ʾ����,���л�����
XC_API void  WINAPI XPane_DockPane(HELE hEle);      //ͣ������,�Զ�����
XC_API void  WINAPI XPane_LockPane(HELE hEle);      //��������
XC_API void  WINAPI XPane_FloatPane(HELE hEle);     //��������,������ͷ��
XC_API void  WINAPI XPane_DrawPane(HELE hEle, HDRAW hDraw);
XC_API BOOL  WINAPI XPane_SetSelect(HELE hEle);   //���������,ʹ��ѡ��
XC_API BOOL WINAPI XFloatWnd_EnableCaptionContent(HWINDOW hWindow, BOOL bEnable);
XC_API HXCGUI WINAPI XFloatWnd_GetCaptionLayout(HWINDOW hWindow);
XC_API HXCGUI WINAPI XFloatWnd_GetCaptionShapeText(HWINDOW hWindow);
XC_API HELE   WINAPI XFloatWnd_GetCaptionButtonClose(HWINDOW hWindow);
XC_API void  WINAPI XFloatWnd_SetTitle(HWINDOW hWindow, const wchar_t* pTitle);
XC_API const wchar_t* WINAPI XFloatWnd_GetTitle(HWINDOW hWindow);
XC_API HELE WINAPI XProgBar_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API void WINAPI XProgBar_SetRange(HELE hEle, int range);
XC_API int  WINAPI XProgBar_GetRange(HELE hEle);

XC_API void WINAPI XProgBar_SetPos(HELE hEle, int pos);
XC_API int  WINAPI XProgBar_GetPos(HELE hEle);
XC_API void WINAPI XProgBar_EnableStretch(HELE hEle, BOOL bStretch);
XC_API void WINAPI XProgBar_EnableHorizon(HELE hEle, BOOL bHorizon);
XC_API void WINAPI XProgBar_SetImageLoad(HELE hEle, HIMAGE hImage);
XC_API HELE WINAPI XPGrid_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API int  WINAPI XPGrid_AddItem(HELE hEle, const wchar_t* pName, propertyGrid_item_type_ nType, int nParentID = XC_ID_ROOT); //�����
XC_API int  WINAPI XPGrid_AddItemString(HELE hEle, const wchar_t* pName, const wchar_t* pValue, int nParentID = XC_ID_ROOT);
XC_API int  WINAPI XPGrid_AddItemEle(HELE hEle, HELE hElePanel, int nParentID = XC_ID_ROOT);
XC_API void WINAPI XPGrid_DeleteAll(HELE hEle);
XC_API HELE WINAPI XPGrid_GetItemHELE(HELE hEle, int nItemID);
XC_API void WINAPI XPGrid_SetWidth(HELE hEle, int nWidth);
XC_API BOOL WINAPI XPGrid_SetItemValue(HELE hEle, int nItemID, const wchar_t* pValue);
XC_API BOOL WINAPI XPGrid_SetItemValueInt(HELE hEle, int nItemID, int nValue);
XC_API BOOL WINAPI XPGrid_SetItemData(HELE hEle, int nItemID, vint nUserData);
XC_API vint WINAPI XPGrid_GetItemData(HELE hEle, int nItemID);
XC_API const wchar_t* WINAPI XPGrid_GetItemValue(HELE hEle, int nItemID);
XC_API int  WINAPI XPGrid_HitTest(HELE hEle, POINT* pPt, BOOL* pbExpandButton);
XC_API int  WINAPI XPGrid_HitTestOffset(HELE hEle, POINT* pPt, BOOL* pbExpandButton);
XC_API BOOL WINAPI XPGrid_ExpandItem(HELE hEle, int nItemID, BOOL bExpand);//չ����
XC_API int  WINAPI XPGrid_GetSelItem(HELE hEle);
XC_API BOOL WINAPI XPGrid_SetSelItem(HELE hEle, int nItemID);
XC_API void WINAPI XPGrid_SetDrawItemBkFlags(HELE hEle, int nFlags);
XC_API void   WINAPI XRes_EnableDelayLoad(BOOL bEnable);
XC_API void   WINAPI XRes_SetLoadFileCallback(funLoadFile pFun);
XC_API int    WINAPI XRes_GetIDValue(const wchar_t* pName);  //��ȡ��ԴIDֵ
XC_API HIMAGE WINAPI XRes_GetImage(const wchar_t* pName);  //��ȡ��ԴͼƬ
XC_API HIMAGE WINAPI XRes_GetImageEx(const wchar_t* pFileName, const wchar_t* pName); //��ȡ��ԴͼƬ
XC_API COLORREF WINAPI XRes_GetColor(const wchar_t* pName);  //��ȡ��Դ��ɫ
XC_API HFONTX   WINAPI XRes_GetFont(const wchar_t* pName);  //��ȡ��Դ����
XC_API HBKM     WINAPI XRes_GetBkM(const wchar_t* pName);  //��ȡ��Դ������Ϣ
XC_API HELE WINAPI XEditColor_Create(int x, int y, int cx, int cy, HXCGUI hParent);
XC_API void WINAPI XEditColor_SetColor(HELE hEle, COLORREF color);//������ɫ
XC_API COLORREF WINAPI XEditColor_GetColor(HELE hEle); //��ȡ��ɫRGBֵ
XC_API HELE WINAPI XEditSet_Create(int x, int y, int cx, int cy, HXCGUI hParent);
XC_API HELE WINAPI XEditFile_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API void WINAPI XEditFile_SetOpenFileType(HELE hEle, const wchar_t* pType); //���ô��ļ�����
XC_API void WINAPI XEditFile_SetDefaultFile(HELE hEle, const wchar_t* pFile); //����Ĭ��Ŀ¼�ļ�
XC_API void WINAPI XEditFile_SetRelativeDir(HELE hEle, const wchar_t* pDir); //TODO:�������·��
XC_API HELE WINAPI XEditFolder_Create(int x, int y, int cx, int cy, HXCGUI hParent);
XC_API void WINAPI XEditFolder_SetDefaultDir(HELE hEle, const wchar_t* pDir);  //����Ĭ��Ŀ¼
XC_API HELE WINAPI XSBar_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API void WINAPI XSBar_SetRange(HELE hEle, int range);
XC_API int  WINAPI XSBar_GetRange(HELE hEle);
XC_API void  WINAPI XSBar_ShowButton(HELE hEle, BOOL bShow);
XC_API void WINAPI XSBar_SetSliderLength(HELE hEle, int length); //���û��鳤��
XC_API void WINAPI XSBar_SetSliderMinLength(HELE hEle, int minLength); //���û�����С����
XC_API void WINAPI XSBar_SetSliderPadding(HELE hEle, int nPadding);
XC_API BOOL WINAPI XSBar_EnableHorizon(HELE hEle, BOOL bHorizon);  //ˮƽ��ʾ��ֱ
XC_API int  WINAPI XSBar_GetSliderMaxLength(HELE hEle);
XC_API BOOL WINAPI XSBar_ScrollUp(HELE hEle);       //�������
XC_API BOOL WINAPI XSBar_ScrollDown(HELE hEle);     //���ҹ���
XC_API BOOL WINAPI XSBar_ScrollTop(HELE hEle);      //����������
XC_API BOOL WINAPI XSBar_ScrollBottom(HELE hEle);   //�������ײ�
XC_API BOOL WINAPI XSBar_ScrollPos(HELE hEle, int pos); //������ָ����
XC_API HELE WINAPI XSBar_GetButtonUp(HELE hEle);
XC_API HELE WINAPI XSBar_GetButtonDown(HELE hEle);
XC_API HELE WINAPI XSBar_GetButtonSlider(HELE hEle);
XC_API HELE WINAPI XSView_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API BOOL WINAPI XSView_SetTotalSize(HELE hEle, int cx, int cy); //������ͼ�����ܴ�С(�������߿���)
XC_API void WINAPI XSView_GetTotalSize(HELE hEle, out_ SIZE* pSize);  //��ȡ���õ����ݴ�С
XC_API BOOL WINAPI XSView_SetLineSize(HELE hEle, int nWidth, int nHeight);
XC_API void WINAPI XSView_GetLineSize(HELE hEle, out_ SIZE* pSize);
XC_API void WINAPI XSView_SetScrollBarSize(HELE hEle, int size); //���ù�������С
XC_API int  WINAPI XSView_GetViewPosH(HELE hEle);   //��ȡ�ӿ�ԭ��X����
XC_API int  WINAPI XSView_GetViewPosV(HELE hEle);   //��ȡ�ӿ�ԭ��Y����
XC_API int  WINAPI XSView_GetViewWidth(HELE hEle);
XC_API int  WINAPI XSView_GetViewHeight(HELE hEle);
XC_API void WINAPI XSView_GetViewRect(HELE hEle, out_ RECT* pRect); //��ȡ�ӿ�����(�����߿���),leftΪ�ӿ�������С,topΪ�ӿ��ϼ����С,��(0,0).
XC_API HELE WINAPI XSView_GetScrollBarH(HELE hEle); //��ȡˮƽ������
XC_API HELE WINAPI XSView_GetScrollBarV(HELE hEle); //��ȡ��ֱ������

XC_API BOOL WINAPI XSView_ScrollPosH(HELE hEle, int pos); //������ָ����
XC_API BOOL WINAPI XSView_ScrollPosV(HELE hEle, int pos); //������ָ����
XC_API BOOL WINAPI XSView_ScrollPosXH(HELE hEle, int posX); //������ָ������
XC_API BOOL WINAPI XSView_ScrollPosYV(HELE hEle, int posY); //������ָ������
XC_API void WINAPI XSView_ShowSBarH(HELE hEle, BOOL bShow); //����ˮƽ������
XC_API void WINAPI XSView_ShowSBarV(HELE hEle, BOOL bShow); //���ô�ֱ������
XC_API void WINAPI XSView_EnableAutoShowScrollBar(HELE hEle, BOOL bEnable);
XC_API BOOL WINAPI XSView_ScrollLeftLine(HELE hEle);    //�������
XC_API BOOL WINAPI XSView_ScrollRightLine(HELE hEle);   //���ҹ���
XC_API BOOL WINAPI XSView_ScrollTopLine(HELE hEle);     //���Ϲ���
XC_API BOOL WINAPI XSView_ScrollBottomLine(HELE hEle);    //���¹���
XC_API BOOL WINAPI XSView_ScrollLeft(HELE hEle);    //ˮƽ���������
XC_API BOOL WINAPI XSView_ScrollRight(HELE hEle);   //ˮƽ�������Ҳ�
XC_API BOOL WINAPI XSView_ScrollTop(HELE hEle);     //����������
XC_API BOOL WINAPI XSView_ScrollBottom(HELE hEle);  //�������ײ�

XC_API void  WINAPI XShape_RemoveShape(HXCGUI hShape);

XC_API int  WINAPI XShape_GetZOrder(HXCGUI hShape);
XC_API void WINAPI XShape_Redraw(HXCGUI hShape);
XC_API int  WINAPI XShape_GetWidth(HXCGUI hShape);
XC_API int  WINAPI XShape_GetHeight(HXCGUI hShape);
XC_API void WINAPI XShape_GetRect(HXCGUI hShape, out_ RECT* pRect);
XC_API void WINAPI XShape_SetRect(HXCGUI hShape, in_  RECT* pRect);
XC_API BOOL WINAPI XShape_SetRectLogic(HXCGUI hShape, RECT* pRect, BOOL bRedraw);
XC_API void WINAPI XShape_GetRectLogic(HXCGUI hShape, out_ RECT* pRect);
XC_API void WINAPI XShape_GetWndClientRect(HXCGUI hShape, out_ RECT* pRect);
XC_API void WINAPI XShape_GetContentSize(HXCGUI hShape, out_ SIZE* pSize);//��ȡ���ݴ�С
XC_API void WINAPI XShape_ShowLayout(HXCGUI hShape, BOOL bShow);
XC_API void WINAPI XShape_AdjustLayout(HXCGUI hShape);
XC_API void WINAPI XShape_Destroy(HXCGUI hShape);
XC_API HXCGUI WINAPI XShapeText_Create(int x, int y, int cx, int cy, const wchar_t* pName, HXCGUI hParent = NULL);
XC_API void  WINAPI XShapeText_SetText(HXCGUI hTextBlock, const wchar_t* pName);
XC_API const wchar_t* WINAPI XShapeText_GetText(HXCGUI hTextBlock);
XC_API int   WINAPI XShapeText_GetTextLength(HXCGUI hTextBlock);
XC_API void  WINAPI XShapeText_SetFont(HXCGUI hTextBlock, HFONTX hFontx);
XC_API HFONTX WINAPI XShapeText_GetFont(HXCGUI hTextBlock);
XC_API void WINAPI XShapeText_SetTextColor(HXCGUI hTextBlock, COLORREF color);
XC_API COLORREF WINAPI XShapeText_GetTextColor(HXCGUI hTextBlock);
XC_API void WINAPI XShapeText_SetTextAlign(HXCGUI hTextBlock, int align);
XC_API void WINAPI XShapeText_SetOffset(HXCGUI hTextBlock, int x, int y);
XC_API HXCGUI WINAPI XShapePic_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API void   WINAPI XShapePic_SetImage(HXCGUI hShape, HIMAGE hImage);
XC_API HIMAGE WINAPI XShapePic_GetImage(HXCGUI hShape);
XC_API HXCGUI WINAPI XShapeGif_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API void   WINAPI XShapeGif_SetImage(HXCGUI hShape, HIMAGE hImage);
XC_API HIMAGE WINAPI XShapeGif_GetImage(HXCGUI hShape);
XC_API HXCGUI WINAPI XShapeRect_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API void WINAPI XShapeRect_SetBorderColor(HXCGUI hShape, COLORREF color);
XC_API void WINAPI XShapeRect_SetFillColor(HXCGUI hShape, COLORREF color);
XC_API void WINAPI XShapeRect_SetRoundAngle(HXCGUI hShape, int nWidth, int nHeight);
XC_API void WINAPI XShapeRect_GetRoundAngle(HXCGUI hShape, out_ int* pWidth, out_ int* pHeight);
XC_API void WINAPI XShapeRect_EnableBorder(HXCGUI hShape, BOOL bEnable);
XC_API void WINAPI XShapeRect_EnableFill(HXCGUI hShape, BOOL bEnable);
XC_API void WINAPI XShapeRect_EnableRoundAngle(HXCGUI hShape, BOOL bEnable);
XC_API HXCGUI WINAPI XShapeEllipse_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API void WINAPI XShapeEllipse_SetBorderColor(HXCGUI hShape, COLORREF color);
XC_API void WINAPI XShapeEllipse_SetFillColor(HXCGUI hShape, COLORREF color);
XC_API void WINAPI XShapeEllipse_EnableBorder(HXCGUI hShape, BOOL bEnable);
XC_API void WINAPI XShapeEllipse_EnableFill(HXCGUI hShape, BOOL bEnable);
XC_API HXCGUI WINAPI XShapeGroupBox_Create(int x, int y, int cx, int cy, const wchar_t* pName, HXCGUI hParent = NULL);
XC_API void WINAPI XShapeGroupBox_SetBorderColor(HXCGUI hShape, COLORREF color);
XC_API void WINAPI XShapeGroupBox_SetTextColor(HXCGUI hShape, COLORREF color);
XC_API void WINAPI XShapeGroupBox_SetFontX(HXCGUI hShape, HFONTX hFontX);
XC_API void WINAPI XShapeGroupBox_SetTextOffset(HXCGUI hShape, int offsetX, int offsetY);
XC_API void WINAPI XShapeGroupBox_SetRoundAngle(HXCGUI hShape, int nWidth, int nHeight);
XC_API void WINAPI XShapeGroupBox_SetText(HXCGUI hShape, const wchar_t* pText);
XC_API void WINAPI XShapeGroupBox_GetTextOffset(HXCGUI hShape, out_ int* pOffsetX, out_ int* pOffsetY);
XC_API void WINAPI XShapeGroupBox_GetRoundAngle(HXCGUI hShape, out_ int* pWidth, out_ int* pHeight);
XC_API void WINAPI XShapeGroupBox_EnableRoundAngle(HXCGUI hShape, BOOL bEnable);
XC_API HXCGUI WINAPI XShapeLine_Create(int x1, int y1, int x2, int y2, HXCGUI hParent = NULL);
XC_API void WINAPI XShapeLine_SetPosition(HXCGUI hShape, int x1, int y1, int x2, int y2);
XC_API void WINAPI XShapeLine_SetColor(HXCGUI hShape, COLORREF color);
XC_API HELE WINAPI XSliderBar_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API void WINAPI XSliderBar_SetRange(HELE hEle, int range);
XC_API int  WINAPI XSliderBar_GetRange(HELE hEle);
XC_API void WINAPI XSliderBar_SetButtonWidth(HELE hEle, int width);
XC_API void WINAPI XSliderBar_SetButtonHeight(HELE hEle, int height);

XC_API void WINAPI XSliderBar_SetPos(HELE hEle, int pos);
XC_API int  WINAPI XSliderBar_GetPos(HELE hEle);
XC_API HELE WINAPI XSliderBar_GetButton(HELE hEle);
XC_API void WINAPI XSliderBar_EnableHorizon(HELE hEle, BOOL bHorizon);
XC_API void WINAPI XSliderBar_SetImageLoad(HELE hEle, HIMAGE hImage);
XC_API const char* WINAPI XC_itoa(int nValue);
XC_API const wchar_t* WINAPI XC_itow(int nValue);
XC_API const wchar_t* WINAPI XC_i64tow(__int64 nValue);
XC_API const char* WINAPI XC_ftoa(float fValue);
XC_API const wchar_t* WINAPI XC_ftow(float fValue);
XC_API const wchar_t* WINAPI XC_fftow(double fValue);
XC_API const wchar_t* WINAPI XC_atow(const char* pValue);
XC_API const char* WINAPI XC_wtoa(const wchar_t* pValue);
XC_API const wchar_t* WINAPI XC_utf8tow(const char* pUtf8);
XC_API const wchar_t* WINAPI XC_utf8towEx(const char* pUtf8, int length);
XC_API const char* WINAPI XC_utf8toa(const char* pUtf8);
XC_API const char* WINAPI XC_atoutf8(const char* pValue);
XC_API const char* WINAPI XC_wtoutf8(const wchar_t* pValue);
XC_API const char* WINAPI XC_wtoutf8Ex(const wchar_t* pValue, int length);
XC_API HELE WINAPI XTabBar_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API int  WINAPI XTabBar_AddLabel(HELE hEle, const wchar_t* pName); //���һ����ǩ
XC_API int  WINAPI XTabBar_InsertLabel(HELE hEle, int index, const wchar_t* pName);
XC_API BOOL WINAPI XTabBar_MoveLabel(HELE hEle, int iSrc, int iDest);
XC_API BOOL WINAPI XTabBar_DeleteLabel(HELE hEle, int index);  //ɾ��
XC_API void WINAPI XTabBar_DeleteLabelAll(HELE hEle);  //ɾ������TAB
XC_API HELE WINAPI XTabBar_GetLabel(HELE hEle, int index);//��ȡ��ǩ��ťButton
XC_API HELE WINAPI XTabBar_GetLabelClose(HELE hEle, int index);
XC_API HELE WINAPI XTabBar_GetButtonLeft(HELE hEle);
XC_API HELE WINAPI XTabBar_GetButtonRight(HELE hEle);
XC_API HELE WINAPI XTabBar_GetButtonDropMenu(HELE hEle);
XC_API int  WINAPI XTabBar_GetSelect(HELE hEle);  //��ȡѡ��ı�ǩ
XC_API int  WINAPI XTabBar_GetLabelSpacing(HELE hEle); //��ȡ��ǩ���, 0û�м��
XC_API int  WINAPI XTabBar_GetLabelCount(HELE hEle); //��ȡ��ǩ������
XC_API int  WINAPI XTabBar_GetindexByEle(HELE hEle, HELE hLabel);
XC_API void WINAPI XTabBar_SetLabelSpacing(HELE hEle, int spacing);//���ñ�ǩ���, 0û�м��
XC_API void WINAPI XTabBar_SetPadding(HELE hEle, int left, int top, int right, int bottom);
XC_API void WINAPI XTabBar_SetSelect(HELE hEle, int index);   //����ѡ���ǩ
XC_API void WINAPI XTabBar_SetUp(HELE hEle);    //�����
XC_API void WINAPI XTabBar_SetDown(HELE hEle);  //�ҹ���
XC_API void WINAPI XTabBar_EnableTile(HELE hEle, BOOL bTile);  //ƽ�̱�ǩ,ÿ����ǩ��ʾ��ͬ��С
XC_API void WINAPI XTabBar_EnableDropMenu(HELE hEle, BOOL bEnable);
XC_API void WINAPI XTabBar_EnableClose(HELE hEle, BOOL bEnable);
XC_API void WINAPI XTabBar_SetCloseSize(HELE hEle, SIZE* pSize);
XC_API void WINAPI XTabBar_SetTurnButtonSize(HELE hEle, SIZE* pSize);
XC_API void WINAPI XTabBar_SetLabelWidth(HELE hEle, int index, int nWidth);
XC_API BOOL WINAPI XTabBar_ShowLabel(HELE hEle, int index, BOOL bShow); //��ʾ������ָ����
XC_API HXCGUI WINAPI XTable_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API void WINAPI XTable_Reset(HXCGUI hShape, int nRow, int nCol);
XC_API void WINAPI XTable_ComboRow(HXCGUI hShape, int iRow, int iCol, int count);
XC_API void WINAPI XTable_ComboCol(HXCGUI hShape, int iRow, int iCol, int count);
XC_API void WINAPI XTable_SetColWidth(HXCGUI hShape, int iCol, int width);
XC_API void WINAPI XTable_SetRowHeight(HXCGUI hShape, int iRow, int height);
XC_API void WINAPI XTable_SetBorderColor(HXCGUI hShape, COLORREF color);
XC_API void WINAPI XTable_SetTextColor(HXCGUI hShape, COLORREF color);
XC_API void WINAPI XTable_SetFont(HXCGUI hShape, HFONTX hFont);
XC_API void WINAPI XTable_SetItemPadding(HXCGUI hShape, int leftSize, int topSize, int rightSize, int bottomSize);
XC_API void WINAPI XTable_SetItemText(HXCGUI hShape, int iRow, int iCol, const wchar_t* pText);
XC_API void WINAPI XTable_SetItemFont(HXCGUI hShape, int iRow, int iCol, HFONTX hFont);
XC_API void WINAPI XTable_SetItemTextAlign(HXCGUI hShape, int iRow, int iCol, int nAlign);
XC_API void WINAPI XTable_SetItemTextColor(HXCGUI hShape, int iRow, int iCol, COLORREF color, BOOL bColor);
XC_API void WINAPI XTable_SetItemBkColor(HXCGUI hShape, int iRow, int iCol, COLORREF color, BOOL bColor);
XC_API void WINAPI XTable_SetItemLine(HXCGUI hShape, int iRow1, int iCol1, int iRow2, int iCol2, int nFlag, COLORREF color);
XC_API void WINAPI XTable_SetItemFlag(HXCGUI hShape, int iRow, int iCol, int flag);
XC_API BOOL WINAPI XTable_GetItemRect(HXCGUI hShape, int iRow, int iCol, out_ RECT* pRect);
XC_API HELE WINAPI XTextLink_Create(int x, int y, int cx, int cy, const wchar_t* pName, HXCGUI hParent = NULL);
XC_API void WINAPI XTextLink_EnableUnderlineLeave(HELE hEle, BOOL bEnable);
XC_API void WINAPI XTextLink_EnableUnderlineStay(HELE hEle, BOOL bEnable);
XC_API void WINAPI XTextLink_SetTextColorStay(HELE hEle, COLORREF color);
XC_API void WINAPI XTextLink_SetUnderlineColorLeave(HELE hEle, COLORREF color);
XC_API void WINAPI XTextLink_SetUnderlineColorStay(HELE hEle, COLORREF color);
XC_API HELE WINAPI XToolBar_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API int WINAPI XToolBar_InsertEle(HELE hEle, HELE hNewEle, int index = -1); //���Ԫ�ص�������, -1���뵽ĩβ
XC_API int WINAPI XToolBar_InsertSeparator(HELE hEle, int index = -1, COLORREF color = RGB(128, 128, 128)); //��ӷָ���, -1���뵽ĩβ
XC_API void WINAPI XToolBar_EnableButtonMenu(HELE hEle, BOOL bEnable);  //��ʾ������˵���ť
XC_API HELE WINAPI XToolBar_GetEle(HELE hEle, int index);  //��ȡ��������Ԫ�ؾ��
XC_API HELE WINAPI XToolBar_GetButtonLeft(HELE hEle);   //��ȡ�������������ťButton
XC_API HELE WINAPI XToolBar_GetButtonRight(HELE hEle);  //��ȡ�������ҹ�����ťButton
XC_API HELE WINAPI XToolBar_GetButtonMenu(HELE hEle);   //��ȡ�����˵���ť
XC_API void WINAPI XToolBar_SetSpace(HELE hEle, int nSize);
XC_API void WINAPI XToolBar_DeleteEle(HELE hEle, int index); //�Ƴ���������Ԫ�ز�����
XC_API void WINAPI XToolBar_DeleteAllEle(HELE hEle);
XC_API HELE WINAPI XTree_Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL);
XC_API void WINAPI XTree_EnableDragItem(HELE hEle, BOOL bEnable);
XC_API void WINAPI XTree_EnableConnectLine(HELE hEle, BOOL bEnable, BOOL bSolid);
XC_API void WINAPI XTree_EnableExpand(HELE hEle, BOOL bEnable);
XC_API void WINAPI XTree_EnablemTemplateReuse(HELE hEle, BOOL bEnable);
XC_API void WINAPI XTree_SetConnectLineColor(HELE hEle, COLORREF color);
XC_API void WINAPI XTree_SetExpandButtonSize(HELE hEle, int nWidth, int nHeight);
XC_API void WINAPI XTree_SetConnectLineLength(HELE hEle, int nLength);
XC_API void WINAPI XTree_SetDragInsertPositionColor(HELE hEle, COLORREF color);
XC_API BOOL WINAPI XTree_SetItemTemplateXML(HELE hEle, const wchar_t* pXmlFile);
XC_API BOOL WINAPI XTree_SetItemTemplateXMLSel(HELE hEle, const wchar_t* pXmlFile);
XC_API BOOL WINAPI XTree_SetItemTemplate(HELE hEle, HTEMP hTemp);
XC_API BOOL WINAPI XTree_SetItemTemplateSel(HELE hEle, HTEMP hTemp);
XC_API BOOL WINAPI XTree_SetItemTemplateXMLFromString(HELE hEle, const char* pStringXML);
XC_API BOOL WINAPI XTree_SetItemTemplateXMLSelFromString(HELE hEle, const char* pStringXML);
XC_API void WINAPI XTree_SetDrawItemBkFlags(HELE hEle, int nFlags);
XC_API BOOL WINAPI XTree_SetItemData(HELE hEle, int nID, vint nUserData);
XC_API vint WINAPI XTree_GetItemData(HELE hEle, int nID);
XC_API BOOL WINAPI XTree_SetSelectItem(HELE hEle, int nID);
XC_API int  WINAPI XTree_GetSelectItem(HELE hEle);
XC_API void WINAPI XTree_VisibleItem(HELE hEle, int nID);
XC_API BOOL WINAPI XTree_IsExpand(HELE hEle, int nID);
XC_API BOOL WINAPI XTree_ExpandItem(HELE hEle, int nID, BOOL bExpand);
XC_API BOOL WINAPI XTree_ExpandAllChildItem(HELE hEle, int nID, BOOL bExpand);
XC_API int  WINAPI XTree_HitTest(HELE hEle, POINT* pPt);
XC_API int  WINAPI XTree_HitTestOffset(HELE hEle, POINT* pPt);
XC_API int  WINAPI XTree_GetFirstChildItem(HELE hEle, int nID);
XC_API int  WINAPI XTree_GetEndChildItem(HELE hEle, int nID);
XC_API int  WINAPI XTree_GetPrevSiblingItem(HELE hEle, int nID);
XC_API int  WINAPI XTree_GetNextSiblingItem(HELE hEle, int nID);
XC_API int  WINAPI XTree_GetParentItem(HELE hEle, int nID);
XC_API void WINAPI XTree_SetIndentation(HELE hEle, int nWidth);
XC_API int  WINAPI XTree_GetIndentation(HELE hEle);
XC_API void WINAPI XTree_SetItemHeight(HELE hEle, int nID, int nHeight, int nSelHeight);
XC_API void WINAPI XTree_GetItemHeight(HELE hEle, int nID, out_ int* pHeight, out_ int* pSelHeight);
XC_API void WINAPI XTree_SetRowSpace(HELE hEle, int nSpace);
XC_API int  WINAPI XTree_GetRowSpace(HELE hEle);
XC_API BOOL WINAPI XTree_MoveItem(HELE hEle, int nMoveItem, int nDestItem, int nFlag);

XC_API void WINAPI XTree_SetItemHeightDefault(HELE hEle, int nHeight, int nSelHeight);
XC_API void WINAPI XTree_GetItemHeightDefault(HELE hEle, out_ int* pHeight, out_ int* pSelHeight);
XC_API HXCGUI WINAPI XTree_GetTemplateObject(HELE hEle, int nID, int nTempItemID); //ͨ��ģ����ID,��ȡʵ����ģ����ID��Ӧ�Ķ���.
XC_API int    WINAPI XTree_GetItemIDFromHXCGUI(HELE hEle, HXCGUI hXCGUI);
XC_API HXCGUI WINAPI XTree_CreateAdapter(HELE hEle);
XC_API void WINAPI XTree_BindAdapter(HELE hEle, HXCGUI hAdapter);
XC_API HXCGUI WINAPI XTree_GetAdapter(HELE hEle);
XC_API void WINAPI XTree_RefreshData(HELE hEle);
XC_API void WINAPI XTree_RefreshItem(HELE hEle, int nID);
XC_API int WINAPI XTree_InsertItemText(HELE hEle, const wchar_t* pValue, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST);
XC_API int WINAPI XTree_InsertItemTextEx(HELE hEle, const wchar_t* pName, const wchar_t* pValue, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST);
XC_API int WINAPI XTree_InsertItemImage(HELE hEle, HIMAGE hImage, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST);
XC_API int WINAPI XTree_InsertItemImageEx(HELE hEle, const wchar_t* pName, HIMAGE hImage, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST);
XC_API int WINAPI XTree_GetCount(HELE hEle);
XC_API int WINAPI XTree_GetCountColumn(HELE hEle);
XC_API BOOL WINAPI XTree_SetItemText(HELE hEle, int nID, int iColumn, const wchar_t* pValue);
XC_API BOOL WINAPI XTree_SetItemTextEx(HELE hEle, int nID, const wchar_t* pName, const wchar_t* pValue);
XC_API BOOL WINAPI XTree_SetItemImage(HELE hEle, int nID, int iColumn, HIMAGE hImage);
XC_API BOOL WINAPI XTree_SetItemImageEx(HELE hEle, int nID, const wchar_t* pName, HIMAGE hImage);
XC_API const wchar_t* WINAPI XTree_GetItemText(HELE hEle, int nID, int iColumn);
XC_API const wchar_t* WINAPI XTree_GetItemTextEx(HELE hEle, int nID, const wchar_t* pName);
XC_API HIMAGE WINAPI XTree_GetItemImage(HELE hEle, int nID, int iColumn);
XC_API HIMAGE WINAPI XTree_GetItemImageEx(HELE hEle, int nID, const wchar_t* pName);
XC_API BOOL WINAPI XTree_DeleteItem(HELE hEle, int nID);
XC_API void WINAPI XTree_DeleteItemAll(HELE hEle);
XC_API void WINAPI XTree_DeleteColumnAll(HELE hEle);
XC_API BOOL WINAPI _XWnd_RegEvent(HWINDOW hWindow, UINT nEvent, xc_event* pEvent);
XC_API BOOL WINAPI _XWnd_RemoveEvent(HWINDOW hWindow, UINT nEvent, xc_event* pEvent);
XC_API BOOL WINAPI XWnd_RegEventC(HWINDOW hWindow, int nEvent, void* pFun);
XC_API BOOL WINAPI XWnd_RegEventC1(HWINDOW hWindow, int nEvent, void* pFun);
XC_API BOOL WINAPI XWnd_RemoveEventC(HWINDOW hWindow, int nEvent, void* pFun);
XC_API HWINDOW WINAPI XWnd_Create(int x, int y, int cx, int cy, const wchar_t* pTitle, HWND hWndParent = NULL, int XCStyle = window_style_default);
XC_API BOOL WINAPI XWnd_AddChild(HWINDOW hWindow, HXCGUI hChild);
XC_API BOOL WINAPI XWnd_InsertChild(HWINDOW hWindow, HXCGUI hChild, int index);
XC_API HWND WINAPI XWnd_GetHWND(HWINDOW hWindow);
XC_API void WINAPI XWnd_EnableDragBorder(HWINDOW hWindow, BOOL bEnable);
XC_API void WINAPI XWnd_EnableDragWindow(HWINDOW hWindow, BOOL bEnable);
XC_API void WINAPI XWnd_EnableDragCaption(HWINDOW hWindow, BOOL bEnable);
XC_API void WINAPI XWnd_EnableDrawBk(HWINDOW hWindow, BOOL bEnable);
XC_API void WINAPI XWnd_EnableAutoFocus(HWINDOW hWindow, BOOL bEnable); //�������������Ƿ��ý���
XC_API void WINAPI XWnd_EnableMaxWindow(HWINDOW hWindow, BOOL bEnable);
XC_API void WINAPI XWnd_EnablemLimitWindowSize(HWINDOW hWindow, BOOL bEnable);
XC_API void WINAPI XWnd_EnableLayout(HWINDOW hWindow, BOOL bEnable);
XC_API void WINAPI XWnd_EnableLayoutOverlayBorder(HWINDOW hWindow, BOOL bEnable);
XC_API void WINAPI XWnd_ShowLayoutFrame(HWINDOW hWindow, BOOL bEnable);
XC_API BOOL WINAPI XWnd_IsEnableLayout(HWINDOW hWindow);
XC_API BOOL WINAPI XWnd_IsMaxWindow(HWINDOW hWindow);
XC_API void WINAPI XWnd_Redraw(HWINDOW hWindow, BOOL bImmediate = FALSE);
XC_API void WINAPI XWnd_RedrawRect(HWINDOW hWindow, RECT* pRect, BOOL bImmediate = FALSE); //�ػ洰��ָ������
XC_API void WINAPI XWnd_SetFocusEle(HWINDOW hWindow, HELE hFocusEle);
XC_API HELE WINAPI XWnd_GetFocusEle(HWINDOW hWindow);
XC_API HELE WINAPI XWnd_GetStayEle(HWINDOW hWindow);  //��ȡ��ǰ�����ͣ��Ԫ��
XC_API void WINAPI XWnd_DrawWindow(HWINDOW hWindow, HDRAW hDraw);
XC_API void WINAPI XWnd_Center(HWINDOW hWindow);
XC_API void WINAPI XWnd_CenterEx(HWINDOW hWindow, int width, int height);
XC_API void WINAPI XWnd_SetCursor(HWINDOW hWindow, HCURSOR hCursor);
XC_API HCURSOR WINAPI XWnd_GetCursor(HWINDOW hWindow);
XC_API HCURSOR WINAPI XWnd_SetCursorSys(HWINDOW hWindow, HCURSOR hCursor);
XC_API void WINAPI XWnd_SetFont(HWINDOW hWindow, HFONTX hFontx);
XC_API void WINAPI XWnd_SetTextColor(HWINDOW hWindow, COLORREF color);
XC_API COLORREF WINAPI XWnd_GetTextColor(HWINDOW hWindow);
XC_API COLORREF WINAPI XWnd_GetTextColorEx(HWINDOW hWindow);
XC_API void WINAPI XWnd_SetID(HWINDOW hWindow, int nID);
XC_API int  WINAPI XWnd_GetID(HWINDOW hWindow);
XC_API void  WINAPI XWnd_SetName(HWINDOW hWindow, const wchar_t* pName);
XC_API const wchar_t* WINAPI XWnd_GetName(HWINDOW hWindow);
XC_API void WINAPI XWnd_SetCaptureEle(HWINDOW hWindow, HELE hEle);
XC_API HELE WINAPI XWnd_GetCaptureEle(HWINDOW hWindow);
XC_API void WINAPI XWnd_SetBorderSize(HWINDOW hWindow, int left, int top, int right, int bottom);
XC_API void WINAPI XWnd_GetBorderSize(HWINDOW hWindow, out_ borderSize_* pBorder);
XC_API void WINAPI XWnd_SetPadding(HWINDOW hWindow, int left, int top, int right, int bottom);
XC_API void WINAPI XWnd_GetPadding(HWINDOW hWindow, out_ paddingSize_* pPadding);
XC_API void WINAPI XWnd_SetDragBorderSize(HWINDOW hWindow, int left, int top, int right, int bottom); //�����϶��߿��С
XC_API void WINAPI XWnd_GetDragBorderSize(HWINDOW hWindow, out_ borderSize_* pSize);
XC_API void WINAPI XWnd_SetMinimumSize(HWINDOW hWindow, int width, int height);
XC_API HELE WINAPI XWnd_HitChildEle(HWINDOW hWindow, POINT* pPt);
XC_API int  WINAPI XWnd_GetChildCount(HWINDOW hWindow);
XC_API HXCGUI WINAPI XWnd_GetChildByIndex(HWINDOW hWindow, int index);
XC_API HXCGUI WINAPI XWnd_GetChildByID(HWINDOW hWindow, int nID);
XC_API HXCGUI WINAPI XWnd_GetChild(HWINDOW hWindow, int nID);
XC_API void WINAPI XWnd_GetDrawRect(HWINDOW hWindow, RECT* pRcPaint);
XC_API BOOL WINAPI XWnd_ShowWindow(HWINDOW hWindow, int nCmdShow);
XC_API void WINAPI XWnd_AdjustLayout(HWINDOW hWindow);
XC_API void WINAPI XWnd_AdjustLayoutEx(HWINDOW hWindow, int nFlags = adjustLayout_self);
XC_API void WINAPI XWnd_CloseWindow(HWINDOW hWindow);
XC_API void WINAPI XWnd_CreateCaret(HWINDOW hWindow, HELE hEle, int x, int y, int width, int height);//���������

XC_API HELE WINAPI XWnd_GetCaretHELE(HWINDOW hWindow);
XC_API void WINAPI XWnd_SetCaretColor(HWINDOW hWindow, COLORREF color); //���ò������ɫ
XC_API void WINAPI XWnd_ShowCaret(HWINDOW hWindow, BOOL bShow);  //��ʾ�����
XC_API void WINAPI XWnd_DestroyCaret(HWINDOW hWindow);    //���ٲ����

XC_API void WINAPI XWnd_SetCaretPos(HWINDOW hWindow, int x, int y, int width, int height, BOOL bUpdate = FALSE);
XC_API HELE WINAPI XWnd_GetCaretInfo(HWINDOW hWindow, int* pX, int* pY, int* pWidth, int* pHeight);

XC_API BOOL WINAPI XWnd_GetClientRect(HWINDOW hWindow, out_ RECT* pRect); //��ȡ�ͻ�������
XC_API void WINAPI XWnd_GetBodyRect(HWINDOW hWindow, out_ RECT* pRect);  //��ȡ����body����
XC_API void WINAPI XWnd_GetLayoutRect(HWINDOW hWindow, out_ RECT* pRect);
XC_API void WINAPI XWnd_GetRect(HWINDOW hWindow, out_ RECT* pRect);
XC_API void WINAPI XWnd_SetRect(HWINDOW hWindow, RECT* pRect);
XC_API void WINAPI XWnd_SetTop(HWINDOW hWindow);
XC_API void WINAPI XWnd_MaxWindow(HWINDOW hWindow, BOOL bMaximize);
XC_API UINT WINAPI XWnd_SetTimer(HWINDOW hWindow, UINT nIDEvent, UINT uElapse); //���ö�ʱ��
XC_API BOOL WINAPI XWnd_KillTimer(HWINDOW hWindow, UINT nIDEvent);
XC_API BOOL WINAPI XWnd_SetXCTimer(HWINDOW hWindow, UINT nIDEvent, UINT uElapse); //���ö�ʱ��
XC_API BOOL WINAPI XWnd_KillXCTimer(HWINDOW hWindow, UINT nIDEvent);
XC_API HBKM WINAPI  XWnd_GetBkManager(HWINDOW hWindow);
XC_API HBKM WINAPI  XWnd_GetBkManagerEx(HWINDOW hWindow);
XC_API void WINAPI  XWnd_SetBkMagager(HWINDOW hWindow, HBKM hBkInfoM);
XC_API void WINAPI XWnd_SetTransparentType(HWINDOW hWindow, window_transparent_ nType);  //����͸������
XC_API void WINAPI XWnd_SetTransparentAlpha(HWINDOW hWindow, BYTE alpha); //���ô���͸����
XC_API void WINAPI XWnd_SetTransparentColor(HWINDOW hWindow, COLORREF color); //���ô���͸��ɫ
XC_API void WINAPI XWnd_SetShadowInfo(HWINDOW hWindow, int nSize, int nDepth, int nAngeleSize, BOOL bRightAngle, COLORREF color);
XC_API window_transparent_ WINAPI XWnd_GetTransparentType(HWINDOW hWindow);
XC_API void WINAPI XWnd_GetShadowInfo(HWINDOW hWindow, out_ int* pnSize, out_ int* pnDepth, out_ int* pnAngeleSize, out_ BOOL* pbRightAngle, out_ COLORREF* pColor);
XC_API BOOL WINAPI _XWnd_RegEvent(HWINDOW hWindow, UINT nEvent, xc_event* pEvent);
XC_API BOOL WINAPI _XWnd_RemoveEvent(HWINDOW hWindow, UINT nEvent, xc_event* pEvent);
XC_API BOOL WINAPI _XEle_RegEvent(HELE hEle, UINT nEvent, xc_event* pEvent);
XC_API BOOL WINAPI _XEle_RemoveEvent(HELE hEle, UINT nEvent, xc_event* pEvent);

//����
XC_API void WINAPI XWidget_LayoutItem_EnableWrap(HXCGUI hXCGUI, BOOL bWrap);
XC_API void WINAPI XWidget_LayoutItem_EnableSwap(HXCGUI hXCGUI, BOOL bEnable);
XC_API void WINAPI XWidget_LayoutItem_EnableFloat(HXCGUI hXCGUI, BOOL bFloat);
				   
XC_API void WINAPI XWidget_LayoutItem_SetWidth(HXCGUI hXCGUI, layout_size_ nType, int nWidth);
XC_API void WINAPI XWidget_LayoutItem_SetHeight(HXCGUI hXCGUI, layout_size_ nType, int nHeight);
XC_API void WINAPI XWidget_LayoutItem_GetWidth(HXCGUI hXCGUI, out_ layout_size_* pType, out_ int* pWidth);
XC_API void WINAPI XWidget_LayoutItem_GetHeight(HXCGUI hXCGUI, out_ layout_size_* pType, out_ int* pHeight);
XC_API void WINAPI XWidget_LayoutItem_SetAlign(HXCGUI hXCGUI, layout_align_axis_ nAlign);
XC_API void WINAPI XWidget_LayoutItem_SetMargin(HXCGUI hXCGUI, int left, int top, int right, int bottom);
XC_API void WINAPI XWidget_LayoutItem_GetMargin(HXCGUI hXCGUI, out_ marginSize_* pMargin);
XC_API void WINAPI XWidget_LayoutItem_SetMinSize(HXCGUI hXCGUI, int width, int height);
XC_API void WINAPI XWidget_LayoutItem_SetPosition(HXCGUI hXCGUI, int left, int top, int right, int bottom);

XC_API HWINDOW WINAPI XWnd_Attach(HWND hWnd, int XCStyle);
XC_API HWINDOW WINAPI XModalWnd_Attach(HWND  hWnd, int XCStyle);
XC_API HWINDOW WINAPI XFrameWnd_Attach(HWND  hWnd, int XCStyle);
XC_API void WINAPI XWnd_EnableDragFiles(HWINDOW hWindow, BOOL bEnable);
XC_API HELE WINAPI XMenuBar_GetButton(HELE hEle, int nIndex);
XC_API void WINAPI XDraw_DrawArc(HDRAW hDraw, int x, int y, int nWidth, int nHeight, float startAngle, float sweepAngle);


XC_API void WINAPI XObj_SetTypeEx(HXCGUI hXCGUI, XC_OBJECT_TYPE_EX nType);
XC_API void WINAPI XWnd_Show(HWINDOW hWindow, BOOL bShow);
XC_API void WINAPI XProgBar_EnableShowText(HELE hEle, BOOL bEnable);

XC_API void WINAPI XWidget_SetID(HXCGUI hXCGUI, int nID);
XC_API int  WINAPI XWidget_GetID(HXCGUI hXCGUI);

XC_API void WINAPI XWidget_SetUID(HXCGUI hXCGUI, int nUID);
XC_API int  WINAPI XWidget_GetUID(HXCGUI hXCGUI);

XC_API void WINAPI XWidget_SetName(HXCGUI hXCGUI, const wchar_t* pName);
XC_API const wchar_t* WINAPI XWidget_GetName(HXCGUI hXCGUI);



XC_API HDRAW WINAPI XDraw_Create(HWINDOW hWindow); //����
XC_API HDRAW WINAPI XDraw_CreateGDI(HWINDOW hWindow, HDC hdc);

XC_API void  WINAPI XDraw_Destroy(HDRAW hDraw); //����
XC_API void  WINAPI XDraw_SetOffset(HDRAW hDraw, int x, int y); //��������ƫ����
XC_API void  WINAPI XDraw_GetOffset(HDRAW hDraw, out_ int* pX, out_ int* pY); //��ȡ����ƫ����
XC_API HDC   WINAPI XDraw_GetHDC(HDRAW hDraw);

XC_API void WINAPI XDraw_SetBrushColor(HDRAW hDraw, COLORREF color);
XC_API void WINAPI XDraw_SetTextAlign(HDRAW hDraw, int nFlag);
XC_API void WINAPI XDraw_SetTextVertical(HDRAW hDraw, BOOL bVertical);
XC_API void WINAPI XDraw_SetFont(HDRAW hDraw, HFONTX  hFontx);
XC_API void WINAPI XDraw_SetLineWidth(HDRAW hDraw, int width);
XC_API void WINAPI XDraw_SetLineWidthF(HDRAW hDraw, float width);

XC_API void WINAPI XDraw_SetClipRect(HDRAW hDraw, RECT* pRect);
XC_API void WINAPI XDraw_ClearClip(HDRAW hDraw);

XC_API void WINAPI XDraw_EnableSmoothingMode(HDRAW hDraw, BOOL  bEnable);   //����ƽ��ģʽ
XC_API void WINAPI XDraw_EnableWndTransparent(HDRAW hDraw, BOOL  bTransparent);

//GDI:
XC_API void WINAPI XDraw_GDI_RestoreGDIOBJ(HDRAW hDraw);  //��ԭ״̬,�ͷ��û��󶨵�GDI����
XC_API int  WINAPI XDraw_GDI_SetBkMode(HDRAW hDraw, BOOL bTransparent);
XC_API int  WINAPI XDraw_GDI_SelectClipRgn(HDRAW hDraw, HRGN hRgn);

XC_API HBRUSH WINAPI XDraw_GDI_CreateSolidBrush(HDRAW hDraw, COLORREF crColor);
XC_API HPEN WINAPI XDraw_GDI_CreatePen(HDRAW hDraw, int fnPenStyle, int width, COLORREF crColor);
XC_API HRGN WINAPI XDraw_GDI_CreateRectRgn(HDRAW hDraw, int nLeftRect, int nTopRect, int nRightRect, int nBottomRect);
XC_API HRGN WINAPI XDraw_GDI_CreateRoundRectRgn(HDRAW hDraw, int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, int nWidthEllipse, int nHeightEllipse);
XC_API HRGN WINAPI XDraw_GDI_CreatePolygonRgn(HDRAW hDraw, POINT* pPt, int cPoints, int fnPolyFillMode);

XC_API BOOL WINAPI XDraw_GDI_Rectangle(HDRAW hDraw, int nLeftRect, int nTopRect, int nRightRect, int nBottomRect);
XC_API BOOL WINAPI XDraw_GDI_FillRgn(HDRAW hDraw, HRGN hrgn, HBRUSH hbr);
XC_API BOOL WINAPI XDraw_GDI_Ellipse(HDRAW hDraw, RECT* pRect);
XC_API BOOL WINAPI XDraw_GDI_FrameRgn(HDRAW hDraw, HRGN hrgn, HBRUSH hbr, int width, int nHeight);

XC_API BOOL WINAPI XDraw_GDI_MoveToEx(HDRAW hDraw, int X, int Y, POINT* pPoint = NULL);
XC_API BOOL WINAPI XDraw_GDI_LineTo(HDRAW hDraw, int nXEnd, int nYEnd);
XC_API BOOL WINAPI XDraw_GDI_Polyline(HDRAW hDraw, in_buffer_ POINT* pArrayPt, int arrayPtSize);

XC_API BOOL WINAPI XDraw_GDI_DrawIconEx(HDRAW hDraw, int xLeft, int yTop, HICON hIcon, int cxWidth, int cyWidth, UINT istepIfAniCur, HBRUSH hbrFlickerFreeDraw, UINT diFlags);

XC_API BOOL WINAPI XDraw_GDI_BitBlt(HDRAW hDrawDest, int nXDest, int nYDest, int width, int nHeight, HDC hdcSrc, int nXSrc, int nYSrc, DWORD dwRop);
XC_API BOOL WINAPI XDraw_GDI_BitBlt2(HDRAW hDrawDest, int nXDest, int nYDest, int width, int nHeight, HDRAW hDrawSrc, int nXSrc, int nYSrc, DWORD dwRop);
XC_API BOOL WINAPI XDraw_GDI_AlphaBlend(HDRAW hDraw, int nXOriginDest, int nYOriginDest, int nWidthDest, int nHeightDest, HDC hdcSrc, int nXOriginSrc, int nYOriginSrc, int nWidthSrc, int nHeightSrc, int alpha);
XC_API COLORREF WINAPI XDraw_GDI_SetPixel(HDRAW hDraw, int X, int Y, COLORREF crColor);

//-----------------
XC_API void WINAPI XDraw_FillRect(HDRAW hDraw, RECT* pRect);
XC_API void WINAPI XDraw_FillRectF(HDRAW hDraw, RECTF* pRect);
XC_API void WINAPI XDraw_FillRectColor(HDRAW hDraw, RECT* pRect, COLORREF color);
XC_API void WINAPI XDraw_FillRectColorF(HDRAW hDraw, RECTF* pRect, COLORREF color);

XC_API void WINAPI XDraw_DrawRect(HDRAW hDraw, RECT* pRect);
XC_API void WINAPI XDraw_DrawRectF(HDRAW hDraw, RECTF* pRect);

XC_API void WINAPI XDraw_FillEllipse(HDRAW hDraw, RECT* pRect);
XC_API void WINAPI XDraw_FillEllipseF(HDRAW hDraw, RECTF* pRect);

XC_API void WINAPI XDraw_DrawEllipse(HDRAW hDraw, RECT* pRect);
XC_API void WINAPI XDraw_DrawEllipseF(HDRAW hDraw, RECTF* pRect);

XC_API void WINAPI XDraw_FillRoundRect(HDRAW hDraw, RECT* pRect, int width, int nHeight);
XC_API void WINAPI XDraw_FillRoundRectF(HDRAW hDraw, RECTF* pRect, float width, float height);

XC_API void WINAPI XDraw_DrawRoundRect(HDRAW hDraw, RECT* pRect, int width, int nHeight);
XC_API void WINAPI XDraw_DrawRoundRectF(HDRAW hDraw, RECTF* pRect, float width, float height);

XC_API void WINAPI XDraw_FillRoundRectEx(HDRAW hDraw, RECT* pRect, int leftTop, int rightTop, int rightBottom, int leftBottom);
XC_API void WINAPI XDraw_FillRoundRectExF(HDRAW hDraw, RECTF* pRect, float leftTop, float rightTop, float rightBottom, float leftBottom);

XC_API void WINAPI XDraw_DrawRoundRectEx(HDRAW hDraw, RECT* pRect, int leftTop, int rightTop, int rightBottom, int leftBottom);
XC_API void WINAPI XDraw_DrawRoundRectExF(HDRAW hDraw, RECTF* pRect, float leftTop, float rightTop, float rightBottom, float leftBottom);

XC_API void WINAPI XDraw_GradientFill2(HDRAW hDraw, RECT* pRect, COLORREF color1, COLORREF color2, int mode);
XC_API void WINAPI XDraw_GradientFill2F(HDRAW hDraw, RECTF* pRect, COLORREF color1, COLORREF color2, int mode);

XC_API void WINAPI XDraw_GradientFill4(HDRAW hDraw, RECT* pRect, COLORREF color1, COLORREF color2, COLORREF color3, COLORREF color4, int mode);
XC_API void WINAPI XDraw_GradientFill4F(HDRAW hDraw, RECTF* pRect, COLORREF color1, COLORREF color2, COLORREF color3, COLORREF color4, int mode);

XC_API void WINAPI XDraw_FocusRect(HDRAW hDraw, RECT* pRect);
XC_API void WINAPI XDraw_FocusRectF(HDRAW hDraw, RECTF* pRect);

XC_API void WINAPI XDraw_DrawLine(HDRAW hDraw, int x1, int y1, int x2, int y2);
XC_API void WINAPI XDraw_DrawLineF(HDRAW hDraw, float x1, float y1, float x2, float y2);

XC_API void WINAPI XDraw_Dottedline(HDRAW hDraw, int x1, int y1, int x2, int y2);
XC_API void WINAPI XDraw_DottedlineF(HDRAW hDraw, float x1, float y1, float x2, float y2);

XC_API void WINAPI XDraw_DrawCurve(HDRAW hDraw, in_buffer_ POINT* points, int count, float tension);
XC_API void WINAPI XDraw_DrawCurveF(HDRAW hDraw, in_buffer_ POINTF* points, int count, float tension);

//����Բ��
XC_API void WINAPI XDraw_DrawArc(HDRAW hDraw, int x, int y, int width, int nHeight, float startAngle, float sweepAngle);
XC_API void WINAPI XDraw_DrawArcF(HDRAW hDraw, float x, float y, float width, float height, float startAngle, float sweepAngle);

//���ƶ����
XC_API void WINAPI XDraw_DrawPolygon(HDRAW hDraw, in_buffer_ POINT* points, int nCount);
XC_API void WINAPI XDraw_DrawPolygonF(HDRAW hDraw, in_buffer_ POINTF* points, int nCount);

XC_API void WINAPI XDraw_FillPolygon(HDRAW hDraw, in_buffer_ POINT* points, int nCount);
XC_API void WINAPI XDraw_FillPolygonF(HDRAW hDraw, in_buffer_ POINTF* points, int nCount);

//ͼƬ
XC_API void WINAPI XDraw_Image(HDRAW hDraw, HIMAGE hImageFrame, int x, int y);
XC_API void WINAPI XDraw_ImageF(HDRAW hDraw, HIMAGE hImageFrame, float x, float y);

XC_API void WINAPI XDraw_ImageEx(HDRAW hDraw, HIMAGE hImageFrame, int x, int y, int width, int height);
XC_API void WINAPI XDraw_ImageExF(HDRAW hDraw, HIMAGE hImageFrame, float x, float y, float width, float height);

XC_API void WINAPI XDraw_ImageAdaptive(HDRAW hDraw, HIMAGE hImageFrame, RECT* pRect, BOOL bOnlyBorder = FALSE);
XC_API void WINAPI XDraw_ImageAdaptiveF(HDRAW hDraw, HIMAGE hImageFrame, RECTF* pRect, BOOL bOnlyBorder = FALSE);

//�����½������Ͻ���,����ƽ������
//flag:ƽ������,0���Ͻ�,1�����½�
XC_API void WINAPI XDraw_ImageTile(HDRAW hDraw, HIMAGE hImageFrame, RECT* pRect, int flag = 0);
XC_API void WINAPI XDraw_ImageTileF(HDRAW hDraw, HIMAGE hImageFrame, RECTF* pRect, int flag = 0);

XC_API void WINAPI XDraw_ImageSuper(HDRAW hDraw, HIMAGE hImageFrame, RECT* pRect, BOOL bClip = FALSE);
XC_API void WINAPI XDraw_ImageSuperF(HDRAW hDraw, HIMAGE hImageFrame, RECTF* pRect, BOOL bClip = FALSE);

XC_API void WINAPI XDraw_ImageSuperEx(HDRAW hDraw, HIMAGE hImageFrame, RECT* pRcDest, RECT* pRcSrc);
XC_API void WINAPI XDraw_ImageSuperExF(HDRAW hDraw, HIMAGE hImageFrame, RECTF* pRcDest, RECTF* pRcSrc);

XC_API void WINAPI XDraw_ImageSuperMask(HDRAW hDraw, HIMAGE hImageFrame, HIMAGE hImageFrameMask, RECT* pRect, RECT* pRectMask, BOOL bClip = FALSE);

//�ı�
XC_API void WINAPI XDraw_DrawText(HDRAW hDraw, const wchar_t* pString, int nCount, RECT* pRect);
XC_API void WINAPI XDraw_DrawTextF(HDRAW hDraw, const wchar_t* pString, int nCount, RECTF* pRect);

XC_API void WINAPI XDraw_DrawTextUnderline(HDRAW hDraw, const wchar_t* pString, int nCount, RECT* pRect, COLORREF colorLine);
XC_API void WINAPI XDraw_DrawTextUnderlineF(HDRAW hDraw, const wchar_t* pString, int nCount, RECTF* pRect, COLORREF colorLine);

XC_API void WINAPI XDraw_TextOut(HDRAW hDraw, int xStart, int yStart, const wchar_t* pString, int cbString);
XC_API void WINAPI XDraw_TextOutF(HDRAW hDraw, float xStart, float yStart, const wchar_t* pString, int cbString);

XC_API void WINAPI XDraw_TextOutEx(HDRAW hDraw, int xStart, int yStart, const wchar_t* pString);
XC_API void WINAPI XDraw_TextOutExF(HDRAW hDraw, float xStart, float yStart, const wchar_t* pString);

XC_API void WINAPI XDraw_TextOutA(HDRAW hDraw, int xStart, int yStart, const char* pString);
XC_API void WINAPI XDraw_TextOutAF(HDRAW hDraw, float xStart, float yStart, const char* pString);

//v3.1.1
XC_API void WINAPI XWnd_SetIcon(HWINDOW hWindow, HIMAGE hImage);
XC_API void WINAPI XWnd_SetTitle(HWINDOW hWindow, const wchar_t* pTitle);
XC_API void WINAPI XWnd_SetTitleColor(HWINDOW hWindow, COLORREF color);
XC_API HELE WINAPI XWnd_GetButton(HWINDOW hWindow, int nFlag);
XC_API HIMAGE WINAPI XWnd_GetIcon(HWINDOW hWindow);
XC_API const wchar_t* WINAPI XWnd_GetTitle(HWINDOW hWindow);
XC_API COLORREF WINAPI XWnd_GetTitleColor(HWINDOW hWindow);

XC_API vint WINAPI XC_GetD2dFactory();
XC_API vint WINAPI XC_GetWicFactory();
XC_API vint WINAPI XC_GetDWriteFactory();
XC_API void WINAPI XC_SetD2dTextRenderingMode(XC_DWRITE_RENDERING_MODE mode);

XC_API vint WINAPI XDraw_GetD2dRenderTarget(HDRAW hDraw);
XC_API void WINAPI XDraw_SetD2dTextRenderingMode(HDRAW hDraw, XC_DWRITE_RENDERING_MODE mode);

XC_API HELE WINAPI XLayoutFrame_CreateEx(HXCGUI hParent);
XC_API void WINAPI XLayoutFrame_EnableLayout(HELE hEle, BOOL bEnable);
XC_API BOOL WINAPI XLayoutFrame_IsEnableLayout(HELE hEle);
XC_API int  WINAPI XLayoutFrame_GetWidthIn(HELE hEle);
XC_API int  WINAPI XLayoutFrame_GetHeightIn(HELE hEle);

XC_API void   WINAPI XDraw_SetTextRenderingHint(HDRAW hDraw, int  nType);
XC_API HFONTX WINAPI XFont_CreateFromMem(void* data, UINT length, int fontSize = 12, int style = fontStyle_regular);
XC_API void WINAPI XComboBox_PopupDropList(HELE hEle);
XC_API BOOL WINAPI XComboBox_SetItemTemplate(HELE hEle, HTEMP hTemp);

XC_API BOOL WINAPI XC_IsEnableD2D();
XC_API HFONTX WINAPI XFont_CreateFromRes(int id, const wchar_t* pType, int fontSize, int style, HMODULE hModule=NULL);

XC_API int WINAPI XC_MessageBox(const wchar_t* pTitle, const wchar_t* pText, int nFlags=messageBox_flag_ok | messageBox_flag_icon_info, HWND hWndParent =0, int XCStyle = window_style_modal);
XC_API HWINDOW WINAPI XMsg_Create(const wchar_t* pTitle, const wchar_t* pText, int nFlags=messageBox_flag_ok | messageBox_flag_icon_info, HWND hWndParent =0, int XCStyle = window_style_modal);

//3.2.0--------------------------
//�޸�:
XC_API BOOL WINAPI XC_LoadStyleFromStringW(const wchar_t* pString, const wchar_t* pFileName);
//����:
XC_API BOOL WINAPI XC_LoadStyleFromString(const char* pString, const wchar_t* pFileName);
XC_API BOOL WINAPI XC_LoadStyleFromStringUtf8(const char* pString, const wchar_t* pFileName);

XC_API HIMAGE WINAPI XImage_LoadSvg(HSVG hSvg);
XC_API HIMAGE WINAPI XImage_LoadSvgFile(const wchar_t* pFileName);
XC_API HSVG   WINAPI XImage_GetSvg(HIMAGE hImage);

//SVG �ϲ��� 3.3.0

XC_API void WINAPI XDraw_DrawSvgSrc(HDRAW hDraw, HSVG hSvg);
XC_API void WINAPI XDraw_DrawSvg(HDRAW hDraw, HSVG hSvg, int x, int y);
XC_API void WINAPI XDraw_DrawSvgEx(HDRAW hDraw, HSVG hSvg, int x, int y, int nWidth, int nHeight);
XC_API void WINAPI XDraw_DrawSvgSize(HDRAW hDraw, HSVG hSvg, int nWidth, int nHeight);

XC_API void WINAPI XC_ShowSvgFrame(BOOL bShow);

XC_API void WINAPI XWnd_AddBkBorder(HWINDOW hWindow, int nState, COLORREF color, int width);
XC_API void WINAPI XWnd_AddBkFill(HWINDOW hWindow, int nState, COLORREF color);
XC_API void WINAPI XWnd_AddBkImage(HWINDOW hWindow, int nState, HIMAGE hImage);
XC_API int  WINAPI XWnd_GetBkInfoCount(HWINDOW hWindow);
XC_API void WINAPI XWnd_ClearBkInfo(HWINDOW hWindow);


//3.3.0----------------------------------------

//�Ƴ�:
//XEle_Move
//XEle_MoveLogic
//XShape_Move
//XSvg_GetOffset
//XSvg_SetOffset
//XWnd_Move
//XSvg_LoadString
//XImage_LoadSvgString

//����:
XC_API void WINAPI XWnd_SetPosition(HWINDOW hWindow, int x, int y);
XC_API int  WINAPI XEle_SetPosition(HELE hEle, int x, int y, BOOL bRedraw = FALSE, int nFlags = adjustLayout_all, UINT nAdjustNo = 0);
XC_API int  WINAPI XEle_SetPositionLogic(HELE hEle, int x, int y, BOOL bRedraw = FALSE, int nFlags = adjustLayout_all, UINT nAdjustNo = 0);
XC_API void WINAPI XEle_GetPosition(HELE hEle, int* pOutX, int* pOutY);
XC_API int  WINAPI XEle_SetSize(HELE hEle, int nWidth, int nHeight, BOOL bRedraw = FALSE, int nFlags = adjustLayout_all, UINT nAdjustNo = 0);
XC_API void WINAPI XEle_GetSize(HELE hEle, out_ int* pOutWidth, out_ int* pOutHeight);

XC_API void WINAPI XShape_SetPosition(HXCGUI hShape, int x, int y);
XC_API void WINAPI XShape_GetPosition(HXCGUI hShape, int* pOutX, int* pOutY);
XC_API void WINAPI XShape_SetSize(HXCGUI hShape, int  nWidth, int  nHeight);
XC_API void WINAPI XShape_GetSize(HXCGUI hShape, int* pOutWidth, int* pOutHeight);
XC_API void WINAPI XShape_SetAlpha(HXCGUI hShape, BYTE alpha);
XC_API BYTE WINAPI XShape_GetAlpha(HXCGUI hShape);

XC_API HIMAGE WINAPI XImage_LoadSvgString(const char* pString); //�޸�
XC_API HIMAGE WINAPI XImage_LoadSvgStringW(const wchar_t* pString);
XC_API HIMAGE WINAPI XImage_LoadSvgStringUtf8(const char* pString);

XC_API float WINAPI XEase_Ex(float pos, int flag);

//-----SVG---------------------------------------------------------------
XC_API HSVG WINAPI XSvg_LoadFile(const wchar_t* pFileName);
XC_API HSVG WINAPI XSvg_LoadString(const char* pString);
XC_API HSVG WINAPI XSvg_LoadStringW(const wchar_t* pString);
XC_API HSVG WINAPI XSvg_LoadStringUtf8(const char* pString);
XC_API HSVG WINAPI XSvg_LoadZip(const wchar_t* pZipFileName, const wchar_t* pFileName, const wchar_t* pPassword = NULL);
XC_API HSVG WINAPI XSvg_LoadRes(int id, const wchar_t* pType, HMODULE hModule = NULL);

XC_API void WINAPI XSvg_SetSize(HSVG hSvg, int nWidth, int nHeight);
XC_API void WINAPI XSvg_GetSize(HSVG hSvg, out_ int* pWidth, out_ int* pHeight);

XC_API int  WINAPI XSvg_GetWidth(HSVG hSvg);
XC_API int  WINAPI XSvg_GetHeight(HSVG hSvg);

XC_API void WINAPI XSvg_SetPosition(HSVG hSvg, int x, int y);
XC_API void WINAPI XSvg_GetPosition(HSVG hSvg, out_ int* pX, out_ int* pY);

void WINAPI XSvg_SetPositionF(HSVG hSvg, float x, float y);
void WINAPI XSvg_GetPositionF(HSVG hSvg, out_ float* pX, out_ float* pY);

XC_API void WINAPI XSvg_GetViewBox(HSVG hSvg, out_ RECT* pViewBox);
XC_API void WINAPI XSvg_SetAlpha(HSVG hSvg, BYTE alpha);
XC_API BYTE WINAPI XSvg_GetAlpha(HSVG hSvg);

XC_API void WINAPI XSvg_SetUserFillColor(HSVG hSvg, COLORREF color, BOOL bEnable);
XC_API void WINAPI XSvg_SetUserStrokeColor(HSVG hSvg, COLORREF color, float strokeWidth, BOOL bEnable);

XC_API BOOL WINAPI XSvg_GetUserFillColor(HSVG hSvg, out_ COLORREF* pColor);
XC_API BOOL WINAPI XSvg_GetUserStrokeColor(HSVG hSvg, out_ COLORREF* pColor, out_ float* pStrokeWidth);

XC_API void WINAPI XSvg_SetRotateAngle(HSVG hSvg, float angle);
XC_API float WINAPI XSvg_GetRotateAngle(HSVG hSvg);
XC_API void WINAPI XSvg_SetRotate(HSVG hSvg, float angle, float x, float y, BOOL bOffset = FALSE);
XC_API void WINAPI XSvg_GetRotate(HSVG hSvg, out_ float* pAngle, out_ float* pX, out_ float* pY, out_ BOOL* pbOffset);

XC_API void WINAPI XSvg_Show(HSVG hSvg, BOOL bShow);
XC_API void WINAPI XSvg_EnableAutoDestroy(HSVG hSvg, BOOL bEnable);
XC_API void WINAPI XSvg_AddRef(HSVG hSvg);
XC_API void WINAPI XSvg_Release(HSVG hSvg);
XC_API int  WINAPI XSvg_GetRefCount(HSVG hSvg);
XC_API void WINAPI XSvg_Destroy(HSVG hSvg);

//������Ч------------------------------------------------
XC_API void   WINAPI XAnima_Run(HXCGUI hAnimation, HXCGUI hRedrawObjectUI);
XC_API BOOL   WINAPI XAnima_Release(HXCGUI hAnimation, BOOL bEnd = TRUE);
XC_API int    WINAPI XAnima_ReleaseEx(HXCGUI hObjectUI, BOOL bEnd); //�Ƴ�ָ��UI��������Ķ���

//��������
XC_API HXCGUI WINAPI XAnima_Create(HXCGUI hObjectUI, int nLoopCount = 0);

XC_API HXCGUI WINAPI XAnima_Move(HXCGUI  hSequence, UINT duration, float x, float y, int nLoopCount = 1, int ease_flag = 0, BOOL bGoBack = FALSE);
XC_API HXCGUI WINAPI XAnima_MoveEx(HXCGUI  hSequence, UINT duration, float from_x, float from_y, float to_x, float to_y, int nLoopCount = 1, int ease_flag = 0, BOOL bGoBack = FALSE);
HXCGUI Anima_MoveExT(HXCGUI  hSequence, UINT duration, float from_x, float from_y, float to_x, float to_y, int nLoopCount = 1, int ease_flag = 0, BOOL bGoBack = FALSE, BOOL bFrom = FALSE);

XC_API HXCGUI WINAPI XAnima_Rotate(HXCGUI  hSequence, UINT duration, float angle, int nLoopCount = 1, int ease_flag = 0, BOOL bGoBack = FALSE);
XC_API HXCGUI WINAPI XAnima_RotateEx(HXCGUI  hSequence, UINT duration, float from, float to, int nLoopCount = 1, int ease_flag = 0, BOOL bGoBack = FALSE);
HXCGUI Anima_RotateExT(HXCGUI  hSequence, UINT duration, float from, float to, int nLoopCount = 1, int ease_flag = 0, BOOL bGoBack = FALSE, BOOL bFrom = FALSE);

XC_API HXCGUI WINAPI XAnima_Scale(HXCGUI hSequence, UINT duration, float scaleX, float scaleY, int nLoopCount = 0, int ease_flag = 0, BOOL bGoBack = TRUE);
XC_API HXCGUI WINAPI XAnima_ScaleSize(HXCGUI hSequence, UINT duration, float width, float height, int nLoopCount = 1, int ease_flag = 0, BOOL bGoBack = FALSE);

XC_API HXCGUI WINAPI XAnima_Alpha(HXCGUI hSequence, UINT duration, BYTE alpha, int nLoopCount = 0, int ease_flag = 0, BOOL bGoBack = FALSE);
XC_API HXCGUI WINAPI XAnima_AlphaEx(HXCGUI hSequence, UINT duration, BYTE  from_alpha, BYTE to_alpha, int nLoopCount = 0, int ease_flag = 0, BOOL bGoBack = FALSE);
HXCGUI Anima_AlphaExT(HXCGUI hSequence, UINT duration, BYTE  from_alpha, BYTE to_alpha, int nLoopCount = 0, int ease_flag = 0, BOOL bGoBack = FALSE, BOOL bFrom = FALSE);

XC_API HXCGUI WINAPI XAnima_Color(HXCGUI hSequence, UINT duration, COLORREF color, int nLoopCount = 0, int ease_flag = 0, BOOL bGoBack = FALSE);
XC_API HXCGUI WINAPI XAnima_ColorEx(HXCGUI hSequence, UINT duration, COLORREF from, COLORREF to, int nLoopCount = 0, int ease_flag = 0, BOOL bGoBack = FALSE);
HXCGUI Anima_ColorExT(HXCGUI hSequence, UINT duration, COLORREF from, COLORREF to, int nLoopCount = 0, int ease_flag = 0, BOOL bGoBack = FALSE, BOOL bFrom = FALSE);

XC_API HXCGUI WINAPI XAnima_LayoutWidth(HXCGUI hSequence, UINT duration, layout_size_  nType, float width, int nLoopCount = 1, int ease_flag = 0, BOOL bGoBack = FALSE);
XC_API HXCGUI WINAPI XAnima_LayoutHeight(HXCGUI hSequence, UINT duration, layout_size_  nType, float height, int nLoopCount = 1, int ease_flag = 0, BOOL bGoBack = FALSE);

XC_API HXCGUI WINAPI XAnima_LayoutSize(HXCGUI hSequence, UINT duration, layout_size_  nWidthType, float width, layout_size_  nHeightType, float height, int nLoopCount = 0, int ease_flag = 0, BOOL bGoBack = TRUE);


XC_API HXCGUI WINAPI XAnima_Delay(HXCGUI hSequence, float duration);
XC_API HXCGUI WINAPI XAnima_Show(HXCGUI hSequence, float duration, BOOL bShow);

//������
XC_API HXCGUI WINAPI XAnimaGroup_Create(int nLoopCount = 0);
XC_API void   WINAPI XAnimaGroup_AddItem(HXCGUI hGroup, HXCGUI hSequence);

//����������
XC_API void   WINAPI XAnimaItem_EnableCompleteRelease(HXCGUI hAnimationItem, BOOL bEnable);
XC_API void   WINAPI XAnimaRotate_SetCenter(HXCGUI hAnimationRotate, float x, float y, BOOL bOffset = FALSE);
XC_API void   WINAPI XAnimaScale_SetPosition(HXCGUI hAnimationScale, position_flag_  position);

XC_API HXCGUI WINAPI XAnima_GetObjectUI(HXCGUI hAnimation); //��ȡ����������UI����
XC_API void   WINAPI XAnima_EnableAutoDestroy(HXCGUI hAnimation, BOOL bEnable);//�����Զ�����


//v3.3.1---------------------------------------------------------

//�Ż�����˳��
XC_API HWINDOW WINAPI XWnd_CreateEx(DWORD dwExStyle, DWORD dwStyle, const wchar_t* lpClassName, int x, int y, int cx, int cy, const wchar_t* pTitle, HWND hWndParent = NULL, int XCStyle = window_style_default);
XC_API HWINDOW WINAPI XModalWnd_CreateEx(DWORD dwExStyle, DWORD dwStyle, const wchar_t* lpClassName, int x, int y, int cx, int cy, const wchar_t* pTitle, HWND hWndParent, int XCStyle=window_style_modal);  //��������
XC_API HWINDOW WINAPI XFrameWnd_CreateEx(DWORD dwExStyle, DWORD dwStyle, wchar_t* lpClassName, int x, int y, int cx, int cy, wchar_t* pTitle, HWND hWndParent, int XCStyle);  //��������

//����
XC_API HXCGUI WINAPI XAnima_DestroyObjectUI(HXCGUI hSequence, float duration);
XC_API void   WINAPI XAnima_SetCallBack(HXCGUI hAnimation, funAnimation callback);
XC_API void   WINAPI XAnima_SetUserData(HXCGUI hAnimation, vint nUserData);
XC_API vint   WINAPI XAnima_GetUserData(HXCGUI hAnimation);
XC_API BOOL   WINAPI XAnima_Stop(HXCGUI hAnimation);
XC_API BOOL   WINAPI XAnima_Start(HXCGUI hAnimation);
XC_API BOOL   WINAPI XAnima_Pause(HXCGUI hAnimation);
XC_API void   WINAPI XAnimaItem_SetCallback(HXCGUI hAnimationItem, funAnimationItem callback);
XC_API void   WINAPI XAnimaItem_SetUserData(HXCGUI hAnimationItem, vint nUserData);
XC_API vint   WINAPI XAnimaItem_GetUserData(HXCGUI hAnimationItem);
XC_API void   WINAPI XAnimaItem_EnableAutoDestroy(HXCGUI hAnimationItem, BOOL bEnable);

XC_API HELE WINAPI XNotifyMsg_WindowPopup(HWINDOW hWindow, position_flag_ position, const wchar_t* pTitle, const wchar_t* pText, HIMAGE hIcon, notifyMsg_skin_ skin = notifyMsg_skin_no);
XC_API HELE WINAPI XNotifyMsg_WindowPopupEx(HWINDOW hWindow, position_flag_ position, const wchar_t* pTitle, const wchar_t* pText, HIMAGE hIcon = NULL, notifyMsg_skin_ skin = notifyMsg_skin_no, BOOL bBtnClose = TRUE, BOOL bAutoClose = TRUE, int nWidth = -1, int nHeight = -1);
//�����浯��֪ͨ��Ϣ,���ش��ھ��
XC_API HWINDOW WINAPI XNotifyMsg_Popup(position_flag_ position, const wchar_t* pTitle, const wchar_t* pText, HIMAGE hIcon, notifyMsg_skin_ skin = notifyMsg_skin_no);
XC_API HWINDOW WINAPI XNotifyMsg_PopupEx(position_flag_ position, const wchar_t* pTitle, const wchar_t* pText, HIMAGE hIcon = NULL, notifyMsg_skin_ skin = notifyMsg_skin_no, BOOL bBtnClose = TRUE, BOOL bAutoClose = TRUE, int nWidth = -1, int nHeight = -1);
//����ָ������֪ͨ��Ϣ����, ���δָ������,��ô��������֪ͨ��Ϣ����
XC_API void WINAPI XNotifyMsg_SetDuration(HWINDOW hWindow, UINT duration);
XC_API void WINAPI XNotifyMsg_SetCaptionHeight(HWINDOW hWindow, int nHeight);
XC_API void WINAPI XNotifyMsg_SetWidth(HWINDOW hWindow, int nWidth);
XC_API void WINAPI XNotifyMsg_SetSpace(HWINDOW hWindow, int nSpace);
XC_API void WINAPI XNotifyMsg_SetBorderSize(HWINDOW hWindow, int left, int top, int right, int bottom);
XC_API void WINAPI XNotifyMsg_SetParentMargin(HWINDOW hWindow, int left, int top, int right, int bottom);

XC_API HWINDOW WINAPI XMsg_CreateEx(DWORD dwExStyle, DWORD dwStyle, const wchar_t* lpClassName,  const wchar_t* pTitle, const wchar_t* pText, int nFlags = messageBox_flag_ok | messageBox_flag_icon_info, HWND hWndParent = 0, int XCStyle = window_style_modal);

//v3.3.2--------------------------------------------------------
XC_API HXCGUI WINAPI XAnima_DelayEx(HXCGUI hSequence, float duration, int nLoopCount = 1, int ease_flag = 0, BOOL bGoBack = FALSE);
XC_API void   WINAPI XAnimaMove_SetFlag(HXCGUI hAnimationMove, int flags);
XC_API int  WINAPI XEle_SetBkInfo(HELE hEle, const wchar_t* pText);
XC_API int  WINAPI XWnd_SetBkInfo(HWINDOW hWindow, const wchar_t* pText);
XC_API int  WINAPI XBkM_SetInfo(HBKM hBkInfoM, const wchar_t* pText);


//���Ӳ��� hAttachWnd
XC_API HXCGUI WINAPI XC_LoadLayout(const wchar_t *pFileName, HXCGUI hParent=NULL, HWND hAttachWnd=NULL);
XC_API HXCGUI WINAPI XC_LoadLayoutZip(const wchar_t *pZipFileName, const wchar_t *pFileName, const wchar_t* pPassword=NULL, HXCGUI hParent=NULL, HWND hAttachWnd = NULL);
XC_API HXCGUI WINAPI XC_LoadLayoutZipMem(void* data, int length, const wchar_t *pFileName, const wchar_t* pPassword = NULL, HXCGUI hParent = NULL, HWND hAttachWnd = NULL);
XC_API HXCGUI WINAPI XC_LoadLayoutFromString(const char *pStringXML, HXCGUI hParent=NULL, HWND hAttachWnd = NULL);
XC_API HXCGUI WINAPI XC_LoadLayoutFromStringUtf8(const char *pStringXML, HXCGUI hParent = NULL, HWND hAttachWnd = NULL);

XC_API void WINAPI XWnd_SetCaptionMargin(HWINDOW hWindow, int left, int top, int right, int bottom);
XC_API BOOL WINAPI XWnd_IsDragBorder(HWINDOW hWindow);
XC_API BOOL WINAPI XWnd_IsDragWindow(HWINDOW hWindow);
XC_API BOOL WINAPI XWnd_IsDragCaption(HWINDOW hWindow);

//v3.3.3-------------------------------------------------------
XC_API void WINAPI XList_SetSplitLineColor(HELE hEle, COLORREF color);
XC_API void WINAPI XListBox_SetSplitLineColor(HELE hEle, COLORREF color);
XC_API void WINAPI XTree_SetSplitLineColor(HELE hEle, COLORREF color);

XC_API void  WINAPI XDraw_D2D_Clear(HDRAW hDraw, COLORREF color);

XC_API BOOL WINAPI XBkM_GetStateTextColor(HBKM hBkInfoM, int nState, out_ COLORREF* color);
XC_API vint WINAPI XBkM_GetObject(HBKM hBkInfoM, int id);

XC_API BOOL WINAPI XMenu_SetItemWidth(HMENUX hMenu, int nID, int nWidth);

XC_API void WINAPI XBkObj_SetMargin(vint hObj, int left, int top, int right, int bottom);
XC_API void WINAPI XBkObj_SetAlign(vint hObj, int  nFlags);//bkInfo_align_flags_
XC_API void WINAPI XBkObj_SetImage(vint hObj, HIMAGE hImage);
XC_API void WINAPI XBkObj_SetRotate(vint hObj, float angle);

XC_API void WINAPI XBkObj_SetFillColor(vint hObj, COLORREF color);
XC_API void WINAPI XBkObj_SetBorderWidth(vint hObj, int  width);
XC_API void WINAPI XBkObj_SetBorderColor(vint hObj, COLORREF color);
XC_API void WINAPI XBkObj_SetRectRoundAngle(vint hObj, int leftTop, int leftBottom, int rightTop, int rightBottom);

XC_API void WINAPI XBkObj_EnableFill(vint hObj, BOOL bEnable);
XC_API void WINAPI XBkObj_EnableBorder(vint hObj, BOOL bEnable);

XC_API void WINAPI XBkObj_SetText(vint hObj, const wchar_t* pText);
XC_API void WINAPI XBkObj_SetFont(vint hObj, HFONTX hFont);
XC_API void WINAPI XBkObj_SetTextAlign(vint hObj, int nAlign);

XC_API void WINAPI XBkObj_GetMargin(vint hObj, out_ marginSize_* pMargin);
XC_API int  WINAPI XBkObj_GetAlign(vint hObj);
XC_API HIMAGE WINAPI XBkObj_GetImage(vint hObj);
XC_API int  WINAPI XBkObj_GetRotate(vint hObj);

XC_API COLORREF WINAPI XBkObj_GetFillColor(vint hObj);
XC_API COLORREF WINAPI XBkObj_GetBorderColor(vint hObj);
XC_API int WINAPI XBkObj_GetBorderWidth(vint hObj);
XC_API void WINAPI XBkObj_GetRectRoundAngle(vint hObj, out_ RECT* pRect);

XC_API BOOL WINAPI XBkObj_IsFill(vint hObj);
XC_API BOOL WINAPI XBkObj_IsBorder(vint hObj);

XC_API const wchar_t* WINAPI XBkObj_GetText(vint hObj);
XC_API HFONTX WINAPI XBkObj_GetFont(vint hObj);
XC_API int  WINAPI XBkObj_GetTextAlign(vint hObj);

//v3.3.4---------------------------------
XC_API void WINAPI XEdit_SetRowSpace(HELE hEle, int nSpace);
XC_API void WINAPI XEdit_SetBackFont(HELE hEle, HFONTX hFont);

XC_API BOOL WINAPI XEdit_ReleaseStyle(HELE hEle, int iStyle);
XC_API int  WINAPI XEdit_ModifyStyle(HELE hEle, int iStyle, HFONTX hFont, COLORREF color, BOOL bColor);

XC_API void WINAPI XEdit_SetSpaceSize(HELE hEle, int size);
XC_API void WINAPI XEdit_SetCharSpaceSize(HELE hEle, int size, int sizeZh);

XC_API int  WINAPI XEdit_GetSelectTextLength(HELE hEle);
XC_API void WINAPI XEdit_SetSelectTextStyle(HELE hEle, int iStyle);

XC_API const char* WINAPI XEditor_GetExpandState(HELE hEle); //��ȡ�۵�״̬
XC_API BOOL WINAPI XEditor_SetExpandState(HELE hEle, const char* pString); //�����۵�״̬
XC_API int  WINAPI XEditor_GetIndentation(HELE hEle, int iRow);
XC_API BOOL WINAPI XEidtor_IsEmptyRow(HELE hEle, int iRow);

XC_API void WINAPI XEdit_AddTextUser(HELE hEle, const wchar_t* pString);
XC_API void WINAPI XEdit_PosToRowCol(HELE hEle, int iPos, out_ position_* pInfo);
XC_API int  WINAPI XEdit_RowColToPos(HELE hEle, int iRow, int iCol);
XC_API void WINAPI XEdit_SetCurPosEx(HELE hEle, int iRow, int iCol); //����
XC_API void WINAPI XEdit_GetCurPosEx(HELE hEle, out_ int* iRow, out_ int* iCol); //����
XC_API BOOL WINAPI XEdit_SetCurPos(HELE hEle, int pos);  //�޸�
XC_API void WINAPI XEdit_MoveEnd(HELE hEle); //����

//���Ӳ���
XC_API void  WINAPI XPane_ShowPane(HELE hEle, BOOL bActivate);
XC_API void  WINAPI XPane_HidePane(HELE hEle, BOOL bGroupDelay = FALSE);
//����:
XC_API BOOL WINAPI XPane_IsGroupActivate(HELE hEle);

//���Ӳ���:
XC_API void WINAPI XC_GetTextShowRect(const wchar_t* pString, int length, HFONTX hFontX, int nTextAlign, int width, out_ SIZE* pOutSize);

//����:
XC_API void WINAPI XList_SetItemHeight(HELE hEle, int iItem, int nHeight, int nSelHeight);
XC_API void WINAPI XList_GetItemHeight(HELE hEle, int iItem, out_ int* pHeight, out_ int* pSelHeight);

//�����˵��޸� �Ա���������֧��, �Դ�������֧��

//����������ӵ�20��

//�����б���ͼ ȡ���ݽӿ�
XC_API const wchar_t* WINAPI XAdListView_Group_GetText(HXCGUI hAdapter, int iGroup, int iColumn); //new
XC_API const wchar_t* XAdListView_Group_GetTextEx(HXCGUI hAdapter, int iGroup, const wchar_t* pName); //new
XC_API HIMAGE WINAPI XAdListView_Group_GetImage(HXCGUI hAdapter, int iGroup, int iColumn); //new
XC_API HIMAGE WINAPI XAdListView_Group_GetImageEx(HXCGUI hAdapter, int iGroup, const wchar_t* pName);//new

XC_API const wchar_t* WINAPI XAdListView_Item_GetText(HXCGUI hAdapter, int iGroup, int iItem, int iColumn);
XC_API HIMAGE WINAPI XAdListView_Item_GetImage(HXCGUI hAdapter, int iGroup, int iItem, int iColumn);

XC_API const wchar_t* WINAPI XListView_Group_GetText(HELE hEle, int iGroup, int iColumn); //new
XC_API const wchar_t* XListView_Group_GetTextEx(HELE hEle, int iGroup, const wchar_t* pName); //new
XC_API HIMAGE WINAPI XListView_Group_GetImage(HELE hEle, int iGroup, int iColumn); //new
XC_API HIMAGE WINAPI XListView_Group_GetImageEx(HELE hEle, int iGroup, const wchar_t* pName);//new

XC_API const wchar_t* WINAPI XListView_Item_GetText(HELE hEle, int iGroup, int iItem, int iColumn);
XC_API HIMAGE WINAPI XListView_Item_GetImage(HELE hEle, int iGroup, int iItem, int iColumn);


XC_API void WINAPI XDraw_ImageMask(HDRAW hDraw, HIMAGE hImageFrame, HIMAGE hImageFrameMask, RECT* pRect, int x2, int y2);
XC_API void WINAPI XDraw_ImageMaskRect(HDRAW hDraw, HIMAGE hImageFrame, RECT* pRect, RECT* pRcMask, RECT* pRcRoundAngle);
XC_API void WINAPI XDraw_ImageMaskEllipse(HDRAW hDraw, HIMAGE hImageFrame, RECT* pRect, RECT* pRcMask);


XC_API void WINAPI XDateTime_Popup(HELE hEle);
XC_API void WINAPI XMonthCal_SetTextColor(HELE hEle, int nFlag, COLORREF color);
XC_API HTEMP WINAPI XTemp_Clone(HTEMP hTemp);
XC_API frameWnd_cell_type_ WINAPI XFrameWnd_GetDragFloatWndTopFlag(HWINDOW hWindow);

