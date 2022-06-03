#pragma once
#include "pch.h"
#include "xcgui/adapter/XCAdapterMap.hpp"
#include "xcgui/XCImage.hpp"

namespace xcgui {

	void declareAdapterMap(py::module& m) {

		py::class_<XCAdapterMap, XCAdapter>(m, "XAdapterMap")
			.def(py::init<>())

			.def("addItemText", &XCAdapterMap::AddItemText, "name"_a, "value"_a)
			.def("addItemImage", [](XCAdapterMap& self, const std::wstring& name, const XCImage& image) {
				return self.AddItemImage(name, image.getImageHandle());
			}, "name"_a,"image"_a)
			.def("deleteItem", &XCAdapterMap::DeleteItem, "name"_a)
			.def("getCount", &XCAdapterMap::GetCount)
			.def("getItemText", &XCAdapterMap::GetItemText, "name"_a)

			.def("getItemImage", [](XCAdapterMap& self, const std::wstring& name) -> XCImage* {
				auto handle = self.GetItemImage(name);
				if (!handle) return nullptr;
				return new XCImage(handle);
			}, "name"_a, py::return_value_policy::take_ownership)

			.def("setItemText", &XCAdapterMap::SetItemText, "name"_a,"value"_a)
			.def("setItemImage", [](XCAdapterMap& self, const std::wstring& name, const XCImage& image){
				return self.SetItemImage(name, image.getImageHandle());
			}, "name"_a, "image"_a)

		
					;
	}
}