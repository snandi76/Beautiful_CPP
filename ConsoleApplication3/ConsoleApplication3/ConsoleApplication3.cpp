// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
char *strRev(char *strArg)
{
	char *strTemp;
	int iLen = 0;
	while (strArg[iLen] != '\0')
	{
		iLen++;
	}
	int count = 0;

	strTemp = (char*)malloc(sizeof(char)*iLen);

	for (int i = iLen; (i >= 0); i--)
	{

		if (strArg[i] != '\0')
		{

			strTemp[count] = strArg[i];
			char a = strArg[i];
			count++;
		}

		//*strTemp = strArg[iLen];
		//sstrTemp[count] = strArg[iLen];
	}
	return strTemp;
}
int main()
{
	char str[10] = "sunandan\0";
	char *strRevFinal;
	strRevFinal = strRev(str);
	free(strRevFinal);
	return 0;
}

