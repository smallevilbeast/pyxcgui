#pragma once
#include "pch.h"
#include "binding/XEnum.hpp"
#include "binding/XStruct.hpp"
#include "binding/XObject.hpp"
#include "binding/XBkManager.hpp"
#include "binding/XObjectUI.hpp"
#include "binding/XApp.hpp"
#include "binding/XWidget.hpp"
#include "binding/XWindow.hpp"
#include "binding/XFont.hpp"
#include "binding/XSvg.hpp"
#include "binding/XDraw.hpp"
#include "binding/XImage.hpp"
#include "binding/XImageSrc.hpp"
#include "binding/XElement.hpp"
#include "binding/element/XButton.hpp"

						 
namespace xcgui {

	PYBIND11_MODULE(xcgui, m) {
		m.doc() = "xcgui for python";

		// 所有枚举类型
		declareEnum(m);

		// 所有struct
		declareStruct(m);

		// base
		declareBase(m);

		// bkManager
		declareBkManager(m);

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
		


		// ObjectUI
		declareObjectUI(m);

		// app
		declareApp(m);

		// window
		declareWindow(m);

		// widget
		declareWidget(m);

		// element
		declareElement(m);

		// button
		declareButton(m);


		
	}
}