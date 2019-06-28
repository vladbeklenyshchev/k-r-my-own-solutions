#include <ctype.h> 
#include <stdio.h>

#define SIZE 100

int getch(void);
void ungetch(int);

int main(int argc, char const *argv[])
{
	int n, array[SIZE], getint(int *) ; 
	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++) 
		printf("%d ", array[n]);
	return 0;
}

/* getint: считывает очередное целое число 
из входного потока в *рп */ 
int getint(int *pn) 
{ 
	int c, sign = 1; 
	
	while (isspace(c= getch()) || c == '+' || c == '-')
		if (c=='-')
			sign = -1;
		else if (c=='+')
			sign = 1;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-') { 
		ungetch(c); /*not a number*/
		return 0; 
	} 
	
	if (c == '+' || c == '-' ) 
		/* previous version
		*c = getch();
		*/
		if(!isdigit(c = getch()))
		{
			if(sign) ungetch('+');
			else ungetch('-');
			return getint(pn);
		}
		
	for(*pn = 0; isdigit(c); c = getch()) 
		*pn = 10 * *pn + (c - '0');
	
	*pn *= sign; 
	if (c != EOF) 
		ungetch(c);
	return c; 
} 

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;/* next free position in buf */

int getch()
{
	return (bufp > 0) ? buf [--bufp] : getchar(); 
}

void ungetch(int c)
{ 
	if (bufp >= BUFSIZE) 
		printf("ungetch: too many characters\n"); 
	else 
		buf [bufp++] = c; 
} 