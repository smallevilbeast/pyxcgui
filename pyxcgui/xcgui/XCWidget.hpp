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
		// �Ƿ���ʾ
		bool IsShow() 
		{
			return XWidget_IsShow(m_handle);
		}

		// ��ʾ
		void Show(bool bShow)
		{
			XWidget_Show(m_handle, bShow);
		}

		// ���ò��ֿ���
		void EnableLayoutControl(bool bEnable)
		{
			XWidget_EnableLayoutControl(m_handle, bEnable);
		}

		// �Ƿ񲼾ֿ���
		bool IsLayoutControl()
		{
			return XWidget_IsLayoutControl(m_handle);
		}

		// todo ȡ��Ԫ��
		HELE GetParentEle()	const 
		{
			if (!m_handle)
				return nullptr;

			auto eleHandle = XWidget_GetParentEle(m_handle);
			return eleHandle;
		}

		// todo ��ȡ������,��������Ԫ�ػ򴰿�,ͨ���˺������Լ���Ƿ��и�
		HXCGUI getParent() const 
		{
			if (!m_handle)
				return nullptr;

			return XWidget_GetParent(m_handle);
		}


		// ȡ���ھ��ϵͳ
		uintptr_t GetHWND()
		{
			return (uintptr_t)XWidget_GetHWND(m_handle);
		}

		// ȡ����
		HWINDOW GetWindow() const 
		{
			if (!m_handle)
				return nullptr;

			return XWidget_GetHWINDOW(m_handle);
		}

		// ����Ԫ��ID
		void SetID(int nID)
		{
			XWidget_SetID(m_handle, nID);
		}


		// ��ȡԪ��ID
		int GetID()
		{
			return XWidget_GetID(m_handle);
		}

		// ����Ԫ��UID, ȫ��Ψһ��ʶ��
		void SetUID(int nUID)
		{
			XWidget_SetUID(m_handle, nUID);
		}

		// ��ȡԪ��UID,ȫ��Ψһ��ʶ��
		int GetUID()
		{
			return XWidget_GetUID(m_handle);
		}

		// ����Ԫ��name
		void SetName(const std::wstring& name)
		{
			XWidget_SetName(m_handle, name.c_str());
		}


		// ��ȡԪ��name
		std::wstring GetName()
		{
			auto pName = XWidget_GetName(m_handle);
			if (!pName) {
				return L"";
			}
			return pName;
		}
		// ǿ�ƻ���
		void LayoutEnableWrap(bool bWrap)
		{
			XWidget_LayoutItem_EnableWrap(m_handle, bWrap);
		}

		// ����ˮƽ��ֱ���ֱ任, ��������(���,�߶�,��С���,��С�߶�)
		void LayoutEnableSwap(bool bEnable)
		{
			XWidget_LayoutItem_EnableSwap(m_handle, bEnable);
		}


		// �򷴷������
		void LayoutEnableFloat(bool bFloat)
		{
			XWidget_LayoutItem_EnableFloat(m_handle, bFloat);
		}

		// ���ÿ��
		void LayoutSetWidth(layout_size_ sizeType, int size=0)
		{
			XWidget_LayoutItem_SetWidth(m_handle, sizeType, size);
		}


		// ���ø߶�
		void LayoutSetHeight(layout_size_ sizeType, int size = 0)
		{
			XWidget_LayoutItem_SetHeight(m_handle, sizeType, size);
		}

		// ȡ���
		XCLayoutSize LayoutGetWidth()
		{
			XCLayoutSize layoutSize;
			XWidget_LayoutItem_GetWidth(m_handle, &layoutSize.sizeType, &layoutSize.size);
			return layoutSize;
		}

		// ȡ�߶���Ϣ
		XCLayoutSize LayoutGetHeight()
		{
			XCLayoutSize layoutSize;
			XWidget_LayoutItem_GetHeight(m_handle, &layoutSize.sizeType, &layoutSize.size);
			return layoutSize;
		}

		// ����ˮƽ��ֱ��仯����
		void LayoutSetAlign(layout_align_axis_ nAlign)
		{
			XWidget_LayoutItem_SetAlign(m_handle, nAlign);
		}

		// ������_������
		void LayoutSetMargin(int left, int top, int right, int bottom)
		{
			XWidget_LayoutItem_SetMargin(m_handle, left, top, right, bottom);
		}

		// ������_ȡ����
		XCRect LayoutGetMargin()
		{
			XCRect margin;
			XWidget_LayoutItem_GetMargin(m_handle, (marginSize_*)&margin);
			return margin;
		}

		// ���ƴ�С�����������Ч(�Զ�, ��丸, ����, �ٷֱ�)
		void LayoutSetMinSize(int width, int height)
		{
			XWidget_LayoutItem_SetMinSize(m_handle, width, height);
		}

		// ���λ��, ֵ���ڵ���0��Ч
		void LayoutSetPosition(int left, int top, int right, int bottom)
		{
			XWidget_LayoutItem_SetPosition(m_handle, left, top, right, bottom);
		}
	};


}