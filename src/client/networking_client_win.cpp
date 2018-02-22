//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#ifdef _WIN32

#include "networking_client_win.h"
#include "../base/base.h"

#include <iostream>
#include <winsock2.h>

char * SendData(const char * pData, ClientSettings * pSettings)
{
	WSADATA WSAData;
	SOCKET server;
	SOCKADDR_IN addr;

	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	addr.sin_addr.s_addr = inet_addr(pSettings->aServerIP);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(pSettings->ServerPort);

	connect(server, (SOCKADDR *)&addr, sizeof(addr));
	//std::cout << "Connected to server!" << std::endl;

	char aBuf[1024];
	//str_format(aBuf, sizeof(aBuf), "%d", pos);
	//ClearConsole();

	send(server, pData, PACKAGE_SIZE-1, 0);
	//std::cout << "send: " << pData << std::endl;
	//std::cout << "Message sent!" << std::endl;

	memset(aBuf, 0, sizeof(aBuf));
	recv(server, aBuf, sizeof(aBuf), 0);



    closesocket(server);
	WSACleanup();

	//std::cout << "Socket closed." << std::endl << std::endl;

	char * pBuf = &aBuf[0];

	return pBuf;
}
#endif
