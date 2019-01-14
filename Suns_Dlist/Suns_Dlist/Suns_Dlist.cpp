// Suns_Dlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Dlist {
	private:
		int iData;

	public:
		Dlist() :iData(0), Next(NULL), Prev(NULL) {}
		~Dlist() { cout <<"~DLsit called"; }
		void setData(int& riData);
		Dlist* Next;
		Dlist* Prev;
		static void createFirstNode(Dlist* Head, int& riData)
		{
			Head->iData = riData;
			Head->Next = NULL;
			Head->Prev = NULL;
		}
		static void AddNode(Dlist* Head, int& riData) 
		{
			Dlist* NewNode = new Dlist();
			NewNode->iData = riData;
			NewNode->Next = NULL;
			NewNode->Prev = NULL;

			Dlist* Curr = Head;
			while (Curr != NULL)
			{
				if (Curr->Next == NULL)
				{
					Curr->Next = NewNode;
					NewNode->Prev = Curr;
					return;
				}
				Curr = Curr->Next;
			}
			//Curr->Next = NewNode;
			//NewNode->Prev = Curr;
		}

		static void Display(Dlist* pHead)
		{
			Dlist* curr = pHead;
			cout << "Lsit is:" << endl;
			while (curr != NULL)
			{
				cout << curr->iData;
				curr = curr->Next;
			}
		}

};

void Dlist::setData(int& riData) { iData = riData; }



int main()
{
	Dlist *pHead = NULL;
	pHead = new Dlist();
	int iData = 10;
	Dlist::createFirstNode(pHead, iData);
	iData = 100;
	Dlist::AddNode(pHead, iData);
	Dlist::Display(pHead);
	char* abc = NULL;
	int count = 9;
	cin.getline(abc, count);
	return 0;
}

