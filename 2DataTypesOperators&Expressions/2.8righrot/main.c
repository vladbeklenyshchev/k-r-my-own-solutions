#include <stdio.h>

/********************************************************************************

Упражнение 2.8. Напишите функцию right rot (x,n), которая бы возвращала  
значение своего целого аргумента х после его вращения вправо на n двоичных разрядов. 

*********************************************************************************/

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

int getbitcount(unsigned x)
{
	unsigned t = x;
	int i;
	for (i = 1; t != 1;t/=2, i++);
	return i;
}

unsigned rightrot(unsigned x, int n)
{
	return (x >> n) | (getbits(x, n - 1, n) << (getbitcount(x) - n));
}

int main(int argc, char const *argv[])
{
	int x = 90; // 1011010
	int n = 3;
	printf("%d\n", rightrot(x, n));
	return 0;
}