#pragma once
#include "pch.h"
#include "xcgui/bkmanager/XCBkManager.hpp"
#include "xcgui/bkmanager/XCBkObject.hpp"
#include "xcgui/XCImage.hpp"
#include "xcgui/XCDraw.hpp"
#include "xcgui/XCStruct.hpp"

namespace xcgui {

	void declareBkManager(py::module& m) {

		py::class_<XCBkManager, XCObject>(m, "XBkManager")
			.def(py::init<>())
			.def("setInfo", &XCBkManager::SetInfo, "text"_a)
			.def("addInfo", &XCBkManager::AddInfo, "text"_a)
			.def("addBorder", &XCBkManager::AddBorder, "state"_a, "color"_a, "width"_a, "bkId"_a=0)
			.def("addFill", &XCBkManager::AddFill, "state"_a, "color"_a, "bkId"_a)
			.def("addImage", [](XCBkManager& self, int state, const XCImage& image, int bkId=0) {
				self.AddImage(state, image.getImageHandle(), bkId);
			}, "state"_a, "image"_a, "bkId"_a = 0)
			.def("getCount", &XCBkManager::GetCount)
			.def("clear", &XCBkManager::Clear)
			.def("draw", [](XCBkManager& self, int state, const XCDraw& draw, const XCRect& rect) {
				return self.Draw(state, draw.getDrawHandle(), (RECT*)&rect);
			}, "state"_a, "draw"_a, "rect"_a)
			.def("drawEx", [](XCBkManager& self, int state, const XCDraw& draw, const XCRect& rect, int stateEx) {
				return self.DrawEx(state, draw.getDrawHandle(), (RECT*)&rect, stateEx);
			}, "state"_a, "draw"_a, "rect"_a, "stateEx"_a)
			.def("getStateTextColor", [](XCBkManager& self, int state) -> COLORREF {
				COLORREF color;
				if (!self.GetStateTextColor(state, &color))
					return 0;
				return color;
			}, "state"_a)
			.def("getBkObjectHandle", &XCBkManager::GetBkObject, "bkId"_a)
			.def("getBkObject", [](XCBkManager& self, int bkId) -> XCBkObject* {
				auto handle = self.GetBkObject(bkId);
				if (!handle) {
					return nullptr;
				}
				return new XCBkObject(handle);

			}, "bkId"_a, py::return_value_policy::take_ownership)

			.def("enableAutoDestroy", &XCBkManager::EnableAutoDestroy, "enable"_a)
			.def("addRef", &XCBkManager::AddRef)
			.def("release", &XCBkManager::Release)
			.def("getRefCount", &XCBkManager::GetRefCount)
			.def("destroy", &XCBkManager::Destroy);
	}
}