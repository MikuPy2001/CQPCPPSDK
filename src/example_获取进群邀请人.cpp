#include <CQEVE_RequestAddGroup.h>
#include <CQMsgCode.h>

#include <string>

using namespace std;
using namespace CQ;

EVE_Request_AddGroup_EX(AddGroup) {
    if (eve.subType != 1)return;//不是别人请求入群，忽略
	
    MsgCode mc(eve.msg);//解析附言
	
    if (!mc.find("at"))return;//查找是否有酷q码:[CQ:at,qq=xxxx]
	
    string qq = mc.get("qq");//提取qq
}