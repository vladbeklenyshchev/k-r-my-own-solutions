#include "get_line.h"
#include <stdio.h>

char * get_line(char s[], int lim)
{
	int c, i;
	for(i = 0; i< lim - 1 && (c = getchar()) != EOF && c!='\n'; ++i)
		s[i] = c;

	if (c == '\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';

	return s;
}