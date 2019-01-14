// ConsoleApplication17_app.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<Windows.h>
#include"ConsoleApplication_testdll.h"
typedef void(*DLLPROC) (int *p);

int main()
{
	HINSTANCE hinstDLL;
	DLLPROC HelloWorld;
	BOOL fFreeDLL;

	hinstDLL = LoadLibrary(_T("ConsoleApplication_testdll.dll"));

	if (hinstDLL != NULL)
	{
		HelloWorld = (DLLPROC)GetProcAddress(hinstDLL, "HelloWorld");

		if (HelloWorld != NULL)
		{ 
			int *p = NULL;
			HelloWorld(p);
		}
		fFreeDLL = FreeLibrary(hinstDLL);
	}
	return 0;
}

