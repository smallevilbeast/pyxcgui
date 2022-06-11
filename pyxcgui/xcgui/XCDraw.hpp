#pragma once
#include "pch.h"
#include "xcgui/XCObject.hpp"
#include "xcgui/window/XCWindow.hpp"

namespace xcgui {

	class XCDraw : public XCObject
	{
	public:
		XCDraw()
			: XCObject()
		{
		}

		XCDraw(HXCGUI drawHandle)
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

		// ����ͼ�λ���ģ��ʵ��
		HDRAW CreateGDI(HWINDOW hWindow, HDC hdc) {
			m_handle = XDraw_CreateGDI(hWindow, hdc);
			return (HDRAW)m_handle;
		}

		// ����ͼ�λ���ģ��ʵ�����.  
		void Destroy() {
			XDraw_Destroy((HDRAW)m_handle);
		}

		// ��������ƫ����,X����ƫ��Ϊ����,����ƫ��Ϊ����.  
		void SetOffset(int x, int y) {
			XDraw_SetOffset((HDRAW)m_handle, x, y);
		}

		// ��ȡ����ƫ����,X����ƫ��Ϊ����,����ƫ��Ϊ����.  
		void GetOffset(int* pX, int* pY) {
			XDraw_GetOffset((HDRAW)m_handle, pX, pY);
		}

		// ��ԭ״̬,�ͷ��û��󶨵�GDI����,���续ˢ,����
		void GDI_RestoreGDIOBJ() {
			XDraw_GDI_RestoreGDIOBJ((HDRAW)m_handle);
		}

		// GDI_�ñ���ģʽ
		int GDI_SetBkMode(bool bTransparent) {
			return XDraw_GDI_SetBkMode((HDRAW)m_handle, bTransparent);
		}

		// ѡ��һ��������Ϊ��ǰ�ü�����,ע��:�ú���ֻ��GDI��Ч
		//@���� hRgn ������.
		//@���� ����ֵָ�������ĸ����ԣ�����������ֵ֮һ.\n
		//@����  GDI_ѡ��ü�����()
		int GDI_SelectClipRgn(HRGN hRgn) {
			return XDraw_GDI_SelectClipRgn((HDRAW)m_handle, hRgn);
		}

		// GDI��������ָ���Ĵ�ɫ�߼�ˢ
		//@���� crColor ��ˢ��ɫ.
		//@���� ��������ɹ�,����ֵ��ʶһ���߼�ˢ,�������ʧ��,����ֵ��NULL.
		//@����  GDI_����ʵ�Ļ�ˢ()
		HBRUSH GDI_CreateSolidBrush(COLORREF crColor) {
			return XDraw_GDI_CreateSolidBrush((HDRAW)m_handle, crColor);
		}

		// GDI����һ���߼���,ָ������ʽ,��Ⱥ���ɫ,���ıʿ���ѡ���豸������,���ڻ�������������
		//@���� fnPenStyle ������ʽ, PS_SOLID:ʵ�� PS_DASH:���� PS_DOT:����  PS_DASHDOT:����_���� PS_DASHDOTDOT:����_��_�� PS_NULL:��  PS_INSIDEFRAME:ʵ��_�ʿ���������չ
		//@���� width ���ʿ��
		//@���� crColor ��ɫ
		//@���� ��������ɹ�,����ֵ��һ�����,��ʶһ���߼���,�������ʧ��,����ֵ��NULL.
		//@����  GDI_��������()
		HPEN GDI_CreatePen(int fnPenStyle, int width, COLORREF crColor) {
			return XDraw_GDI_CreatePen((HDRAW)m_handle, fnPenStyle, width, crColor);
		}


		// GDI������������
		//@���� nLeftRect ���Ͻ�X����.
		//@���� nTopRect ���Ͻ�Y����.
		//@���� nRightRect ���½�X����.
		//@���� nBottomRect ���½�Y����.
		//@���� �ɹ�����������,ʧ�ܷ���NULL.
		//@����  GDI_������������()
		HRGN GDI_CreateRectRgn(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect) {
			return XDraw_GDI_CreateRectRgn((HDRAW)m_handle, nLeftRect, nTopRect, nRightRect, nBottomRect);
		}


		// GDI����һ��Բ�ǵľ�������
		//@���� nLeftRect X-��������Ͻ�.
		//@���� nTopRect Y-�������Ͻ�����
		//@���� nRightRect X-�������½�
		//@���� nBottomRect Y-�������½�
		//@���� nWidthEllipse ��Բ�Ŀ��.
		//@���� nHeightEllipse ��Բ�ĸ߶�.
		//@���� ��������ɹ�,����ֵ�Ǹ�����ľ��,�������ʧ��,����ֵ��NULL.
		//@����  GDI_����Բ�Ǿ�������()
		HRGN GDI_CreateRoundRectRgn(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, int nWidthEllipse, int nHeightEllipse) {
			return XDraw_GDI_CreateRoundRectRgn((HDRAW)m_handle, nLeftRect, nTopRect, nRightRect, nBottomRect, nWidthEllipse, nHeightEllipse);
		}

