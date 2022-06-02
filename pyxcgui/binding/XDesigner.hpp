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

			}, "fileName"_a, "parent"_a=nullptr, "attachHWND"_a=0, py::return_value_policy::reference)

		   .def_static("loadLayoutFromString", [](const std::string& xml, XCObject* parent=nullptr, uintptr_t attachHWND=0) -> XCObject* {
				HXCGUI parentHandle = NULL;
				if (parent) {
					parentHandle = parent->GetHandle();
				}
				auto handle = XCDesigner::LoadLayoutFromString(xml, parentHandle, (HWND)attachHWND);
				return XCastManager::GetInstance()->CastObject(handle);

			}, "xml"_a, "parent"_a=nullptr, "attachHWND"_a=0, py::return_value_policy::reference)

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
				py::return_value_policy::reference)

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
				py::return_value_policy::reference)
		;
	}

}