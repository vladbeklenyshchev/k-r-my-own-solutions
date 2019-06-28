#include <stdio.h>

#define MAX_LEN 1000

int get_line(char[], int);

int main(int argc, char const *argv[])
{
	char s[MAX_LEN];
	int len;
	int l;

	while((len = get_line(s, MAX_LEN)) > 0)
	{

	}
	return 0;
}

int get_line(char s[], int lim)
{
	int c, i;
	for (i = 0; (i < lim - 1) + ((c = getchar()) != EOF) + (c != '\n') == 3; ++i)
		s[i] = c;
	
	if(c == '\n')
	{
		s[i] = c;
		i++;
	}

	s[i] = '\0';

	return i;
}