#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int max);

int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern to search for */

int main()
{
	char line[MAXLINE];
	int found = 0;

	while(get_line(line, MAXLINE) > 0)
	{
		if (strindex(line, pattern) >= 0)
		{
			/* pattern was found */
			printf("%s", line);
			found++;
		}
	}

	return found;
}

/*get_line: get line into s, return length*/
int get_line(char s[], int lim)
{
	int c, i;
	for(i = 0; --lim > 0/*i< lim - 1*/ && (c = getchar()) != EOF && c!='\n'; ++i)
		s[i] = c;

	if (c == '\n')
	{
		s[i++] = c;
	}

	s[i] = '\0';

	return i;
}

/*strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; ++i)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}

	return -1;
}