#pragma once
#include "pch.h"
#include "xcgui/XCObject.hpp"

namespace xcgui {

	void declareBase(py::module& m) {

		py::class_<XCObject>(m, "XObject")
			.def("getType", &XCObject::GetType)
			.def("getTypeBase", &XCObject::GetTypeBase)
			.def("getTypeEx", &XCObject::GetTypeEx)
			.def("setTypeEx", &XCObject::SetTypeEx, "nType"_a)
			.def("__eq__", [](const XCObject& self, const XCObject& other) {
				return self.GetHandle() == other.GetHandle();
			});

	}
}