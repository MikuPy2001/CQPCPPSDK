#pragma once

#include <memory>

//gbk转UTF-8
//回传的char*自行销毁
std::shared_ptr<char*> U(const char* strGbk);//传入的strGbk是GBK编码
//UTF-8转gbk
//回传的char*自行销毁
std::shared_ptr<char*> G(const char* strUtf8);//传入的strUtf8是UTF-8编码

//gbk转UTF-8
//回传的char*自行销毁
char* _U(const char* strGbk);//传入的strGbk是GBK编码
//UTF-8转gbk
//回传的char*自行销毁
char* _G(const char* strUtf8);//传入的strUtf8是UTF-8编码