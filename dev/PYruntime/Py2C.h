#pragma once
#include <Python.h>
#include <string>
#include "py_зЊТы.h"

inline PyObject* toPyObj(int arg) { return Py_BuildValue("i", arg); }
inline bool setPyObj(PyObject*obj, int*arg) { return PyArg_Parse(obj, "i", arg); }

inline PyObject* toPyObj(long long arg) { return Py_BuildValue("L", arg); }
inline bool setPyObj(PyObject*obj, long long*arg) { return PyArg_Parse(obj, "L", arg); }

inline PyObject* toPyObj(std::string arg) { return toPyObj(arg.c_str()); }
inline PyObject* toPyObj(const char* arg) { auto tepptr = U(arg); char*tepU = *tepptr; return Py_BuildValue("s", tepU); }
inline bool setPyObj(PyObject*obj, char**arg) {
	if (PyArg_Parse(obj, "s", arg)) { *arg = _G(*arg); return true; }
	return false;
}