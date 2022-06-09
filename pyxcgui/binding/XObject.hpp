#pragma once
#include "pch.h"
#include "xcgui/XCObject.hpp"

namespace xcgui {

	void declareBase(py::module& m) {

		py::class_<XCObject>(m, "XObject")
			PYCASTOBJECT(XCObject)
			.def("getType", &XCObject::GetType, u8R"(获取对象最终类型)")
			.def("getTypeBase", &XCObject::GetTypeBase, u8R"(获取对象的基础类型, 返回对象类型, 以下类型之一: (XC_ERROR, XC_WINDOW, XC_ELE, XC_SHAPE, XC_ADAPTER))")
			.def("getHandle", [](XCObject& self) -> uintptr_t {
				return (uintptr_t)self.GetHandle();
			})
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