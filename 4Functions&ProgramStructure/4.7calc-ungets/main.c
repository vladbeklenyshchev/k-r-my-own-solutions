#include <stdio.h>
#include <stdlib.h> /*for atof*/

#define MAXOP 100 /*max size of operand or operator*/
#define NUMBER '0' /*signal that a number was found*/

int getop(char s[]);
void push(double);
double pop(void);

double gettop();
void createtopclone();
void swaptwotops();
void clearstack();

double csin(double); /*sin (x)*/
double cexp(double); /* e^x */
double cpow(double,double); /* x^y ->возникает ошибка области определения, 
							если х = 0 и у < 0 или если х < 0 и у - не целое*/ 


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
			case 's':
				push(csin(pop()));
				break;
			case 'e':
				push(cexp(pop()));
				break;
			case 'p':
				op2 = pop();
				push(cpow(pop(), op2));
				break;
			/*case '$':
				printf("top item: %f\n",gettop());
				swaptwotops();
				printf("top item: %f\n",gettop());
				createtopclone();
				break;
			case '@':
				clearstack();
				break;*/
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

double gettop()
{
	if(sp > 0)
		return var[sp-1];
	else 
	{
		printf("There are no elements in stack :(\n");
		return 0.0;
	}
}

void createtopclone() { push(gettop());}

void swaptwotops()
{
	double first = pop();
	double second = pop();
	push(first);
	push(second);
}

void clearstack()
{
	while(sp!=0)
		pop();
}

#include <ctype.h>

int getch(void);
void ungetch(int);
void ungets(char[]);

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

void ungets(char s[])
{
	int i;
	for (i = 0; s[i]; i++);
	i--;
	while (i >= 0)
		ungetch(s[i--]);
}

#include <math.h>
#define EXP 2.718
#define TRUE 1
#define FALSE 0

double csin(double arg) /*sin (x)*/
{
	return sin(arg);
}
double cexp(double x) /* e^x */
{
	if (x == 0)
		return 1;
	else return EXP * cexp(x-1);
}
double cpow(double x,double y) /* x^y ->возникает ошибка области определения, 
							если х = 0 и у < 0 или если х < 0 и у - не целое*/ 
{
	if(x == 0 && y < 0 || x < 0 || y != ceil(y))
	{
		printf("Domain Error! Check your input. \n");
		return 0.0;
	}
	
	if (y == 0)
		return 1;
	else return x * cpow(x, y-1);
}

