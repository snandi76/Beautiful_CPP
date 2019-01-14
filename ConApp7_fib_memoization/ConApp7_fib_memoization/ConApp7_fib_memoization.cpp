// ConApp7_fib_memoization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int arrF[51];
int F(int data)
{
	if (arrF[data] != -1)
	{
		return arrF[data];
	}

	arrF[data] = F(data - 2) + F(data - 1);
	return arrF[data];
		
}


int main()
{
	for (int i = 0; i < 51; i++)
		arrF[i] = -1;
	
	arrF[0] = 0;
	arrF[1] = 1;
	int val;
	cin >> val;
	cout<<F(val);
    return 0;
}

