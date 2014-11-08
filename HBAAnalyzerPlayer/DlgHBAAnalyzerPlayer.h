#pragma once

#include "resource.h"
#include "CtlBitmapButton.h"


class CDlgHBAAnalyzerPlayer : public CDialog {

private:
    void                Initialize();
    void                Destroy();
    void                InitBackground();
    void                DestroyBackground();
    void                InitScreen();
    void                DestroyScreen();
    void                InitFileList();
    void                DestroyFileList();
    void                InitPlayerControl();
    void                DestroyPlayerControl();

private:
    HICON               m_hIcon;
    CDC                 m_dcBackground;
    CBitmap             m_bmpBackground;
    CCtlBitmapButton    m_bnClose,
                        m_bnMinimize,
                        m_bnFileList,
                        m_bnFileOpen,
                        m_bnConfigure,
                        m_bnPlayback,
                        m_bnStop,
                        m_bnPrevFrame,
                        m_bnNextFrame,
                        m_bnRewind,
                        m_bnForward,
                        m_bnPrevFile,
                        m_bnNextFile;

public:
	CDlgHBAAnalyzerPlayer(CWnd* pParent = NULL);

	enum {
        IDD = IDD_HBAANALYZERPLAYER_DIALOG
    };

protected:
	virtual void        DoDataExchange(CDataExchange* pDX);
	virtual BOOL        OnInitDialog();
    virtual BOOL        PreTranslateMessage(MSG* pMsg);
	afx_msg void        OnPaint();
	afx_msg HCURSOR     OnQueryDragIcon();
    afx_msg void        OnDestroy();
    afx_msg LRESULT     OnNcHitTest(CPoint point);
    afx_msg void        OnBnClickedBnClose();
    afx_msg void        OnBnClickedBnMinimize();
    afx_msg void        OnBnClickedBnFileList();
    afx_msg void        OnBnClickedBnFileOpen();
    afx_msg void        OnBnClickedBnConfigure();
    afx_msg void        OnBnClickedBnPlayback();
    afx_msg void        OnBnClickedBnStop();
    afx_msg void        OnBnClickedBnPrevFrame();
    afx_msg void        OnBnClickedBnNextFrame();
    afx_msg void        OnBnClickedBnRewind();
    afx_msg void        OnBnClickedBnForward();
    afx_msg void        OnBnClickedBnPrevFile();
    afx_msg void        OnBnClickedBnNextFile();
    DECLARE_MESSAGE_MAP()
public:

};
