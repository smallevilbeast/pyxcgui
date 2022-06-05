#pragma once
#include "pch.h"
#include <map>	 
#include <vector>
#include <functional>

#include "xcgui/window/XCWindow.hpp"
#include "XCastManager.hpp"
#include "xcgui/XCStruct.hpp"
#include "xcgui/XCResource.hpp"

/*

def threaded(f):
	@functools.wraps(f)
	def wrapper(*args, **kwargs):
		t = threading.Thread(target=f, args=args, kwargs=kwargs)
		t.daemon = True
		t.start()

	return wrapper


class callUiThread:
	def __init__(self):
		pass

	def __call__(self, func):
		self.func = func

		@functools.wraps(func)
		def objCall(*args, **kwargs):
			_callUiThread(self.func, *args, **kwargs)
		return objCall

*/

namespace xcgui {

	using XUiThreadCallback = std::function<void(py::args, py::kwargs)>;
	class XMainThreadObject {
	public:
		XMainThreadObject() = default;
		XMainThreadObject(const py::object& method, const py::args& args, const py::kwargs& kwargs)
			:method(method)
			,args(args)
			,kwargs(kwargs)
		{
		}

		py::object method;
		py::args args;
		py::kwargs kwargs;
	};



	class XMainThreadManager {
	public:
		SINGLETON_DEFINE(XMainThreadManager);
		XMainThreadManager() = default;
		~XMainThreadManager() {
			Release();
		}


	public:
		void CallUiThread(const py::object& method, const py::args& args, const py::kwargs& kwargs) {
			auto pMainObject = new XMainThreadObject(method, args, kwargs);		
			XC_CallUiThread(&XMainThreadManager::OnUiThreadCallback, (vint)pMainObject);
		}

		static vint WINAPI OnUiThreadCallback(vint data) {
			auto pMainObject = (XMainThreadObject*)(data);
			pMainObject->method(*pMainObject->args, **pMainObject->kwargs);
			delete pMainObject;
			return 0;
		}

		void Release() {
		}

	};
}