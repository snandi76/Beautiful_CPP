#pragma once
#include"Node.h"
#include<iostream>
using namespace std;
template<typename T>
class SingleLL {
private:
	Node<T>* m_Head;
public:

	SingleLL()
	{
		cout << "LL cretaed";
		m_Head = nullptr;
		//m_Head->link = nullptr;
	}
	~SingleLL() {

		
		while (m_Head != nullptr)
		{
			Node<T> *temp = m_Head;
			m_Head = m_Head->link;

			delete temp;

		}

	}
	
	void InsertAtEnd(T& data) 
	{
		if (m_Head == nullptr)
		{
			m_Head = new Node<T>();
			m_Head->data = data;
			m_Head->link = nullptr;
			return;
		}
		Node<T>* temp = m_Head;

		while (temp != nullptr)
		{
			if (temp->link == nullptr)
			{
				Node<T>* nNode = new Node<T>();
				nNode->data = data;
				nNode->link = nullptr;
				temp->link = nNode;
				return;
			}
			temp = temp->link;
		}


	}

	Node<T>* FindMiddleOfLL()
	{
		Node<T>* pFast = nullptr;
		Node<T>* pSlow = nullptr;
		if(m_Head != nullptr)
		{
			pSlow = m_Head;
			pFast = m_Head;

			while (pFast != nullptr && pFast->link != nullptr)
			{
			
				pSlow = pSlow->link;
				pFast = pFast->link->link;
			}
	
			return pSlow;
		}
		return nullptr;
	}

	void InsertInMiddle(T& data)
	{
		Node<T>* temp = FindMiddleOfLL();
		if (temp != nullptr)
		{
			Node<T>* temp1 = new Node<T>();
			temp1->data = data;
			temp1->link = temp->link;
			temp->link = temp1;
		}
	}

	void showLL() {
		Node<T>* temp = m_Head;
		cout << "\ndisplay LL\n";
		while (temp != nullptr)
		{
			cout << temp->data;
			temp = temp->link;
		}
	}

	T WrapperGetCnt()
	{
		return getCount(m_Head);
	}

	int getCount(Node<T>* trav) {
		if (trav == nullptr)
			return 0;
		else
		{
			return 1 + getCount(trav->link);
		}
	}


	bool IsLLPalindrome()
	{
		bool bRet = true;
		int iLLCount = getCount(m_Head);

		if (iLLCount % 2 == 0)
		{
			Node<T>* first = m_Head;
			Node<T>* mid = FindMiddleOfLL();
			while (first != nullptr && mid != nullptr)
			{
				if (first->data != mid->data)
				{
					return false;
				}
				first = first->link;
				mid = mid->link;
				
			}

		}
		else
		{
			Node<T>* first = m_Head;
			Node<T>* midPos = FindMiddleOfLL();
			Node<T>* mid = midPos->link;
			while (first != nullptr && mid != nullptr)
			{
				if (first->data != mid->data)
				{
					return false;
				}
				first = first->link;
				mid = mid->link;

			}

		}

		return bRet;
	}

};

