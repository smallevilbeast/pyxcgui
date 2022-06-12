#pragma once
#include "pch.h"
#include "xcgui/animation/XCAnimation.hpp"
#include "binding/manager/XUserDataManager.hpp"
#include "binding/manager/XCallbackManager.hpp"
#include "xcgui/XCObjectUI.hpp"

namespace xcgui {

	void declareAnimation(py::module& m) {
		py::class_<XCAnimation, XCObject>(m, "XAnimation")
			PYCASTOBJECT(XCAnimation)

			.def("run", [](XCAnimation& self, const XCObjectUI& ele) {
				self.Run(ele.GetHandle());
			}, "obejctUI"_a)

			.def("release", [](XCAnimation& self, bool end=false) {
				self.Release(end);
			}, "end"_a)

			.def_static("releaseEx", [](const XCObject& ele, bool bEnd=false) {
				XCAnimation::ReleaseEx(ele.GetHandle(), bEnd);
			}, "objectUI"_a, "end"_a=false)
			
			.def("enableAutoDestroy", &XCAnimation::EnableAutoDestroy, "enable"_a)
			
			.def("getObjectUI", [](XCAnimation& self) -> XCObject*  {
				auto handle = self.GetObjectUI();
				return XCastManager::GetInstance()->CastObject(handle);
			}, py::return_value_policy::take_ownership)
				
			.def("setCallback", [](XCAnimation& self, const XAnimationCallback& callback) {
				XCallbackManager::GetInstance()->SetAnimationCallback(self.GetHandle(), callback);
			}, "callback"_a)

			.def("getUserData", [](XCAnimation& self) {
				XUserDataManager::GetInstance()->GetUserData(self.GetHandle());
			})

			.def("setUserData", [](XCAnimation& self, const py::object& object) {
				XUserDataManager::GetInstance()->SetUserData(self.GetHandle(), object);
			}, "userdata"_a)
				
			.def("start", &XCAnimation::Start)
			.def("pause", &XCAnimation::Pause)

			;
	}
}