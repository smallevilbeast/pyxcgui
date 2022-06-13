#pragma once
#include "pch.h"
#include "xcgui/shape/XCShapeGif.hpp"
#include "xcgui/XCImage.hpp"

namespace xcgui {

	void declareShapeGif(py::module& m) {
		py::class_<XCShapeGif, XCShape>(m, "XShapeGif")
			PYCASTOBJECT(XCShapeGif)
			PYOBJECTVALID(XCShapeGif, XC_SHAPE_GIF)
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCShapeGif obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCShapeGif obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)


			.def("setImage", [](XCShapeGif& self, const XCImage& image) {
				self.SetImage(image.getImageHandle());
			}, "image"_a)
			.def("getImage", [](XCShapeGif& self) -> XCImage* {
				auto handle = self.GetImage();
				if (!handle) return nullptr;
				return new XCImage(handle);	
			}, py::return_value_policy::take_ownership)				
			;
	}
}