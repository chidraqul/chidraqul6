//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017


#ifndef SYSTEM_H
#define SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

	/*
	Function: str_format
	Performs printf formating into a buffer.

	Parameters:
	buffer - Pointer to the buffer to recive the formated string.
	buffer_size - Size of the buffer.
	format - printf formating string.
	... - Parameters for the formating.

	Returns:
	Length of written string

	Remarks:
	- See the C manual for syntax for the printf formating string.
	- The strings are treated as zero-termineted strings.
	- Garantees that dst string will contain zero-termination.
	*/
	
	int str_format(char *buffer, int buffer_size, const char *format, ...); // Proudly stolen from Teeworlds

#ifdef __cplusplus
}
#endif

#endif // !SYSTEM_H
