// TestInterview7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main(int argc, int **argv)
{
	int arr[5] = {2,7,11,10,12};
	for (int i = 1; i < (5 - 1); i++)
	{
		if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
			cout << "peak";
		else
			cout << "NO peak";
	}

	return 0;

}










//int* function()
//{
//	
//	
//		register int a = 10;
//	
//	
//	return &a;
//}
//int main()
//{
//	//auto can be accessed outside of scope if pointer is returned
//	int *Point = function();
//	printf("%d", *Point);
//	int val = 10;
//	//print if and else
//	if (!(std::cout << "Mandira"))
//	{
//
//	}
//	else
//	{
//		std::cout << "sunandan";
//	}
//	//comapre two num using XOR
//
//	int a = 10, b = 10;
//	bool bCom = a ^ b;
//
//	//static variable understanding
//
//	{
//		static int sIntVal = 100;;
//		++sIntVal;
//		std::cout << "\n"<<&sIntVal<<std::endl;
//	} 
//
//	{
//	static int sIntVal;;
//	std::cout << &sIntVal<<std::endl;
//	}
//     return 0;
//}

