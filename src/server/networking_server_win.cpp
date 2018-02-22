//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#ifdef _WIN32

#include "networking_server_win.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <winsock2.h>
#include "../base/system.h"
#include "server.h"

ServerSettings srv_settings;

int main()
{
	int port = 4200;
	InitServer(&srv_settings);
	port = srv_settings.Port;

	WSADATA WSAData;

	SOCKET server, client;

	SOCKADDR_IN serverAddr, clientAddr;

	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);

	bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));

	std::cout << "[server] started and listening on port " << port << std::endl;

	while (1)
	{
		listen(server, 0);

		//std::cout << "Listening for incoming connections..." << std::endl;

		char aBuf[PACKAGE_SIZE];
		int clientAddrSize = sizeof(clientAddr);
		if ((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
		{
			//std::cout << "Client connected!" << std::endl;

			//RECIVE data
			//memset(aBuf, 0, sizeof(aBuf));
			recv(client, aBuf, sizeof(aBuf), 0);
			//printf("[debug] recv=%s\n", aBuf);
			std::cout << "Client x[" << aBuf << "]" << std::endl;

			//PROCESS data (handelt in server.cpp)
			//str_format(aBuf, sizeof(aBuf), "%d", rand() % 3 - 1);
			MainDataJuggeling(aBuf);

			//SEND data
			send(client, aBuf, sizeof(aBuf), 0);
			std::cout << "Server x[" << aBuf << "]" << std::endl;
			memset(aBuf, 0, sizeof(aBuf));


			closesocket(client);
			//std::cout << "Client disconnected." << std::endl;
		}
	}
}

#endif
