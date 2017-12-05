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

#ifdef __APPLE__
int kbhit(void);
void KeyPrinter();
#endif

void PauseGame();
void ChillClearScreen();
int DetectOS();

#endif //BASE_H
