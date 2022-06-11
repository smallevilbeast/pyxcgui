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

		// 添加文件搜索路径, 默认路为exe目录和程序当前运行目录
		void AddFileSearchPath(const std::wstring& path) {
			XC_AddFileSearchPath(path.c_str());
		}

		//  启动或禁用自动退出程序,当检测到所有用户创建的窗口都关闭时,自动退出程序; 可调用 XC_PostQuitMessage() 手动退出程序
		void EnableAutoExitApp(bool bEnable) {
			XC_EnableAutoExitApp(bEnable);
		}

		//  打印调试信息到文件
		void DebugToFileInfo(const std::string& file) {
			XC_DebugToFileInfo(file.c_str());
		}

		// 启用debug文件
		void EnableDebugFile(bool bEnable) {
			XC_EnableDebugFile(bEnable);
		}
		
		// 启用错误弹出,通过该接口可以设置遇到严重错误时不弹出消息提示框.
		void EnableErrorMessageBox(bool bEnable) {
			XC_EnableErrorMessageBox(bEnable);
		}

		// 启用GDI绘制文本 将影响到以下函数: XDraw_TextOut XDraw_TextOutEx XDraw_TextOutA
		void EnableGdiDrawText(bool bEnable) {
			XC_EnableGdiDrawText(bEnable);
		}

		// 启用资源监视器
		void EnableResMonitor(bool bEnable) {
			XC_EnableResMonitor(bEnable);
		}

		// 显示布局对象边界
		void ShowLayoutFrame(bool bShow) {
			XC_ShowLayoutFrame(bShow);
		}

		// 显示边界 辅助功能
		void ShowSvgFrame(bool bShow) {
			XC_ShowSvgFrame(bShow);
		}

		// 设置布局边框颜色
		void SetLayoutFrameColor(COLORREF color) {
			XC_SetLayoutFrameColor(color);
		}

		// 设置UI的最小重绘频率
		void SetPaintFrequency(uint32_t milliseconds) {
			XC_SetPaintFrequency(milliseconds);
		}

		// 设置文本渲染质量GDI+.
		void SetTextRenderingHint(int nType) {
			XC_SetTextRenderingHint(nType);
		}

		// SetD2dTextRenderingMode
		void SetD2dTextRenderingMode(XC_DWRITE_RENDERING_MODE mode) {
			XC_SetD2dTextRenderingMode(mode);
		}




	};
}
