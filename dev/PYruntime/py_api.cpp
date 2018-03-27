#include "py_环境.h"

#include <CQLogger.h>
#include <CQAPI_EX.h>
#include"PyTupleMinute.h"
#include"PyTupleGet.h"
#include"PyObjGet.h"

using namespace CQ;
using namespace std;

typedef PyObject* PYO;
static Logger logger("PyRunAPi");

//self - 调用方
//args - 参数
#define SPO(name) static PYO name (PYO self, PYO args)

#define 喵 PYO res = nullptr; Py_BEGIN_ALLOW_THREADS
#define 帕 PyTupleMinute r(args,
#define 斯 ); if (r) {
#define DE_ZA }else logger.Debug() << "有Py插件试图调用API,但是参数不正确" << send;\
               Py_END_ALLOW_THREADS;return res;

#define 啪 PYO res = nullptr;Py_BEGIN_ALLOW_THREADS res = PyTupleGet(
#define 死 ); Py_END_ALLOW_THREADS;return res;

#define 咪 PYO res = nullptr;Py_BEGIN_ALLOW_THREADS
#define 趴 Py_END_ALLOW_THREADS;return res;

SPO(py_addLog) { 喵 整数型 优先级; char* 类型; char* 内容; 帕 &优先级, &类型, &内容 斯 res = PyTupleGet(addLog(优先级, 类型, 内容)); DE_ZA }
SPO(py_deleteMsg) { 喵 长整数型 MsgId; 帕 &MsgId 斯 res = PyTupleGet(deleteMsg(MsgId)); DE_ZA }
SPO(py_getAppDirectory) { 啪 getAppDirectory() 死 }
SPO(py_getCookies) { 啪 getCookies() 死 }
SPO(py_getCsrfToken) { 啪 getCsrfToken() 死 }
SPO(py_getGroupList) { 咪 auto list = getGroupList(); PyObjGet obj; for (auto ls : list)obj.put(ls.first, ls.second); res = PyTupleGet(obj); 趴 }
SPO(py_getGroupMemberInfo) {
	喵 长整数型 群号; 长整数型 QQID; 逻辑型 不使用缓存; 帕 &群号, &QQID, &不使用缓存 斯
		GroupMemberInfo info = getGroupMemberInfo(群号, QQID, 不使用缓存);
	PyObjGet obj;
	obj.put("Group", info.Group);
	obj.put("QQID", info.QQID);
	obj.put("昵称", info.昵称);
	obj.put("名片", info.名片);
	obj.put("性别", info.性别);
	obj.put("年龄", info.年龄);
	obj.put("地区", info.地区);
	obj.put("加群时间", info.加群时间);
	obj.put("最后发言", info.最后发言);
	obj.put("等级_名称", info.等级_名称);
	obj.put("permissions", info.permissions);
	obj.put("专属头衔", info.专属头衔);
	obj.put("专属头衔过期时间", info.专属头衔过期时间);
	obj.put("不良记录成员", info.不良记录成员);
	obj.put("允许修改名片", info.允许修改名片);
	res = PyTupleGet(obj);
	DE_ZA
}
SPO(py_getLoginNick) { 啪 getLoginNick() 死 }
SPO(py_getLoginQQ) { 啪 getLoginQQ() 死 }
SPO(py_getRecord) { 喵 文本型 file, outformat; 帕 &file, &outformat 斯 res = PyTupleGet(getRecord(file, outformat)); DE_ZA }
SPO(py_getStrangerInfo) {
	喵 长整数型 QQID; 逻辑型 不使用缓存; 帕 &QQID, &不使用缓存 斯
	auto info = getStrangerInfo(QQID, 不使用缓存);
	
	res = PyTupleGet();
	DE_ZA
}
SPO(py_sendDiscussMsg) { 喵 长整数型 讨论组号; 文本型 msg; 帕 &讨论组号, &msg 斯 res = PyTupleGet(sendDiscussMsg(讨论组号, msg)); DE_ZA }
SPO(py_sendGroupMsg) { 喵 长整数型 群号; 文本型 msg; 帕 &群号, &msg 斯 res = PyTupleGet(sendGroupMsg(群号, msg)); DE_ZA }
SPO(py_sendLike) { 喵 长整数型 QQID; 整数型 times; 帕 &QQID, &times 斯 res = PyTupleGet(sendLike(QQID, times)); DE_ZA }
SPO(py_sendPrivateMsg) { 喵 长整数型 QQ; 文本型 msg; 帕 &QQ, &msg 斯 res = PyTupleGet(sendPrivateMsg(QQ, msg)); DE_ZA }
SPO(py_setDiscussLeave) { 喵 长整数型 讨论组号 帕 &讨论组号 斯 res = PyTupleGet(setDiscussLeave(讨论组号)); DE_ZA }
SPO(py_setFriendAddRequest) { 喵 文本型 请求反馈标识;整数型 反馈类型;文本型 备注; 帕 &求反馈标识,&反馈类型,&备注 斯 res = PyTupleGet(setFriendAddRequest(请求反馈标识,反馈类型,备注)); DE_ZA }
SPO(py_setGroupAddRequest) { 喵 文本型 请求反馈标识;整数型 请求类型,反馈类型;文本型 备注; 帕 &求反馈标识,&请求类型,&反馈类型,&备注 斯 res = PyTupleGet(setGroupAddRequest(请求反馈标识,请求类型,反馈类型,备注)); DE_ZA }
SPO(py_setGroupAdmin) { 喵 长整数型 群号, QQID;逻辑型 成为管理员; 帕 &群号, &QQID, &成为管理员 斯 res = PyTupleGet(setGroupAdmin(群号, QQID, 成为管理员)); DE_ZA }
SPO(py_setGroupAnonymous) { 喵 长整数型 群号;逻辑型 开启匿名; 帕 &群号,&开启匿名 斯 res = PyTupleGet(setGroupAnonymous(群号,开启匿名)); DE_ZA }
SPO(py_setGroupAnonymousBan) { 喵 长整数型 群号;文本型 匿名;长整数型 禁言时间; 帕 &群号,&匿名,&禁言时间 斯 res = PyTupleGet(setGroupAnonymousBan(群号,匿名,禁言时间)); DE_ZA }
SPO(py_setGroupBan) { 喵 长整数型 群号,QQID,禁言时间; 帕 &群号,&QQID,&禁言时间 斯 res = PyTupleGet(setGroupBan(群号, QQID,禁言时间)); DE_ZA }
SPO(py_setGroupCard) { 喵 长整数型 群号,QQID;文本型 新名片_昵称 帕 &群号,&QQID,&新名片_昵称 斯 res = PyTupleGet(setGroupCard(群号,QQID,新名片_昵称)); DE_ZA }
SPO(py_setGroupKick) { 喵 长整数型 群号,  QQID;逻辑型 拒绝再加群 帕 &群号,&QQID,&拒绝再加群 斯 res = PyTupleGet(setGroupKick(群号,QQID,拒绝再加群)); DE_ZA }
SPO(py_setGroupLeave) { 喵 长整数型 群号;逻辑型 是否解散 帕 &群号,&是否解散 斯 res = PyTupleGet(setGroupLeave(群号,是否解散)); DE_ZA }
SPO(py_setGroupSpecialTitle) { 喵 长整数型 群号,QQID 帕 群号,QQID 斯 res = PyTupleGet(setGroupSpecialTitle(群号,QQID)); DE_ZA }
SPO(py_setGroupWholeBan) { 喵  帕  斯 res = PyTupleGet(); DE_ZA }

