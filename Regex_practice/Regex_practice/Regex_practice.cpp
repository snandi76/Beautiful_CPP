// Regex_practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<regex>

using namespace std;
int main()
{
	string strTest = "I am looking for GeeksForGeeks";
	//regex pat("(Geek)(.*)");
	regex pat{ "(\\s+(\\w+))" };
	//if (regex_match(strTest, pat))
	//	cout<< "string a  matches regular expression";

	//if(regex_match(strTest.begin(), strTest.end(), pat) )
	//	cout << "string a  matches regular expression 0 to string end";

	//smatch m;
	//regex_search(strTest, m, pat);
	//cout<<(typeid(m).name());
	for (sregex_iterator p(strTest.begin(), strTest.end(), pat); p != sregex_iterator{}; ++p)
		cout << (*p)[1] << endl;

	return 0;
}

