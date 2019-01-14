#include "stdafx.h"
#include "Example.h"

CFrameTest::CFrameTest()
{
	CRect rectPopUp(400, 280, 580, 520);
	Create(NULL, _T("Windows APP"), WS_CHILD | WS_VISIBLE , rectPopUp, NULL, NULL,NULL);

}