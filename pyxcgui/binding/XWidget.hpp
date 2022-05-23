#pragma once
#include "pch.h"
#include "xcgui/XCWidget.hpp"


namespace xcgui {

	void declareWidget(py::module& m) {

		py::class_<XCWidget>(m, "XWidget")
			.def(py::init<>())
			.def("show", &XCWidget::Show, py::arg("bShow"))
			.def("enableLayoutControl", &XCWidget::EnableLayoutControl, py::arg("bEnable"))
			.def("IsLayoutControl", &XCWidget::IsLayoutControl)
			.def("getParentEle", &XCWidget::GetParentEle, py::return_value_policy::take_ownership);

	}
}