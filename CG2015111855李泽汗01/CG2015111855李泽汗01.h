
// CG2015111855李泽汗01.h: CG2015111855李泽汗01 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CCG2015111855李泽汗01App:
// 有关此类的实现，请参阅 CG2015111855李泽汗01.cpp
//

class CCG2015111855李泽汗01App : public CWinAppEx
{
public:
	CCG2015111855李泽汗01App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCG2015111855李泽汗01App theApp;
