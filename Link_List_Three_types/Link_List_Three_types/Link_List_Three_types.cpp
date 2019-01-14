// Link_List_Three_types.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"singleLL.h"
#include"DoubleLL.h"
#include<string>
#include"Stack_usingSLL.h"
bool Ispalindrome(string str)
{
	
	bool bRet = true;
	int Len = str.size();
	if (Len % 2 == 0)
	{
		int j = (Len -1);
		for (int i = 0; i < (Len / 2); i++)
		{
			if (str[i] != str[j])
			{
				bRet =  false;
				break;
			}
			j--;
		}

	}
	else
	{
		int MidPos = Len / 2;

		int strB = 0;
		int strM = Len -1;

		for (int i = 0; i < MidPos; i++)
		{
			if (str[i] != str[strM])
			{
				bRet = false;
				break;
			}
			strM--;
		}
	}
	return bRet;

}

int MinNumOFchrForMakingPalindrm(string str)
{
	int Len = str.size();
	char c = str[Len - 1];
	for (int i = (Len - 2); i >= 0; i--)
	{
		if (c == str[i])
		{
			continue;
		}
		else
		{
			return(i + 1);
		}
	}
		

}
int main()
{
	struct LL* stack = CreateLL();
	Push(stack,10);
	Push(stack, 100);
	show(stack);
	Pop(stack);
	show(stack);

	//palindrome
	/*string str = "baban";
	cout<<Ispalindrome(str);
	cout << MinNumOFchrForMakingPalindrm(str);*/
	
	//DoubleLL<int> obj;
	//for(int i = 0; i < 9; i++)
	//	obj.InsterAtEndInDL(i);

	//int Pos = 3;
	//obj.RotateFromPos(Pos);
	//obj.show();

	
	//SingleLL<int> objLL;
	//for (int i = 0; i <3; i++)
	//	objLL.InsertAtEnd(i);
	//for (int i = 1; i >= 0; i--)
	//	objLL.InsertAtEnd(i);
	//
	//cout << "Mid:"<<objLL.FindMiddleOfLL()->data<<endl;
	//objLL.showLL();
	//cout <<endl<<"IsLLPalindrome:"<< objLL.IsLLPalindrome();
    return 0;
}

