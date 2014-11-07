#pragma once

#include "resource.h"


class CDlgHBAAnalyzerPlayer : public CDialog {

private:
    HICON m_hIcon;

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
	DECLARE_MESSAGE_MAP()
};
