#pragma once
#include "pch.h"
#include "XCObject.hpp"
#include "XCWindow.hpp"

namespace xcgui {

	class XCDraw : public XCObject
	{
	public:
		XCDraw()
			: XCObject()
		{
		}

		XCDraw(HDRAW drawHandle)
			:XCObject(drawHandle)
		{
			m_handle = drawHandle;
		}

		HDRAW getDrawHandle() const
		{
			return (HDRAW)m_handle;
		}

		XCDraw(HWINDOW hWin)
		{
			m_handle = XDraw_Create(hWin);
	
		}

		HDRAW Create(HWINDOW hWin) {
			m_handle = XDraw_Create(hWin);
			return (HDRAW)m_handle;
		}

		// 创建图形绘制模块实例
		HDRAW CreateGDI(HWINDOW hWindow, HDC hdc) {
			m_handle = XDraw_CreateGDI(hWindow, hdc);
			return (HDRAW)m_handle;
		}

		// 销毁图形绘制模块实例句柄.  
		void Destroy() {
			XDraw_Destroy((HDRAW)m_handle);
		}

		// 设置坐标偏移量,X向左偏移为负数,向右偏移为正数.  
		void SetOffset(int x, int y) {
			XDraw_SetOffset((HDRAW)m_handle, x, y);
		}

		// 获取坐标偏移量,X向左偏移为负数,向右偏移为正数.  
		void GetOffset(int* pX, int* pY) {
			XDraw_GetOffset((HDRAW)m_handle, pX, pY);
		}

		// 还原状态,释放用户绑定的GDI对象,例如画刷,画笔
		void GDI_RestoreGDIOBJ() {
			XDraw_GDI_RestoreGDIOBJ((HDRAW)m_handle);
		}

		// GDI_置背景模式
		int GDI_SetBkMode(bool bTransparent) {
			return XDraw_GDI_SetBkMode((HDRAW)m_handle, bTransparent);
		}

		// 选择一个区域作为当前裁剪区域,注意:该函数只对GDI有效
		//@参数 hRgn 区域句柄.
		//@返回 返回值指定地区的复杂性，可以是下列值之一.\n
		//@别名  GDI_选择裁剪区域()
		int GDI_SelectClipRgn(HRGN hRgn) {
			return XDraw_GDI_SelectClipRgn((HDRAW)m_handle, hRgn);
		}

		// GDI创建具有指定的纯色逻辑刷
		//@参数 crColor 画刷颜色.
		//@返回 如果函数成功,返回值标识一个逻辑刷,如果函数失败,返回值是NULL.
		//@别名  GDI_创建实心画刷()
		HBRUSH GDI_CreateSolidBrush(COLORREF crColor) {
			return XDraw_GDI_CreateSolidBrush((HDRAW)m_handle, crColor);
		}

		// GDI创建一个逻辑笔,指定的样式,宽度和颜色,随后的笔可以选择到设备上下文,用于绘制线条和曲线
		//@参数 fnPenStyle 画笔样式, PS_SOLID:实线 PS_DASH:段线 PS_DOT:点线  PS_DASHDOT:段线_点线 PS_DASHDOTDOT:段线_点_点 PS_NULL:空  PS_INSIDEFRAME:实线_笔宽是向里扩展
		//@参数 width 画笔宽度
		//@参数 crColor 颜色
		//@返回 如果函数成功,返回值是一个句柄,标识一个逻辑笔,如果函数失败,返回值是NULL.
		//@别名  GDI_创建画笔()
		HPEN GDI_CreatePen(int fnPenStyle, int width, COLORREF crColor) {
			return XDraw_GDI_CreatePen((HDRAW)m_handle, fnPenStyle, width, crColor);
		}


		// GDI创建矩形区域
		//@参数 nLeftRect 左上角X坐标.
		//@参数 nTopRect 左上角Y坐标.
		//@参数 nRightRect 右下角X坐标.
		//@参数 nBottomRect 右下角Y坐标.
		//@返回 成功返回区域句柄,失败返回NULL.
		//@别名  GDI_创建矩形区域()
		HRGN GDI_CreateRectRgn(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect) {
			return XDraw_GDI_CreateRectRgn((HDRAW)m_handle, nLeftRect, nTopRect, nRightRect, nBottomRect);
		}


		// GDI创建一个圆角的矩形区域
		//@参数 nLeftRect X-坐标的左上角.
		//@参数 nTopRect Y-坐标左上角坐标
		//@参数 nRightRect X-坐标右下角
		//@参数 nBottomRect Y-坐标右下角
		//@参数 nWidthEllipse 椭圆的宽度.
		//@参数 nHeightEllipse 椭圆的高度.
		//@返回 如果函数成功,返回值是该区域的句柄,如果函数失败,返回值是NULL.
		//@别名  GDI_创建圆角矩形区域()
		HRGN GDI_CreateRoundRectRgn(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, int nWidthEllipse, int nHeightEllipse) {
			return XDraw_GDI_CreateRoundRectRgn((HDRAW)m_handle, nLeftRect, nTopRect, nRightRect, nBottomRect, nWidthEllipse, nHeightEllipse);
		}

