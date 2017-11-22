//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#include "base.h"
#include "render.h"
#include "controls.h" //TODO: remove me beause only used for debugging

void RenderFrame(CPlayer& player)
{
#ifdef __APPLE__
    /*
	refresh();
	move(2, 0);
	printw("__________");
	move(2, player.PosX);
	printw(&player.Skin);
	move(4, 9);
	int fps = rand() % 9;
    printw("fps: %d", fps);
	move(20, 30);
     */
    ChillSetCursor(0, 9);
    //std::cout << "Jump: " << player.IsJump << " " << "TilesJumped: " <<player.TilesJumped;
    PrintCurrentPos("Jump:");
    ChillSetCursor(0, 10);
    //std::cout << "DirX: " << LastInpDirX;
    PrintCurrentPos("DirX:");
    ChillSetCursor(0, 11);
    //std::cout << "AimDir:       "; //clear old value
    PrintCurrentPos("AimDir:");
    //ChillSetCursor(0, 11);
    //std::cout << "AimDir: " << player.AimDir;
#endif // __APPLE__
#ifdef _WIN32
	ChillSetCursor(0, 9);
	std::cout << "Jump: " << player.IsJump << " " << "TilesJumped: " <<player.TilesJumped;
	ChillSetCursor(0, 10);
	std::cout << "DirX: " << LastInpDirX;
	ChillSetCursor(0, 11);
	std::cout << "AimDir:       "; //clear old value
	ChillSetCursor(0, 11);
	std::cout << "AimDir: " << player.AimDir;
#endif // _WIN32
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

