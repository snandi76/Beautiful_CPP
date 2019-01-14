
// PopUpWindowDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PopUpWindow.h"
#include "PopUpWindowDlg.h"
#include "afxdialogex.h"
#include "Example.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPopUpWindowDlg dialog



CPopUpWindowDlg::CPopUpWindowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_POPUPWINDOW_DIALOG, pParent)
	, m_CurrentTime(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPopUpWindowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TIMER, m_CurrentTime);
}

BEGIN_MESSAGE_MAP(CPopUpWindowDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CPopUpWindowDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CPopUpWindowDlg::OnBnClickedButton1)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CPopUpWindowDlg message handlers

BOOL CPopUpWindowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	SetTimer(1, 200, 0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPopUpWindowDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPopUpWindowDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPopUpWindowDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	
}


void CPopUpWindowDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	ASSERT(AfxGetMainWnd != NULL);
	AfxGetMainWnd()->SendMessage(WM_CLOSE);

}


void CPopUpWindowDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	CTime stCurrent = CTime::GetCurrentTime();
	unsigned int uiHours, uiMinutes, uiSeconds;
	uiHours		= stCurrent.GetHour();
	uiMinutes	= stCurrent.GetMinute();
	uiSeconds	= stCurrent.GetSecond();
	CString strHour, strMinutes, strsecond;
	if (uiHours < 10)
		strHour.Format(_T("0%d"), uiHours);
	else
		strHour.Format(_T("%d"), uiHours);

	if (uiMinutes < 10)
		strMinutes.Format(_T("0%d"), uiMinutes);
	else
		strMinutes.Format(_T("%d"), uiMinutes);


	if (uiSeconds < 10)
		strsecond.Format(_T("0%d"), uiSeconds);
	else
		strsecond.Format(_T("%d"), uiSeconds);
		m_CurrentTime = _T("sdsdsa");
	
	//m_CurrentTime.Format(_T("dsdsadsa"));
	//m_Test.Format(_T("%s:%s:%s"), strHour, strMinutes, strsecond);
	
	CDialogEx::OnTimer(nIDEvent);
	

}
