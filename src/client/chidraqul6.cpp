//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

//windows clearup commit1


#include "chidraqul6.h"
#include "world.h"
#include "controls.h"
#include "render.h"

#ifdef _WIN32
#include "networking_client_win.h"
#elif (__APPLE__) || (__linux__)
#include "networking_client_osx.h"
#endif

CPlayer player;


void OnTick()
{ 
    HandleInputs(player); //creates LastInpDirX
	player.OnTick(); //uses LastInpDirX to keep moving in fall
	RenderFrame(player);
	SendPosition(player);
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
    
	player.Spawn();
    while (true)
    {
		OnTick();
    }
}
