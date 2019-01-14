// PropPage1.cpp : implementation file
//

#include "stdafx.h"
#include "MFCAppMind.h"
#include "PropPage1.h"


// CPropPage1 dialog

IMPLEMENT_DYNCREATE(CPropPage1, COlePropertyPage)



// Message map

BEGIN_MESSAGE_MAP(CPropPage1, COlePropertyPage)
END_MESSAGE_MAP()



// Initialize class factory and guid

// {4614C6BA-2BAF-4A5F-B95B-0A8A171DF336}
IMPLEMENT_OLECREATE_EX(CPropPage1, "MFCAppMind.PropPage1",
	0x4614c6ba, 0x2baf, 0x4a5f, 0xb9, 0x5b, 0xa, 0x8a, 0x17, 0x1d, 0xf3, 0x36)



// CPropPage1::CPropPage1Factory::UpdateRegistry -
// Adds or removes system registry entries for CPropPage1

BOOL CPropPage1::CPropPage1Factory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Define string resource for page type; replace '0' below with ID.

	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, 0);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CPropPage1::CPropPage1 - Constructor

// TODO: Define string resource for page caption; replace '0' below with ID.

CPropPage1::CPropPage1() :
	COlePropertyPage(IDD_PROPPAGE_1, 0)
{

}



// CPropPage1::DoDataExchange - Moves data between page and properties

void CPropPage1::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CPropPage1 message handlers
