#pragma once
#include "pch.h"

namespace xcgui {
	class XCEase
	{
	public:
		//@备注 线性
	//@参数 pos 位置, 0.0f - 1.0f
	//@返回 返回计算结果
	//@别名 缓动_Linear()
		static float Linear(float pos) {
			return XEase_Linear(pos);
		}

		//@备注 二次方曲线
		//@参数 pos 位置, 0.0f - 1.0f
		//@参数 flag 缓动方式
		//@返回 返回计算结果
		//@别名 缓动_Quad()
		static float Quad(float pos, ease_type_ flag) {
			return XEase_Quad(pos, flag);
		}

		//@备注 三次方曲线  圆弧
		//@参数 pos 位置, 0.0f - 1.0f
		//@参数 flag 缓动方式
		//@返回 返回计算结果
		//@别名 缓动_Cubic()
		static float Cubic(float pos, ease_type_ flag) {
			return 	XEase_Cubic(pos, flag);
		}

		//@备注 四方曲线
		//@参数 pos 位置, 0.0f - 1.0f
		//@参数 flag 缓动方式
		//@返回 返回计算结果
		//@别名 缓动_Quart()
		static float Quart(float pos, ease_type_ flag) {
			return XEase_Quart(pos, flag);
		}

		//@备注 五次方曲线
		//@参数 pos 位置, 0.0f - 1.0f
		//@参数 flag 缓动方式
		//@返回 返回计算结果
		//@别名 缓动_Quint()
		static float Quint(float pos, ease_type_ flag) {
			return XEase_Quint(pos, flag);
		}


		//@备注 正弦曲线, 在末端变化
		//@参数 pos 位置, 0.0f - 1.0f
		//@参数 flag 缓动方式
		//@返回 返回计算结果
		//@别名 缓动_Sine()
		static float Sine(float pos, ease_type_ flag) {
			return XEase_Sine(pos, flag);
		}

		//@备注 突击曲线, 突然一下
		//@参数 pos 位置, 0.0f - 1.0f
		//@参数 flag 缓动方式
		//@返回 返回计算结果
		//@别名 缓动_Expo()
		static float Expo(float pos, ease_type_ flag) {
			return XEase_Expo(pos, flag); 
		}

		//@备注 圆环, 好比绕过一个圆环
		//@参数 pos 位置, 0.0f - 1.0f
		//@参数 flag 缓动方式
		//@返回 返回计算结果
		//@别名 缓动_Circ()
		static float Circ(float pos, ease_type_ flag) {
			return XEase_Circ(pos, flag);
		}


		//@备注 强力回弹
		//@参数 pos 位置, 0.0f - 1.0f
		//@参数 flag 缓动方式
		//@返回 返回计算结果
		//@别名 缓动_Elastic()
		static float Elastic(float pos, ease_type_ flag) {
			return XEase_Elastic(pos, flag);
		}

		//@备注 回弹, 比较缓慢
		//@参数 pos 位置, 0.0f - 1.0f
		//@参数 flag 缓动方式
		//@返回 返回计算结果
		//@别名 缓动_Back()
		static float Back(float pos, ease_type_ flag) {
			return 	XEase_Back(pos, flag);
		}

		//@备注 弹跳  模拟小球落地弹跳
		//@参数 pos 位置, 0.0f - 1.0f
		//@参数 flag 缓动方式
		//@返回 返回计算结果
		//@别名 缓动_Bounce()
		static float Bounce(float pos, ease_type_ flag) {
			return XEase_Bounce(pos, flag);
		}


		//@备注 全部缓动类型
		//@参数 pos 位置, 0.0f - 1.0f
		//@参数 flag 缓动方式 @ref ease_flag_
		//@返回 返回计算结果
		//@别名 缓动_扩展()
		static float Ex(float pos, int flag) {
			return XEase_Ex(pos, flag);
		}
	};
}