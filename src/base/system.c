//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#include "system.h"
#include <stdarg.h>
#include "stdlib.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

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
