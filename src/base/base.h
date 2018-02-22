//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#ifdef _WIN32
#include <Windows.h>
#include <wincon.h>
#elif (__APPLE__) || (__linux__)
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <curses.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#endif

#include "system.h"


/*
 Function: kbhit
 Performs a keypress check
 
 Returns:
 Keycode as integer
 */

#ifdef __APPLE__
int kbhit(void);
#endif

/*
 Function: KeyPrinter
 Produces a debuging output for keypresses
 */

#ifdef __APPLE__
void KeyPrinter();
#endif

/*
 Function: PauseGame
 Performs a pause consol command with os depended commands
 The programm stops until a key gets pressed
 */

void PauseGame();

/*
 Function: ChillClearScreen
 Performs a clear consol command with os depended commands
 */

void ChillClearScreen();

/*
 Function: DetectOS
 Performs a operating system check
 */

int DetectOS();

/*
 Function: GotoChidraqulFolder
 Performs a system call to navigate into chidraqul folder
 if no folder found --> create one
 */

int GotoChidraqulFolder();

#endif //BASE_H
