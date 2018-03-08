#include <CQEVE_PrivateMsg.h>
#include <CQLogger.h>

#include <string>
using namespace std;
using namespace CQ;

//
//经过实验,此功能无法实现
//
//
//
//

//请加上static,表示这个logger只有本cpp有效
static Logger logger("ChangMsg");

static bool Chang = false;
EVE_PrivateMsg_EX(ChangMsg) {
	if (!eve.message.compare("CQ:ChangMsg")) {
		eve.messageRAW[0] = 'Q';
		Chang = true;
	}
}
EVE_PrivateMsg_EX(ChangMsg2) {
	static Logger logger("ChangMsg");
	if (Chang) {
		logger.Info(eve.message);
		Chang = false;
	}
}