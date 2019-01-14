#include "stdafx.h"
#include "Server.h"


Server::Server()
	:m_ListenSocket(INVALID_SOCKET)
	, m_ClientSocket(INVALID_SOCKET)
	, m_Result(NULL)
	, m_iRecvBufLen(DEFAULT_BUFLEN)
{
}


Server::~Server()
{
}

bool Server::StartTCPIPServer()
{
	int iResult;
	bool bRet = false;
	WSADATA wsaData;

	while (true)
	{

		// Initialize Winsock
		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != 0) {
			DWORD dw = WSAGetLastError();
			break;
		}

		ZeroMemory(&m_Hints, sizeof(m_Hints));
		m_Hints.ai_family = AF_INET;
		m_Hints.ai_socktype = SOCK_STREAM;
		m_Hints.ai_protocol = IPPROTO_TCP;
		m_Hints.ai_flags = AI_PASSIVE;

		// Resolve the server address and port
		iResult = getaddrinfo(NULL, DEFAULT_PORT, &m_Hints, &m_Result);
		if (iResult != 0)
		{
			DWORD dw = WSAGetLastError();
			WSACleanup();
			break;
		}

		// Create a SOCKET for connecting to server
		m_ListenSocket = socket(m_Result->ai_family, m_Result->ai_socktype, m_Result->ai_protocol);
		if (m_ListenSocket == INVALID_SOCKET)
		{
			DWORD dw = WSAGetLastError();
			freeaddrinfo(m_Result);
			WSACleanup();
			break;
		}

		// Setup the TCP listening socket
		iResult = bind(m_ListenSocket, m_Result->ai_addr, (int)m_Result->ai_addrlen);
		if (iResult == SOCKET_ERROR)
		{
			DWORD dw = WSAGetLastError();
			freeaddrinfo(m_Result);
			closesocket(m_ListenSocket);
			WSACleanup();
			break;
		}

		freeaddrinfo(m_Result);

		iResult = listen(m_ListenSocket, SOMAXCONN);
		if (iResult == SOCKET_ERROR)
		{
			DWORD de = WSAGetLastError();
			closesocket(m_ListenSocket);
			WSACleanup();
			break;
		}

		// Accept a client socket
		m_ClientSocket = accept(m_ListenSocket, NULL, NULL);
		if (m_ClientSocket == INVALID_SOCKET)
		{
			DWORD dw = WSAGetLastError();
			closesocket(m_ListenSocket);
			WSACleanup();
			break;
		}

		// No longer need server socket
		closesocket(m_ListenSocket);

		// Receive until the peer shuts down the connection
		do {

			iResult = recv(m_ClientSocket, m_RecvBuf, m_iRecvBufLen, 0);
			if (iResult > 0)
			{

				CString cstrBytesRcv = _T("");
				cstrBytesRcv.Format(_T("Bytes received: %d"), iResult);
				AfxMessageBox(cstrBytesRcv, 0, 0);

				// Echo the buffer back to the sender
				m_iSendResult = send(m_ClientSocket, m_RecvBuf, iResult, 0);
				if (m_iSendResult == SOCKET_ERROR)
				{
					DWORD dw = WSAGetLastError();
					closesocket(m_ClientSocket);
					WSACleanup();
					break;
				}
				CString cstrBytesSnt = _T("");
				cstrBytesSnt.Format(_T("Bytes sent: %d"), m_iSendResult);
				AfxMessageBox(cstrBytesSnt, 0, 0);
			}
			else if (iResult == 0)
			{
				CString cstrLog = _T("");
				cstrLog.Format(_T("Connection closing..."));
				AfxMessageBox(cstrLog, 0, 0);
			}
			else
			{
				DWORD dw = WSAGetLastError();
				WSACleanup();
				return 1;
			}

		} while (iResult > 0);

		// shutdown the connection since we're done
		iResult = shutdown(m_ClientSocket, SD_SEND);
		if (iResult == SOCKET_ERROR) {
			DWORD dw = WSAGetLastError();
			closesocket(m_ClientSocket);
			WSACleanup();
			break;
		}

		// cleanup
		closesocket(m_ClientSocket);
		WSACleanup();

		bRet = true;
	}

	return bRet;
}
