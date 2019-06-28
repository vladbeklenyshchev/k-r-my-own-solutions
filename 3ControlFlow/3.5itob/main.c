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

void itob(int n, char s[], int b)
{
	int i, sign;

	sign = n < 0 ? -1 : 1;

	i = 0;

	do
	{
		if(n % b < 10)
			s[i++] = (n % b) * sign + '0';
		else 
			s[i++] = (n % b) * sign + 55; // 'A' - 10 = 55 -> '7'
	}while((n /= b) != 0);

	if(sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	
	reverse(s);
}

int main(int argc, char const *argv[])
{
	char s[1000];
	int n = 1256;
	itob(n, s, 8);
	printf("%s\n", s);
	return 0;
}