#pragma once
#include "pch.h"
#include "xcgui/XCWidget.hpp"
#include "xcgui/XCSvg.hpp"
#include "xcgui/XCLayoutBox.hpp"
#include "xcgui/XCFont.hpp"
#include "xcgui/XCDraw.hpp"
#include "xcgui/XCImage.hpp"
#include "xcgui/XCImageSrc.hpp"
#include "xcgui/XCElement.hpp"

// windows
#include "xcgui/window/XCWindow.hpp"
#include "xcgui/window/XCFrameWindow.hpp"
#include "xcgui/window/XCModelWindow.hpp"

// bkmgr
#include "xcgui/bkmanager/XCBkObject.hpp"
#include "xcgui/bkmanager/XCBkManager.hpp"

// adapter
#include "xcgui/adapter/XCAdapter.hpp"
#include "xcgui/adapter/XCAdapterListView.hpp"
#include "xcgui/adapter/XCAdapterMap.hpp"
#include "xcgui/adapter/XCAdapterTable.hpp"
#include "xcgui/adapter/XCAdapterTree.hpp"

// menu
#include "xcgui/menu/XCMenu.hpp"

// template
#include "xcgui/template/XCListItemTemplate.hpp"

// element
#include "xcgui/element/XCButton.hpp"
#include "xcgui/element/XCComboBox.hpp"
#include "xcgui/element/XCDateTime.hpp"
#include "xcgui/element/XCEdit.hpp"
#include "xcgui/element/XCEditor.hpp"
#include "xcgui/element/XCLayoutEle.hpp"
#include "xcgui/element/XCLayoutFrame.hpp"
#include "xcgui/element/XCList.hpp"
#include "xcgui/element/XCListBox.hpp"
#include "xcgui/element/XCListView.hpp"
#include "xcgui/element/XCMenuBar.hpp"
#include "xcgui/element/XCMonthCal.hpp"
#include "xcgui/element/XCPane.hpp"
#include "xcgui/element/XCProgressBar.hpp"
#include "xcgui/element/XCScrollBar.hpp"
#include "xcgui/element/XCScrollView.hpp"
#include "xcgui/element/XCSliderBar.hpp"
#include "xcgui/element/XCTabBar.hpp"
#include "xcgui/element/XCTextLink.hpp"
#include "xcgui/element/XCToolBar.hpp"
#include "xcgui/element/XCTree.hpp"


namespace xcgui
{

	class XCastManager {
	public:
		SINGLETON_DEFINE(XCastManager);
		XCastManager() = default;
		~XCastManager() {
			Release();
		}


	public:
		void Release() {	 
			for (auto iter : m_mObjects) {
				delete iter.second;
			}
			m_mObjects.clear();
		}

		XCObject* FindObject(HXCGUI handle) {
			auto iter = m_mObjects.find(handle);
			if (iter != m_mObjects.end()) {
				return iter->second;
			}
			return nullptr;
		}

