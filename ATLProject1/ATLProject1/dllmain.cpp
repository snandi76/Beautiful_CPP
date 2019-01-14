// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "ATLProject1_i.h"
#include "dllmain.h"

CATLProject1Module _AtlModule;

class CATLProject1App : public CWinApp
{
public:

// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CATLProject1App, CWinApp)
END_MESSAGE_MAP()

CATLProject1App theApp;

BOOL CATLProject1App::InitInstance()
{
	return CWinApp::InitInstance();
}

int CATLProject1App::ExitInstance()
{
	return CWinApp::ExitInstance();
}
