//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#include "base.h"


void PauseGame()
{
#ifdef _WIN32
	system("pause >NUL");
#elif (__linux__) || (__APPLE__)
	system("read -n1");
#endif
}

void ChillClearScreen()
{
#ifdef _WIN32
	system("cls");
#endif // _WIN32
}

int DetectOS() //if no compile move me to chidraqul.cpp
{
#ifdef _WIN32
    std::cout << "detected win\n";
    return 1;
#elif __APPLE__
    std::cout << "detected os x\n";
    return 2;
#elif __linux__
    std::cout << "detected linux\n"
    return 3;
#else
    return -1;
    std::cout << "unsupported oss\n";
#endif
}

#ifdef __APPLE__
int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    
    ch = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    
    if (ch == '\033') { // if the first value is esc
        getchar(); // skip the [
        switch(ch) { // the real value
            case 'A':
                // code for arrow up
                return 3;
                break;
            case 'B':
                // code for arrow down
                return 4;
                break;
            case 'C':
                // code for arrow right
                return 2;
                break;
            case 'D':
                // code for arrow left
                return 1;
                break;
        }
    }
    
    /*
     if(ch != EOF)
     {
     ungetc(ch, stdin);
     return 2;
     }
    */
    
    /*
    if (ch == 68) //left
    {
        return 1;
    }
    else if (ch == 67) //right
    {
        return 2;
    }
    else if (ch == 65) //up
    {
        return 3;
    }
    else if (ch == 66) //down
    {
        return 4;
    }
    */
    
    return 0;
}

void KeyPrinter() //a == 97 d == 100
{
    int ch;
    
    while ((ch = getchar()) != 27) /* 27 = Esc key */
    {
        printf("%d", ch);
        if (ch == 0 || ch == 224)
            printf (", %d", getchar());
        printf("\n");
    }
    
    printf("ESC %d\n", ch);
}
#endif

