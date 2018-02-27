//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#include "render.h"
#include "player.h"
#include "controls.h"
#include "world.h"
#include "../base/base.h"

int aBlock[16][3]; // [INDEX] [0 = Alive 1 = PosX 2 = PosY]

bool CPlayer::IsCollision(int X, int Y)
{
	for (int i = 0; i < 16; i++) //iterate tru all 16 blocks
	{
		if (aBlock[i][0])
		{
			if (aBlock[i][1] == X && aBlock[i][2] == Y)
			{
				return true;
			}
		}
	}
	return false;
}

bool CPlayer::IsGrounded()
{
	if (IsCollision(PosX, PosY + 1) || PosY >= WORLD_SIZE_Y)
	{
		return true;
	}
	return false;
}

void CPlayer::Spawn()
{
	PosX = 5;
	PosY = 0;
	IsAlive = true;
	Move(0,0,' '); //update position to render frame
}

void CPlayer::Move(int dirX, int dirY, char world)
{
	if (IsAlive)
	{
		//remove old character
        char aBuf[64];
		ChillSetCursor(PosX, PosY);
        str_format(aBuf, sizeof(aBuf), "%c", world); //TODO: find better way to convert char to const char *
        PrintCurrentPos(aBuf);
		int OldPosX = PosX;
		int OldPosY = PosY;
		
		//used for falling down out of world prevention
		if (dirX < 0) //left 
		{
			if (PosX > 0 && dirX != 0) //left 
			{
				PosX = PosX + dirX;
			}
		}
		else if (dirX > 0) //right 
		{
			if (PosX < WORLD_SIZE_X && dirX != 0) //right 
			{
				PosX = PosX + dirX;
			}
		}
		PosY = PosY + dirY;

		//If collieded set on old position
		if (IsCollision(PosX, PosY))
		{
			if ((dirX && !dirY) || (!dirX && dirY)) //walked straight into it or fell straight into it
			{
				PosX = OldPosX;
				PosY = OldPosY;
			}
			else //diagonal fall
			{
				PosX = OldPosX; //keep falling
				//check agian if collided with new block
				if (IsCollision(PosX, PosY)) { PosY = OldPosY; }
			}
		}

		//print new character
		ChillSetCursor(PosX, PosY);
        str_format(aBuf, sizeof(aBuf), "%c", Skin);
        PrintCurrentPos(aBuf);
        str_format(aBuf, sizeof(aBuf), "x[%d] y[%d]", PosX, PosY);
        ChillSetCursor(0, 8);
        PrintCurrentPos("                     "); //cleanup
        ChillSetCursor(0, 8);
        PrintCurrentPos(aBuf);
	}
}

void CPlayer::UpdatePosition(int X, int Y, char world)
{
	if (IsAlive)
	{
		//remove old character
		char aBuf[64];
		ChillSetCursor(PosX, PosY);
		str_format(aBuf, sizeof(aBuf), "%c", world); //TODO: find better way to convert char to const char *
		PrintCurrentPos(aBuf);

		PosX = X;
		PosY = Y;

		//print new character
		ChillSetCursor(PosX, PosY);
		str_format(aBuf, sizeof(aBuf), "%c", Skin);
		PrintCurrentPos(aBuf);
		str_format(aBuf, sizeof(aBuf), "x[%d] y[%d]", PosX, PosY);
		ChillSetCursor(0, 8);
		PrintCurrentPos("                     "); //cleanup
		ChillSetCursor(0, 8);
		PrintCurrentPos(aBuf);
	}
}

void CPlayer::PlaceBlock()
{
	//check world border
	if ((AimDir == 1 && PosX >= WORLD_SIZE_X) || (AimDir == -1 && PosX - 1 <= 0) || (AimDir == 2 && PosY + 1 >= WORLD_SIZE_Y) || (AimDir == -2 && PosY - 1 <= 0))
	{
		return;
	}

	//search lowes free block index
	int BlockIndex = -1;
	for (int i = 0; i < 16; i++)
	{
		if (!aBlock[i][0]) //found unused block in array
		{
			BlockIndex = i;
			break;
		}
	}


	if (BlockIndex != -1)
	{
		aBlock[BlockIndex][0] = 1; //set to alive
		if (AimDir == -1) //left
		{
			aBlock[BlockIndex][1] = PosX - 1;
			aBlock[BlockIndex][2] = PosY;
		}
		else if (AimDir == 1) //right
		{
			aBlock[BlockIndex][1] = PosX + 1;
			aBlock[BlockIndex][2] = PosY;
		}
		else if (AimDir == -2) //up
		{
			aBlock[BlockIndex][1] = PosX;
			aBlock[BlockIndex][2] = PosY - 1;
		}
		else if (AimDir == 2) //down
		{
			aBlock[BlockIndex][1] = PosX;
			aBlock[BlockIndex][2] = PosY + 1;
		}

		//print block
		ChillSetCursor(aBlock[BlockIndex][1], aBlock[BlockIndex][2]);
        PrintCurrentPos("o");
	}




	//print message
	ChillSetCursor(2, 12);
	std::cout << "                   ";
	if (BlockIndex == -1)
	{
		ChillSetCursor(2, 12);
        PrintCurrentPos("no blocks");
	}
	else
	{
		ChillSetCursor(2, 12);
        PrintCurrentPos("block placed");
	}
}

void CPlayer::OnTick()
{
	PlayerTick++;
	if (IsAlive) //Player Physics
	{
		if (PosY < 5 && !IsJump && !IsGrounded()) //gravity
		{
			FallTick++;
			if (FallTick > FALLING_SPEED)
			{
				Move(LastInpDirX, 1, ' ');
				FallTick = 0;
			}
		}
		if (TilesJumped > 2 || PosY == 0) //jump tile checker
		{
			TilesJumped = 0;
			IsJump = false;
		}
		if (IsJump) //jumps
		{
			JumpTick++;
			if (JumpTick > JUMPING_SPEED)
			{
				Move(LastInpDirX, -1, ' ');
				TilesJumped++;
				JumpTick = 0;
			}
		}
	}
	if (LastInpResetTick)
	{
		LastInpResetTick--;
		if (LastInpResetTick == 1)
		{
			LastInpDirX = 0;
		}
	}
}

CPlayer::CPlayer() //Constructor
{
	ClientID = -1;
	PosX = 0;
	PosY = 0;
    Skin = 'x';
	IsAlive = false;
	IsJump = false;
	//std::cout << "Player Spawned" << std::endl;
}

CPlayer::~CPlayer() //Destructor
{
	//std::cout << "Player Destroyed" << std::endl;
}
