#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c;
	static int buf = 0;
	if (buf != 0)
	{
		c = buf;
		buf = 0; /* !!!!!!! */
	}
	else c = getch();
	while((s[0] = c)== ' ' || c == '\t')
		c = getch();

	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c; /* not a number*/
	
	/*if it's a number*/
	i = 0;
	if(isdigit(c))	/* collect integer part */
		while(isdigit(s[++i] = c = getch()))
			;

	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;

	s[i] = '\0';
	if(c != EOF)
		buf = c;

	return NUMBER;
}