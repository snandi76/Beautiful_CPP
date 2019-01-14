#pragma once
#include"vecStack.h"
#include"vecStack.cpp"
class RevString
{
private:
	string m_strRev;
	vecStack<char> m_vecS;
public:
	RevString();
	~RevString();
	string RevStr_print(string strOrg);
};

