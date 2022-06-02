#pragma once
#include "pch.h"
#include "xcgui/XCSvg.hpp"
#include "xcgui/XCStruct.hpp"

namespace xcgui {

	void declareSvg(py::module& m) {

		py::class_<XCSvg, XCObject>(m, "XSvg")
			.def_static("loadFile", [](const std::wstring& filename) -> XCSvg* {
				auto pSvg = new XCSvg();
				if (!pSvg->LoadFile(filename.c_str())) {
					return nullptr;
				}
				return pSvg;
			}, "filename"_a, py::return_value_policy::take_ownership)

			.def_static("loadRes", [](int resId, const std::wstring& typeName, uintptr_t hModule) -> XCSvg* {
				auto pSvg = new XCSvg();
				if (!pSvg->LoadRes(resId, typeName, (HMODULE)hModule)) {
					return nullptr;
				}
				return pSvg;
			}, "resId"_a, "filename"_a, "hModule"_a, py::return_value_policy::take_ownership)

 			.def_static("loadString", [](const std::wstring& name) -> XCSvg* {
				auto pSvg = new XCSvg();
				if (!pSvg->LoadStringW(name)) {
					return nullptr;
				}
				return pSvg;
			}, "name"_a, py::return_value_policy::take_ownership)


   			.def_static("loadZip", [](const std::wstring& zipFileName, const std::wstring& fileName, const std::wstring& password) -> XCSvg* {
				auto pSvg = new XCSvg();
				if (!pSvg->LoadZip(zipFileName, fileName, password)) {
					return nullptr;
				}
				return pSvg;
			}, "zipFileName"_a, "fileName"_a, "password"_a, py::return_value_policy::take_ownership)


			.def("show", &XCSvg::Show, "enable"_a)
			.def("setAlpha", &XCSvg::SetAlpha, "alpha"_a)
			.def("getAlpha", &XCSvg::GetAlpha)
			.def("setPosition", &XCSvg::SetPosition, "x"_a, "y"_a)
			.def("getPosition", [](XCSvg& self) -> XCPoint {
				XCPoint point;
				self.GetPosition(&point.x, &point.y);
				return point;
			})
			.def("setRotate", &XCSvg::SetRotate, "angle"_a, "x"_a, "y"_a, "offset"_a)
			.def("getRotate", [](XCSvg& self) -> XCRotateInfo {
				XCRotateInfo info;
				self.GetRotate(&info.angle, &info.x, &info.y, &info.offset);
				return info;
			})
			.def("setRotateAngle", &XCSvg::SetRotateAngle, "angle"_a)
			.def("getRotateAngle", &XCSvg::GetRotateAngle)
			.def("setSize", &XCSvg::SetSize, "width"_a, "height"_a)
			.def("getSize", [](XCSvg& self) -> XCSize {
				XCSize info;
				self.GetSize(&info.width, &info.height);
				return info;
			})
			.def("getWidth", &XCSvg::GetWidth)
			.def("getHeight", &XCSvg::GetHeight)
			.def("getViewBox", [](XCSvg& self) -> XCRect {
				XCRect info;
				self.GetViewBox((RECT*)&info);
				return info;
			})
			.def("setUserFillColor", &XCSvg::SetUserFillColor, "color"_a, "enable"_a)
			.def("getUserFillColor", [](XCSvg& self) -> intptr_t {
				COLORREF color;
				if (!self.GetUserFillColor(&color))
					return 0;
				return color;
			})
			.def("setUserStrokeColor", &XCSvg::SetUserStrokeColor, "color"_a, "strokeWidth"_a, "enable"_a)
			.def("getUserStrokeColor", [](XCSvg& self) -> XCStrokeInfo {
				XCStrokeInfo info;
				self.GetUserStrokeColor(&info.color, &info.strokeWidth);
				return info;
			})
			.def("enableAutoDestroy", &XCSvg::EnableAutoDestroy, "enable"_a)
			.def("addRef", &XCSvg::AddRef)
			.def("release", &XCSvg::Release)
			.def("getRefCount", &XCSvg::GetRefCount)
			.def("destroy", &XCSvg::Destroy);;
	}
}