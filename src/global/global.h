//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#include "../server/server.h"

#ifndef GLOBAL_H
#define GLOBAL_H

// network

#define PACKAGE_SIZE 16
#define DATA_DELIMITER '_'
#define MAX_CLIENTS 16

// windows Family
#if defined(WIN32) || defined(_WIN32) || defined(__CYGWIN32__) || defined(__MINGW32__) || defined(WIN64) || defined(_WIN64)
#define CONF_FAMILY_WINDOWS 1
#endif

// unix family
#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#define CONF_FAMILY_UNIX 1
#endif

#if defined(__OpenBSD__)
#define CONF_FAMILY_UNIX 1
#endif

#if defined(__LINUX__) || defined(__linux__)
#define CONF_FAMILY_UNIX 1
#endif

#if defined(__GNU__) || defined(__gnu__)
#define CONF_FAMILY_UNIX 1
#endif

#if defined(MACOSX) || defined(__APPLE__) || defined(__DARWIN__)
#define CONF_FAMILY_UNIX 1
#endif

#endif // GLOBAL_H