#ifndef PCH_H
#define PCH_H

#include "framework.h"
#include <windows.h>
#include <string>
#include <functional>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
#include <pybind11/functional.h>


namespace py = pybind11;
using namespace pybind11::literals;

#include "xcgui.h"

#define SINGLETON_DEFINE(TypeName)				\
static TypeName* GetInstance()					\
{												\
	static TypeName type_instance;				\
	return &type_instance;						\
}												\
												\
TypeName(const TypeName&) = delete;				\
TypeName& operator=(const TypeName&) = delete

#define PYCAST(TypeName)\
.def_static("cast", [](uintptr_t pointer) -> TypeName* {           \
	if (::IsBadReadPtr((const void*)pointer, sizeof(uintptr_t))) { \
		return nullptr;											   \
	}															   \
	return (TypeName*)(pointer);								   \
}, "pointer"_a, py::return_value_policy::reference)		

#define PYCASTOBJECT(TypeName)\
.def_static("cast", [](uintptr_t pointer) -> TypeName* {\
	return new TypeName((HXCGUI)pointer);					    \
}, "handle"_a, py::return_value_policy::take_ownership)		

#define PYOBJECTVALID(TypeName, ObjectType)  \
.def("isValid", [](TypeName& self) -> bool { \
	return self.GetType() == ObjectType;     \
})

#endif 

