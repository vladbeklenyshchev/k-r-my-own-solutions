#include <stdio.h>

/*get_line: get line into s, return length*/
int get_line(char s[], int lim)
{
	int c, i;
	for(i = 0; --lim > 0/*i< lim - 1*/ && (c = getchar()) != EOF && c!='\n'; ++i)
		s[i] = c;

	if (c == '\n')
	{
		s[i++] = c;
	}

	s[i] = '\0';

	return i;
}