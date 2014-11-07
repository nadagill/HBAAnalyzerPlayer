
// DlgHBAAnalyzerPlayer.h : header file
//

#pragma once


// CDlgHBAAnalyzerPlayer dialog
class CDlgHBAAnalyzerPlayer : public CDialog
{
// Construction
public:
	CDlgHBAAnalyzerPlayer(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_HBAANALYZERPLAYER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
