#pragma once
#include "pch.h"
#include "xcgui/XCObjectUI.hpp"
#include "binding/manager/XCastManager.hpp"

namespace xcgui {

	void declareObjectUI(py::module& m) {

		py::class_<XCObjectUI, XCObject>(m, "XObjectUI")
			.def("setStyle", &XCObjectUI::SetStyle, "style"_a)
			.def("getStyle", &XCObjectUI::GetStyle)
			.def("enableCss", &XCObjectUI::EnableCSS, "enable"_a)
			.def("setCssName", &XCObjectUI::SetCssName, "name"_a)
			.def("getCssName", &XCObjectUI::GetCssName)

			.def("findObjectByName", [](XCObjectUI& self, const std::wstring& name) -> XCObject* {
				auto handle = self.FindObjectByName(name);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "name"_a, py::return_value_policy::reference)
			.def("findObjectByUID", [](XCObjectUI& self, int nId) -> XCObject* {
				auto handle = self.FindObjectByUID(nId);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "nID"_a, py::return_value_policy::reference)
			.def("findObjectByUIDName", [](XCObjectUI& self, const std::wstring& name) -> XCObject* {
				auto handle = self.FindObjectByUIDName(name);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "name"_a, py::return_value_policy::reference)
			;

	}
}