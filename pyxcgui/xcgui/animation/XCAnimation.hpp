#pragma once
#include "pch.h"
#include "xcgui/XCObject.hpp"

namespace xcgui {


	class XCAnimation : public XCObject
	{

	public:
		XCAnimation(HXCGUI handle)
		{
			m_handle = handle;
		}

		XCAnimation() = default;

		XCAnimation(HXCGUI obj, int loopCount) {

			m_handle = XAnima_Create(obj, loopCount);
		}

		//@备注 将动画加入动画系统中运行
		//@参数 hAnimationEx 动画序列或动画组句柄
		//@参数 hRedrawObjectUI 当更新UI时重绘的UI层;  UI对象句柄: 窗口句柄,元素句柄,形状句柄,SVG句柄
		//@别名 动画_运行()
		void XAnima_Run(HXCGUI hRedrawObjectUI);
		//@备注 将动画从动画系统中移除,并且自动销毁(如果启用自动销毁)
		//@参数 hAnimationEx 动画序列或动画组句柄
		//@参数 bEnd 是否立即执行到终点
		//@别名 动画_释放()
		BOOL XAnima_Release(BOOL bEnd = TRUE);
		//@备注 从动画系统中移除与指定UI对象关联的所有动画, 并且自动销毁(如果启用自动销毁)
		//@参数 hObjectUI 指定UI对象句柄
		//@参数 bEnd 是否立即执行到终点
		//@返回 返回释放动画数量
		//@别名 动画_释放扩展()
		int XAnima_ReleaseEx(HXCGUI hObjectUI, BOOL bEnd);
		//@备注 按顺序执行的动画列表
		//@参数 hObjectUI 绑定的UI对象,  UI对象句柄: 窗口句柄,元素句柄,形状句柄,SVG句柄
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@返回 返回句柄
		//@别名 动画_创建动画序列()
		HXCGUI XAnima_Create(HXCGUI hObjectUI, int nLoopCount = 1);
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
		HXCGUI XAnima_Move(HXCGUI hSequence, UINT duration, float x, float y, int nLoopCount = 1, int ease_flag = 0, BOOL bGoBack = FALSE);
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
		HXCGUI XAnima_MoveEx(HXCGUI hSequence, UINT duration, float from_x, float from_y, float to_x, float to_y, int nLoopCount = 1, int ease_flag = 0, BOOL bGoBack = FALSE);
		//@备注 旋转角度支持负数值, 因为负数可以控制反向旋转
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 angle 角度
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@参数 ease_flag 缓动标识 @ref ease_flag_
		//@参数 bGoBack 是否返回; 当启用后:往返到起点,  起点->终点->起点
		//@返回 返回动画项句柄
		//@别名 动画_旋转()
		HXCGUI XAnima_Rotate(HXCGUI hSequence, UINT duration, float angle, int nLoopCount = 1, int ease_flag = 0, BOOL bGoBack = FALSE);
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
		HXCGUI XAnima_RotateEx(HXCGUI hSequence, UINT duration, float from, float to, int nLoopCount = 1, int ease_flag = 0, BOOL bGoBack = FALSE);
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
		HXCGUI XAnima_Scale(HXCGUI hSequence, UINT duration, float scaleX, float scaleY, int nLoopCount = 0, int ease_flag = 0, BOOL bGoBack = TRUE);
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
		HXCGUI XAnima_ScaleSize(HXCGUI hSequence, UINT duration, float width, float height, int nLoopCount = 1, int ease_flag = 0, BOOL bGoBack = FALSE);
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 alpha 透明度
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@参数 ease_flag 缓动标识 @ref ease_flag_
		//@参数 bGoBack 是否返回; 当启用后:往返到起点,  起点->终点->起点
		//@返回 返回动画项句柄
		//@别名 动画_透明度()
		HXCGUI XAnima_Alpha(HXCGUI hSequence, UINT duration, BYTE alpha, int nLoopCount = 0, int ease_flag = 0, BOOL bGoBack = FALSE);
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
		HXCGUI XAnima_AlphaEx(HXCGUI hSequence, UINT duration, BYTE from_alpha, BYTE to_alpha, int nLoopCount = 0, int ease_flag = 0, BOOL bGoBack = FALSE);
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 color 颜色
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@参数 ease_flag 缓动标识 @ref ease_flag_
		//@参数 bGoBack 是否返回; 当启用后:往返到起点,  起点->终点->起点
		//@返回 返回动画项句柄
		//@别名 动画_颜色()
		HXCGUI XAnima_Color(HXCGUI hSequence, UINT duration, COLORREF color, int nLoopCount = 0, int ease_flag = 0, BOOL bGoBack = FALSE);
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
		HXCGUI XAnima_ColorEx(HXCGUI hSequence, UINT duration, COLORREF from, COLORREF to, int nLoopCount = 0, int ease_flag = 0, BOOL bGoBack = FALSE);
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
		HXCGUI XAnima_LayoutWidth(HXCGUI hSequence, UINT duration, layout_size_ nType, float width, int nLoopCount = 1, int ease_flag = 0, BOOL bGoBack = FALSE);
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
		HXCGUI XAnima_LayoutHeight(HXCGUI hSequence, UINT duration, layout_size_ nType, float height, int nLoopCount = 1, int ease_flag = 0, BOOL bGoBack = FALSE);
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
		HXCGUI XAnima_LayoutSize(HXCGUI hSequence, UINT duration, layout_size_ nWidthType, float width, layout_size_ nHeightType, float height, int nLoopCount = 0, int ease_flag = 0, BOOL bGoBack = TRUE);
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@返回 返回动画项句柄
		//@别名 动画_延迟()
		HXCGUI XAnima_Delay(HXCGUI hSequence, float duration);
		//@备注 可以作为一个空动画, 然后在回调里处理自己的算法
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@参数 ease_flag 缓动标识  @ref ease_flag_
		//@参数 bGoBack 是否返回; 当启用后:往返到起点,  起点->终点->起点
		//@返回 返回动画项句柄
		//@别名 动画_延迟扩展()
		HXCGUI XAnima_DelayEx(HXCGUI hSequence, float duration, int nLoopCount = 1, int ease_flag = 0, BOOL bGoBack = FALSE);
		//@备注 显示或隐藏UI对象
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@参数 bShow 显示或隐藏
		//@返回 返回动画项句柄
		//@别名 动画_显示()
		HXCGUI XAnima_Show(HXCGUI hSequence, float duration, BOOL bShow);
		//@参数 hSequence 动画序列句柄
		//@参数 duration 持续时间
		//@返回 返回动画项句柄
		//@别名 动画_销毁UI对象()
		HXCGUI XAnima_DestroyObjectUI(HXCGUI hSequence, float duration);
		//@备注 TRUE:自动销毁 FALSE:手动销毁
		//@参数 hAnimationEx 动画序列或动画组句柄
		//@参数 bEnable 是否启用
		//@别名 动画_启用自动销毁()
		void XAnima_EnableAutoDestroy(BOOL bEnable);
		//@备注 获取动画关联的UI对象
		//@参数 hAnimationEx 动画序列或动画组或动画项句柄
		//@返回 返回UI对象句柄
		//@别名 动画_取UI对象()
		HXCGUI XAnima_GetObjectUI(HXCGUI hAnimationEx);
		//@参数 hAnimationEx 动画序列或动画组句柄
		//@参数 callback 回调函数
		//@别名 动画_置回调()
		void XAnima_SetCallBack(funAnimation callback);
		//@参数 hAnimationEx 动画序列或动画组句柄
		//@参数 nUserData 用数据
		//@别名 动画_置用户数据()
		void XAnima_SetUserData(vint nUserData);
		//@参数 hAnimationEx 动画序列或动画组句柄
		//@返回 返回用户数据
		//@别名 动画_取用户数据()
		vint XAnima_GetUserData(HXCGUI hAnimationEx);
		//@参数 hAnimationEx 动画序列或动画组句柄
		//@别名 动画_停止()
		void XAnima_Stop(HXCGUI hAnimationEx);
		//@参数 hAnimationEx 动画序列或动画组句柄
		//@别名 动画_开始()
		void XAnima_Start(HXCGUI hAnimationEx);
		//@备注 未实现功能
		//@参数 hAnimationEx 动画序列或动画组句柄
		//@别名 动画_暂停()
		void XAnima_Pause(HXCGUI hAnimationEx);
		//@分组}
		//@分组{  动画特效

