#pragma once
#include "pch.h"
#include "xcgui/XCObject.hpp"

namespace xcgui {


	class XCAnimationItem : public XCObject
	{

	public:
		XCAnimationItem(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCAnimationItem() = default;

		//@参数 hAnimationItem 动画项句柄
		//@参数 bEnable 是否启用
		//@别名 动画项_启用自动销毁()
		void EnableAutoDestroy(bool bEnable) {
			XAnimaItem_EnableAutoDestroy(m_handle, bEnable);
		}

		//@备注 当动画项完成后自动释放
		//@参数 hAnimationItem 动画项句柄
		//@参数 bEnable 是否启用
		//@别名 动画项_启用完成释放()
		void EnableCompleteRelease(bool bEnable) {
			XAnimaItem_EnableCompleteRelease(m_handle, bEnable);
		}


		//@参数 hAnimationItem 动画项句柄
		//@参数 callback 回调函数
		//@别名 动画项_置回调()
		void SetCallback(funAnimationItem callback) {
			XAnimaItem_SetCallback(m_handle, callback);
		}


		//@参数 hAnimationItem 动画项句柄
		//@参数 nUserData 用户数据
		//@别名 动画项_置用户数据()
		void SetUserData(vint nUserData) {
			XAnimaItem_SetUserData(m_handle, nUserData);
		}

		//@参数 hAnimationItem 动画项句柄
		//@返回 返回用户数据
		//@别名 动画项_取用户数据()
		vint GetUserData() {
			XAnimaItem_GetUserData(m_handle);
		}

		//@备注 设置旋转中心点坐标
		//@参数 hAnimationRotate 动画旋转项句柄
		//@参数 x 坐标X
		//@参数 y 坐标Y
		//@参数 bOffset true:相对于自身中心点偏移, false:绝对坐标
		//@返回 如果成功返回true,否则返回false
		//@别名 动画旋转_置中心()
		void RotateSetCenter(float x, float y, bool bOffset = false) {
			XAnimaRotate_SetCenter(m_handle, x, y, bOffset);
		}


		//@备注 设置缩放起点, 确定延伸方向
		//@参数 hAnimationScale 动画缩放项句柄
		//@参数 position 位置
		//@返回 如果成功返回true,否则返回false
		//@别名 动画缩放_置延伸位置()
		void ScaleSetPosition(position_flag_ position) {
			XAnimaScale_SetPosition(m_handle, position);
		}


		//@备注 此接口可独立设置x轴移动或y轴移动
		//@参数 hAnimationMove 动画移动项句柄
		//@参数 flags @ref animation_move_x : X轴移动, @ref animation_move_y : Y轴移动, 可组合使用, @ref animation_move_
		//@别名 动画移动_置标识()
		void MoveSetFlag(int flags) {
			return XAnimaMove_SetFlag(m_handle, flags);
		}


	};
}