#pragma once
#include "pch.h"
#include "xcgui/shape/XCShape.hpp"
#include "xcgui/XCStruct.hpp"

namespace xcgui {

	void declareShape(py::module& m) {
		py::class_<XCShape, XCWidget>(m, "XShape")
			PYCASTOBJECT(XCShape)	
			.def("removeShape", &XCShape::RemoveShape)
			.def("getZOrder", &XCShape::GetZOrder)
			.def("redraw", &XCShape::Redraw)
			.def("getWidth", &XCShape::GetWidth)
			.def("setPosition", &XCShape::SetPosition, "x"_a, "y"_a)
			.def("getPosition", [](XCShape& self) {
				XCPoint pt;
				self.GetPosition(&pt.x, &pt.y);
				return pt;
			})

			.def("setSize", &XCShape::SetSize, "width"_a, "height"_a)
			.def("getSize", [](XCShape& self) {
				XCSize info;
				self.GetSize(&info.width, &info.height);
				return info;
			})
			
			.def("setAlpha", &XCShape::SetAlpha, "alpha"_a)
			.def("getAlpha", &XCShape::GetAlpha)
				
			.def("getRect", [](XCShape& self) {
				XCRect info;
				self.GetRect((RECT*)&info);
				return info;
			})

			.def("setRectLogic", [](XCShape& self, const XCRect& rect, bool bRedraw) {
				return self.SetRectLogic((RECT*)&rect, bRedraw);
			}, "rect"_a, "redraw"_a)
			.def("getRectLogic", [](XCShape& self) {
				XCRect info;
				self.GetRectLogic((RECT*)&info);
				return info;
			})
			.def("getWndClientRect", [](XCShape& self) {
				XCRect info;
				self.GetWndClientRect((RECT*)&info);
				return info;
			})
			.def("getContentSize", [](XCShape& self) {
				XCSize info;
				self.GetContentSize((SIZE*)&info);
				return info;
			})

				
			.def("showLayout", &XCShape::ShowLayout, "enable"_a)
			.def("adjustLayout", &XCShape::AdjustLayout)
			.def("destroy", &XCShape::Destroy)
			
			;
	}
}