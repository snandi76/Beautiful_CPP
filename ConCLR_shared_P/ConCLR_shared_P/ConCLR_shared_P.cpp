// ConCLR_shared_P.cpp : main project file.

#include "stdafx.h"
#include<memory>
#include<iostream>
using namespace System;

class Test {
public:
	int m_iVar;
	Test()
	{
		std::cout << "Begin constr" << std::endl;
	}
	Test(std::shared_ptr<Test> rhs)
	{
		this->m_iVar = rhs->m_iVar;
	}
	~Test() {
		std::cout << "des End" << std::endl;
	}
};

std::shared_ptr<Test> func(std::shared_ptr<Test> rhsparam)
{
	std::shared_ptr<Test> obj(rhsparam);
	//std::cout << obj.use_count() << std::endl;
	obj->m_iVar = 120;
	return obj;
}

int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Hello World");
	std::shared_ptr<Test> ref1 = std::make_shared<Test>();
	ref1->m_iVar = 999;
	
	std::shared_ptr<Test> ref2 = func(ref1);

	std::cout << ref1->m_iVar << std::endl;
	std::cout << ref2->m_iVar<<std::endl;
	std::cout <<"ref cnt1:" <<ref1.use_count() << std::endl;
	std::cout << "ref cnt2:" << ref2.use_count() << std::endl;
	/*std::shared_ptr<Test> ref2; ref2 = ref1;*/
	//std::cout << ref2.use_count() << std::endl;
	//std::cout << ref1.use_count() << std::endl;
	std::cout << "End of main" << std::endl;
	return 0;
}
