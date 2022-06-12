#pragma once
#include "pch.h"
#include "xcgui.h"
#include "manager/XCastManager.hpp"
#include "manager/XMainThreadManager.hpp"
#include "xcgui/utils/Color.hpp"
#include "xcgui/XCStruct.hpp"
#include "xcgui/XCGlobal.hpp"
#include "xcgui/XCFont.hpp"	 
#include "xcgui/XCStruct.hpp"

namespace xcgui {

	void declareGlobal(py::module& m) {

		m.def("Cast", [](uintptr_t handle) -> XCObject* {
			return XCastManager::GetInstance()->CastObject((HXCGUI)handle);
		}, "handle"_a, py::return_value_policy::take_ownership);


		m.def("RGB", [](BYTE r, BYTE g, BYTE b) {
			return (RGB(r, g, b)) &0xFFFFFFFF;
		}, "r"_a, "g"_a, "b"_a);

		m.def("RGB", [](const std::string& hexColor) {
			return hexToRGBColorRef(hexColor);
		}, "hexcolor"_a);

		m.def("RGBA", [](const std::string& hexColor) {
			return hexToRGBAColorRef(hexColor);
		}, "hexcolor"_a);

		m.def("RGBA", [](BYTE r, BYTE g, BYTE b, BYTE a) {
			return  (RGBA(r, g, b, a)) & 0xFFFFFFFF;
		}, "r"_a, "g"_a, "b"_a, "a"_a);

		m.def("RGBA", [](int rgb, BYTE a) {
			return  ((rgb & 16777215) | (a & 255) << 24) & 0xFFFFFFFF;
		}, "rgb"_a, "a"_a);

		m.def("PointClientToScreen", [](uintptr_t hwnd, XCPoint& point) {
			XCPoint newPoint(point.x, point.y);
			::ClientToScreen((HWND)hwnd, (LPPOINT)&newPoint);
			return newPoint;
		}, "hwnd"_a, "point"_a);

		m.def("CallUiThread", [](py::object method, py::args args, py::kwargs kwargs) {
			XMainThreadManager::GetInstance()->CallUiThread(method, args, kwargs);
		}, "func"_a); // py::call_guard<py::gil_scoped_release>()

		m.def("Alert", &XCGlobal::Alert, "title"_a, "text"_a);
		m.def("MessageBox", [](const std::wstring& title, const std::wstring& text, int flags, uintptr_t hWndParent, int XCStyle= window_style_modal) {
			return XCGlobal::MessageBox(title, text, flags, (HWND)hWndParent, XCStyle);
		}, "title"_a, "text"_a, "flags"_a, "hWndParent"_a, "xcStyle"_a=(int)window_style_modal);

		m.def("PostMessage", [](uintptr_t hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
			return XCGlobal::PostMessage((HWND)hwnd, msg, wParam, lParam);
		}, "hwnd"_a, "msg"_a, "wParam"_a, "lParam"_a);

		m.def("SendMessage", [](uintptr_t hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
			return XCGlobal::SendMessage((HWND)hwnd, msg, wParam, lParam);
		}, "hwnd"_a, "msg"_a, "wParam"_a, "lParam"_a);

		m.def("PostQuitMessage", &XCGlobal::PostQuitMessage, "exitCode"_a);

		m.def("RegisterWindowClassName", &XCGlobal::RegisterWindowClassName, "className"_a);
		m.def("SetActivateTopWindow", &XCGlobal::SetActivateTopWindow);

		m.def("SetDefaultFont", [](const XCFont& font) {
			XCGlobal::SetDefaultFont(font.getFontHandle());
		}, "font"_a);

		m.def("GetDefaultFont", []() {
			auto handle = XCGlobal::GetDefaultFont();
			XCFont font(handle);
			return font;
		});

		m.def("CombineRect", [](const XCRect& rect1, const XCRect& rect2) {
			XCRect rect3;
			XCGlobal::CombineRect((RECT*)&rect3, (RECT*)&rect1, (RECT*)&rect2);
			return rect3;
		}, "rect1"_a, "rect2"_a);

		m.def("RectInRect", [](const XCRect& rect1, const XCRect& rect2) {
			return XCGlobal::RectInRect((RECT*)&rect1, (RECT*)&rect2);
		}, "rect1"_a, "rect2"_a);

		m.def("Malloc", [](int size) -> uintptr_t {
			return (uintptr_t)XCGlobal::Malloc(size);
		}, "size"_a);

		m.def("GetProcAddress", [](uintptr_t hModule, const std::string & procName) -> uintptr_t {
			return (uintptr_t)XCGlobal::GetProcAddress((HMODULE)hModule, procName.c_str());
		}, "hModule"_a, "procName"_a);

		m.def("LoadDll", [](const std::wstring fileName) {
			return (uintptr_t)XCGlobal::LoadDll(fileName);
		}, "fileName"_a);

		
		m.def("LoadLibrary", [](const std::wstring fileName) {
			return (uintptr_t)XCGlobal::LoadLibrary(fileName);
		}, "fileName"_a);

		m.def("Free", [](uintptr_t pointer) {
			XCGlobal::Free((void*)pointer);
		}, "pointer"_a);

		m.def("FreeLibrary", [](uintptr_t hModule) {
			return XCGlobal::FreeLibrary((HMODULE)hModule);
		}, "hModule"_a);
		
		m.def("GetTextShowRect", [](const std::wstring& text, const XCFont& font, int textAlign, int maxWidth) {
			XCSize info;
			XCGlobal::GetTextShowRect(text, font.getFontHandle(), textAlign, maxWidth, (SIZE*)&info);
			return info;
		}, "text"_a, "font"_a, "textAlign"_a, "maxWidth"_a);

		m.def("GetTextShowSize", [](const std::wstring& text, const XCFont& font) {
			XCSize info;
			XCGlobal::GetTextShowSize(text, font.getFontHandle(), (SIZE*)&info);
			return info;
		}, "text"_a, "font"_a);


		m.def("GetTextShowSizeEx", [](const std::wstring& text, const XCFont& font, int textAlign) {
			XCSize info;
			XCGlobal::GetTextShowSizeEx(text, font.getFontHandle(), textAlign, (SIZE*)&info);
			return info;
		}, "text"_a, "font"_a, "textAlign"_a);

		m.def("GetTextSize", [](const std::wstring& text, const XCFont& font) {
			XCSize info;
			XCGlobal::GetTextSize(text, font.getFontHandle(), (SIZE*)&info);
			return info;
		}, "text"_a, "font"_a);

		;
	}

}