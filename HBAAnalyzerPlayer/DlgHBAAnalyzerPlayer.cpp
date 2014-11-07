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

    DDX_Control(pDX, IDC_BN_CLOSE, m_bnClose);
    DDX_Control(pDX, IDC_BN_MINIMIZE, m_bnMinimize);
}


BEGIN_MESSAGE_MAP(CDlgHBAAnalyzerPlayer, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_WM_DESTROY()
    ON_BN_CLICKED(IDC_BN_CLOSE, &CDlgHBAAnalyzerPlayer::OnBnClickedBnClose)
    ON_BN_CLICKED(IDC_BN_MINIMIZE, &CDlgHBAAnalyzerPlayer::OnBnClickedBnMinimize)
END_MESSAGE_MAP()


BOOL CDlgHBAAnalyzerPlayer::OnInitDialog() {
	
    CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

    Initialize();

	return TRUE;
}


void CDlgHBAAnalyzerPlayer::OnPaint() {
	
    CPaintDC dc(this);

    if (IsIconic()) {
		
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

        CRect rect;
        GetClientRect(&rect);
        dc.TransparentBlt(0, 0, rect.Width(), rect.Height(), &m_dcBackground, 0, 0, rect.Width(), rect.Height(), RGB(255,0,255));
	}
}


HCURSOR CDlgHBAAnalyzerPlayer::OnQueryDragIcon() {
	
    return static_cast<HCURSOR>(m_hIcon);
}


void CDlgHBAAnalyzerPlayer::OnDestroy() {
    
    CDialog::OnDestroy();

    Destroy();
}


void CDlgHBAAnalyzerPlayer::OnBnClickedBnClose() {
    
    CDialog::OnOK();
}


void CDlgHBAAnalyzerPlayer::OnBnClickedBnMinimize() {
    
    WINDOWPLACEMENT stWP;

    GetWindowPlacement(&stWP);
    stWP.showCmd = SW_SHOWMINIMIZED;
    SetWindowPlacement(&stWP);
}


void CDlgHBAAnalyzerPlayer::Initialize() {

    InitBackground();

    m_bnClose.SetButton(IDB_BN_CLOSE, L"종료");
    m_bnClose.MoveWindow(MAX_MAIN_DIALOG_WIDTH-30, 5, 17, 17);

    m_bnMinimize.SetButton(IDB_BN_MINIMIZE, L"최소화");
    m_bnMinimize.MoveWindow(MAX_MAIN_DIALOG_WIDTH-50, 5, 17, 17);
}


void CDlgHBAAnalyzerPlayer::Destroy() {

    DestroyBackground();
}


void CDlgHBAAnalyzerPlayer::InitBackground() {

    if (!m_bmpBackground.LoadBitmap(IDB_BG_MAIN))
        return;
    
    m_dcBackground.CreateCompatibleDC(GetDC());
    m_dcBackground.SelectObject(m_bmpBackground);
    m_dcBackground.SetBkMode(TRANSPARENT);
    
    MoveWindow(0, 0, MAX_MAIN_DIALOG_WIDTH, MAX_MAIN_DIALOG_HEIGHT);
    CenterWindow();
}


void CDlgHBAAnalyzerPlayer::DestroyBackground() {

    m_bmpBackground.DeleteObject();
    m_dcBackground.DeleteDC();
}


void CDlgHBAAnalyzerPlayer::InitScreen() {

}


void CDlgHBAAnalyzerPlayer::DestroyScreen() {

}


void CDlgHBAAnalyzerPlayer::InitFileList() {

}


void CDlgHBAAnalyzerPlayer::DestroyFileList() {

}


void CDlgHBAAnalyzerPlayer::InitPlayerControl() {

}


void CDlgHBAAnalyzerPlayer::DestroyPlayerControl() {

}
