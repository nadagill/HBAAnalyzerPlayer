#pragma once

#include "resource.h"
#include "CtlBitmapButton.h"


class CDlgHBAAnalyzerPlayer : public CDialog {

private:
    void Initialize();
    void Destroy();
    void InitBackground();
    void DestroyBackground();
    void InitScreen();
    void DestroyScreen();
    void InitFileList();
    void DestroyFileList();
    void InitPlayerControl();
    void DestroyPlayerControl();

private:
    HICON   m_hIcon;
    CDC     m_dcBackground;
    CBitmap m_bmpBackground;
    CCtlBitmapButton m_bnClose,
                     m_bnMinimize,
                     m_bnFileList;

public:
	CDlgHBAAnalyzerPlayer(CWnd* pParent = NULL);

	enum {
        IDD = IDD_HBAANALYZERPLAYER_DIALOG
    };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnDestroy();
	DECLARE_MESSAGE_MAP()
public:
    
    afx_msg void OnBnClickedBnClose();
    afx_msg void OnBnClickedBnMinimize();
};
