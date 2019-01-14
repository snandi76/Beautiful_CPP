#pragma once


// MapTestClass

class MapTestClass : public CWnd
{
	DECLARE_DYNAMIC(MapTestClass)

public:
	MapTestClass();
	virtual ~MapTestClass();
	void CreateMap();

protected:
	DECLARE_MESSAGE_MAP()
};


