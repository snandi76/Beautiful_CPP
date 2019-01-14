// ConsoleApp7_Cplusplus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
//#include"vecStack.h"
//#include"vecStack.cpp"
#include "PostfixEvelation.h"
#include"Source.cpp"
#include "RevString.h"
#include "TwoStack.h"
#include"CQueue.h"
#include"XORLinkList.h"
using namespace std;
//void BaseFrnd(Base* &ptr);
//class Base {
//	int a = 0;
//public:
//	Base() { cout << "Base()"; }
//	~Base() { cout << "~Base()"; }
//	friend void BaseFrnd(Base* &);
//};
//class Derived :public Base {
//public:
//	Derived() { cout << "Deri()";
//	}
//	~Derived() {
//		cout << "~Deri()";
//	}
//};
//
//void BaseFrnd(Base* &ptr) {
//	cout << "I am Base frnd"<< ptr->a;
//}
void LLPrint(Node* &);
void CreateLL_Reverse();



int main()
{

	struct LL* objL = CreateLL();
	Insert(objL, 10);
	Insert(objL, 100);
	Insert(objL, 1000);
	Insert(objL, 10000);
	show(objL);
	//struct Queue* q = CreateQueue();
	//enqueue(q, 10);
	//enqueue(q, 11);
	//struct QNode* temp = dequeue(q);
	//Two stack
	/*try{
	CTwoStack objTwoStack(5);
	
	objTwoStack.PushInSt1(1);
	objTwoStack.ShowStacks();
	objTwoStack.PushInSt1(2);
	objTwoStack.PushInSt1(3);
	objTwoStack.PushInSt1(4);
	objTwoStack.ShowStacks();
	objTwoStack.PushInSt2(10);
	}
	catch (exception *e)
	{
		cout << e->what();
	}*/
	
	//////////////////////////////////////
	/*string strPostFix = "5,6,2,+,*,12,4,/,-";
	CPostfixEvelation objPostFixEval;
	cout<<"val:"<<objPostFixEval.EvaluatePostFixNotaion(strPostFix);
	*/
	
	///////////////////////////////
	/*string strOrg = "baban";
	RevString objRevStr;
	cout<<objRevStr.RevStr_print(strOrg);
	*/


	////////////////////////////
	//vecStack<int> obj;
	//
	//obj.Push(100);
	//obj.GetCount();
	//obj.Pop();
	//obj.GetCount();
	//objS.Push(10);

	//auto_ptr<Base> ptr(new Derived());

	//Node* temp;
	
	//////Vec copy Prac
	//vector<int> *v1 = new vector<int>{ 10,20,30,40,50 };
	//
	//vector<int> *v2 = new vector<int>;
	///*v2 = v1;*/
	//

	//auto itS = v1->begin();
	//auto itE = v1->end();
	//v2->assign(itS, itS +v1->size());
	//
	//itS = v2->begin();
	//itE = v2->end();
	//for (; itS != itE;itS++)
	//{
	//	cout << *itS;
	//}
    return 0;
}

void LLPrint(Node* &rNode)
{
	Node* temp = rNode;
	while (temp != nullptr)
	{
		cout << temp->data << endl;
		temp = temp->link;
	}
}

void CreateLL_Reverse()
{
	Node* Head = nullptr;
	Node* Temp = nullptr;
	for (int i = 0; i < 10; i++)
	{
		if (Head == nullptr)
		{
			Head = new Node();
			Head->data = i;
			Head->link = nullptr;
			Temp = Head;
		}
		else
		{
			Node* Temp1 = new Node();
			Temp1->data = i;
			Temp1->link = nullptr;

			Temp->link = Temp1;
			Temp = Temp->link;
		}


	}

	LLPrint(Head);

	//reverse a LL
	Node* curr = nullptr;
	Node* prev = nullptr;
	Node* TempR = Head;

	while (TempR != nullptr)
	{
		curr = new Node();
		curr->data = TempR->data;
		curr->link = prev;
		prev = curr;
		TempR = TempR->link;
	}
	LLPrint(curr);
}