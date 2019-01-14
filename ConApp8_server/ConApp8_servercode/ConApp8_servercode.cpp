// ConApp8_servercode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<stdio.h>
#include<winsock2.h>
#include<ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib") //Winsock Library

int main()
{
	WSADATA wsa;
	SOCKET new_socket, ls;
	struct sockaddr_in server,client;
	int c;
	puts("Init sock");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
	printf("sock lib err%d\n",WSAGetLastError());
	}
	puts("Initialized");

	if ((ls = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
	{
		printf("cond not create socket :%d", WSAGetLastError());
	}
	printf("socket created\n");

	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);
	
	//Bind
	if (bind(ls, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
	{
		printf("Bind failed with error code : %d", WSAGetLastError());
	}
	puts("Bind done");

	listen(ls, 3);

	//Accept and incoming connection
	puts("Waiting for incoming connections...");

	c = sizeof(struct sockaddr_in);
	new_socket = accept(ls, (struct sockaddr *)&client, &c);
	if (new_socket == INVALID_SOCKET)
	{
		printf("accept failed with error code : %d", WSAGetLastError());
	}

	puts("Connection accepted");

	closesocket(ls);
    return 0;
}

