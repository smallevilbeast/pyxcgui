#pragma once
#include "pch.h"
#include "xcgui/element/XCScrollBar.hpp"
#include "xcgui/element/XCButton.hpp"

namespace xcgui {

	void declareScrollBar(py::module& m) {
		py::class_<XCScrollBar, XCElement>(m, "XScrollBar")
			PYCASTOBJECT(XCScrollBar)
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCScrollBar obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCScrollBar obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)

			.def("setRange", &XCScrollBar::SetRange, "range"_a)
			.def("getRange", &XCScrollBar::GetRange)
			.def("showButton", &XCScrollBar::ShowButton, "enable"_a)


			.def("setSliderLength", &XCScrollBar::SetSliderLength, "length"_a)
			.def("setSliderMinLength", &XCScrollBar::SetSliderMinLength, "length"_a)
			.def("setSliderPadding", &XCScrollBar::SetSliderPadding, "padding"_a)
			.def("enableHorizon", &XCScrollBar::EnableHorizon, "enable"_a)
			.def("getSliderMaxLength", &XCScrollBar::GetSliderMaxLength)
			.def("scrollUp", &XCScrollBar::ScrollUp)
			.def("scrollDown", &XCScrollBar::ScrollDown)
			.def("scrollTop", &XCScrollBar::ScrollTop)
			.def("scrollBottom", &XCScrollBar::ScrollBottom)
			.def("scrollPos", &XCScrollBar::ScrollPos, "pos"_a)
			.def("scrollUp", &XCScrollBar::ScrollUp)


			.def("getButtonUp", [](XCScrollBar& self) {
				auto handle = self.GetButtonUp();
				XCButton btn(handle);
				return btn;
			})

			.def("getButtonDown", [](XCScrollBar& self) {
				auto handle = self.GetButtonDown();
				XCButton btn(handle);
				return btn;
			})

			.def("getButtonSlider", [](XCScrollBar& self) {
				auto handle = self.GetButtonSlider();
				XCButton btn(handle);
				return btn;
			})
	
			;
	}
}