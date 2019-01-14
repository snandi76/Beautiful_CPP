// ServerSocket.cpp : implementation file
//

#include "stdafx.h"
#include "MFCServer.h"
#include "ServerSocket.h"


// CServerSocket

CServerSocket::CServerSocket()
{
}

CServerSocket::~CServerSocket()
{
}

void CServerSocket::OnAccept(int nErrorCode)
{
	// TODO: Add your specialized code here and/or call the base class
	AfxMessageBox(L"Connection accepted");
	CSocket::OnAccept(nErrorCode);
}
void CServerSocket::OnReceive(int nErrorCode)
{
	// TODO: Add your specialized code here and/or call the base class
	AfxMessageBox(L"Data Received");
	CSocket::OnReceive(nErrorCode);
}



// CServerSocket member functions
