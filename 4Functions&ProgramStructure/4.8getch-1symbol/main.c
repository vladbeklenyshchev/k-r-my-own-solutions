#include <stdio.h>
#include <stdlib.h> /*for atof*/
#include <ctype.h>

#define MAXOP 100 /*max size of operand or operator*/
#define NUMBER '0' /*signal that a number was found*/
#define BUFSIZE 100

int getop(char s[]);
int getch(void);
void ungetch(int);

int main(int argc, char const *argv[])
{
	int c;
	double op2; //temp variable for uncommutative operators
	char s[MAXOP];

	ungetch('2');
	ungetch('1');
	printf("%c\n", getch());
	ungetch('1');

	return 0;
}

char buf = 0;

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c, tmp;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	if (!isdigit(c) && c != '.')
		if(c == '-')
			if(isdigit(tmp = getch()))
				/*sign -*/
				ungetch(tmp);
			else
			{
				/*operator -*/
				ungetch(tmp);
				return c;
			}
		/*not a number and not a '-'*/
		else return c;
	
	/*if it's a number*/
	i = 0;

	if(isdigit(c) || c == '-')	/* collect integer part */
		while(isdigit(s[++i] = c = getch()))
			;

	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;

	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

int getch()
{
	char tmp;
	if(buf != 0){tmp = buf; buf = 0; return tmp; }
	else getchar(); 
}

/*overwrite the buffer*/
void ungetch(int c){ buf = c; }
