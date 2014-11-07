#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"


class CAppHBAAnalyzerPlayer : public CWinApp {

public:
	CAppHBAAnalyzerPlayer();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	DECLARE_MESSAGE_MAP()
};

extern CAppHBAAnalyzerPlayer theApp;