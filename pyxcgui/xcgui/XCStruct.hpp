#pragma once
#include "pch.h"

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

}