// ConApp11_TEST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string.h>
#include <malloc.h>
int main()
{
	char *StrP = "Hello";
	int len = strlen(StrP);
	char *StrStk = (char*)malloc(len);
	int count = len - 1;
	StrStk[len] = '\0';
	for (int i = 0; i < len; i++)
		StrStk[count--] = StrP[i];
	printf("%s", StrStk);
    return 0;
}

