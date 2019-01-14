// MapTestClass.cpp : implementation file
//

#include "stdafx.h"
#include "TestSTLSkill.h"
#include "MapTestClass.h"
#include <map>

// MapTestClass

IMPLEMENT_DYNAMIC(MapTestClass, CWnd)

MapTestClass::MapTestClass()
{	
	std::map< std::string, int> MapString;
	MapString["Abc"] = 10;
	MapString.begin();
	//MapString[_T("sunandan")] = _T("Nandi");
	//MapString[_T("Mandira")] = _T("SethNandi");
	//MapString.count;
}

MapTestClass::~MapTestClass()
{
}

void MapTestClass::CreateMap()
{ 

}


BEGIN_MESSAGE_MAP(MapTestClass, CWnd)
END_MESSAGE_MAP()



// MapTestClass message handlers