		// GDI����һ�����������
		//@���� pPt POINT����.
		//@���� cPoints �����С.
		//@���� fnPolyFillMode ��������ģʽ,ָ������ȷ���ڸõ������������ģʽ,�����������������ֵ֮һ.\n
		//@���� ��������ɹ�,����ֵ�Ǹ�����ľ��,�������ʧ��,����ֵ��NULL.
		//@����  GDI_�������������()
		HRGN GDI_CreatePolygonRgn(POINT* pPt, int cPoints, int fnPolyFillMode) {
			return XDraw_GDI_CreatePolygonRgn((HDRAW)m_handle, pPt, cPoints, fnPolyFillMode);
		}

		// ���ƾ���,ʹ�õ�ǰ�Ļ�ˢ�ͻ���
		//@���� nLeftRect ���Ͻ�X����.
		//@���� nTopRect ���Ͻ�Y����.
		//@���� nRightRect ���½�X����.
		//@���� nBottomRect ���½�Y����.
		//@���� ��������ɹ�,���ط���ֵ,�������ʧ��,����ֵ����.
		//@����  GDI_����()
		bool GDI_Rectangle(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect) {
			return XDraw_GDI_Rectangle((HDRAW)m_handle, nLeftRect, nTopRect, nRightRect, nBottomRect);
		}

		// ͨ��ʹ��ָ���Ļ�ˢ���һ������
		//@���� hrgn ������.
		//@���� hbr ��ˢ���.
		//@���� ��������ɹ�,���ط���ֵ,�������ʧ��,����ֵ����.
		//@����  GID_�������()
		bool GDI_FillRgn(HRGN hrgn, HBRUSH hbr) {
			return XDraw_GDI_FillRgn((HDRAW)m_handle, hrgn, hbr);
		}

		//@���� pRect ��������
		//@���� ����ɹ�����TRUE,���򷵻�FALSE
		//@����  GDI_��Բ()
		bool GDI_Ellipse(RECT* pRect) {
			return XDraw_GDI_Ellipse((HDRAW)m_handle, pRect);
		}

		// ���Ʊ߿�,ʹ��ָ���Ļ�ˢ����ָ��������ı߿�
		//@���� hrgn ������.
		//@���� hbr ��ˢ���.
		//@���� width �߿���,��ֱ��.
		//@���� height �߿�߶�,ˮƽ��.
		//@���� ��������ɹ�,���ط���ֵ,�������ʧ��,����ֵ����.
		//@����  GDI_�߿�����()
		bool GDI_FrameRgn(HRGN hrgn, HBRUSH hbr, int width, int nHeight) {
			return XDraw_GDI_FrameRgn((HDRAW)m_handle, hrgn, hbr, width, nHeight);
		}

		// ���µ�ǰλ�õ�ָ���㣬��������ǰ��λ��
		//@���� X ����.
		//@���� Y ����.
		//@���� pPoint ������ǰ�ĵ�ǰλ�õ�һ��POINT�ṹ��ָ��,������������NULLָ��,û�з���ԭ����λ��.
		//@���� ��������ɹ�,���ط���ֵ,�������ʧ��,����ֵ����.
		//@����  GDI_�ƶ������()
		bool GDI_MoveToEx(int X, int Y, POINT* pPoint = NULL) {
			return XDraw_GDI_MoveToEx((HDRAW)m_handle, X, Y, pPoint);
		}

		// ��������һ���ߴӵ�ǰλ�õ�,��������ָ����
		//@���� nXEnd X����,�߽�����.
		//@���� nYEnd Y����,�߽�����.
		//@���� ��������ɹ�,���ط���ֵ,�������ʧ��,����ֵ����.
		//@����  GDI_���յ�()
		bool GDI_LineTo(int nXEnd, int nYEnd) {
			return XDraw_GDI_LineTo((HDRAW)m_handle, nXEnd, nYEnd);
		}

		// Polyline() �μ�MSDN
		//@���� pArrayPt �μ�MSDN.
		//@���� arrayPtSize �μ�MSDN.
		//@���� �μ�MSDN.
		//@����  GDI_����()
		bool GDI_Polyline(POINT* pArrayPt, int arrayPtSize) {
			return XDraw_GDI_Polyline((HDRAW)m_handle, pArrayPt, arrayPtSize);
		}

		// ����ͼ��,DrawIconEx()�μ�MSDN
		//@���� xLeft .
		//@���� yTop .
		//@���� hIcon .
		//@���� cxWidth .
		//@���� cyWidth .
		//@���� istepIfAniCur .
		//@���� hbrFlickerFreeDraw .
		//@���� diFlags .
		//@���� .
		//@����  GDI_ͼ����չ()
		bool GDI_DrawIconEx(int xLeft, int yTop, HICON hIcon, int cxWidth, int cyWidth, UINT istepIfAniCur, HBRUSH hbrFlickerFreeDraw, UINT diFlags) {
			return XDraw_GDI_DrawIconEx((HDRAW)m_handle, xLeft, yTop, hIcon, cxWidth, cyWidth, istepIfAniCur, hbrFlickerFreeDraw, diFlags);
		}