		// GDI创建一个多边形区域
		//@参数 pPt POINT数组.
		//@参数 cPoints 数组大小.
		//@参数 fnPolyFillMode 多边形填充模式,指定用于确定在该地区的像素填充模式,这个参数可以是下列值之一.\n
		//@返回 如果函数成功,返回值是该区域的句柄,如果函数失败,返回值是NULL.
		//@别名  GDI_创建多边形区域()
		HRGN GDI_CreatePolygonRgn(POINT* pPt, int cPoints, int fnPolyFillMode) {
			return XDraw_GDI_CreatePolygonRgn((HDRAW)m_handle, pPt, cPoints, fnPolyFillMode);
		}

		// 绘制矩形,使用当前的画刷和画笔
		//@参数 nLeftRect 左上角X坐标.
		//@参数 nTopRect 左上角Y坐标.
		//@参数 nRightRect 右下角X坐标.
		//@参数 nBottomRect 右下角Y坐标.
		//@返回 如果函数成功,返回非零值,如果函数失败,返回值是零.
		//@别名  GDI_矩形()
		bool GDI_Rectangle(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect) {
			return XDraw_GDI_Rectangle((HDRAW)m_handle, nLeftRect, nTopRect, nRightRect, nBottomRect);
		}

		// 通过使用指定的画刷填充一个区域
		//@参数 hrgn 区域句柄.
		//@参数 hbr 画刷句柄.
		//@返回 如果函数成功,返回非零值,如果函数失败,返回值是零.
		//@别名  GID_填充区域()
		bool GDI_FillRgn(HRGN hrgn, HBRUSH hbr) {
			return XDraw_GDI_FillRgn((HDRAW)m_handle, hrgn, hbr);
		}

		//@参数 pRect 矩形区域
		//@返回 如果成功返回TRUE,否则返回FALSE
		//@别名  GDI_椭圆()
		bool GDI_Ellipse(RECT* pRect) {
			return XDraw_GDI_Ellipse((HDRAW)m_handle, pRect);
		}

		// 绘制边框,使用指定的画刷绘制指定的区域的边框
		//@参数 hrgn 区域句柄.
		//@参数 hbr 画刷句柄.
		//@参数 width 边框宽度,垂直边.
		//@参数 height 边框高度,水平边.
		//@返回 如果函数成功,返回非零值,如果函数失败,返回值是零.
		//@别名  GDI_边框区域()
		bool GDI_FrameRgn(HRGN hrgn, HBRUSH hbr, int width, int nHeight) {
			return XDraw_GDI_FrameRgn((HDRAW)m_handle, hrgn, hbr, width, nHeight);
		}

		// 更新当前位置到指定点，并返回以前的位置
		//@参数 X 坐标.
		//@参数 Y 坐标.
		//@参数 pPoint 接收以前的当前位置到一个POINT结构的指针,如果这个参数是NULL指针,没有返回原来的位置.
		//@返回 如果函数成功,返回非零值,如果函数失败,返回值是零.
		//@别名  GDI_移动到起点()
		bool GDI_MoveToEx(int X, int Y, POINT* pPoint = NULL) {
			return XDraw_GDI_MoveToEx((HDRAW)m_handle, X, Y, pPoint);
		}

		// 函数绘制一条线从当前位置到,但不包括指定点
		//@参数 nXEnd X坐标,线结束点.
		//@参数 nYEnd Y坐标,线结束点.
		//@返回 如果函数成功,返回非零值,如果函数失败,返回值是零.
		//@别名  GDI_线终点()
		bool GDI_LineTo(int nXEnd, int nYEnd) {
			return XDraw_GDI_LineTo((HDRAW)m_handle, nXEnd, nYEnd);
		}

		// Polyline() 参见MSDN
		//@参数 pArrayPt 参见MSDN.
		//@参数 arrayPtSize 参见MSDN.
		//@返回 参见MSDN.
		//@别名  GDI_折线()
		bool GDI_Polyline(POINT* pArrayPt, int arrayPtSize) {
			return XDraw_GDI_Polyline((HDRAW)m_handle, pArrayPt, arrayPtSize);
		}

		// 绘制图标,DrawIconEx()参见MSDN
		//@参数 xLeft .
		//@参数 yTop .
		//@参数 hIcon .
		//@参数 cxWidth .
		//@参数 cyWidth .
		//@参数 istepIfAniCur .
		//@参数 hbrFlickerFreeDraw .
		//@参数 diFlags .
		//@返回 .
		//@别名  GDI_图标扩展()
		bool GDI_DrawIconEx(int xLeft, int yTop, HICON hIcon, int cxWidth, int cyWidth, UINT istepIfAniCur, HBRUSH hbrFlickerFreeDraw, UINT diFlags) {
			return XDraw_GDI_DrawIconEx((HDRAW)m_handle, xLeft, yTop, hIcon, cxWidth, cyWidth, istepIfAniCur, hbrFlickerFreeDraw, diFlags);
		}

