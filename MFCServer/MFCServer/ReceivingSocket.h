#pragma once

// CReceivingSocket command target

class CReceivingSocket : public CSocket
{
public:
	CReceivingSocket();
	virtual ~CReceivingSocket();
	void OnReceive(int nErrorCode);
};


