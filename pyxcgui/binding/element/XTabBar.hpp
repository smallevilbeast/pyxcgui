#pragma once
#include "pch.h"
#include "xcgui/element/XCTabBar.hpp"
#include "xcgui/XCStruct.hpp"
#include "binding/manager/XCastManager.hpp"

namespace xcgui {

	void declareTabBar(py::module& m) {
		py::class_<XCTabBar, XCElement>(m, "XTabBar")
			PYCASTOBJECT(XCTabBar)
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCTabBar obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCTabBar obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)

			.def("addLabel", &XCTabBar::AddLabel, "name"_a)
			.def("insertLabel", &XCTabBar::InsertLabel, "index"_a, "name"_a)
			.def("moveLabel", &XCTabBar::MoveLabel, "src"_a, "dest"_a)
			.def("deleteLabel", &XCTabBar::DeleteLabel, "index"_a)
			.def("deleteLabelAll", &XCTabBar::DeleteLabelAll)

			.def("moveLabel", &XCTabBar::MoveLabel, "src"_a, "dest"_a)
			.def("addLabel", &XCTabBar::AddLabel, "name"_a)
			.def("insertLabel", &XCTabBar::InsertLabel, "index"_a, "name"_a)
			.def("moveLabel", &XCTabBar::MoveLabel, "src"_a, "dest"_a)
			.def("addLabel", &XCTabBar::AddLabel, "name"_a)
			.def("insertLabel", &XCTabBar::InsertLabel, "index"_a, "name"_a)
			.def("moveLabel", &XCTabBar::MoveLabel, "src"_a, "dest"_a)
			.def("addLabel", &XCTabBar::AddLabel, "name"_a)
			.def("insertLabel", &XCTabBar::InsertLabel, "index"_a, "name"_a)
			.def("moveLabel", &XCTabBar::MoveLabel, "src"_a, "dest"_a)

			.def("getLabel", [](XCTabBar& self, int index) -> XCObject* {
				auto handel = self.GetLabel(index);
				return XCastManager::GetInstance()->CastObject(handel);
			}, "index"_a)

			.def("getLabelClose", [](XCTabBar& self, int index)  -> XCObject* {
				auto handle = self.GetLabelClose(index);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "index"_a)

			.def("getButtonLeft", [](XCTabBar& self)  -> XCObject* {
				auto handle = self.GetButtonLeft();
				return XCastManager::GetInstance()->CastObject(handle);
			})
			.def("getButtonRight", [](XCTabBar& self)  -> XCObject* {
				auto handle = self.GetButtonRight();
				return XCastManager::GetInstance()->CastObject(handle);
			})
			.def("getButtonDropMenu", [](XCTabBar& self) -> XCObject* {
				auto handle = self.GetButtonDropMenu();
				return XCastManager::GetInstance()->CastObject(handle);
			})

			.def("getSelect", &XCTabBar::GetSelect)
			.def("getLabelSpacing", &XCTabBar::GetLabelSpacing)
			.def("getLabelCount", &XCTabBar::GetLabelCount)
			.def("getIndexByEle", [](XCTabBar& self, const XCElement& ele) {
				return self.GetIndexByEle(ele.getEleHandle());
			}, "ele"_a)
			.def("setLabelSpacing", &XCTabBar::SetLabelSpacing, "spacing"_a)
			.def("setPadding", &XCTabBar::SetPadding, "left"_a, "top"_a, "right"_a, "bottom"_a)
			.def("setSelect", &XCTabBar::SetSelect, "index"_a)
			.def("setUp", &XCTabBar::SetUp)
			.def("setDown", &XCTabBar::SetDown)
			.def("enableTile", &XCTabBar::EnableTile, "enable"_a)
			.def("enableDropMenu", &XCTabBar::EnableDropMenu, "enable"_a)
			.def("enableClose", &XCTabBar::EnableClose, "enable"_a)
			.def("setCloseSize", [](XCTabBar& self, const XCSize& size) {
				self.SetCloseSize((SIZE*)&size);
			}, "size"_a)
			.def("setTurnButtonSize", [](XCTabBar& self, const XCSize& size) {
				self.SetTurnButtonSize((SIZE*)&size);
			}, "size"_a)

			.def("setLabelWidth", &XCTabBar::SetLabelWidth, "index"_a, "width"_a)
			.def("showLabel", &XCTabBar::ShowLabel, "index"_a, "enable"_a)
	
			;
	}
}