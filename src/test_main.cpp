
#include "CQSDK\Unpack.h"
#include "CQSDK/CQTools.h"
#include "sqlite/sqlite3.h"
#include "sqlite/sqlitetool.h"
#include "ini/INItool.h"
#include "CQSDK\CQEVE_Status.h"

#include <iostream>
#include <atlbase.h>
#include <thread>

#include <Windows.h>
using namespace std;
using namespace CQ;

void sqlite_test();
void ini_test();
void unpack_test();
void main() {
	//sqlite_test();
	//    ini_test();
	//    unpack_test();

	cin.get();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

/*
void unpack_test()
{
cout << "unpack_test" << endl;
auto msg1 = "AAAAAAAPQkMAA0JZMgAoqB7sRA+yXhCpbcJQOu2dcQyaZu7ZbH79b74nQDlKY2p7TkWXXahTeQ==";
auto msg2 = base64_decode(msg1);
cout << "解码后的原始数据: ";
show((void*)msg2.data(), msg2.size());
Unpack p(msg2);
cout << p.getLong() << endl;
cout << p.getstring().c_str() << endl;
}
void ini_test()
{
cout << "ini_test" << endl;

ini::INItool ini("../test.ini");
cout << ini << endl << endl;

ini::INItool ini2;
ini2["1"]["2"] = "3";
cout << ini2 << endl << endl;

cout << string(ini["段2"]["键"]).c_str();
}
*/

//time系列函数需要的
LARGE_INTEGER LARGE_st, LARGE_end, nFreq;
decltype(GetCycleCount()) cputime_st, cputime_end;
HANDLE consolehwnd;

inline void time_init() {
	QueryPerformanceFrequency(&nFreq);
	consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);//实例化句柄
}
inline void time_bfb(int len,int jd) {
	if (jd!=0 && len%jd != 0)return;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(consolehwnd, &csbi);//获取当前坐标

	cout << "进度: " << len;

	SetConsoleCursorPosition(consolehwnd, csbi.dwCursorPosition);//回到历史坐标
}
inline void time_st() {
	QueryPerformanceCounter(&LARGE_st);
	cputime_st = GetCycleCount();
}
inline void time_end(int len=0) {

	cputime_end = GetCycleCount(); 
	QueryPerformanceCounter(&LARGE_end);
	auto dt = (LARGE_end.QuadPart - LARGE_st.QuadPart) / (double)nFreq.QuadPart ;
	dt *= 1000;//ms


	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(consolehwnd, &csbi);
	WORD colorOld = csbi.wAttributes;

	cout << "耗时: ";
	SetConsoleTextAttribute(consolehwnd, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	cout << cputime_end - cputime_st;
	SetConsoleTextAttribute(consolehwnd, colorOld);
	cout << "(";
	SetConsoleTextAttribute(consolehwnd, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	cout << dt;
	SetConsoleTextAttribute(consolehwnd, colorOld);
	cout << "ms)";

	if (len != 0) {
		cout << "(";
		SetConsoleTextAttribute(consolehwnd, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		cout << dt / len;
		SetConsoleTextAttribute(consolehwnd, colorOld);
		cout << "ms/每条)";
	}
	cout << endl;

}
void sqlite_test()
{
	cout << "sqlite测试项目里" << endl << endl;
	//插入次数
	auto file = 
	"";  
	// "sql.db";
	int lll = 100000;
	//初始化
	remove(file);

	sqlite3* db;
	sqlite3_stmt * stmt;

	auto create = "CREATE TABLE COMPANY(a TEXT,b TEXT)",
		insert = "INSERT INTO COMPANY (a,b) VALUES (123 , 456)",
		prepare_ = "INSERT INTO COMPANY VALUES (?,?)";
	auto
		BEGIN = U("BEGIN"),//事务开始
		COMMIT = U("COMMIT"),//事务结束
		CREATE = U(create),
		INSERT = U(insert),
		prepare = U(prepare_),
		t = U("123");
	auto len = strlen(t);
	int re;

	time_init();

	//cpu执行周期
	cout << "执行  for (int i = 0; i < 10000; ++i);" << endl;
	time_st(); {
		for (int i = 0; i < 10000; ++i);
	}
	time_end();


	//数据库连接
	cout << endl
		<< "打开数据库" << endl
		<< "文件地址:" << file << endl
		<< "sqlite3_open(...); " << endl;
	time_st();
	{
		auto re = sqlite3_open(file, &db);
		if (re != SQLITE_OK) { cout << "数据库连接出错: " << G(sqlite3_errmsg(db)) << endl; return; }
	}
	time_end();

	//建表
	cout << endl
		<< "建表: sqlite3_exec(...);" << endl
		<< "T-SQL: CREATE TABLE COMPANY(a TEXT,b TEXT);" << endl;
	time_st();
	{
		re=sqlite3_exec(db, CREATE, nullptr, 0, nullptr); if (re != SQLITE_OK) { cout << "数据库建立失败: " << G(sqlite3_errmsg(db)) << endl;  return;		}
	}
	time_end();

	//方法一,每次都完整执行插入方法
	cout << endl
		<< "方法一,每次都完整执行插入方法" << endl
		<< "sqlite3_exec(...);(" << lll << "次)" << endl
		<< insert << endl;
	time_st();
	{
		for (int i = 0; i < lll; ++i) {
			time_bfb(i, lll / 1000);
			 re = sqlite3_exec(db, INSERT, nullptr, 0, nullptr); if (re != SQLITE_OK) { cout << "数据插入失败(" << i << "): " << G(sqlite3_errmsg(db)) << endl; break; }
		}
	}
	time_end(lll);

	//方法二,每次都完整执行插入方法(事务)
	cout << endl
		<< "方法二,每次都完整执行插入方法(事务)" << endl
		<< "sqlite3_exec(...);(" << lll << "次)" << endl
		<< insert << endl;
	time_st();
	{
		re = sqlite3_exec(db, BEGIN, nullptr, 0, nullptr);if (re != SQLITE_OK) { cout << "事务打开失败!" << endl; }
		else {
			for (int i = 0; i < lll; ++i) {
				time_bfb(i, lll / 1000);
				re = sqlite3_exec(db, INSERT, nullptr, 0, nullptr); if (re != SQLITE_OK) { cout << "数据插入失败(" << i << "): " << G(sqlite3_errmsg(db)) << endl; break; }
			}
			sqlite3_exec(db, COMMIT, nullptr, 0, nullptr);
		}
	}
	time_end(lll);


	re = sqlite3_prepare_v2(db, prepare, strlen(prepare), &stmt, nullptr); if (re != SQLITE_OK) { cout << "语句准备失败: " << G(sqlite3_errmsg(db)) << endl; }
	re = sqlite3_bind_text(stmt, 1, t, len, nullptr); if (re != SQLITE_OK) { cout << "数据准备失败1: " << G(sqlite3_errmsg(db)) << endl; }
	re = sqlite3_bind_text(stmt, 2, t, len, nullptr); if (re != SQLITE_OK) { cout << "数据准备失败2: " << G(sqlite3_errmsg(db)) << endl; }
	//方法三,执行准备
	cout << endl
		<< "方法三,执行准备" << endl
		<< "sqlite3_prepare_v2;(" << lll << "次)" << endl
		<< prepare_ << endl;
	time_st();
	{
		for (int i = 0; i < lll; ++i) {
			time_bfb(i, lll / 1000);
			 re = sqlite3_step(stmt); if (re != SQLITE_DONE) { cout << "数据插入失败(" << i << "): " << G(sqlite3_errmsg(db)) << endl; break; }
		}
	}
	time_end(lll);

	//方法四,执行准备(事务)
	cout << endl
		<< "方法四,执行准备(事务)" << endl
		<< "sqlite3_prepare_v2;(" << lll << "次)" << endl
		<< prepare_ << endl;
	time_st();
	{
		re=sqlite3_exec(db, BEGIN, nullptr, 0, nullptr); if (re != SQLITE_OK) { cout << "事务打开失败!" << endl; }
		else {
			for (int i = 0; i < lll; ++i) {
				time_bfb(i, lll / 1000);
				re = sqlite3_step(stmt); if (re != SQLITE_DONE) { cout << "数据插入失败(" << i << "): " << G(sqlite3_errmsg(db)) << endl; break; }
			}
			sqlite3_exec(db, COMMIT, nullptr, 0, nullptr);
		}
	}
	time_end(lll);
	sqlite3_finalize(stmt);


	sqlite3_close(db);
}
