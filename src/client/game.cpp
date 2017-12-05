//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#include "game.h"


void CGame::InitPlayers()
{
	for (int i = 0; i < MAX_PLAYERS; i++)
	{
		apPlayers[i] = new CPlayer;
	}

	pPlayer = apPlayers[0];
}
