#pragma once
class CTwoStack
{
private:
	int *m_iArr;
	int  m_iStack1_Top,  m_iStack2_Top,m_iFullArrSize;
public:
	CTwoStack(int iArrSize);
	~CTwoStack(); 
	void PushInSt1(int data);
	void PushInSt2(int data);
	int PopFromSt1();
	int PopFromSt2();
	void ShowStacks();
};

