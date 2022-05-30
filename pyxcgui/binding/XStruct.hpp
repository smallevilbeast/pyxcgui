#pragma once
#include "pch.h"
#include "xcgui/XCStruct.hpp"


namespace xcgui {

	void declareStruct(py::module& m) {

		py::class_<XCPoint>(m, "XPoint")
			.def(py::init<>())
			.def(py::init<int, int>(), "x"_a, "y"_a)
			.def_readwrite("x", &XCPoint::x)
			.def_readwrite("y", &XCPoint::y);
						  
		py::class_<XCPointF>(m, "XPointF")
			.def(py::init<>())
			.def(py::init<float, float>(), "x"_a, "y"_a)
			.def_readwrite("x", &XCPointF::x)
			.def_readwrite("y", &XCPointF::y);
		
		py::class_<XCSize>(m, "XSize")
			.def(py::init<>())
			.def(py::init<int, int>(), "width"_a, "height"_a)
			.def_readwrite("width", &XCSize::width)
			.def_readwrite("height", &XCSize::height);

		py::class_<XCRect>(m, "XRect")
			.def(py::init<>())
			.def(py::init<int, int, int, int>(), "left"_a, "top"_a, "right"_a, "bottom"_a)
			.def_readwrite("left", &XCRect::left)
			.def_readwrite("top", &XCRect::top)
			.def_readwrite("right", &XCRect::right)
			.def_readwrite("bottom", &XCRect::bottom)
			.def_readwrite("x", &XCRect::left)
			.def_readwrite("y", &XCRect::top)
			.def_readwrite("width", &XCRect::right)
			.def_readwrite("height", &XCRect::bottom);


		py::class_<XCRectF>(m, "XRectF")
			.def(py::init<>())
			.def(py::init<float, float, float, float>(), "left"_a, "top"_a, "right"_a, "bottom"_a)
			.def_readwrite("left", &XCRectF::left)
			.def_readwrite("top", &XCRectF::top)
			.def_readwrite("right", &XCRectF::right)
			.def_readwrite("bottom", &XCRectF::bottom)
			.def_readwrite("x", &XCRectF::left)
			.def_readwrite("y", &XCRectF::top)
			.def_readwrite("width", &XCRectF::right)
			.def_readwrite("height", &XCRectF::bottom);

		py::class_<XCFontInfo>(m, "XFontInfo")
			.def(py::init<>())
			.def(py::init<const std::wstring&, int, int>(), "name"_a, "size"_a, "style"_a)
			.def_readwrite("name", &XCFontInfo::name)
			.def_readwrite("size", &XCFontInfo::size)
			.def_readwrite("style", &XCFontInfo::style);

		py::class_<XCRotateInfo>(m, "XRotateInfo")
			.def(py::init<>())
			.def(py::init<float, float, float, bool>(), "angle"_a, "x"_a, "y"_a, "offset"_a)
			.def_readwrite("angle", &XCRotateInfo::angle)
			.def_readwrite("x", &XCRotateInfo::x)
			.def_readwrite("y", &XCRotateInfo::y)
			.def_readwrite("offset", &XCRotateInfo::offset);

		py::class_<XCStrokeInfo>(m, "XStrokeInfo")
			.def(py::init<>())
			.def(py::init<COLORREF, float>(), "color"_a, "strokeWidth"_a)
			.def_readwrite("name", &XCStrokeInfo::color)
			.def_readwrite("strokeWidth", &XCStrokeInfo::strokeWidth);


		py::class_<XCEvent>(m, "XEvent")
			.def_readonly("eventType", &XCEvent::eventType)
			.def_readonly("sender", &XCEvent::sender)
			.def_readonly("mouse", &XCEvent::mouse)
			.def_readonly("wParam", &XCEvent::wParam)
			.def_readonly("lParam", &XCEvent::lParam);
	}
}