		// BitBlt() 参见MSDN
		//@参数 nXDest XX.
		//@参数 nYDest XX.
		//@参数 width XX.
		//@参数 height XX.
		//@参数 hdcSrc XX.
		//@参数 nXSrc XX.
		//@参数 nYSrc XX.
		//@参数 dwRop XX.
		//@返回 .
		//@别名  GDI_复制()
		bool GDI_BitBlt(int nXDest, int nYDest, int width, int nHeight, HDC hdcSrc, int nXSrc, int nYSrc, DWORD dwRop) {
			return XDraw_GDI_BitBlt((HDRAW)m_handle, nXDest, nYDest, width, nHeight, hdcSrc, nXSrc, nYSrc, dwRop);
		}

		// BitBlt() 参见MSDN
		//@参数 nXDest XX.
		//@参数 nYDest XX.
		//@参数 width XX.
		//@参数 height XX.
		//@参数 hDrawSrc XX.
		//@参数 nXSrc XX.
		//@参数 nYSrc XX.
		//@参数 dwRop XX.
		//@返回 .
		//@别名  GDI_复制2()
		bool GDI_BitBlt2(int nXDest, int nYDest, int width, int nHeight, HDRAW hDrawSrc, int nXSrc, int nYSrc, DWORD dwRop) {
			return XDraw_GDI_BitBlt2((HDRAW)m_handle, nXDest, nYDest, width, nHeight, hDrawSrc, nXSrc, nYSrc, dwRop);
		}

		// AlphaBlend() 参见MSDN
		//@参数 nXOriginDest XX.
		//@参数 nYOriginDest XX.
		//@参数 nWidthDest XX.
		//@参数 nHeightDest XX.
		//@参数 hdcSrc XX.
		//@参数 nXOriginSrc XX.
		//@参数 nYOriginSrc XX.
		//@参数 nWidthSrc XX.
		//@参数 nHeightSrc XX.
		//@参数 alpha XX.
		//@返回 成功返回TRUE否则返回FALSE.
		//@别名  GDI_带透明复制()
		bool GDI_AlphaBlend(int nXOriginDest, int nYOriginDest, int nWidthDest, int nHeightDest, HDC hdcSrc, int nXOriginSrc, int nYOriginSrc, int nWidthSrc, int nHeightSrc, int alpha) {
			return XDraw_GDI_AlphaBlend((HDRAW)m_handle, nXOriginDest, nYOriginDest, nWidthDest, nHeightDest, hdcSrc, nXOriginSrc, nYOriginSrc, nWidthSrc, nHeightSrc, alpha);
		}

		// 函数设置在指定的坐标到指定的颜色的像素
		//@参数 X 坐标
		//@参数 Y 坐标
		//@参数 crColor 颜色值, 请使用宏: RGBA()
		//@返回 如果函数成功返回RGB值,如果失败返回-1.
		//@别名  GDI_置像素颜色()
		COLORREF GDI_SetPixel(int X, int Y, COLORREF crColor) {
			return XDraw_GDI_SetPixel((HDRAW)m_handle, X, Y, crColor);
		}

		// 获取绑定的设备上下文HDC.  
		//@返回 返回HDC句柄. 
		//@别名  取HDC()
		HDC GetHDC() {
			return XDraw_GetHDC((HDRAW)m_handle);
		}

		//@返回 返回 ID2D1RenderTarget*
		//@别名  取D2D渲染目标()
		vint GetD2dRenderTarget() {
			return XDraw_GetD2dRenderTarget((HDRAW)m_handle);
		}

		//@参数 mode 渲染模式  @ref XC_DWRITE_RENDERING_MODE
		//@别名  置D2D文本渲染模式()
		void SetD2dTextRenderingMode(XC_DWRITE_RENDERING_MODE mode) {
			XDraw_SetD2dTextRenderingMode((HDRAW)m_handle, mode);
		}

		// 设置文本渲染质量GDI+
		//@参数 nType 参见GDI+ TextRenderingHint 定义.
		//@别名  置文本炫彩质量()
		void SetTextRenderingHint(int nType) {
			XDraw_SetTextRenderingHint((HDRAW)m_handle, nType);
		}

		// 使用指定颜色清理画布
		//@参数 color 颜色值, 请使用宏: RGBA()
		//@别名  D2D_清理()
		void D2D_Clear(COLORREF color) {
			XDraw_D2D_Clear((HDRAW)m_handle, color);
		}

		// 设置画刷颜色.  
		//@参数 color 颜色值, 请使用宏: RGBA()
		//@别名  置画刷颜色()
		void SetBrushColor(COLORREF color) {
			XDraw_SetBrushColor((HDRAW)m_handle, color);
		}

		// 设置文本垂直显示.  
		//@参数 bVertical 是否垂直显示文本.
		//@别名  置文本垂直()
		void SetTextVertical(bool bVertical) {
			XDraw_SetTextVertical((HDRAW)m_handle, bVertical);
		}

		// 设置文本对齐.  
		//@参数 nFlags 对齐标识 @ref textFormatFlag_ .
		//@别名  置文本对齐()
		void SetTextAlign(int nFlag) {
			XDraw_SetTextAlign((HDRAW)m_handle, nFlag);
		}

		// 设置字体.  
		//@参数 hFontx 炫彩字体.
		//@别名  置字体()
		void SetFont(HFONTX hFontx) {
			XDraw_SetFont((HDRAW)m_handle, hFontx);
		}

