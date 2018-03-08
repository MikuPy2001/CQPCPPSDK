#include <CQEVE.h>
#include <CQLogger.h>

#include "APPINFO.h"

#include <string>
using namespace std;
using namespace CQ;

//请加上static,表示这个logger只有本cpp有效
static Logger logger("酷Q样例应用");

EVE_Enable(Enable)
{
	logger.Info("应用被启用");
	return 0;
}

EVE_Disable(Disable)
{
	logger.Info("应用被停用");
	return 0;
}

MUST_AppInfo_RETURN(CQAPPID)