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


		//@备注 将动画加入动画系统中运行
		//@参数 hAnimationEx 动画序列或动画组句柄
		//@参数 hRedrawObjectUI 当更新UI时重绘的UI层;  UI对象句柄: 窗口句柄,元素句柄,形状句柄,SVG句柄
		//@别名 动画_运行()
		void Run(HXCGUI hRedRawObjectUI) {
			XAnima_Run(m_handle, hRedRawObjectUI);
		}
		//@备注 将动画从动画系统中移除,并且自动销毁(如果启用自动销毁)
		//@参数 hAnimationEx 动画序列或动画组句柄
		//@参数 bEnd 是否立即执行到终点
		//@别名 动画_释放()
		bool Release(bool bEnd = true) {
			return XAnima_Release(m_handle, bEnd);

		}
		//@备注 从动画系统中移除与指定UI对象关联的所有动画, 并且自动销毁(如果启用自动销毁)
		//@参数 hObjectUI 指定UI对象句柄
		//@参数 bEnd 是否立即执行到终点
		//@返回 返回释放动画数量
		//@别名 动画_释放扩展()
		static int ReleaseEx(HXCGUI objectUI, bool bEnd) {
			return XAnima_ReleaseEx(objectUI, bEnd);
		}



		//@备注 true:自动销毁 false:手动销毁
		//@参数 hAnimationEx 动画序列或动画组句柄
		//@参数 bEnable 是否启用
		//@别名 动画_启用自动销毁()
		void EnableAutoDestroy(bool bEnable) {
			XAnima_EnableAutoDestroy(m_handle, bEnable);
		}


		//@备注 获取动画关联的UI对象
		//@参数 hAnimationEx 动画序列或动画组或动画项句柄
		//@返回 返回UI对象句柄
		//@别名 动画_取UI对象()
		HXCGUI GetObjectUI() {
			return XAnima_GetObjectUI(m_handle);
		}

		//@参数 hAnimationEx 动画序列或动画组句柄
		//@参数 callback 回调函数
		//@别名 动画_置回调()
		void SetCallBack(funAnimation callback) {
			XAnima_SetCallback(m_handle, callback);
		}


		//@参数 hAnimationEx 动画序列或动画组句柄
		//@参数 nUserData 用数据
		//@别名 动画_置用户数据()
		void SetUserData(vint nUserData) {
			return XAnima_SetUserData(m_handle, nUserData);
		}


		//@参数 hAnimationEx 动画序列或动画组句柄
		//@返回 返回用户数据
		//@别名 动画_取用户数据()
		vint GetUserData() {
			return XAnima_GetUserData(m_handle);
		}

		//@参数 hAnimationEx 动画序列或动画组句柄
		//@别名 动画_停止()
		void Stop() {
			XAnima_Stop(m_handle);
		}


		//@参数 hAnimationEx 动画序列或动画组句柄
		//@别名 动画_开始()
		void Start() {
			XAnima_Start(m_handle);
		}

		//@备注 未实现功能
		//@参数 hAnimationEx 动画序列或动画组句柄
		//@别名 动画_暂停()
		void Pause() {
			XAnima_Pause(m_handle);
		}

	protected:
		HXCGUI m_objectHandle;
	};
}