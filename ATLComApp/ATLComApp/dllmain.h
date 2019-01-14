// dllmain.h : Declaration of module class.

class CATLComAppModule : public ATL::CAtlDllModuleT< CATLComAppModule >
{
public :
	DECLARE_LIBID(LIBID_ATLComAppLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLCOMAPP, "{E1CA8514-D889-47A4-8919-69CB7B582807}")
};

extern class CATLComAppModule _AtlModule;
