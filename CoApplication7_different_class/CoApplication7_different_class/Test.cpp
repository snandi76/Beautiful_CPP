#include "stdafx.h"
#include "Test.h"

template<typename T>
CTest<T>::CTest()
{
}

template<typename T>
CTest<T>::~CTest()
{
}
template<typename T>
T CTest<T>::getV()
{
	return m_iData;
}
template<typename T>
void  CTest<T>::setV(T data)
{
	m_iData = data;
}
