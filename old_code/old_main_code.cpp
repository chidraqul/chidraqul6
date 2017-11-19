//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c) 2017
//chidraqul6 includes

#include "base.cpp"

int posX = 0;
int posY = 0;
int world_sizeX = 20;
int world_sizeY = 5;
char skin = '#';
int i = 0;

void CreateWorld()
{
	char aWorld[20][5];
	for (int y = 0; y < world_sizeY; y++)
	{
		for (int x = 0; x < world_sizeX; x++)
		{
			aWorld[x][y] = '_';
		}
	}

	std::string World = "";


	aWorld[posX][posY] = skin;


	// output each array element's value                      
	for (int y = 0; y < world_sizeY; y++)
	{
		for (int x = 0; x < world_sizeX; x++) {
			World += aWorld[x][y];
		}
		World += "\n";
	}



	printf("fps: %d\n", i);
	printf("%s\n", World.c_str());
	printf("pos: %d|%d\n", posX, posY);

	//char aBuf[64];
	//std::cin >> aBuf;
}

void KeyPresses()
{
#ifdef _WIN32
        char msg[64] = {'x'};

        //https://msdn.microsoft.com/de-de/library/windows/desktop/dd375731(v=vs.85).aspx
        //if (GetAsyncKeyState(VK_UP))
        //{
        //        if (posY > 0)
        //        {
        //            posY--;
        //        }
        //        msg[0] = 'u';
        //}
        //else if (GetAsyncKeyState(VK_DOWN))
        //{
        //    if (posY < world_sizeY)
        //    {
        //        posY++;
        //    }
        //    msg[0] = 'd';
        //}
        //if (GetAsyncKeyState(VK_LEFT))
        //{
        //    if (posX > 0)
        //    {
        //        posX--;
        //    }
        //    msg[0] = 'u';
        //}
        //else if (GetAsyncKeyState(VK_RIGHT))
        //{
        //    if (posX < world_sizeX)
        //    {
        //        posX++;
        //    }
        //    msg[0] = 'd';
        //}
        //else if (GetAsyncKeyState(0x54)) //T
        //{
        //    //printf("The T Key Has Been Pressed\n");
        //    CreateWorld();
        //}
        i++;
        system("cls");
        Sleep(200);
#elif __APPLE__
    {
        if (kbhit() == 1)
        {
            if (posX > 0)
            {
                posX--;
            }
        }
        else if (kbhit() == 2)
        {
            if (posX < world_sizeX)
            {
                posX++;
            }        }
        else if (kbhit() == 3)
        {
            if (posY > 0)
            {
                posY--;
            }
        }
        else if (kbhit() == 4)
        {
            if (posY < world_sizeY)
            {
                posY++;
            }
        }
        
        i++;
        system("clear");
        usleep(1000);
    }
#elif __linux__
    {
        std::cout << "Linux keypress support coming soon.";
    }
#else
    {
        std::cout << "No operating system found.";
    }
#endif
}

int main()
{
    std::cout << "==================" << std::endl;
    std::cout << "   chidraqul6     " << std::endl;
    std::cout << " by ChillerDragon " << std::endl;
    std::cout << "==================" << std::endl;
    DetectOS();
    std::cin.get();

    
    while (true)
    {
        //KeyPresses();
        //CreateWorld();
        KeyPrinter();
    }
	
	

}
