#include "pch.h"
#include "xcgui/window/XCFrameWindow.hpp"
#include "xcgui/XCElement.hpp"
#include "xcgui/XCStruct.hpp"

namespace xcgui {

	void declareFrameWindow(py::module& m) {

		py::class_<XCFrameWindow, XCWindow>(m, "XFrameWindow")
			PYCASTOBJECT(XCFrameWindow)
			PYOBJECTVALID(XCFrameWindow, XC_FRAMEWND)
			.def(py::init<>())
			.def(py::init([](int width, int height, const std::wstring& title) {
				XCFrameWindow window(0, 0, width, height, title, 0, window_style_default);
				return window;
				}), "width"_a, "height"_a, "title"_a)
			.def(py::init<int, int, int, int, const std::wstring&, uintptr_t, int>()
				, "x"_a, "y"_a, "width"_a, "height"_a, "title"_a, "hwndParent"_a, "xcStyle"_a=(int)window_style_default)
			
			.def(py::init<DWORD, DWORD, const std::wstring&,
						int, int, int, int, const std::wstring&, uintptr_t, int>()
				, "exStyle"_a, "style"_a, "className"_a, "x"_a, "y"_a, "width"_a, "height"_a,
				"title"_a, "hwndParent"_a, "xcStyle"_a=int(window_style_default))

			.def("attach", &XCFrameWindow::Attach, "hwnd"_a, "style"_a)
			.def("setView", [](XCFrameWindow& self, const XCElement& ele){
				self.SetView(ele.getEleHandle());
			}, "ele"_a)

			.def("setTabBarHeight", &XCFrameWindow::SetTabBarHeight, "height"_a)
			.def("setPaneSplitBarColor", &XCFrameWindow::SetPaneSplitBarColor, "color"_a)
			.def("saveLayoutToFile", &XCFrameWindow::SaveLayoutToFile, "filename"_a)
			.def("addPane", [](XCFrameWindow& self, const XCElement& dest, const XCElement& newEle, pane_align_ align){
				return self.AddPane(dest.getEleHandle(), newEle.getEleHandle(), align);
			}, "panelDest"_a, "paneNew"_a, "align"_a)

			.def("mergePane", [](XCFrameWindow& self, const XCElement& dest, const XCElement& newEle){
				return self.MergePane(dest.getEleHandle(), newEle.getEleHandle());
			}, "panelDest"_a, "paneNew"_a)

			.def("loadLayoutFile", [](XCFrameWindow& self, std::vector<XCElement> paneList, const std::wstring& fileName){
				std::vector<HELE> vEles;
				for (auto& ele : paneList) {
					vEles.emplace_back(ele.getEleHandle());
				}
				return self.LoadLayoutFile(&vEles[0], paneList.size(), fileName);
			}, "panelList"_a, "filename"_a)

			.def("getLayoutAreaRect", [](XCFrameWindow& self) {
				XCRect rect;
				self.GetLayoutAreaRect((RECT*)&rect);
				})

			// 3.3.5 新增
			.def("getDragFloatWndTopFlag", &XCFrameWindow::GetDragFloatWndTopFlag)
			;
	}
}