
// MFCCClient.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols

#include "ClientSocket.h"
// CMFCCClientApp:
// See MFCCClient.cpp for the implementation of this class
//

class CMFCCClientApp : public CWinApp
{
public:
	CMFCCClientApp();

// Overrides
public:
	virtual BOOL InitInstance();
	CClientSocket m_clientSocket;
// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCCClientApp theApp;