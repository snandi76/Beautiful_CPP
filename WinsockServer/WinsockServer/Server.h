#pragma once
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
class Server
{
private:

	SOCKET m_ListenSocket, m_ClientSocket; 
	struct addrinfo *m_Result;
	struct addrinfo m_Hints;
	int m_iSendResult;
	char m_RecvBuf[DEFAULT_BUFLEN];
	int m_iRecvBufLen;
	

public:
	Server();
	~Server();
	bool StartTCPIPServer();
};

