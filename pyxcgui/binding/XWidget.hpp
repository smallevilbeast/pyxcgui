#pragma once
#include "pch.h"
#include "xcgui/XCWidget.hpp"


namespace xcgui {

	void declareWidget(py::module& m) {

		py::class_<XCLayoutSize>(m, "XLayoutSize")
			.def(py::init<>())
			.def(py::init<layout_size_, int>(), "sizeType"_a, "size"_a)
			.def_readwrite("sizeType", &XCLayoutSize::sizeType)
			.def_readwrite("size", &XCLayoutSize::size);


		py::class_<XCWidgetLayout>(m, "XWidgetLayout")
			.def("enableWrap", &XCWidgetLayout::EnableWrap, "wrap"_a)
			.def("enableSwap", &XCWidgetLayout::EnableSwap, "swap"_a)
			.def("enableFloat", &XCWidgetLayout::EnableFloat, "float"_a)
			.def("setWidth", &XCWidgetLayout::SetWidth, "sizeInfo"_a)
			.def("setHeight", &XCWidgetLayout::SetHeight, "sizeInfo"_a)
			.def("getWidth", &XCWidgetLayout::GetWidth, py::return_value_policy::take_ownership)
			.def("getHeight", &XCWidgetLayout::GetHeight, py::return_value_policy::take_ownership)
			.def("setAlign", &XCWidgetLayout::SetAlign, "align"_a)
			.def("setMargin", &XCWidgetLayout::SetMargin, "margin"_a)
			.def("getMargin", &XCWidgetLayout::GetMargin, py::return_value_policy::take_ownership)
			.def("setMinSize", &XCWidgetLayout::SetMinSize, "width"_a, "height"_a)
			.def("setPosition", &XCWidgetLayout::SetPosition, "left"_a, "top"_a, "right"_a, "bottom"_a);



		py::class_<XCWidget>(m, "XWidget")
			.def(py::init<>())
			.def("show", &XCWidget::Show, "show"_a)
			.def("enableLayoutControl", &XCWidget::EnableLayoutControl, "enable"_a)
			.def("IsLayoutControl", &XCWidget::IsLayoutControl)
			.def("getParentEle", &XCWidget::GetParentEle, py::return_value_policy::take_ownership);

	}
}