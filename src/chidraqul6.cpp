//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

//windows clearup commit1


#include "chidraqul6.h"
#include "world.h"
#include "controls.h"
#include "render.h"

CPlayer player;


void OnTick()
{ 
    HandleInputs(player); //creates LastInpDirX
	player.OnTick(); //uses LastInpDirX to keep moving in fall
	RenderFrame(player);
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
