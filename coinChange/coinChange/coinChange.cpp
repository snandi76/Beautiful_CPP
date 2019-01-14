// coinChange.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

//void ChangeCountFunction(vector<int> &vRefinedlistOfCoinType, unsigned int uiPositioninTheList, int iInputValue);
string CoinChange(int input1, vector < int > &input2);
int main()
{
	
	vector<int> vecinput;
	//for (int i = 1; i < 4; i++)
		vecinput.push_back(1);
		vecinput.push_back(3);
		//vecinput.push_back(1);
		vecinput.push_back(4);
	int a;
	cout << CoinChange(2, vecinput);
	cin >> a;
	return 0;
}


static unsigned int uiTotalChangeCount = 0;
string CoinChange(int input1, vector < int > &input2)
{
	vector<int> vecAmount;
	for (int i = 0; i <= input1; i++)
	{
		if(i == 0)
			vecAmount.push_back(1);
		else
			vecAmount.push_back(0);
	}

	for (int ncoin = 0; ncoin < input2.size(); ncoin++)
	{
		for (int nAmount = 0; nAmount < vecAmount.size(); nAmount++)
		{
			if (nAmount >= input2.at(ncoin))
			{
				vecAmount[nAmount] += vecAmount[nAmount - input2.at(ncoin)];
			}
		}
	}

	//std::ostringstream oss;
	//for (int i = 0; i < vecAmount.size(); i++)
	//	oss<<vecAmount[i];

	return std::to_string(vecAmount.at(input1));

}

//string CoinChange(int input1, vector < int > &input2)
//{
//	//Write code here
//	vector<int> vRefinedlistOfCoinType;
//	for (int i = 0; i < input2.size(); i++)
//	{
//		if ((input2.at(i) != 0) && (input2.at(i) <= input1))
//		{
//			vRefinedlistOfCoinType.push_back(input2.at(i));
//		}
//	}
//
//
//	if (input1 == 0 || vRefinedlistOfCoinType.size() == 0)
//	{
//		string cst = "Empty";
//		return cst;
//	}
//	//qsort(vRefinedlistOfCoinType.begin(), vRefinedlistOfCoinType.end(),);
//	int uiPositioninTheList = 0;
//	for (int i = uiPositioninTheList; i < (vRefinedlistOfCoinType.size()); i++)
//	{
//		int iInputValue = input1;
//		uiPositioninTheList = i;
//		ChangeCountFunction(vRefinedlistOfCoinType, uiPositioninTheList, iInputValue);
//	}
//
//	std::ostringstream oss;
//	oss << uiTotalChangeCount;
//
//
//	return oss.str();
//}
//
//void ChangeCountFunction(vector<int> &vRefinedlistOfCoinType, unsigned int uiPositioninTheList, int iInputValue)
//{
//	if ((iInputValue % vRefinedlistOfCoinType.at(uiPositioninTheList)) == 0)
//	{
//		uiTotalChangeCount++;
//	}
//	while (uiPositioninTheList < vRefinedlistOfCoinType.size())
//	{
//		iInputValue = iInputValue - vRefinedlistOfCoinType.at(uiPositioninTheList);
//		if ((iInputValue == 0) || (iInputValue < vRefinedlistOfCoinType.at(uiPositioninTheList)))
//			break;
//
//		uiPositioninTheList++;
//		while(uiPositioninTheList < vRefinedlistOfCoinType.size())
//		{
//			ChangeCountFunction(vRefinedlistOfCoinType, uiPositioninTheList, iInputValue);
//		//	uiPositioninTheList++;
//		}
//	}
//}

