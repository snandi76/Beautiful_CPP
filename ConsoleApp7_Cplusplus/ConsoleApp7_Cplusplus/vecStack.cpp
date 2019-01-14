#pragma once
#include"stdafx.h"
#include"vecStack.h"
#include<iostream>
using namespace std;
template<typename T>
vecStack<T>::vecStack(void)
{
	cout << "Stack created"<<endl;
}

template<typename T>
vecStack<T>::~vecStack()
{
	cout << "Stack destroyed"<<endl;
	m_vSt.clear();
}

template<typename T>
T vecStack<T>::Pop()
{
	if (m_vSt.empty() == true)
	{
		cout << "Empty";
		throw std::out_of_range("underflow");

	}
		T backVal = m_vSt.back();
		m_vSt.pop_back();
		return backVal;
	
}

template<typename T>
void vecStack<T>::Push(T data)
{
	m_vSt.push_back(data);
}

template<typename T>
int vecStack<T>::GetCount()
{
	return m_vSt.size();
}