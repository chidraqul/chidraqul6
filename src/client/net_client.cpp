//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#include "base.h"
#include "render.h"

#ifdef _WIN32
#include "networking_client_win.h"
#elif (__APPLE__) || (__linux__)
#include "networking_client_osx.h"
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

int GetServerOtherPosX(const char * pData, int player_num)
{
	char aPos[PACKAGE_SIZE];
	int str_start = GetDelimiterPos(pData, DATA_DELIMITER, player_num + 1) + 1;
	int str_end = GetDelimiterPos(pData, DATA_DELIMITER, player_num + 2);
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

int PumpNetwork(CPlayer& player, CPlayer& player2)
{
	char aSend[PACKAGE_SIZE];
	char aRecv[PACKAGE_SIZE];
	str_format(aSend, PACKAGE_SIZE, "%d_%d____", player.ClientID, player.PosX);

	//printf("DATA: %s SIZE: %d", aSend, sizeof(aSend));

	str_format(aRecv, sizeof(aRecv), "%s", SendData(aSend));

	player.ClientID = GetServerCID(aRecv);
	player.PosX = GetServerPosX(aRecv);
	int p2_pos = GetServerOtherPosX(aRecv, 1);

	RenderFrame(player2, p2_pos);
	player2.UpdatePosition(p2_pos, 0, ' ');

	return 0;
}