		// 设置线宽.  
		//@参数 width 宽度.
		//@别名  置线宽()
		void SetLineWidth(int width) {
			XDraw_SetLineWidth((HDRAW)m_handle, width);
		}

		// 设置线宽
		//@参数 width 宽度.
		//@别名  置线宽F()
		void SetLineWidthF(float width) {
			XDraw_SetLineWidthF((HDRAW)m_handle, width);
		}

		// 设置裁剪区域.  
		//@参数 pRect 区域坐标.
		//@别名  置裁剪区域()
		void SetClipRect(RECT* pRect) {
			XDraw_SetClipRect((HDRAW)m_handle, pRect);
		}

		// 清除裁剪区域.  
		//@别名  清除裁剪区域()
		void ClearClip() {
			XDraw_ClearClip((HDRAW)m_handle);
		}

		// 启用平滑模式.  
		//@参数 bEnable 是否启用.
		//@别名  启用平滑模式()
		void EnableSmoothingMode(bool bEnable) {
			XDraw_EnableSmoothingMode((HDRAW)m_handle, bEnable);
		}

		// 当启用之后,调用GDI+函数时, 如果参数alpha=255,将自动修改为254, 应对GDI+的bug, 否则透明通道异常
		//@参数 bTransparent 是否启用
		//@别名  启用窗口透明判断()
		void EnableWndTransparent(bool bTransparent) {
			XDraw_EnableWndTransparent((HDRAW)m_handle, bTransparent);
		}

		//@参数 pRect 矩形区域.
		//@别名  填充矩形()
		void FillRect(RECT* pRect) {
			XDraw_FillRect((HDRAW)m_handle, pRect);
		}

		//@参数 pRect 矩形区域
		//@别名  填充矩形F()
		void FillRectF(RECTF* pRect) {
			XDraw_FillRectF((HDRAW)m_handle, pRect);
		}

		//@参数 pRect 矩形区域.
		//@参数 color 颜色.
		//@别名  填充矩形指定颜色()
		void FillRectColor(RECT* pRect, COLORREF color) {
			XDraw_FillRectColor((HDRAW)m_handle, pRect, color);
		}

		//@参数 pRect 矩形区域.
		//@参数 color 颜色.
		//@别名  填充矩形指定颜色F()
		void FillRectColorF(RECTF* pRect, COLORREF color) {
			XDraw_FillRectColorF((HDRAW)m_handle, pRect, color);
		}

		//@参数 pRect 矩形区域
		//@别名  填充椭圆()
		void FillEllipse(RECT* pRect) {
			XDraw_FillEllipse((HDRAW)m_handle, pRect);
		}

		//@参数 pRect 矩形区域
		//@别名  填充椭圆F()
		void FillEllipseF(RECTF* pRect) {
			XDraw_FillEllipseF((HDRAW)m_handle, pRect);
		}

		// 绘制椭圆边框
		//@参数 pRect 矩形区域.
		//@别名  椭圆()
		void DrawEllipse(RECT* pRect) {
			XDraw_DrawEllipse((HDRAW)m_handle, pRect);
		}

		// 绘制椭圆边框
		//@参数 pRect 矩形区域.
		//@别名  椭圆F()
		void DrawEllipseF(RECTF* pRect) {
			XDraw_DrawEllipseF((HDRAW)m_handle, pRect);
		}

		// 填充圆角矩形
		//@参数 pRect 矩形坐标.
		//@参数 width 圆角宽度.
		//@参数 height 圆角高度.
		//@别名  填充圆角矩形()
		void FillRoundRect(RECT* pRect, int width, int nHeight) {
			XDraw_FillRoundRect((HDRAW)m_handle, pRect, width, nHeight);
		}

		// 填充圆角矩形
		//@参数 pRect 矩形坐标.
		//@参数 width 圆角宽度.
		//@参数 height 圆角高度.
		//@别名  填充圆角矩形F()
		void FillRoundRectF(RECTF* pRect, float width, float height) {
			XDraw_FillRoundRectF((HDRAW)m_handle, pRect, width, height);
		}

		// 绘制圆角矩形边框.  
		//@参数 pRect 矩形坐标.
		//@参数 width 圆角宽度.
		//@参数 height 圆角高度.
		//@别名  圆角矩形()
		void DrawRoundRect(RECT* pRect, int width, int nHeight) {
			XDraw_DrawRoundRect((HDRAW)m_handle, pRect, width, nHeight);
		}

		// 绘制圆角矩形边框
		//@参数 pRect 矩形坐标.
		//@参数 width 圆角宽度.
		//@参数 height 圆角高度.
		//@别名  圆角矩形F()
		void DrawRoundRectF(RECTF* pRect, float width, float height) {
			XDraw_DrawRoundRectF((HDRAW)m_handle, pRect, width, height);
		}

		// 填充圆角矩形.  
		//@参数 pRect 坐标.
		//@参数 leftTop 圆角大小.
		//@参数 rightTop 圆角大小.
		//@参数 rightBottom 圆角大小.
		//@参数 leftBottom 圆角大小.
		//@别名  填充圆角矩形扩展()
		void FillRoundRectEx(RECT* pRect, int leftTop, int rightTop, int rightBottom, int leftBottom) {
			XDraw_FillRoundRectEx((HDRAW)m_handle, pRect, leftTop, rightTop, rightBottom, leftBottom);
		}

