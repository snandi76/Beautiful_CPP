// Test_new_feature_in_console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<conio.h>
using namespace std;

class Test
{
private:
	const char C = 0;
	int data;
public:
	Test();
	~Test();
};
Test::Test() { cout << "Test constructor" << endl; }
Test::~Test(){ cout << "Test destructor" << endl; }

class DTest :public Test 
{
public:
	DTest();
	~DTest();
};
DTest::DTest()
{
	cout << "DTest constructor" << endl;
}
DTest::~DTest()
{
	cout << "DTest destructor" << endl;
}

class DDTest :public DTest 
{
	
public:
	DDTest();
	~DDTest();
};

DDTest::DDTest() {
	cout << "DDTest constructor" << endl;
}
DDTest::~DDTest(){
	cout << "DDTest destructor" << endl;
}

int fun()
{	
	try {
		Test *ob1 = new DDTest();
		delete ob1;
	}
	catch (exception e) { 
		//error 
		
	}
	return 0;
}
int main()
{
	//DTest ob1;// = new DTest();
	//delete ob1;
	fun();
	
	cin.get();
	//system("");
}
