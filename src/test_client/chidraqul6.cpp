//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#include "chidraqul6.h"
#include "world.h"
#include "controls.h"
#include "render.h"
#include "client.h"

#include "networking_client_osx.h"
#include "net_client.h"

CPlayer *pPlayer = new CPlayer;
CPlayer *pPlayer2 = new CPlayer;

void OnTick(ClientSettings * pSettings)
{ 
    HandleInputs(*pPlayer); //creates LastInpDirX
	pPlayer->OnTick(); //uses LastInpDirX to keep moving in fall
	PumpNetwork(*pPlayer, *pPlayer2, pSettings);
#ifdef __APPLE__
    //system("sleep 0.000000001"); //shit xd
#endif // __APPLE__
}

int main()
{
	ClientSettings client_settings;

    InitClient(&client_settings);
    printf("[client] press ENTER to start the game.\n");
    PauseGame();
    ChillClearScreen();
    std::cout << "==================" << std::endl;
    std::cout << "   chidraqul6     " << std::endl;
    std::cout << " by ChillerDragon " << std::endl;
    std::cout << "==================" << std::endl;
    DetectOS();
	PauseGame();
    
    
	InitWorld();
#if defined(__APPLE__) || defined(__linux__)
	initscr();
    system("stty -icanon time 0 min 0");
#endif // __APPLE__

	pPlayer->Spawn();
	pPlayer2->Spawn();

    
    //moved main loop in networking code
    NetworkMain(&client_settings, *pPlayer, *pPlayer2);
    
    /*
    while (true)
    {
		OnTick(&client_settings);
    }
     */
}
