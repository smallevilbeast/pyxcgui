#pragma once
#include "pch.h"
#include "xcgui/XCDesigner.hpp"
#include "xcgui/XCObject.hpp"
#include "manager/XCastManager.hpp"

namespace xcgui {

	void declareDesigner(py::module& m) {
		py::class_<XCDesigner>(m, "XDesigner")
			.def_static("loadLayout", [](const std::wstring& fileName, XCObject* parent=nullptr, uintptr_t attachHWND=0) -> XCObject* {
				HXCGUI parentHandle = NULL;
				if (parent) {
					parentHandle = parent->GetHandle();
				}
				auto handle = XCDesigner::LoadLayout(fileName, parentHandle, (HWND)attachHWND);
				return XCastManager::GetInstance()->CastObject(handle);

			}, "fileName"_a, "parent"_a=nullptr, "attachHWND"_a=0, py::return_value_policy::take_ownership)

		   .def_static("loadLayoutFromString", [](const std::string& xml, XCObject* parent=nullptr, uintptr_t attachHWND=0) -> XCObject* {
				HXCGUI parentHandle = NULL;
				if (parent) {
					parentHandle = parent->GetHandle();
				}
				auto handle = XCDesigner::LoadLayoutFromString(xml, parentHandle, (HWND)attachHWND);
				return XCastManager::GetInstance()->CastObject(handle);

			}, "xml"_a, "parent"_a=nullptr, "attachHWND"_a=0, py::return_value_policy::take_ownership)

			.def_static("loadLayoutZip", [](const std::wstring& zipFileName,
				const std::wstring& fileName, const std::wstring& password,
				XCObject* parent=nullptr, uintptr_t attachHWND=0) -> XCObject* {
				HXCGUI parentHandle = NULL;
				if (parent) {
					parentHandle = parent->GetHandle();
				}
				auto handle = XCDesigner::LoadLayoutZip(fileName, fileName, password, parentHandle, (HWND)attachHWND);
				return XCastManager::GetInstance()->CastObject(handle);

			}, "zipFileName"_a, "fileName"_a, "password"_a, "parent"_a = nullptr, "attachHWND"_a = 0,
				py::return_value_policy::take_ownership)

			.def_static("loadLayoutZipMem", [](const py::bytes& data,
				const std::wstring& fileName, const std::wstring& password,
				XCObject* parent=nullptr, uintptr_t attachHWND=0) -> XCObject* {
				HXCGUI parentHandle = NULL;
				if (parent) {
					parentHandle = parent->GetHandle();
				}
				auto handle = XCDesigner::LoadLayoutZipMem(data, fileName, password, parentHandle, (HWND)attachHWND);
				return XCastManager::GetInstance()->CastObject(handle);

			}, "data"_a, "fileName"_a, "password"_a, "parent"_a = nullptr, "attachHWND"_a = 0,
				py::return_value_policy::take_ownership)

			.def_static("loadResource", &XCDesigner::LoadResource, "filename"_a)
			.def_static("loadResourceString", &XCDesigner::LoadResourceString, "xml"_a, "filename"_a)
			.def_static("loadResourceZip", &XCDesigner::LoadResourceZip, "zipFileName"_a, "filename"_a, "password"_a)
			.def_static("loadResourceZipMem", [](const py::bytes data, const std::wstring& fileName, const std::wstring& password) {
				return XCDesigner::LoadResourceZipMem(data, fileName, password);
			}, "data"_a, "filename"_a, "password"_a)

			.def_static("loadStyle", &XCDesigner::LoadStyle, "filename"_a)
			.def_static("loadStyleString", &XCDesigner::LoadStyleString, "xml"_a, "filename"_a)
			.def_static("loadStyleZip", &XCDesigner::LoadStyleZip, "zipFileName"_a, "filename"_a, "password"_a)
			.def_static("loadStyleZipMem", [](const py::bytes data, const std::wstring& fileName, const std::wstring& password) {
				return XCDesigner::LoadStyleZipMem(data, fileName, password);
			}, "data"_a, "filename"_a, "password"_a)

		;
	}

}