#include <CQEVE_PrivateMsg.h>
#include <CQcode.h>
#include <CQLogger.h>

#include <string>
using namespace std;
using namespace CQ;

//请加上static,表示这个logger只有本cpp有效
static Logger logger("SendMsg");

EVE_PrivateMsg_EX(SendMsg) {
	logger.Debug() << DEBUGINFO << eve.message;
	auto msg = eve.sendMsg();
	auto message = eve.message;

	if (!message.compare("CQ:msg1"))
		eve.sendMsg("收到消息了!");

	if (!message.compare("CQ:msg2"))
		//一定要末尾加上<<send才会发送出去
		msg << "收到消息了!" << send;

	if (!message.compare("CQ:msg3"))
		//发送内容由多个内容组成
		msg
		<< "发送人为:" << eve.fromQQ
		<< ",消息为:" << eve.message
		<< send;

	if (!message.compare("CQ:image")) {
		logger.Debug() << "raw模式:" << msg.isRAW() << send;
		//发送一个图片
		msg << code::image("123.png") << send;
	}

	if (!message.compare("CQ:face"))
		//发送一个表情
		msg << code::face(face::得意) << send;

	if (!message.compare("CQ:raw"))
		msg
		//RAW 表示后面的消息将被原样发送
		//而不是解析成CQ码,并调用特有功能,例如发送图片
		<< RAW << code::at(eve.fromQQ)
		//CODE 表示后面的消息将被解析为CQ码
		//默认解析
		<< CODE << code::face(face::得意)
		<< send;

	if (!message.compare("CQ:effect"))
		//发送一个魔法字体,此CQ码必须单独一条消息
		eve.sendMsg(code::effect("art", 2003, "魔法消息"));
}