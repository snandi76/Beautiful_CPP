// ConsoleApp7_monk.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



// Write your code here
#include <iostream>
#include<string>
using namespace std;


long long MeanPrice(long long MP, long long TillNodePos, long long* arrC, long long *arrF)
{

	long long meanprice = 0;
	for (long long j = MP; j<TillNodePos; j++)
	{
		meanprice +=  arrF[j];
	}
	return meanprice*arrC[MP];
}

long long MinCPos(long long MP, long long TillNodePos, long long* arrC)
{
	long long Min = arrC[MP],MinPos = 0;
	for (long long i = (MP + 1); i<TillNodePos; i++)
	{
		if (arrC[i] < Min)
		{
			Min = arrC[i];
			MinPos = i;
		}
	}

	return MinPos;


}
long long MeanFl(long long MP, long long TillNodePos, long long* arrC, long long *arrF)
{
	if (MP == 0)
	{
		return MeanPrice(MP, TillNodePos, arrC, arrF);

	}
	else
	{
		long long sum = 0;
		sum = MeanPrice(MP, TillNodePos, arrC, arrF);
		long long MPos = MinCPos(0, MP, arrC);
		sum += MeanFl(MPos, MP, arrC, arrF);
		return sum;
	}

}


int main() {
	int iTcase;
	cin >> iTcase;
	if (iTcase < 1 || iTcase>5)
		return -1;
	long long *iTReslu = new long long[iTcase];
	for (int i = 0; i<iTcase; i++)
	{
		long long iCPoints;
		cin >> iCPoints;
		long long *arrC = new long long[iCPoints];
		long long *arrF = new long long[iCPoints];
		for (long long j = 0; j<2; j++)
		{
			if (j == 0)
			{
				for (long long k = 0; k<iCPoints; k++)
				{
					long long at;
					cin >> at;
					arrC[k] = at;
				}
			}
			else
			{
				for (long long k = 0; k<iCPoints; k++)
				{
					long long kt;
					cin >> kt;
					arrF[k] = kt;
				}
			}


		}
		long long imindis = 0;
		long long MP = MinCPos(0, iCPoints, arrC);
		imindis = MeanFl(MP, iCPoints, arrC, arrF);
		//cout << imindis << endl;
		iTReslu[i] = imindis;
		delete[] arrC;
		delete[] arrF;
	}
	for (long long i = 0; i < iTcase; i++)
		cout << iTReslu[i] << endl;

	return 0;
	// Writing output to STDOUT
}






