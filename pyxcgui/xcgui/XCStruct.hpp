#pragma once
#include "pch.h"
#include "XCObject.hpp"

namespace xcgui {

	class XCPoint 
	{
	public:
		XCPoint() 
			:x(0)
			,y(0)
		{
		}
		XCPoint(int x, int y) 
			:x(x)
			,y(y)
		{

		}
	public:
		int x;
		int y;
	};

	class XCPointF
	{
	public:
		XCPointF()
			:x(0)
			, y(0)
		{
		}
		XCPointF(float x, float y)
			:x(x)
			, y(y)
		{

		}
	public:
		float x;
		float y;
	};

	class XCSize
	{
	public:
		XCSize()
			:width(0)
			, height(0)
		{
		}
		XCSize(int width, int height)
			:width(width)
			, height(height)
		{

		}
	public:
		int width;
		int height;
	};

	
	class XCRect
	{
	public:
		XCRect()
			:left(0)
			, top(0)
			, right(0)
			, bottom(0)
		{
		}
		XCRect(int left, int top, int right, int bottom)
			:left(left)
			,top(top)
			,right(right)
			,bottom(bottom)
		{

		}
	public:
		int left;
		int top;
		int right;
		int bottom;
	};

	class XCRectF
	{
	public:
		XCRectF()
			:left(0)
			, top(0)
			, right(0)
			, bottom(0)
		{
		}
		XCRectF(float left, float top, float right, float bottom)
			:left(left)
			, top(top)
			, right(right)
			, bottom(bottom)
		{

		}
	public:
		float left;
		float top;
		float right;
		float bottom;
	};

	class XCFontInfo {
	public:
		XCFontInfo()
			:name()
			,size(0)
			,style(0)
		{}
		XCFontInfo(const std::wstring& name, int size, int style)
			:name(name)
			, size(size)
			, style(style)
		{

		}

		std::wstring name;
		int size;
		int style;
	};

	class XCRotateInfo {
	public:
		XCRotateInfo()
			:angle(0)
			,x(0)
			,y(0)
			,offset(false)
		{}
		XCRotateInfo(float angle, float x, float y, bool offset) 
			:angle(angle)
			,x(x)
			,y(y)
			,offset(offset)
		{

		}

		float angle;
		float x;
		float y;
		bool offset;
	};

	class XCStrokeInfo {
	public:
		XCStrokeInfo()
			:color(0)
			,strokeWidth(0)
		{}
		XCStrokeInfo(COLORREF color, float strokeWidth) 
			:color(color)
			,strokeWidth(strokeWidth)
		{

		}

		COLORREF color;
		float strokeWidth;
	};


	class XCEvent {
	public:
		int eventType;
		XCObject* sender;
		XCPoint mouse;
		uintptr_t wParam;
		uintptr_t lParam;
	};

	class XCCareInfo {
	public:
		int x;
		int y;
		int width;
		int height;
		XCObject* pCare;
	};

	class XCShadowInfo {
	public:
		int size;
		int depth;
		int angeleSize;
		bool rightAngle;
		COLORREF color;
	};

}