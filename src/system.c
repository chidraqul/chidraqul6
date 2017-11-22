//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#include "system.h"
#include <stdarg.h>
#include "stdlib.h"
#include "stdio.h"

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
