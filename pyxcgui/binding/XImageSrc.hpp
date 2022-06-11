#pragma once
#include "pch.h"
#include "xcgui/XCImageSrc.hpp"

namespace xcgui {

	void declareImageSrc(py::module& m) {

		py::class_<XCImageSrc, XCObject>(m, "XImageSrc")
			PYCASTOBJECT(XCImageSrc)
			.def_static("loadFile", [](const std::wstring& fileName) -> XCImageSrc* {
				auto pImage = new XCImageSrc();
				if (!pImage->LoadFile(fileName)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "filename"_a, py::return_value_policy::take_ownership)


			.def_static("loadFileRect", [](const std::wstring& fileName, int x, int y, int cx, int cy) -> XCImageSrc* {
					auto pImage = new XCImageSrc();
					if (!pImage->LoadFileRect(fileName, x, y, cx, cy)) {
						delete pImage;
						return nullptr;
					}
					return pImage;
				}, "fileName"_a, "x"_a, "y"_a, "cx"_a, "cy"_a, py::return_value_policy::take_ownership)


 			.def_static("loadRes", [](int id, const std::wstring& typeName, uintptr_t hModule) -> XCImageSrc* {
				auto pImage = new XCImageSrc();
				if (!pImage->LoadRes(id, typeName, (HMODULE)hModule)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "resId"_a, "typeName"_a, "hModule"_a, py::return_value_policy::take_ownership)

			.def_static("loadZip", [](const std::wstring& zipFileName, const std::wstring& fileName, 
				const std::wstring& password) -> XCImageSrc* {
				auto pImage = new XCImageSrc();
				if (!pImage->LoadZip(zipFileName, fileName, password)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "zipFileName"_a, "fileName"_a, "password"_a, py::return_value_policy::take_ownership)


 			.def_static("loadZipRect", [](const std::wstring& zipFileName, const std::wstring& fileName, 
				const std::wstring& password, int x, int y, int cx, int cy) -> XCImageSrc* {
				auto pImage = new XCImageSrc();
				if (!pImage->LoadZipRect(zipFileName, fileName, password, x, y, cx, cy)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "zipFileName"_a, "fileName"_a, "password"_a,"x"_a,"y"_a,"cx"_a,"cy"_a, py::return_value_policy::take_ownership)

			.def_static("loadZipMem", [](const py::bytes& data, const std::wstring& fileName, const std::wstring& password) -> XCImageSrc* {
				auto pImage = new XCImageSrc();
				if (!pImage->LoadZipMem(data, fileName, password)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "data"_a, "fileName"_a, "password"_a, py::return_value_policy::take_ownership)

			.def_static("loadMemory", [](const py::bytes& data) -> XCImageSrc* {
				auto pImage = new XCImageSrc();
				if (!pImage->LoadMemory(data)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "data"_a, py::return_value_policy::take_ownership)	
					
					
			.def_static("loadMemoryRect", [](const py::bytes& data, int x, int y, int cx, int cy) -> XCImageSrc* {
				auto pImage = new XCImageSrc();
				if (!pImage->LoadMemoryRect(data, x, y, cx, cy)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "data"_a, "x"_a, "y"_a, "cx"_a, "cy"_a, py::return_value_policy::take_ownership)

			.def_static("loadFromImage", [](uintptr_t gdiImageHandle) -> XCImageSrc* {
				auto pImage = new XCImageSrc();
				if (!pImage->LoadFromImage((void*)gdiImageHandle)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "gdiImageHandle"_a, py::return_value_policy::take_ownership)		
					
					
			.def_static("loadFromExtractIcon", [](const std::wstring& fileName) -> XCImageSrc* {
				auto pImage = new XCImageSrc();
				if (!pImage->LoadFromExtractIcon(fileName)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "fileName"_a, py::return_value_policy::take_ownership)		
					
			
			.def_static("loadFromHICON", [](uintptr_t hIcon) -> XCImageSrc* {
				auto pImage = new XCImageSrc();
				if (!pImage->LoadFromHICON((HICON)hIcon)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "hIcon"_a, py::return_value_policy::take_ownership)
					
			
			.def_static("loadFromHBITMAP", [](uintptr_t hBitmap) -> XCImageSrc* {
				auto pImage = new XCImageSrc();
				if (!pImage->LoadFromHBITMAP((HBITMAP)hBitmap)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "hBitmap"_a, py::return_value_policy::take_ownership)

			.def("enableAutoDestroy", &XCImageSrc::EnableAutoDestroy, "enable"_a)
			.def("getWidth", &XCImageSrc::GetWidth)
			.def("getHeight", &XCImageSrc::GetHeight)
			.def("getFile", &XCImageSrc::GetFile)
			.def("addRef", &XCImageSrc::AddRef)
			.def("release", &XCImageSrc::Release)
			.def("getRefCount", &XCImageSrc::GetRefCount)
			.def("destroy", &XCImageSrc::Destroy);
	}
}