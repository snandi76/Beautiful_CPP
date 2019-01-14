// CoApplication7_different_class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Test.h"
#include"Test.cpp"
#include<iostream>

//int main()
//{
//	
//	CTest<int> obj;
//	obj.setV(10);
//	std::cout << obj.getV();
//    return 0;
//}
#include<iostream>
using namespace std;

#include<iostream>

#include<iostream>
using namespace std;

class GB
{
public:
	GB() { cout<<"I am at GB"<<endl; }
	virtual ~GB() { cout << "I am des GB"<<endl; }
};
class Base:private GB {
public:
	Base() { cout << "Constructor: Base" << endl; }
	virtual ~Base() { cout << "Destructor : Base" << endl; }
};
class Derived : public Base {
public:
	Derived() { cout << "Constructor: Derived" << endl; }
	~Derived() { cout << "Destructor : Derived" << endl; }
};
int main() {

	string obj[2] = { "baban","mandy" };

	char* objCP[2];// = { "baban1","mandy1" };
	
	for (int i = 0; i < 2; i++)
	{
		objCP[i] = (char*)malloc(10 * sizeof(char));
	}
	printf("%x\n", objCP[0]);
	char* p = "babann";
	objCP[0] = "babann";

	//memcpy((void*)objCP[0], (void*)p, 10);
	printf("%x\n", p);
	printf("%x\n", objCP[0]);
	return 0;
}
