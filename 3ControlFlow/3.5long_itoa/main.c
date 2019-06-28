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

void itoa(int n, char s[], int min_f)
{
	int i, sign;
	
	sign = (n < 0 ? -1 : 1); 
	
	i = 0;

	do 
	{
		s[i++] = (n % 10)*sign + '0';
	} while ((n /= 10) != 0);

	if(sign < 0)
		s[i++] = '-';

	for (int j = 0, k = i; j < (min_f - k); ++j)
		s[i++] = ' ';

	s[i] = '\0';
	reverse(s);
}


int main(int argc, char const *argv[])
{
	char s[1000];
	int n = 1256;
	itoa(n, s, 8);
	printf("%s\n", s);
	return 0;
}