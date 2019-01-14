
// TestCodeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestCode.h"
#include "TestCodeDlg.h"
#include "afxdialogex.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestCodeDlg dialog

void TestFunc(int parram1, int param2=20)
{
	//MessageBoxW( _T"Two param" , NULL , MB_OK );
}
void TestFunc(int parram1)
{
	//MessageBoxW( _T"One param" , NULL , MB_OK );
}

CTestCodeDlg::CTestCodeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTCODE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestCodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestCodeDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CTestCodeDlg message handlers
CString GetTwosComplement(CString strBin1)
{
	CString strBin2 = NULL , strResult = NULL;
	unsigned int uilen = strBin1.GetLength();
	int carry = 1;
	for (int i = (uilen-1) ; i >= 0; i--)
	{
		 if (strBin1[i] == '1' && carry == 1) //10000111 1
		{
			 strResult += "0" ;
		}
		else if (strBin1[i] == '0' && carry == 1)
		{
			strResult += "1";
			carry = 0;
		}
		else
		{
			strResult += strBin1[i];
		}
		 
	}//end for
	strResult.MakeReverse();

	return strResult;
}

//input:Binary string
//output:Ones complement 

CString GetOnesComplement(CString strBin) 
{
	CString strOne = NULL;
	unsigned int uilen = strBin.GetLength();
	for (int i = 0; i<uilen; i++)
	{
		if (strBin[i] == '0')
		{
			strOne += "1";
		}
		else if (strBin[i] == '1')
		{
			strOne += "0";
		}
		else
		{//nothing 
		}
	}


	return strOne;
}

//input:String of Hex numbers
//output:Striong of Binary
CString GetBinStr(CString BinStr)
{
	CString strResult = NULL;
	unsigned int uiLength = BinStr.GetLength();
	for (int i = 0; i < uiLength; i++)
	{
		switch (BinStr[i])
		{
		case 'F':
		case 'f':
			strResult += "1111";
			break;
		case 'E':
		case 'e':
			strResult += "1110";
			break;
		case 'D':  
		case 'd':
			strResult += "1101";
			break;
		case 'C' :
		case 'c' :
			strResult += "1100";
			break;
		case 'B' :
		case 'b' :
			strResult += "1011";
			break;
		case 'A' :
		case'a'	 :
			strResult += "1010";
			break;
		case '9':
			strResult += "1001";
			break;
		case '8':
			strResult += "1000";
			break;
		case '7':
			strResult += "0111";
			break;
		case '6':
			strResult += "0110";
			break;
		case '5':
			strResult += "0101";
			break;
		case '4':
			strResult += "0100";
			break;
		case '3':
			strResult += "0011";
			break;
		case '2':
			strResult += "0010";
			break;
		case '1':
			strResult += "0001";
		case '0':
			strResult += "0000";
			break;
			
		}//end switch
		
	}//end for

	return strResult;
}

BOOL CTestCodeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	int param1 = 100;
	//TestFunc(param1);

	std::string strH = "1010";
	long n = strtol(strH.c_str(), NULL , 10);
	
	CString cstr = _T("FFFFFF88");
	CString strBin, strBin1, strBin2;
	//in case of 2's complement
	if (cstr[0] == 'F')
	{
		 strBin		= GetBinStr(cstr);//Getting Binary String
		 strBin1	= GetOnesComplement(strBin);
		 strBin2	= GetTwosComplement(strBin1);
	}

	CT2CA pszConvertedAnsiString(strBin2);
	std::string srtNew(pszConvertedAnsiString);

	long n1 = strtol(srtNew.c_str(), NULL, 2);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestCodeDlg::OnPaint()
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
HCURSOR CTestCodeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

