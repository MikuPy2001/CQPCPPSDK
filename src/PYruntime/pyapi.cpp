#include "stdafx.h"
#include "init.h"



typedef PyObject* PYO;
#define SPO static PYO 

SPO addLog(PYO self, PYO args) {
	整数型 优先级;
	文本型 类型;
	文本型 内容;

	if (!PyArg_ParseTuple(args, "iss", &优先级,&类型,&内容)) {
		return NULL;
	}
}
SPO deleteMsg(PYO self, PYO args) {}
SPO getAppDirectory(PYO self, PYO args) {}
SPO getCookies(PYO self, PYO args) {}
SPO getCsrfToken(PYO self, PYO args) {}
SPO getGroupList(PYO self, PYO args) {}
SPO getGroupMemberInfo(PYO self, PYO args) {}
SPO getLoginNick(PYO self, PYO args) {}
SPO getLoginQQ(PYO self, PYO args) {}
SPO getRecord(PYO self, PYO args) {}
SPO getStrangerInfo(PYO self, PYO args) {}
SPO sendDiscussMsg(PYO self, PYO args) {}
SPO sendGroupMsg(PYO self, PYO args) {}
SPO sendLike(PYO self, PYO args) {}
SPO sendPrivateMsg(PYO self, PYO args) {}
SPO setDiscussLeave(PYO self, PYO args) {}
SPO setFatal(PYO self, PYO args) {}
SPO setFriendAddRequest(PYO self, PYO args) {}
SPO setGroupAddRequest(PYO self, PYO args) {}
SPO setGroupAdmin(PYO self, PYO args) {}
SPO setGroupAnonymous(PYO self, PYO args) {}
SPO setGroupAnonymousBan(PYO self, PYO args) {}
SPO setGroupBan(PYO self, PYO args) {}
SPO setGroupCard(PYO self, PYO args) {}
SPO setGroupKick(PYO self, PYO args) {}
SPO setGroupLeave(PYO self, PYO args) {}
SPO setGroupSpecialTitle(PYO self, PYO args) {}
SPO setGroupWholeBan(PYO self, PYO args) {}






static PyMethodDef API方法数组[] = {
	//{ "getAuth", getAuth, METH_VARARGS ,"" },
	{ "addLog",addLog, METH_VARARGS , },
	{ "deleteMsg",deleteMsg, METH_VARARGS , },
	{ "getAppDirectory",getAppDirectory, METH_VARARGS , },
	{ "getCookies",getCookies, METH_VARARGS , },
	{ "getCsrfToken",getCsrfToken, METH_VARARGS , },
	{ "getGroupList",getGroupList, METH_VARARGS , },
	{ "getGroupMemberInfo",getGroupMemberInfo, METH_VARARGS , },
	{ "getLoginNick",getLoginNick, METH_VARARGS , },
	{ "getLoginQQ",getLoginQQ, METH_VARARGS , },
	{ "getRecord",getRecord, METH_VARARGS , },
	{ "getStrangerInfo",getStrangerInfo, METH_VARARGS , },
	{ "sendDiscussMsg",sendDiscussMsg, METH_VARARGS , },
	{ "sendGroupMsg",sendGroupMsg, METH_VARARGS , },
	{ "sendLike",sendLike, METH_VARARGS , },
	{ "sendPrivateMsg",sendPrivateMsg, METH_VARARGS , },
	{ "setDiscussLeave",setDiscussLeave, METH_VARARGS , },
	{ "setFatal",setFatal, METH_VARARGS , },
	{ "setFriendAddRequest",setFriendAddRequest, METH_VARARGS , },
	{ "setGroupAddRequest",setGroupAddRequest, METH_VARARGS , },
	{ "setGroupAdmin",setGroupAdmin, METH_VARARGS , },
	{ "setGroupAnonymous",setGroupAnonymous, METH_VARARGS , },
	{ "setGroupAnonymousBan",setGroupAnonymousBan, METH_VARARGS , },
	{ "setGroupBan",setGroupBan, METH_VARARGS , },
	{ "setGroupCard",setGroupCard, METH_VARARGS , },
	{ "setGroupKick",setGroupKick, METH_VARARGS , },
	{ "setGroupLeave",setGroupLeave, METH_VARARGS , },
	{ "setGroupSpecialTitle",setGroupSpecialTitle, METH_VARARGS , },
	{ "setGroupWholeBan",setGroupWholeBan, METH_VARARGS , },

	{ NULL, NULL,0,NULL },
};

static struct PyModuleDef API描述 = {
	PyModuleDef_HEAD_INIT,
	"CQ",   /* name of module */
	NULL, /* module documentation, may be NULL */
	-1,       /* size of per-interpreter state of the module,
			  or -1 if the module keeps state in global variables. */
	API方法数组
};
PYO getCQAPI() {
	return PyModule_Create(&API描述);
}