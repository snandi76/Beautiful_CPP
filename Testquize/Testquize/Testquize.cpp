// Testquize.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
//int appearanceCount(int input1, int input2, string input3, string input4);
//
//int FindAppearanceCount(int input1, int input2, string input3, string input4)
//{
//	//Write code here
//
//	int iAppreanceCount = 0;
//	unsigned int uiCodeSize = input1;
//	unsigned int uiMainStringSize = input2;
//	std::string strMainString = input4;
//
//	while (true)
//	{
//		std::string strMainCodeString;
//		//static bool bExit = false;
//		for (int i = 0; i<uiCodeSize; i++)
//		{
//			//if (bExit == true)
//			//	break;
//			
//			
//			for (int j = i; j<uiCodeSize; j++)
//			{	
//				unsigned int uiIndex = 0;
//
//				//if (bExit == true)
//				//	break;
//
//				//std::strcpy(strMainCodeString, input3, uiCodeSize);
//				strMainCodeString = input3;
//				if ((i != 0) || (j != 0))
//				{
//					char cTemp;
//					cTemp = strMainCodeString[i];
//					strMainCodeString[i] = strMainCodeString[j];
//					strMainCodeString[j] = cTemp;
//				}
//				
//				//Got the first code in cMainCodeString
//				while (uiIndex < uiMainStringSize)
//				{
//					uiIndex = strMainString.find(strMainCodeString, uiIndex);
//					if (std::string::npos == strMainString.find(strMainCodeString, uiIndex))
//					{
//						
//						break;
//
//					}
//					uiIndex += uiCodeSize;
//					iAppreanceCount++;
//
//					if(uiIndex >= uiMainStringSize)
//						break;
//				}
//
//			}//end of second for
//
//		}//end of first for
//
//		break;
//
//	}
//
//	return iAppreanceCount;
//}
int FindAppearanceCount(vector<string> const strVec, const string strMainString) 
{
	int iCount = 0;
	//vector<string>::iterator it;
	for (const auto iterator : strVec)
	{
		//cout << iterator;
		int iIndex = 0;
		iIndex = strMainString.find(iterator, iIndex);
		while (std::string::npos != strMainString.find(iterator, iIndex))
		{

			iIndex += strlen(iterator.c_str());
			iCount++;

		}
	}

	return iCount;

}

void swap(string &strA, int iX, int iY)
{
	char cTemp;
	cTemp = strA[iX];
	strA[iX] = strA[iY];
	strA[iY] = cTemp;
}


void permute(string strA, int l, int r, vector<string> &vecRef)
{
	
	if (l == r)
	{
		vecRef.push_back(strA);
	}
	else
	{
		for (int i = l; i <= r; i++)
		{
			swap(strA, l, i);
			permute(strA, l + 1, r, vecRef);
			swap(strA, l, i); //backtrack
		}
	}
}


int main()
{
	
	vector<string> strVec;
	permute("CaRA", 0, 3, strVec);
	int result = FindAppearanceCount(strVec, "AbrAcadAbRa");
	return 0;
}

