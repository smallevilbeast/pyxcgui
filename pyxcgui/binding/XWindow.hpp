#include "pch.h"
#include "xcgui/XCWindow.hpp"
#include "xcgui/XCCast.hpp"
#include "xcgui/XCElement.hpp"
#include "xcgui/XCFont.hpp"
#include "xcgui/XCDraw.hpp"
#include "xcgui/XCImage.hpp"
#include "xcgui/element/XCButton.hpp"
#include "XEventManager.hpp" 

namespace xcgui {

	struct XWindowEvent {
		
		py::args args;
		py::kwargs kwargs;
	};

	void declareWindow(py::module& m) {

		py::class_<XCWindow, XCObjectUI>(m, "XWindow")
			.def(py::init<>())
			.def(py::init<int, int, const std::wstring&>(), "width"_a, "height"_a, "title"_a)
			.def(py::init<int, int, int, int, const std::wstring&, uintptr_t, int>(),
				"x"_a, "y"_a, "width"_a, "height"_a, "title"_a,
				"hWndParent"_a = 0, "style"_a = (int)window_style_default)
			.def("attach", &XCWindow::Attach, "hwnd"_a, "style"_a)
			.def("regEvent", [](const XCWindow& self, int eventType, const XEventCallback& callback, const py::object& userdata) {
				XEventManager::GetInstance()->RegWindowEvent(self.GetWindowHandle(), eventType, callback, userdata);
			}, "eventType"_a, "callback"_a, "userdata"_a= py::none())
			.def("addChild", &XCWindow::AddChild, "child"_a)
			.def("insertChild", &XCWindow::InsertChild, "child"_a, "index"_a)
			.def("redraw", &XCWindow::Redraw, "immediate"_a)
			.def("redrawRect", &XCWindow::RedrawRect, "rect"_a, "immediate"_a)
			.def("setFoucsEle", &XCWindow::SetFoucsEle, "ele"_a)

			.def("getFoucsEle", [](const XCWindow& self) -> XCObject* {
				return CastObject((HXCGUI)self.GetFocusEle());
			}, py::return_value_policy::take_ownership)


			.def("getStayEle", [](const XCWindow& self) -> XCObject* {
				return CastObject((HXCGUI)self.GetStayEle());
			}, py::return_value_policy::take_ownership)

			.def("drawWindow", [](XCWindow& self, const XCDraw& draw){
				self.DrawWindow(draw.getDrawHandle());
			}, "draw"_a)

			.def("center", &XCWindow::Center)
			.def("centerEx", &XCWindow::CenterEx, "width"_a, "height"_a)
			
			.def("setCursor", [](XCWindow& self, uintptr_t hCursor){
				self.SetCursor((HCURSOR)hCursor);
			}, "hCursor"_a)
			.def("setCursor", [](XCWindow& self){
				return (uintptr_t)self.GetCursor();
			})

			.def("getHWND", [](XCWindow& self){
				return (uintptr_t)self.GetHWND();
			})
			.def("enableDragBorder", &XCWindow::EnableDragBorder, "enable"_a)
			.def("enableDragWindow", &XCWindow::EnableDragWindow, "enable"_a)
			.def("enableDragCaption", &XCWindow::EnableDragCaption, "enable"_a)
			.def("enableDrawBk", &XCWindow::EnableDrawBk, "enable"_a)
			.def("enableAutoFocus", &XCWindow::EnableAutoFocus, "enable"_a)
			.def("enableMaxWindow", &XCWindow::EnableMaxWindow, "enable"_a)
			.def("enablemLimitWindowSize", &XCWindow::EnablemLimitWindowSize, "enable"_a)
			.def("enableDragFiles", &XCWindow::EnableDragFiles, "enable"_a)
			.def("enableLayout", &XCWindow::EnableLayout, "enable"_a)
			.def("enableLayoutOverlayBorder", &XCWindow::EnableLayoutOverlayBorder, "enable"_a)
			.def("showLayoutFrame", &XCWindow::ShowLayoutFrame, "enable"_a)
			.def("isEnableLayout", &XCWindow::IsEnableLayout)
			.def("isMaxWindow", &XCWindow::IsMaxWindow)
			.def("isDragBorder", &XCWindow::IsDragBorder)
			.def("isDragCaption", &XCWindow::IsDragCaption)
			
			.def("setCaptureEle", [](XCWindow& self, const XCElement& ele){
				self.SetCaptureEle(ele.getEleHandle());
			}, "ele"_a)
			.def("getCaptureEle", [](XCWindow& self) {
				auto ele = self.GetCaptureEle();
				return CastObject((HXCGUI)ele);
			}, py::return_value_policy::take_ownership)

			.def("getDrawRect", [](XCWindow& self) {
				XCRect rect;
				self.GetDrawRect((RECT*)&rect);
				return rect;
			})

			.def("show", &XCWindow::Show, "show"_a)
			.def("showWindow", &XCWindow::ShowWindow, "showType"_a = SW_SHOW)

			.def("setCursorSys", [](XCWindow& self, uintptr_t hCursor) -> uintptr_t {
				return (uintptr_t)self.SetCursorSys((HCURSOR)hCursor);
			}, "hCursor"_a)

			.def("setFont", [](XCWindow& self, const XCFont& font){
				self.SetFont(font.getFontHandle());
			}, "font"_a)

			.def("setTextColor", &XCWindow::SetTextColor, "color"_a)
			.def("getTextColor", &XCWindow::GetTextColor)
			.def("getTextColorEx", &XCWindow::GetTextColorEx)

			.def("getID", &XCWindow::GetID)
			.def("setID", &XCWindow::SetID, "nId"_a)

			.def("setName", &XCWindow::SetName, "name"_a)
			.def("getName", &XCWindow::GetName)

			.def("setBorderSize", &XCWindow::SetBorderSize, "left"_a, "top"_a, "right"_a, "bottom"_a)
			.def("getBorderSize", [](XCWindow& self) {
				XCRect rect;
				self.GetBorderSize((borderSize_*)&rect);
				return rect;
			})

			.def("setPadding", &XCWindow::SetPadding, "left"_a, "top"_a, "right"_a, "bottom"_a)
			.def("setDragBorderSize", &XCWindow::SetDragBorderSize, "left"_a, "top"_a, "right"_a, "bottom"_a)
			.def("getDragBorderSize", [](XCWindow& self) {
				XCRect rect;
				self.GetDragBorderSize((borderSize_*)&rect);
				return rect;
			})

			.def("setCaptionMargin", &XCWindow::SetCaptionMargin, "left"_a, "top"_a, "right"_a, "bottom"_a)
			.def("setMinimumSize", &XCWindow::SetMinimumSize, "width"_a, "height"_a)
			.def("hitChildEle", [](XCWindow& self, const XCPoint& point) -> XCObject* {
					auto handle = self.HitChildEle((POINT*) & point);
					return CastObject(handle);
			}, "point"_a, py::return_value_policy::take_ownership)

			.def("getChildCount", &XCWindow::GetChildCount)
			.def("getChildByIndex", [](XCWindow& self, int index) {
				auto handle = self.GetChildByIndex(index);
				return CastObject(handle);
			}, "index"_a)
			.def("getChildByID", [](XCWindow& self, int nId) {
				auto handle = self.GetChildByID(nId);
				return CastObject(handle);
			}, "nId"_a)
			.def("getChild", [](XCWindow& self, int nId) {
				auto handle = self.GetChild(nId);
				return CastObject(handle);
			}, "nId"_a)


			.def("setIcon", [](XCWindow& self, const XCImage& image) {
				self.SetIcon(image.getImageHandle());
			}, "image"_a)
			.def("getIcon", [](XCWindow& self) -> XCImage* {
				auto handle = self.GetIcon();
				if (!handle)
					return nullptr;
				return new XCImage(handle);
			})

			.def("setTitle", &XCWindow::SetTitle, "title"_a)
			.def("getTitle", &XCWindow::GetTitle)

			.def("setTitleColor", &XCWindow::SetTitleColor, "color"_a)
			.def("getTitleColor", &XCWindow::GetTitleColor)

			.def("getButton", [](XCWindow& self, int flag) -> XCButton* {
				auto ele = self.GetButton(flag);
				if (!ele)
					return nullptr;
				return new XCButton(ele);
			}, "flag"_a)
			
			.def("closeWindow", &XCWindow::CloseWindow)
			.def("adjustLayout", &XCWindow::AdjustLayout)
			.def("adjustLayoutEx", &XCWindow::AdjustLayoutEx, "flags"_a)
			.def("setTextColor", &XCWindow::SetTextColor, "color"_a)

			.def("createCaret", [](XCWindow& self, const XCElement& ele, int x, int y, int width, int height){
				self.CreateCaret(ele.getEleHandle(), x, y, width, height);
			}, "ele"_a, "x"_a, "y"_a, "width"_a, "height"_a)
			.def("setCaretPos", &XCWindow::SetCaretPos, "x"_a, "y"_a, "width"_a, "height"_a, "update"_a)
			.def("setCaretColor", &XCWindow::SetCaretColor, "color"_a)
			.def("showCaret", &XCWindow::ShowCaret, "show"_a)


			.def("getCaretHELE", [](XCWindow& self) -> XCObject* {
					auto handle = self.GetCaretHELE();
					return CastObject(handle);
			}, py::return_value_policy::take_ownership)












				;

	}
}