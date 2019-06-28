#include "Strdup.h"
#include <stdlib.h>
#include <string.h>

char * mystrdup(const char *s) /*make a duplicate of s*/
{
	char *p;

	p = (char *)malloc(strlen(s) + 1); /*+1 for '\0'*/
	if (p != NULL)
		strcpy(p, s);
	return p;
}