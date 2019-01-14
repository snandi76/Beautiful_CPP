// partial_name_search.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	vector<string> vName;
	//cout<<"Enter No of Operatoin"<<endl;
	unsigned int uiOp = 0;
	cin >> uiOp;

	for (int i = 0; i < uiOp; i++)
	{
		string strOp, strDat;
		cin >> strOp;
		if (strOp.compare("add") != 0)
		{
			vName.push_back(strOp);
		}

	}
	//test code
	//for(int i = 0; i < vName.size(); i++)
	//{
	//    cout<<vName[i]<<endl;    
	//}

	string strf1 = "hac", strf2 = "hak";
	//find1
	unsigned int uistrf1 = 0;
	for (int i = 0; i < vName.size(); i++)
	{
		short sret = vName[i].find(strf1, 0);
		if ((sret != std::string::npos) && (sret == 0))
		{
			uistrf1++;
		}
	}
	//"hac partial match"<<
	cout << uistrf1 << endl;

	//find2
	unsigned int uistrf2 = 0;
	for (int i = 0; i < vName.size(); i++)
	{
		short sret = vName[i].find(strf2, 0);
		if ((sret != std::string::npos) && (sret == 0))
		{
			uistrf2++;
		}
	}
	//<<"hak partial match"
	cout << uistrf2 << endl;

	//cout<<strFind;



	return 0;
}


