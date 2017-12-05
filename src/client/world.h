//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#ifndef WORLD_H
#define WORLD_H

#include "player.h"

#define WORLD_SIZE_X 20
#define WORLD_SIZE_Y 5


extern int aBlock[16][3]; // [INDEX] [0 = Alive 1 = PosX 2 = PosY]

void ResetWorld();
void PrintWorld();
void InitWorld();

#endif // !WORLD_H

