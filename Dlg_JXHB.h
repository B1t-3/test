#pragma once

class CEap_JXHB;
// CDlg_JXHB 对话框

class CDlg_JXHB : public CDialog
{
	DECLARE_DYNAMIC(CDlg_JXHB)

public:
	CDlg_JXHB(CEap_JXHB *pEap, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlg_JXHB();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_JXHB };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()


public:
	CString m_sDBPassword;
	CString m_sDBTable;
	CString m_sDBUserName;
	int m_iDBPort;
	DWORD m_dIp;
	CString m_sMacID;
	CString m_sMacName;
	CString m_sOperator;

	afx_msg void OnBnClickedButtonConnectDb();

	CEap_JXHB *m_pEap_JXHB;

	DWORD m_dMesPostIP;
	int m_iMesPostPort;
	CString m_sBelongFactory;

	int m_iSeverPort;
	DWORD m_dSeverAddrIP;
	CString m_sSaveImagePath;
};
