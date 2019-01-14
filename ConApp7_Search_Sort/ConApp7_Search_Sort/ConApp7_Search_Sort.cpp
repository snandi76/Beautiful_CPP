// ConApp7_Search_Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Binary_Search.h"
#include"QuickSort.h"
#include"MergeSort.h"
#include<iostream>
int main()
{
	int arr[4] = {10,55,100,3};
	std::cout << sizeof(arr)/sizeof(arr[0]);
	MergeSort(arr, 0, 3);
	for (int i = 0; i < 4; i++)
		std::cout << arr[i];
	//std::cout << BinarySearch(arr, 1, 7, 3);
    return 0;
}

