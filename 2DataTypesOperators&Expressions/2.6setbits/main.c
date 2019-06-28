#include <stdio.h>

/********************************************************************************

Упражнение 2.6. Напишите функцию setbits (x,p,n,y) так, чтобы она возвращала 
аргумент х, в котором n битов, начиная с позиции р, равны n крайним правым битам  
аргумента у, а остальные биты не тронуты. 

*********************************************************************************/

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

int getbitcount(unsigned x)
{
	unsigned t = x;
	int i = 1;
	while (t != 1)
	{
		t/=2;
		i++;
	}
	return i;
}

unsigned rightrot(unsigned x, int n)
{
	return (x >> n) | (getbits(x, n - 1, n) << (getbitcount(x, n) - n));
}

int main(int argc, char const *argv[])
{
	int x = 90; // 1011010
	int y = 5; // 101
	//printf("%d\n", rightrot(x, 3));
	return 0;
}