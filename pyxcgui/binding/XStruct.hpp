#pragma once
#include "pch.h"

namespace xcgui {

	void declareStruct(py::module& m) {

		py::class_<POINTF>(m, "POINTF")
			.def(py::init<>())
			.def_readwrite("x", &POINTF::x)
			.def_readwrite("y", &POINTF::y);

		py::class_<RECTF>(m, "RECTF")
			.def(py::init<>())
			.def_readwrite("left", &RECTF::left)
			.def_readwrite("top", &RECTF::top)
			.def_readwrite("right", &RECTF::right)
			.def_readwrite("bottom", &RECTF::bottom);

		py::class_<borderSize_>(m, "borderSize_")
			.def(py::init<>())
			.def_readwrite("leftSize", &borderSize_::leftSize)
			.def_readwrite("topSize", &borderSize_::topSize)
			.def_readwrite("rightSize", &borderSize_::rightSize)
			.def_readwrite("bottomSize", &borderSize_::bottomSize);

		py::class_<position_>(m, "position_")
			.def(py::init<>())
			.def_readwrite("iRow", &position_::iRow)
			.def_readwrite("iColumn", &position_::iColumn);


	}
}