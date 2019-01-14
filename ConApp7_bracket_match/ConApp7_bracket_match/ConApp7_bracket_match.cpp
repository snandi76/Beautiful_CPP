// ConApp7_bracket_match.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//bool IsMatched(vector<char> &strref, char cend)
//{
//	bool bRet = false;
//	int index = (strref.size() - 1);
//	while (strref.empty() == false)
//	{
//		if (strref[index] == cend)
//		{
//			strref.pop_back();
//			bRet = true;
//			break;
//		}
//		else if (strref[index] == '(' || strref[index] == '[' || strref[index] == '{')
//		{
//			break;
//		}
//		strref.pop_back();
//		--index;
//
//	}
//	return bRet;
//}
//
//int main()
//{
//	int inumOfStr = 0;
//	cin >> inumOfStr;
//	vector<char> vstr;
//	bool *vRes = new bool(inumOfStr);
//
//
//	for (int i = 0; i < inumOfStr; i++)
//	{
//		string strtemp;
//		cin>>strtemp;
//		/*vstr.push_back(strtemp);*/
//		int len = strtemp.size();
//
//		//stack to process
//		bool ret;
//		for (int j = 0; j < len; j++)
//		{
//			char c = strtemp.at(j);
//			switch (c)
//			{
//			case ')':
//			{
//
//				ret = IsMatched(vstr, '(');
//				vRes[i] = ret;
//			}
//			break;
//			case '}':
//			{
//				ret = IsMatched(vstr, '{');
//				vRes[i] = ret;
//			}
//			break;
//			case ']':
//			{
//				ret = IsMatched(vstr, '[');
//				vRes[i] = ret;
//			}
//			break;
//			default:
//			{
//				vstr.push_back(strtemp.at(j));
//			}
//			}//end case
//		}//end for
//		if (vstr.empty() == false)
//		{
//			vRes[i] = false;
//		}
//		vstr.clear();
//
//
//	}//end of all string input
//
//	for(int i = 0 ;i<inumOfStr;i++)
//	{
//		if (vRes[i] == true)
//			cout << "YES"<<endl;
//		else
//			cout << "NO"<<endl;
//	}
//	return 0;
//}
//////////////////////////////////////////////////////////////////////
///////////2nd try
/////////////////////////////////////////////////////////////////////
#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool iSMatched(string &rStr)
{
	stack<char> stck;
	for(char c : rStr)
	{
		if (c == '{')stck.push('}');
		else if (c == '[')stck.push(']');
		else if (c == '(')stck.push(')');
		else
		{
			if (stck.empty() || c != stck.top())
				return false;
			stck.pop();
		}

	}
	return stck.empty();
}
int main()
{
	int num;
	cin >> num;
	bool* arr = new bool[num];
	for(int i = 0; i<num;i++)
	{
		string strtemp;
		cin >> strtemp;
		arr[i] = iSMatched(strtemp);
	}
	for (int i = 0; i < num; i++)
		cout << arr[i] << endl;

		return 0;
}
