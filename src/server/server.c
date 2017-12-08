//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017


#include "server.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../base/system.h"

#ifdef __cplusplus
extern "C" {
#endif

	Player *apPlayers[MAX_CLIENTS];
    
    int GetPlayerPos(const char * pData)
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

    int GetPlayerID(const char * pData)
    {
        char aPlayerID[PACKAGE_SIZE]; //allocates too much memory because the whole data isn't only pos, but it runs faster because we only need 1 len check
        
        for (int i = 0; i < PACKAGE_SIZE; i++)
        {
            if (pData[i] == '\0' && pData[i] == DATA_DELIMITER)
            {
                aPlayerID[i] = '\0';
                break;
            }
            
            //printf("[%d]='%c'\n", i, pData[i]);
            
            aPlayerID[i] = pData[i];
        }
        
        return atoi(aPlayerID);
    }
    
    void MainDataJuggeling(char * pClientData)
    {
        printf("[debug] init data juggle");
        char aBuf[PACKAGE_SIZE];

		//identification
		int id = GetPlayerID(pClientData);
		if (id == -1) //client requests id
		{
			//get next free id
			id = GetNextClientID();
			if (id == -1)
			{
				printf("[error] player id=%d failed", id);
				return;
			}

			apPlayers[id] = malloc(sizeof *apPlayers[id]);
			apPlayers[id]->PosX = 5;
			apPlayers[id]->PosY = 0;
			apPlayers[id]->ClientID = id;
			printf("[player] added new player with id=%d\n", id);
		}

        printf("[debug] movement");

		//movement
        int pos = GetPlayerPos(pClientData);
		apPlayers[id]->PosX = pos;

		//send other players pos
		int pos2 = -1;
		for (int i = 0; i < MAX_CLIENTS; i++)
		{
			if (apPlayers[i] && apPlayers[i]->ClientID != id)
			{
				pos2 = apPlayers[i]->PosX;
				break;
			}
		}
        
        printf("[debug] done data juggle in fun");
        
        str_format(pClientData, PACKAGE_SIZE, "%d_%d_%d_", id, pos, pos2);
    }

	int GetNextClientID()
	{
		for (int i = 0; i < MAX_CLIENTS; i++)
		{
			if (!apPlayers[i])
				return i;
		}
		return -1;
	}

	void InitServer()
	{
		for (int i = 0; i < MAX_CLIENTS; i++)
		{
			apPlayers[i] = NULL;
		}
	}

#ifdef __cplusplus
}
#endif
