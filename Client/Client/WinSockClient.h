#pragma once
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
class WinSockClient
{
private:

	SOCKET ConnectSocket = INVALID_SOCKET;
	struct addrinfo *m_Result = NULL,
					*m_ptr    = NULL,
					 m_Hints;
	char *m_sendbuf = "this is a test";
	char m_RecvBuf[DEFAULT_BUFLEN];
	int m_iResult;
	int m_RecvBufLen = DEFAULT_BUFLEN;

public:
	WinSockClient();
	~WinSockClient();
};

