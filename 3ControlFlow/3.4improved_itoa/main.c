#include <stdio.h>

#define TRUE 1
#define FALSE 0

int strlen(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; ++i);
	return i;
}

void reverse(char s[])
{
	for (int i = strlen(s) - 1, j = 0; i >= j; --i, j ++)
	{
		int tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}

void itoa(int n, char s[])
{
	int i, sign;
	int is_over_load = FALSE;
	
	sign = (n < 0 ? -1 : 1); 
	
	i = 0;

	do 
	{
		s[i++] = (n % 10)*sign + '0';
	} while ((n /= 10) != 0);

	if(sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);
}

int main(int argc, char const *argv[])
{
	char s[1000];
	int n = -2147483648;
	itoa(n, s);
	printf("%s\n", s);
	return 0;
}