static PyMethodDef API方法数组[] = {
 { "addLog"              ,py_addLog, METH_VARARGS , ""},
 //{ "deleteMsg"           ,py_deleteMsg, METH_VARARGS , ""},
 //{ "getAppDirectory"     ,py_getAppDirectory, METH_VARARGS , ""},
 //{ "getCookies"          ,py_getCookies, METH_VARARGS , ""},
 //{ "getCsrfToken"        ,py_getCsrfToken, METH_VARARGS ,"" },
 //{ "getGroupList"        ,py_getGroupList, METH_VARARGS , ""},
 //{ "getGroupMemberInfo"  ,py_getGroupMemberInfo, METH_VARARGS ,"" },
 //{ "getLoginNick"        ,py_getLoginNick, METH_VARARGS , ""},
 //{ "getLoginQQ"          ,py_getLoginQQ, METH_VARARGS ,"" },
 //{ "getRecord"           ,py_getRecord, METH_VARARGS , ""},
 //{ "getStrangerInfo"     ,py_getStrangerInfo, METH_VARARGS ,"" },
 //{ "sendDiscussMsg"      ,py_sendDiscussMsg, METH_VARARGS , ""},
 //{ "sendGroupMsg"        ,py_sendGroupMsg, METH_VARARGS , ""},
 //{ "sendLike"            ,py_sendLike, METH_VARARGS ,"" },
 //{ "sendPrivateMsg"      ,py_sendPrivateMsg, METH_VARARGS , ""},
 //{ "setDiscussLeave"     ,py_setDiscussLeave, METH_VARARGS , ""},
 //{ "setFriendAddRequest" ,py_setFriendAddRequest, METH_VARARGS ,"" },
 //{ "setGroupAddRequest"  ,py_setGroupAddRequest, METH_VARARGS , ""},
 //{ "setGroupAdmin"       ,py_setGroupAdmin, METH_VARARGS ,"" },
 //{ "setGroupAnonymous"   ,py_setGroupAnonymous, METH_VARARGS ,"" },
 //{ "setGroupAnonymousBan",py_setGroupAnonymousBan, METH_VARARGS , ""},
 //{ "setGroupBan"         ,py_setGroupBan, METH_VARARGS ,"" },
 //{ "setGroupCard"        ,py_setGroupCard, METH_VARARGS , ""},
 //{ "setGroupKick"        ,py_setGroupKick, METH_VARARGS , ""},
 //{ "setGroupLeave"       ,py_setGroupLeave, METH_VARARGS ,"" },
 //{ "setGroupSpecialTitle",py_setGroupSpecialTitle, METH_VARARGS , ""},
 //{ "setGroupWholeBan"    ,py_setGroupWholeBan, METH_VARARGS ,"" },

 { NULL                  , NULL,0,NULL },
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