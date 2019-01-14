// ConApp7_birthday_cake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
	
	int iNumTestcase = 0;
	cin >> iNumTestcase;
	for(int i =0; i<iNumTestcase;i++)
	{
		//cout << "enter type of cack" << endl;
		long long ltypeofcake = 0;
		cin >> ltypeofcake;

		//cout << "frd of monk" << endl;
		long long lNofrd = 0;
		cin >> lNofrd;

		//cout << "eating cap of each frd" << endl;
		long long *iarrECapa = new long long[lNofrd];
		for (long long i = 0; i < lNofrd; i++)
			cin >> iarrECapa[i];


		long long lMaxWtofCake = 0;
		//cout << "Wt of each cake" << endl;
		long long *iarrWCake = new long long[ltypeofcake];
		for (long long i = 0; i < ltypeofcake; i++)
		{
			cin >> iarrWCake[i];
			if (iarrWCake[i] > lMaxWtofCake)
			{
				lMaxWtofCake = iarrWCake[i];
			}
		}


		//cout << "No of each cake" << endl;
		long long TotalCake = 0;
		//long long *iarrNCake = new long long[ltypeofcake];
		map<long long, long long> wtvsNum;
		for (long long i = 0; i < ltypeofcake; i++)
		{
			long long lNumofCake = 0;
			cin >> lNumofCake;
			TotalCake += lNumofCake;
			wtvsNum.insert(make_pair(iarrWCake[i], lNumofCake));
		}


		//sort frd in capacity
		sort(iarrECapa, iarrECapa + lNofrd);
		

		if (lMaxWtofCake > iarrECapa[lNofrd - 1])
		{
			//cout << "lMaxWtofCake:" << lMaxWtofCake << "iarrECapa" << iarrECapa[lNofrd - 1] << endl;
			cout << "1" << endl;
			continue;
		}
		int sec = 0;

		//logic
		while (TotalCake != 0)
		{
			sec++;
			long long ilastEaten = lNofrd;

			for (auto it = wtvsNum.rbegin(); it != wtvsNum.rend(); it++)
			{
				if (it->second == 0)
					continue;

				for (long long j = (ilastEaten - 1); j >= 0; j--)//frd
				{
					if (it->second != 0)
					{
						if (it->first <= iarrECapa[j])
						{
							--it->second;
							--TotalCake;
							--ilastEaten;
							if (it->second == 0)
								break;
						}
					}
					else
					{
						break;
					}

				}
			}
		}




		cout << sec << endl;
		delete[] iarrECapa;
		wtvsNum.clear();
	
	}
	
    return 0;
}

////////////////
//flaw::takeing more time:optimized
//////////////