		// 填充圆角矩形
		//@参数 pRect 坐标.
		//@参数 leftTop 圆角大小.
		//@参数 rightTop 圆角大小.
		//@参数 rightBottom 圆角大小.
		//@参数 leftBottom 圆角大小.
		//@别名  填充圆角矩形扩展F()
		void FillRoundRectExF(RECTF* pRect, float leftTop, float rightTop, float rightBottom, float leftBottom) {
			XDraw_FillRoundRectExF((HDRAW)m_handle, pRect, leftTop, rightTop, rightBottom, leftBottom);
		}

		// 绘制圆角矩形边框  
		//@参数 pRect 坐标.
		//@参数 leftTop 圆角大小.
		//@参数 rightTop 圆角大小.
		//@参数 rightBottom 圆角大小.
		//@参数 leftBottom 圆角大小.
		//@别名  圆角矩形扩展()
		void DrawRoundRectEx(RECT* pRect, int leftTop, int rightTop, int rightBottom, int leftBottom) {
			XDraw_DrawRoundRectEx((HDRAW)m_handle, pRect, leftTop, rightTop, rightBottom, leftBottom);
		}

		// 绘制圆角矩形边框
		//@参数 pRect 坐标.
		//@参数 leftTop 圆角大小.
		//@参数 rightTop 圆角大小.
		//@参数 rightBottom 圆角大小.
		//@参数 leftBottom 圆角大小.
		//@别名  圆角矩形扩展F()
		void DrawRoundRectExF(RECTF* pRect, float leftTop, float rightTop, float rightBottom, float leftBottom) {
			XDraw_DrawRoundRectExF((HDRAW)m_handle, pRect, leftTop, rightTop, rightBottom, leftBottom);
		}

		// 渐变填充,从一种颜色过渡到另一种颜色.  
		//@参数 pRect 矩形坐标.
		//@参数 color1 开始颜色.
		//@参数 color2 结束颜色.
		//@参数 mode 模式.
		//@别名  渐变填充2()
		void GradientFill2(RECT* pRect, COLORREF color1, COLORREF color2, int mode) {
			XDraw_GradientFill2((HDRAW)m_handle, pRect, color1, color2, mode);
		}

		// 渐变填充,从一种颜色过渡到另一种颜色
		//@参数 pRect 矩形坐标.
		//@参数 color1 开始颜色.
		//@参数 color2 结束颜色.
		//@参数 mode 模式.
		//@别名  渐变填充2F()
		void GradientFill2F(RECTF* pRect, COLORREF color1, COLORREF color2, int mode) {
			XDraw_GradientFill2F((HDRAW)m_handle, pRect, color1, color2, mode);
		}

		// 渐变填充,从一种颜色过渡到另一种颜色.  
		//@参数 pRect 矩形坐标.
		//@参数 color1 开始颜色.
		//@参数 color2 结束颜色,中间.
		//@参数 color3 开始颜色,中间.
		//@参数 color4 结束颜色.
		//@参数 mode 模式.
		//@别名  渐变填充4()
		void GradientFill4(RECT* pRect, COLORREF color1, COLORREF color2, COLORREF color3, COLORREF color4, int mode) {
			XDraw_GradientFill4((HDRAW)m_handle, pRect, color1, color2, color3, color4, mode);
		}

		// 渐变填充,从一种颜色过渡到另一种颜色
		//@参数 pRect 矩形坐标.
		//@参数 color1 开始颜色.
		//@参数 color2 结束颜色,中间.
		//@参数 color3 开始颜色,中间.
		//@参数 color4 结束颜色.
		//@参数 mode 模式.
		//@别名  渐变填充4F()
		void GradientFill4F(RECTF* pRect, COLORREF color1, COLORREF color2, COLORREF color3, COLORREF color4, int mode) {
			XDraw_GradientFill4F((HDRAW)m_handle, pRect, color1, color2, color3, color4, mode);
		}

		// 绘制矩形边框  
		//@参数 pRect 矩形坐标
		//@别名  矩形()
		void DrawRect(RECT* pRect) {
			XDraw_DrawRect((HDRAW)m_handle, pRect);
		}

		// 绘制矩形边框
		//@参数 pRect 矩形坐标
		//@别名  矩形F()
		void DrawRectF(RECTF* pRect) {
			XDraw_DrawRectF((HDRAW)m_handle, pRect);
		}

		// 绘制线条.  
		//@参数 x1 坐标.
		//@参数 y1 坐标.
		//@参数 x2 坐标.
		//@参数 y2 坐标.
		//@别名  线条()
		void DrawLine(int x1, int y1, int x2, int y2) {
			XDraw_DrawLine((HDRAW)m_handle, x1, y1, x2, y2);
		}

		// 绘制线条
		//@参数 x1 坐标.
		//@参数 y1 坐标.
		//@参数 x2 坐标.
		//@参数 y2 坐标.
		//@别名  线条F()
		void DrawLineF(float x1, float y1, float x2, float y2) {
			XDraw_DrawLineF((HDRAW)m_handle, x1, y1, x2, y2);
		}

