#include "stdafx.h"
#include "AppHBAAnalyzerPlayer.h"
#include "DlgHBAAnalyzerPlayer.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CDlgHBAAnalyzerPlayer::CDlgHBAAnalyzerPlayer(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgHBAAnalyzerPlayer::IDD, pParent) {
	
    EnableActiveAccessibility();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


void CDlgHBAAnalyzerPlayer::DoDataExchange(CDataExchange* pDX) {
	
    CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgHBAAnalyzerPlayer, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


BOOL CDlgHBAAnalyzerPlayer::OnInitDialog() {
	
    CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	return TRUE;
}


void CDlgHBAAnalyzerPlayer::OnPaint() {
	
    if (IsIconic()) {
		
        CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	} else {
		
        CDialog::OnPaint();
	}
}


HCURSOR CDlgHBAAnalyzerPlayer::OnQueryDragIcon() {
	
    return static_cast<HCURSOR>(m_hIcon);
}

