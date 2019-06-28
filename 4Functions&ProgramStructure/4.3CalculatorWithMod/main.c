#include <stdio.h>
#include <stdlib.h> /*for atof*/

#define MAXOP 100 /*max size of operand or operator*/
#define NUMBER '0' /*signal that a number was found*/

int getop(char s[]);
void push(double);
double pop(void);

int main(int argc, char const *argv[])
{
	int type;
	double op2; //temp variable for uncommutative operators
	char s[MAXOP];

	while((type = getop(s)) != EOF)
	{
		switch(type)
		{
			case NUMBER:
				push(atof(s));
				printf("%s\n", s);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				double op3 = pop();
				if(op2 != 0.0)
					push(op3 - op2*((int)(op3/op2)));
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				/*print a result*/
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

#define MAXVAL 100 /*max depth of stack*/

/*external variables*/
double var[MAXVAL]; /*value stack*/
int sp = 0; /* next free stack position*/

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

#include <ctype.h>

int getch(void);
void ungetch(int);

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

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;/* next free position in buf */

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
