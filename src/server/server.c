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
    
    int GetPlayerPosX(const char * pData)
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

	int GetPlayerPosY(const char * pData)
	{
		char aPos[PACKAGE_SIZE];
		int str_start = GetDelimiterPos(pData, DATA_DELIMITER, 2) + 1;
		int str_end = GetDelimiterPos(pData, DATA_DELIMITER, 3);
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
        //printf("[debug] init main data juggle\n");
        char aBuf[PACKAGE_SIZE];

        
		//identification
        int id = -2;
		id = GetPlayerID(pClientData);
        if (id < -1)
        {
            printf("[error] id failed id=%d\n", id);
            return;
        }
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
        if (!apPlayers[id])
        {
            printf("[error] clientid=%d not vaild\n", id);
            return; //TODO: handle this error
        }


		//movement
        int posX = GetPlayerPosX(pClientData);
		int posY = GetPlayerPosY(pClientData);
        
        apPlayers[id]->PosX = posX;
        apPlayers[id]->PosY = posY;
        
        

		//send other players pos
		int pos2X = -1;
		int pos2Y = -1;
		for (int i = 0; i < MAX_CLIENTS; i++)
		{
			if (apPlayers[i] && apPlayers[i]->ClientID != id)
			{
				pos2X = apPlayers[i]->PosX;
				pos2Y = apPlayers[i]->PosY;
				break;
			}
		}
         
        str_format(pClientData, PACKAGE_SIZE-1, "%d_%d_%d_%d_%d_", id, posX, posY, pos2X, pos2Y);
        
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

	void InitServer(ServerSettings * pSettings)
	{
		for (int i = 0; i < MAX_CLIENTS; i++)
		{
			apPlayers[i] = NULL;
		}

		int set = LoadServerSettings(pSettings);

		if (set == -1) //load default settings on error
		{
			printf("[server] loading default settings...\n");
			pSettings->Port = 4200;
		}
	}

	int LoadServerSettings(ServerSettings * pSettings)
	{
		char aSettingsFile[128] = "server.cfg";
		char aBuf[128];

		printf("[server] Init...\n");
		if (GotoChidraqulFolder("server"))
		{
			printf("[server] error loading chidraqul6 dir\n");
			printf("[server] skipping settings load\n");
		}
		else
		{
			printf("[server] loading settings...\n");
			
			FILE *pServerSettingsFile;

			pServerSettingsFile = fopen(aSettingsFile, "r");
			if (pServerSettingsFile == NULL)
			{
				printf("[server] error: failed to load settings \n");
				return -1;
			}

			fscanf(pServerSettingsFile, "%s", aBuf);
			printf("[debug] loaded=%s \n", aBuf);
			pSettings->Port = atoi(aBuf);
			fclose(pServerSettingsFile);

			printf("[server] loaded port=%d \n", pSettings->Port);
		}
		return 0;
	}

#ifdef __cplusplus
}
#endif
