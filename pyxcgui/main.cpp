#include "pch.h"
#include "main.h"
#include "binding/XEnum.hpp"
#include "binding/XStruct.hpp"
#include "binding/XObject.hpp"
#include "binding/XObjectUI.hpp"
#include "binding/XApp.hpp"
#include "binding/XWidget.hpp"
#include "binding/XWindow.hpp"




						 
namespace xcgui {

	PYBIND11_MODULE(xcgui, m) {
		m.doc() = "xcgui for python";

		// 所有枚举类型
		declareEnum(m);

		// 所有struct
		declareStruct(m);

		// base
		declareBase(m);

		// ObjectUI
		declareObjectUI(m);

		// app
		declareApp(m);

		// window
		declareWindow(m);

		// widget
		declareWidget(m);


		
	}
}