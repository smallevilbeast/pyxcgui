#pragma once
#include "pch.h"
#include "xcgui/XCResource.hpp"
#include "xcgui/bkmanager/XCBkManager.hpp"
#include "xcgui/XCImage.hpp"
#include "xcgui/XCFont.hpp"
#include "binding/manager/XCallbackManager.hpp"

namespace xcgui {

	void declareResource(py::module& m) {
		py::class_<XCResource>(m, "XResource")
			.def_static("enableDelayLoad", &XCResource::EnableDelayLoad, "enable"_a)
			.def_static("getColor", &XCResource::GetColor, "name"_a)
			.def_static("getIDValue", &XCResource::GetIDValue, "name"_a)
			.def_static("getBkManager", [](const std::wstring& name) -> XCBkManager* {
				auto handle = XCResource::GetBkM(name);
				if (!handle)
					return nullptr;

				return new XCBkManager(handle);
			}, "name"_a, py::return_value_policy::take_ownership)

			.def_static("getFont", [](const std::wstring& name) -> XCFont* {
				auto handle = XCResource::GetFont(name);
				if (!handle)
					return nullptr;

				return new XCFont(handle);
			}, "name"_a, py::return_value_policy::take_ownership)

			.def_static("getImage", [](const std::wstring& name) -> XCImage* {
				auto handle = XCResource::GetImage(name);
				if (!handle)
					return nullptr;

				return new XCImage(handle);
			}, "name"_a, py::return_value_policy::take_ownership)

			.def_static("getImageEx", [](const std::wstring& fileName, const std::wstring& name) -> XCImage* {
				auto handle = XCResource::GetImageEx(fileName, name);
				if (!handle)
					return nullptr;

				return new XCImage(handle);
			}, "filename"_a, "name"_a, py::return_value_policy::take_ownership)

			.def_static("setLoadFileCallback", [](const XResourceLoadFileCallback& callback) {
				XCallbackManager::GetInstance()->SetLoadFileCallback(callback);
			}, "callback"_a);
	}
}