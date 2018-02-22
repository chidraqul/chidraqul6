//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#include "system.h"
#include <stdarg.h>
#include "stdlib.h"
#include "stdio.h"
#ifdef _WIN32
#include <direct.h>
#else
#include <unistd.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif
    
	void ClearConsole()
	{
#ifdef _WIN32
		system("cls");
#else
		system("clean");
#endif // _WIN32

	}

	int GotoChidraqulFolder(const char * env)
	{
#ifdef _WIN32
		char* appdata = getenv("APPDATA");
		if (_chdir(appdata))
		{
			printf("[%s] failed to set working directory\n", env);
			return -1;
		}
		system("if not exist \"chidraqul\\\" mkdir chidraqul\\");
		if (_chdir("chidraqul"))
		{
			printf("[%s] failed to enter chidraqul directory\n", env);
			return -1;
		}
		system("if not exist \"chidraqul6\\\" mkdir chidraqul6\\");
		if (_chdir("chidraqul6"))
		{
			printf("[%s] failed to enter chidraqul6 directory\n", env);
			return -1;
		}
#elif __APPLE__
		chdir(getenv("HOME"));
		if (chdir("Library/Application Support/"))
		{
			printf("[%s] failed to set working directory\n", env);
			return -1;
		}
		system("mkdir -p chidraqul");
		if (chdir("chidraqul/"))
		{
			printf("[%s] failed to enter chidraqul directory\n", env);
			return -1;
		}
		system("mkdir -p chidraqul6");
		if (chdir("chidraqul6/"))
		{
			printf("[%s] failed to enter chidraqul6 directory\n", env);
			return -1;
		}
#elif __linux__
		if (chdir(getenv("HOME")))
		{
			printf("[%s] failed to set working directory\n", env);
			return -1;
		}
		//system("mkdir -p chidraqul;echo \"[client] successfully created chidraqul6 directory\";pwd");
		system("mkdir -p .chidraqul");
		if (chdir(".chidraqul/"))
		{
			printf("[%s] failed to enter chidraqul directory\n", env);
			return -1;
		}
		system("mkdir -p chidraqul6");
		if (chdir("chidraqul6/"))
		{
			printf("[%s] failed to enter chidraqul6 directory\n", env);
			return -1;
		}
#else
		printf("[%s] error OS not supported\n", env);
		return -1;
#endif
		return 0;
	}

	int GetDelimiterPos(const char * buffer, char delimiter, int num)
	{
		if (num < 1)
		{
			printf("[error] GetDelimiterPos() num=%d\n", num);
			return -2;
		}

		int found = 0;
		for (int i = 0; i < PACKAGE_SIZE; i++)
		{
			if (buffer[i] == '\0')
			{
				return -1;
			}
			else if (buffer[i] == delimiter)
			{
				found++;
				if (found == num)
				{
					return i;
				}
			}
		}

		printf("[error] GetDelimiterPos() failed delimiter=%c num=%d data=%s\n", delimiter, num, buffer);
		return -3;
		}

	int str_format(char *buffer, int buffer_size, const char *format, ...)
	{
		int ret;
#if defined(CONF_FAMILY_WINDOWS)
		va_list ap;
		va_start(ap, format);
		ret = _vsnprintf(buffer, buffer_size, format, ap);
		va_end(ap);
#else
		va_list ap;
		va_start(ap, format);
		ret = vsnprintf(buffer, buffer_size, format, ap);
		va_end(ap);
#endif

		buffer[buffer_size - 1] = 0; /* assure null termination */
		return ret;
	}

#ifdef __cplusplus
}
#endif
