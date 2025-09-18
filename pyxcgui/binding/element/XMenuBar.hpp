#pragma once
#include "pch.h"
#include "xcgui/element/XCMenuBar.hpp"
#include "xcgui/menu/XCMenu.hpp"
#include "xcgui/element/XCButton.hpp"


namespace xcgui {

	void declareMenuBar(py::module& m) {
		py::class_<XCMenuBar, XCElement>(m, "XMenuBar")
			PYCASTOBJECT(XCMenuBar)
			PYOBJECTVALID(XCMenuBar, XC_MENUBAR)
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCMenuBar obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCMenuBar obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)

			.def("addButton", &XCMenuBar::AddButton, "text"_a)
			.def("setButtonHeight", &XCMenuBar::SetButtonHeight, "height"_a)
			.def("getMenu", [](XCMenuBar& self, int index) -> XCMenu* {
				auto handle = self.GetMenu(index);
				if (!handle) return nullptr;
				return new XCMenu(handle);
			}, "index"_a, py::return_value_policy::take_ownership)

			.def("getButton", [](XCMenuBar& self, int index) -> XCButton* {
				auto handle = self.GetButton(index);
				if (!handle) return nullptr;
				return new XCButton(handle);
			}, "index"_a, py::return_value_policy::take_ownership)

			.def("deleteButton", &XCMenuBar::DeleteButton, "index"_a)
			.def("enableAutoWidth", &XCMenuBar::EnableAutoWidth, "enable"_a)

			// 3.3.8.1 新增
			.def("getSelect", [](XCMenuBar& self) {
				return XMenuBar_GetSelect(self.getEleHandle());
			})

			;
	}
}