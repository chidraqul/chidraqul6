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
    
    int GetDelimiterPos(const char * pData, char delimiter, int num)
    {
        if (num < 1)
        {
            printf("[error] GetDelimiterPos() num=%d\n", num);
            return -2;
        }
        
        int found = 0;
        for (int i = 0; i < PACKAGE_SIZE; i++)
        {
            if (pData[i] == '\0')
            {
                return -1;
            }
            else if (pData[i] == delimiter)
            {
                found++;
                if (found == num)
                {
                    return i;
                }
            }
        }
        
        printf("[error] GetDelimiterPos() failed delimiter=%c num=%d data=%s\n", delimiter, num, pData);
        return -3;
    }
    
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
        char aBuf[PACKAGE_SIZE];
        int pos = GetPlayerPos(pClientData);
        pos++;
        
        
        str_format(pClientData, PACKAGE_SIZE, "%d", pos);
    }

#ifdef __cplusplus
}
#endif
