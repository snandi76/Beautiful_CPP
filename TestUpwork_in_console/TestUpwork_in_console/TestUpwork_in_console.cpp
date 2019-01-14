// TestUpwork_in_console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
union MyUnion
{
	double iData;
};

int main()
{

	MyUnion objunion;
	
	objunion.iData = 7;
	//objunion.dData = 7.7f;
	std::cout <<"sizeof union:\t" <<sizeof(objunion) <<"\n\t" << objunion.iData;
	return 0;
}

