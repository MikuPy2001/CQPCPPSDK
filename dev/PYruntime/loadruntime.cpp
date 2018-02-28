#include "stdafx.h"
#include "init.h"
#include <CQLogger.h>
#include <iostream>

using namespace std;
using namespace CQ;

bool init = false; PyObject *runtime;
void load_runtime() {
	logger log("初始化");
	if (init) {
		return;
	}

	auto lib = LoadLibrary(L"\\bin\\python36.dll");
	if (!lib) {
		log.Warning("无法加载\\bin\\python36.dll,请检查!");
		return;
	}

	Py_Initialize();
	if (!Py_IsInitialized())
	{
		log.Warning("py环境初始化失败");
		return;
	}

	PyRun_SimpleString("import sys;");
	PyRun_SimpleString("sys.path.append(\"pyapp\");");

	runtime = PyImport_ImportModule("PluginManager");
	if (!runtime) {
		err = true;
		log.Warning("py文件加载失败");
		Py_Finalize();
		return ;
	}
}