		// BitBlt() �μ�MSDN
		//@���� nXDest XX.
		//@���� nYDest XX.
		//@���� width XX.
		//@���� height XX.
		//@���� hdcSrc XX.
		//@���� nXSrc XX.
		//@���� nYSrc XX.
		//@���� dwRop XX.
		//@���� .
		//@����  GDI_����()
		bool GDI_BitBlt(int nXDest, int nYDest, int width, int nHeight, HDC hdcSrc, int nXSrc, int nYSrc, DWORD dwRop) {
			return XDraw_GDI_BitBlt((HDRAW)m_handle, nXDest, nYDest, width, nHeight, hdcSrc, nXSrc, nYSrc, dwRop);
		}

		// BitBlt() �μ�MSDN
		//@���� nXDest XX.
		//@���� nYDest XX.
		//@���� width XX.
		//@���� height XX.
		//@���� hDrawSrc XX.
		//@���� nXSrc XX.
		//@���� nYSrc XX.
		//@���� dwRop XX.
		//@���� .
		//@����  GDI_����2()
		bool GDI_BitBlt2(int nXDest, int nYDest, int width, int nHeight, HDRAW hDrawSrc, int nXSrc, int nYSrc, DWORD dwRop) {
			return XDraw_GDI_BitBlt2((HDRAW)m_handle, nXDest, nYDest, width, nHeight, hDrawSrc, nXSrc, nYSrc, dwRop);
		}

		// AlphaBlend() �μ�MSDN
		//@���� nXOriginDest XX.
		//@���� nYOriginDest XX.
		//@���� nWidthDest XX.
		//@���� nHeightDest XX.
		//@���� hdcSrc XX.
		//@���� nXOriginSrc XX.
		//@���� nYOriginSrc XX.
		//@���� nWidthSrc XX.
		//@���� nHeightSrc XX.
		//@���� alpha XX.
		//@���� �ɹ�����TRUE���򷵻�FALSE.
		//@����  GDI_��͸������()
		bool GDI_AlphaBlend(int nXOriginDest, int nYOriginDest, int nWidthDest, int nHeightDest, HDC hdcSrc, int nXOriginSrc, int nYOriginSrc, int nWidthSrc, int nHeightSrc, int alpha) {
			return XDraw_GDI_AlphaBlend((HDRAW)m_handle, nXOriginDest, nYOriginDest, nWidthDest, nHeightDest, hdcSrc, nXOriginSrc, nYOriginSrc, nWidthSrc, nHeightSrc, alpha);
		}

		// ����������ָ�������굽ָ������ɫ������
		//@���� X ����
		//@���� Y ����
		//@���� crColor ��ɫֵ, ��ʹ�ú�: RGBA()
		//@���� ��������ɹ�����RGBֵ,���ʧ�ܷ���-1.
		//@����  GDI_��������ɫ()
		COLORREF GDI_SetPixel(int X, int Y, COLORREF crColor) {
			return XDraw_GDI_SetPixel((HDRAW)m_handle, X, Y, crColor);
		}

		// ��ȡ�󶨵��豸������HDC.  
		//@���� ����HDC���. 
		//@����  ȡHDC()
		HDC GetHDC() {
			return XDraw_GetHDC((HDRAW)m_handle);
		}

		//@���� ���� ID2D1RenderTarget*
		//@����  ȡD2D��ȾĿ��()
		vint GetD2dRenderTarget() {
			return XDraw_GetD2dRenderTarget((HDRAW)m_handle);
		}

		//@���� mode ��Ⱦģʽ  @ref XC_DWRITE_RENDERING_MODE
		//@����  ��D2D�ı���Ⱦģʽ()
		void SetD2dTextRenderingMode(XC_DWRITE_RENDERING_MODE mode) {
			XDraw_SetD2dTextRenderingMode((HDRAW)m_handle, mode);
		}

		// �����ı���Ⱦ����GDI+
		//@���� nType �μ�GDI+ TextRenderingHint ����.
		//@����  ���ı��Ų�����()
		void SetTextRenderingHint(int nType) {
			XDraw_SetTextRenderingHint((HDRAW)m_handle, nType);
		}

		// ʹ��ָ����ɫ������
		//@���� color ��ɫֵ, ��ʹ�ú�: RGBA()
		//@����  D2D_����()
		void D2D_Clear(COLORREF color) {
			XDraw_D2D_Clear((HDRAW)m_handle, color);
		}

		// ���û�ˢ��ɫ.  
		//@���� color ��ɫֵ, ��ʹ�ú�: RGBA()
		//@����  �û�ˢ��ɫ()
		void SetBrushColor(COLORREF color) {
			XDraw_SetBrushColor((HDRAW)m_handle, color);
		}

		// �����ı���ֱ��ʾ.  
		//@���� bVertical �Ƿ�ֱ��ʾ�ı�.
		//@����  ���ı���ֱ()
		void SetTextVertical(bool bVertical) {
			XDraw_SetTextVertical((HDRAW)m_handle, bVertical);
		}

		// �����ı�����.  
		//@���� nFlags �����ʶ @ref textFormatFlag_ .
		//@����  ���ı�����()
		void SetTextAlign(int nFlag) {
			XDraw_SetTextAlign((HDRAW)m_handle, nFlag);
		}

		// ��������.  
		//@���� hFontx �Ų�����.
		//@����  ������()
		void SetFont(HFONTX hFontx) {
			XDraw_SetFont((HDRAW)m_handle, hFontx);
		}

