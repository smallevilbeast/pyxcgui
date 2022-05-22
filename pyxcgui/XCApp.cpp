#pragma once
#include "pch.h"
#include "XCApp.h"

XCApp::XCApp(bool bD2D)
{
	XInitXCGUI(bD2D);
}

void XCApp::Run()
{
	XRunXCGUI();
}

void XCApp::Exit()
{
	XExitXCGUI();
}
