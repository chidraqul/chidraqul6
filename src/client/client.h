//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#ifndef CLIENT_H
#define CLIENT_H

/*
Struct: ClientSettings

Saves all the global config values
- server ip
- server port
- username
- you
- get
- the
- point
*/

typedef struct
{
	char aServerIP[32];
	int ServerPort;
	char aUsername[32];
} ClientSettings;

/*
 Function: CreateSettings
 Creates new config file with default settings in the chidraqul6 dir
 
 Parameter:
 filename - settings file name without path
 
 Returns:
 0 on success
 -1 on fail
 */

int CreateSettings(char * filename);

/*
 Function: InitClient
 Performs an client initialization and loads all the stuff
 
 Parameter:
 pSettings - a pointer to the settings struct

 Returns:
 0 on success or some fail code
 */

int InitClient(ClientSettings * pSettings);

/*
 Function: LoadSettings
 Loads the client configs from config.cfg
 
 Parameters:
 filename - settings file name without path
 pSettings - a pointer to the settings struct
 
 Returns:
 0 on success
 -1 on fail
 */

int LoadSettings(char * filename, ClientSettings * pSettings);

#endif
