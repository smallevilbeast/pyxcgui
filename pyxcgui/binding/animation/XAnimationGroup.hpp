#pragma once
#include "pch.h"
#include "xcgui/animation/XCAnimationGroup.hpp"
#include "xcgui/animation/XCAnimationSequence.hpp"



namespace xcgui {

	void declareAnimationGroup(py::module& m) {
		py::class_<XCAnimationGroup, XCAnimation>(m, "XAnimationGroup")
			PYCASTOBJECT(XCAnimationGroup)
			PYOBJECTVALID(XCAnimationGroup, XC_ANIMATION_GROUP)
			.def(py::init<int>(), "loopCount"_a=0)

			.def("addItem", [](XCAnimationGroup& self, const XCAnimationSequence& sequence) {
				self.AddItem(sequence.GetHandle());
			}, "sequence"_a)
			;
	}
}