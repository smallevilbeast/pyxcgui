#pragma once
#include "pch.h"
#include "XCObject.hpp"

namespace xcgui {

	class XCLayoutBox :virtual public XCObject
	{
	public:
		XCLayoutBox() {

		}
		XCLayoutBox(HXCGUI handle)
		{
			m_handle = handle;
		}
		// 布局盒子_启用水平
		void EnableHorizon(bool bEnable) {
			XLayoutBox_EnableHorizon(m_handle, bEnable);
		 }
		  
		// 布局盒子_启用自动换行
		void EnableAutoWrap(bool bEnable) {
			XLayoutBox_EnableAutoWrap(m_handle, bEnable);
		}

		// 布局盒子_启用溢出隐藏
		void EnableOverflowHide(bool bEnable) {
			XLayoutBox_EnableOverflowHide(m_handle, bEnable);
		}

		// 布局盒子_置水平对齐
		void SetAlignH(layout_align_ align) {
			XLayoutBox_SetAlignH(m_handle, align);
		}

		// 布局盒子_置垂直对齐
		void SetAlignV(layout_align_ align) {
			XLayoutBox_SetAlignV(m_handle, align);
		}

		//  布局盒子_置对齐基线
		void SetAlignBaseline(layout_align_axis_ align) {
			XLayoutBox_SetAlignBaseline(m_handle, align);
		}

		// 布局盒子_置间距
		void SetSpace(int space) {
			XLayoutBox_SetSpace(m_handle, space);
		}

	    // 布局盒子_置行距
		void SetSpaceRow(int space) {
			XLayoutBox_SetSpaceRow(m_handle, space);
		}
	};
}