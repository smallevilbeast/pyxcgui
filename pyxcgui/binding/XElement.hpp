#pragma once
#include "pch.h"
#include "xcgui/XCElement.hpp"
#include "xcgui/XCFont.hpp"
#include "xcgui/bkmanager/XCBkManager.hpp"
#include "xcgui/XCDraw.hpp"
#include "manager/XUserDataManager.hpp"
#include "manager/XEventManager.hpp"
#include "manager/XCastManager.hpp"

namespace xcgui {

	void declareElement(py::module& m) {

		py::class_<XCElement, XCWidget>(m, "XElement")
			PYCASTOBJECT(XCElement)
			PYOBJECTVALID(XCElement, XC_ELE)
			.def(py::init([](int x, int y, int cx, int cy, const XCObjectUI* parent=nullptr) {	  
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCElement ele(x, y, cx, cy, handle);
				return ele;
			}), "x"_a, "y"_a, "width"_a, "height"_a, "parent"_a=nullptr)

			.def(py::init([](int cx, int cy, XCObjectUI* parent=nullptr) {
				HXCGUI handle = nullptr;
				if (parent) {
					handle = parent->GetHandle();
				}
				XCElement obj(0,0, cx, cy, handle);
				return obj;
			}), "width"_a, "height"_a, "parent"_a=nullptr)

			.def("regEvent", [](const XCElement& self, int eventType, const XEventCallback& callback, const py::object& userdata) {
					XEventManager::GetInstance()->RegEleEvent(self.getEleHandle(), eventType, callback, userdata);
			}, "eventType"_a, "callback"_a, "userdata"_a = py::none())

			.def("sendEvent", [](XCElement& self, int eventType, intptr_t wParam, intptr_t lParam) -> int {
					return self.SendEvent(eventType, (WPARAM)wParam, (LPARAM)lParam);
				}, "eventType"_a, "wParam"_a, "lParam"_a)
			
			.def("postEvent", [](XCElement& self, int eventType, intptr_t wParam, intptr_t lParam) -> int {
					return self.PostEvent(eventType, (WPARAM)wParam, (LPARAM)lParam);
				}, "eventType"_a, "wParam"_a, "lParam"_a)
			
			.def("getRect", [](XCElement& self) -> XCRect {
					XCRect rect;
					self.GetRect((RECT*)&rect);
					return rect;
				})
			.def("getRectLogic", [](XCElement& self) -> XCRect {
					XCRect rect;
					self.GetRectLogic((RECT*)&rect);
					return rect;
				})
			.def("getClientRect", [](XCElement& self) -> XCRect {
					XCRect rect;
					self.GetClientRect((RECT*)&rect);
					return rect;
				})

			.def("setWidth", &XCElement::SetWidth, "size"_a)
			.def("setHeight", &XCElement::SetHeight, "size"_a)
			.def("getWidth", &XCElement::GetWidth)
			.def("getHeight", &XCElement::GetHeight)

			.def("rectWndClientToEleClient", [](XCElement& self, const XCRect& rect) -> XCRect {
					XCRect newRect(rect.left, rect.top, rect.right, rect.bottom);
					self.RectWndClientToEleClient((RECT*)&newRect);
					return newRect;
				}, "rect"_a)

			.def("pointWndClientToEleClient", [](XCElement& self, const XCPoint& pt) -> XCPoint {
					XCPoint point(pt.x, pt.y);
					self.PointWndClientToEleClient((POINT*)&point);
					return point;
				}, "point"_a)

			.def("rectClientToWndClient", [](XCElement& self, const XCRect& rect) -> XCRect {
					XCRect newRect(rect.left, rect.top, rect.right, rect.bottom);
					self.RectClientToWndClient((RECT*)&newRect);
					return newRect;
				}, "rect"_a)
					
			.def("pointClientToWndClient", [](XCElement& self, const XCPoint& pt) -> XCPoint {
					XCPoint point(pt.x, pt.y);
					self.PointClientToWndClient((POINT*)&point);
					return point;
				}, "point"_a)

			.def("pointClientToScreen", [](XCElement& self,
				position_flag_ position_flag, int xOffset, int yOffset) -> XCPoint {
					XCPoint point;
					self.PointClientToScreen((POINT*)&point, position_flag, xOffset, yOffset);
					return point;
				}, "position_flag"_a= py::cast(position_flag_leftBottom), "xOffset"_a=0, "yOffset"_a=0)
		
			.def("getWndClientRect", [](XCElement& self) -> XCRect {
					XCRect rect;
					self.GetWndClientRect((RECT*)&rect);
					return rect;
				})

			// 3.3.8 新增
			.def("getWndClientRectDPI", [](XCElement& self) -> XCRect {
					XCRect rect;
					XEle_GetWndClientRectDPI(self.getEleHandle(), (RECT*)&rect);
					return rect;
				})
			.def("pointClientToWndClientDPI", [](XCElement& self, const XCPoint& point) -> XCPoint {
					XCPoint result = point;
					XEle_PointClientToWndClientDPI(self.getEleHandle(), (POINT*)&result);
					return result;
				}, "point"_a)
			.def("rectClientToWndClientDPI", [](XCElement& self, const XCRect& rect) -> XCRect {
					XCRect result = rect;
					XEle_RectClientToWndClientDPI(self.getEleHandle(), (RECT*)&result);
					return result;
				}, "rect"_a)

			.def("getCursor", [](XCElement& self) -> intptr_t {
					return (intptr_t)self.GetCursor();
				})

			.def("setCursor", [](XCElement& self, intptr_t hCursor) {
					self.SetCursor((HCURSOR)hCursor);
				}, "hCursor"_a)

			.def("addChild", [](XCElement& self, const XCWidget& child) {
					self.AddChild(child.GetHandle());
				}, "child"_a)

			.def("insertChild", [](XCElement& self, const XCWidget& child, int index) {
					self.InsertChild(child.GetHandle(), index);
				}, "child"_a, "index"_a)

			.def("setRect", &XCElement::SetRect, "rect"_a, "redraw"_a = false, "flags"_a = py::cast(adjustLayout_all), "adjust_no"_a = 0)
			.def("setRectEx", &XCElement::SetRectEx, "x"_a, "y"_a, "cx"_a, "cy"_a, "redraw"_a = false, "flags"_a = py::cast(adjustLayout_all), "adjust_no"_a = 0)
			.def("setRectLogic", &XCElement::SetRectLogic, "rect"_a, "redraw"_a = false, "flags"_a = py::cast(adjustLayout_all), "adjust_no"_a = 0)
			.def("setPosition", &XCElement::SetPosition, "x"_a, "y"_a, "redraw"_a=false,"flags"_a= py::cast(adjustLayout_all), "adjust_no"_a=0)
			.def("setPositionLogic", &XCElement::SetPositionLogic, "x"_a, "y"_a, "redraw"_a = false, "flags"_a = py::cast(adjustLayout_all), "adjust_no"_a = 0)
			.def("getPositon", [](XCElement& self) -> XCPoint {
					XCPoint point;
					self.GetPosition(&point.x, &point.y);
					return point;
				})
			.def("setSize", &XCElement::SetSize, "width"_a, "height"_a, "redraw"_a=false, "flags"_a=py::cast(adjustLayout_all), "adjust_no"_a = 0)
			.def("getSize", [](XCElement& self) -> XCSize {
					XCSize size;
					self.GetSize(&size.width, &size.height);
					return size;
				})
			.def("isDrawFocus", &XCElement::IsDrawFocus)
			.def("isEnable", &XCElement::IsEnable)
			.def("isEnableFocus", &XCElement::IsEnableFocus)
			.def("isMouseThrough", &XCElement::IsMouseThrough)
			.def("hitChildEle", [](XCElement& self, const XCPoint& point) {
					auto handle = self.HitChildEle((POINT*) & point);
					return XCastManager::GetInstance()->CastObject(handle);
			}, "point"_a, py::return_value_policy::take_ownership)
			
			.def("isBkTransparent", &XCElement::IsBkTransparent)
			.def("isEnableEvent_XE_PAINT_END", &XCElement::IsEnableEvent_XE_PAINT_END)
			.def("isKeyTab", &XCElement::IsKeyTab)
			.def("isSwitchFocus", &XCElement::IsSwitchFocus)
			.def("isEnable_XE_MOUSEWHEEL", &XCElement::IsEnable_XE_MOUSEWHEEL)
			.def("isChildEle", [](XCElement& self, const XCWidget& child) {
				return self.IsChildEle((HELE)child.GetHandle());
			}, "child"_a)
			.def("isEnableCanvas", &XCElement::IsEnableCanvas)
			.def("isFocus", &XCElement::IsFocus)
			.def("isFocusEx", &XCElement::IsFocusEx)
			.def("enable", &XCElement::Enable, "enable"_a)
			.def("enableFocus", &XCElement::EnableFocus, "enable"_a)
			.def("enableDrawFocus", &XCElement::EnableDrawFocus, "enable"_a)
			.def("enableDrawBorder", &XCElement::EnableDrawBorder, "enable"_a)
			.def("enableCanvas", &XCElement::EnableCanvas, "enable"_a)
			.def("enableEvent_XE_PAINT_END", &XCElement::EnableEvent_XE_PAINT_END, "enable"_a)
			.def("enableBkTransparent", &XCElement::EnableBkTransparent, "enable"_a)
			.def("enableMouseThrough", &XCElement::EnableMouseThrough, "enable"_a)
			.def("enableKeyTab", &XCElement::EnableKeyTab, "enable"_a)
			.def("enableSwitchFocus", &XCElement::EnableSwitchFocus, "enable"_a)
			.def("enableEvent_XE_MOUSEWHEEL", &XCElement::EnableEvent_XE_MOUSEWHEEL, "enable"_a)
			.def("remove", &XCElement::Remove)
			.def("setZOrder", &XCElement::SetZOrder, "index"_a)
			.def("setZOrderEx", [](XCElement& self, const XCWidget& destEle, zorder_ zorder) {
				self.SetZOrderEx((HELE)destEle.GetHandle(), zorder);
			}, "destEle"_a, "index"_a)
			.def("getZOrder", &XCElement::GetZOrder)
			.def("enableTopmost", &XCElement::EnableTopmost, "enable"_a)
			.def("redraw", &XCElement::Redraw, "immediate"_a=false)
			.def("redrawRect", [](XCElement& self, const XCRect& rect, bool immediate) {
				self.RedrawRect((RECT*)&rect, immediate);
			}, "rect"_a, "immediate"_a = false)

			.def("getChildCount", &XCElement::GetChildCount)
			.def("getChildByIndex", [](XCElement& self, int index) {
				auto handle = self.GetChildByIndex(index);
				return XCastManager::GetInstance()->CastObject(handle);
			}, "index"_a, py::return_value_policy::take_ownership)
			.def("getChildByID", [](XCElement& self, int nId) {
				auto handle = self.GetChildByID(nId);
				return XCastManager::GetInstance()->CastObject(handle);
				}, "nId"_a, py::return_value_policy::take_ownership)

			.def("setBorderSize", &XCElement::SetBorderSize, "left"_a, "top"_a, "right"_a, "bottom"_a)
			.def("getBorderSize", [](XCElement& self) -> XCRect {
					XCRect rect;
					self.GetBorderSize((borderSize_*)&rect);
					return rect;
			})
			.def("setPadding", &XCElement::SetPadding, "left"_a, "top"_a, "right"_a, "bottom"_a)
			.def("getPadding", [](XCElement& self) -> XCRect {
				XCRect rect;
				self.GetPadding((paddingSize_*)&rect);
				return rect;
			})
			.def("setDragBorder", &XCElement::SetDragBorder, "flags"_a)
			.def("setDragBorderBindEle", [](XCElement& self, int flags, const XCWidget& bindEle, int space) {
					self.SetDragBorderBindEle(flags, (HELE)bindEle.GetHandle(), space);
			}, "flags"_a, "element"_a, "space"_a)
			.def("setMinSize", &XCElement::SetMinSize, "width"_a, "height"_a)
			.def("setMaxSize", &XCElement::SetMaxSize, "width"_a, "height"_a)
			.def("setMaxSize", &XCElement::SetLockScroll, "horizon"_a, "vertical"_a)
			.def("setTextColor", [](XCElement& self, COLORREF hColor) {
				self.SetTextColor(hColor);
			}, "hColor"_a)
			.def("getTextColor", [](XCElement& self) {
				return self.GetTextColor();
			})
			.def("getTextColorEx", [](XCElement& self) {
				return self.GetTextColorEx();
			})
			.def("setFocusBorderColor", [](XCElement& self, COLORREF hColor) {
				self.SetFocusBorderColor(hColor);
			}, "hColor"_a)
			.def("getFocusBorderColor", [](XCElement& self) {
				return self.GetFocusBorderColor();
			})
			.def("setFont", [](XCElement& self, const XCFont& font) {
				self.SetFont(font.getFontHandle());
			}, "font"_a)
			.def("getFont", [](XCElement& self) -> XCFont {
				auto handle = self.GetFont();
				return XCFont(handle);
			})

			.def("getFontEx", [](XCElement& self) -> XCFont {
				auto handle = self.GetFontEx();
				return XCFont(handle);
			})
			.def("setAlpha", &XCElement::SetAlpha, "alpha"_a)
			.def("getAlpha", &XCElement::GetAlpha)
			.def("destroy", [](XCElement& self) {
				self.Destroy();
			})
			.def("addBkBorder", &XCElement::AddBkBorder, "state"_a, "hColor"_a, "width"_a)
			.def("addBkFill", &XCElement::AddBkFill, "state"_a, "hColor"_a)
			.def("addBkImage", [](XCElement& self, int nState, const XCImage& image) {
				self.AddBkImage(nState, image.getImageHandle());
				}, "state"_a, "image"_a)
			.def("setBkInfo", &XCElement::SetBkInfo, "text"_a)
			.def("getBkInfoCount", &XCElement::GetBkInfoCount)
			.def("clearBkInfo", &XCElement::ClearBkInfo)
			.def("getBkManager", [](XCElement& self) -> XCBkManager {
				auto handle = self.GetBkManager();
				return XCBkManager(handle);
			})
			.def("getBkManagerEx", [](XCElement& self) -> XCBkManager {
				auto handle = self.GetBkManagerEx();
				return XCBkManager(handle);
			})
			.def("setBkManager", [](XCElement& self, const XCBkManager& bkm) {
				self.SetBkManager(bkm.GetBkmHandle());
			}, "bkm"_a)
			.def("getStateFlags", &XCElement::GetStateFlags)
			.def("drawFocus", [](XCElement& self, const XCDraw& draw, const XCRect& rect) {
				self.DrawFocus(draw.getDrawHandle(), (RECT*)&rect);
			}, "draw"_a, "rect"_a)
			.def("drawEle", [](XCElement& self, const XCDraw& draw) {
				self.DrawEle(draw.getDrawHandle());
			}, "draw"_a)
			.def("setUserData", [](XCElement& self, const py::object& userdata) {
				XUserDataManager::GetInstance()->SetUserData(self.GetHandle(), userdata);
			}, "userdata"_a)
			.def("getUserData", [](XCElement& self) {
				return XUserDataManager::GetInstance()->GetUserData(self.GetHandle());
			})
			.def("getContentSize", [](XCElement& self, bool horizon, int cx, int cy) {
				XCSize size;
				self.GetContentSize(horizon, cx, cy, (SIZE*)&size);
				return size;
			}, "horizon"_a, "cx"_a, "cy"_a)
			.def("setCapture", &XCElement::SetCapture, "enable"_a, py::call_guard<py::gil_scoped_release>())
			.def("enableTransparentChannel", &XCElement::EnableTransparentChannel, "enable"_a)
			.def("setXCTimer", &XCElement::SetXCTimer, "eventId"_a, "elapse"_a)
			.def("killXCTimer", &XCElement::KillXCTimer, "eventId"_a)
			.def("setToolTip", &XCElement::SetToolTip, "text"_a)
			.def("setToolTipEx", &XCElement::SetToolTipEx, "text"_a, "textAlign"_a)
			.def("getToolTip", &XCElement::GetToolTip)
			.def("popupToolTip", &XCElement::PopupToolTip, "x"_a, "y"_a)
			.def("adjustLayout", &XCElement::AdjustLayout, "adjustNo"_a=0)
			.def("adjustLayoutEx", &XCElement::AdjustLayoutEx, "flags"_a, "adjustNo"_a=0);

	}
}