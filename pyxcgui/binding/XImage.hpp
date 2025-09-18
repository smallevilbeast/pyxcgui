#pragma once
#include "pch.h"
#include "xcgui/XCImage.hpp"
#include "xcgui/XCImageSrc.hpp"
#include "xcgui/XCSvg.hpp"

namespace xcgui {

	void declareImage(py::module& m) {

		py::class_<XCImage, XCObject>(m, "XImage")
			PYCASTOBJECT(XCImage)
			PYOBJECTVALID(XCImage, XC_IMAGE)
			.def_static("loadFile", [](const std::wstring& fileName) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->LoadFile(fileName)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
			}, "filename"_a, py::return_value_policy::take_ownership)

			.def_static("loadSrc", [](const XCImageSrc& imageSrc) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->loadSrc(imageSrc.getImageSrcHandle())) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "imageSrc"_a, py::return_value_policy::take_ownership)
			
			.def_static("loadFileAdaptive", [](const std::wstring& fileName, int leftSize, int topSize, int rightSize, int bottomSize) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->LoadFileAdaptive(fileName, leftSize, topSize, rightSize, bottomSize)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "fileName"_a, "leftSize"_a, "topSize"_a, "rightSize"_a, "bottomSize"_a, py::return_value_policy::take_ownership)
				
			.def_static("loadFileRect", [](const std::wstring& fileName, int x, int y, int cx, int cy) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->LoadFileRect(fileName, x, y, cx, cy)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "fileName"_a, "x"_a, "y"_a, "cx"_a, "cy"_a, py::return_value_policy::take_ownership)
				
			.def_static("loadRes", [](int id, const std::wstring& typeName, uintptr_t hModule) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->LoadRes(id, typeName, (HMODULE)hModule)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "resId"_a, "typeName"_a, "hModule"_a, py::return_value_policy::take_ownership)	
				
			.def_static("loadZip", [](const std::wstring& zipFileName, const std::wstring& fileName, const std::wstring& password) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->LoadZip(zipFileName, fileName, password)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "zipFileName"_a, "fileName"_a, "password"_a, py::return_value_policy::take_ownership)	


			.def_static("loadZipAdaptive", [](const std::wstring& zipFileName, const std::wstring& fileName, 
				const std::wstring& password, int x1, int x2, int y1, int y2) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->LoadZipAdaptive(zipFileName, fileName, password, x1, x2, y1, y2)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "zipFileName"_a, "fileName"_a, "password"_a,"x1"_a,"x2"_a,"y1"_a,"y2"_a, py::return_value_policy::take_ownership)

			.def_static("loadZipRect", [](const std::wstring& zipFileName, const std::wstring& fileName, 
				const std::wstring& password, int x, int y, int cx, int cy) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->LoadZipRect(zipFileName, fileName, password, x, y, cx, cy)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "zipFileName"_a, "fileName"_a, "password"_a,"x"_a,"y"_a,"cx"_a,"cy"_a, py::return_value_policy::take_ownership)


			.def_static("loadZipMem", [](const py::bytes& data, const std::wstring& fileName, const std::wstring& password) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->LoadZipMem(data, fileName, password)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "data"_a, "fileName"_a, "password"_a, py::return_value_policy::take_ownership)

			// 3.3.8 新增
			.def_static("loadZipRes", [](int id, const std::wstring& fileName, const std::wstring& password = L"", uintptr_t hModule = 0) -> XCImage* {
				auto pImage = new XCImage();
				const wchar_t* pPassword = password.empty() ? NULL : password.c_str();
				pImage->SetHandle(XImage_LoadZipRes(id, fileName.c_str(), pPassword, (HMODULE)hModule));
				if (!pImage->GetHandle()) {
					delete pImage;
					return nullptr;
				}
				return pImage;
			}, "id"_a, "fileName"_a, "password"_a = L"", "hModule"_a = 0, py::return_value_policy::take_ownership)

			.def_static("loadMemory", [](const py::bytes& data) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->LoadMemory(data)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "data"_a, py::return_value_policy::take_ownership)	
					
					
			.def_static("loadMemoryRect", [](const py::bytes& data, int x, int y, int cx, int cy) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->LoadMemoryRect(data, x, y, cx, cy)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "data"_a, "x"_a, "y"_a, "cx"_a, "cy"_a, py::return_value_policy::take_ownership)
					
			
			.def_static("loadMemoryAdaptive", [](const py::bytes& data, int leftSize, int topSize, int rightSize, int bottomSize) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->LoadMemoryAdaptive(data, leftSize, topSize, rightSize, bottomSize)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "data"_a, "leftSize"_a, "topSize"_a, "rightSize"_a, "bottomSize"_a, py::return_value_policy::take_ownership)		
					
					
			.def_static("loadFromImage", [](uintptr_t gdiImageHandle) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->LoadFromImage((void*)gdiImageHandle)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "gdiImageHandle"_a, py::return_value_policy::take_ownership)		
					
					
			.def_static("loadFromExtractIcon", [](const std::wstring& fileName) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->LoadFromExtractIcon(fileName)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "fileName"_a, py::return_value_policy::take_ownership)		
					
			
			.def_static("loadFromHICON", [](uintptr_t hIcon) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->LoadFromHICON((HICON)hIcon)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "hIcon"_a, py::return_value_policy::take_ownership)
					
			
			.def_static("loadFromHBITMAP", [](uintptr_t hBitmap) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->LoadFromHBITMAP((HBITMAP)hBitmap)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "hBitmap"_a, py::return_value_policy::take_ownership)

			.def_static("loadSvg", [](const XCSvg& svg) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->LoadSvg(svg.getSvgHandle())) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "svg"_a, py::return_value_policy::take_ownership)

			.def_static("loadSvgFile", [](const std::wstring& fileName) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->LoadSvgFile(fileName)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "fileName"_a, py::return_value_policy::take_ownership)

			.def_static("loadSvgString", [](const std::wstring& data) -> XCImage* {
				auto pImage = new XCImage();
				if (!pImage->LoadSvgStringW(data)) {
					delete pImage;
					return nullptr;
				}
				return pImage;
				}, "data"_a, py::return_value_policy::take_ownership)


			.def("isStretch", &XCImage::IsStretch)
			.def("isTile", &XCImage::IsStretch)

			.def("getSvg", [](XCImage& self) -> XCSvg* {
				auto handle = self.GetSvg();
				if (!handle)
					return nullptr;
				return new XCSvg(handle);
			}, py::return_value_policy::take_ownership)

			.def("setDrawType", &XCImage::SetDrawType, "drawType"_a)
			.def("setDrawTypeAdaptive", &XCImage::SetDrawTypeAdaptive, "leftSize"_a, "topSize"_a, "rightSize"_a, "bottomSize"_a)
			.def("setTranColor", &XCImage::SetTranColor, "color"_a)
			.def("setTranColorEx", &XCImage::SetTranColorEx, "color"_a, "alpha"_a)
			.def("setRotateAngle", &XCImage::SetRotateAngle, "angle"_a)
			.def("setSplitEqual", &XCImage::SetSplitEqual, "count"_a, "index"_a)
			.def("enableTranColor", &XCImage::EnableTranColor, "enable"_a)
			.def("enableAutoDestroy", &XCImage::EnableAutoDestroy, "enable"_a)
			.def("enableCenter", &XCImage::EnableCenter, "enable"_a)
			.def("isCenter", &XCImage::IsCenter)
			.def("getWidth", &XCImage::GetWidth)
			.def("getHeight", &XCImage::GetHeight)
			.def("getImageSrc", [](XCImage& self) -> XCImageSrc* {
				auto handle = self.GetImageSrc();
				if (!handle)
					return nullptr;
				return new XCImageSrc(handle);
			}, py::return_value_policy::take_ownership)
			.def("addRef", &XCImage::AddRef)
			.def("release", &XCImage::Release)
			.def("getRefCount", &XCImage::GetRefCount)
			.def("destroy", &XCImage::Destroy)
			.def("setScaleSize", &XCImage::SetScaleSize, "width"_a, "height"_a)
			
			;

	}
}