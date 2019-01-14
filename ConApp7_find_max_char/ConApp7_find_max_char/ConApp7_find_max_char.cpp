// ConApp7_find_max_char.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Example program
#include <iostream>
#include <string>
#include<map>
//#include<pair>
using namespace std;
void FindmaxChar(string str)
{
	map<char, int> cMap;
	for (int i = 0; i<str.size(); i++)
	{

		if (cMap.find(str[i]) == cMap.end())
		{
			cMap.insert(std::pair<char,int>(str.at(i), 1));
		}
		else
		{
			auto it = cMap.find(str[i]);
			it->second = it->second + 1;
		}

	}

	int Max = -1;
	char ch;
	for (auto it = cMap.begin(); it != cMap.end(); it++)
	{
		if (it->second > Max)
		{
			Max = it->second;
			ch = it->first;

		}
	}

	cout << ch << Max;

}


int main()
{
	//std::string name;
	//std::cout << "What is your name? ";
	//getline(std::cin, name);
	//std::cout << "Hello, " << name << "!\n";
	//FindmaxChar(name);

	//cout << count("");
	return 0;
}

