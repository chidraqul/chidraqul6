//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#ifdef _WIN32

#include "networking_server_win.h"

#include <iostream>
#include <winsock2.h>
#include "../base/system.h"

int main()
{
	WSADATA WSAData;

	SOCKET server, client;

	SOCKADDR_IN serverAddr, clientAddr;

	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(5555);

	bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));


	while (1)
	{
		listen(server, 0);

		std::cout << "Listening for incoming connections..." << std::endl;

		char aBuf[1024];
		int clientAddrSize = sizeof(clientAddr);
		if ((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
		{
			//std::cout << "Client connected!" << std::endl;

			recv(client, aBuf, sizeof(aBuf), 0);
			std::cout << "Client x[" << aBuf << "]" << std::endl;
			memset(aBuf, 0, sizeof(aBuf));


			closesocket(client);
			//std::cout << "Client disconnected." << std::endl;
		}
	}
}

#endif
