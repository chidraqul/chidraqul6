//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#include "../base/base.h"
#include "render.h"

#ifdef _WIN32
#include "networking_client_win.h"
#include "net_client.h"
#elif (__APPLE__) || (__linux__)
#include "networking_client_unix.h"
#include "net_client.h"
#endif

int GetServerPosX(const char * pData)
{
	char aPos[PACKAGE_SIZE];
	int str_start = GetDelimiterPos(pData, DATA_DELIMITER, 1) + 1;
	int str_end = GetDelimiterPos(pData, DATA_DELIMITER, 2);
	int index = 0;

	if (str_start < 0 || str_end < 0)
	{
		printf("[error] recived bad data s=%d e=%d data=%s\n", str_start, str_end, pData);
	}

	for (int i = str_start; i < str_end; i++)
	{
		aPos[index] = pData[i];
		index++;
	}
	aPos[index] = '\0';

	return atoi(aPos);
}

int GetServerData(const char * pData, int data_index)
{
	char aPos[PACKAGE_SIZE];
	int str_start = GetDelimiterPos(pData, DATA_DELIMITER, data_index + 1) + 1;
	int str_end = GetDelimiterPos(pData, DATA_DELIMITER, data_index + 2);
	int index = 0;

	if (str_start < 0 || str_end < 0)
	{
		printf("[error] recived bad data s=%d e=%d data=%s\n", str_start, str_end, pData);
	}

	for (int i = str_start; i < str_end; i++)
	{
		aPos[index] = pData[i];
		index++;
	}
	aPos[index] = '\0';

	return atoi(aPos);
}

int GetServerPosY(const char * pData)
{
	return GetServerData(pData, 1);
}

int GetServerPlayerX(const char * pData, int player)
{
	return GetServerData(pData, player * 2);
}

int GetServerPlayerY(const char * pData, int player)
{
	return GetServerData(pData, player * 2 + 1);
}

int GetServerCID(const char * pData)
{
	char aPlayerID[PACKAGE_SIZE];

	for (int i = 0; i < PACKAGE_SIZE; i++)
	{
		if (pData[i] == '\0' && pData[i] == DATA_DELIMITER)
		{
			aPlayerID[i] = '\0';
			break;
		}

		aPlayerID[i] = pData[i];
	}

	return atoi(aPlayerID);
}

int PumpNetwork(CPlayer& player, CPlayer& player2, ClientSettings * pSettings)
{
	char aSend[PACKAGE_SIZE];
	char aRecv[PACKAGE_SIZE];
	str_format(aSend, sizeof(aSend), "%d_%d_%d_", player.ClientID, player.PosX, player.PosY);

	//printf("DATA: %s SIZE: %d", aSend, sizeof(aSend));

	str_format(aRecv, sizeof(aRecv), "%s", SendData(aSend, pSettings));

	player.ClientID = GetServerCID(aRecv);
	player.PosX = GetServerPosX(aRecv);
	int p2_posX = GetServerPlayerX(aRecv, 1);
	int p2_posY = GetServerPlayerY(aRecv, 1);

	RenderFrame(player2, p2_posX);
	player2.UpdatePosition(p2_posX, p2_posY, ' ');

	return 0;
}
