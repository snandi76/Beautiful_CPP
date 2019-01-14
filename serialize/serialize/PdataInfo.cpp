// PdataInfo.cpp : implementation file
//

#include "stdafx.h"
#include "serialize.h"
#include "PdataInfo.h"


// PdataInfo

//IMPLEMENT_DYNAMIC(PdataInfo, CObject)
IMPLEMENT_SERIAL(PdataInfo, CObject, 1)


PdataInfo::~PdataInfo()
{
}

PdataInfo::PdataInfo(CString rhsName, unsigned int irhsAge)
{
	m_cstrName = rhsName;
	m_iAge = irhsAge;
}

void PdataInfo::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << m_cstrName << m_iAge;
	}
	else//
	{
		ar >> m_cstrName >> m_iAge;
	}
}




// PdataInfo message handlers


