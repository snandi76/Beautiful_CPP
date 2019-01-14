// ConDynamic_static_obj_prev7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
class ATest {
//public:
//	static ATest* GetIns(){
//		return new ATest();
//}
public:	
	ATest(){
	}
	~ATest() {
	}

private:
	void* operator new(size_t size);
};

int main()
{
	//ATest *obj = ATest::GetIns();
	ATest statobj;
	return 0;
}

