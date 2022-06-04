#pragma once
#include "pch.h"
#include "xcgui/element/XCMonthCal.hpp"
#include "xcgui/element/XCButton.hpp"
#include "xcgui/XCStruct.hpp"


namespace xcgui {

	void declareMonthCal(py::module& m) {
		py::class_<XCMonthCal, XCElement>(m, "XMonthCal")
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCMonthCal obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCMonthCal obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)

			.def("getButton", [](XCMonthCal& self, monthCal_button_type_ btnType) -> XCButton* {
				auto handle = self.GetButton(btnType);
				if (!handle) return nullptr;
				return new XCButton(handle);
			}, "btnType"_a, py::return_value_policy::take_ownership)

			.def("getToday", [](XCMonthCal& self) -> XCDateInfo  {
				XCDateInfo info;
				self.GetToday(&info.year, &info.month, &info.day);
				return info;
			})
			.def("GetSelDate", [](XCMonthCal& self) -> XCDateInfo  {
				XCDateInfo info;
				self.GetSelDate(&info.year, &info.month, &info.day);
				return info;
			})
			.def("setToday", &XCMonthCal::SetToday, "year"_a, "month"_a, "day"_a)
			.def("setTextColor", &XCMonthCal::SetTextColor, "flag"_a, "color"_a)	
				
			;
	}
}