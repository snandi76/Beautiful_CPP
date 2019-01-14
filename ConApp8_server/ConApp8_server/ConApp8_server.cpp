// ConApp8_server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<stdio.h>
#include<winsock2.h>
#include<ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib") //Winsock Library

int main(int argc, char *argv[])
{
	WSADATA wsa;
	SOCKET s;
	
	char* message,reply_msg[2000];
	int recv_size;

	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return 1;
	}

	printf("Initialised.");

	SOCKADDR_IN server;
	if ((s = socket(PF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("cond not create socket :%d", WSAGetLastError());
	}
	printf("socket created\n");

	//server.sin_addr.s_addr = inet_addr("127.0.0.1");
	InetPton(AF_INET, _T("127.0.0.1"), &server.sin_addr.s_addr);
	server.sin_family = AF_INET;
	server.sin_port = htons(8888);

	if ((connect(s, (struct sockaddr *)&server, sizeof(server))) < 0)
	{
		printf("connect error%d",GetLastError());
		return 1;
	}
	puts("Connected");
	//message = "GET / HTTP/1.1\r\n\r\n";
	//if (send(s, message, strlen(message), 0) < 0)
	//{
	//	printf("error send%d",GetLastError());
	//}
	//puts("Data send\n");
	//if ((recv_size = recv(s, reply_msg, 2000, 0)) == SOCKET_ERROR)
	//{
	//	puts("rcv error");
	//}
	//else
	//{
	//	reply_msg[recv_size] = '\0';
	//	puts(reply_msg);
	//}
	closesocket(s);
	WSACleanup();

	return 0;
}

