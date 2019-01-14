#pragma once
template<typename T>
class CTest
{
private:

	T m_iData;
public:
	CTest();
	~CTest();
	T getV();
	void setV(T);
};

