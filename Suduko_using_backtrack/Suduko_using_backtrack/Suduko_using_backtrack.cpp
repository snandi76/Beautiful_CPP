// Suduko_using_backtrack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool SolveSudoku(vector<int> &iVectGrid);
bool IsUnassignedLocation(vector<int> iVectGrid, int &iRow, int &iCol);
bool IsSafe(vector<int> iVecgrid, const int &iRow, const int &iCol, const int &num);
static const int iUNINITIALIZED = 0;
static const int iSizeOfMatrix = 9;


bool IsSafe(vector<int> iVecgrid, const int &iRow, const int &iCol, const int &num)
{
	bool bRet = false;

	while (true)
	{
		//COLUMN check
		int iTemCol = 0;
		while (iTemCol < iSizeOfMatrix)
		{
			iTemCol++;
			if (iVecgrid[iRow * (iSizeOfMatrix - 1) + iTemCol] == num)
			{
				break;
			}

		}//end while

		//ROW check
		int iTempRow = 0;
		while (iTempRow < iSizeOfMatrix)
		{
			iTempRow++;
			if (iVecgrid[iTempRow * (iSizeOfMatrix - 1) + iCol] == num)
			{
				break;
			}

		}//end while

		//small BOX check
		int iBoxEndRowIndex = (iSizeOfMatrix - 1), iBoxStartRowIndex = 0;
		int iBoxEndColIndex = (iSizeOfMatrix - 1), iBoxStartColIndex = 0;

		if (iRow < iSizeOfMatrix / 2)
		{
			iBoxEndRowIndex = ((iSizeOfMatrix / 2) - 1);
		}
		else
		{
			iBoxStartRowIndex = iSizeOfMatrix / 2;
		}

		if (iCol < iSizeOfMatrix / 2)
		{
			iBoxEndColIndex = ((iSizeOfMatrix / 2) - 1);
		}
		else
		{
			iBoxStartColIndex = iSizeOfMatrix / 2;
		}

		bool bExitFlag = false;
		for (int iTempRow = iBoxStartRowIndex; iTempRow <= iBoxEndRowIndex; iTempRow++)
		{
			for (int iTempCol = iBoxStartColIndex; iTempCol <= iBoxEndColIndex; iTempCol++)
			{
				//if((iTempRow == iRow) && (iTempCol == iCol))
				//	continue;

				if (iVecgrid[iTempRow * (iSizeOfMatrix - 1) + iTempCol] == num)
				{
					//Set condition to exit from for loop
					goto FailedInBox;
				}

			}

		}


		bRet = true;


	}
	//label
FailedInBox:
	return bRet;
}


//bool IsUnassignedLocation(vector<int> iVectGrid, int &iRow, int &iCol)
//{
//	bool bRet = false;
//
//	while (iVectGrid[(iRow * (iSizeOfMatrix - 1)) + iCol] == iUNINITIALIZED)
//	{
//		if (iCol < iSizeOfMatrix)
//		{
//			iCol++;
//		}
//		else if (iRow < iSizeOfMatrix)
//		{
//			iRow++;
//		}
//		if (iRow < iSizeOfMatrix || iCol < iSizeOfMatrix)
//		{
//			bRet = true;
//		}
//
//	}
//
//	return bRet;
//}


bool SolveSudoku(vector<int> &iVectGrid)
{
	bool bRet = false;
	int iCol = 0, iRow = 0;
	

	//base condtition
	while ((iCol < iSizeOfMatrix ) && (iRow < iSizeOfMatrix))
	{




		if (iVectGrid[(iRow * (iSizeOfMatrix - 1)) + iCol] == iUNINITIALIZED)
		{

			while (true)
			{
				for (int num = 1; num <= iSizeOfMatrix; num++)
				{
					if (IsSafe(iVectGrid, iRow, iCol, num) == true)
					{
						iVectGrid[iRow * (iSizeOfMatrix)+iCol] = num;
						bRet = true;
						break;
					}
					else
					{
						//not solved
						if (SolveSudoku(iVectGrid))
							iVectGrid[iRow * (iSizeOfMatrix)+iCol] = iUNINITIALIZED;
					}

				}
			}
		}
		else
		{
			
			if (iCol < (iSizeOfMatrix-1))
			{
				iCol++;
			}
			else if (iRow < (iSizeOfMatrix - 1))
			{
				iRow++;
			}

			
		}


	}
return bRet;
}


int main()
{

	vector<int> iVecSampleSuduko;
	/*for (int iRow = 0; iRow < iSize; iRow++)
	{
		for (int iCol = 0; iCol < iSize; iCol++)
		{
			iVecSampleSuduko.push_back(iUNINITIALIZED);
		}

	}*/
	iVecSampleSuduko = { 0,2,3,4,2,1,4,3,3,4,1,2,4,3,2,1 };

	//for (int iRow = 0; iRow < iSizeOfMatrix; iRow++)
	//{

	//	for (int iCol = 0; iCol < iSizeOfMatrix; iCol++)
	//	{

				SolveSudoku(iVecSampleSuduko);
//			}
	//	}
	//}



	for (int iRow = 0; iRow < iSizeOfMatrix; iRow++)
	{
		std::cout << "\n";
		for (int iCol = 0; iCol < iSizeOfMatrix; iCol++)
		{
			std::cout << iVecSampleSuduko[iRow * (iSizeOfMatrix)+iCol];
			//std::cout << iVecSampleSuduko
		}
	}
	int a;
	std::cin >> a;
	return 0;
}

