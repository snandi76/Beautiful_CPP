//// ConApp7_State_Pattern.cpp : Defines the entry point for the console application.
////
//
#include "stdafx.h"
//#include <iostream>
#include "Header.h"
//class State;
//class Machine {
//	class State* current;
//public:
//	Machine();
//	//~Machine();
//	void SetCurrent(State *s)
//	{
//		current = s;
//	}
//	void Off();
//	void On();
//};
//
//void Machine::Off() {
//
//	current->Off(this);
//}
//
//void Machine::On()
//{
//	current->On(this);
//}
//Machine::Machine()
//{
//	current = new OFF();
//	std::cout << '\n';
//}
//
//class State {
//public:
//	virtual void On(Machine *m) {
//		std::cout << "already on" << std::endl;
//	}
//	virtual void Off(Machine *m) {
//		std::cout << "already off" << std::endl;
//	}
//};
//
//class ON :public State {
//
//public:
//	ON()
//	{
//		std::cout << "On ctor" << std::endl;
//	}
//	~ON()
//	{
//		std::cout << "On dtor" << std::endl;
//
//	}
//	void Off(Machine *m);
//
//};
//
//
//class OFF :public State {
//public:
//	OFF() {
//		std::cout << "Off ctor" << std::endl;
//	}
//
//	~OFF()
//	{
//		std::cout << "Off dtor" << std::endl;
//	}
//	void On(Machine *m);
//};
//
//void ON::Off(Machine *m) {
//
//	std::cout << "   going from ON to OFF";
//	m->SetCurrent(new OFF());
//	delete this;
//
//}
//
//void OFF::On(Machine *m)
//{
//	std::cout << "   going from OFF to ON";
//	m->SetCurrent(new ON());
//	delete this;
//
//}
//
//int main()
//{
//	void (Machine::*ptrs[])() {
//		Machine::Off, Machine::On
//	};
//	Machine fsm;
//	int iv = 0;
//	while (1) {
//		std::cout << "Enter 0/1" << std::endl;
//		std::cin>> iv;
//		(fsm.*ptrs[iv])();
//	}
//    return 0;
//}
//


//class GR2;
//class GR3;


void Machine::gr1()
{
	current->gr1(this);
}

void Machine::gr2()
{
	current->gr2(this);
}

void Machine::gr3()
{
	current->gr3(this);
}
//class GR1;







void GR1::gr3(Machine *m)
{
	cout << "   going from gr1 to gr3";
	m->setCurrent(new GR3());
	delete this;
}
void GR1::gr2(Machine *m)
{
	cout << "   going from gr1 to gr2";
	m->setCurrent(new GR2());
	delete this;
}

void GR2::gr3(Machine *m)
{
	cout << "   going from gr2 to gr3";
	m->setCurrent(new GR3());
	delete this;
}

void GR2::gr1(Machine *m)
{
	cout << "   going from gr2 to gr1";
	m->setCurrent(new GR1());
	delete this;
}


void GR3::gr1(Machine *m)
{
	cout << "   going from gr3 to gr1";
	m->setCurrent(new GR1());
	delete this;
}

void GR3::gr2(Machine *m)
{
	cout << "   going from gr3 to gr2";
	m->setCurrent(new GR2());
	delete this;
}

Machine::Machine()
{
	current = new GR1();
	cout << '\n';
}

int main()
{
	void(Machine:: *ptrs[3])() =
	{
		&Machine::gr1, &Machine::gr2,&Machine::gr3
	};
	Machine fsm;
	int num;
	while (1)
	{
		cout << "Enter 0-gr1/gr2 -1/gr3 -2: ";
		cin >> num;
		(fsm.*ptrs[num])();
	}
}