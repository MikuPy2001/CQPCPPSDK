#include "py_init.h"

#include <CQLogger.h>
#include <CQEVE_ALL.h>

using namespace std;
using namespace CQ;

static Logger logger("python");

EVE_Enable(Enable) {
	logger.Info("Enable");

	if (py_isinit)
		logger.Debug("已加载");
	else if (py_init())
		logger.Info("加载成功");//初始化环境
	else
		logger.Info("加载失败");

	return 0;
}

//
//EVE_Exit(Exit) {}
//
//EVE_Disable(Disable) {}

EVE_PrivateMsg(PrivateMsg1) {
	if (!py_PrivateMsg1) return 0;
	//if (!py_t_PrivateMsg1) return 0;
	logger.Debug() << "接受事件:" << send;

	auto args = Py_BuildValue("(iilsi)", subType, msgId, fromQQ, _U(msg), font);

	logger.Debug() << "调用函数:" << (int)&args << send;
	auto *ret = PyEval_CallObject(py_PrivateMsg1, args);
	logger.Debug() << "返回值地址:" << (int)&ret << send;

	auto ex = PyErr_Occurred();
	if (ex) {
		auto *ret = PyEval_CallObject(py_printex, NULL);
		char* result;
		PyArg_Parse(ret, "c", &result);

		logger.InfoSend() << "程序未能正确执行,异常如下:"<< result << send;

		PyErr_Clear();
		return 0;
	}

	int result;
	PyArg_Parse(ret, "i", &result);
	logger.Debug() << "返回值:" << result << send;
	return result;
}
//EVE_PrivateMsg(PrivateMsg2) {}
//EVE_PrivateMsg(PrivateMsg3) {}
//EVE_PrivateMsg(PrivateMsg4) {}
//EVE_GroupMsg(GroupMsg1) {}
//EVE_GroupMsg(GroupMsg2) {}
//EVE_GroupMsg(GroupMsg3) {}
//EVE_GroupMsg(GroupMsg4) {}
//EVE_DiscussMsg(DiscussMsg1) {}
//EVE_DiscussMsg(DiscussMsg2) {}
//EVE_DiscussMsg(DiscussMsg3) {}
//EVE_DiscussMsg(DiscussMsg4) {}
//
//EVE_Friend_Add(Friend_Add1) {}
//EVE_Friend_Add(Friend_Add2) {}
//EVE_Friend_Add(Friend_Add3) {}
//EVE_Friend_Add(Friend_Add4) {}
//EVE_GroupUpload(GroupUpload1) {}
//EVE_GroupUpload(GroupUpload2) {}
//EVE_GroupUpload(GroupUpload3) {}
//EVE_GroupUpload(GroupUpload4) {}
//EVE_Request_AddFriend(Request_AddFriend1) {}
//EVE_Request_AddFriend(Request_AddFriend2) {}
//EVE_Request_AddFriend(Request_AddFriend3) {}
//EVE_Request_AddFriend(Request_AddFriend4) {}
//EVE_Request_AddGroup(Request_AddGroup1) {}
//EVE_Request_AddGroup(Request_AddGroup2) {}
//EVE_Request_AddGroup(Request_AddGroup3) {}
//EVE_Request_AddGroup(Request_AddGroup4) {}
//EVE_System_GroupAdmin(System_GroupAdmin1) {}
//EVE_System_GroupAdmin(System_GroupAdmin2) {}
//EVE_System_GroupAdmin(System_GroupAdmin3) {}
//EVE_System_GroupAdmin(System_GroupAdmin4) {}
//EVE_System_GroupMemberDecrease(System_GroupMemberDecrease1) {}
//EVE_System_GroupMemberDecrease(System_GroupMemberDecrease2) {}
//EVE_System_GroupMemberDecrease(System_GroupMemberDecrease3) {}
//EVE_System_GroupMemberDecrease(System_GroupMemberDecrease4) {}
//EVE_System_GroupMemberIncrease(System_GroupMemberIncrease1) {}
//EVE_System_GroupMemberIncrease(System_GroupMemberIncrease2) {}
//EVE_System_GroupMemberIncrease(System_GroupMemberIncrease3) {}
//EVE_System_GroupMemberIncrease(System_GroupMemberIncrease4) {}