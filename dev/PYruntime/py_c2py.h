#pragma once
#include <Python.h>
#include "py_init.h"
#include <vector>

class PyObj {
	template<class T,class...Args>
	void add(T one, Args...args);
	void add();
public:
	std::vector<PyObject*> objs;
	template<class...Args>
	PyObj(Args...args);

	PyObject* getObj();
};

template<class ...Args>
inline PyObj::PyObj( Args ...args) { add(args...); }

template<class T, class ...Args>
inline void PyObj::add(T one, Args ...args) { objs.push_back(toPyObj(one)); add(args...); }

inline void PyObj::add(){}

inline PyObject * PyObj::getObj() {
	auto obj = PyTuple_New(objs.size());
	for (unsigned int i = 0; i < objs.size(); i++)
		PyTuple_SetItem(obj, i, objs[i]);
	return obj;
}

inline PyObject* toPyObj(int arg) { return Py_BuildValue("i", arg); }
inline PyObject* toPyObj(long long arg) { return Py_BuildValue("L", arg); }
inline PyObject* toPyObj(const char* arg) { auto tepptr = U(arg); char*tepU = *tepptr; return Py_BuildValue("s", tepU); }

