//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017


#include "server.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../base/system.h"
#include "../network/network.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetPlayerID(const char * pData)
{
	char aPos[PACKAGE_SIZE]; //allocates too much memory because the whole data isn't only pos, but it runs faster because we only need 1 len check

	for (int i = 0; i < PACKAGE_SIZE; i++)
	{
		if (pData[i] == '\0' && pData[i] == DATA_DELIMITER)
		{
			aPos[i] = '\0';
			break;
		}

		//printf("[%d]='%c'\n", i, pData[i]);

		aPos[i] = pData[i];
	}

	return atoi(aPos);
}

void MainDataJuggeling(char * pClientData)
{
	char aBuf[PACKAGE_SIZE];
	//int pos = atoi(pClientData);
	int pos = 1;
	pos++;



	str_format(pClientData, PACKAGE_SIZE, "%d", pos);
}

#ifdef __cplusplus
}
#endif
