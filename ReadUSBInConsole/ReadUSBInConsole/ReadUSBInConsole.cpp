// ReadUSBInConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include<iostream>
#include <bitset>

void bin(int n)
{
	static int ncount = 0;
	unsigned i;
	for (i = 1 << 31; i > 0; i = i / 2)
	{
		(n & i) ? printf("1") : printf("0");
		ncount++;
	}
}

int main()
{
	int dwList = GetLogicalDrives();
	if (dwList == 0)
	{
		printf("Error is %d\n", GetLastError());
	}
	else 
	{
		bin(dwList);
	}
    return 0;
}

