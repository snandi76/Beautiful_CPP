
// TestCodeDlg.h : header file
//

#pragma once
CString GetBinStr(CString BinStr);
CString GetOnesComplement(CString strBin);
CString GetTwosComplement(CString strBin1);
// CTestCodeDlg dialog
class CTestCodeDlg : public CDialogEx
{
// Construction
public:
	CTestCodeDlg(CWnd* pParent = NULL);	// standard constructor


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTCODE_DIALOG };
#endif

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
	void TestFunc(int parram1, int param2 = 20);
		void TestFunc(int parram1);

};
