//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#include "base.h"
#include "render.h"
#include "controls.h" //TODO: remove me beause only used for debugging

void RenderFrame(CPlayer& player, int recv_pos)
{
	if (player.IsDebug)
	{
		char aBuf[128];

		ChillSetCursor(0, 9);
		str_format(aBuf, sizeof(aBuf), "Jump: %d TilesJumped: %d", player.IsJump, player.TilesJumped);
		PrintCurrentPos(aBuf);
		ChillSetCursor(0, 10);
		PrintCurrentPos("DirX:   "); //clear old value
		ChillSetCursor(0, 10);
		str_format(aBuf, sizeof(aBuf), "DirX: %d", LastInpDirX);
		PrintCurrentPos(aBuf);
		ChillSetCursor(0, 11);
		PrintCurrentPos("AimDir:       "); //clear old value
		ChillSetCursor(0, 11);
		str_format(aBuf, sizeof(aBuf), "AimDir: %d", player.AimDir);
		PrintCurrentPos(aBuf);
        ChillSetCursor(0, 12);
        str_format(aBuf, sizeof(aBuf), "recv: %d", recv_pos);
        PrintCurrentPos(aBuf);
	}
}


void ChillSetCursor(int x, int y)
{
#ifdef _WIN32
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#elif (__linux__) || (__APPLE__) //TODO: finish this
    /*
	initscr();
	refresh();
	move(10, 3);
	printw("UNFINISHED CODE");
	refresh();
	endwin(); //kills everything --> comment it out to use move() and print stuff
     */
    initscr();
    refresh();
    move(y,x);
    //refresh();
#endif
}

void PrintCurrentPos(const char * str)
{
#ifdef _WIN32
    std::cout << str;
#elif (__linux__) || (__APPLE__)
    printw(str);
#endif
}