		//@备注 动画同步组, 当组中动画序列全部完成后, 重新开始; 当遇到无限循环项时,直至其他序列完成后终止循环,避免出现无法到达终点,无法返回头部进行同步
		//@参数 nLoopCount 动画循环次数, 0:无限循环
		//@返回 返回动画组句柄
		//@别名 动画组_创建()
		HXCGUI XAnimaGroup_Create(int nLoopCount = 1);
		//@备注 将动画序列添加到组中
		//@参数 hGroup 动画组句柄
		//@参数 hSequence 动画序列句柄
		//@别名 动画组_添加项()
		void XAnimaGroup_AddItem(HXCGUI hGroup, HXCGUI hSequence);
		//@分组}
		//@分组{  动画特效

		//@参数 hAnimationItem 动画项句柄
		//@参数 bEnable 是否启用
		//@别名 动画项_启用自动销毁()
		void XAnimaItem_EnableAutoDestroy(HXCGUI hAnimationItem, BOOL bEnable);
		//@备注 当动画项完成后自动释放
		//@参数 hAnimationItem 动画项句柄
		//@参数 bEnable 是否启用
		//@别名 动画项_启用完成释放()
		void XAnimaItem_EnableCompleteRelease(HXCGUI hAnimationItem, BOOL bEnable);
		//@参数 hAnimationItem 动画项句柄
		//@参数 callback 回调函数
		//@别名 动画项_置回调()
		void XAnimaItem_SetCallback(HXCGUI hAnimationItem, funAnimationItem callback);
		//@参数 hAnimationItem 动画项句柄
		//@参数 nUserData 用户数据
		//@别名 动画项_置用户数据()
		void XAnimaItem_SetUserData(HXCGUI hAnimationItem, vint nUserData);
		//@参数 hAnimationItem 动画项句柄
		//@返回 返回用户数据
		//@别名 动画项_取用户数据()
		vint XAnimaItem_GetUserData(HXCGUI hAnimationItem);
		//@分组}
		//@分组{  动画特效

