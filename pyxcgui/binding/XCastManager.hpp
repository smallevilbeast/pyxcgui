#pragma once
#include "pch.h"
#include "xcgui/window/XCWindow.hpp"
#include "xcgui/XCFont.hpp"
#include "xcgui/XCDraw.hpp"
#include "xcgui/bkmanager/XCBkManager.hpp"
#include "xcgui/XCImage.hpp"
#include "xcgui/XCImageSrc.hpp"
#include "xcgui/XCSvg.hpp"
#include "xcgui/element/XCButton.hpp"

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
				pObj = new XCWindow((HWINDOW)handle);
				break;
			case XC_MODALWINDOW:
				break;
			case XC_FRAMEWND:
				break;
			case XC_FLOATWND:
				break;
			case XC_COMBOBOXWINDOW:
				break;
			case XC_POPUPMENUWINDOW:
				break;
			case XC_POPUPMENUCHILDWINDOW:
				break;
			case XC_OBJECT_UI:
				return new XCObjectUI(handle);
				break;
			case XC_WIDGET_UI:
				return new XCWidget(handle);
				break;
			case XC_ELE:
				return new XCElement((HELE)handle);
				break;
			case XC_ELE_LAYOUT:
				break;
			case XC_LAYOUT_FRAME:
				break;
			case XC_BUTTON:
				return new XCButton((HELE)handle);
				break;
			case XC_EDIT:
				break;
			case XC_EDITOR:
				break;
			case XC_RICHEDIT:
				break;
			case XC_COMBOBOX:
				break;
			case XC_SCROLLBAR:
				break;
			case XC_SCROLLVIEW:
				break;
			case XC_LIST:
				break;
			case XC_LISTBOX:
				break;
			case XC_LISTVIEW:
				break;
			case XC_TREE:
				break;
			case XC_MENUBAR:
				break;
			case XC_SLIDERBAR:
				break;
			case XC_PROGRESSBAR:
				break;
			case XC_TOOLBAR:
				break;
			case XC_MONTHCAL:
				break;
			case XC_DATETIME:
				break;
			case XC_PROPERTYGRID:
				break;
			case XC_EDIT_COLOR:
				break;
			case XC_EDIT_SET:
				break;
			case XC_TABBAR:
				break;
			case XC_TEXTLINK:
				break;
			case XC_PANE:
				break;
			case XC_PANE_SPLIT:
				break;
			case XC_MENUBAR_BUTTON:
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
				break;
			case XC_IMAGE:
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
				break;
			case XC_ADAPTER_TREE:
				break;
			case XC_ADAPTER_LISTVIEW:
				break;
			case XC_ADAPTER_MAP:
				break;
			case XC_BKINFOM:
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