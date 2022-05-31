#pragma once
#include "pch.h"
#include "xcgui.h"
#include "manager/XCastManager.hpp"
#include "xcgui/utils/Color.hpp"

namespace xcgui {

	void declareGlobal(py::module& m) {

		m.def("cast", [](uintptr_t handle) -> XCObject* {
			return XCastManager::GetInstance()->CastObject((HXCGUI)handle);
		}, "handle"_a, py::return_value_policy::reference);


		m.def("RGB", [](BYTE r, BYTE g, BYTE b) {
			return (RGB(r, g, b)) &0xFFFFFFFF;
		}, "r"_a, "g"_a, "b"_a);

		m.def("RGB", [](const std::string& hexColor) {
			return hexToRGBColorRef(hexColor);
		}, "hexcolor"_a);

		m.def("RGBA", [](const std::string& hexColor) {
			return hexToRGBAColorRef(hexColor);
		}, "hexcolor"_a);

		m.def("RGBA", [](BYTE r, BYTE g, BYTE b, BYTE a) {
			return  (RGBA(r, g, b, a)) & 0xFFFFFFFF;
		}, "r"_a, "g"_a, "b"_a, "a"_a);

		m.def("RGBA", [](int rgb, BYTE a) {
			return  ((rgb & 16777215) | (a & 255) << 24) & 0xFFFFFFFF;
		}, "rgb"_a, "a"_a);
	}

}