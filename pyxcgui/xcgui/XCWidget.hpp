#pragma once
#include "pch.h"
#include "XCObjectUI.hpp"
#include "XCStruct.hpp"

namespace xcgui {

	class XCLayoutSize
	{
	public:
		XCLayoutSize() = default;
		XCLayoutSize(layout_size_ sizeType, int size) 
			:sizeType(sizeType)
			, size(size)
		{

		}

		layout_size_ sizeType;
		int size;
	};


	class XCWidget : virtual public XCObjectUI
	{
	public:
		XCWidget() 
			:XCObjectUI()
		{

		}
		XCWidget(HXCGUI handle)
		{
			m_handle = handle;
		}
		// 是否显示
		bool IsShow() 
		{
			return XWidget_IsShow(m_handle);
		}

		// 显示
		void Show(bool bShow)
		{
			XWidget_Show(m_handle, bShow);
		}

		// 启用布局控制
		void EnableLayoutControl(bool bEnable)
		{
			XWidget_EnableLayoutControl(m_handle, bEnable);
		}

		// 是否布局控制
		bool IsLayoutControl()
		{
			return XWidget_IsLayoutControl(m_handle);
		}

		// todo 取父元素
		HELE GetParentEle()	const 
		{
			if (!m_handle)
				return nullptr;

			auto eleHandle = XWidget_GetParentEle(m_handle);
			return eleHandle;
		}

		// todo 获取父对象,父可能是元素或窗口,通过此函数可以检查是否有父
		HXCGUI getParent() const 
		{
			if (!m_handle)
				return nullptr;

			return XWidget_GetParent(m_handle);
		}


		// 取窗口句柄系统
		uintptr_t GetHWND()
		{
			return (uintptr_t)XWidget_GetHWND(m_handle);
		}

		// 取窗口
		HWINDOW GetWindow() const 
		{
			if (!m_handle)
				return nullptr;

			return XWidget_GetHWINDOW(m_handle);
		}

		// 设置元素ID
		void SetID(int nID)
		{
			XWidget_SetID(m_handle, nID);
		}


		// 获取元素ID
		int GetID()
		{
			return XWidget_GetID(m_handle);
		}

		// 设置元素UID, 全局唯一标识符
		void SetUID(int nUID)
		{
			XWidget_SetUID(m_handle, nUID);
		}

		// 获取元素UID,全局唯一标识符
		int GetUID()
		{
			return XWidget_GetUID(m_handle);
		}

		// 设置元素name
		void SetName(const std::wstring& name)
		{
			XWidget_SetName(m_handle, name.c_str());
		}


		// 获取元素name
		std::wstring GetName()
		{
			auto pName = XWidget_GetName(m_handle);
			if (!pName) {
				return L"";
			}
			return pName;
		}
		// 强制换行
		void LayoutEnableWrap(bool bWrap)
		{
			XWidget_LayoutItem_EnableWrap(m_handle, bWrap);
		}

		// 根据水平垂直布局变换, 交换属性(宽度,高度,最小宽度,最小高度)
		void LayoutEnableSwap(bool bEnable)
		{
			XWidget_LayoutItem_EnableSwap(m_handle, bEnable);
		}


		// 向反方向对齐
		void LayoutEnableFloat(bool bFloat)
		{
			XWidget_LayoutItem_EnableFloat(m_handle, bFloat);
		}

		// 设置宽度
		void LayoutSetWidth(layout_size_ sizeType, int size=0)
		{
			XWidget_LayoutItem_SetWidth(m_handle, sizeType, size);
		}


		// 设置高度
		void LayoutSetHeight(layout_size_ sizeType, int size = 0)
		{
			XWidget_LayoutItem_SetHeight(m_handle, sizeType, size);
		}

		// 取宽度
		XCLayoutSize LayoutGetWidth()
		{
			XCLayoutSize layoutSize;
			XWidget_LayoutItem_GetWidth(m_handle, &layoutSize.sizeType, &layoutSize.size);
			return layoutSize;
		}

		// 取高度信息
		XCLayoutSize LayoutGetHeight()
		{
			XCLayoutSize layoutSize;
			XWidget_LayoutItem_GetHeight(m_handle, &layoutSize.sizeType, &layoutSize.size);
			return layoutSize;
		}

		// 根据水平垂直轴变化对齐
		void LayoutSetAlign(layout_align_axis_ nAlign)
		{
			XWidget_LayoutItem_SetAlign(m_handle, nAlign);
		}

		// 布局项_置外间距
		void LayoutSetMargin(int left, int top, int right, int bottom)
		{
			XWidget_LayoutItem_SetMargin(m_handle, left, top, right, bottom);
		}

		// 布局项_取外间距
		XCRect LayoutGetMargin()
		{
			XCRect margin;
			XWidget_LayoutItem_GetMargin(m_handle, (marginSize_*)&margin);
			return margin;
		}

		// 限制大小仅针对缩放有效(自动, 填充父, 比例, 百分比)
		void LayoutSetMinSize(int width, int height)
		{
			XWidget_LayoutItem_SetMinSize(m_handle, width, height);
		}

		// 相对位置, 值大于等于0有效
		void LayoutSetPosition(int left, int top, int right, int bottom)
		{
			XWidget_LayoutItem_SetPosition(m_handle, left, top, right, bottom);
		}
	};


}