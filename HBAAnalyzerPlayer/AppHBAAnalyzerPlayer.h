#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"

#define MAX_CAPTION_HEIGHT                  25

#define MAX_MAIN_DIALOG_WIDTH               500
#define MAX_MAIN_DIALOG_HEIGHT              440

#define MAX_FILE_LIST_DIALOG_WIDTH          334
#define MAX_FILE_LIST_DIALOG_HEIGHT         MAX_MAIN_DIALOG_HEIGHT

#define MAX_SETUP_DIALOG_WIDTH              240
#define MAX_SETUP_DIALOG_HEIGHT             200

#define RT_BUTTON_PLAYBACK                  CRect(6, 389, 6+50, 389+49)
#define RT_BUTTON_STOP                      CRect(56, 394, 56+37, 394+38)
#define RT_BUTTON_PREV_FRAME                CRect(93, 394, 93+37, 394+38)
#define RT_BUTTON_NEXT_FRAME                CRect(130, 394, 130+37, 394+38)
#define RT_BUTTON_REWIND                    CRect(167, 394, 167+37, 394+38)
#define RT_BUTTON_FORWARD                   CRect(204, 394, 204+37, 394+38)
#define RT_BUTTON_PREV_FILE                 CRect(241, 394, 241+37, 394+38)
#define RT_BUTTON_NEXT_FILE                 CRect(278, 394, 278+37, 394+38)
#define RT_BUTTON_FILE_OPEN                 CRect(404, 391, 404+45, 391+45)
#define RT_BUTTON_CONFIGURE                 CRect(451, 391, 451+45, 391+43)


class CAppHBAAnalyzerPlayer : public CWinApp {

public:
	CAppHBAAnalyzerPlayer();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	DECLARE_MESSAGE_MAP()
};

extern CAppHBAAnalyzerPlayer theApp;