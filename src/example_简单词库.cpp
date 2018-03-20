#include <CQEVE_GroupMsg.h>
#include <CQEVE_PrivateMsg.h>
#include <CQMsgSend.h>
#include <CQAPI_EX.h>
#include  <INItool.h>

#include <string>
using namespace std;
using namespace CQ;

int  Thesaurus(文本型 msg, MsgSend send) {
}

EVE_Enable(ThesaurusE) {
	auto file = string(getAppDirectory()) + "Thesaurus.ini";
	ini::INItool INI(file);
	for (auto t : INI) {

	}
}

EVE_PrivateMsg(ThesaurusP) {
	return Thesaurus(msg, MsgSend(fromQQ, msgtype::好友));
}
EVE_GroupMsg(ThesaurusG) {
	return Thesaurus(msg, MsgSend(fromGroup, msgtype::群));
}