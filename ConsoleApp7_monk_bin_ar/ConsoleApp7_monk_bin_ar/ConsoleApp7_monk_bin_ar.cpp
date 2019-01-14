// ConsoleApp7_monk_bin_ar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int FindXOR(vector<int> &rVec)
//{
//	int r = 0;//init with 0
//	if (rVec.size() == 1 && rVec[0] == 1)
//	{
//		r = 1;
//	}
//	else
//	{
//		for (int i = 1; i < rVec.size(); i++)
//		{
//			if((i-1) == 0)
//			{
//				r = rVec[0] ^ rVec[1];
//			}
//			else
//			{
//				r = r ^ rVec[i];
//			}
//			
//		}
//	}
//	 
//    return r;
//}
//
//int Find1Count(int iele,vector<int> &vBin)
//{
//	//calculation
//	int count = 0;
//	for (int i = 0; i < iele; i++)
//	{
//		vector<int> vTemp;
//		for (int j = i; j < iele; j++)
//		{
//			if (i == j)
//			{
//				vTemp.clear();
//				vTemp.push_back(vBin[i]);
//			}
//			else
//			{
//				vTemp.push_back(vBin[j]);
//			}
//			if (FindXOR(vTemp) == 1)
//				count++;
//
//		}
//	}
//
//	return count;
//}
//
//int main()
//{
//	int iele = 0;
//
//	cin >> iele;
//	vector<int> vBin;
//	for (int j = 0; j < iele; j++)
//	{
//		int itemp;
//		cin >> itemp;
//		vBin.push_back(itemp);
//	}
//	
//	int iMax = 0;
//	int iorginalval;
//	for(int i =0; i< iele;i++)
//	{
//		if (vBin[i] == 0)
//		{
//			iorginalval = vBin.back();
//			vBin.pop_back();
//			vBin.push_back(1);
//		}
//		else
//		{
//			iorginalval = vBin.back();
//			vBin.pop_back();
//			vBin.push_back(0);
//		}
//		int ival = Find1Count(iele, vBin);
//		if (ival > iMax)
//		{
//			iMax = ival;
//		}
//		vBin.pop_back();
//		vBin.push_back(iorginalval);
//	}
//	
//
//	//result
//	cout << iMax;
//	return 0;
//}
#include <iostream>

int main()
{
	long n, x;
	//scanf("%ld", &n);
	std::cin >> n;
	x = n / 2;
	printf("%ld", (x + 1)*(n - x));
	return 0;
}
