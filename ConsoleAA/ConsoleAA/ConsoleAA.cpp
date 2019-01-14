// ConsoleAA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
//class A {
//
//public:
//	A() { std::cout << "A const"; }
//	~A() { std::cout << "A's des"; }
//};
//
//class B : public A {
//
//public:
//	B() { std::cout << "B const"; }
//	~B() { std::cout << "B's des"; }
//};

void(*funcH)(int);

void print1(int iOne)
{
	std::cout << "callback"<<iOne;
}

void call(void(*funcH)(int))
{
	std::cout << "Insice call" << std::endl;
	(*funcH)(10);
}
int main()
{
	//funcH = &print1();
	call(print1);

	return 0;
}

//class Base{
//public:
//	Base() { std::cout << "Base const"; }
//	virtual ~Base() { std::cout << "Base des"; }
//
//};
//
//class Child :public Base {
//public:
//	Child() { std::cout << "Child const"; }
//	~Child() { std::cout << "Child des"; }
//};
//int main()
//{
//	Base *objs = new Child();
//	delete objs;
//
//	int *a = new int[10];
//	int p = a[0];
//	return 0;
//}
