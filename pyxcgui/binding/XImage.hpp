#pragma once
#include "pch.h"
#include "xcgui/XCImage.hpp"

namespace xcgui {

	void declareImage(py::module& m) {

		py::class_<XCImage, XCObject>(m, "XImage")
			.def_static("loadFile", [](const std::wstring& fileName) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->LoadFile(fileName)) {
					return nullptr;
				}
				return pImage;
			}, "filename"_a, py::return_value_policy::take_ownership);

	}
}