//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#ifndef NET_CLIENT_H
#define NET_CLIENT_H

#include "player.h"

/*
Function: PumpNetwork
Performs an exchange of data with the server and updates the game

Parameters:
- not 
- sure 
- yet
- lul

Returns:
- 0 on success
- everything else on error

*/

int PumpNetwork(CPlayer& player, CPlayer& player2);

/*
Function: GetServerCID
Feteches the client id out of the server buffer.

Parameters:
buffer - Pointer to the server data buffer.

Returns:
The ClientID of the player as an integer
*/

int GetServerCID(const char * pData);

/*
Function: GetServerPosX
Feteches the client pos x out of the server buffer.

Parameters:
buffer - Pointer to the server data buffer.

Returns:
The pos x of the player as an integer
*/

int GetServerPosX(const char * pData);

/*
Function: GetServerOtherPosX
Feteches the pos x of an specific players on the server out of the server buffer.

Parameters:
buffer - Pointer to the server data buffer.
player_num - Which player should be requested

Returns:
The pos x of the player player_num as an integer
*/

int GetServerOtherPosX(const char * pData, int player_num); //TODO: use this also for own pos and remove GetServerPosX() func

#endif
