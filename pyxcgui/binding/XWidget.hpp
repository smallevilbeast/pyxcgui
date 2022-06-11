#pragma once
#include "pch.h"
#include "xcgui/XCWidget.hpp"
#include "manager/XCastManager.hpp"


namespace xcgui {

	void declareWidget(py::module& m) {

		py::class_<XCLayoutSize>(m, "XLayoutSize")
			.def(py::init<>())
			.def(py::init<layout_size_, int>(), "sizeType"_a, "size"_a)
			.def_readwrite("sizeType", &XCLayoutSize::sizeType)
			.def_readwrite("size", &XCLayoutSize::size);

		py::class_<XCWidget, XCObjectUI>(m, "XWidget")
			PYCASTOBJECT(XCWidget)
			.def("isShow", &XCWidget::IsShow)
			.def("show", &XCWidget::Show, "show"_a)
			.def("enableLayoutControl", &XCWidget::EnableLayoutControl, "enable"_a)
			.def("isLayoutControl", &XCWidget::IsLayoutControl)

			.def("getParentEle", [](const XCWidget& self) -> XCObject* { 
				return XCastManager::GetInstance()->CastObject(self.GetParentEle());
			}, py::return_value_policy::reference)


			.def("getParent", [](const XCWidget& self) -> XCObject* {
				return XCastManager::GetInstance()->CastObject(self.getParent());
			}, py::return_value_policy::reference)


			.def("getHWND", &XCWidget::GetHWND)
			.def("getWindow", [](const XCWidget& self) -> XCObject* {
				return XCastManager::GetInstance()->CastObject(self.GetWindow());
			}, py::return_value_policy::reference)

			.def("setID", &XCWidget::SetID, "id"_a)
			.def("getID", &XCWidget::GetID)
			.def("setUID", &XCWidget::SetUID, "uid"_a)
			.def("getUID", &XCWidget::GetUID)
			.def("setName", &XCWidget::SetName, "name"_a)
			.def("getName", &XCWidget::GetName)
			.def("layoutEnableWrap", &XCWidget::LayoutEnableWrap, "wrap"_a)
			.def("layoutEnableSwap", &XCWidget::LayoutEnableSwap, "swap"_a)
			.def("layoutEnableFloat", &XCWidget::LayoutEnableFloat, "float"_a)
			.def("layoutSetWidth", &XCWidget::LayoutSetWidth, "sizeType"_a, "size"_a=0)
			.def("layoutSetHeight", &XCWidget::LayoutSetHeight, "sizeType"_a, "size"_a = 0)
			.def("layoutGetWidth", &XCWidget::LayoutGetWidth)
			.def("layoutGetHeight", &XCWidget::LayoutGetHeight)
			.def("layoutSetAlign", &XCWidget::LayoutSetAlign, "align"_a)
			.def("layoutSetMargin", &XCWidget::LayoutSetMargin, "left"_a, "top"_a, "right"_a, "bottom"_a)
			.def("layoutGetMargin", &XCWidget::LayoutGetMargin)
			.def("layoutSetMinSize", &XCWidget::LayoutSetMinSize, "width"_a, "height"_a)
			.def("layoutSetPosition", &XCWidget::LayoutSetPosition, "left"_a, "top"_a, "right"_a, "bottom"_a);

	}
}