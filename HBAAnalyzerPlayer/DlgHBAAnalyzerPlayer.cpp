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
    DDX_Control(pDX, IDC_BN_FILE_LIST, m_bnFileList);
    DDX_Control(pDX, IDC_BN_FILE_OPEN, m_bnFileOpen);
    DDX_Control(pDX, IDC_BN_CONFIGURE, m_bnConfigure);
    DDX_Control(pDX, IDC_BN_PLAYBACK, m_bnPlayback);
    DDX_Control(pDX, IDC_BN_STOP, m_bnStop);
    DDX_Control(pDX, IDC_BN_PREV_FRAME, m_bnPrevFrame);
    DDX_Control(pDX, IDC_BN_NEXT_FRAME, m_bnNextFrame);
    DDX_Control(pDX, IDC_BN_REWIND, m_bnRewind);
    DDX_Control(pDX, IDC_BN_FORWARD, m_bnForward);
    DDX_Control(pDX, IDC_BN_PREV_FILE, m_bnPrevFile);
    DDX_Control(pDX, IDC_BN_NEXT_FILE, m_bnNextFile);
}


BOOL CDlgHBAAnalyzerPlayer::OnInitDialog() {

    CDialog::OnInitDialog();

    SetIcon(m_hIcon, TRUE);
    SetIcon(m_hIcon, FALSE);

    Initialize();

    return TRUE;
}


BOOL CDlgHBAAnalyzerPlayer::PreTranslateMessage(MSG* pMsg) {

    if (pMsg->message == WM_KEYDOWN) {

        switch (pMsg->wParam) {

        case VK_RETURN :
            return TRUE;

        case VK_ESCAPE :
            return TRUE;

        case VK_SPACE :
            return TRUE;

        case VK_UP :
            return TRUE;

        case VK_DOWN :
            return TRUE;

        case VK_LEFT :
            return TRUE;

        case VK_RIGHT :
            return TRUE;
        }
    }
/*
        case VK_LEFT :
            PostMessage(WM_COMMAND, MAKEWPARAM(IDC_BN_REWIND, BN_CLICKED));
            return TRUE;

        case VK_RIGHT :
            PostMessage(WM_COMMAND, MAKEWPARAM(IDC_BN_FAST_FORWARD, BN_CLICKED));
            return TRUE;

        case VK_UP :
            PostMessage(MSG_PLAYER_VOLUME_UP);
            return TRUE;

        case VK_DOWN :
            PostMessage(MSG_PLAYER_VOLUME_DOWN);
            return TRUE;

        case VK_ESCAPE :
        }
    }
    
    if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_SPACE) {

        //if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_SPACE)
        //    OnBnClickedBnPlayback();
        
        if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE) {

            if (theApp.m_stIniConfigure.m_bFullScreen) {

                theApp.m_stIniConfigure.m_bFullScreen = FALSE;
                ::SendMessage(theApp.m_hScreenDlg, MSG_SCREEN_FULL_SCREEN, 0, FALSE);
            }
            
            theApp.m_stIniConfigure.m_bAlwaysTopMost = FALSE;
            ::SendMessage(theApp.m_hScreenDlg, MSG_SCREEN_ALWAYS_TOP_MOST, 0, FALSE);
            BringWindowToTop();
        }
        return TRUE;
    }
*/

    return CDialog::PreTranslateMessage(pMsg);
}


