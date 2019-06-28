#include <ctype.h> 
#include <stdio.h>

#define SIZE 100

int getch(void);
void ungetch(int);

int main(int argc, char const *argv[])
{
	float array[SIZE];
	int n, getfloat(float *); 
	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++) 
		printf("%f ", array[n]);
	return 0;
}

/* getint: считывает очередное целое число 
из входного потока в *рп */ 
int getfloat(float *pn) 
{ 
	int c, sign = 1;
	float power;
	
	while (isspace(c= getch()))
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-') { 
		ungetch(c); /*not a number*/
		return 0; 
	} 
	
	sign = (c == '-') ? -1 : 1;

	if (c == '+' || c == '-' ) 
		c = getch();

	for(*pn = 0.0; isdigit(c); c = getch()) 
		*pn = 10.0 * *pn + (c - '0');

	if (c == '.')
		c = getch();

	for(power = 1.0; isdigit(c); c = getch())
	{
		*pn = 10.0 * *pn + (c - '0');
		power *= 10;
	}
	
	*pn = sign * *pn / power; 

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