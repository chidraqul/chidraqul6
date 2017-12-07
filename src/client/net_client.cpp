//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#include "base.h"
#include "render.h"
#include "../network/network.h"

#ifdef _WIN32
#include "networking_client_win.h"
#elif (__APPLE__) || (__linux__)
#include "networking_client_osx.h"
#endif

int PumpNetwork(CPlayer& player, CPlayer& player2)
{
	char aBuf[PACKAGE_SIZE];
	str_format(aBuf, PACKAGE_SIZE, "%d_%d_", player.ClientID, player.PosX);

	//printf("DATA: %s SIZE: %d", aBuf, sizeof(aBuf));

	int recv_pos = SendData(aBuf);
	RenderFrame(player2, recv_pos);
	player2.UpdatePosition(recv_pos, 0, ' ');

	return 0;
}
