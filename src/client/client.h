//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#ifndef CLIENT_H
#define CLIENT_H

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
 
 Returns:
 0 on success or some fail code
 */

int InitClient();

/*
 Function: LoadSettings
 Loads the client configs from config.cfg
 
 Parameter:
 filename - settings file name without path
 
 Returns:
 0 on success
 -1 on fail
 */

int LoadSettings(char * filename);

#endif