		// �����߿�.  
		//@���� width ���.
		//@����  ���߿�()
		void SetLineWidth(int width) {
			XDraw_SetLineWidth((HDRAW)m_handle, width);
		}

		// �����߿�
		//@���� width ���.
		//@����  ���߿�F()
		void SetLineWidthF(float width) {
			XDraw_SetLineWidthF((HDRAW)m_handle, width);
		}

		// ���òü�����.  
		//@���� pRect ��������.
		//@����  �òü�����()
		void SetClipRect(RECT* pRect) {
			XDraw_SetClipRect((HDRAW)m_handle, pRect);
		}

		// ����ü�����.  
		//@����  ����ü�����()
		void ClearClip() {
			XDraw_ClearClip((HDRAW)m_handle);
		}

		// ����ƽ��ģʽ.  
		//@���� bEnable �Ƿ�����.
		//@����  ����ƽ��ģʽ()
		void EnableSmoothingMode(bool bEnable) {
			XDraw_EnableSmoothingMode((HDRAW)m_handle, bEnable);
		}

		// ������֮��,����GDI+����ʱ, �������alpha=255,���Զ��޸�Ϊ254, Ӧ��GDI+��bug, ����͸��ͨ���쳣
		//@���� bTransparent �Ƿ�����
		//@����  ���ô���͸���ж�()
		void EnableWndTransparent(bool bTransparent) {
			XDraw_EnableWndTransparent((HDRAW)m_handle, bTransparent);
		}

		//@���� pRect ��������.
		//@����  ������()
		void FillRect(RECT* pRect) {
			XDraw_FillRect((HDRAW)m_handle, pRect);
		}

		//@���� pRect ��������
		//@����  ������F()
		void FillRectF(RECTF* pRect) {
			XDraw_FillRectF((HDRAW)m_handle, pRect);
		}

		//@���� pRect ��������.
		//@���� color ��ɫ.
		//@����  ������ָ����ɫ()
		void FillRectColor(RECT* pRect, COLORREF color) {
			XDraw_FillRectColor((HDRAW)m_handle, pRect, color);
		}

		//@���� pRect ��������.
		//@���� color ��ɫ.
		//@����  ������ָ����ɫF()
		void FillRectColorF(RECTF* pRect, COLORREF color) {
			XDraw_FillRectColorF((HDRAW)m_handle, pRect, color);
		}

		//@���� pRect ��������
		//@����  �����Բ()
		void FillEllipse(RECT* pRect) {
			XDraw_FillEllipse((HDRAW)m_handle, pRect);
		}

		//@���� pRect ��������
		//@����  �����ԲF()
		void FillEllipseF(RECTF* pRect) {
			XDraw_FillEllipseF((HDRAW)m_handle, pRect);
		}

		// ������Բ�߿�
		//@���� pRect ��������.
		//@����  ��Բ()
		void DrawEllipse(RECT* pRect) {
			XDraw_DrawEllipse((HDRAW)m_handle, pRect);
		}

		// ������Բ�߿�
		//@���� pRect ��������.
		//@����  ��ԲF()
		void DrawEllipseF(RECTF* pRect) {
			XDraw_DrawEllipseF((HDRAW)m_handle, pRect);
		}

		// ���Բ�Ǿ���
		//@���� pRect ��������.
		//@���� width Բ�ǿ��.
		//@���� height Բ�Ǹ߶�.
		//@����  ���Բ�Ǿ���()
		void FillRoundRect(RECT* pRect, int width, int nHeight) {
			XDraw_FillRoundRect((HDRAW)m_handle, pRect, width, nHeight);
		}

		// ���Բ�Ǿ���
		//@���� pRect ��������.
		//@���� width Բ�ǿ��.
		//@���� height Բ�Ǹ߶�.
		//@����  ���Բ�Ǿ���F()
		void FillRoundRectF(RECTF* pRect, float width, float height) {
			XDraw_FillRoundRectF((HDRAW)m_handle, pRect, width, height);
		}

		// ����Բ�Ǿ��α߿�.  
		//@���� pRect ��������.
		//@���� width Բ�ǿ��.
		//@���� height Բ�Ǹ߶�.
		//@����  Բ�Ǿ���()
		void DrawRoundRect(RECT* pRect, int width, int nHeight) {
			XDraw_DrawRoundRect((HDRAW)m_handle, pRect, width, nHeight);
		}

		// ����Բ�Ǿ��α߿�
		//@���� pRect ��������.
		//@���� width Բ�ǿ��.
		//@���� height Բ�Ǹ߶�.
		//@����  Բ�Ǿ���F()
		void DrawRoundRectF(RECTF* pRect, float width, float height) {
			XDraw_DrawRoundRectF((HDRAW)m_handle, pRect, width, height);
		}

		// ���Բ�Ǿ���.  
		//@���� pRect ����.
		//@���� leftTop Բ�Ǵ�С.
		//@���� rightTop Բ�Ǵ�С.
		//@���� rightBottom Բ�Ǵ�С.
		//@���� leftBottom Բ�Ǵ�С.
		//@����  ���Բ�Ǿ�����չ()
		void FillRoundRectEx(RECT* pRect, int leftTop, int rightTop, int rightBottom, int leftBottom) {
			XDraw_FillRoundRectEx((HDRAW)m_handle, pRect, leftTop, rightTop, rightBottom, leftBottom);
		}

