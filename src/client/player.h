//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#ifndef PLAYER_H
#define PLAYER_H

#include "../base/base.h"

#define FALLING_SPEED 120
#define JUMPING_SPEED 210
#define RESETLASTINP_SPEED 620

class CPlayer {
private:
public:
	int PlayerTick;

	int ClientID;
	int AimDir;
	int PosX;
	int PosY;
    char Skin;
	bool IsAlive;
	bool IsJump;
	int TilesJumped;
	int JumpTick;
	int FallTick;
	int LastInpResetTick;
    char DebugMsg[1024];
	bool IsCollision(int X, int Y);
	bool IsGrounded();
	void Spawn();
	void Move(int dirX, int dirY, char world);
	void UpdatePosition(int X, int Y, char world);
	void PlaceBlock();
	void OnTick();

	//settings
	bool IsDebug;

	//Constructror
	CPlayer();

	//Destructor
	~CPlayer();
};


#endif
