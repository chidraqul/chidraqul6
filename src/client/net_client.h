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

int PumpNetwork(CPlayer& player, CPlayer& player2, ClientSettings * pSettings);

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
Function: GetServerPosY
Feteches the client pos y out of the server buffer.

Parameters:
buffer - Pointer to the server data buffer.

Returns:
The pos y of the player as an integer
*/

int GetServerPosY(const char * pData);

/*
Function: GetServerPlayerX
Feteches the client pos x out of the server buffer.

Parameters:
buffer - Pointer to the server data buffer.
player - Which player should be fetched;.

Returns:
The pos x of the player as an integer
*/

int GetServerPlayerX(const char * pData, int player);

/*
Function: GetServerPlayerY
Feteches the client pos y out of the server buffer.

Parameters:
buffer - Pointer to the server data buffer.
player - Which player should be fetched;.

Returns:
The pos y of the player as an integer
*/

int GetServerPlayerY(const char * pData, int player);

/*
Function: GetServerData
Feteches the data at data_index out of the server buffer.

Parameters:
buffer - Pointer to the server data buffer.
data_index - Which index in the server buffer should be fetched

Index:
- 0 Own posX
- 1 Own posY
- 2 Other posX
- 3 Other posY

Returns:
The data_index element of the data buffer recvied from the server
*/

int GetServerData(const char * pData, int data_index);

#endif
