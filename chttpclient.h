// HttpClient.h: interface for the CHttpClient class.
//
/////////////////////////////////////////
#if !defined(AFX_HTTPCLIENT_H__8318EEA0_9921_4CE1_8E09_FC46AF7055CA__INCLUDED_)
#define AFX_HTTPCLIENT_H__8318EEA0_9921_4CE1_8E09_FC46AF7055CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include <string>
using namespace std;

class __declspec(dllexport) CHttpClient  
{
public:
	CHttpClient();
	virtual ~CHttpClient();

public:
	static int post(CString url,CString in,string &out);
	static int post_json(CString url,CString in,string &out);	
	static int get_info(CString url="");
	static int get_json(CString url,CString in,string &out);
	void GetToken(CString IP,CString User,CString Password, const CString& sFilePath);
	void httpWriteLog(CString content);
	static CString GetAppPath();
	static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream);
};

char* utf82gb2312(const char* utf8);

//std::string ANSItoUTF8(const char* strAnsi);
#endif 