		//@备注 设置旋转中心点坐标
		//@参数 hAnimationRotate 动画旋转项句柄
		//@参数 x 坐标X
		//@参数 y 坐标Y
		//@参数 bOffset TRUE:相对于自身中心点偏移, FALSE:绝对坐标
		//@返回 如果成功返回TRUE,否则返回FALSE
		//@别名 动画旋转_置中心()
		void XAnimaRotate_SetCenter(HXCGUI hAnimationRotate, float x, float y, BOOL bOffset = FALSE);
		//@分组}
		//@分组{  动画特效

		//@备注 设置缩放起点, 确定延伸方向
		//@参数 hAnimationScale 动画缩放项句柄
		//@参数 position 位置
		//@返回 如果成功返回TRUE,否则返回FALSE
		//@别名 动画缩放_置延伸位置()
		void XAnimaScale_SetPosition(HXCGUI hAnimationScale, position_flag_ position);
		//@分组}
		//@分组{  动画特效

		//@备注 此接口可独立设置x轴移动或y轴移动
		//@参数 hAnimationMove 动画移动项句柄
		//@参数 flags @ref animation_move_x : X轴移动, @ref animation_move_y : Y轴移动, 可组合使用, @ref animation_move_
		//@别名 动画移动_置标识()
		void XAnimaMove_SetFlag(HXCGUI hAnimationMove, int flags);

	};
}