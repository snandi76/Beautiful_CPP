// ConsoleApplication17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;
class Test {
public:
	Test() {
		cout << "Test const"<<endl;
	}
	~Test() {
		cout << "Test dest" << endl;
	}
};

Test objTest;
int main()
{
	cout << "In main" << endl;
    return 0;
}
