#include "Source.h"

//class Flower
Flower::Flower(string &rstrColor, double &rdPrice, FlowerType eType):m_strColor(rstrColor), m_dPrice(rdPrice),m_eType(eType)
{}

string Flower::GetColor() const
{
	return m_strColor;
}

double Flower::GetPrice() const
{
	return m_dPrice;
}

//FlowerType Flower::GetType() const
//{
//	return m_eType;
//}

//class Rose
Rose::Rose(string &rstrColor, double &rdPrice, FlowerType Type):Flower(rstrColor, rdPrice, Type)
{	
}

//bool Rose::Pollinate()
//{
//	return 0;
//}

//class Tulip

Tulip::Tulip(string &rstrColor, double &rdPrice, FlowerType Type) :Flower(rstrColor, rdPrice, Type)
{
}

//bool Tulip::Pollinate()
//{
//	return 1;
//}


/////////////
//Dlist
void Dlist::setData(auto_ptr<Flower> riData) { iData = riData; }


//class Bouqets
Bouqets::Bouqets():m_pDListHead(NULL), m_iFlowerCount(0)
{

}

Bouqets::~Bouqets()
{
	//delete m_pDListHead;
}

 void Bouqets::Appened(auto_ptr<Flower> robj)
{
	 if (m_pDListHead.get() == NULL)
	 {
		 Dlist::createFirstNode(&m_pDListHead, robj);
		 m_iFlowerCount++;
	 }
	 else
	 {
		 Dlist::AddNode(m_pDListHead, robj);
		 m_iFlowerCount++;
	 }
}

 void Bouqets::GetListOfFlower()
 {
	 //Dlist* curr = m_pDListHead;
	 Dlist::Display(m_pDListHead);
 }


//Main
 int main()
 {
	 string rstrColor = "Red";
	 double rdPrice = 5;
	 FlowerType Type = FlowerType::rose;
	 auto_ptr<Flower> FRose(new Rose(rstrColor, rdPrice, Type));

	 auto_ptr<Bouqets> FirstBoque( new Bouqets());
	 FirstBoque->Appened(FRose);
	 rdPrice = 30;
	 rstrColor = "yellow";
	 auto_ptr<Flower> FTulip(new Tulip(rstrColor, rdPrice, tulip));
	 FirstBoque->Appened(FTulip);

	 FirstBoque->GetListOfFlower();
	 cin.get();

	 return 0;
 }