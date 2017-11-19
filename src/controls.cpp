//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#ifdef _WIN32
#include <conio.h>
#endif // _WIN32


#include "base.h"
#include "controls.h"
#include "world.h"

int LastInpDirX;
//int LastInpDirY;

void HandleInputs(CPlayer& player)
{
#ifdef __APPLE__
	int key = getchar();
	if (key == 97)
	{
		if (player.PosX > 0)
		{
			player.PosX--;
		}
	}
	else if (key == 100)
	{
		if (player.PosX < 10)
		{
			player.PosX++;
		}
	}
#endif // __APPLE__
#ifdef _WIN32
	char key = '0';
	//LastInpDirX = 0;
	//LastInpDirY = 0;
	if (_kbhit() == 1)
	{
		key = getch();
	}
	if (key == 'a')
	{
		player.AimDir = -1; //set aimdir no matter if you walk agianst a wall
		if (player.PosX > 0)
		{
			LastInpDirX = -1;
			player.Move(-1,0,' ');
		}
	}
	else if (key == 'd')
	{
		player.AimDir = 1; //set aimdir no matter if you walk agianst a wall
		if (player.PosX < WORLD_SIZE_X)
		{
			LastInpDirX = 1;
			player.Move(1, 0, ' ');
		}
	}
	else if (key == 'w')
	{
		player.AimDir = -2; //set aimdir no matter if you walk agianst a wall
		if (player.IsGrounded())
		{
			player.IsJump = true;
		}
	}
	else if (key == 's')
	{
		player.AimDir = 2; //set aimdir no matter if you walk agianst a wall
		//if (player.PosY < 5) //we have garvity lol
		//{
		//	player.Move(0, 1, ' ');
		//}
	}
	else if (key == 'b')
	{
		player.PlaceBlock();
	}

	if (key == 'a' || key == 'd') //umoved left or right
	{
		player.LastInpResetTick = RESETLASTINP_SPEED;
	}
#endif // _WIN32
}
