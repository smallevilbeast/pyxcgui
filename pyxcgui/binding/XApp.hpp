#pragma once
#include "pch.h"
#include "xcgui/XCApp.hpp"
#include "manager/XEventManager.hpp"
#include "manager/XUserDataManager.hpp"
#include "manager/XCastManager.hpp"
#include "manager/XCallbackManager.hpp"

namespace xcgui {

	void declareApp(py::module& m) {
		py::class_<XCApp>(m, "XApp")
			.def(py::init<bool>(), py::arg("useD2D") = false)
			.def("run", &XCApp::Run, py::call_guard<py::gil_scoped_release>())
			.def("exit", [](XCApp& self) {
				XEventManager::GetInstance()->Release();
				XUserDataManager::GetInstance()->Release();
				XCallbackManager::GetInstance()->Release();
				self.Exit();
			})
			

			.def("addFileSearchPath", &XCApp::AddFileSearchPath, "path"_a)
			.def("enableAutoExitApp", &XCApp::EnableAutoExitApp, "enable"_a)
			.def("debugToFileInfo", &XCApp::DebugToFileInfo, "file"_a)
			.def("enableDebugFile", &XCApp::EnableDebugFile, "enable"_a)
			.def("enableErrorMessageBox", &XCApp::EnableErrorMessageBox, "enable"_a)
			.def("enableGdiDrawText", &XCApp::EnableGdiDrawText, "enable"_a)
			.def("enableResMonitor", &XCApp::EnableResMonitor, "enable"_a)
			.def("showLayoutFrame", &XCApp::ShowLayoutFrame, "enable"_a)
			.def("showSvgFrame", &XCApp::ShowSvgFrame, "enable"_a)
			.def("setLayoutFrameColor", &XCApp::SetLayoutFrameColor, "color"_a)
			.def("setPaintFrequency", &XCApp::SetPaintFrequency, "milliseconds"_a)
			.def("setTextRenderingHint", &XCApp::SetTextRenderingHint, "nType"_a)
			.def("setD2dTextRenderingMode", &XCApp::SetD2dTextRenderingMode, "mode"_a)

			// 3.3.8 新增
			.def("enableDPI", [](XCApp& self, bool enable) {
				XC_EnableDPI(enable);
			}, "enable"_a)
			.def("enableAutoDPI", [](XCApp& self, bool enable) {
				XC_EnableAutoDPI(enable);
			}, "enable"_a)
			.def("setWindowIcon", [](XCApp& self, uintptr_t hIcon) {
				XC_SetWindowIcon((HICON)hIcon);
			}, "hIcon"_a)
			.def_static("loadResourceZipRes", [](int id, const std::wstring& fileName, const std::wstring& password = L"", uintptr_t hModule = 0) {
				return XC_LoadResourceZipRes(id, fileName.c_str(), password.empty() ? NULL : password.c_str(), (HMODULE)hModule);
			}, "id"_a, "fileName"_a, "password"_a = L"", "hModule"_a = 0)
			.def_static("loadStyleZipRes", [](int id, const std::wstring& fileName, const std::wstring& password = L"", uintptr_t hModule = 0) {
				return XC_LoadStyleZipRes(id, fileName.c_str(), password.empty() ? NULL : password.c_str(), (HMODULE)hModule);
			}, "id"_a, "fileName"_a, "password"_a = L"", "hModule"_a = 0)
			;
	}
}