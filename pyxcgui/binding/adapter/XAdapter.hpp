#pragma once
#include "pch.h"
#include "xcgui/adapter/XCAdapter.hpp"

namespace xcgui {

	void declareAdapter(py::module& m) {

		py::class_<XCAdapter, XCObject>(m, "XAdapter")
			PYCASTOBJECT(XCAdapter)
			PYOBJECTVALID(XCAdapter, XC_ADAPTER)
			.def("enableAutoDestroy", &XCAdapter::EnableAutoDestroy, "enable"_a)
			.def("addRef", &XCAdapter::AddRef)
			.def("release", &XCAdapter::Release)
			.def("getRefCount", &XCAdapter::GetRefCount)
			.def("destroy", &XCAdapter::Destroy);
			;
	}
}