#pragma once
#include "stdafx.h"
#include<iostream>
#include<vector>

//using namespace std;
template<typename T>
class vecStack {
private:
	std::vector<T> m_vSt;
	T operator=(vecStack&) {};
	//vecStack(const vecStack&) {};
public:
	vecStack(void);
	~vecStack();
	T Pop();
	void Push(T);
	int GetCount();
};