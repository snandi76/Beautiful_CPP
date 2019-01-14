// ConsoleApplication12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;


/*
***********************
*					  *
* Hello				  *
*					  *
***********************
*/
int main()
{

	cout << "Enter the name:             ""Hello";
	string strName;
	cin >> strName;
	int pads = 1;
	int rows = pads * 2 + 3;
	size_t cols = strName.size() + pads * 2 + 2;
	for (int row = 0; row < rows; row++)
	{
		size_t col = 0;
		while (col < cols)
		{
			if (row == (pads + 1) && col == (pads + 1))
			{
				cout << strName;
				col = col + strName.size();
			}
			else
			{
				if ((row == 0) || (row == (rows - 1)) || (col == 0) || (col == (cols - 1)))
				{
					cout << "*";
					col = col + 1;
				}
				else
				{
					cout << " ";
					col = col + 1;
				}
			}

		}
		cout << endl;
	}


    return 0;
}

