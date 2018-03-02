#include <CQEVE_RequestAddGroup.h>
#include <CQMsgCode.h>

#include <string>
using namespace std;
using namespace CQ;

EVE_Request_AddGroup_EX(AddGroup) {
	if (eve.subType != 1)return;

	MsgCode mc(eve.msg);

	if (!mc.find("at"))return;

	string qq = mc.get("qq");
}