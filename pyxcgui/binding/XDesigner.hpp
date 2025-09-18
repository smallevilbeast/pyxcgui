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

			.def_static("loadLayoutEx", [](const std::wstring& fileName, const std::wstring& prefixName = L"", XCObject* parent = nullptr, uintptr_t parentHWND = 0, uintptr_t attachHWND = 0) -> XCObject* {
				HXCGUI parentHandle = NULL;
				if (parent) {
					parentHandle = parent->GetHandle();
				}
				auto handle = XCDesigner::LoadLayoutEx(fileName, prefixName, parentHandle, (HWND)parentHWND, (HWND)attachHWND);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "fileName"_a, "prefixName"_a = L"", "parent"_a = nullptr, "parentHWND"_a = 0, "attachHWND"_a = 0, py::return_value_policy::take_ownership)

			.def_static("loadLayoutZipEx", [](const std::wstring& zipFileName,
				const std::wstring& fileName,
				const std::wstring& password = L"",
				const std::wstring& prefixName = L"",
				XCObject* parent = nullptr,
				uintptr_t parentHWND = 0,
				uintptr_t attachHWND = 0) -> XCObject* {
				HXCGUI parentHandle = NULL;
				if (parent) {
					parentHandle = parent->GetHandle();
				}
				auto handle = XCDesigner::LoadLayoutZipEx(zipFileName, fileName, password, prefixName, parentHandle, (HWND)parentHWND, (HWND)attachHWND);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "zipFileName"_a, "fileName"_a, "password"_a = L"", "prefixName"_a = L"", "parent"_a = nullptr, "parentHWND"_a = 0, "attachHWND"_a = 0, py::return_value_policy::take_ownership)

			.def_static("loadLayoutZipMemEx", [](const py::bytes& data,
				const std::wstring& fileName,
				const std::wstring& password = L"",
				const std::wstring& prefixName = L"",
				XCObject* parent = nullptr,
				uintptr_t parentHWND = 0,
				uintptr_t attachHWND = 0) -> XCObject* {
				HXCGUI parentHandle = NULL;
				if (parent) {
					parentHandle = parent->GetHandle();
				}
				auto handle = XCDesigner::LoadLayoutZipMemEx(data, fileName, password, prefixName, parentHandle, (HWND)parentHWND, (HWND)attachHWND);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "data"_a, "fileName"_a, "password"_a = L"", "prefixName"_a = L"", "parent"_a = nullptr, "parentHWND"_a = 0, "attachHWND"_a = 0, py::return_value_policy::take_ownership)

			.def_static("loadLayoutFromStringEx", [](const std::string& xml, const std::wstring& prefixName = L"", XCObject* parent = nullptr, uintptr_t parentHWND = 0, uintptr_t attachHWND = 0) -> XCObject* {
				HXCGUI parentHandle = NULL;
				if (parent) {
					parentHandle = parent->GetHandle();
				}
				auto handle = XCDesigner::LoadLayoutFromStringEx(xml, prefixName, parentHandle, (HWND)parentHWND, (HWND)attachHWND);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "xml"_a, "prefixName"_a = L"", "parent"_a = nullptr, "parentHWND"_a = 0, "attachHWND"_a = 0, py::return_value_policy::take_ownership)

			.def_static("loadLayoutFromStringUtf8Ex", [](const std::string& xml, const std::wstring& prefixName = L"", XCObject* parent = nullptr, uintptr_t parentHWND = 0, uintptr_t attachHWND = 0) -> XCObject* {
				HXCGUI parentHandle = NULL;
				if (parent) {
					parentHandle = parent->GetHandle();
				}
				auto handle = XCDesigner::LoadLayoutFromStringUtf8Ex(xml, prefixName, parentHandle, (HWND)parentHWND, (HWND)attachHWND);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "xml"_a, "prefixName"_a = L"", "parent"_a = nullptr, "parentHWND"_a = 0, "attachHWND"_a = 0, py::return_value_policy::take_ownership)

			// 3.3.8 新增
			.def_static("loadLayoutZipResEx", [](int id, const std::wstring& fileName, const std::wstring& password = L"", const std::wstring& prefixName = L"", XCObject* parent = nullptr, uintptr_t parentHWND = 0, uintptr_t attachHWND = 0, uintptr_t hModule = 0) -> XCObject* {
				HXCGUI parentHandle = NULL;
				if (parent) {
					parentHandle = parent->GetHandle();
				}
				auto handle = XC_LoadLayoutZipResEx(id, fileName.c_str(), password.empty() ? NULL : password.c_str(), prefixName.empty() ? NULL : prefixName.c_str(), parentHandle, (HWND)parentHWND, (HWND)attachHWND, (HMODULE)hModule);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "id"_a, "fileName"_a, "password"_a = L"", "prefixName"_a = L"", "parent"_a = nullptr, "parentHWND"_a = 0, "attachHWND"_a = 0, "hModule"_a = 0, py::return_value_policy::take_ownership)

		;
	}

}