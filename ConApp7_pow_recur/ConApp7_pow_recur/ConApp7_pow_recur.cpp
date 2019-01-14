// ConApp7_pow_recur.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int pow(int power, int val)
{
	if (power == 0)
		return 1;

	if (power % 2 == 0)
	{
		int y = pow(power/2, val);
		return y*y;
	}
	else
	{
		return val*pow(power - 1, val);
	}
}


int main()
{
	cout << "enter val:";
	int val;
	cin >> val;
	cout << "enter power:";
	int power;
	cin >> power;
	cout << pow(power, val);

    return 0;
}

