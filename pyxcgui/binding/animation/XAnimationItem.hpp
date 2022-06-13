#pragma once
#include "pch.h"
#include "xcgui/animation/XCAnimationItem.hpp"
#include "binding/manager/XUserDataManager.hpp"
#include "binding/manager/XCallbackManager.hpp"

namespace xcgui {

	void declareAnimationItem(py::module& m) {
		py::class_<XCAnimationItem, XCObject>(m, "XAnimationItem")
			PYCASTOBJECT(XCAnimationItem)
			PYOBJECTVALID(XCAnimationItem, XC_ANIMATION_ITEM)
			.def("enableAutoDestroy", &XCAnimationItem::EnableAutoDestroy, "enable"_a)
			
			.def("enableCompleteRelease", &XCAnimationItem::EnableCompleteRelease, "enable"_a)
				
			.def("setCallback", [](XCAnimationItem& self, const XAnimationItemCallback& callback) {
				XCallbackManager::GetInstance()->SetAnimationItemCallback(self.GetHandle(), callback);
			}, "callback"_a)

			.def("getUserData", [](XCAnimationItem& self) {
				XUserDataManager::GetInstance()->GetUserData(self.GetHandle());
			})

			.def("setUserData", [](XCAnimationItem& self, const py::object& object) {
				XUserDataManager::GetInstance()->SetUserData(self.GetHandle(), object);
			}, "userdata"_a)
				
			.def("rotateSetCenter", &XCAnimationItem::RotateSetCenter, "x"_a, "y"_a, "offset"_a)
			.def("scaleSetPosition", &XCAnimationItem::ScaleSetPosition, "position"_a)
			.def("moveSetFlag", &XCAnimationItem::MoveSetFlag, "flags"_a)
			;
	}
}