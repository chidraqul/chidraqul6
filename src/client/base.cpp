//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#include "base.h"

#ifdef _WIN32
#include <direct.h>
#endif // _WIN32


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
#else
    system("clear");
#endif
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
    std::cout << "detected linux\n";
    return 3;
#else
    return -1;
    std::cout << "unsupported oss\n";
#endif
}

int GotoChidraqulFolder()
{
#ifdef _WIN32
	char* appdata = getenv("APPDATA");
    if (_chdir(appdata))
    {
        printf("[client] failed to set working directory\n");
		return -1;
    }
    system("if not exist \"chidraqul\\\" mkdir chidraqul\\");
    if (_chdir("chidraqul"))
    {
        printf("[client] failed to enter chidraqul directory\n");
        return -1;
    }
    system("if not exist \"chidraqul6\\\" mkdir chidraqul6\\");
    if (_chdir("chidraqul6"))
    {
        printf("[client] failed to enter chidraqul6 directory\n");
        return -1;
    }
#elif __APPLE__
    chdir(getenv("HOME"));
    if (chdir("Library/Application Support/"))
    {
        printf("[client] failed to set working directory\n");
        return -1;
    }
    system("mkdir -p chidraqul");
    if (chdir("chidraqul/"))
    {
        printf("[client] failed to enter chidraqul directory\n");
        return -1;
    }
    system("mkdir -p chidraqul6");
    if (chdir("chidraqul6/"))
    {
        printf("[client] failed to enter chidraqul6 directory\n");
        return -1;
    }
#elif __linux__
    if (chdir(getenv("HOME")))
    {
        printf("[client] failed to set working directory\n");
        return -1;
    }
    system("mkdir -p chidraqul");
    if (chdir("chidraqul/"))
    {
        printf("[client] failed to enter chidraqul directory\n");
        return -1;
    }
    system("mkdir -p chidraqul6");
    if (chdir("chidraqul6/"))
    {
        printf("[client] failed to enter chidraqul6 directory\n");
        return -1;
    }
#else
    printf("[client] error OS not supported");
    return -1;
#endif
    return 0;
}

#if defined(__APPLE__) || defined(__linux__)
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

