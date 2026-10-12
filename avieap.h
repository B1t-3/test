// AviEap.h : AviEap DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include "EapDefine.h"


#if !defined(NO_HTTP)
#ifdef _DEBUG
#pragma comment(lib, "./../Bin/ReleaseLib64/RpcRT4.Lib")
#else
#pragma comment(lib, "./../Bin/DebugLib64/RpcRT4.Lib")
#endif
#endif
// CAviEapApp
// 有关此类实现的信息，请参阅 AviEap.cpp
//

class CAviEapApp : public CWinApp
{
public:
	CAviEapApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
