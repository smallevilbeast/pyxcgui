#pragma once
#include "pch.h"
#include "xcgui/XCObject.hpp"

namespace xcgui {

	void declareBase(py::module& m) {

		py::class_<XCObject>(m, "XObject")
			PYCASTOBJECT(XCObject)
			.def("getType", &XCObject::GetType)
			.def("getTypeBase", &XCObject::GetTypeBase)
			.def("getHandle", [](XCObject& self) -> uintptr_t {
				return (uintptr_t)self.GetHandle();
			})
			.def("releaseAnimation", [](XCObject& self, bool end=false) {
				self.ReleaseAnimation(end);
			}, "end"_a=false)
			.def("getTypeEx", &XCObject::GetTypeEx)
			.def("setTypeEx", &XCObject::SetTypeEx, "nType"_a)
			.def("setProperty", &XCObject::SetProperty, "name"_a, "value"_a)
			.def("getProperty", &XCObject::GetProperty, "name"_a)
			.def("__eq__", [](const XCObject& self, const XCObject& other) {
				return self.GetHandle() == other.GetHandle();
			});

	}
}