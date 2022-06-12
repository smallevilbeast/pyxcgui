#pragma once
#include "pch.h"
#include "xcgui/XCObjectUI.hpp"
#include "binding/manager/XCastManager.hpp"
#include "xcgui/XCDesigner.hpp"

namespace xcgui {

	void declareObjectUI(py::module& m) {

		py::class_<XCObjectUI, XCObject>(m, "XObjectUI")
			PYCASTOBJECT(XCObjectUI)
			.def("setStyle", &XCObjectUI::SetStyle, "style"_a)
			.def("getStyle", &XCObjectUI::GetStyle)
			.def("enableCss", &XCObjectUI::EnableCSS, "enable"_a)
			.def("setCssName", &XCObjectUI::SetCssName, "name"_a)
			.def("getCssName", &XCObjectUI::GetCssName)

			.def("findObjectByName", [](XCObjectUI& self, const std::wstring& name) -> XCObject* {
				auto handle = self.FindObjectByName(name);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "name"_a, py::return_value_policy::take_ownership)
			.def("findObjectByUID", [](XCObjectUI& self, int nId) -> XCObject* {
				auto handle = self.FindObjectByUID(nId);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "nID"_a, py::return_value_policy::take_ownership)
			.def("findObjectByUIDName", [](XCObjectUI& self, const std::wstring& name) -> XCObject* {
				auto handle = self.FindObjectByUIDName(name);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "name"_a, py::return_value_policy::take_ownership)

			.def("loadLayout", [](XCObjectUI& self, const std::wstring& fileName, 
				XCObject* parent=nullptr, uintptr_t attachHWND=0) -> bool {
				
				HXCGUI parentHandle = NULL;
				if (parent) {
					parentHandle = parent->GetHandle();
				}
				auto handle = XCDesigner::LoadLayout(fileName, parentHandle, (HWND)attachHWND);
				self.SetHandle(handle);

				return XC_IsHWINDOW(handle);

			}, "fileName"_a, "parent"_a=nullptr, "attachHWND"_a=0)

		   .def("loadLayoutFromString", [](XCObjectUI& self, const std::string& xml,
			   XCObject* parent=nullptr, uintptr_t attachHWND=0) -> bool {
				HXCGUI parentHandle = NULL;
				if (parent) {
					parentHandle = parent->GetHandle();
				}
				auto handle = XCDesigner::LoadLayoutFromString(xml, parentHandle, (HWND)attachHWND);
				self.SetHandle(handle);
				return XC_IsHWINDOW(handle);
			}, "xml"_a, "parent"_a=nullptr, "attachHWND"_a=0)

			.def("loadLayoutZip", [](XCObjectUI& self, const std::wstring& zipFileName,
				const std::wstring& fileName, const std::wstring& password,
				XCObject* parent=nullptr, uintptr_t attachHWND=0) -> bool {
				HXCGUI parentHandle = NULL;
				if (parent) {
					parentHandle = parent->GetHandle();
				}
				auto handle = XCDesigner::LoadLayoutZip(fileName, fileName, password, parentHandle, (HWND)attachHWND);
				self.SetHandle(handle);
				return XC_IsHWINDOW(handle);

			}, "zipFileName"_a, "fileName"_a, "password"_a, "parent"_a = nullptr, "attachHWND"_a = 0)

			.def("loadLayoutZipMem", [](XCObjectUI& self, const py::bytes& data,
				const std::wstring& fileName, const std::wstring& password,
				XCObject* parent=nullptr, uintptr_t attachHWND=0) -> bool {
				HXCGUI parentHandle = NULL;
				if (parent) {
					parentHandle = parent->GetHandle();
				}
				auto handle = XCDesigner::LoadLayoutZipMem(data, fileName, password, parentHandle, (HWND)attachHWND);
				self.SetHandle(handle);
				return XC_IsHWINDOW(handle);

			}, "data"_a, "fileName"_a, "password"_a, "parent"_a = nullptr, "attachHWND"_a = 0)
			;

	}
}