		// ���Բ�Ǿ���
		//@���� pRect ����.
		//@���� leftTop Բ�Ǵ�С.
		//@���� rightTop Բ�Ǵ�С.
		//@���� rightBottom Բ�Ǵ�С.
		//@���� leftBottom Բ�Ǵ�С.
		//@����  ���Բ�Ǿ�����չF()
		void FillRoundRectExF(RECTF* pRect, float leftTop, float rightTop, float rightBottom, float leftBottom) {
			XDraw_FillRoundRectExF((HDRAW)m_handle, pRect, leftTop, rightTop, rightBottom, leftBottom);
		}

		// ����Բ�Ǿ��α߿�  
		//@���� pRect ����.
		//@���� leftTop Բ�Ǵ�С.
		//@���� rightTop Բ�Ǵ�С.
		//@���� rightBottom Բ�Ǵ�С.
		//@���� leftBottom Բ�Ǵ�С.
		//@����  Բ�Ǿ�����չ()
		void DrawRoundRectEx(RECT* pRect, int leftTop, int rightTop, int rightBottom, int leftBottom) {
			XDraw_DrawRoundRectEx((HDRAW)m_handle, pRect, leftTop, rightTop, rightBottom, leftBottom);
		}

		// ����Բ�Ǿ��α߿�
		//@���� pRect ����.
		//@���� leftTop Բ�Ǵ�С.
		//@���� rightTop Բ�Ǵ�С.
		//@���� rightBottom Բ�Ǵ�С.
		//@���� leftBottom Բ�Ǵ�С.
		//@����  Բ�Ǿ�����չF()
		void DrawRoundRectExF(RECTF* pRect, float leftTop, float rightTop, float rightBottom, float leftBottom) {
			XDraw_DrawRoundRectExF((HDRAW)m_handle, pRect, leftTop, rightTop, rightBottom, leftBottom);
		}

		// �������,��һ����ɫ���ɵ���һ����ɫ.  
		//@���� pRect ��������.
		//@���� color1 ��ʼ��ɫ.
		//@���� color2 ������ɫ.
		//@���� mode ģʽ.
		//@����  �������2()
		void GradientFill2(RECT* pRect, COLORREF color1, COLORREF color2, int mode) {
			XDraw_GradientFill2((HDRAW)m_handle, pRect, color1, color2, mode);
		}

		// �������,��һ����ɫ���ɵ���һ����ɫ
		//@���� pRect ��������.
		//@���� color1 ��ʼ��ɫ.
		//@���� color2 ������ɫ.
		//@���� mode ģʽ.
		//@����  �������2F()
		void GradientFill2F(RECTF* pRect, COLORREF color1, COLORREF color2, int mode) {
			XDraw_GradientFill2F((HDRAW)m_handle, pRect, color1, color2, mode);
		}

		// �������,��һ����ɫ���ɵ���һ����ɫ.  
		//@���� pRect ��������.
		//@���� color1 ��ʼ��ɫ.
		//@���� color2 ������ɫ,�м�.
		//@���� color3 ��ʼ��ɫ,�м�.
		//@���� color4 ������ɫ.
		//@���� mode ģʽ.
		//@����  �������4()
		void GradientFill4(RECT* pRect, COLORREF color1, COLORREF color2, COLORREF color3, COLORREF color4, int mode) {
			XDraw_GradientFill4((HDRAW)m_handle, pRect, color1, color2, color3, color4, mode);
		}

		// �������,��һ����ɫ���ɵ���һ����ɫ
		//@���� pRect ��������.
		//@���� color1 ��ʼ��ɫ.
		//@���� color2 ������ɫ,�м�.
		//@���� color3 ��ʼ��ɫ,�м�.
		//@���� color4 ������ɫ.
		//@���� mode ģʽ.
		//@����  �������4F()
		void GradientFill4F(RECTF* pRect, COLORREF color1, COLORREF color2, COLORREF color3, COLORREF color4, int mode) {
			XDraw_GradientFill4F((HDRAW)m_handle, pRect, color1, color2, color3, color4, mode);
		}

		// ���ƾ��α߿�  
		//@���� pRect ��������
		//@����  ����()
		void DrawRect(RECT* pRect) {
			XDraw_DrawRect((HDRAW)m_handle, pRect);
		}

		// ���ƾ��α߿�
		//@���� pRect ��������
		//@����  ����F()
		void DrawRectF(RECTF* pRect) {
			XDraw_DrawRectF((HDRAW)m_handle, pRect);
		}

		// ��������.  
		//@���� x1 ����.
		//@���� y1 ����.
		//@���� x2 ����.
		//@���� y2 ����.
		//@����  ����()
		void DrawLine(int x1, int y1, int x2, int y2) {
			XDraw_DrawLine((HDRAW)m_handle, x1, y1, x2, y2);
		}

		// ��������
		//@���� x1 ����.
		//@���� y1 ����.
		//@���� x2 ����.
		//@���� y2 ����.
		//@����  ����F()
		void DrawLineF(float x1, float y1, float x2, float y2) {
			XDraw_DrawLineF((HDRAW)m_handle, x1, y1, x2, y2);
		}

