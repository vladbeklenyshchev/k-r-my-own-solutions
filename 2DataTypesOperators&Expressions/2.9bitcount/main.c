#include <stdio.h>

int bitcount(unsigned x) {
        int i;
        for (i = 0; x; i++, x &= (x-1));
        return i;
}

int main(int argc, char const *argv[])
{
	int x = 10; // 1011010 or 132(8)
	printf("%d\n", bitcount(x));
	return 0;
}