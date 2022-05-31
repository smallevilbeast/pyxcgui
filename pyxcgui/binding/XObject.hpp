#pragma once
#include "pch.h"
#include "xcgui/XCObject.hpp"

namespace xcgui {

	void declareBase(py::module& m) {

		py::class_<XCObject>(m, "XObject")
			.def("getType", &XCObject::GetType, u8R"(获取对象最终类型)")
			.def("getTypeBase", &XCObject::GetTypeBase, u8R"(获取对象的基础类型, 返回对象类型, 以下类型之一: (XC_ERROR, XC_WINDOW, XC_ELE, XC_SHAPE, XC_ADAPTER))")

			.def("getTypeEx", &XCObject::GetTypeEx)
			.def("getHandle", &XCObject::GetHandle)
			.def("setTypeEx", &XCObject::SetTypeEx, "nType"_a)
			.def("__eq__", [](const XCObject& self, const XCObject& other) {
				return self.GetHandle() == other.GetHandle();
			});

	}
}