#pragma once
#include "pch.h"
#include "xcgui/element/XCPane.hpp"
#include "xcgui/window/XCFrameWindow.hpp"
#include "xcgui/XCDraw.hpp"


namespace xcgui {

	void declarePanel(py::module& m) {
		py::class_<XCPane, XCElement>(m, "XPane")
			.def(py::init([](const std::wstring& name, int width, int height, XCFrameWindow* parent) {
				HWINDOW handle = nullptr;
				if (parent) {
					handle = parent->GetWindowHandle();
				}
				XCPane obj(name, width, height, handle);
				return obj;
			}), "name"_a, "width"_a, "height"_a, "parent"_a = nullptr)

			.def("setView", [](XCPane& self, const XCElement& ele) {
				self.SetView(ele.getEleHandle());
			}, "ele"_a)

			.def("setTitle", &XCPane::SetTitle, "title"_a)
			.def("getTitle", &XCPane::GetTitle)

			.def("setCaptionHeight", &XCPane::SetCaptionHeight, "height"_a)
			.def("getCaptionHeight", &XCPane::GetCaptionHeight)
			
			.def("isShowPane", &XCPane::IsShowPane)
			.def("isGroupActivate", &XCPane::IsGroupActivate)

			.def("setSize", &XCPane::SetSize, "width"_a, "height"_a)

			.def("getState", &XCPane::GetState)

			.def("getViewRect", [](XCPane& self) {
				XCRect rect;
				self.GetViewRect((RECT*)&rect);
				return rect;
			})

			.def("hidePane", &XCPane::HidePane, "groupDelay"_a=false)
			.def("showPane", &XCPane::ShowPane, "groupActivate"_a)
			.def("dockPane", &XCPane::DockPane)
			.def("lockPane", &XCPane::LockPane)
			.def("floatPane", &XCPane::FloatPane)

			.def("drawPane", [](XCPane& self, const XCDraw& draw) {
				self.DrawPane(draw.getDrawHandle());
			}, "draw"_a)
			
			.def("setSelect", &XCPane::SetSelect)
				
			;
	}
}