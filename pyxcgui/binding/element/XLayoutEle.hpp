#pragma once
#include "pch.h"
#include "xcgui/element/XCLayoutEle.hpp"

namespace xcgui {

	void declareLayoutEle(py::module& m) {
		py::class_<XCLayoutEle, XCElement, XCLayoutBox>(m, "XLayoutEle")
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCLayoutEle obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCLayoutEle obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)

			.def(py::init([](XCObjectUI* parent) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCLayoutEle obj(handle);
				return obj;
			}), "parent"_a=nullptr)

			.def("enableLayout", &XCLayoutEle::EnableLayout, "enable"_a)
			.def("isEnableLayout", &XCLayoutEle::IsEnableLayout)
			.def("showLayoutFrame", &XCLayoutEle::ShowLayoutFrame, "enable"_a)
			.def("getWidthIn", &XCLayoutEle::GetWidthIn)
			.def("getHeightIn", &XCLayoutEle::GetHeightIn)
				
			;
	}
}