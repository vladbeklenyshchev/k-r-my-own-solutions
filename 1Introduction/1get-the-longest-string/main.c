#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
void copy(char to[], char from[]);

int main(int argc, char const *argv[])
{
	int len; // длина текущей строки
	int max; // текущая максимальная длина
	char line[MAXLINE]; //текущая введенная строка

	max = 0;
	while((len = get_line(line, MAXLINE)) > 0)
		if (len > max)
		 {
		 	max = len;
		 	copy(longest, line);
		 } 
	if(max > 0) /*была непустая строка*/
		 printf("longest: %s max_len: %d", longest, max);
		 printf("longest: %s max_len via strlen: %d", longest, strlen(longest));
	return 0;
}

int get_line(char s[], int lim)
{
	int c, i;
	for(i = 0; i< lim - 1 && (c = getchar()) != EOF && c!='\n'; ++i)
		s[i] = c;

	if (c == '\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';

	return i;
}

void copy(char to[], char from[])
{
	int i = 0;

	while ((to[i] = from[i]) != '\0')
		i++;
}