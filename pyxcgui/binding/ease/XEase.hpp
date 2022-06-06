#pragma once
#include "pch.h"
#include "xcgui/ease/XCEase.hpp"

namespace xcgui {

	void declareEase(py::module& m) {

		py::class_<XCEase>(m, "XEase")
			.def_static("linear", &XCEase::Linear, "pos"_a)
			.def_static("quad", &XCEase::Quad, "pos"_a, "flag"_a)
			.def_static("cubic", &XCEase::Cubic, "pos"_a, "flag"_a)
			.def_static("quart", &XCEase::Quart, "pos"_a, "flag"_a)
			.def_static("quint", &XCEase::Quint, "pos"_a, "flag"_a)
			.def_static("sine", &XCEase::Sine, "pos"_a, "flag"_a)
			.def_static("expo", &XCEase::Expo, "pos"_a, "flag"_a)
			.def_static("circ", &XCEase::Circ, "pos"_a, "flag"_a)
			.def_static("elastic", &XCEase::Elastic, "pos"_a, "flag"_a)
			.def_static("back", &XCEase::Back, "pos"_a, "flag"_a)
			.def_static("bounce", &XCEase::Bounce, "pos"_a, "flag"_a)
			.def_static("ex", &XCEase::Ex, "pos"_a, "flag"_a)
		;
	}

}