#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
const double PERROSEPRICE = 20.0;
const double PERTULIPPRICE = 30.0;

using namespace std;
enum FlowerType{
	None,
	rose,
	tulip,
	count
};

class Flower {

public:
	string m_strColor;
	double m_dPrice;
	FlowerType m_eType;

public:
	Flower(string & rstrColor,	double& rdPrice, FlowerType eType);
	virtual ~Flower() {
		m_strColor = ""; 
		m_dPrice = 0.0;
		m_eType = None;

	};

	string GetColor() const;
	double GetPrice() const;
	virtual FlowerType GetType() = 0;
	//virtual bool Pollinate() = 0;

};


class Rose :public Flower {

public:
	Rose(string &rstrColor, double &rdPrice, FlowerType Type);
	~Rose() {};
	FlowerType GetType() { return m_eType; }

	//bool Pollinate();
};


class Tulip :public Flower {

public:
	
	Tulip(string &rstrColor, double &rdPrice, FlowerType Type);

	~Tulip() {};
	FlowerType GetType() { return m_eType; }
	//bool Pollinate();

};


//class DList {
//public:
//	DList() {};
//	~DList() {};
//	vector<Flower*> vecFlower;
//			
//	int GetFlowersCount() { return vecFlower.size(); }
//	Flower* GetNextFlower();
//	Flower* GetPreviousFlower();
//	void AppenedAtDList();
//};
class Dlist {
private:
	auto_ptr<Flower> iData;

public:
	Dlist() :iData(NULL), Next(NULL), Prev(NULL) {}
	~Dlist() { cout << "~DLsit called"; }
	
	void setData(auto_ptr<Flower> riData);
	auto_ptr<Dlist> Next;
	auto_ptr<Dlist> Prev;
	static void createFirstNode(auto_ptr<Dlist>* Head, auto_ptr<Flower> riData)
	{
		auto_ptr<Dlist> NewNode(new Dlist());
		NewNode->iData = riData;
		//NewNode->Next(NULL);
		//NewNode->Prev.reset();

		*Head = NewNode;
		
	}
	static void AddNode(auto_ptr<Dlist> Head, auto_ptr<Flower> riData)
	{
		auto_ptr<Dlist> NewNode( new Dlist());
		NewNode->iData = riData;

		Dlist* Curr = Head.get();
		while (Curr != NULL)
		{
			if (Curr->Next.get() == NULL)
			{
				Curr->Next = NewNode;
				NewNode->Prev = Curr;
				return;
			}
			Curr = Curr->Next.get();
		}
		//Curr->Next = NewNode;
		//NewNode->Prev = Curr;
	}

	static void Display(auto_ptr<Dlist> pHead)
	{
		auto_ptr<Dlist> curr = pHead;
		cout << "Lsit is:" << endl;
		while (curr.get() != NULL)
		{
			string strtype = "";
			switch (curr->iData->GetType())
			{
			case rose:			
				strtype = "Rose";
					break;
			case tulip:
				strtype = "Tulip";
					break;
			default:
				break;
			}
			cout << strtype;
			curr = curr->Next;
		}
	}

};


class Bouqets {
private:
	int m_iFlowerCount;
	auto_ptr<Dlist> m_pDListHead;
public:
	Bouqets();
	~Bouqets();
	void Appened(auto_ptr<Flower> robj);
	void GetListOfFlower();
	//double GetPrice();
};