// ConApp7_DiamondProb.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class A {

public:
	int data;
	A():data(0){ };
	~A() {};
	//void gp();
	//virtual void init() = 0;
	void init() {
		cout << "at A" << endl;
	};
};

class C1 :public virtual A {
public:

	C1() {};
	~C1() {};
	//void init() {
	//	cout << "at C1" << endl;
	//};
};

class C2 :public virtual A {
public:

	C2() {
		
	};
	~C2() {};
	//void init() {
	//	cout << "at C2" << endl;
	//};
};

class D : public C1, public C2 {

public:
	D() {};
	~D() {};
	//void init() {
	//	cout << "at D" << endl;
	//	data = 100;
	//};
};


int main()
{
	A *ob = new D();
	ob->init();

	return 0;
}

