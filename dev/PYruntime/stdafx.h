// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料
// Windows 头文件: 
#include <windows.h>

#ifdef _DEBUG
#pragma comment(lib,"SDK_Debug.lib")
#else
#pragma comment(lib,"SDK_Release.lib")
#endif

#define CQAPPID "cn.mikupy2001.PYruntime"

// TODO: 在此处引用程序需要的其他头文件
#include <Python.h>
#include <CQEVE_ALL.h>
#include <CQAPI_EX.h>