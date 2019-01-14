
// MFCServer.h : main header file for the MFCServer application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols
//#include "MFCServerView.h"
#include "ServerSocket.h"
#include "MFCServerView.h"

// CMFCServerApp:
// See MFCServer.cpp for the implementation of this class
//

class CMFCServerApp : public CWinAppEx
{
public:
	CMFCServerApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	CServerSocket m_serverSocket;
	CMFCServerView *m_pServerView;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCServerApp theApp;
