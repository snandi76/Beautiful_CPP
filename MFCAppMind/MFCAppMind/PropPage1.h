#pragma once

#ifdef _WIN32_WCE
#error "COlePropertyPage is not supported for Windows CE."
#endif 

// CPropPage1 : Property page dialog

class CPropPage1 : public COlePropertyPage
{
	DECLARE_DYNCREATE(CPropPage1)
	DECLARE_OLECREATE_EX(CPropPage1)

// Constructors
public:
	CPropPage1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROPPAGE_1 };
#endif

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);        // DDX/DDV support

// Message maps
protected:
	DECLARE_MESSAGE_MAP()
};
