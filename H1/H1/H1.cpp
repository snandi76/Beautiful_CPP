// H1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include<iostream>
#include<vector>

using namespace std;
vector<int> ivlist;
void update(int iStart, int iEnd, int iVal)
{
	for (int i = iStart; i <= iEnd; i++)
	{
		ivlist[i] += iVal;
	}
}

int GetMax()
{
	int retVal = 0;

	for (auto& item : ivlist)
	{
		if (retVal < item)
		{
			retVal = item;
		}
		cout << "item" << item<<endl;

	}
	return retVal;
}

int main() {

	int n;
	int m;
	cin >> n >> m;
	for (int i = 0; i <n; i++)
	{
		ivlist.push_back(0);
	}
	for (int a0 = 0; a0 < m; a0++) {
		int a;
		int b;
		int k;
		cin >> a >> b >> k;
		update(a, b, k);
	}

	cout << "\nMaxVal::" << GetMax();
	return 0;
}

