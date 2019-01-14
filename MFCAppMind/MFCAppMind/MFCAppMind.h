
// MFCAppMind.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCAppMindApp:
// See MFCAppMind.cpp for the implementation of this class
//

class CMFCAppMindApp : public CWinApp
{
public:
	CMFCAppMindApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCAppMindApp theApp;