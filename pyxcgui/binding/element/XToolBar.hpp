#pragma once
#include "pch.h"
#include "xcgui/element/XCToolBar.hpp"
#include "xcgui/XCStruct.hpp"
#include "binding/manager/XCastManager.hpp"
#include "xcgui/utils/Color.hpp"

namespace xcgui {

	void declareToolbar(py::module& m) {
		py::class_<XCToolBar, XCElement>(m, "XToolBar")
			PYCASTOBJECT(XCToolBar)
			PYOBJECTVALID(XCToolBar, XC_TOOLBAR)
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCToolBar obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCToolBar obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)


			.def("insertEle", [](XCToolBar& self, const XCElement& ele, int index) {
				self.InsertEle(ele.getEleHandle(), index);
			}, "ele"_a, "index"_a)

			.def("insertSeparator", &XCToolBar::InsertSeparator, "index"_a=-1, 
				"color"_a= (uint32_t)(COLORREF_MAKE(128, 128, 128, 255) & 0xFFFFFFFF))

			.def("enableButtonMenu", &XCToolBar::EnableButtonMenu, "enable"_a)
			.def("getEle", [](XCToolBar& self, int index) -> XCObject* {
				auto handel = self.GetEle(index);
				return XCastManager::GetInstance()->CastObject(handel);
			}, "index"_a)
			.def("getButtonLeft", [](XCToolBar& self)  -> XCObject* {
				auto handle = self.GetButtonLeft();
				return XCastManager::GetInstance()->CastObject(handle);
			})
			.def("getButtonRight", [](XCToolBar& self)  -> XCObject* {
				auto handle = self.GetButtonRight();
				return XCastManager::GetInstance()->CastObject(handle);
			})
			.def("getButtonMenu", [](XCToolBar& self) -> XCObject* {
				auto handle = self.GetButtonMenu();
				return XCastManager::GetInstance()->CastObject(handle);
			})

			.def("setSpace", &XCToolBar::SetSpace, "size"_a)
			.def("deleteEle", &XCToolBar::DeleteEle, "index"_a)
			.def("deleteAllEle", &XCToolBar::DeleteAllEle)
	
			;
	}
}