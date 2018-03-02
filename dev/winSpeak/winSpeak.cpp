#include "..\..\inculde\winSpeak.h"

#include "sapi.h"
#include "sphelper.h"
#pragma comment(lib, "sapi.lib")

#include <iostream>

using namespace std;

wchar_t*TW(string file) {
	USES_CONVERSION;
	wchar_t*t = A2W(file.c_str());
	wchar_t*w = new wchar_t[wcslen(t) + 1];
	wcscpy(w, t);
	return w;
}

ISpVoice *pISpVoice;//讲述人接口

bool Speak_init() {
	if (!pISpVoice)
	{
		// 重要COM接口
		::CoInitialize(NULL);

		// 获取ISpVoice接口
		CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_INPROC_SERVER, IID_ISpVoice, (void**)&pISpVoice);

		return pISpVoice;
	}
	return true;
}

bool Speak_to_wav_file(string file, string wantSay) {
	bool res = false;

	auto _file = TW(file);
	auto _wantSay = TW(wantSay);

	CSpStreamFormat OriginalFmt;//创建一个输出流，绑定到wav文件
	CComPtr<ISpStream> cpWavStream;//wav音频流
	CComPtr<ISpStreamFormat> cpOldStream;//旧的流

	HRESULT hr = pISpVoice->GetOutputStream(&cpOldStream);
	if (hr == S_OK)
	{
		hr = OriginalFmt.AssignFormat(cpOldStream);

		if (SUCCEEDED(hr))
		{
			// 使用sphelper.h中提供的函数创建 wav 文件
			hr = SPBindToFile(_file, SPFM_CREATE_ALWAYS, &cpWavStream, &OriginalFmt.FormatId(), OriginalFmt.WaveFormatExPtr());

			if (SUCCEEDED(hr))
			{
				//设置声音的输出到 wav 文件，而不是 speakers
				pISpVoice->SetOutput(cpWavStream, TRUE);

				//开始朗读
				pISpVoice->Speak(_wantSay, SPF_IS_NOT_XML, 0);

				//把流设置回去
				pISpVoice->SetOutput(cpOldStream, FALSE);

				cpWavStream.Release();

				res = true;
			}
			else {
				cout << "SPBindToFile" << endl;
			}
		}
		else {
			cout << "OriginalFmt.AssignFormat(cpOldStream)" << endl;
		}
	}
	else {
		cout << "GetOutputStream" << endl;
	}

	return res;
}