		// D2D暂时留空
		//@参数 points 坐标点数组
		//@参数 count 数组大小
		//@参数 tension 大于或等于0.0F的值，指定曲线的张力。D2D 忽略此参数
		//@别名  曲线()
		void DrawCurve(POINT* points, int count, float tension) {
			XDraw_DrawCurve((HDRAW)m_handle, points, count, tension);
		}

		// D2D暂时留空
		//@参数 points 坐标点数组
		//@参数 count 数组大小
		//@参数 tension 大于或等于0.0F的值，指定曲线的张力。D2D 忽略此参数
		//@别名  曲线F()
		void DrawCurveF(POINTF* points, int count, float tension) {
			XDraw_DrawCurveF((HDRAW)m_handle, points, count, tension);
		}

		//@参数 x 坐标
		//@参数 y 坐标
		//@参数 width 宽度
		//@参数 height 高度
		//@参数 startAngle 起始角度
		//@参数 sweepAngle 绘制角度, 从起始角度开始计算
		//@别名  圆弧()
		void DrawArc(int x, int y, int width, int nHeight, float startAngle, float sweepAngle) {
			XDraw_DrawArc((HDRAW)m_handle, x, y, width, nHeight, startAngle, sweepAngle);
		}

		//@参数 x 坐标
		//@参数 y 坐标
		//@参数 width 宽度
		//@参数 height 高度
		//@参数 startAngle 起始角度
		//@参数 sweepAngle 绘制角度, 从起始角度开始计算
		//@别名  圆弧F()
		void DrawArcF(float x, float y, float width, float height, float startAngle, float sweepAngle) {
			XDraw_DrawArcF((HDRAW)m_handle, x, y, width, height, startAngle, sweepAngle);
		}

		// 绘制焦点矩形.  
		//@参数 pRect 矩形坐标.
		//@别名  焦点矩形()
		void FocusRect(RECT* pRect) {
			XDraw_FocusRect((HDRAW)m_handle, pRect);
		}

		// 绘制焦点矩形
		//@参数 pRect 矩形坐标.
		//@别名  焦点矩形F()
		void FocusRectF(RECTF* pRect) {
			XDraw_FocusRectF((HDRAW)m_handle, pRect);
		}

		// 绘制水平或垂直虚线.  
		//@参数 x1 起点x坐标.
		//@参数 y1 起点y坐标.
		//@参数 x2 结束点x坐标.
		//@参数 y2 结束点y坐标.
		//@别名  虚线()
		void Dottedline(int x1, int y1, int x2, int y2) {
			XDraw_Dottedline((HDRAW)m_handle, x1, y1, x2, y2);
		}

		// 绘制水平或垂直虚线
		//@参数 x1 起点x坐标.
		//@参数 y1 起点y坐标.
		//@参数 x2 结束点x坐标.
		//@参数 y2 结束点y坐标.
		//@别名  虚线F()
		void DottedlineF(float x1, float y1, float x2, float y2) {
			XDraw_DottedlineF((HDRAW)m_handle, x1, y1, x2, y2);
		}

		// 绘制多边形.  
		//@参数 points 顶点坐标数组.
		//@参数 nCount 顶点数量.
		//@别名  多边形()
		void DrawPolygon(POINT* points, int nCount) {
			XDraw_DrawPolygon((HDRAW)m_handle, points, nCount);
		}

		// 绘制多边形
		//@参数 points 顶点坐标数组.
		//@参数 nCount 顶点数量.
		//@别名  多边形F()
		void DrawPolygonF(POINTF* points, int nCount) {
			XDraw_DrawPolygonF((HDRAW)m_handle, points, nCount);
		}

		// 填充多边形.  
		//@参数 points 顶点坐标数组.
		//@参数 nCount 顶点数量.
		//@别名  填充多边形()
		void FillPolygon(POINT* points, int nCount) {
			XDraw_FillPolygon((HDRAW)m_handle, points, nCount);
		}

		// 填充多边形
		//@参数 points 顶点坐标数组.
		//@参数 nCount 顶点数量.
		//@别名  填充多边形F()
		void FillPolygonF(POINTF* points, int nCount) {
			XDraw_FillPolygonF((HDRAW)m_handle, points, nCount);
		}

		// 绘制图片.  
		//@参数 hImageFrame 图片句柄.
		//@参数 x x坐标.
		//@参数 y y坐标.
		//@别名  图片()
		void Image(HIMAGE hImageFrame, int x, int y) {
			XDraw_Image((HDRAW)m_handle, hImageFrame, x, y);
		}

		// 绘制图片
		//@参数 hImageFrame 图片句柄.
		//@参数 x x坐标.
		//@参数 y y坐标.
		//@别名  图片F()
		void ImageF(HIMAGE hImageFrame, float x, float y) {
			XDraw_ImageF((HDRAW)m_handle, hImageFrame, x, y);
		}

