#include <CQEVE_GroupMsg.h>
#include <winSpeak.h>
#include <CQMsgCode.h>

#include <string>
using namespace std;
using namespace CQ;

EVE_GroupMsg_EX(Speak) {
	if (eve.message[0] != '.')return;

	auto txt = eve.message.substr(1);

	Speak_init();

	char pBuf[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, pBuf);

	string s(pBuf);
	s += "\\data\\record\\out.wav";

	Speak_to_wav_file(s, txt);

	eve.sendMsg() << code::record("out.wav") << send;
}