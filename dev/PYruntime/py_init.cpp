#include "stdafx.h"
#include "py_init.h"
#include <CQLogger.h>
#include <iostream>

using namespace std;
using namespace CQ;

bool 反射函数() {
	py_Disable1                    = PyObject_GetAttrString(py_RunTime, "Disable1");
	py_Disable2                    = PyObject_GetAttrString(py_RunTime, "Disable2");
	py_Disable3                    = PyObject_GetAttrString(py_RunTime, "Disable3");
	py_Disable4                    = PyObject_GetAttrString(py_RunTime, "Disable4");
	py_DiscussMsg1                 = PyObject_GetAttrString(py_RunTime, "DiscussMsg1");
	py_DiscussMsg2                 = PyObject_GetAttrString(py_RunTime, "DiscussMsg2");
	py_DiscussMsg3                 = PyObject_GetAttrString(py_RunTime, "DiscussMsg3");
	py_DiscussMsg4                 = PyObject_GetAttrString(py_RunTime, "DiscussMsg4");
	py_Enable1                     = PyObject_GetAttrString(py_RunTime, "Enable1");
	py_Enable2                     = PyObject_GetAttrString(py_RunTime, "Enable2");
	py_Enable3                     = PyObject_GetAttrString(py_RunTime, "Enable3");
	py_Enable4                     = PyObject_GetAttrString(py_RunTime, "Enable4");
	py_Exit                        = PyObject_GetAttrString(py_RunTime, "Exit");
	py_Friend_Add1                 = PyObject_GetAttrString(py_RunTime, "Friend_Add1");
	py_Friend_Add2                 = PyObject_GetAttrString(py_RunTime, "Friend_Add2");
	py_Friend_Add3                 = PyObject_GetAttrString(py_RunTime, "Friend_Add3");
	py_Friend_Add4                 = PyObject_GetAttrString(py_RunTime, "Friend_Add4");
	py_GroupMsg1                   = PyObject_GetAttrString(py_RunTime, "GroupMsg1");
	py_GroupMsg2                   = PyObject_GetAttrString(py_RunTime, "GroupMsg2");
	py_GroupMsg3                   = PyObject_GetAttrString(py_RunTime, "GroupMsg3");
	py_GroupMsg4                   = PyObject_GetAttrString(py_RunTime, "GroupMsg4");
	py_GroupUpload1                = PyObject_GetAttrString(py_RunTime, "GroupUpload1");
	py_GroupUpload2                = PyObject_GetAttrString(py_RunTime, "GroupUpload2");
	py_GroupUpload3                = PyObject_GetAttrString(py_RunTime, "GroupUpload3");
	py_GroupUpload4                = PyObject_GetAttrString(py_RunTime, "GroupUpload4");
	py_PrivateMsg1                 = PyObject_GetAttrString(py_RunTime, "PrivateMsg1");
	py_PrivateMsg2                 = PyObject_GetAttrString(py_RunTime, "PrivateMsg2");
	py_PrivateMsg3                 = PyObject_GetAttrString(py_RunTime, "PrivateMsg3");
	py_PrivateMsg4                 = PyObject_GetAttrString(py_RunTime, "PrivateMsg4");
	py_Request_AddFriend1          = PyObject_GetAttrString(py_RunTime, "Request_AddFriend1");
	py_Request_AddFriend2          = PyObject_GetAttrString(py_RunTime, "Request_AddFriend2");
	py_Request_AddFriend3          = PyObject_GetAttrString(py_RunTime, "Request_AddFriend3");
	py_Request_AddFriend4          = PyObject_GetAttrString(py_RunTime, "Request_AddFriend4");
	py_Request_AddGroup1           = PyObject_GetAttrString(py_RunTime, "Request_AddGroup1");
	py_Request_AddGroup2           = PyObject_GetAttrString(py_RunTime, "Request_AddGroup2");
	py_Request_AddGroup3           = PyObject_GetAttrString(py_RunTime, "Request_AddGroup3");
	py_Request_AddGroup4           = PyObject_GetAttrString(py_RunTime, "Request_AddGroup4");
	py_Startup                     = PyObject_GetAttrString(py_RunTime, "Startup");
	py_System_GroupAdmin1          = PyObject_GetAttrString(py_RunTime, "System_GroupAdmin1");
	py_System_GroupAdmin2          = PyObject_GetAttrString(py_RunTime, "System_GroupAdmin2");
	py_System_GroupAdmin3          = PyObject_GetAttrString(py_RunTime, "System_GroupAdmin3");
	py_System_GroupAdmin4          = PyObject_GetAttrString(py_RunTime, "System_GroupAdmin4");
	py_System_GroupMemberDecrease1 = PyObject_GetAttrString(py_RunTime, "System_GroupMemberDecrease1");
	py_System_GroupMemberDecrease2 = PyObject_GetAttrString(py_RunTime, "System_GroupMemberDecrease2");
	py_System_GroupMemberDecrease3 = PyObject_GetAttrString(py_RunTime, "System_GroupMemberDecrease3");
	py_System_GroupMemberDecrease4 = PyObject_GetAttrString(py_RunTime, "System_GroupMemberDecrease4");
	py_System_GroupMemberIncrease1 = PyObject_GetAttrString(py_RunTime, "System_GroupMemberIncrease1");
	py_System_GroupMemberIncrease2 = PyObject_GetAttrString(py_RunTime, "System_GroupMemberIncrease2");
	py_System_GroupMemberIncrease3 = PyObject_GetAttrString(py_RunTime, "System_GroupMemberIncrease3");
	py_System_GroupMemberIncrease4 = PyObject_GetAttrString(py_RunTime, "System_GroupMemberIncrease4");
}
bool 准备环境() {
	if (py_isinit) {
		return;
	}
	logger log("初始化");

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

	py_RunTime = PyImport_ImportModule("PluginManager");
	if (!py_RunTime) {
		log.Warning("py文件加载失败");
		Py_Finalize();
		return;
	}
	py_isinit = true;
}
bool py_init() {
	if (!py_isinit)
		if (准备环境() && 反射函数())
			return py_isinit = true;
	return py_isinit;
}