BEGIN_MESSAGE_MAP(CDlgHBAAnalyzerPlayer, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_WM_DESTROY()
    ON_BN_CLICKED(IDC_BN_CLOSE, &CDlgHBAAnalyzerPlayer::OnBnClickedBnClose)
    ON_BN_CLICKED(IDC_BN_MINIMIZE, &CDlgHBAAnalyzerPlayer::OnBnClickedBnMinimize)
    ON_WM_NCHITTEST()
    ON_BN_CLICKED(IDC_BN_FILE_LIST, &CDlgHBAAnalyzerPlayer::OnBnClickedBnFileList)
    ON_BN_CLICKED(IDC_BN_FILE_OPEN, &CDlgHBAAnalyzerPlayer::OnBnClickedBnFileOpen)
    ON_BN_CLICKED(IDC_BN_CONFIGURE, &CDlgHBAAnalyzerPlayer::OnBnClickedBnConfigure)
    ON_BN_CLICKED(IDC_BN_PLAYBACK, &CDlgHBAAnalyzerPlayer::OnBnClickedBnPlayback)
    ON_BN_CLICKED(IDC_BN_STOP, &CDlgHBAAnalyzerPlayer::OnBnClickedBnStop)
    ON_BN_CLICKED(IDC_BN_PREV_FRAME, &CDlgHBAAnalyzerPlayer::OnBnClickedBnPrevFrame)
    ON_BN_CLICKED(IDC_BN_NEXT_FRAME, &CDlgHBAAnalyzerPlayer::OnBnClickedBnNextFrame)
    ON_BN_CLICKED(IDC_BN_REWIND, &CDlgHBAAnalyzerPlayer::OnBnClickedBnRewind)
    ON_BN_CLICKED(IDC_BN_FORWARD, &CDlgHBAAnalyzerPlayer::OnBnClickedBnForward)
    ON_BN_CLICKED(IDC_BN_PREV_FILE, &CDlgHBAAnalyzerPlayer::OnBnClickedBnPrevFile)
    ON_BN_CLICKED(IDC_BN_NEXT_FILE, &CDlgHBAAnalyzerPlayer::OnBnClickedBnNextFile)
END_MESSAGE_MAP()


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


LRESULT CDlgHBAAnalyzerPlayer::OnNcHitTest(CPoint point) {
    
    CRect rect(0, 0, MAX_MAIN_DIALOG_WIDTH, MAX_CAPTION_HEIGHT);

    ScreenToClient(&point);
    if (PtInRect(&rect, point))
        return HTCAPTION;

    return CDialog::OnNcHitTest(point);
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


void CDlgHBAAnalyzerPlayer::OnBnClickedBnFileList() {
    // TODO: Add your control notification handler code here
}


void CDlgHBAAnalyzerPlayer::OnBnClickedBnFileOpen() {
    // TODO: Add your control notification handler code here
}


void CDlgHBAAnalyzerPlayer::OnBnClickedBnConfigure() {
    // TODO: Add your control notification handler code here
}


void CDlgHBAAnalyzerPlayer::OnBnClickedBnPlayback() {
    // TODO: Add your control notification handler code here
}


void CDlgHBAAnalyzerPlayer::OnBnClickedBnStop() {
    // TODO: Add your control notification handler code here
}


void CDlgHBAAnalyzerPlayer::OnBnClickedBnPrevFrame() {
    // TODO: Add your control notification handler code here
}


void CDlgHBAAnalyzerPlayer::OnBnClickedBnNextFrame() {
    // TODO: Add your control notification handler code here
}


void CDlgHBAAnalyzerPlayer::OnBnClickedBnRewind() {
    // TODO: Add your control notification handler code here
}


void CDlgHBAAnalyzerPlayer::OnBnClickedBnForward() {
    // TODO: Add your control notification handler code here
}


void CDlgHBAAnalyzerPlayer::OnBnClickedBnPrevFile() {
    // TODO: Add your control notification handler code here
}


void CDlgHBAAnalyzerPlayer::OnBnClickedBnNextFile() {
    // TODO: Add your control notification handler code here
}


void CDlgHBAAnalyzerPlayer::Initialize() {

    InitBackground();

    m_bnClose.SetButton(IDB_BN_CLOSE, L"종료");
    m_bnClose.MoveWindow(MAX_MAIN_DIALOG_WIDTH-30, 5, 17, 17);

    m_bnMinimize.SetButton(IDB_BN_MINIMIZE, L"최소화");
    m_bnMinimize.MoveWindow(MAX_MAIN_DIALOG_WIDTH-50, 5, 17, 17);

    InitPlayerControl();
}


void CDlgHBAAnalyzerPlayer::Destroy() {

    DestroyPlayerControl();
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

    /* Playback Button */
    m_bnPlayback.SetButton(IDB_BN_PLAY, L"재생");
    m_bnPlayback.MoveWindow(RT_BUTTON_PLAYBACK);

    /* Stop Button */
    m_bnStop.SetButton(IDB_BN_STOP, L"정지");
    m_bnStop.MoveWindow(RT_BUTTON_STOP);

    /* Previous Frame Button */
    m_bnPrevFrame.SetButton(IDB_BN_PREV_FRAME, L"이전 프레임");
    m_bnPrevFrame.MoveWindow(RT_BUTTON_PREV_FRAME);

    /* Next Frame Button */
    m_bnNextFrame.SetButton(IDB_BN_NEXT_FRAME, L"다음 프레임");
    m_bnNextFrame.MoveWindow(RT_BUTTON_NEXT_FRAME);

    /* Rewind Button */
    m_bnRewind.SetButton(IDB_BN_REWIND, L"되감기 (-15초)");
    m_bnRewind.MoveWindow(RT_BUTTON_REWIND);

    /* Forward Button */
    m_bnForward.SetButton(IDB_BN_FORWARD, L"빨리감기 (+15초)");
    m_bnForward.MoveWindow(RT_BUTTON_FORWARD);

    /* Previous File Button */
    m_bnPrevFile.SetButton(IDB_BN_PREV_FILE, L"이전 파일 재생");
    m_bnPrevFile.MoveWindow(RT_BUTTON_PREV_FILE);

    /* Next File Button */
    m_bnNextFile.SetButton(IDB_BN_NEXT_FILE, L"다음 파일 재생");
    m_bnNextFile.MoveWindow(RT_BUTTON_NEXT_FILE);

    /* File Open Button */
    m_bnFileOpen.SetButton(IDB_BN_FILE_OPEN, L"파일 열기");
    m_bnFileOpen.MoveWindow(RT_BUTTON_FILE_OPEN);

    /* Configure Button */
    m_bnConfigure.SetButton(IDB_BN_CONFIGURE, L"설정");
    m_bnConfigure.MoveWindow(RT_BUTTON_CONFIGURE);
}


void CDlgHBAAnalyzerPlayer::DestroyPlayerControl() {

}
