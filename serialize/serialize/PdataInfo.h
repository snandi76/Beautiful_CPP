#pragma once


// PdataInfo

class PdataInfo : public CObject
{
	//DECLARE_DYNAMIC(PdataInfo)
	DECLARE_SERIAL(PdataInfo)

public:
	PdataInfo():m_cstrName(_T("")), m_iAge(-1)
	{};
	PdataInfo(CString rhsName, unsigned int irhsAge);
	virtual ~PdataInfo();
	void Serialize(CArchive& ar);

//protected:
	CString m_cstrName;
	unsigned int m_iAge;
	//DECLARE_MESSAGE_MAP()
};


