#pragma once
#include "pch.h"
#include "xcgui/XCFont.hpp"
#include "xcgui/XCStruct.hpp"

namespace xcgui {

	void declareFont(py::module& m) {

		

		py::class_<XCFont, XCObject>(m, "XFont")
			.def(py::init([](int size) {
				auto font = new XCFont(size);
				return font;
			}), "size"_a, py::return_value_policy::take_ownership)

			.def_static("createFromName", [](const std::wstring& name, int size, int style) -> XCFont* {
				auto pFont = new XCFont();
				if (!pFont->CreateEx(name, size, style)) {
					return nullptr;
				}
				return pFont;
				}, "name"_a, "size"_a, "style"_a, py::return_value_policy::take_ownership)

			.def_static("createFromGdiFont", [](intptr_t pGdiFont) -> XCFont* {
				auto pFont = new XCFont();
				if (!pFont->CreateFromFont((void*)pGdiFont)) {
					return nullptr;
				}
				return pFont;
				}, "pGdiFont"_a, py::return_value_policy::take_ownership)

			.def_static("createFromFile", [](const std::wstring& fontFile, int size, int style) -> XCFont* {
				auto pFont = new XCFont();
				if (!pFont->CreateFromFile(fontFile, size, style)) {
					return nullptr;
				}
				return pFont;
				}, "fontFile"_a, "size"_a, "style"_a, py::return_value_policy::take_ownership)

			.def_static("createFromMem", [](const py::bytes& data, int size, int style) -> XCFont* {
				auto pFont = new XCFont();
				if (!pFont->CreateFromMem(data, size, style)) {
					return nullptr;
				}
				return pFont;
				}, "data"_a, "size"_a, "style"_a, py::return_value_policy::take_ownership)

			.def_static("createFromRes", [](int id, const std::wstring& typeName, int fontSize, int style, uintptr_t hModule) -> XCFont* {
				auto pFont = new XCFont();
				if (!pFont->CreateFromRes(id, typeName, fontSize, style, (HMODULE)hModule)) {
					return nullptr;
				}
				return pFont;
				}, "resId"_a, "typeName"_a, "size"_a, "style"_a, "hModule"_a, py::return_value_policy::take_ownership)

			.def("getGdiFont", [](XCFont& self) {
					return (uintptr_t)self.GetFont();
				})

			.def("getFontInfo", [](XCFont& self) -> XCFontInfo {
					font_info_ lFontInfo;
					self.GetFontInfo(&lFontInfo);
					XCFontInfo xFontInfo(lFontInfo.name, lFontInfo.nSize, lFontInfo.nStyle);
					return xFontInfo;
				})

			.def("enableAutoDestroy", &XCFont::EnableAutoDestroy, "enable"_a)
			.def("addRef", &XCFont::AddRef)
			.def("release", &XCFont::Release)
			.def("getRefCount", &XCFont::GetRefCount)
			.def("destroy", &XCFont::Destroy);
		;
	}
}