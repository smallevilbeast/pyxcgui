#pragma once
#include "pch.h"
#include "xcgui/element/XCButton.hpp"
#include "xcgui/XCImage.hpp"
#include "binding/manager/XCastManager.hpp"

namespace xcgui {

	void declareButton(py::module& m) {
		py::class_<XCButton, XCElement>(m, "XButton")
			PYCASTOBJECT(XCButton)
			.def(py::init([](int x, int y, int cx, int cy, const std::wstring& text, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCButton button(x, y, cx, cy, text, handle);
				return button;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "text"_a, "parent"_a=nullptr)

			.def(py::init([](int cx, int cy, const std::wstring& text, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCButton button(0,0, cx, cy, text, handle);
				return button;
			}), "width"_a, "height"_a, "text"_a, "parent"_a=nullptr)

			.def("isCheck", &XCButton::IsCheck)
			.def("setCheck", &XCButton::SetCheck, "checked"_a)
			.def("setState", &XCButton::SetState, "state"_a)
			.def("getState", &XCButton::GetState)
			.def("getStateEx", &XCButton::GetStateEx)
			.def("setBtnTypeEx", &XCButton::SetBtnTypeEx, "nType"_a)
			.def("setGroupId", &XCButton::SetGroupID, "groupId"_a)
			.def("getGroupId", &XCButton::GetGroupID)
			.def("setBindEle", [](XCButton& self, const XCWidget& ele) {
				self.SetBindEle((HELE)ele.GetHandle());
			}, "ele"_a)
			.def("getBindEle", [](XCButton& self) {
				auto handle = self.GetBindEle();
				return XCastManager::GetInstance()->CastObject(handle);
			}, py::return_value_policy::reference)
			.def("setTextAlign", &XCButton::SetTextAlign, "flags"_a)
			.def("getTextAlign", &XCButton::GetTextAlign)
			.def("setIconAlign", &XCButton::SetIconAlign, "align"_a)
			.def("setOffset", &XCButton::SetOffset, "x"_a, "y"_a)
			.def("setOffsetIcon", &XCButton::SetOffsetIcon, "x"_a, "y"_a)
			.def("setIconSpace", &XCButton::SetIconSpace, "size"_a)
			.def("setText", &XCButton::SetText, "text"_a)
			.def("getText", &XCButton::GetText)
			.def("setIcon", [](XCButton& self, const XCImage& image) {
				self.SetIcon(image.getImageHandle());
			}, "image"_a)
			.def("setIconDisable", [](XCButton& self, const XCImage& image) {
				self.SetIconDisable(image.getImageHandle());
				}, "image"_a)
			.def("getIcon", [](XCButton& self, int nType) {
				auto handle = self.GetIcon(nType);
				return XCImage(handle);
			}, "nType"_a)
			.def("addAnimationFrame", [](XCButton& self, const XCImage& image, UINT elapse) {
				self.AddAnimationFrame(image.getImageHandle(), elapse);
				}, "image"_a, "elapse"_a)
			.def("getText", &XCButton::EnableAnimation, "enable"_a, "loopPlay"_a = false);
	}
}