		XCObject* NewObject(HXCGUI handle) {
			auto objectType = XObj_GetType(handle);
			XCObject* pObj = nullptr;

			switch (objectType)
			{
			case XC_ERROR:
				break;
			case XC_NOTHING:
				break;
			case XC_WINDOW:
				pObj = new XCWindow(handle);
				break;
			case XC_MODALWINDOW:
				pObj = new XCModelWindow(handle);
				break;
			case XC_FRAMEWND:
				pObj = new XCFrameWindow(handle);
				break;
			case XC_FLOATWND:
				pObj = new XCWindow(handle);
				break;
			case XC_COMBOBOXWINDOW:
				pObj = new XCWindow(handle);
				break;
			case XC_POPUPMENUWINDOW:
				pObj = new XCWindow(handle);
				break;
			case XC_POPUPMENUCHILDWINDOW:
				pObj = new XCWindow(handle);
				break;
			case XC_OBJECT_UI:
				pObj = new XCObjectUI(handle);
				break;
			case XC_WIDGET_UI:
				pObj = new XCWidget(handle);
				break;
			case XC_ELE:
				pObj = new XCElement((HELE)handle);
				break;
			case XC_ELE_LAYOUT:
				pObj = new XCLayoutEle(handle);
				break;
			case XC_LAYOUT_FRAME:
				pObj = new XCLayoutFrame(handle);
				break;
			case XC_BUTTON:
				pObj = new XCButton((HELE)handle);
				break;
			case XC_EDIT:
				pObj = new XCEdit(handle);
				break;
			case XC_EDITOR:
				pObj = new XCEditor(handle);
				break;
			case XC_RICHEDIT:
				break;
			case XC_COMBOBOX:
				pObj = new XCComboBox(handle);
				break;
			case XC_SCROLLBAR:
				pObj = new XCScrollBar(handle);
				break;
			case XC_SCROLLVIEW:
				pObj = new XCScrollView(handle);
				break;
			case XC_LIST:
				pObj = new XCList(handle);
				break;
			case XC_LISTBOX:
				pObj = new XCListBox(handle);
				break;
			case XC_LISTVIEW:
				pObj = new XCListView(handle);
				break;
			case XC_TREE:
				pObj = new XCTree(handle);
				break;
			case XC_MENUBAR:
				pObj = new XCMenuBar(handle);
				break;
			case XC_SLIDERBAR:
				pObj = new XCSliderBar(handle);
				break;
			case XC_PROGRESSBAR:
				pObj = new XCProgressBar(handle);
				break;
			case XC_TOOLBAR:
				pObj = new XCToolBar(handle);
				break;
			case XC_MONTHCAL:
				pObj = new XCMonthCal(handle);
				break;
			case XC_DATETIME:
				pObj = new XCDateTime(handle);
				break;
			case XC_PROPERTYGRID:
				break;
			case XC_EDIT_COLOR:
				break;
			case XC_EDIT_SET:
				break;
			case XC_TABBAR:
				pObj = new XCTabBar(handle);
				break;
			case XC_TEXTLINK:
				pObj = new XCTextLink(handle);
				break;
			case XC_PANE:
				pObj = new XCPane(handle);
				break;
			case XC_PANE_SPLIT:
				pObj = new XCWidget(handle);
				break;
			case XC_MENUBAR_BUTTON:
				pObj = new XCButton(handle);
				break;
			case XC_EDIT_FILE:
				break;
			case XC_EDIT_FOLDER:
				break;
			case XC_LIST_HEADER:
				break;
			case XC_SHAPE:
				break;
			case XC_SHAPE_TEXT:
				break;
			case XC_SHAPE_PICTURE:
				break;
			case XC_SHAPE_RECT:
				break;
			case XC_SHAPE_ELLIPSE:
				break;
			case XC_SHAPE_LINE:
				break;
			case XC_SHAPE_GROUPBOX:
				break;
			case XC_SHAPE_GIF:
				break;
			case XC_SHAPE_TABLE:
				break;
			case XC_MENU:
				pObj = new XCMenu(handle);
				break;
			case XC_IMAGE:
				pObj = new XCImage(handle);
				break;
				//case XC_IMAGE_TEXTURE:
				//	break;
			case XC_HDRAW:
				pObj = new XCDraw((HDRAW)handle);
				break;
			case XC_FONT:
				pObj = new XCFont((HFONTX)handle);
				break;
			case XC_IMAGE_FRAME:
				pObj = new XCImage((HIMAGE)handle);
				break;
			case XC_SVG:
				pObj = new XCSvg((HSVG)handle);
				break;
			case XC_LAYOUT_OBJECT:
				break;
			case XC_ADAPTER:
				break;
			case XC_ADAPTER_TABLE:
				pObj = new XCAdapterTable(handle);
				break;
			case XC_ADAPTER_TREE:
				pObj = new XCAdapterTree(handle);
				break;
			case XC_ADAPTER_LISTVIEW:
				pObj = new XCAdapterListView(handle);
				break;
			case XC_ADAPTER_MAP:
				pObj = new XCAdapterMap(handle);
				break;
			case XC_BKINFOM:
				pObj = new XCBkManager(handle);
				break;
			case XC_LAYOUT_LISTVIEW:
				break;
			case XC_LAYOUT_LIST:
				break;
			case XC_LAYOUT_OBJECT_GROUP:
				break;
			case XC_LAYOUT_OBJECT_ITEM:
				break;
			case XC_LAYOUT_PANEL:
				break;
			case XC_LAYOUT_BOX:
				break;
			case XC_ANIMATION_SEQUENCE:
				break;
			case XC_ANIMATION_GROUP:
				break;
			case XC_ANIMATION_ITEM:
				break;
			default:
				break;
			}
			return pObj;
		}

		XCObject* CastObject(HXCGUI handle)
		{
			if (!handle)
				return nullptr;
			XCObject* pObj = nullptr;
			pObj = this->FindObject(handle);
			if (pObj) {
				return pObj;
			}

			pObj = NewObject(handle);
			if (!pObj) {
				return nullptr;
			}

			m_mObjects[handle] = pObj;
			return pObj;
		}

		XCObject* CastObject(const XCObject& obj) {
			return CastObject(obj.GetHandle());
		}

		XCObject* CastObject(const XCObject* pObj) {
			return CastObject(pObj->GetHandle());
		}
		
	protected:
		std::map<HXCGUI, XCObject*> m_mObjects;
	};


}