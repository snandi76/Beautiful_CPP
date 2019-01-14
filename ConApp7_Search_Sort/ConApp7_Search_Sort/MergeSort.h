#pragma once
#include<iostream>
#include<vector>
using namespace std;
void merge(int* a, int low, int mid, int high)
{
	/*int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	vector<int> pL,pR;

	for (int i = 0; i < n1; i++)
		pL.push_back(pArr[left + i]);
	for (int j = 0; j < n2; j++)
		pR.push_back(pArr[mid + 1 + j]);

	i = j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		if (pL[i] <= pR[j])
		{
			pArr[k] = pL[i];
			i++;
		}
		else
		{
			pArr[k] = pL[j];
			j++;
		}
		k++;
	}


	while (i < n1)
	{
		pArr[k] = pL[i];
		i++;
		k++;

	}


	while (j < n2)
	{
		pArr[k] = pR[j];
		j++;
		k++;
	}
	std::cout << std::endl;
	for (int i = left; i < right; i++)
		std::cout << pArr[i];
	std::cout << std::endl;*/
	int *temp = new int[high - low + 1];

	int left = low;
	int right = mid + 1;
	int current = 0;
	// Merges the two arrays into temp[] 
	while (left <= mid && right <= high) {
		if (a[left] <= a[right]) {
			temp[current] = a[left];
			left++;
		}
		else { // if right element is smaller that the left
			temp[current] = a[right];
			right++;
		}
		current++;
	}

	// Completes the array 

	// Extreme example a = 1, 2, 3 || 4, 5, 6
	// The temp array has already been filled with 1, 2, 3, 
	// So, the right side of array a will be used to fill temp.
	if (left > mid) {
		for (int i = right; i <= high; i++) {
			temp[current] = a[i];
			current++;
		}
	}
	// Extreme example a = 6, 5, 4 || 3, 2, 1
	// The temp array has already been filled with 1, 2, 3
	// So, the left side of array a will be used to fill temp.
	else {
		for (int i = left; i <= mid; i++) {
			temp[current] = a[i];
			current++;
		}
	}
	// into the original array
	for (int i = 0; i <= high - low; i++) {
		a[i + low] = temp[i];
	}
	delete[] temp;
}

void MergeSort(int* pArr,int left, int right)
{
	if (right > left)
	{
		int mid = (left + right) / 2;
		MergeSort(pArr, left, mid);
		MergeSort(pArr, mid+1, right);

		merge(pArr, left, mid, right);
	}
}