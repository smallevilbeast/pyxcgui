#pragma once
#include "pch.h"
#include "XCAnimation.hpp"

namespace xcgui {


	class XCAnimationSequence : public XCAnimation
	{

	public:
		XCAnimationSequence(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCAnimationSequence() = default;

		XCAnimationSequence(HXCGUI objectHandle, int nLoopCount) {
			m_objectHandle = objectHandle;
			m_handle = XAnima_Create(objectHandle, nLoopCount);
		}

		//@备注 移动到目标位置, 默认以UI对象中心点为操作方式,避免出现坐标错位
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 x 终点位置X(对象左上角坐标)
		//@参数 y 终点位置Y(对象左上角坐标)
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@参数 ease_flag 缓动标识 @ref ease_flag_
		//@参数 bGoBack 是否返回; 当启用后:往返到起点,  起点->终点->起点
		//@返回 返回动画项句柄
		//@别名 动画_移动()
		HXCGUI Move(UINT duration, float x, float y, int nLoopCount = 1, int ease_flag = 0, bool bGoBack = false) {
			return XAnima_Move(m_handle, duration, x, y, nLoopCount, ease_flag, bGoBack);
		}


		//@备注 从指定位置移动到目标位置, 默认以UI对象中心点为操作方式,避免出现坐标错位
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 from_x 起点位置X(对象左上角坐标)
		//@参数 from_y 起点位置Y(对象左上角坐标)
		//@参数 to_x 终点位置X(对象左上角坐标)
		//@参数 to_y 终点位置Y(对象左上角坐标)
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@参数 ease_flag 缓动标识 @ref ease_flag_
		//@参数 bGoBack 是否返回; 当启用后:往返到起点,  起点->终点->起点
		//@返回 返回动画项句柄
		//@别名 动画_移动扩展()
		HXCGUI MoveEx(UINT duration, float from_x, float from_y, float to_x, float to_y, int nLoopCount = 1, int ease_flag = 0, bool bGoBack = false) {
			return XAnima_MoveEx(m_handle, duration, from_x, from_y, to_x, to_y, nLoopCount, ease_flag, bGoBack);
		}

		//@备注 旋转角度支持负数值, 因为负数可以控制反向旋转
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 angle 角度
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@参数 ease_flag 缓动标识 @ref ease_flag_
		//@参数 bGoBack 是否返回; 当启用后:往返到起点,  起点->终点->起点
		//@返回 返回动画项句柄
		//@别名 动画_旋转()
		HXCGUI Rotate(UINT duration, float angle, int nLoopCount = 1, int ease_flag = 0, bool bGoBack = false) {
			return XAnima_Rotate(m_handle, duration, angle, nLoopCount, ease_flag, bGoBack);
		}

		//@备注 指定起点和终点
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 from 起点角度
		//@参数 to 终点角度
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@参数 ease_flag 缓动标识 @ref ease_flag_
		//@参数 bGoBack 是否返回; 当启用后:往返到起点,  起点->终点->起点
		//@返回 返回动画项句柄
		//@别名 动画_旋转扩展()
		HXCGUI RotateEx(UINT duration, float from, float to, int nLoopCount = 1, int ease_flag = 0, bool bGoBack = false) {
			return XAnima_RotateEx(m_handle, duration, from, to, nLoopCount, ease_flag, bGoBack);
		}

		//@备注 缩放对象   默认以自身为中心缩放
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 scaleX X轴缩放比例
		//@参数 scaleY Y轴缩放比例
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@参数 ease_flag 缓动标识  @ref ease_flag_
		//@参数 bGoBack 是否返回; 当启用后:往返到起点,  起点->终点->起点
		//@返回 返回动画项句柄
		//@别名 动画_缩放()
		HXCGUI Scale(UINT duration, float scaleX, float scaleY, int nLoopCount = 0, int ease_flag = 0, bool bGoBack = true) {
			return XAnima_Scale(m_handle, duration, scaleX, scaleY, nLoopCount, ease_flag, bGoBack);
		}

		//@备注 修改UI对象大小,默认向右延伸
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 width 宽度
		//@参数 height 高度
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@参数 ease_flag 缓动标识 @ref ease_flag_
		//@参数 bGoBack 是否返回; 当启用后:往返到起点,  起点->终点->起点
		//@返回 返回动画项句柄
		//@别名 动画_缩放大小()
		HXCGUI ScaleSize(UINT duration, float width, float height, int nLoopCount = 1, int ease_flag = 0, bool bGoBack = false) {
			return XAnima_ScaleSize(m_handle, duration, width, height, nLoopCount, ease_flag, bGoBack);
		}

		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 alpha 透明度
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@参数 ease_flag 缓动标识 @ref ease_flag_
		//@参数 bGoBack 是否返回; 当启用后:往返到起点,  起点->终点->起点
		//@返回 返回动画项句柄
		//@别名 动画_透明度()
		HXCGUI Alpha(UINT duration, BYTE alpha, int nLoopCount = 0, int ease_flag = 0, bool bGoBack = false) {
			return XAnima_Alpha(m_handle, duration, alpha, nLoopCount, ease_flag, bGoBack);
		}

		//@备注 从指定透明度到目标透明度
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 from_alpha 起始透明度
		//@参数 to_alpha 终止透明度
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@参数 ease_flag 缓动标识  @ref ease_flag_
		//@参数 bGoBack 是否返回; 当启用后:往返到起点,  起点->终点->起点
		//@返回 返回动画项句柄
		//@别名 动画_透明度扩展()
		HXCGUI AlphaEx(UINT duration, BYTE from_alpha, BYTE to_alpha, int nLoopCount = 0, int ease_flag = 0, bool bGoBack = false) {
			return XAnima_AlphaEx(m_handle, duration, from_alpha, to_alpha, nLoopCount, ease_flag, bGoBack);
		}

		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 color 颜色
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@参数 ease_flag 缓动标识 @ref ease_flag_
		//@参数 bGoBack 是否返回; 当启用后:往返到起点,  起点->终点->起点
		//@返回 返回动画项句柄
		//@别名 动画_颜色()
		HXCGUI Color(UINT duration, COLORREF color, int nLoopCount = 0, int ease_flag = 0, bool bGoBack = false) {
			return XAnima_Color(m_handle, duration, color, nLoopCount, ease_flag, bGoBack);
		}

		//@备注 从指定颜色到目标颜色
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 from 起点颜色
		//@参数 to 终点颜色
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@参数 ease_flag 缓动标识 @ref ease_flag_
		//@参数 bGoBack 是否返回; 当启用后:往返到起点,  起点->终点->起点
		//@返回 返回动画项句柄
		//@别名 动画_颜色扩展()
		HXCGUI ColorEx(UINT duration, COLORREF from, COLORREF to, int nLoopCount = 0, int ease_flag = 0, bool bGoBack = false) {
			return XAnima_ColorEx(m_handle, duration, from, to, nLoopCount, ease_flag, bGoBack);
		}


		//@备注 修改布局宽度属性
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 nType 布局宽度类型
		//@参数 width 布局宽度
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@参数 ease_flag 缓动标识  @ref ease_flag_
		//@参数 bGoBack 是否返回; 当启用后:往返到起点,  起点->终点->起点
		//@返回 返回动画项句柄
		//@别名 动画_布局宽度()
		HXCGUI LayoutWidth(UINT duration, layout_size_ nType, float width, int nLoopCount = 1, int ease_flag = 0, bool bGoBack = false) {
			return XAnima_LayoutWidth(m_handle, duration, nType, width, nLoopCount, ease_flag, bGoBack);
		}

		//@备注 修改布局高度属性
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 nType 布局高度类型
		//@参数 height 布局高度
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@参数 ease_flag 缓动标识  @ref ease_flag_
		//@参数 bGoBack 是否返回; 当启用后:往返到起点,  起点->终点->起点
		//@返回 返回动画项句柄
		//@别名 动画_布局高度()
		HXCGUI LayoutHeight(UINT duration, layout_size_ nType, float height, int nLoopCount = 1, int ease_flag = 0, bool bGoBack = false) {
			return XAnima_LayoutHeight(m_handle, duration, nType, height, nLoopCount, ease_flag, bGoBack);
		}


		//@备注 修改布局宽度和高度
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 nWidthType 布局宽度类型, @ref layout_size_disable : 禁用宽度动画
		//@参数 width 布局宽度
		//@参数 nHeightType 布局高度类型, @ref layout_size_disable : 禁用高度动画
		//@参数 height 布局高度
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@参数 ease_flag 缓动标识  @ref ease_flag_
		//@参数 bGoBack 是否返回; 当启用后:往返到起点,  起点->终点->起点
		//@返回 返回动画项句柄
		//@别名 动画_布局大小()
		HXCGUI LayoutSize(UINT duration, layout_size_ nWidthType, float width, layout_size_ nHeightType, float height, int nLoopCount = 0, int ease_flag = 0, bool bGoBack = true) {
			return XAnima_LayoutSize(m_handle, duration, nWidthType, width, nHeightType, height, nLoopCount, ease_flag, bGoBack);
		}


		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@返回 返回动画项句柄
		//@别名 动画_延迟()
		HXCGUI Delay(float duration) {
			return XAnima_Delay(m_handle, duration);
		}


		//@备注 可以作为一个空动画, 然后在回调里处理自己的算法
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@参数 ease_flag 缓动标识  @ref ease_flag_
		//@参数 bGoBack 是否返回; 当启用后:往返到起点,  起点->终点->起点
		//@返回 返回动画项句柄
		//@别名 动画_延迟扩展()
		HXCGUI DelayEx(float duration, int nLoopCount = 1, int ease_flag = 0, bool bGoBack = false) {
			return XAnima_DelayEx(m_handle, duration, nLoopCount, ease_flag, bGoBack);
		}

		//@备注 显示或隐藏UI对象
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 bShow 显示或隐藏
		//@返回 返回动画项句柄
		//@别名 动画_显示()
		HXCGUI Show(float duration, bool bShow) {
			return XAnima_Show(m_handle, duration, bShow);
		}


		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@返回 返回动画项句柄
		//@别名 动画_销毁UI对象()
		HXCGUI DestroyObjectUI(float duration) {
			return XAnima_DestroyObjectUI(m_handle, duration);
		}

	};
}