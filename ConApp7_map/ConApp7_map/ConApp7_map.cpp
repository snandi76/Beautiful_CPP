// ConApp7_map.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<map>
using namespace std;

int main()
{
	map<long long, long long> msgmap = {
		make_pair(90000000000, 80000000000000),
		make_pair(10000000000, 10000000000000),
		make_pair(70000000000, 80000000000000),
		make_pair(110000000000, 80000000000000)
	};

	//msgmap.insert(make_pair(90000000000, 80000000000000));
	//msgmap.insert(make_pair(10000000000, 10000000000000));
	//msgmap.insert(make_pair(70000000000, 80000000000000));
	//msgmap.insert(make_pair(110000000000, 80000000000000));
	
	for (auto it = msgmap.rbegin(); it!= msgmap.rend();it++)
		cout << it->first << ":" << it->second<<endl;

	//cout << msgmap.find(300000000000)->second;
    return 0;
}

