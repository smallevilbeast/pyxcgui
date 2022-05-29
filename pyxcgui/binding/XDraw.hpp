#pragma once
#include "pch.h"
#include "xcgui/XCDraw.hpp"
#include "xcgui/XCStruct.hpp"
#include "xcgui/XCImage.hpp"
#include "xcgui/XCSvg.hpp"
#include <vector>

namespace xcgui {

	void declareDraw(py::module& m) {

		py::class_<XCDraw, XCObject>(m, "XDraw")
				
			.def_static("create", [](const XCObject& win) -> XCDraw* {
				auto handle = win.GetHandle();
				if (!XC_IsHWINDOW(handle)) {
					return nullptr;
				}
				auto pDraw = new XCDraw();
				if (!pDraw->Create((HWINDOW)handle))
				{
					return nullptr;
				}
				return pDraw;
			}, "window"_a, py::return_value_policy::take_ownership)

	
			.def_static("createFromGdi", [](const XCObject& win, intptr_t hdc) -> XCDraw* {
				auto handle = win.GetHandle();
				if (!XC_IsHWINDOW(handle)) {
					return nullptr;
				}

				auto pDraw = new XCDraw();
				if (!pDraw->CreateGDI((HWINDOW)handle, (HDC)hdc)) {
					return nullptr;
				}
				return pDraw;
			}, "window"_a, "hdc"_a, py::return_value_policy::take_ownership)

			.def("destroy", &XCDraw::Destroy)
			.def("setOffset", &XCDraw::SetOffset, "x"_a, "y"_a)
			.def("getOffset", [](XCDraw& self){
				XCPoint point;
				self.GetOffset(&point.x, &point.y);
				return point;
			})
			.def("gdiRestoreGDIOBJ", &XCDraw::GDI_RestoreGDIOBJ)
			.def("gdiSetBkMode", &XCDraw::GDI_SetBkMode)
			.def("gdiSelectClipRgn", [](XCDraw& self, uintptr_t hRgn) -> uintptr_t {
				return (uintptr_t)self.GDI_SelectClipRgn((HRGN)hRgn);
			}, "hRgn"_a)
			.def("gdiCreateSolidBrush", [](XCDraw& self, COLORREF color) -> uintptr_t {
				return (uintptr_t)self.GDI_CreateSolidBrush(color);
			}, "color"_a)
			.def("gdiCreatePen", [](XCDraw& self, int fnPenStyle, int width, COLORREF crColor) -> uintptr_t {
				return (uintptr_t)self.GDI_CreatePen(fnPenStyle, width, crColor);
			}, "penStyle"_a, "width"_a, "color"_a)
			.def("gdiCreateRectRgn", [](XCDraw& self, int left, int top, int right, int bottom) -> uintptr_t {
				return (uintptr_t)self.GDI_CreateRectRgn(left, top, right, bottom);
			}, "left"_a, "top"_a, "right"_a, "bottom"_a)
			.def("gdiCreateRoundRectRgn", [](XCDraw& self, int left, int top, int right, int bottom, int widthEllipse, int heightEllipse) -> uintptr_t {
				return (uintptr_t)self.GDI_CreateRoundRectRgn(left, top, right, bottom, widthEllipse, heightEllipse);
			}, "left"_a, "top"_a, "right"_a, "bottom"_a, "widthEllipse"_a, "heightEllipse"_a)
			.def("gdiCreatePolygonRgn", [](XCDraw& self, const std::vector<XCPoint>& pointList, int polyFillMode) -> uintptr_t {
				return (uintptr_t)self.GDI_CreatePolygonRgn( (POINT*)(& pointList[0]),  pointList.size(), polyFillMode);
			}, "pointList"_a, "polyFillMode"_a)
			.def("gdiRectangle", &XCDraw::GDI_Rectangle, "left"_a, "top"_a, "right"_a, "bottom"_a)
			
			.def("gdiFillRgn", [](XCDraw& self, uintptr_t hRgn, uintptr_t hBrush){
				return self.GDI_FillRgn((HRGN)hRgn, (HBRUSH)hBrush);
			}, "hRgn"_a, "hBrush"_a)

			.def("gdiEllipse", [](XCDraw& self, const XCRect& rect) {
				return self.GDI_Ellipse((RECT*)&rect);
			}, "rect"_a)
		
			.def("gdiFrameRgn", [](XCDraw& self, uintptr_t hRgn, uintptr_t hBrush, int width, int height) {
				return self.GDI_FrameRgn((HRGN)hRgn, (HBRUSH)hBrush, width, height);
			}, "hRgn"_a, "hBrush"_a, "width"_a, "height"_a)
				
			.def("gdiMoveToEx", [](XCDraw& self, int x, int y) -> XCPoint {
				XCPoint point;
				self.GDI_MoveToEx(x, y, (POINT*)&point);
				return point;
			}, "x"_a, "y"_a)

			.def("gdiLineTo", &XCDraw::GDI_LineTo, "xEnd"_a, "yEnd"_a)
			.def("gdiPolyline", [](XCDraw& self, const std::vector<XCPoint>& pointList) {
				return (uintptr_t)self.GDI_Polyline( (POINT*)(& pointList[0]),  pointList.size());
			}, "pointList"_a)

			.def("gdiDrawIconEx", [](XCDraw& self, int xLeft, int yTop, uintptr_t hIcon, int cxWidth, int cyWidth,
				UINT istepIfAniCur, uintptr_t hbrFlickerFreeDraw, UINT diFlags){
				return self.GDI_DrawIconEx(xLeft, yTop, (HICON)hIcon, cxWidth, cyWidth, 
					istepIfAniCur, (HBRUSH)hbrFlickerFreeDraw, diFlags);
			}, "xLeft"_a, "yTop"_a, "hIcon"_a, "cxWidth"_a, "cyWidth"_a, "stepIfAniCur"_a, "hbrFlickerFreeDraw"_a, "diFlags"_a)

			.def("gdiBitBlt", [](XCDraw& self, int nXDest, int nYDest, int width, int nHeight, 
				uintptr_t hdcSrc, int nXSrc, int nYSrc, DWORD dwRop){
				return self.GDI_BitBlt(nXDest, nYDest, width, nHeight, (HDC)hdcSrc,
					nXSrc, nYSrc, dwRop);
			}, "xDest"_a, "yDest"_a, "width"_a, "height"_a, "hdcSrc"_a, "xSrc"_a, "ySrc"_a, "rop"_a)
			
			.def("gdiBitBlt2", [](XCDraw& self, int nXDest, int nYDest, int width, int nHeight, 
				const XCDraw& drawSrc , int nXSrc, int nYSrc, DWORD dwRop){
				return self.GDI_BitBlt2(nXDest, nYDest, width, nHeight, drawSrc.getDrawHandle(),
					nXSrc, nYSrc, dwRop);
			}, "xDest"_a, "yDest"_a, "width"_a, "height"_a, "drawSrc"_a, "xSrc"_a, "ySrc"_a, "rop"_a)	

			.def("gdiAlphaBlend", &XCDraw::GDI_AlphaBlend, "xOriginDest"_a, "yOriginDest"_a, "widthDest"_a, "heightDest"_a, 
				"hdcSrc"_a, "xOriginSrc"_a, "yOriginSrc"_a, "widthSrc"_a, "heightSrc"_a, "alpha"_a)

			.def("gdiSetPixel", &XCDraw::GDI_SetPixel, "x"_a, "y"_a, "color"_a)
			.def("getHDC", [](XCDraw& self) {
				return (uintptr_t)self.GetHDC();
			})
			.def("getD2dRenderTarget", &XCDraw::GetD2dRenderTarget)
			.def("setD2dTextRenderingMode", &XCDraw::SetD2dTextRenderingMode, "mode"_a)
			.def("setTextRenderingHint", &XCDraw::SetTextRenderingHint, "nType"_a)
			.def("setBrushColor", &XCDraw::SetBrushColor, "color"_a)
			.def("setTextVertical", &XCDraw::SetTextVertical, "vertical"_a)

 			.def("setTextAlign", &XCDraw::SetTextAlign, "flag"_a)
			.def("setFont", [](XCDraw& self, const XCFont& font) {
				self.SetFont(font.getFontHandle());
			}, "font"_a)
			.def("setLineWidth", &XCDraw::SetLineWidth, "width"_a)
			.def("setLineWidthF", &XCDraw::SetLineWidthF, "width"_a)
			.def("setClipRect", [](XCDraw& self, const XCRect& rect) {
				self.SetClipRect((RECT*)&rect);
			}, "rect"_a)

			.def("clearClip", &XCDraw::ClearClip)
			.def("enableSmoothingMode", &XCDraw::EnableSmoothingMode, "enable"_a)
			.def("enableWndTransparent", &XCDraw::EnableWndTransparent, "enable"_a)

			.def("fillRect", [](XCDraw& self, const XCRect& rect) {
				self.FillRect((RECT*)&rect);
			}, "rect"_a)
			.def("fillRectF", [](XCDraw& self, const XCRectF& rect) {
				self.FillRectF((RECTF*)&rect);
			}, "rect"_a)

			.def("fillRectColor", [](XCDraw& self, const XCRect& rect, COLORREF color) {
				self.FillRectColor((RECT*)&rect, color);
			}, "rect"_a, "color"_a)
			.def("fillRectColorF", [](XCDraw& self, const XCRectF& rect, COLORREF color) {
				self.FillRectColorF((RECTF*)&rect, color);
			}, "rect"_a, "color"_a)
			
			.def("drawEllipse", [](XCDraw& self, const XCRect& rect) {
				self.DrawEllipse((RECT*)&rect);
			}, "rect"_a)
			.def("drawEllipseF", [](XCDraw& self, const XCRectF& rect) {
				self.DrawEllipseF((RECTF*)&rect);
			}, "rect"_a)

			.def("fillRoundRect", [](XCDraw& self, const XCRect& rect, int width, int height) {
				self.FillRoundRect((RECT*)&rect, width, height);
			}, "rect"_a, "width"_a, "height"_a)
			.def("fillRoundRectF", [](XCDraw& self, const XCRectF& rect, float width, float height) {
				self.FillRoundRectF((RECTF*)&rect, width, height);
			}, "rect"_a, "width"_a, "height"_a)

			.def("drawRoundRect", [](XCDraw& self, const XCRect& rect, int width, int height) {
				self.DrawRoundRect((RECT*)&rect, width, height);
			}, "rect"_a, "width"_a, "height"_a)
			.def("drawRoundRectF", [](XCDraw& self, const XCRectF& rect, float width, float height) {
				self.DrawRoundRectF((RECTF*)&rect, width, height);
			}, "rect"_a, "width"_a, "height"_a)

			.def("fillRoundRectEx", [](XCDraw& self, const XCRect& rect, int leftTop, int rightTop, int rightBottom, int leftBottom) {
				self.FillRoundRectEx((RECT*)&rect, leftTop, rightTop, rightBottom, leftBottom);
			}, "rect"_a, "leftTop"_a, "rightTop"_a, "rightBottom"_a, "leftBottom"_a)
			.def("fillRoundRectExF", [](XCDraw& self, const XCRectF& rect, float leftTop, float rightTop, float rightBottom, float leftBottom) {
				self.FillRoundRectExF((RECTF*)&rect, leftTop, rightTop, rightBottom, leftBottom);
			}, "rect"_a, "leftTop"_a, "rightTop"_a, "rightBottom"_a, "leftBottom"_a)

			.def("drawRoundRectEx", [](XCDraw& self, const XCRect& rect, int leftTop, int rightTop, int rightBottom, int leftBottom) {
				self.DrawRoundRectEx((RECT*)&rect, leftTop, rightTop, rightBottom, leftBottom);
			}, "rect"_a, "leftTop"_a, "rightTop"_a, "rightBottom"_a, "leftBottom"_a)
			.def("drawRoundRectExF", [](XCDraw& self, const XCRectF& rect, float leftTop, float rightTop, float rightBottom, float leftBottom) {
				self.DrawRoundRectExF((RECTF*)&rect, leftTop, rightTop, rightBottom, leftBottom);
			}, "rect"_a, "leftTop"_a, "rightTop"_a, "rightBottom"_a, "leftBottom"_a)

			.def("gradientFill2", [](XCDraw& self, const XCRect& rect, COLORREF color1, COLORREF color2, int mode) {
				self.GradientFill2((RECT*)&rect, color1, color2, mode);
			}, "rect"_a, "color1"_a, "color2"_a, "mode"_a)
			.def("gradientFill2F", [](XCDraw& self, const XCRectF& rect, COLORREF color1, COLORREF color2, int mode) {
				self.GradientFill2F((RECTF*)&rect, color1, color2, mode);
			}, "rect"_a, "color1"_a, "color2"_a, "mode"_a)

			.def("gradientFill4", [](XCDraw& self, const XCRect& rect, COLORREF color1, COLORREF color2,
				COLORREF color3, COLORREF color4, int mode) {
				self.GradientFill4((RECT*)&rect, color1, color2, color3, color4, mode);
			}, "rect"_a, "color1"_a, "color2"_a, "color3"_a, "color4"_a, "mode"_a)

			.def("gradientFill4F", [](XCDraw& self, const XCRectF& rect, COLORREF color1, COLORREF color2,
				COLORREF color3, COLORREF color4, int mode) {
				self.GradientFill4F((RECTF*)&rect, color1, color2, color3, color4, mode);
			}, "rect"_a, "color1"_a, "color2"_a, "color3"_a, "color4"_a, "mode"_a)

			.def("drawRect", [](XCDraw& self, const XCRect& rect) {
				self.DrawRect((RECT*)&rect);
			}, "rect"_a)
			.def("drawRectF", [](XCDraw& self, const XCRectF& rect) {
				self.DrawRectF((RECTF*)&rect);
			}, "rect"_a)

			.def("drawLine", [](XCDraw& self, int x1, int y1, int x2, int y2) {
				self.DrawLine(x1, y1, x2, y2);
			}, "x1"_a, "y1"_a, "x2"_a, "y2"_a)
			.def("drawLineF", [](XCDraw& self, float x1, float y1, float x2, float y2) {
				self.DrawLineF(x1, y1, x2, y2);
			}, "x1"_a, "y1"_a, "x2"_a, "y2"_a)

			.def("drawCurve", [](XCDraw& self, const std::vector<XCPoint>& pointList, float tension) {
				self.DrawCurve( (POINT*)(& pointList[0]),  pointList.size(), tension);
			}, "pointList"_a, "tension"_a)
			 .def("drawCurveF", [](XCDraw& self, const std::vector<XCPointF>& pointList, float tension) {
				self.DrawCurveF( (POINTF*)(& pointList[0]),  pointList.size(), tension);
			}, "pointList"_a, "tension"_a)

			.def("drawArc", &XCDraw::DrawArc, "x"_a, "y"_a, "width"_a, "height"_a, "startAngle"_a, "sweepAngle"_a)
			.def("drawArcF", &XCDraw::DrawArcF, "x"_a, "y"_a, "width"_a, "height"_a, "startAngle"_a, "sweepAngle"_a)

			.def("focusRect", [](XCDraw& self, const XCRect& rect) {
				self.FocusRect((RECT*)&rect);
			}, "rect"_a)
			.def("focusRectF", [](XCDraw& self, const XCRectF& rect) {
				self.FocusRectF((RECTF*)&rect);
			}, "rect"_a)

			.def("dottedline", [](XCDraw& self, int x1, int y1, int x2, int y2) {
				self.Dottedline(x1, y1, x2, y2);
			}, "x1"_a, "y1"_a, "x2"_a, "y2"_a)
			.def("dottedlineF", [](XCDraw& self, float x1, float y1, float x2, float y2) {
				self.DottedlineF(x1, y1, x2, y2);
			}, "x1"_a, "y1"_a, "x2"_a, "y2"_a)

			.def("drawPolygon", [](XCDraw& self, const std::vector<XCPoint>& pointList) {
				self.DrawPolygon( (POINT*)(& pointList[0]),  pointList.size());
			}, "pointList"_a)
			.def("drawPolygonF", [](XCDraw& self, const std::vector<XCPointF>& pointList) {
				self.DrawPolygonF( (POINTF*)(& pointList[0]),  pointList.size());
			}, "pointList"_a)

			.def("fillPolygon", [](XCDraw& self, const std::vector<XCPoint>& pointList) {
				self.FillPolygon( (POINT*)(& pointList[0]),  pointList.size());
			}, "pointList"_a)
			.def("fillPolygonF", [](XCDraw& self, const std::vector<XCPointF>& pointList) {
				self.FillPolygonF( (POINTF*)(& pointList[0]),  pointList.size());
			}, "pointList"_a)

			.def("image", [](XCDraw& self, const XCImage& image, int x, int y) {
				self.Image(image.getImageHandle(), x, y);
			}, "image"_a, "x"_a, "y"_a)
			.def("imageF", [](XCDraw& self, const XCImage& image, float x, float y) {
				self.ImageF(image.getImageHandle(), x, y);
			}, "imageF"_a, "x"_a, "y"_a)

			.def("imageEx", [](XCDraw& self, const XCImage& image, int x, int y, int width, int height) {
				self.ImageEx(image.getImageHandle(), x, y, width, height);
			}, "image"_a, "x"_a, "y"_a, "width"_a, "height"_a)
			.def("imageExF", [](XCDraw& self, const XCImage& image, float x, float y, float width, float height) {
				self.ImageExF(image.getImageHandle(), x, y, width, height);
			}, "image"_a, "x"_a, "y"_a, "width"_a, "height"_a)

			.def("imageAdaptive", [](XCDraw& self, const XCImage& image, const XCRect& rect, bool onlyBorder=false) {
				self.ImageAdaptive(image.getImageHandle(), (RECT*)&rect, onlyBorder);
			}, "image"_a, "rect"_a, "onlyBorder"_a=false)
			.def("imageAdaptiveF", [](XCDraw& self, const XCImage& image, const XCRectF& rect, bool onlyBorder=false) {
				self.ImageAdaptiveF(image.getImageHandle(), (RECTF*)&rect, onlyBorder);
			}, "image"_a, "rect"_a, "onlyBorder"_a=false)

			.def("imageTile", [](XCDraw& self, const XCImage& image, const XCRect& rect, int flag=0) {
				self.ImageTile(image.getImageHandle(), (RECT*)&rect, flag);
			}, "image"_a, "rect"_a, "flag"_a=0)
			.def("imageTileF", [](XCDraw& self, const XCImage& image, const XCRectF& rect, int flag=0) {
				self.ImageTileF(image.getImageHandle(), (RECTF*)&rect, flag);
			}, "image"_a, "rect"_a, "flag"_a=0)

			.def("imageSuper", [](XCDraw& self, const XCImage& image, const XCRect& rect, bool bClip=false) {
				self.ImageSuper(image.getImageHandle(), (RECT*)&rect, bClip);
			}, "image"_a, "rect"_a, "clip"_a=false)
			.def("imageSuperF", [](XCDraw& self, const XCImage& image, const XCRectF& rect, bool bClip=false) {
				self.ImageSuperF(image.getImageHandle(), (RECTF*)&rect, bClip);
			}, "image"_a, "rect"_a, "clip"_a=false)

			.def("imageSuperEx", [](XCDraw& self, const XCImage& image, const XCRect& rectDest, const XCRect& rectSrc) {
				self.ImageSuperEx(image.getImageHandle(), (RECT*)&rectDest, (RECT*)&rectSrc);
			}, "image"_a, "rectDest"_a, "rectSrc"_a)
			.def("imageSuperExF", [](XCDraw& self, const XCImage& image, const XCRectF& rectDest, const XCRectF& rectSrc) {
				self.ImageSuperExF(image.getImageHandle(), (RECTF*)&rectDest, (RECTF*)&rectSrc);
			}, "image"_a, "rectDest"_a, "rectSrc"_a)

			.def("imageMask", [](XCDraw& self, const XCImage& image, const XCImage& imageMask, const XCRect& rect, int x2, int y2) {
				self.ImageMask(image.getImageHandle(), imageMask.getImageHandle(), (RECT*)&rect, x2, y2);
			}, "image"_a, "imageMask"_a, "rect"_a, "x2"_a, "y2"_a)

			.def("ImageSuperMask", [](XCDraw& self, const XCImage& image, const XCImage& imageMask,
				const XCRect& rect, const XCRect& rectMask, bool bClip=false) {
				self.ImageSuperMask(image.getImageHandle(), imageMask.getImageHandle(), (RECT*)&rect, (RECT*)&rectMask, bClip);
			}, "image"_a, "imageMask"_a, "rect"_a, "rectMask"_a, "clip"_a)

			.def("drawText", [](XCDraw& self, const std::wstring& text, const XCRect& rect) {
				self.DrawText(text, (RECT*)&rect);
			}, "text"_a, "rect"_a)
			.def("drawTextF", [](XCDraw& self, const std::wstring& text, const XCRectF& rect) {
				self.DrawTextF(text, (RECTF*)&rect);
			}, "text"_a, "rect"_a)

			.def("drawTextUnderline", [](XCDraw& self, const std::wstring& text, const XCRect& rect, COLORREF colorLine) {
				self.DrawTextUnderline(text, (RECT*)&rect, colorLine);
			}, "text"_a, "rect"_a, "lineColor"_a)
			.def("drawTextUnderlineF", [](XCDraw& self, const std::wstring& text, const XCRectF& rect, COLORREF colorLine) {
				self.DrawTextUnderlineF(text, (RECTF*)&rect, colorLine);
			}, "text"_a, "rect"_a, "lineColor"_a)

			.def("textOut", [](XCDraw& self, int xStart, int yStart, const std::wstring& text) {
				self.TextOut(xStart, yStart, text);
			}, "xStart"_a, "yStart"_a, "text"_a)
			.def("textOutF", [](XCDraw& self, float xStart, float yStart, const std::wstring& text) {
				self.TextOutF(xStart, yStart, text);
			}, "xStart"_a, "yStart"_a, "text"_a)

			.def("textOutEx", [](XCDraw& self, int xStart, int yStart, const std::wstring& text) {
				self.TextOutEx(xStart, yStart, text);
			}, "xStart"_a, "yStart"_a, "text"_a)
			.def("textOutExF", [](XCDraw& self, float xStart, float yStart, const std::wstring& text) {
				self.TextOutExF(xStart, yStart, text);
			}, "xStart"_a, "yStart"_a, "text"_a)

			.def("drawSvgSrc", [](XCDraw& self, const XCSvg& svg) {
				self.DrawSvgSrc(svg.getSvgHandle());
			}, "svg"_a)		
			.def("drawSvg", [](XCDraw& self, const XCSvg& svg, int x, int y) {
				self.DrawSvg(svg.getSvgHandle(), x, y);
			}, "svg"_a, "x"_a, "y"_a)
			.def("drawSvgEx", [](XCDraw& self, const XCSvg& svg, int x, int y, int width, int height) {
				self.DrawSvgEx(svg.getSvgHandle(), x, y, width, height);
			}, "svg"_a, "x"_a, "y"_a, "width"_a, "height"_a)
			.def("drawSvgSize", [](XCDraw& self, const XCSvg& svg, int width, int height) {
				self.DrawSvgSize(svg.getSvgHandle(), width, height);
			}, "svg"_a, "width"_a, "height"_a);
	}
}