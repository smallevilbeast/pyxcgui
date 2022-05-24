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


}