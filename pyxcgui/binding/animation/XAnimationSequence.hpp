#pragma once
#include "pch.h"
#include "xcgui/animation/XCAnimationSequence.hpp"
#include "xcgui/animation/XCAnimationItem.hpp"


namespace xcgui {

	void declareAnimationSequence(py::module& m) {
		py::class_<XCAnimationSequence, XCAnimation>(m, "XAnimationSequence")
			PYCASTOBJECT(XCAnimationSequence)
			
			.def(py::init([](const XCObject& xcObject, int loopCount=1) {
				auto handle = xcObject.GetHandle();
				XCAnimationSequence obj(handle, loopCount);
				return obj;
			}), "xcObject"_a, "loopCount"_a=1)

			.def("move", [](XCAnimationSequence& self, UINT duration, float x, float y, int nLoopCount = 1, int easeFlag = 0, bool bGoBack = false) {
				auto handle = self.Move(duration, x, y, nLoopCount, easeFlag, bGoBack);
				return XCAnimationItem(handle);
			}, "duration"_a, "x"_a, "y"_a, "loopCount"_a=1, "easeFlag"_a=0, "goBack"_a=false)
				
			.def("moveEx", [](XCAnimationSequence& self, UINT duration, float fromX, float fromY, float toX, float toY, int nLoopCount = 1, int easeFlag = 0, bool bGoBack = false) {
				auto handle = self.MoveEx(duration, fromX, fromY, toX, toY, nLoopCount, easeFlag, bGoBack);
				return XCAnimationItem(handle);
			}, "duration"_a, "fromX"_a, "fromY"_a, "toX"_a, "toY"_a, "loopCount"_a = 1, "easeFlag"_a = 0, "goBack"_a = false)

			.def("rotate", [](XCAnimationSequence& self, UINT duration, float angle, int nLoopCount = 1, int easeFlag = 0, bool bGoBack = false) {
				auto handle = self.Rotate(duration, angle, nLoopCount, easeFlag, bGoBack);
				return XCAnimationItem(handle);
			}, "duration"_a, "angle"_a, "loopCount"_a=1, "easeFlag"_a=0, "goBack"_a=false)
				
			.def("rotateEx", [](XCAnimationSequence& self, UINT duration, float from, float to, int nLoopCount = 1, int easeFlag = 0, bool bGoBack = false) {
				auto handle = self.RotateEx(duration, from, to, nLoopCount, easeFlag, bGoBack);
				return XCAnimationItem(handle);
			}, "duration"_a, "fromAngle"_a, "toAngle"_a, "loopCount"_a=1, "easeFlag"_a=0, "goBack"_a=false)


			.def("scale", [](XCAnimationSequence& self, UINT duration, float scaleX, float scaleY, int nLoopCount = 0, int easeFlag = 0, bool bGoBack = true) {
				auto handle = self.Scale(duration, scaleX, scaleY, nLoopCount, easeFlag, bGoBack);
				return XCAnimationItem(handle);
			}, "duration"_a, "scaleX"_a, "scaleY"_a, "loopCount"_a=1, "easeFlag"_a=0, "goBack"_a=false)
				
			.def("scaleSize", [](XCAnimationSequence& self, UINT duration, float width, float height, int nLoopCount = 1, int easeFlag = 0, bool bGoBack = false) {
				auto handle = self.ScaleSize(duration, width, height, nLoopCount, easeFlag, bGoBack);
				return XCAnimationItem(handle);
			}, "duration"_a, "width"_a, "height"_a, "loopCount"_a=1, "easeFlag"_a=0, "goBack"_a=false)

			.def("alpha", [](XCAnimationSequence& self, UINT duration, BYTE alpha, int nLoopCount = 0, int easeFlag = 0, bool bGoBack = false) {
				auto handle = self.Alpha(duration, alpha, nLoopCount, easeFlag, bGoBack);
				return XCAnimationItem(handle);
			}, "duration"_a, "alpha"_a, "loopCount"_a = 1, "easeFlag"_a = 0, "goBack"_a = false)
				
			.def("alphaEx", [](XCAnimationSequence& self, UINT duration, BYTE from_alpha, BYTE to_alpha, int nLoopCount = 0, int easeFlag = 0, bool bGoBack = false) {
				auto handle = self.AlphaEx(duration, from_alpha, to_alpha, nLoopCount, easeFlag, bGoBack);
				return XCAnimationItem(handle);
			}, "duration"_a, "fromAlpha"_a, "toAlpha"_a, "loopCount"_a=1, "easeFlag"_a=0, "goBack"_a=false)


			.def("color", [](XCAnimationSequence& self, UINT duration, COLORREF color, int nLoopCount = 0, int easeFlag = 0, bool bGoBack = false) {
				auto handle = self.Color(duration, color, nLoopCount, easeFlag, bGoBack);
				return XCAnimationItem(handle);
			}, "duration"_a, "color"_a, "loopCount"_a=1, "easeFlag"_a=0, "goBack"_a=false)
				
			.def("colorEx", [](XCAnimationSequence& self, UINT duration, COLORREF from, COLORREF to, int nLoopCount = 0, int easeFlag = 0, bool bGoBack = false) {
				auto handle = self.ColorEx(duration, from, to, nLoopCount, easeFlag, bGoBack);
				return XCAnimationItem(handle);
			}, "duration"_a, "fromColor"_a, "toColor"_a, "loopCount"_a=1, "easeFlag"_a=0, "goBack"_a=false)



			.def("layoutWidth", [](XCAnimationSequence& self, UINT duration, layout_size_ nType, float width, int nLoopCount = 1, int easeFlag = 0, bool bGoBack = false) {
				auto handle = self.LayoutWidth(duration, nType, width, nLoopCount, easeFlag, bGoBack);
				return XCAnimationItem(handle);
			}, "duration"_a, "sizeType"_a, "width"_a, "loopCount"_a=1, "easeFlag"_a=0, "goBack"_a=false)
				
			.def("layoutHeight", [](XCAnimationSequence& self, UINT duration, layout_size_ nType, float height, int nLoopCount = 1, int easeFlag = 0, bool bGoBack = false) {
				auto handle = self.LayoutHeight(duration, nType, height, nLoopCount, easeFlag, bGoBack);
				return XCAnimationItem(handle);
			}, "duration"_a, "sizeType"_a, "height"_a, "loopCount"_a=1, "easeFlag"_a=0, "goBack"_a=false)

			.def("layoutSize", [](XCAnimationSequence& self, UINT duration, layout_size_ nWidthType, float width, layout_size_ nHeightType, float height, int nLoopCount = 0, int easeFlag = 0, bool bGoBack = true) {
				auto handle = self.LayoutSize(duration, nWidthType, width, nHeightType, height, nLoopCount, easeFlag, bGoBack);
				return XCAnimationItem(handle);
			}, "duration"_a, "widthSizeType"_a, "width"_a, "heightSizeType"_a, "height"_a, "loopCount"_a = 1, "easeFlag"_a = 0, "goBack"_a = false)
				
			.def("delay", [](XCAnimationSequence& self, float duration) {
				auto handle = self.Delay(duration);
				return XCAnimationItem(handle);
			}, "duration"_a)


			.def("delayEx", [](XCAnimationSequence& self, float duration, int nLoopCount = 1, int easeFlag = 0, bool bGoBack = false) {
				auto handle = self.DelayEx(duration, nLoopCount, easeFlag, bGoBack);
				return XCAnimationItem(handle);
			}, "duration"_a, "loopCount"_a=1, "easeFlag"_a=0, "goBack"_a=false)
				
			.def("show", [](XCAnimationSequence& self, float duration, bool bShow) {
				auto handle = self.Show(duration, bShow);
				return XCAnimationItem(handle);
			}, "duration"_a, "show"_a)

			.def("destroyObjectUI", [](XCAnimationSequence& self, float duration) {
				auto handle = self.DestroyObjectUI(duration);
				return XCAnimationItem(handle);
			}, "duration"_a)
			;
	}
}