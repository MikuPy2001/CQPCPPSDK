#include <CQEVE_GroupMsg.h>
#include <winSpeak.h>
#include <CQMsgCode.h>

#include <string>
using namespace std;
using namespace CQ;

EVE_GroupMsg_EX(Speak) {
	if (eve.message[0] != '.')return;
	if (eve.message[1] != ' ')return;

	auto txt = eve.message.substr(2);

	eve.sendMsg() << code::record("out.wav", txt) << send;
}