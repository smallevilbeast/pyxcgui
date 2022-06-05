						 #pragma once
#include "pch.h"
#include "xcgui/adapter/XCAdapterListView.hpp"
#include "xcgui/XCImage.hpp"

namespace xcgui {

	void declareAdapterListView(py::module& m) {

		py::class_<XCAdapterListView, XCAdapter>(m, "XAdapterListView")
			PYCASTOBJECT(XCAdapterListView)
			.def(py::init<>())
			.def("groupAddColumn", &XCAdapterListView::GroupAddColumn, "name"_a)
			.def("groupAddItemText", &XCAdapterListView::GroupAddItemText, "value"_a, "pos"_a=-1)
			.def("groupAddItemTextEx", &XCAdapterListView::GroupAddItemTextEx, "name"_a, "value"_a, "pos"_a = -1)
			.def("groupAddItemImage", [](XCAdapterListView& self, const XCImage& image, int iPos = -1) {
				return self.GroupAddItemImage(image.getImageHandle(), iPos);
			}, "image"_a, "pos"_a=-1)
			.def("groupAddItemImageEx", [](XCAdapterListView& self, const std::wstring& name, const XCImage& image, int iPos = -1) {
				return self.GroupAddItemImageEx(name, image.getImageHandle(), iPos);
			}, "name"_a, "image"_a, "pos"_a=-1)

			.def("groupSetText", &XCAdapterListView::GroupSetText, "group"_a, "column"_a, "value"_a)
			.def("groupSetTextEx", &XCAdapterListView::GroupSetTextEx, "group"_a, "name"_a, "value"_a)

			.def("groupSetImage", [](XCAdapterListView& self, int iGroup, int iColumn, const XCImage& image)
			{
				return self.GroupSetImage(iGroup, iColumn, image.getImageHandle());
			}, "group"_a, "column"_a, "image"_a)

			.def("groupSetImageEx", [](XCAdapterListView& self, int iGroup, const std::wstring& name, const XCImage& image)
			{
				return self.GroupSetImageEx(iGroup, name, image.getImageHandle());
			}, "group"_a, "name"_a, "image"_a)

			.def("groupGetText", &XCAdapterListView::GroupGetText, "group"_a, "column"_a)
			.def("groupGetTextEx", &XCAdapterListView::GroupGetTextEx, "group"_a, "name"_a)


			.def("groupGetImage", [](XCAdapterListView& self, int iGroup, int iColumn) -> XCImage* {
				auto handle = self.GroupGetImage(iGroup, iColumn);
				if (!handle) return nullptr;
				return new XCImage(handle);
			}, "item"_a, "column"_a, py::return_value_policy::take_ownership)

			.def("groupGetImageEx", [](XCAdapterListView& self, int iGroup, const std::wstring& name) -> XCImage* {
				auto handle = self.GroupGetImageEx(iGroup, name);
				if (!handle) return nullptr;
				return new XCImage(handle);
			}, "item"_a, "column"_a, py::return_value_policy::take_ownership)


			.def("itemAddColumn", &XCAdapterListView::ItemAddColumn, "name"_a)
			.def("groupGetCount", &XCAdapterListView::GroupGetCount)
			.def("itemGetCount", &XCAdapterListView::ItemGetCount, "group"_a)

			.def("itemAddItemText", &XCAdapterListView::ItemAddItemText, "group"_a, "value"_a, "pos"_a=-1)
			
			.def("itemAddItemTextEx", &XCAdapterListView::ItemAddItemTextEx, "group"_a, "name"_a, "value"_a, "pos"_a = -1)
			

			.def("itemAddItemImage", [](XCAdapterListView& self, int iGroup, const XCImage& image, int iPos = -1) {
				return self.ItemAddItemImage(iGroup, image.getImageHandle(), iPos);
			}, "group"_a, "image"_a, "pos"_a=-1)
			 .def("itemAddItemImageEx", [](XCAdapterListView& self, int iGroup, std::wstring& name, const XCImage& image, int iPos = -1) {
				return self.ItemAddItemImageEx(iGroup, name, image.getImageHandle(), iPos);
			}, "group"_a, "name"_a, "image"_a, "pos"_a=-1)

			.def("groupDeleteItem", &XCAdapterListView::GroupDeleteItem, "group"_a)
			
			.def("groupDeleteAllChildItem", &XCAdapterListView::GroupDeleteAllChildItem, "group"_a)
			.def("itemDeleteItem", &XCAdapterListView::ItemDeleteItem,  "group"_a, "item"_a)

			.def("deleteAll", &XCAdapterListView::DeleteAll)
			.def("deleteAllGroup", &XCAdapterListView::DeleteAllGroup)
			.def("deleteAllItem", &XCAdapterListView::DeleteAllItem)
			.def("deleteColumnGroup", &XCAdapterListView::DeleteColumnGroup, "column"_a)
			.def("deleteColumnItem", &XCAdapterListView::DeleteColumnItem, "column"_a)

			.def("itemGetText", &XCAdapterListView::ItemGetText, "group"_a, "item"_a, "column"_a)
			.def("itemGetTextEx", &XCAdapterListView::ItemGetTextEx, "group"_a, "item"_a, "name"_a)
			
			.def("itemGetImage", [](XCAdapterListView& self, int group, int item, int column) -> XCImage* {
				auto handle = self.ItemGetImage(group, item, column);
				if (!handle) return nullptr;
				return new XCImage(handle);
			}, "group"_a, "item"_a, "column"_a, py::return_value_policy::take_ownership)
			.def("itemGetImageEx", [](XCAdapterListView& self, int group, int item, const std::wstring& name) -> XCImage* {
				auto handle = self.ItemGetImageEx(group, item, name);
				if (!handle) return nullptr;
				return new XCImage(handle);
			}, "group"_a, "item"_a, "name"_a, py::return_value_policy::take_ownership)

			.def("itemSetText", &XCAdapterListView::ItemSetText, "group"_a, "item"_a, "column"_a, "value"_a)
			.def("itemSetTextEx", &XCAdapterListView::ItemSetTextEx, "group"_a, "item"_a, "name"_a, "value"_a)

			.def("itemSetImage", [](XCAdapterListView& self, int group, int item, int iColumn, const XCImage& image){
				return self.ItemSetImage(group, item, iColumn, image.getImageHandle());
			}, "group"_a, "item"_a, "column"_a, "image"_a)
			.def("itemSetImageEx", [](XCAdapterListView& self, int group, int item, const std::wstring& name, const XCImage& image){
				return self.ItemSetImageEx(group, item, name, image.getImageHandle());
			}, "group"_a, "item"_a, "name"_a, "image"_a)
		
		;
	}
}