// ConsoleApplication13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;
class Base {
private:
	string Demodata;
public:
	Base(){}
	Base(string strDemo) :Demodata(strDemo){}
	~Base(){}
	Base(Base& obj) {
		Demodata = obj.Demodata;
	}//copy const
	Base& operator=(Base& objRight) {
		Base objTemp;
		objTemp.Demodata = objRight.Demodata;
		return objTemp;
	}//assignment operator overloding
	void Show() {
		cout << Demodata<<endl;
	}
};

int main()
{
	Base ob("Momo");
	Base ob1(ob);
	Base ob2;
	ob2 = ob1;
	ob2.Show();
    return 0;
}

