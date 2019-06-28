#include <stdio.h>

#define swap(t, x, y) {t tmp; tmp = x; x = y; y = tmp;}

int main(int argc, char const *argv[])
{
	int a[] = {1, 2, 3, 4};
	swap(int, a[0], a[3]);
	for (int i = 0; i < 4; ++i)
		printf("%d\n", a[i]);
	return 0;
}