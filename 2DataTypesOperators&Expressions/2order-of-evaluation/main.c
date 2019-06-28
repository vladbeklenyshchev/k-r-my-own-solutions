#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a = 5;
	a = ++a+a; // 12, increments a before its value is used
	//a = a+++a // 11, increments a after its value is used
	printf("%d\n", a);
	return 0;
}