		// D2D��ʱ����
		//@���� points ���������
		//@���� count �����С
		//@���� tension ���ڻ����0.0F��ֵ��ָ�����ߵ�������D2D ���Դ˲���
		//@����  ����()
		void DrawCurve(POINT* points, int count, float tension) {
			XDraw_DrawCurve((HDRAW)m_handle, points, count, tension);
		}

		// D2D��ʱ����
		//@���� points ���������
		//@���� count �����С
		//@���� tension ���ڻ����0.0F��ֵ��ָ�����ߵ�������D2D ���Դ˲���
		//@����  ����F()
		void DrawCurveF(POINTF* points, int count, float tension) {
			XDraw_DrawCurveF((HDRAW)m_handle, points, count, tension);
		}

		//@���� x ����
		//@���� y ����
		//@���� width ���
		//@���� height �߶�
		//@���� startAngle ��ʼ�Ƕ�
		//@���� sweepAngle ���ƽǶ�, ����ʼ�Ƕȿ�ʼ����
		//@����  Բ��()
		void DrawArc(int x, int y, int width, int nHeight, float startAngle, float sweepAngle) {
			XDraw_DrawArc((HDRAW)m_handle, x, y, width, nHeight, startAngle, sweepAngle);
		}

		//@���� x ����
		//@���� y ����
		//@���� width ���
		//@���� height �߶�
		//@���� startAngle ��ʼ�Ƕ�
		//@���� sweepAngle ���ƽǶ�, ����ʼ�Ƕȿ�ʼ����
		//@����  Բ��F()
		void DrawArcF(float x, float y, float width, float height, float startAngle, float sweepAngle) {
			XDraw_DrawArcF((HDRAW)m_handle, x, y, width, height, startAngle, sweepAngle);
		}

		// ���ƽ������.  
		//@���� pRect ��������.
		//@����  �������()
		void FocusRect(RECT* pRect) {
			XDraw_FocusRect((HDRAW)m_handle, pRect);
		}

		// ���ƽ������
		//@���� pRect ��������.
		//@����  �������F()
		void FocusRectF(RECTF* pRect) {
			XDraw_FocusRectF((HDRAW)m_handle, pRect);
		}

		// ����ˮƽ��ֱ����.  
		//@���� x1 ���x����.
		//@���� y1 ���y����.
		//@���� x2 ������x����.
		//@���� y2 ������y����.
		//@����  ����()
		void Dottedline(int x1, int y1, int x2, int y2) {
			XDraw_Dottedline((HDRAW)m_handle, x1, y1, x2, y2);
		}

		// ����ˮƽ��ֱ����
		//@���� x1 ���x����.
		//@���� y1 ���y����.
		//@���� x2 ������x����.
		//@���� y2 ������y����.
		//@����  ����F()
		void DottedlineF(float x1, float y1, float x2, float y2) {
			XDraw_DottedlineF((HDRAW)m_handle, x1, y1, x2, y2);
		}

		// ���ƶ����.  
		//@���� points ������������.
		//@���� nCount ��������.
		//@����  �����()
		void DrawPolygon(POINT* points, int nCount) {
			XDraw_DrawPolygon((HDRAW)m_handle, points, nCount);
		}

		// ���ƶ����
		//@���� points ������������.
		//@���� nCount ��������.
		//@����  �����F()
		void DrawPolygonF(POINTF* points, int nCount) {
			XDraw_DrawPolygonF((HDRAW)m_handle, points, nCount);
		}

		// �������.  
		//@���� points ������������.
		//@���� nCount ��������.
		//@����  �������()
		void FillPolygon(POINT* points, int nCount) {
			XDraw_FillPolygon((HDRAW)m_handle, points, nCount);
		}

		// �������
		//@���� points ������������.
		//@���� nCount ��������.
		//@����  �������F()
		void FillPolygonF(POINTF* points, int nCount) {
			XDraw_FillPolygonF((HDRAW)m_handle, points, nCount);
		}

		// ����ͼƬ.  
		//@���� hImageFrame ͼƬ���.
		//@���� x x����.
		//@���� y y����.
		//@����  ͼƬ()
		void Image(HIMAGE hImageFrame, int x, int y) {
			XDraw_Image((HDRAW)m_handle, hImageFrame, x, y);
		}

		// ����ͼƬ
		//@���� hImageFrame ͼƬ���.
		//@���� x x����.
		//@���� y y����.
		//@����  ͼƬF()
		void ImageF(HIMAGE hImageFrame, float x, float y) {
			XDraw_ImageF((HDRAW)m_handle, hImageFrame, x, y);
		}

		// ����ͼƬ
		//@���� hImageFrame ͼƬ���.
		//@���� x x����.
		//@���� y y����.
		//@���� width ���.
		//@���� height �߶�.
		//@����  ͼƬ��չ()
		void ImageEx(HIMAGE hImageFrame, int x, int y, int width, int height) {
			XDraw_ImageEx((HDRAW)m_handle, hImageFrame, x, y, width, height);
		}

		// ����ͼƬ
		//@���� hImageFrame ͼƬ���.
		//@���� x x����.
		//@���� y y����.
		//@���� width ���.
		//@���� height �߶�.
		//@����  ͼƬ��չF()
		void ImageExF(HIMAGE hImageFrame, float x, float y, float width, float height) {
			XDraw_ImageExF((HDRAW)m_handle, hImageFrame, x, y, width, height);
		}

