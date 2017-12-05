//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#ifndef GAME_H
#define GAME_H

#include "player.h"

#define MAX_PLAYERS 5

class CGame
{
public:
	CPlayer *apPlayers[MAX_PLAYERS];
	CPlayer *pPlayer;

	void InitPlayers();
};


#endif //GAME_H
