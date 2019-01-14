#pragma once
int BinarySearch(int *pArr, int iLPos, int iRPos, int NumToFind)
{

	if (iRPos > iLPos)
	{
		int Mid = iLPos + (iRPos - iLPos) / 2;

		if (pArr[Mid] == NumToFind)
			return Mid;

		if (pArr[Mid] > NumToFind)
		{
			iRPos = (Mid - 1);
		}
		else
		{
			iLPos = (Mid + 1);
		}

		BinarySearch(pArr, iLPos, iRPos, NumToFind);
	}

}