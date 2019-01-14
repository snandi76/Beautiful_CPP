#pragma once

// CServerSocket command target

class CServerSocket : public CSocket
{
public:
	CServerSocket();
	virtual ~CServerSocket();
	void OnAccept(int nErrorCode);
	void OnReceive(int nErrorCode);

};


