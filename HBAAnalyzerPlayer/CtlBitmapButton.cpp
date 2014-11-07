#include "stdafx.h"
#include "CtlBitmapButton.h"


IMPLEMENT_DYNAMIC(CCtlBitmapButton, CBitmapButton)

CCtlBitmapButton::CCtlBitmapButton()
    : m_bTracking(FALSE)
    , m_bHOver(FALSE)
    , m_bHoldPress(FALSE) {
}


CCtlBitmapButton::~CCtlBitmapButton() {
    
    m_bmpImage.DeleteObject();
}


void CCtlBitmapButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) {
    
    CRect rtClient;

    GetClientRect(&rtClient);

    CDC *pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
    CDC *pMemDC = new CDC;
    pMemDC->CreateCompatibleDC(pDC);

    CBitmap *pOldImage;
    pOldImage = pMemDC->SelectObject(&m_bmpImage);

    if (lpDrawItemStruct->itemState & ODS_DISABLED && m_nImageCnt >= 4) {

        pDC->TransparentBlt(0, 0, m_siImage.cx, m_siImage.cy, pMemDC, m_siImage.cx*3, 0, m_siImage.cx, m_siImage.cy, RGB(255, 0, 255));
    } else if (lpDrawItemStruct->itemState & ODS_SELECTED || m_bHoldPress) {

        pDC->TransparentBlt(0, 0, m_siImage.cx, m_siImage.cy, pMemDC, m_siImage.cx, 0, m_siImage.cx, m_siImage.cy, RGB(255, 0, 255));
    } else if (m_bHOver) {

        pDC->TransparentBlt(0, 0, m_siImage.cx, m_siImage.cy, pMemDC, m_siImage.cx*2, 0, m_siImage.cx, m_siImage.cy, RGB(255, 0, 255));
    } else {

        pDC->TransparentBlt(0, 0, m_siImage.cx, m_siImage.cy, pMemDC, 0, 0, m_siImage.cx, m_siImage.cy, RGB(255, 0, 255));
    }

    CString m_strWindowText;
    GetWindowText(m_strWindowText);
    if (!m_strWindowText.IsEmpty()) {

        pDC->SetBkMode(TRANSPARENT);
        pDC->SetTextColor(RGB(255,255,255));
        pDC->DrawText(m_strWindowText, rtClient, DT_SINGLELINE|DT_CENTER|DT_VCENTER);
    }

    pMemDC->SelectObject(pOldImage);
    pMemDC->DeleteDC();
    delete pMemDC;
}


void CCtlBitmapButton::PreSubclassWindow() {

    ModifyStyle(0, BS_OWNERDRAW);

    CBitmapButton::PreSubclassWindow();
}


BOOL CCtlBitmapButton::PreTranslateMessage(MSG* pMsg) {

    if (m_ToolTip.m_hWnd != NULL)
        m_ToolTip.RelayEvent(pMsg);

    return CBitmapButton::PreTranslateMessage(pMsg);
}


BEGIN_MESSAGE_MAP(CCtlBitmapButton, CBitmapButton)
    ON_WM_MOUSEHOVER()
    ON_WM_MOUSELEAVE()
    ON_WM_MOUSEMOVE()
    ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()


void CCtlBitmapButton::OnMouseHover(UINT nFlags, CPoint point) {
    
    m_bHOver = TRUE;
    Invalidate(FALSE);

    CBitmapButton::OnMouseHover(nFlags, point);
}


void CCtlBitmapButton::OnMouseLeave() {
    
    m_bTracking = FALSE;
    m_bHOver = FALSE;
    Invalidate(FALSE);

    CBitmapButton::OnMouseLeave();
}


void CCtlBitmapButton::OnMouseMove(UINT nFlags, CPoint point) {
    
    if (!m_bTracking) {

        TRACKMOUSEEVENT tme;

        tme.cbSize = sizeof(tme);
        tme.hwndTrack = m_hWnd;
        tme.dwFlags = TME_LEAVE|TME_HOVER;
        tme.dwHoverTime = 1;

        m_bTracking = _TrackMouseEvent(&tme);
    }

    CBitmapButton::OnMouseMove(nFlags, point);
}


void CCtlBitmapButton::OnLButtonDblClk(UINT nFlags, CPoint point) {
    
    SendMessage(WM_LBUTTONDOWN, nFlags, MAKELPARAM(point.x, point.y));

    CBitmapButton::OnLButtonDblClk(nFlags, point);
}


BOOL CCtlBitmapButton::SetBitmap(UINT nResID, int nImageCnt/* =3 */, CSize *pSize/* =NULL */) {
    
    BITMAP bmp;

    m_bmpImage.DeleteObject();
    if (!m_bmpImage.LoadBitmap(nResID))
        return FALSE;

    m_bmpImage.GetBitmap(&bmp);
    m_nImageCnt = nImageCnt;
    m_siImage.cx = bmp.bmWidth/m_nImageCnt;
    m_siImage.cy = bmp.bmHeight;

    if (pSize) {

        *pSize = m_siImage;
    }

    SetWindowPos(NULL, 0, 0, m_siImage.cx, m_siImage.cy, SWP_NOMOVE|SWP_NOOWNERZORDER);

    return TRUE;
}


void CCtlBitmapButton::SetToolTip(CString strText) {
    
    if (m_ToolTip.m_hWnd == NULL) {

        m_ToolTip.Create(this);
        m_ToolTip.Activate(TRUE);
    }

    if (m_ToolTip.GetToolCount() == 0) {

        CRect rtClient;

        GetClientRect(&rtClient);
        m_ToolTip.AddTool(this, strText, rtClient, 1);
    }

    m_ToolTip.UpdateTipText(strText, this, 1);
    m_ToolTip.Activate(TRUE);
}


BOOL CCtlBitmapButton::SetButton(UINT nResID, CString strToolTip/* ="" */, BOOL bInvalidate/* =TRUE */, int nImageCnt/* =3 */) {
    
    if (!SetBitmap(nResID, nImageCnt))
        return FALSE;

    SetToolTip(strToolTip);

    if (bInvalidate)
        Invalidate(FALSE);

    return TRUE;
}
