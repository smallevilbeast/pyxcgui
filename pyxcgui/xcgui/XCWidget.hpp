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

	class XCWidgetLayout
	{
	public:
		XCWidgetLayout(HXCGUI* pHandle)
			:m_pHandle(pHandle)
		{

		}

		// 强制换行
		void EnableWrap(bool bWrap)
		{
			XWidget_LayoutItem_EnableWrap(*m_pHandle, bWrap);
		}

		// 根据水平垂直布局变换, 交换属性(宽度,高度,最小宽度,最小高度)
		void EnableSwap(bool bEnable)
		{
			XWidget_LayoutItem_EnableSwap(*m_pHandle, bEnable);
		}


		// 向反方向对齐
		void EnableFloat(bool bFloat)
		{
			XWidget_LayoutItem_EnableFloat(*m_pHandle, bFloat);
		}

		// 设置宽度
		void SetWidth(const XCLayoutSize& sizeInfo)
		{
			XWidget_LayoutItem_SetWidth(*m_pHandle, sizeInfo.sizeType, sizeInfo.size);
		}


		// 设置高度
		void SetHeight(const XCLayoutSize& sizeInfo)
		{
			XWidget_LayoutItem_SetHeight(*m_pHandle, sizeInfo.sizeType, sizeInfo.size);
		}

		// 取宽度
		XCLayoutSize GetWidth() 
		{
			XCLayoutSize layoutSize;
			XWidget_LayoutItem_GetWidth(*m_pHandle, &layoutSize.sizeType, &layoutSize.size);
			return layoutSize;
		}

		// 取高度信息
		XCLayoutSize GetHeight()
		{
			XCLayoutSize layoutSize;
			XWidget_LayoutItem_GetHeight(*m_pHandle, &layoutSize.sizeType, &layoutSize.size);
			return layoutSize;
		}

		// 根据水平垂直轴变化对齐
		void SetAlign(layout_align_axis_ nAlign)
		{
			XWidget_LayoutItem_SetAlign(*m_pHandle, nAlign);
		}

		// 布局项_置外间距
		void SetMargin(const XCRect& pRect)
		{
			XWidget_LayoutItem_SetMargin(*m_pHandle, pRect.left, pRect.top,
				pRect.right, pRect.bottom);
		}

		// 布局项_取外间距
		XCRect GetMargin()
		{
			XCRect margin;
			XWidget_LayoutItem_GetMargin(*m_pHandle, (marginSize_*)&margin);
			return margin;
		}

		// 限制大小仅针对缩放有效(自动, 填充父, 比例, 百分比)
		void SetMinSize(int width, int height)
		{
			XWidget_LayoutItem_SetMinSize(*m_pHandle, width, height);
		}

		// 相对位置, 值大于等于0有效
		void SetPosition(int left, int top, int right, int bottom)
		{
			XWidget_LayoutItem_SetPosition(*m_pHandle, left, top, right, bottom);
		}


	protected:
		HXCGUI* m_pHandle;

	};


	class XCWidget : public XCObjectUI
	{
	public:
		XCWidget() 
			:XCObjectUI(),
			m_layout(&m_handle)
		{

		}
		XCWidget(HXCGUI handle)
			:XCObjectUI(handle)
			, m_layout(&m_handle)
		{
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

	public:
		XCWidgetLayout m_layout;
	};


}