//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 201

#include "chidraqul6.h"
#include "world.h"
#include "controls.h"
#include "render.h"

#ifdef _WIN32
#include "networking_client_win.h"
#elif (__APPLE__) || (__linux__)
#include "networking_client_osx.h"
#endif

CPlayer *pPlayer = new CPlayer;
CPlayer *pPlayer2 = new CPlayer;

void OnTick()
{ 
    HandleInputs(*pPlayer); //creates LastInpDirX
	pPlayer->OnTick(); //uses LastInpDirX to keep moving in fall
	int recv_pos = SendPosition(pPlayer->PosX);
	RenderFrame(*pPlayer, recv_pos);
	pPlayer2->Move(recv_pos,0,' ');
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

	pPlayer->Spawn();
	pPlayer2->Spawn();

    while (true)
    {
		OnTick();
    }
}
