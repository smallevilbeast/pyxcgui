						   				 					 							#pragma once
#include "pch.h"
#include "xcgui/element/XCScrollView.hpp"
#include "xcgui/element/XCButton.hpp"
#include "binding/manager/XCastManager.hpp"

namespace xcgui {

	void declareScrollView(py::module& m) {
		py::class_<XCScrollView, XCElement>(m, "XScrollView")
			.def(py::init([](int x, int y, int cx, int cy, XCObjectUI* parent = nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCScrollView obj(x, y, cx, cy, handle);
				return obj;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a = nullptr)

		.	def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCScrollView obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)

			.def("setTotalSize", &XCScrollView::SetTotalSize, "width"_a, "height"_a)
			.def("getTotalSize", [](XCScrollView& self) {
				XCSize size;
				self.GetTotalSize((SIZE*)&size);
				return size;
			})

			.def("setLineSize", &XCScrollView::SetLineSize, "width"_a, "height"_a)
			.def("getLineSize", [](XCScrollView& self) {
				XCSize size;
				self.GetLineSize((SIZE*)&size);
				return size;
			})

			.def("setScrollBarSize", &XCScrollView::SetScrollBarSize, "size"_a)
			.def("getViewPosH", &XCScrollView::GetViewPosH)
			.def("getViewPosV", &XCScrollView::GetViewPosV)
			.def("getViewWidth", &XCScrollView::GetViewWidth)
			.def("getViewHeight", &XCScrollView::GetViewHeight)

			.def("getViewRect", [](XCScrollView& self) {
				XCRect info;
				self.GetViewRect((RECT*)&info);
				return info;
			})

			.def("getScrollBarH", [](XCScrollView& self)  -> XCObject* {
				auto handle = self.GetScrollBarH();
				return XCastManager::GetInstance()->CastObject(handle);
			})
			.def("getScrollBarV", [](XCScrollView& self)  -> XCObject* {
				auto handle = self.GetScrollBarV();
				return XCastManager::GetInstance()->CastObject(handle);
			})

			.def("scrollPosH", &XCScrollView::ScrollPosH, "pos"_a)
			.def("scrollPosV", &XCScrollView::ScrollPosV, "pos"_a)
			.def("scrollPosXH", &XCScrollView::ScrollPosXH, "pos"_a)
			.def("scrollPosYV", &XCScrollView::ScrollPosYV, "pos"_a)


			.def("showSBarH", &XCScrollView::ShowSBarH, "enable"_a)
			.def("showSBarV", &XCScrollView::ShowSBarV, "enable"_a)
			.def("enableAutoShowScrollBar", &XCScrollView::EnableAutoShowScrollBar, "enable"_a)
			.def("scrollLeftLine", &XCScrollView::ScrollLeftLine)
			.def("scrollRightLine", &XCScrollView::ScrollRightLine)
			.def("scrollTopLine", &XCScrollView::ScrollTopLine)
			.def("scrollBottomLine", &XCScrollView::ScrollBottomLine)
			.def("scrollLeft", &XCScrollView::ScrollLeft)
			.def("scrollRight", &XCScrollView::ScrollRight)
			.def("scrollTop", &XCScrollView::ScrollTop)
			.def("scrollBottom", &XCScrollView::ScrollBottom)
	
			;
	}
}