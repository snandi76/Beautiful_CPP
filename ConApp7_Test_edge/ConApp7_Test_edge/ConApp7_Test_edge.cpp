//perfect power

#include "stdafx.h"
#include<iostream>

#include<map>

using namespace std;
void ListPrimefactor(map<int, int> &mapPower, int &num)
{
	int iResult = num;
	while (iResult % 2 == 0)
	{
		auto it = mapPower.find(2);
		if (it == mapPower.end())
		{
			mapPower.insert(pair<int, int>(2, 1));
		}
		else
		{
			mapPower[2] = mapPower[2] + 1;
		}
		iResult = iResult / 2;
	}

	for (int i = 3; i <= sqrt(iResult); i++)
	{
		while (iResult%i == 0)
		{
			auto it = mapPower.find(i);
			if (it == mapPower.end())
			{
				mapPower.insert(pair<int, int>(i, 1));
			}
			else
			{
				mapPower[i] = mapPower[i] + 1;
			}
			iResult = iResult / i;
		}

	}

	if (iResult > 2)
	{
		auto it = mapPower.find(iResult);
		if (it == mapPower.end())
		{
			mapPower.insert(pair<int, int>(iResult, 1));
		}
		else
		{
			mapPower[iResult] = mapPower[iResult] + 1;
		}

	}
}

int gcd(int n1, int n2)
{
	while (n1 != n2)
	{
		if (n1 > n2)
			n1 = n2 - n1;
		else 
			n2 = n2 - n1;
	}

	return n1;
}

int GetGcd(map<int, int> &mapPower)
{
	int iResult = mapPower.begin()->second;
	if (mapPower.size() == 1)
		return iResult;

	for (auto i : mapPower)
	{
		iResult = gcd(i.second, iResult);
	}

	return iResult;
}




int main()
{
	map<int, int> mapPower;

	int num = 256;
	ListPrimefactor(mapPower, num);
	if (GetGcd(mapPower) > 1)
		cout << "perfect power";

	for (auto i : mapPower)
		cout << i.first << "^+" << i.second << "^+";
	
	return 0;
}

