// ConsoleApplication14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
long arrayManipulation(int n, vector<vector<int>> queries) {
	vector<long> vArr(n, 0);
	for (auto query = queries.begin(); query != queries.end(); query++)
	{
		for (long strt = query->at(0); strt <= query->at(1); strt++)
		{
			vArr[strt] = vArr[strt] + query->at(2);
		}
	}
	sort(vArr.begin(), vArr.end());
	return vArr[n - 1];
}


int main()
{
    return 0;
}



