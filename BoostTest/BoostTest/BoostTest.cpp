// BoostTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <boost\algorithm\string.hpp>
#include <boost\date_time\date.hpp>

using namespace std;
int main()
{
	std::string s{ "Hello vs2015" };
	std::string s1 = boost::to_lower_copy(s);
	vector<std::string> spilledparts;
	boost::split(spilledparts, s1, boost::is_any_of(""));

	for (const auto& p : spilledparts)
	{
		std:cout << p.c_str() << "Length=" << p.length() << std::endl;
	}
   return 0;
}

