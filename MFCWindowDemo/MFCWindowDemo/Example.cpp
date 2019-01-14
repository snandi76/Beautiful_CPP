#include <afxwin.h>
#include "resource.h"

class CExample : public CWinApp {
public:
	BOOL InitInstance();
};

class CExampleDlg : public CDialog {
public:
	enum { IDD = IDD_DIALOG_EXAMPLE };

	CExampleDlg();
	~CExampleDlg();
};

CExampleDlg::CExampleDlg() :CDialog(CExampleDlg::IDD) {

}

CExampleDlg::~CExampleDlg() {

}

BOOL CExample::InitInstance() {
	CExampleDlg myDlg;
	m_pMainWnd = &myDlg;
	myDlg.DoModal();
	return TRUE;
}
CExample MyApp;