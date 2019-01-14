#include "stdafx.h"
#include "RevString.h"


RevString::RevString()
{
	string m_strRev ="";

}


RevString::~RevString()
{
}

string RevString::RevStr_print(string strOrg)
{
	for (int i=0;strOrg[i] != '\0';i++)
	{
		m_vecS.Push(strOrg[i]);
	}
	
	for (int i = 0; m_vecS.GetCount() > 0; i++)
	{
		m_strRev.push_back(m_vecS.Pop());
	}
		
	return m_strRev;
}

