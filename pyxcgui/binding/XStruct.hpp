#pragma once
#include "pch.h"
#include "xcgui/XCStruct.hpp"

	 	 
namespace xcgui {

	void declareStruct(py::module& m) {

		py::class_<tagPOINT>(m, "POINT")
			PYCAST(tagPOINT)
			.def(py::init<>())
			.def_readwrite("x", &tagPOINT::x)
			.def_readwrite("y", &tagPOINT::y);

		py::class_<tagRECT>(m, "RECT")
			PYCAST(tagRECT)
			.def(py::init<>())
			.def_readwrite("left", &tagRECT::left)
			.def_readwrite("top", &tagRECT::top)
			.def_readwrite("right", &tagRECT::right)
			.def_readwrite("bottom", &tagRECT::bottom);

		py::class_<tagSIZE>(m, "SIZE")
			PYCAST(tagSIZE)
			.def(py::init<>())
			.def_readwrite("cx", &tagSIZE::cx)
			.def_readwrite("cy", &tagSIZE::cy);

		py::class_<XCPoint>(m, "XPoint")
			PYCAST(XCPoint)
			.def(py::init<>())
			.def(py::init<int, int>(), "x"_a, "y"_a)
			.def_readwrite("x", &XCPoint::x)
			.def_readwrite("y", &XCPoint::y);
						  
		py::class_<XCPointF>(m, "XPointF")
			PYCAST(XCPointF)
			.def(py::init<>())
			.def(py::init<float, float>(), "x"_a, "y"_a)
			.def_readwrite("x", &XCPointF::x)
			.def_readwrite("y", &XCPointF::y);
		
		py::class_<XCSize>(m, "XSize")
			PYCAST(XCSize)
			.def(py::init<>())
			.def(py::init<int, int>(), "width"_a, "height"_a)
			.def_readwrite("width", &XCSize::width)
			.def_readwrite("height", &XCSize::height);

		py::class_<XCRect>(m, "XRect")
			PYCAST(XCRect)
			.def(py::init<>())
			.def(py::init<int, int, int, int>(), "left"_a, "top"_a, "right"_a, "bottom"_a)
			.def_readwrite("left", &XCRect::left)
			.def_readwrite("top", &XCRect::top)
			.def_readwrite("right", &XCRect::right)
			.def_readwrite("bottom", &XCRect::bottom);


		py::class_<XCRectF>(m, "XRectF")
			PYCAST(XCRectF)
			.def(py::init<>())
			.def(py::init<float, float, float, float>(), "left"_a, "top"_a, "right"_a, "bottom"_a)
			.def_readwrite("left", &XCRectF::left)
			.def_readwrite("top", &XCRectF::top)
			.def_readwrite("right", &XCRectF::right)
			.def_readwrite("bottom", &XCRectF::bottom);

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

		py::class_<XCCareInfo>(m, "XCareInfo")
			.def_readonly("x", &XCCareInfo::x)
			.def_readonly("y", &XCCareInfo::y)
			.def_readonly("width", &XCCareInfo::width)
			.def_readonly("height", &XCCareInfo::height)
			.def_readonly("care", &XCCareInfo::pCare);

		py::class_<XCShadowInfo>(m, "XShadowInfo")
			.def_readonly("size", &XCShadowInfo::size)
			.def_readonly("depth", &XCShadowInfo::depth)
			.def_readonly("angeleSize", &XCShadowInfo::angeleSize)
			.def_readonly("rightAngle", &XCShadowInfo::rightAngle)
			.def_readonly("color", &XCShadowInfo::color);

		py::class_<XCDateInfo>(m, "XDateInfo")
			.def(py::init<>())
			.def(py::init<int, int, int>(), "year"_a, "month"_a, "day"_a)
			.def_readwrite("year", &XCDateInfo::year)
			.def_readwrite("month", &XCDateInfo::month)
			.def_readwrite("day", &XCDateInfo::day);

		py::class_<XCTimeInfo>(m, "XTimeInfo")
			.def(py::init<>())
			.def(py::init<int, int, int>(), "hour"_a, "minute"_a, "second"_a)
			.def_readwrite("hour", &XCTimeInfo::hour)
			.def_readwrite("minute", &XCTimeInfo::minute)
			.def_readwrite("second", &XCTimeInfo::second);

		py::class_<XCRange>(m, "XRange")
			.def(py::init<>())
			.def(py::init<int, int>(), "start"_a, "end"_a)
			.def_readwrite("start", &XCRange::start)
			.def_readwrite("end", &XCRange::end);

		py::class_<XCItemHeightInfo>(m, "XItemHeightInfo")
			.def(py::init<>())
			.def(py::init<int, int>(), "height"_a, "selHeight"_a)
			.def_readwrite("height", &XCItemHeightInfo::height)
			.def_readwrite("selHeight", &XCItemHeightInfo::selHeight);
	}
}													