#pragma once
#include "pch.h"
#include "XCObject.hpp"

namespace xcgui {

	class XCImage : public XCObject
	{
	public:
		XCImage()
			: XCObject()
		{
		}

		XCImage(HIMAGE ele)
			:XCObject((HXCGUI)ele)
		{
		}


		HIMAGE getImageHandle() const
		{
			return (HIMAGE)m_handle;
		}

		// 加载从图片源
		HIMAGE loadSrc(HIMAGE hImageSrc) {
			m_handle = XImage_LoadSrc(hImageSrc);
			return (HIMAGE)m_handle;
		}

		// 加载从文件
		HIMAGE LoadFile(const std::wstring& fileName) { 
			m_handle = XImage_LoadFile(fileName.c_str()); 
			return (HIMAGE)m_handle;
		}

		// 加载图片从文件,自适应图片
		HIMAGE LoadFileAdaptive(const std::wstring& fileName, int leftSize, int topSize, int rightSize, int bottomSize) {
			m_handle = XImage_LoadFileAdaptive(fileName.c_str(), leftSize, topSize, rightSize, bottomSize);
			return (HIMAGE)m_handle;
		}

		// 加载图片,指定区位置及大小
		HIMAGE LoadFileRect(const std::wstring& fileName, int x, int y, int cx, int cy) {
			m_handle = XImage_LoadFileRect(fileName.c_str(), x, y, cx, cy);
			return (HIMAGE)m_handle;
		}




	};

}
