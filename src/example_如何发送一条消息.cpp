#include <CQEVE_PrivateMsg.h>
#include <CQcode.h>
#include <CQLogger.h>
#include <CQAPI_EX.h>

#include <string>
using namespace std;
using namespace CQ;

//请加上static,表示这个logger只有本cpp有效
static Logger logger("SendMsg");

EVE_PrivateMsg_EX(SendMsg) {
	logger.Debug() << DEBUGINFO << eve.message;

	// 获得一个和事件有关的消息对象
	// 这个消息对象已经自动关联事件对应的群或者好友
	auto msg = eve.sendMsg();
	// 如果你想给特定的人发送消息,例如好友123456
	// 您可以直接调用API
	//sendPrivateMsg(123456, "你好");
	// 或者使用MsgSend
	//MsgSend P123456(123456, msgtype::好友);
	//P123456 << "你好" << send;

	auto message = eve.message;

	// 普通的发送一条消息
	if (!message.compare("CQ:msg1"))
		eve.sendMsg("收到消息了!");

	// 使用<<来发送消息
	if (!message.compare("CQ:msg2"))
		//一定要末尾加上<<send才会发送出去
		msg << "收到消息了!" << send;

	// 强大的消息发送方式
	if (!message.compare("CQ:msg3"))
		// 发送内容由多个内容组成
		msg
		<< "发送人为:" << eve.fromQQ
		<< ",消息为:" << eve.message
		<< send;

	if (!message.compare("CQ:image")) {
		logger.Debug() << "raw模式:" << msg.isRAW() << send;
		// 发送一个图片
		msg << code::image("123.gif") << send;
	}

	if (!message.compare("CQ:face"))
		//发送一个表情
		msg << code::face(face::得意) << send;

	if (!message.compare("CQ:raw"))
		msg
		// RAW 表示后面的消息将被原样发送
		// 而不是解析成CQ码,并调用特有功能,例如发送图片
		<< RAW << code::at(eve.fromQQ)
		// CODE 表示后面的消息将被解析为CQ码
		// 默认解析
		<< CODE << code::face(face::得意)
		<< send;

	if (!message.compare("CQ:effect"))
		// 发送一个魔法字体,此CQ码必须单独一条消息
		eve.sendMsg(code::effect("art", 2003, "魔法消息"));
}