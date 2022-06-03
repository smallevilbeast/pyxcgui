							#pragma once
#include "pch.h"
#include "xcgui/element/XCDateTime.hpp"
#include "xcgui/element/XCButton.hpp"
#include "xcgui/XCStruct.hpp"


namespace xcgui {

	void declareDateTime(py::module& m) {
		py::class_<XCDateTime, XCElement>(m, "XDateTime")
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCDateTime obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCDateTime obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)

			.def("setStyle", &XCDateTime::SetStyle, "style"_a)
			.def("getStyle", &XCDateTime::GetStyle)
			.def("getButton", [](XCDateTime& self, int btnType) -> XCButton* {
				auto handle = self.GetButton(btnType);
				if (!handle) return nullptr;
				return new XCButton(handle);
			}, "btnType"_a, py::return_value_policy::take_ownership)

			.def("getSelBkColor", &XCDateTime::GetSelBkColor)
			.def("setSelBkColor", &XCDateTime::SetSelBkColor, "color"_a)
			.def("getDate", [](XCDateTime& self) -> XCDateInfo  {
				XCDateInfo info;
				self.GetDate(&info.year, &info.month, &info.day);
				return info;
			})
			.def("setDate", &XCDateTime::SetDate, "year"_a, "month"_a, "day"_a)
			.def("getTime", [](XCDateTime& self) -> XCTimeInfo  {
				XCTimeInfo info;
				self.GetTime(&info.hour, &info.minute, &info.second);
				return info;
			})
			.def("setTime", &XCDateTime::SetDate, "hour"_a, "minute"_a, "second"_a)
			.def("popup", &XCDateTime::Popup)	
				
			;
	}
}