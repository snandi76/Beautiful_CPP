#include "stdafx.h"
#include "PostfixEvelation.h"
#include<sstream>


CPostfixEvelation::CPostfixEvelation()
{
	cout << "Post evaluate start" << endl;
}


CPostfixEvelation::~CPostfixEvelation()
{
	cout << "Post evaluate end" << endl;
}

int CPostfixEvelation::EvaluatePostFixNotaion(string &strPostFix)
{
	stringstream oss(strPostFix);
	string token;

	int iLen = strPostFix.size();
	cout << iLen;
	/*for (int i = 0; strPostFix[i]!='\0'; i++)*/
	while (std::getline(oss, token, ','))
	{
		if (token == "+")
		{
			int iLast = m_StackR.Pop();
			int iPrevL = m_StackR.Pop();
			int Result = iPrevL + iLast;
			m_StackR.Push(Result);

		}
		else if (token == "-")
		{
			int iLast = m_StackR.Pop();
			int iPrevL = m_StackR.Pop();
			int Result = iPrevL - iLast;
			m_StackR.Push(Result);

		}
		else if (token == "/")
		{
			int iLast = m_StackR.Pop();
			int iPrevL = m_StackR.Pop();
			int Result = iPrevL / iLast;
			m_StackR.Push(Result);

		}
		else if (token == "*")
		{
			int iLast = m_StackR.Pop();
			int iPrevL = m_StackR.Pop();
			int Result = iPrevL * iLast;
			m_StackR.Push(Result);

		}
		else {
			m_StackR.Push(atoi(token.c_str()));
		}
	}
	return m_StackR.Pop();

}
