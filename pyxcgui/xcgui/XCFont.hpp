#pragma once
#include "pch.h"
#include "XCObject.hpp"
#include "XCWindow.hpp"

namespace xcgui {

	class XCFont : public XCObject
	{
	public:
		XCFont()
			: XCObject()
		{
		}

		XCFont(HFONTX handle)
			:XCObject((HXCGUI)handle)
		{
		}



		HFONTX getFontHandle() const
		{
			return (HFONTX)m_handle;
		}

		// �����Ų�����,����������Ԫ�ع�����,���Զ��ͷ�. 
		XCFont(int size) { 
			m_handle = XFont_Create(size); 
		}

		// �����Ų�����,����������Ԫ�ع�����,���Զ��ͷ�.  
		HFONTX Create(int size) { 
			m_handle = XFont_Create(size);
			return (HFONTX)m_handle;
		}

		// �����Ų�����
		HFONTX CreateEx(const std::wstring& name = L"����", int size = 12, int style = fontStyle_regular) {
			m_handle = XFont_CreateEx(name.c_str(), size, style);
			return (HFONTX)m_handle;
		}

		// �����Ų����� D2D��֧�ִ˽ӿ�
		HFONTX CreateFromLOGFONTW(LOGFONTW* pFontInfo) { 
			m_handle = XFont_CreateFromLOGFONTW(pFontInfo);
			return (HFONTX)m_handle;
		}

		// �����Ų����������HFONT����,  D2D��֧�ִ˽ӿ� 
		HFONTX CreateFromHFONT(HFONT hFont) { 
			m_handle = XFont_CreateFromHFONT(hFont);
			return (HFONTX)m_handle;
		}
		
		// �����Ų������GDI+����(Font), D2D��֧�ִ˽ӿ�
		HFONTX CreateFromFont(void* pFont) { 
			m_handle = XFont_CreateFromFont(pFont);
			return (HFONTX)m_handle;
		}

		//  ����������ļ�
		HFONTX CreateFromFile(const std::wstring& fontFile, int size = 12, int style = fontStyle_regular) { 
			m_handle = XFont_CreateFromFile(fontFile.c_str(), size, style);
			return (HFONTX)m_handle;
		}
		

		// �������ڴ�
		HFONTX CreateFromMem(const std::string& data, int fontSize = 12, int style = fontStyle_regular) { 
			m_handle = XFont_CreateFromMem((void*)data.c_str(), data.size(), fontSize, style);
			return (HFONTX)m_handle;
		}

		// ��������Դ
		HFONTX CreateFromRes(int id, const wchar_t* pType, int fontSize, int style, HMODULE hModule = NULL) { 
			m_handle = XFont_CreateFromRes(id, pType, fontSize, style, hModule);
			return (HFONTX)m_handle;
		}

		// �Ƿ��Զ�����
		void EnableAutoDestroy(bool bEnable) { 
			XFont_EnableAutoDestroy((HFONTX)m_handle, bEnable);
		}

		
		// ��ȡ����,����GDI+ Fontָ��
		void* GetFont() { 
			XFont_GetFont((HFONTX)m_handle); 
		}

		// ��ȡ������Ϣ.  
		void GetFontInfo(font_info_* pInfo) { 
			XFont_GetFontInfo((HFONTX)m_handle, pInfo); 
		}

		// ��ȡ����LOGFONTW  
		bool GetLOGFONTW(HDC hdc, LOGFONTW* pOut) { 
			return XFont_GetLOGFONTW((HFONTX)m_handle, hdc, pOut);
		}

		// ǿ�������Ų�����,����ʹ��, ����ʹ�� 
		void Destroy() { 
			XFont_Destroy((HFONTX)m_handle);
		}

		// �������ü���.  
		void AddRef() { 
			XFont_AddRef((HFONTX)m_handle); 
		}

		// ��ȡ���ü���.  
		int GetRefCount() { 
			return XFont_GetRefCount((HFONTX)m_handle);
		}

		// �ͷ����ü���,�����ü���Ϊ0ʱ,�Զ�����.  
		void Release() { 
			XFont_Release((HFONTX)m_handle); 
		}

	};

}