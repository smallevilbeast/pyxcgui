#pragma once
#include "pch.h"

namespace xcgui {
	class XCApp
	{
	public:
		XCApp(bool bD2D = false)
		{
			XInitXCGUI(bD2D);
		}

		void Run() 
		{
			XRunXCGUI();
		}

		void Exit() 
		{
			XExitXCGUI();
		}

		// ����ļ�����·��, Ĭ��·ΪexeĿ¼�ͳ���ǰ����Ŀ¼
		void AddFileSearchPath(const std::wstring& path) {
			XC_AddFileSearchPath(path.c_str());
		}

		//  ����������Զ��˳�����,����⵽�����û������Ĵ��ڶ��ر�ʱ,�Զ��˳�����; �ɵ��� XC_PostQuitMessage() �ֶ��˳�����
		void EnableAutoExitApp(bool bEnable) {
			XC_EnableAutoExitApp(bEnable);
		}

		//  ��ӡ������Ϣ���ļ�
		void DebugToFileInfo(const std::string& file) {
			XC_DebugToFileInfo(file.c_str());
		}

		// ����debug�ļ�
		void EnableDebugFile(bool bEnable) {
			XC_EnableDebugFile(bEnable);
		}
		
		// ���ô��󵯳�,ͨ���ýӿڿ��������������ش���ʱ��������Ϣ��ʾ��.
		void EnableErrorMessageBox(bool bEnable) {
			XC_EnableErrorMessageBox(bEnable);
		}

		// ����GDI�����ı� ��Ӱ�쵽���º���: XDraw_TextOut XDraw_TextOutEx XDraw_TextOutA
		void EnableGdiDrawText(bool bEnable) {
			XC_EnableGdiDrawText(bEnable);
		}

		// ������Դ������
		void EnableResMonitor(bool bEnable) {
			XC_EnableResMonitor(bEnable);
		}

		// ��ʾ���ֶ���߽�
		void ShowLayoutFrame(bool bShow) {
			XC_ShowLayoutFrame(bShow);
		}

		// ��ʾ�߽� ��������
		void ShowSvgFrame(bool bShow) {
			XC_ShowSvgFrame(bShow);
		}

		// ���ò��ֱ߿���ɫ
		void SetLayoutFrameColor(COLORREF color) {
			XC_SetLayoutFrameColor(color);
		}

		// ����UI����С�ػ�Ƶ��
		void SetPaintFrequency(uint32_t milliseconds) {
			XC_SetPaintFrequency(milliseconds);
		}

		// �����ı���Ⱦ����GDI+.
		void SetTextRenderingHint(int nType) {
			XC_SetTextRenderingHint(nType);
		}

		// SetD2dTextRenderingMode
		void SetD2dTextRenderingMode(XC_DWRITE_RENDERING_MODE mode) {
			XC_SetD2dTextRenderingMode(mode);
		}




	};
}
