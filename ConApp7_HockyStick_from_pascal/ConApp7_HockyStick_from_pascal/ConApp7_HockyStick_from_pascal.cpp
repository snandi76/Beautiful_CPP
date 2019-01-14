// ConApp7_HockyStick_from_pascal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

int pascal(int row, int column)
{
	if (column == 0) // The 0th column element is assumed to 0
		return 0;
	else if (row == 1 && column == 1)
		return 1;
	else if (column > row) // assuming the element is zero (no of columns> no of rows)
		return 0;
	else
		return (pascal(row - 1, column - 1) + pascal(row - 1, column));
}

void HockeyStickPattern(int iRow, int iPos, int iMaxRow, vector<int> &vect)
{
	for (int i = iRow; i < iMaxRow; i++)
	{
		vect.push_back(pascal(i,iPos));
	}
	vect.push_back(pascal(iMaxRow, iPos+1));
	
}


int main()
{
	vector<int> vect;
	HockeyStickPattern(1, 1, 7, vect);
	for (auto i : vect)
		cout << i<<endl;
	return 0;
}

