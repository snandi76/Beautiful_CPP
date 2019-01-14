#pragma once
void swap(int* pArr, int i, int j)
{
	int temp = pArr[i];
	pArr[i] = pArr[j];
	pArr[j] = temp;
}

int partition(int* pArr, int iLow, int iHigh)
{

	int pivot = pArr[iHigh];
	int i = iLow - 1;
	for (int j = iLow; j < iHigh; j++)
	{
		if (pArr[j] <= pivot)
		{
			i++;
			swap(pArr, i, j);
		}
	}
	swap(pArr, (i + 1), iHigh);

	return (i + 1);
}
void QuickSort(int *pArr, int iLow, int iHigh)
{
	if (iHigh > iLow)
	{

		int pi = partition(pArr,iLow,iHigh);

		QuickSort(pArr, iLow, pi - 1);
		QuickSort(pArr, pi + 1, iHigh);

	}
}
