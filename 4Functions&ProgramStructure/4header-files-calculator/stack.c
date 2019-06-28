#include <stdio.h>
#include "calc.h"

#define MAXVAL 100 /*max depth of stack*/

/*definitions*/
static int sp = 0; /* next free stack position*/
static double var[MAXVAL]; /*value stack*/

void push(double item)
{
	if(sp < MAXVAL)
		var[sp++] = item;
	else
		printf("Overflow!!!\n");
}

double pop()
{
	if(sp > 0)
		return var[--sp];
	else 
	{
		printf("Underflow!!!\n");
		return 0.0;
	}
}