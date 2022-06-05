#pragma once
#include "pch.h"
#include "xcgui/element/XCProgressBar.hpp"
#include "xcgui/XCImage.hpp"


namespace xcgui {

	void declareProgressBar(py::module& m) {
		py::class_<XCProgressBar, XCElement>(m, "XProgressBar")
			PYCASTOBJECT(XCProgressBar)
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCProgressBar obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCProgressBar obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)

			.def("enableShowText", &XCProgressBar::EnableShowText, "enable"_a)
			.def("enableStretch", &XCProgressBar::EnableStretch, "enable"_a)
			.def("setRange", &XCProgressBar::SetRange, "range"_a)
			.def("getRange", &XCProgressBar::GetRange)

			.def("setImageLoad", [](XCProgressBar& self, const XCImage& image) {
				self.SetImageLoad(image.getImageHandle());
			}, "image"_a)


			.def("setPos", &XCProgressBar::SetPos, "pos"_a)
			.def("getPos", &XCProgressBar::GetPos)
			.def("enableHorizon", &XCProgressBar::EnableHorizon, "enable"_a)
				
			;
	}
}