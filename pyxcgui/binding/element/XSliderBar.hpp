				 				 					 							#pragma once
#include "pch.h"
#include "xcgui/element/XCSliderBar.hpp"
#include "xcgui/element/XCButton.hpp"
#include "xcgui/XCImage.hpp"

namespace xcgui {

	void declareSliderBar(py::module& m) {
		py::class_<XCSliderBar, XCElement>(m, "XSliderBar")
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCSliderBar obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCSliderBar obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)

			.def("setRange", &XCSliderBar::SetRange, "range"_a)
			.def("getRange", &XCSliderBar::GetRange)
		
			.def("setImageLoad", [](XCSliderBar& self, const XCImage& image) {
				self.SetImageLoad(image.getImageHandle());
			}, "image"_a)


			.def("setButtonWidth", &XCSliderBar::SetButtonWidth, "width"_a)
			.def("setButtonHeight", &XCSliderBar::SetButtonHeight, "length"_a)
			.def("setPos", &XCSliderBar::SetPos, "pos"_a)
			.def("getPos", &XCSliderBar::GetPos)

			.def("getButton", [](XCSliderBar& self) {
				auto handle = self.GetButton();
				XCButton btn(handle);
				return btn;
			})
			.def("enableHorizon", &XCSliderBar::EnableHorizon, "enable"_a)
	
			;
	}
}