		// 绘制图片
		//@参数 hImageFrame 图片句柄.
		//@参数 x x坐标.
		//@参数 y y坐标.
		//@参数 width 宽度.
		//@参数 height 高度.
		//@别名  图片扩展()
		void ImageEx(HIMAGE hImageFrame, int x, int y, int width, int height) {
			XDraw_ImageEx((HDRAW)m_handle, hImageFrame, x, y, width, height);
		}

		// 绘制图片
		//@参数 hImageFrame 图片句柄.
		//@参数 x x坐标.
		//@参数 y y坐标.
		//@参数 width 宽度.
		//@参数 height 高度.
		//@别名  图片扩展F()
		void ImageExF(HIMAGE hImageFrame, float x, float y, float width, float height) {
			XDraw_ImageExF((HDRAW)m_handle, hImageFrame, x, y, width, height);
		}

		// 绘制图片.  
		//@参数 hImageFrame 图片句柄.
		//@参数 pRect 坐标.
		//@参数 bOnlyBorder 是否只绘制边缘区域.
		//@别名  图片自适应()
		void ImageAdaptive(HIMAGE hImageFrame, RECT* pRect, bool bOnlyBorder = false) {
			XDraw_ImageAdaptive((HDRAW)m_handle, hImageFrame, pRect, bOnlyBorder);
		}

		// 绘制图片
		//@参数 hImageFrame 图片句柄.
		//@参数 pRect 坐标.
		//@参数 bOnlyBorder 是否只绘制边缘区域.
		//@别名  图片自适应F()
		void ImageAdaptiveF(HIMAGE hImageFrame, RECTF* pRect, bool bOnlyBorder = false) {
			XDraw_ImageAdaptiveF((HDRAW)m_handle, hImageFrame, pRect, bOnlyBorder);
		}

		// 绘制图片.  
		//@参数 hImageFrame 图片句柄.
		//@参数 pRect 坐标.
		//@参数 flag 标识, 0:从左上角开始平铺,1:从左下角开始平铺.
		//@别名  图片平铺()
		void ImageTile(HIMAGE hImageFrame, RECT* pRect, int flag = 0) {
			XDraw_ImageTile((HDRAW)m_handle, hImageFrame, pRect, flag);
		}

		// 绘制图片
		//@参数 hImageFrame 图片句柄.
		//@参数 pRect 坐标.
		//@参数 flag 标识, 0:从左上角开始平铺,1:从左下角开始平铺.
		//@别名  图片平铺F()
		void ImageTileF(HIMAGE hImageFrame, RECTF* pRect, int flag = 0) {
			XDraw_ImageTileF((HDRAW)m_handle, hImageFrame, pRect, flag);
		}

		// 绘制图片.  
		//@参数 hImageFrame 图片句柄.
		//@参数 pRect 坐标.
		//@参数 bClip 是否裁剪区域.
		//@别名  图片增强()
		void ImageSuper(HIMAGE hImageFrame, RECT* pRect, bool bClip = false) {
			XDraw_ImageSuper((HDRAW)m_handle, hImageFrame, pRect, bClip);
		}

		// 绘制图片
		//@参数 hImageFrame 图片句柄.
		//@参数 pRect 坐标.
		//@参数 bClip 是否裁剪区域.
		//@别名  图片增强F()
		void ImageSuperF(HIMAGE hImageFrame, RECTF* pRect, bool bClip = false) {
			XDraw_ImageSuperF((HDRAW)m_handle, hImageFrame, pRect, bClip);
		}

		// 绘制图片.  
		//@参数 hImageFrame 图片句柄.
		//@参数 pRcDest 目标坐标.
		//@参数 pRcSrc 源坐标.
		//@别名  图片增强2()
		void ImageSuperEx(HIMAGE hImageFrame, RECT* pRcDest, RECT* pRcSrc) {
			XDraw_ImageSuperEx((HDRAW)m_handle, hImageFrame, pRcDest, pRcSrc);
		}

		// 绘制图片
		//@参数 hImageFrame 图片句柄.
		//@参数 pRcDest 目标坐标.
		//@参数 pRcSrc 源坐标.
		//@别名  图片增强扩展F()
		void ImageSuperExF(HIMAGE hImageFrame, RECTF* pRcDest, RECTF* pRcSrc) {
			XDraw_ImageSuperExF((HDRAW)m_handle, hImageFrame, pRcDest, pRcSrc);
		}

		// 绘制带遮盖的图片. D2D留空  
		//@参数 hImageFrame 图片句柄.
		//@参数 hImageFrameMask 图片句柄,遮盖.
		//@参数 pRect 坐标.
		//@参数 pRectMask 坐标,遮盖.
		//@参数 bClip 是否裁剪区域.
		//@别名  图片增强遮盖()
		void ImageSuperMask(HIMAGE hImageFrame, HIMAGE hImageFrameMask, RECT* pRect, RECT* pRectMask, bool bClip = false) {
			XDraw_ImageSuperMask((HDRAW)m_handle, hImageFrame, hImageFrameMask, pRect, pRectMask, bClip);
		}

