#pragma once
#include "pch.h"
#include "binding/XEnum.hpp"
#include "binding/XStruct.hpp"
#include "binding/XObject.hpp"
#include "binding/bkmanager/XBkManager.hpp"
#include "binding/bkmanager/XBkObject.hpp"
#include "binding/XObjectUI.hpp"
#include "binding/XApp.hpp"
#include "binding/XWidget.hpp"
#include "binding/window/XWindow.hpp"
#include "binding/XFont.hpp"
#include "binding/XSvg.hpp"
#include "binding/XDraw.hpp"
#include "binding/XImage.hpp"
#include "binding/XImageSrc.hpp"
#include "binding/XGlobal.hpp"
#include "binding/XElement.hpp"
#include "binding/XLayoutBox.hpp"
#include "binding/element/XButton.hpp"
#include "binding/XResource.hpp"
#include "binding/menu/XMenu.hpp"

						 
namespace xcgui {

	PYBIND11_MODULE(xcgui, m) {
		m.doc() = "xcgui for python";

		// 所有枚举类型
		declareEnum(m);

		// base
		declareBase(m);

		// layoutBox
		declareLayoutBox(m);

		// 所有struct
		declareStruct(m);

		// event
		declareGlobal(m);

		// xfont
		declareFont(m);

		// svg
		declareSvg(m);

		// image src
		declareImageSrc(m);

		// image
		declareImage(m);

		// draw
		declareDraw(m);

		// bkObject
		declareBkObject(m);

		// bkManager
		declareBkManager(m);

		// resource
		declareResource(m);

		// ObjectUI
		declareObjectUI(m);

		// app
		declareApp(m);

		// widget
		declareWidget(m);

		// element
		declareElement(m);

		// menu
		declareMenu(m);

		// button
		declareButton(m);

		// window
		declareWindow(m);

	

		
	}
}