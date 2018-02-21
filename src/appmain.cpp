#include "string"

//#include "CQSDK/CQconstant.h"
//#include "CQSDK/CQAPI_EX.h"
//#include "CQSDK/CQEVE_GroupMsg.h"
//#include "CQSDK/CQEVE_PrivateMsg.h"
//#include "CQSDK/CQLogger.h"

#include <CQAPI_EX.h>
#include <CQEVE_GroupMsg.h>
#include <CQEVE_PrivateMsg.h>
#include <CQLogger.h>

#include "APPINFO.h"

using namespace std;
using namespace CQ;


EVE_PrivateMsg_EX(privateMsgEx)
{
	static logger log("私聊事件");
	try
	{
		log.Info()
			<< "{名称: " << eve.font.名称
			<< ", 字号:" << eve.font.字号
			<< ", 颜色:" << eve.font.颜色
			<< ", 样式:" << eve.font.样式
			<< ", 气泡:" << eve.font.气泡
			<< "}" << send;
	}
	catch (...)
    {
        log.Info("私聊出现异常");
	}
}

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

EVE_Menu(menu2)
{
	addLog(Log_Info, "菜单事件", "菜单2被点击");

	return 0;
}

MUST_AppInfo_RETURN(CQAPPID)