		// 绘制带遮盖的图片.D2D留空  
		//@参数 hImageFrame 图片句柄.
		//@参数 hImageFrameMask 图片句柄,遮盖.
		//@参数 x hImageFrame X坐标.
		//@参数 y hImageFrame Y坐标.
		//@参数 x2 hImageFrameMask X坐标.
		//@参数 y2 hImageFrameMask Y坐标.
		//@别名  图片遮盖()
		void ImageMask(HIMAGE hImageFrame, HIMAGE hImageFrameMask, RECT* pRect, int x2, int y2) {
			XDraw_ImageMask((HDRAW)m_handle, hImageFrame, hImageFrameMask, pRect, x2, y2);
		}

		//@参数 pString 字符串.
		//@参数 nCount 字符串长度.
		//@参数 pRect 坐标.
		//@别名  文本指定矩形()
		void DrawText(const std::wstring& text, RECT* pRect) {
			XDraw_DrawText((HDRAW)m_handle, text.c_str(), text.size(), pRect);
		}

		//@参数 pString 字符串.
		//@参数 nCount 字符串长度.
		//@参数 pRect 坐标.
		//@别名  文本指定矩形F()
		void DrawTextF(const std::wstring& text, RECTF* pRect) {
			XDraw_DrawTextF((HDRAW)m_handle, text.c_str(), text.size(), pRect);
		}

		// 参见MSDN.  
		//@参数 pString 字符串.
		//@参数 nCount 字符串长度.
		//@参数 pRect 坐标.
		//@参数 colorLine 下划线颜色.
		//@别名  文本下划线()
		void DrawTextUnderline(const std::wstring& text, RECT* pRect, COLORREF colorLine) {
			XDraw_DrawTextUnderline((HDRAW)m_handle, text.c_str(), text.size(), pRect, colorLine);
		}

		//@参数 pString 字符串.
		//@参数 nCount 字符串长度.
		//@参数 pRect 坐标.
		//@参数 colorLine 下划线颜色.
		//@别名  文本下划线F()
		void DrawTextUnderlineF(const std::wstring& text, RECTF* pRect, COLORREF colorLine) {
			XDraw_DrawTextUnderlineF((HDRAW)m_handle, text.c_str(), text.size(), pRect, colorLine);
		}

		//@参数 xStart XX.
		//@参数 yStart XX.
		//@参数 pString XX.
		//@参数 cbString XX.
		//@别名  文本()
		void TextOut(int xStart, int yStart, const std::wstring& text) {
			XDraw_TextOut((HDRAW)m_handle, xStart, yStart, text.c_str(), text.size());
		}

		//@参数 xStart XX.
		//@参数 yStart XX.
		//@参数 pString XX.
		//@参数 cbString XX.
		//@别名  文本F()
		void TextOutF(float xStart, float yStart, const std::wstring& text) {
			XDraw_TextOutF((HDRAW)m_handle, xStart, yStart, text.c_str(), text.size());
		}

		//@参数 xStart XX.
		//@参数 yStart XX.
		//@参数 pString XX.
		//@别名  文本扩展()
		void TextOutEx(int xStart, int yStart, const std::wstring& text) {
			XDraw_TextOutEx((HDRAW)m_handle, xStart, yStart, text.c_str());
		}

		//@参数 xStart XX.
		//@参数 yStart XX.
		//@参数 pString XX.
		//@别名  文本扩展F()
		void TextOutExF(float xStart, float yStart, const std::wstring& text) {
			XDraw_TextOutExF((HDRAW)m_handle, xStart, yStart, text.c_str());
		}

		//@参数 xStart XX.
		//@参数 yStart XX.
		//@参数 pString XX.
		//@别名  文本A()
		void TextOutA(int xStart, int yStart, const std::string& text) {
			XDraw_TextOutA((HDRAW)m_handle, xStart, yStart, text.c_str());
		}

		//@参数 xStart XX.
		//@参数 yStart XX.
		//@参数 pString XX.
		//@别名  文本AF()
		void TextOutAF(float xStart, float yStart, const std::string& text) {
			XDraw_TextOutAF((HDRAW)m_handle, xStart, yStart, text.c_str());
		}

		//@参数 hSvg SVG句柄
		//@别名  SVG源()
		void DrawSvgSrc(HSVG hSvg) {
			XDraw_DrawSvgSrc((HDRAW)m_handle, hSvg);
		}

		//@参数 hSvg SVG句柄
		//@参数 x x坐标
		//@参数 y y坐标
		//@别名  SVG()
		void DrawSvg(HSVG hSvg, int x, int y) {
			XDraw_DrawSvg((HDRAW)m_handle, hSvg, x, y);
		}

		//@参数 hSvg SVG句柄
		//@参数 x x坐标
		//@参数 y y坐标
		//@参数 nWidth 宽度
		//@参数 nHeight 高度
		//@别名  SVG扩展()
		void DrawSvgEx(HSVG hSvg, int x, int y, int nWidth, int nHeight) {
			XDraw_DrawSvgEx((HDRAW)m_handle, hSvg, x, y, nWidth, nHeight);
		}

		//@参数 hSvg SVG句柄
		//@参数 nWidth 宽度
		//@参数 nHeight 高度
		//@别名  SVG大小()
		void DrawSvgSize(HSVG hSvg, int nWidth, int nHeight) {
			XDraw_DrawSvgSize((HDRAW)m_handle, hSvg, nWidth, nHeight);
		}

	};

}
