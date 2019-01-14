#pragma once
#include"Node.h"
template<typename T>
class DoubleLL
{
private:
	DNode<T>* m_Head;
public:
	DoubleLL()
	{
		m_Head = nullptr;
	}
	~DoubleLL()
	{
		while (m_Head != nullptr)
		{
			DNode<T>* temp = m_Head;
			m_Head = m_Head->next;
//			m_Head->prev = nullptr;
			delete temp;
		}

	}
	void InsterAtEndInDL(T& data)
	{
		DNode<T>* temp = new DNode<T>;
		temp->data = data;
		temp->next = temp->prev = nullptr;
		if (m_Head == nullptr)
		{
			m_Head = temp;
			return;
		}
		DNode<T>* trav = m_Head;

		while (trav != nullptr)
		{
			if (trav->next == nullptr)
			{
				trav->next = temp;
				temp->prev = trav;
				return;
			}
			trav = trav->next;
		}


	}

	void show()
	{
		DNode<T>* trav = m_Head;
		cout << "\nShow\n";
		while (trav != nullptr)
		{
			
			cout << trav->data;
			trav = trav->next;
		}
	}

	void RotateFromPos(int& Pos)
	{
		static int currPos;
		DNode<T>* LastNode = nullptr, *trav = m_Head;
		DNode<T>* RotateNode = nullptr;
		while(trav!= nullptr)
		{
			currPos++;
			if (currPos == Pos)
			{
				RotateNode = trav;
			}
			LastNode = trav;
			trav = trav->next;
		}

		if (Pos < currPos)
		{
			//make firstno point to last and vice versa
			m_Head->prev = LastNode;
			LastNode->next = m_Head;

			m_Head = RotateNode->next;
			m_Head->prev = nullptr;

			RotateNode->next = nullptr;
		}


	}

};
