//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#ifndef SERVER_H
#define SERVER_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct
    {
        int ClientID;
        int NetState; //idk yet what this is probably some check if this player exsist or something
        
        int PosX;
        int PosY;
        int IsAlive;
    } Player;
    
    typedef struct
    {
        int Port;
        char aServername[32];
    } ServerSettings;
    
    
    
    
    /*
     Function: GetPlayerPosX
     Feteches the player position out of client buffers.
     
     Parameters:
     buffer - Pointer to the client data buffer.
     
     Returns:
     The X position of the player as an integer
     */
    
    int GetPlayerPosX(const char * pData);
    
    /*
     Function: GetPlayerPosY
     Feteches the player position out of client buffers.
     
     Parameters:
     buffer - Pointer to the client data buffer.
     
     Returns:
     The Y position of the player as an integer
     */
    
    int GetPlayerPosY(const char * pData);
    
    /*
     Function: GetPlayerID
     Feteches the player ClientID out of client buffers.
     
     Parameters:
     buffer - Pointer to the client data buffer.
     
     Returns:
     The ClientID of the player as an integer
     */
    
    int GetPlayerID(const char * pData);
    
    /*
     Function: MainDataJuggeling
     Reads recived client data and formats server send data
     
     Parameters:
     buffer - Pointer to the recived client data buffer.
     
     Returns:
     Nothing.
     But formats the pClientData,
     which should then be ready to be send back to the client
     in networking_server_osx.c or networking_server_win.cpp.
     */
    
    void MainDataJuggeling(char * pClientData);
    
    /*
     Function: GetNextClientID
     Checks for the next (lowest) unused client id
     
     Returns:
     client id on success
     -1 on failure (server full)
     */
    
    int GetNextClientID();
    
    /*
     Function: InitServer
     For now just cleaning the players array
     */
    
    void InitServer(ServerSettings * pSettings);
    
    /*
     Function: LoadServerSettings
     Reads server.cfg file in the chidraqul6 directory
     and stores results in the ServerSettings struct
     
     Returns:
     -1 on failure
     0 on success
     */
    
    int LoadServerSettings(ServerSettings * pSettings);


#ifdef __cplusplus
}
#endif
    
#endif // SERVER_H
