//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#ifdef _WIN32

#include "networking_client_win.h"
#include "base.h"

#include <iostream>
#include <winsock2.h>

int SendPosition(int pos)
{
	WSADATA WSAData;
	SOCKET server;
	SOCKADDR_IN addr;

	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5555);

	connect(server, (SOCKADDR *)&addr, sizeof(addr));
	//std::cout << "Connected to server!" << std::endl;

	char aBuf[1024];
	str_format(aBuf, sizeof(aBuf), "%d", pos);

	send(server, aBuf, sizeof(aBuf), 0);
	//std::cout << "send: " << aBuf << std::endl;
	//std::cout << "Message sent!" << std::endl;

	memset(aBuf, 0, sizeof(aBuf));
	recv(server, aBuf, sizeof(aBuf), 0);



    closesocket(server);
	WSACleanup();

	//std::cout << "Socket closed." << std::endl << std::endl;

	return atoi(aBuf);
}
#endif
