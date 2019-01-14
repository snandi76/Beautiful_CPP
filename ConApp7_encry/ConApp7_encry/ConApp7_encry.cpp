// ConApp7_encry.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include<map>
using namespace std;



string strMsg[26] = {
	"._",

	"_...",

	"_._.",

	"_..",

	".",

	".._.",

	"__.",

	"....",

	"..",

	".___",

	"_._",

	"._..",

	"__",

	"_.",

	"___",

	".__.",

	"__._",

	"._.",

	"...",

	"_",

	".._",

	"..._",

	".__",

	"_.._",

	"_.__",

	"__.."


};




int main()
{


	string strEn;
	cin >> strEn;
	vector<char> vecStack;

	string strStack = strEn;
	string strtemp;

	for (int i = 0; i < strEn.length(); i++)
	{
		for (int z = 0; z < i; z++)
		{
			strtemp.push_back(strEn[i]);
		}

		for (int i = 0; i < strStack.length(); i++)
		{
			strtemp.push_back(strStack[i]);
			for (int j = 0; j < 26; j++)
			{
				if (strtemp.compare(strMsg[j]) == 0)
				{
					strtemp.clear();
					vecStack.push_back(j + 65);

					break;
				}
			}
		}

		for (int i = 0; i < vecStack.size(); i++)
		{
			cout << vecStack[i];
		}
		cout << endl;
		vecStack.clear();
	
	}
	



    return 0;
}

