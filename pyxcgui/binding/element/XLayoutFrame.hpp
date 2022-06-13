#pragma once
#include "pch.h"
#include "xcgui/element/XCLayoutFrame.hpp"

namespace xcgui {

	void declareLayoutFrame(py::module& m) {
		py::class_<XCLayoutFrame, XCScrollView, XCLayoutBox>(m, "XLayoutFrame")
			PYCASTOBJECT(XCLayoutFrame)
			PYOBJECTVALID(XCLayoutFrame, XC_LAYOUT_FRAME)
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCLayoutFrame obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCLayoutFrame obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)

			.def(py::init([](XCObjectUI* parent) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCLayoutFrame obj;
				obj.CreateEx(handle);
				return obj;
			}), "parent"_a=nullptr)

			.def("enableLayout", &XCLayoutFrame::EnableLayout, "enable"_a)
			.def("isEnableLayout", &XCLayoutFrame::IsEnableLayout)
			.def("showLayoutFrame", &XCLayoutFrame::ShowLayoutFrame, "enable"_a)
			.def("getWidthIn", &XCLayoutFrame::GetWidthIn)
			.def("getHeightIn", &XCLayoutFrame::GetHeightIn)
				
			;
	}
}