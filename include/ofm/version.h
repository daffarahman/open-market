#include <string.h>

#ifndef OFM_VERSION

#define OFM_VERSION

#define PROGRAM_NAME "ofm"
#define PROGRAM_NAME_LONG "Open Food Market"

#define PROGRAM_VERSION "4.0.36"

#define CODE_NAME "Denali"

char* get_version_info()
{
	char * str = (char*)malloc(sizeof(char) * 255);
	strcpy(str, PROGRAM_NAME_LONG);
	strcat(str, "\n");
	strcat(str, "Version ");
	strcat(str, PROGRAM_VERSION);
	strcat(str, " (");
	strcat(str, CODE_NAME);
	strcat(str, ")\n");
	return str;
}

#endif
