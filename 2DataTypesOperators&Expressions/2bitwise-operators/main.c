#include <stdio.h>

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

int main(int argc, char const *argv[])
{
	/*int n = 22; // 10110
	n = n & 1;
	printf("%d\n", n );*/
	int n = 90;
	printf("%d\n", getbits(n, 4, 3));
	return 0;
}