		// ����ͼƬ.  
		//@���� hImageFrame ͼƬ���.
		//@���� pRect ����.
		//@���� bOnlyBorder �Ƿ�ֻ���Ʊ�Ե����.
		//@����  ͼƬ����Ӧ()
		void ImageAdaptive(HIMAGE hImageFrame, RECT* pRect, bool bOnlyBorder = false) {
			XDraw_ImageAdaptive((HDRAW)m_handle, hImageFrame, pRect, bOnlyBorder);
		}

		// ����ͼƬ
		//@���� hImageFrame ͼƬ���.
		//@���� pRect ����.
		//@���� bOnlyBorder �Ƿ�ֻ���Ʊ�Ե����.
		//@����  ͼƬ����ӦF()
		void ImageAdaptiveF(HIMAGE hImageFrame, RECTF* pRect, bool bOnlyBorder = false) {
			XDraw_ImageAdaptiveF((HDRAW)m_handle, hImageFrame, pRect, bOnlyBorder);
		}

		// ����ͼƬ.  
		//@���� hImageFrame ͼƬ���.
		//@���� pRect ����.
		//@���� flag ��ʶ, 0:�����Ͻǿ�ʼƽ��,1:�����½ǿ�ʼƽ��.
		//@����  ͼƬƽ��()
		void ImageTile(HIMAGE hImageFrame, RECT* pRect, int flag = 0) {
			XDraw_ImageTile((HDRAW)m_handle, hImageFrame, pRect, flag);
		}

		// ����ͼƬ
		//@���� hImageFrame ͼƬ���.
		//@���� pRect ����.
		//@���� flag ��ʶ, 0:�����Ͻǿ�ʼƽ��,1:�����½ǿ�ʼƽ��.
		//@����  ͼƬƽ��F()
		void ImageTileF(HIMAGE hImageFrame, RECTF* pRect, int flag = 0) {
			XDraw_ImageTileF((HDRAW)m_handle, hImageFrame, pRect, flag);
		}

		// ����ͼƬ.  
		//@���� hImageFrame ͼƬ���.
		//@���� pRect ����.
		//@���� bClip �Ƿ�ü�����.
		//@����  ͼƬ��ǿ()
		void ImageSuper(HIMAGE hImageFrame, RECT* pRect, bool bClip = false) {
			XDraw_ImageSuper((HDRAW)m_handle, hImageFrame, pRect, bClip);
		}

		// ����ͼƬ
		//@���� hImageFrame ͼƬ���.
		//@���� pRect ����.
		//@���� bClip �Ƿ�ü�����.
		//@����  ͼƬ��ǿF()
		void ImageSuperF(HIMAGE hImageFrame, RECTF* pRect, bool bClip = false) {
			XDraw_ImageSuperF((HDRAW)m_handle, hImageFrame, pRect, bClip);
		}

		// ����ͼƬ.  
		//@���� hImageFrame ͼƬ���.
		//@���� pRcDest Ŀ������.
		//@���� pRcSrc Դ����.
		//@����  ͼƬ��ǿ2()
		void ImageSuperEx(HIMAGE hImageFrame, RECT* pRcDest, RECT* pRcSrc) {
			XDraw_ImageSuperEx((HDRAW)m_handle, hImageFrame, pRcDest, pRcSrc);
		}

		// ����ͼƬ
		//@���� hImageFrame ͼƬ���.
		//@���� pRcDest Ŀ������.
		//@���� pRcSrc Դ����.
		//@����  ͼƬ��ǿ��չF()
		void ImageSuperExF(HIMAGE hImageFrame, RECTF* pRcDest, RECTF* pRcSrc) {
			XDraw_ImageSuperExF((HDRAW)m_handle, hImageFrame, pRcDest, pRcSrc);
		}

		// ���ƴ��ڸǵ�ͼƬ. D2D����  
		//@���� hImageFrame ͼƬ���.
		//@���� hImageFrameMask ͼƬ���,�ڸ�.
		//@���� pRect ����.
		//@���� pRectMask ����,�ڸ�.
		//@���� bClip �Ƿ�ü�����.
		//@����  ͼƬ��ǿ�ڸ�()
		void ImageSuperMask(HIMAGE hImageFrame, HIMAGE hImageFrameMask, RECT* pRect, RECT* pRectMask, bool bClip = false) {
			XDraw_ImageSuperMask((HDRAW)m_handle, hImageFrame, hImageFrameMask, pRect, pRectMask, bClip);
		}

		// ���ƴ��ڸǵ�ͼƬ.D2D����  
		//@���� hImageFrame ͼƬ���.
		//@���� hImageFrameMask ͼƬ���,�ڸ�.
		//@���� x hImageFrame X����.
		//@���� y hImageFrame Y����.
		//@���� x2 hImageFrameMask X����.
		//@���� y2 hImageFrameMask Y����.
		//@����  ͼƬ�ڸ�()
		void ImageMask(HIMAGE hImageFrame, HIMAGE hImageFrameMask, RECT* pRect, int x2, int y2) {
			XDraw_ImageMask((HDRAW)m_handle, hImageFrame, hImageFrameMask, pRect, x2, y2);
		}

