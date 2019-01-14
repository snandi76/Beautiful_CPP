#pragma once


// CProoPage2 dialog

class CProoPage2 : public CDialogEx
{
	DECLARE_DYNAMIC(CProoPage2)

public:
	CProoPage2(CWnd* pParent = NULL);   // standard constructor
	virtual ~CProoPage2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROPPAGE_2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
