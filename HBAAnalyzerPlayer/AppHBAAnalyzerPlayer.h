#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"

#define MAX_CAPTION_HEIGHT          25

#define MAX_MAIN_DIALOG_WIDTH       500
#define MAX_MAIN_DIALOG_HEIGHT      440

#define MAX_FILE_LIST_DIALOG_WIDTH  334
#define MAX_FILE_LIST_DIALOG_HEIGHT MAX_MAIN_DIALOG_HEIGHT

#define MAX_SETUP_DIALOG_WIDTH      240
#define MAX_SETUP_DIALOG_HEIGHT     200


class CAppHBAAnalyzerPlayer : public CWinApp {

public:
	CAppHBAAnalyzerPlayer();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	DECLARE_MESSAGE_MAP()
};

extern CAppHBAAnalyzerPlayer theApp;