// ScoreCard.h : Declaration of the CScoreCard

#pragma once
#include "resource.h"       // main symbols



#include "ATLComApp_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CScoreCard

class ATL_NO_VTABLE CScoreCard :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CScoreCard, &CLSID_ScoreCard>,
	public IDispatchImpl<IScoreCard, &IID_IScoreCard, &LIBID_ATLComAppLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CScoreCard()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SCORECARD)


BEGIN_COM_MAP(CScoreCard)
	COM_INTERFACE_ENTRY(IScoreCard)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



};

OBJECT_ENTRY_AUTO(__uuidof(ScoreCard), CScoreCard)
