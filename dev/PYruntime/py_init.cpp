#define WIN32_LEAN_AND_MEAN
#include "py_init.h"

#include <CQLogger.h>
#include <CQAPI_EX.h>

#include <Python.h>

#include <iostream>

#include <windows.h>

using namespace std;
using namespace CQ;
static Logger logger("PyInit");

void 反射函数() {
	py_printex = PyObject_GetAttrString(py_RunTime, "printex");

	py_Enable = PyObject_GetAttrString(py_RunTime, "Enable");

	py_Disable = PyObject_GetAttrString(py_RunTime, "Disable");

	py_DiscussMsg1 = PyObject_GetAttrString(py_RunTime, "DiscussMsg1");
	py_DiscussMsg2 = PyObject_GetAttrString(py_RunTime, "DiscussMsg2");
	py_DiscussMsg3 = PyObject_GetAttrString(py_RunTime, "DiscussMsg3");
	py_DiscussMsg4 = PyObject_GetAttrString(py_RunTime, "DiscussMsg4");
	py_Exit = PyObject_GetAttrString(py_RunTime, "Exit");
	py_Friend_Add1 = PyObject_GetAttrString(py_RunTime, "Friend_Add1");
	py_Friend_Add2 = PyObject_GetAttrString(py_RunTime, "Friend_Add2");
	py_Friend_Add3 = PyObject_GetAttrString(py_RunTime, "Friend_Add3");
	py_Friend_Add4 = PyObject_GetAttrString(py_RunTime, "Friend_Add4");
	py_GroupMsg1 = PyObject_GetAttrString(py_RunTime, "GroupMsg1");
	py_GroupMsg2 = PyObject_GetAttrString(py_RunTime, "GroupMsg2");
	py_GroupMsg3 = PyObject_GetAttrString(py_RunTime, "GroupMsg3");
	py_GroupMsg4 = PyObject_GetAttrString(py_RunTime, "GroupMsg4");
	py_GroupUpload1 = PyObject_GetAttrString(py_RunTime, "GroupUpload1");
	py_GroupUpload2 = PyObject_GetAttrString(py_RunTime, "GroupUpload2");
	py_GroupUpload3 = PyObject_GetAttrString(py_RunTime, "GroupUpload3");
	py_GroupUpload4 = PyObject_GetAttrString(py_RunTime, "GroupUpload4");
	py_PrivateMsg1 = PyObject_GetAttrString(py_RunTime, "PrivateMsg1");
	py_PrivateMsg2 = PyObject_GetAttrString(py_RunTime, "PrivateMsg2");
	py_PrivateMsg3 = PyObject_GetAttrString(py_RunTime, "PrivateMsg3");
	py_PrivateMsg4 = PyObject_GetAttrString(py_RunTime, "PrivateMsg4");
	py_Request_AddFriend1 = PyObject_GetAttrString(py_RunTime, "Request_AddFriend1");
	py_Request_AddFriend2 = PyObject_GetAttrString(py_RunTime, "Request_AddFriend2");
	py_Request_AddFriend3 = PyObject_GetAttrString(py_RunTime, "Request_AddFriend3");
	py_Request_AddFriend4 = PyObject_GetAttrString(py_RunTime, "Request_AddFriend4");
	py_Request_AddGroup1 = PyObject_GetAttrString(py_RunTime, "Request_AddGroup1");
	py_Request_AddGroup2 = PyObject_GetAttrString(py_RunTime, "Request_AddGroup2");
	py_Request_AddGroup3 = PyObject_GetAttrString(py_RunTime, "Request_AddGroup3");
	py_Request_AddGroup4 = PyObject_GetAttrString(py_RunTime, "Request_AddGroup4");
	py_Startup = PyObject_GetAttrString(py_RunTime, "Startup");
	py_System_GroupAdmin1 = PyObject_GetAttrString(py_RunTime, "System_GroupAdmin1");
	py_System_GroupAdmin2 = PyObject_GetAttrString(py_RunTime, "System_GroupAdmin2");
	py_System_GroupAdmin3 = PyObject_GetAttrString(py_RunTime, "System_GroupAdmin3");
	py_System_GroupAdmin4 = PyObject_GetAttrString(py_RunTime, "System_GroupAdmin4");
	py_System_GroupMemberDecrease1 = PyObject_GetAttrString(py_RunTime, "System_GroupMemberDecrease1");
	py_System_GroupMemberDecrease2 = PyObject_GetAttrString(py_RunTime, "System_GroupMemberDecrease2");
	py_System_GroupMemberDecrease3 = PyObject_GetAttrString(py_RunTime, "System_GroupMemberDecrease3");
	py_System_GroupMemberDecrease4 = PyObject_GetAttrString(py_RunTime, "System_GroupMemberDecrease4");
	py_System_GroupMemberIncrease1 = PyObject_GetAttrString(py_RunTime, "System_GroupMemberIncrease1");
	py_System_GroupMemberIncrease2 = PyObject_GetAttrString(py_RunTime, "System_GroupMemberIncrease2");
	py_System_GroupMemberIncrease3 = PyObject_GetAttrString(py_RunTime, "System_GroupMemberIncrease3");
	py_System_GroupMemberIncrease4 = PyObject_GetAttrString(py_RunTime, "System_GroupMemberIncrease4");

	PyErr_Clear();
}
bool 准备环境() {
	if (py_isinit) {
		return py_isinit;
	}

	char pBuf[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, pBuf);
	string bins(pBuf), locs(pBuf);

	bins += "\\bin\\python36.dll";
	locs += "\\python36.dll";

	if (!LoadLibrary("python36.dll"))
		if (!LoadLibrary(bins.c_str()))
			if (!LoadLibrary(locs.c_str())) {
				logger.Debug(pBuf);
				logger.Warning("无法找到并加载python36.dll,请将其放入bin目录!");
				return false;
			}

	Py_Initialize();
	if (!Py_IsInitialized())
	{
		logger.Warning("py环境初始化失败");
		return false;
	}

	PyRun_SimpleString("import sys;");
	PyRun_SimpleString("sys.path.append(\"app-python\");");

	py_RunTime = PyImport_ImportModule("PluginManager");
	if (!py_RunTime) {
		logger.Warning("py文件加载失败");
		Py_Finalize();
		return false;
	}
	auto cq = getCQAPI();
	logger.Debug() << "CQ模块地址:" << (int)cq << send;
	auto r = PyModule_AddObject(py_RunTime, "CQ", cq);
	logger.Debug() << "添加到RunTime结果:" << r << send;

	return true;
}
bool py_init() {
	if (!py_isinit)
		if (准备环境()) {
			反射函数();
			return py_isinit = true;
		}
	return py_isinit;
}