//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#ifndef SERVER_H
#define SERVER_H

#ifdef __cplusplus
extern "C" {
#endif

    /*
     Function: GetDelimiterPos
     Performs a search for the num delimiter in a buffer.
     
     Parameters:
     buffer - Pointer to the buffer.
     delimiter - Delimiter to be found in the buffer.
     num - Find the num delimiter.
     
     Returns:
     Position of the num found delemiter in the string
     or -2 on error out of range
     or -1 on delmiter not found
     or -3 on super weird error
     */
    
    int GetDelimiterPos(const char * pData, char delimiter, int num);
    
    /*
     Function: GetPlayerPos
     Feteches the player position out of client buffers.
     
     Parameters:
     buffer - Pointer to the client data buffer.
     
     Returns:
     The X position of the player as an integer
     */
    
    int GetPlayerPos(const char * pData);
    
    /*
     Function: GetPlayerClientID
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

#ifdef __cplusplus
}
#endif
    
#endif // SERVER_H
