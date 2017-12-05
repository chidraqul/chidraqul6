//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 201

#include "chidraqul6.h"
#include "world.h"
#include "controls.h"
#include "render.h"
#include "game.h"

#ifdef _WIN32
#include "networking_client_win.h"
#elif (__APPLE__) || (__linux__)
#include "networking_client_osx.h"
#endif

CGame *pGame = new CGame;

void OnTick()
{ 
    HandleInputs(*pGame->pPlayer); //creates LastInpDirX
	pGame->pPlayer->OnTick(); //uses LastInpDirX to keep moving in fall
	int recv_pos = SendPosition(pGame->pPlayer->PosX);
	RenderFrame(*pGame->pPlayer, recv_pos);
	//player_net.PosX = recv_pos;
#ifdef __APPLE__
    //system("sleep 0.000000001"); //shit xd
#endif // __APPLE__
}

int main()
{
    std::cout << "==================" << std::endl;
    std::cout << "   chidraqul6     " << std::endl;
    std::cout << " by ChillerDragon " << std::endl;
    std::cout << "==================" << std::endl;
    DetectOS();
	PauseGame();
    
    
	InitWorld();
#ifdef __APPLE__
	initscr();
    system("stty -icanon time 0 min 0");
#endif // __APPLE__
    
	pGame->InitPlayers();
	
	for (int i = 0; i < MAX_PLAYERS; i++)
	{
		pGame->apPlayers[i]->Spawn();
	}

    while (true)
    {
		OnTick();
    }
}
