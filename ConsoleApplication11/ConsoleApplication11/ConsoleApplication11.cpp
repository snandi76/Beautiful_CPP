// ConsoleApplication11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include<vector>
using namespace std;
//#define SWAP(a,b) (a = b)
string decode(string encoded)
{

	vector<char> vecStack;
	int iASCII = 0;
	for (long long i = (encoded.length()-1); i >= 0; i--)
	{
		
		char cTemp = encoded.at(i);
		if(iASCII == 0)
		{
			iASCII = (int)cTemp - 48;
		}
		else
		{
			iASCII = iASCII + ((int)cTemp - 48);
		}
		
		if ( ( (65 <= iASCII)&& (iASCII <= 90) ) || ( (97 <= iASCII) &&(iASCII <= 122) ) )
		{
			vecStack.push_back(static_cast<char>(iASCII));
			iASCII = 0;
		}
		else
		{
			iASCII = iASCII * 10;
		}
	}

	string strtemp(vecStack.begin(), vecStack.end());
	return strtemp;
}

int main()
{
	string abc = decode("0756");

	return 0;
}

