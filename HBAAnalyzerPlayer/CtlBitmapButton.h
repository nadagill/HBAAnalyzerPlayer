#pragma once


class CCtlBitmapButton : public CBitmapButton {
	
    DECLARE_DYNAMIC(CCtlBitmapButton)

public:
	CCtlBitmapButton();
	virtual ~CCtlBitmapButton();

protected:
    virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
    virtual void PreSubclassWindow();
    virtual BOOL PreTranslateMessage(MSG* pMsg);
	DECLARE_MESSAGE_MAP()

protected:
    afx_msg void OnMouseHover(UINT nFlags, CPoint point);
    afx_msg void OnMouseLeave();
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);


public:
    BOOL SetBitmap(UINT nResID, int nImageCnt=3, CSize *pSize=NULL);
    void SetToolTip(CString strText);
    BOOL SetButton(UINT nResID, CString strToolTip=L"", BOOL bInvalidate=TRUE, int nImageCnt=3);
    void SetHoldPress(BOOL bHoldPress=TRUE) { m_bHoldPress = bHoldPress, Invalidate(FALSE); }
    BOOL IsHoldPress() { return m_bHoldPress; }

protected:
    CBitmap         m_bmpImage;
    CToolTipCtrl    m_ToolTip;
    CSize           m_siImage;
    int             m_nImageCnt;
    BOOL            m_bTracking;
    BOOL            m_bHOver;
    BOOL            m_bHoldPress;
};


