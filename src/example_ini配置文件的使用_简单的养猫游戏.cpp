#include <CQEVE.h>
#include <CQMsgCode.h>
#include <CQAPI_EX.h>

#include <string>
#include<thread>

using namespace std;
using namespace CQ;

//首先我们要明确插件的核心内容
//我们要编写一个养猫插件
//达到以下几点:

//用户发送[领养+名称]领养相应宠物
//发送[喂食]对宠物喂食,
//宠物有几率死亡
//发送红包复活

//写这个插件的目的在于配置的使用

//首先要导入配置文件的头文件
#include<INItool.h>
//然后引用对应的名字空间
using namespace ini;

//申明一个全局引用.
INItool pz;
int 标志;
thread*saveThread;
EVE_Enable(load) {
	//我们应该在插件加载的时候加载它
	pz = INItool(string(getAppDirectory()) + "data.ini");
	//然后我们每5分钟保存一次
	saveThread = new thread([] {
		while () {//这里先放着吧
			Sleep(5 * 60 * 1000);
			pz.save();
		}
	});
	saveThread->detach();

	return 0;
}
EVE_Disable(save) {
	//然后插件关闭的时候再保存一次.并且停用线程
	pz.save();
}