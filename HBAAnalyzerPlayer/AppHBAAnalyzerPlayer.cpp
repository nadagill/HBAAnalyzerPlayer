#include "stdafx.h"
#include "AppHBAAnalyzerPlayer.h"
#include "DlgHBAAnalyzerPlayer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


BEGIN_MESSAGE_MAP(CAppHBAAnalyzerPlayer, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


CAppHBAAnalyzerPlayer::CAppHBAAnalyzerPlayer() {
	
    m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}


CAppHBAAnalyzerPlayer theApp;


BOOL CAppHBAAnalyzerPlayer::InitInstance() {

    INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	if (!AfxSocketInit()) {
		
        AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	if (!AfxOleInit()) {
		
        AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	CShellManager *pShellManager = new CShellManager;

	SetRegistryKey(_T("HBA Analyzer Player Application"));

	CDlgHBAAnalyzerPlayer dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK) {
	} else if (nResponse == IDCANCEL)	{
	}

	if (pShellManager != NULL) {

        delete pShellManager;
	}

	return FALSE;
}


int CAppHBAAnalyzerPlayer::ExitInstance() {
	
    AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}
