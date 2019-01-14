#pragma once
#include"vecStack.h"
#include"vecStack.cpp"
#include<string>
class CPostfixEvelation
{
private:
	vecStack<int> m_StackR;
	
public:
	CPostfixEvelation();
	~CPostfixEvelation();
	int EvaluatePostFixNotaion(string& strPostFix);
};

