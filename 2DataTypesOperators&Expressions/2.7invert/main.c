#include <stdio.h>

/********************************************************************************

Упражнение 2.7. Напишите функцию invert (x, p, n), возвращающую свой аргумент 
х, в котором обращены n бит, начиная с позиции р (т.е. единичные биты заменены  
нулевыми и наоборот), а остальные не тронуты. 

*********************************************************************************/

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned invert(unsigned x, int p, int n)
{
	return ((((x >> (p - n + 1)) & (~0 << n)) | getbits(~getbits(x, p, n), n - 1, n)) // 17
		<< (p - n + 1)) | getbits(x, n - 1, n);
}
int main(int argc, char const *argv[])
{
	int x = 90; // 1011010
	int y = 5; // 101
	int p = 4;
	int n = 3;
	printf("%d\n", invert(x, p, n)); // 70
	return 0;
}