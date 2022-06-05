#pragma once
#include "pch.h"
#include "xcgui/bkmanager/XCBkObject.hpp"
#include "xcgui/XCImage.hpp"
#include "xcgui/XCFont.hpp"
#include "xcgui/XCStruct.hpp"

namespace xcgui {

	void declareBkObject(py::module& m) {
		py::class_<XCBkObject>(m, "XBkObject")
			PYCASTOBJECT(XCBkObject)
			.def("setMargin", &XCBkObject::SetMargin, "left"_a, "top"_a, "right"_a, "bottom"_a)
			.def("setAlign", &XCBkObject::SetAlign, "flags"_a)
			.def("setImage", [](XCBkObject& self, const XCImage& image) {
				self.SetImage(image.getImageHandle());
			}, "image"_a)
			.def("setAlign", &XCBkObject::SetAlign, "flags"_a)
			.def("setFillColor", &XCBkObject::SetFillColor, "color"_a)
			.def("setBorderWidth", &XCBkObject::SetBorderWidth, "width"_a)
			.def("setBorderColor", &XCBkObject::SetBorderColor, "color"_a)
			.def("setRectRoundAngle", &XCBkObject::SetRectRoundAngle, "leftTop"_a, "leftBottom"_a, "rightTop"_a, "rightBottom"_a)
			.def("enableFill", &XCBkObject::EnableFill, "enable"_a)
			.def("enableBorder", &XCBkObject::EnableBorder, "enable"_a)
			.def("setText", &XCBkObject::SetText, "text"_a)
			
			.def("setFont", [](XCBkObject& self, const XCFont& font) {
				self.SetFont(font.getFontHandle());
			}, "font"_a)

			.def("setTextAlign", &XCBkObject::SetTextAlign, "align"_a)
			.def("getMargin", [](XCBkObject& self) {
				XCRect rect;
				self.GetMargin((marginSize_*)&rect);
				return rect;
			})

			.def("getAlign", &XCBkObject::GetAlign)

			.def("getImage", [](XCBkObject& self) -> XCImage* {
				auto handle = self.GetImage();
				if (!handle) {
					return nullptr;
				}
				return new XCImage(handle);
			}, py::return_value_policy::take_ownership)

			.def("getRotate", &XCBkObject::GetRotate)
			.def("getFillColor", &XCBkObject::GetFillColor)
			.def("getBorderColor", &XCBkObject::GetBorderColor)
			.def("getBorderWidth", &XCBkObject::GetBorderWidth)
			
			.def("getRectRoundAngle", [](XCBkObject& self) {
				XCRect rect;
				self.GetRectRoundAngle((RECT*)&rect);
				return rect;
			})

			.def("isFill", &XCBkObject::IsFill)
			.def("isBorder", &XCBkObject::IsBorder)
			.def("getText", &XCBkObject::GetText)
			.def("getFont", [](XCBkObject& self) -> XCFont* {
				auto handle = self.GetFont();
				if (!handle) {
					return nullptr;
				}
				return new XCFont(handle);
			}, py::return_value_policy::take_ownership)

			.def("getTextAlign", &XCBkObject::GetTextAlign)
			.def("getId", &XCBkObject::GetId);
	}
}