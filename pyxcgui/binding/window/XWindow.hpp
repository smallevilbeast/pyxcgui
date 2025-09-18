#include "pch.h"
#include "xcgui/window/XCWindow.hpp"
#include "xcgui/XCElement.hpp"
#include "xcgui/XCFont.hpp"
#include "xcgui/XCDraw.hpp"
#include "xcgui/XCImage.hpp"
#include "xcgui/XCLayoutBox.hpp"
#include "xcgui/element/XCButton.hpp"
#include "binding/manager/XEventManager.hpp" 
#include "binding/manager/XCastManager.hpp"

namespace xcgui {

	struct XWindowEvent {
		
		py::args args;
		py::kwargs kwargs;
	};

	void declareWindow(py::module& m) {

		py::class_<XCWindow, XCObjectUI, XCLayoutBox>(m, "XWindow")
			PYCASTOBJECT(XCWindow)
			PYOBJECTVALID(XCWindow, XC_WINDOW)
			.def(py::init<>())
			.def(py::init<int, int, const std::wstring&>(), "width"_a, "height"_a, "title"_a)
			.def(py::init<int, int, int, int, const std::wstring&, uintptr_t, int>(),
				"x"_a, "y"_a, "width"_a, "height"_a, "title"_a,
				"hWndParent"_a = 0, "style"_a = (int)window_style_default)
			.def(py::init<DWORD, DWORD, const std::wstring&,
				int, int, int, int, const std::wstring&, uintptr_t, int>()
				, "exStyle"_a, "style"_a, "className"_a, "x"_a, "y"_a, "width"_a, "height"_a,
				"title"_a, "hwndParent"_a, "xcStyle"_a)
			.def("attach", &XCWindow::Attach, "hwnd"_a, "style"_a= (int)window_style_default)
			.def("regEvent", [](const XCWindow& self, int eventType, const XEventCallback& callback, const py::object& userdata) {
				XEventManager::GetInstance()->RegWindowEvent(self.GetWindowHandle(), eventType, callback, userdata);
			}, "eventType"_a, "callback"_a, "userdata"_a= py::none())
			.def("addChild", &XCWindow::AddChild, "child"_a)
			.def("insertChild", &XCWindow::InsertChild, "child"_a, "index"_a)
			.def("redraw", &XCWindow::Redraw, "immediate"_a=false)
			.def("redrawRect", &XCWindow::RedrawRect, "rect"_a, "immediate"_a=false)
			.def("setFoucsEle", &XCWindow::SetFoucsEle, "ele"_a)

			.def("getFoucsEle", [](const XCWindow& self) -> XCObject* {
				return XCastManager::GetInstance()->CastObject((HXCGUI)self.GetFocusEle());
			}, py::return_value_policy::take_ownership)


			.def("getStayEle", [](const XCWindow& self) -> XCObject* {
				return XCastManager::GetInstance()->CastObject((HXCGUI)self.GetStayEle());
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
			.def("enableLimitWindowSize", &XCWindow::EnableLimitWindowSize, "enable"_a)
			.def("enableDragFiles", &XCWindow::EnableDragFiles, "enable"_a)
			.def("enableLayout", &XCWindow::EnableLayout, "enable"_a)
			.def("enableLayoutOverlayBorder", &XCWindow::EnableLayoutOverlayBorder, "enable"_a)
			.def("showLayoutFrame", &XCWindow::ShowLayoutFrame, "enable"_a)
			.def("isEnableLayout", &XCWindow::IsEnableLayout)
			.def("isMaxWindow", &XCWindow::IsMaxWindow)
			.def("isDragBorder", &XCWindow::IsDragBorder)
			.def("isDragCaption", &XCWindow::IsDragCaption)

			// 3.3.8 新增
			.def("setDPI", [](XCWindow& self, int dpi) {
				XWnd_SetDPI(self.GetWindowHandle(), dpi);
			}, "dpi"_a)
			.def("getDPI", [](XCWindow& self) {
				return XWnd_GetDPI(self.GetWindowHandle());
			})
			.def("rectToDPI", [](XCWindow& self, const XCRect& rect) {
				XCRect result = rect;
				XWnd_RectToDPI(self.GetWindowHandle(), (RECT*)&result);
				return result;
			}, "rect"_a)
			.def("pointToDPI", [](XCWindow& self, const XCPoint& point) {
				XCPoint result = point;
				XWnd_PointToDPI(self.GetWindowHandle(), (POINT*)&result);
				return result;
			}, "point"_a)
			.def("getCursorPos", [](XCWindow& self) {
				XCPoint point;
				XWnd_GetCursorPos(self.GetWindowHandle(), (POINT*)&point);
				return point;
			})
			.def("clientToScreen", [](XCWindow& self, const XCPoint& point) {
				XCPoint result = point;
				XWnd_ClientToScreen(self.GetWindowHandle(), (POINT*)&result);
				return result;
			}, "point"_a)
			.def("screenToClient", [](XCWindow& self, const XCPoint& point) {
				XCPoint result = point;
				XWnd_ScreenToClient(self.GetWindowHandle(), (POINT*)&result);
				return result;
			}, "point"_a)
			.def("setWindowPos", [](XCWindow& self, uintptr_t hWndInsertAfter, int x, int y, int cx, int cy, unsigned int flags) {
				XWnd_SetWindowPos(self.GetWindowHandle(), (HWND)hWndInsertAfter, x, y, cx, cy, flags);
			}, "hWndInsertAfter"_a, "x"_a, "y"_a, "cx"_a, "cy"_a, "flags"_a)

			.def("setCaptureEle", [](XCWindow& self, const XCElement& ele){
				self.SetCaptureEle(ele.getEleHandle());
			}, "ele"_a, py::call_guard<py::gil_scoped_release>())
			.def("getCaptureEle", [](XCWindow& self) {
				auto ele = self.GetCaptureEle();
				return XCastManager::GetInstance()->CastObject((HXCGUI)ele);
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
					return XCastManager::GetInstance()->CastObject(handle);
			}, "point"_a, py::return_value_policy::take_ownership)

			.def("getChildCount", &XCWindow::GetChildCount)
			.def("getChildByIndex", [](XCWindow& self, int index) -> XCObject* {
				auto handle = self.GetChildByIndex(index);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "index"_a, py::return_value_policy::take_ownership)
			.def("getChildByID", [](XCWindow& self, int nId) -> XCObject* {
				auto handle = self.GetChildByID(nId);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "nId"_a, py::return_value_policy::take_ownership)
			
			.def("findChildByID", [](XCWindow& self, int nId) -> XCObject* {
				auto handle = self.FindChildByID(nId);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "nId"_a, py::return_value_policy::take_ownership)
			.def("findChildByIDName", [](XCWindow& self, const std::wstring& name) -> XCObject* {
				auto handle = self.FindChildByIDName(name);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "name"_a, py::return_value_policy::take_ownership)


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
			.def("getCare", [](XCWindow& self) -> XCObject* {
				auto handle = self.GetCaretHELE();
				return XCastManager::GetInstance()->CastObject(handle);
			}, py::return_value_policy::take_ownership)
			.def("getCareInfo", [](XCWindow& self) ->  XCCareInfo {
				XCCareInfo info;
				auto handle = self.GetCaretInfo(&info.x, &info.y, &info.width, &info.height);
				info.pCare = XCastManager::GetInstance()->CastObject(handle);
				return info;
			})
			.def("destroyCaret", &XCWindow::DestroyCaret)
			.def("getClientRect", [](XCWindow& self) -> XCRect {
				XCRect rect;
				self.GetClientRect((RECT*)&rect);
				return rect;
			})

			.def("getBodyRect", [](XCWindow& self) -> XCRect {
				XCRect rect;
				self.GetBodyRect((RECT*)&rect);
				return rect;
			})

			.def("getLayoutRect", [](XCWindow& self) -> XCRect {
				XCRect rect;
				self.GetLayoutRect((RECT*)&rect);
				return rect;
			})

			.def("setPosition", &XCWindow::SetPosition, "x"_a, "y"_a)


			.def("getRect", [](XCWindow& self) -> XCRect {
				XCRect rect;
				self.GetRect((RECT*)&rect);
				return rect;
			})

			.def("setRect", [](XCWindow& self, const XCRect& rect) {
				self.SetRect((RECT*)&rect);
				return rect;
			}, "rect"_a)

			.def("maxWindow", &XCWindow::MaxWindow, "maximize"_a)
			.def("setTimer", &XCWindow::SetTimer, "eventId"_a, "elapse"_a)
			.def("killTimer", &XCWindow::KillTimer, "eventId"_a)
			.def("setXCTimer", &XCWindow::SetXCTimer, "eventId"_a, "elapse"_a)
			.def("killXCTimer", &XCWindow::KillXCTimer, "eventId"_a)
			.def("addBkFill", &XCWindow::AddBkFill, "state"_a, "color"_a)
			.def("addBkImage", [](XCWindow& self, int state, const XCImage& image){
				self.AddBkImage(state, image.getImageHandle());
			}, "state"_a, "image"_a)

			.def("setBkInfo", &XCWindow::SetBkInfo, "text"_a)
			.def("getBkInfoCount", &XCWindow::GetBkInfoCount)
			.def("clearBkInfo", &XCWindow::ClearBkInfo)
			.def("getBkManager", [](XCWindow& self) -> XCObject* {
				auto handle = self.GetBkManager();
				return XCastManager::GetInstance()->CastObject(handle);
			}, py::return_value_policy::take_ownership)
			.def("getBkManagerEx", [](XCWindow& self) -> XCObject* {
				auto handle = self.GetBkManagerEx();
				return XCastManager::GetInstance()->CastObject(handle);
			}, py::return_value_policy::take_ownership)
			.def("setBkMagager", [](XCWindow& self, const XCBkManager& manager){
				self.SetBkMagager(manager.GetBkmHandle());
			}, "bkm"_a)

			.def("setTransparentType", &XCWindow::SetTransparentType, "nType"_a)
			.def("getTransparentType", &XCWindow::GetTransparentType)
			.def("setTransparentAlpha", &XCWindow::SetTransparentAlpha, "alpha"_a)
			.def("setTransparentColor", &XCWindow::SetTransparentColor, "color"_a)
			.def("setShadowInfo", &XCWindow::SetShadowInfo, "size"_a, "depth"_a, "angeleSize"_a, "rightAngle"_a, "color"_a)
			.def("getShadowInfo", [](XCWindow& self){
				XCShadowInfo info;
				self.GetShadowInfo(&info.size, &info.depth, &info.angeleSize, (BOOL*)& info.rightAngle, &info.color);
				return info;
			})
			.def("sendMessage", &XCWindow::SendMessage, "msg"_a, "wParam"_a, "lParam"_a)
			.def("postMessage", &XCWindow::PostMessage, "msg"_a, "wParam"_a, "lParam"_a)

			.def("notifyMsgSetBorderSize", &XCWindow::NotifyMsgSetBorderSize, "left"_a, "top"_a, "right"_a, "bottom"_a)
			.def("notifyMsgSetCaptionHeight", &XCWindow::NotifyMsgSetCaptionHeight, "height"_a)
			.def("notifyMsgSetDuration", &XCWindow::NotifyMsgSetDuration, "duration"_a)
			.def("notifyMsgSetParentMargin", &XCWindow::NotifyMsgSetParentMargin, "left"_a, "top"_a, "right"_a, "bottom"_a)
			.def("notifyMsgSetSpace", &XCWindow::NotifyMsgSetSpace, "space"_a)
			.def("notifyMsgSetWidth", &XCWindow::NotifyMsgSetWidth, "width"_a)
			.def("notifyMsgWindowPopup", &XCWindow::NotifyMsgWindowPopup, "position"_a, "title"_a, "text"_a, "icon"_a, "skin"_a)
			.def("notifyMsgWindowPopupEx", &XCWindow::NotifyMsgWindowPopupEx, "position"_a, "title"_a, "text"_a, "icon"_a, "skin"_a,
				"btnClose"_a, "autoClose"_a, "width"_a, "height"_a)

			// 3.3.9 新增 - 窗口销毁
			.def("destroyWindow", [](XCWindow& self) {
				XWnd_DestroyWindow(self.GetWindowHandle());
			})

			// 3.3.9.1 新增
			.def("setTop", [](XCWindow& self, bool bTop = true) {
				XWnd_SetTop(self.GetWindowHandle(), bTop);
			}, "top"_a = true)

			;
	}
}