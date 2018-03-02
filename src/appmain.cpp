#include <CQAPI_EX.h>
#include <CQEVE_GroupMsg.h>
#include <CQEVE_PrivateMsg.h>
#include <CQLogger.h>

#include "APPINFO.h"

#include <string>
using namespace std;
using namespace CQ;

EVE_Disable(Disable)
{
	return 0;
}

EVE_Enable(Enable)
{
	return 0;
}

EVE_Menu(menu1)
{
	addLog(Log_Info, "菜单事件", "菜单1被点击");

	return 0;
}

MUST_AppInfo_RETURN(CQAPPID)