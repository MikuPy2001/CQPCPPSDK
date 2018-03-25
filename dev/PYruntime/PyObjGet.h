#pragma once
#include <Python.h>
#include "PyTupleGet.h"
class PyObjGet {
	PyObject*Obj;
public:
	PyObjGet() { Obj = Py_BuildValue("{}"); }

	template<class KEY, class VAL>
	bool put(KEY key, VAL val) { return PyObject_SetItem(Obj, PyTupleGet(key), PyTupleGet(val)) == 0; }

	operator PyObject*() { return Obj; }
};