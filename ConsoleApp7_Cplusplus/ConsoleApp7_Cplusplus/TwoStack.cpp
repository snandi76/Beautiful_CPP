#include "stdafx.h"
#include "TwoStack.h"
#include<iostream>

CTwoStack::CTwoStack(int iArrSize):m_iFullArrSize(iArrSize)
{
	m_iStack1_Top = -1;
	m_iStack2_Top = iArrSize;
	m_iArr = new int[iArrSize];
}


CTwoStack::~CTwoStack()
{
	delete[] m_iArr;
}

void CTwoStack::PushInSt1(int data)
{

	if (m_iStack1_Top < m_iStack2_Top - 1 )
	{
		m_iStack1_Top++;
		m_iArr[m_iStack1_Top] = data;
		
	}
	else
	{
		throw  std::out_of_range("overflow Stack1");
	}

}

void CTwoStack::PushInSt2(int data)
{

	if (m_iStack2_Top > m_iStack1_Top +1 )
	{
		m_iStack2_Top--;
		m_iArr[m_iStack2_Top] = data;
		
	}
	else
	{
		throw  std::out_of_range("overflow Stack2");
	}
}

int CTwoStack::PopFromSt1()
{
	if (m_iStack1_Top > -1)
	{
		
		int p = m_iArr[m_iStack1_Top];
		--m_iStack1_Top;
		return p;
	}
	else
	{
		throw  std::out_of_range("underflow Stack1");
	}
}
int CTwoStack::PopFromSt2()
{
	if (m_iStack2_Top < m_iFullArrSize)
	{
		
		int q = m_iArr[m_iStack2_Top - 1];
		++m_iStack1_Top;
		return q;
	}
	else
	{
		throw  std::out_of_range("underflow Stack2");
	}
}

void CTwoStack::ShowStacks()
{
	std::cout << std::endl<<"stk1" << std::endl;
	for (int i = 0; i<=m_iStack1_Top ; i++)
	{
		std::cout << m_iArr[i];
	}
	std::cout << std::endl<<"stk2" << std::endl;
	for (int i = (m_iFullArrSize-1); i >= m_iStack2_Top ; i--)
	{
		std::cout << m_iArr[i];
	}

}
