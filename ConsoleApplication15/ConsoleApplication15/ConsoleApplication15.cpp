// ConsoleApplication15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<string>
#include<iostream>
//#include<algorithm>
#include<map>
//#include<iterator>
//#include<utility>
using namespace std;

void checkMagazine(vector<string> magazine, vector<string> note) {
	bool bPossibleFromMag = false;
	map<string, unsigned int> mwordCount;
	for(auto word : note)
	{
		if (find(magazine.begin(), magazine.end(), word) != magazine.end())
		{
			bPossibleFromMag = true;
			if(mwordCount.find(word)!= mwordCount.end())
			{
				if ((mwordCount[word] - 1) == 0) {
					bPossibleFromMag = false;
					break;
				}
					
					

				mwordCount.insert(make_pair(word, (mwordCount[word] - 1) ));
			}
			else
			{
				unsigned int uicount = count(magazine.begin(), magazine.end(), word);
				mwordCount.insert(make_pair(word, (uicount - 1) ));
			}
			
			
		}
		else
		{
			bPossibleFromMag = false;
			break;
		}
	}
	std::cout << ((bPossibleFromMag == true) ? "Yes" : "No");


}


int main()
{
    return 0;
}