		//@���� pString �ַ���.
		//@���� nCount �ַ�������.
		//@���� pRect ����.
		//@����  �ı�ָ������()
		void DrawText(const std::wstring& text, RECT* pRect) {
			XDraw_DrawText((HDRAW)m_handle, text.c_str(), text.size(), pRect);
		}

		//@���� pString �ַ���.
		//@���� nCount �ַ�������.
		//@���� pRect ����.
		//@����  �ı�ָ������F()
		void DrawTextF(const std::wstring& text, RECTF* pRect) {
			XDraw_DrawTextF((HDRAW)m_handle, text.c_str(), text.size(), pRect);
		}

		// �μ�MSDN.  
		//@���� pString �ַ���.
		//@���� nCount �ַ�������.
		//@���� pRect ����.
		//@���� colorLine �»�����ɫ.
		//@����  �ı��»���()
		void DrawTextUnderline(const std::wstring& text, RECT* pRect, COLORREF colorLine) {
			XDraw_DrawTextUnderline((HDRAW)m_handle, text.c_str(), text.size(), pRect, colorLine);
		}

		//@���� pString �ַ���.
		//@���� nCount �ַ�������.
		//@���� pRect ����.
		//@���� colorLine �»�����ɫ.
		//@����  �ı��»���F()
		void DrawTextUnderlineF(const std::wstring& text, RECTF* pRect, COLORREF colorLine) {
			XDraw_DrawTextUnderlineF((HDRAW)m_handle, text.c_str(), text.size(), pRect, colorLine);
		}

		//@���� xStart XX.
		//@���� yStart XX.
		//@���� pString XX.
		//@���� cbString XX.
		//@����  �ı�()
		void TextOut(int xStart, int yStart, const std::wstring& text) {
			XDraw_TextOut((HDRAW)m_handle, xStart, yStart, text.c_str(), text.size());
		}

		//@���� xStart XX.
		//@���� yStart XX.
		//@���� pString XX.
		//@���� cbString XX.
		//@����  �ı�F()
		void TextOutF(float xStart, float yStart, const std::wstring& text) {
			XDraw_TextOutF((HDRAW)m_handle, xStart, yStart, text.c_str(), text.size());
		}

		//@���� xStart XX.
		//@���� yStart XX.
		//@���� pString XX.
		//@����  �ı���չ()
		void TextOutEx(int xStart, int yStart, const std::wstring& text) {
			XDraw_TextOutEx((HDRAW)m_handle, xStart, yStart, text.c_str());
		}

		//@���� xStart XX.
		//@���� yStart XX.
		//@���� pString XX.
		//@����  �ı���չF()
		void TextOutExF(float xStart, float yStart, const std::wstring& text) {
			XDraw_TextOutExF((HDRAW)m_handle, xStart, yStart, text.c_str());
		}

		//@���� xStart XX.
		//@���� yStart XX.
		//@���� pString XX.
		//@����  �ı�A()
		void TextOutA(int xStart, int yStart, const std::string& text) {
			XDraw_TextOutA((HDRAW)m_handle, xStart, yStart, text.c_str());
		}

		//@���� xStart XX.
		//@���� yStart XX.
		//@���� pString XX.
		//@����  �ı�AF()
		void TextOutAF(float xStart, float yStart, const std::string& text) {
			XDraw_TextOutAF((HDRAW)m_handle, xStart, yStart, text.c_str());
		}

		//@���� hSvg SVG���
		//@����  SVGԴ()
		void DrawSvgSrc(HSVG hSvg) {
			XDraw_DrawSvgSrc((HDRAW)m_handle, hSvg);
		}

		//@���� hSvg SVG���
		//@���� x x����
		//@���� y y����
		//@����  SVG()
		void DrawSvg(HSVG hSvg, int x, int y) {
			XDraw_DrawSvg((HDRAW)m_handle, hSvg, x, y);
		}

		//@���� hSvg SVG���
		//@���� x x����
		//@���� y y����
		//@���� nWidth ���
		//@���� nHeight �߶�
		//@����  SVG��չ()
		void DrawSvgEx(HSVG hSvg, int x, int y, int nWidth, int nHeight) {
			XDraw_DrawSvgEx((HDRAW)m_handle, hSvg, x, y, nWidth, nHeight);
		}

		//@���� hSvg SVG���
		//@���� nWidth ���
		//@���� nHeight �߶�
		//@����  SVG��С()
		void DrawSvgSize(HSVG hSvg, int nWidth, int nHeight) {
			XDraw_DrawSvgSize((HDRAW)m_handle, hSvg, nWidth, nHeight);
		}


		// 3.5 ����
		// ʹ�þ�����Ϊ����
		void ImageMaskRect(HIMAGE hImageFrame,RECT* pRect,RECT* pRcMask, RECT* pRcRoundAngle) {
			XDraw_ImageMaskRect((HDRAW)m_handle, hImageFrame, pRect, pRcMask, pRcRoundAngle);
		}

		// ʹ��Բ����Ϊ����
		void ImageMaskEllipse(HIMAGE hImageFrame, RECT* pRect, RECT* pRcMask) {
			XDraw_ImageMaskEllipse((HDRAW)m_handle, hImageFrame, pRect, pRcMask);
		}


	};

}
