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

void MainDataJuggeling(char * pClientData)
{
	char aBuf[128];
	int pos = atoi(pClientData);
	pos++;



	str_format(pClientData, sizeof(pClientData), "%d", pos);
}

#ifdef __cplusplus
}
#endif
