#include <stdio.h>
#include <stdlib.h> /*for atof*/
#include <ctype.h>

#define MAXOP 100 /*max size of operand or operator*/
#define NUMBER '0' /*signal that a number was found*/
#define BUFSIZE 100

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;/* next free position in buf */

int getop(char s[]);
int getch(void);
void ungetch(int);
/*
Exercise 4-9
Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their properties ought to be if an EOF is pushed back,
then implement your design.

Brief explanation:
--
The problem is that the buffer array, buf, was declared as an array of char. However, EOF is represented as a negative value (typically -1).
If we try to store EOF (-1) in our char array, a conversion from int to char will occur. This is fine, because we will only be trimming some bits
on the left. However, when someone calls getch() in the next step, we will pop off our EOF from the char array, and because getch() returns an int, 
a conversion from char to int must occur. The ANSI C standard doesn't specify what happens when an int is converted to a char. If the leftmost bit of the char
is 1, the architecture may simply assume it's a negative number (because of 2's complement), and extend the sign untill it fills the whole word length with 1's,
or it can simply add 0's on the left positions untill word length is reached. If EOF was -1, this would work if the sign was extended, but it would depend on the architecture.
If EOF is not -1, then nothing would work.
The solution is to declare the buffer array as an int array instead of char, which will avoid any type conversions.
*/
int main(int argc, char const *argv[])
{
	int c;
	double op2; //temp variable for uncommutative operators
	char s[MAXOP];

	ungetch('2');
	ungetch('1');
	ungetch(EOF);
	printf("%c\n", getch());
	ungetch('1');

	return 0;
}

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
	return (bufp > 0) ? buf [--bufp] : getchar(); 
}

void ungetch(int c) /* возвращение символа в поток ввода */ 
{ 
	if (bufp >= BUFSIZE) 
		printf("ungetch: too many characters\n"); 
	else 
		buf [bufp++] = c; 
}