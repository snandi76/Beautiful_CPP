// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<numeric>
#include<sstream>
using namespace std;

void FindPrimefactor(map<int,int> &v, int &inum)
{
	int iR = inum;
	while (iR % 2 == 0)
	{
		iR = iR / 2;
		auto pos = v.find(2);
		if (pos == v.end())
		{
			v.insert(pair<int,int>(2,1));
		}
		else
		{
			v[2] = v[2] + 1;
		}
		cout << "2\t";
	}

	for (int i = 3; i <= sqrt(iR); i++)
	{
		while (iR%i == 0)
		{
			auto pos = v.find(i);
			if (pos == v.end())
			{
				v.insert(pair<int, int>(i, 1));
			}
			else
			{
				v[i] = v[i] + 1;
			}
			iR = iR / i;
			cout << i << "\t";
		}
	}

	if (iR > 2)
	{


		auto pos = v.find(iR);
		if (pos == v.end())
		{
			v.insert(pair<int, int>(iR, 1));
		}
		else
		{
			v[iR] = v[iR] + 1;
		}
		cout << iR << "\n";
	}
}

int gcd(int  a, int b)
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}

	return a;
}

int GetGCD(map<int, int> &m)
{

	int iresult = m.begin()->second;
	if (m.size() == 1)
		return iresult;


	for (auto i : m)
	{
		iresult = gcd(i.second,iresult);
	}

	return iresult;

}



int main()
{
	map<int,int> PFmap;
	int num;
	cin >> num;
	FindPrimefactor(PFmap, num);
	
	if (GetGCD(PFmap) > 1)
		cout << "\nperfect power" << endl;

	ostringstream oss;
	//string str = "";

	//string str = "";
	for (auto i : PFmap)
	{
		oss << i.first << "^" << i.second << "+";
	}
	
	cout << "output\n" << num << "="<< oss.str();
	
	//cout << "\r";

	return 0;
}
