// ConsoleApplication_testdll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "stdafx.h"
#include<iostream>
#define EXPORTING_DLL
#include "ConsoleApplication_testdll.h"

//BOOL APIENTRY DllMain(HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
//{
//	return TRUE;
//}
#ifdef __cplusplus
extern "C" {
#endif
	void HelloWorld(int *p)
	{
		//MessageBox(NULL, TEXT("Hello World"),
		//	TEXT("In a DLL"), MB_OK);

		std::cout << "Test output";
		*p = 10;
		/*return 10;*/
	}

#ifdef __cplusplus
}
#endif