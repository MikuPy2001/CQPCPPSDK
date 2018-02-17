#include "stdafx.h"

MUST_AppInfo_RETURN(CQAPPID)

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{

	LoadLibrary(L"\\bin\\python36.dll");

	return TRUE;
}

