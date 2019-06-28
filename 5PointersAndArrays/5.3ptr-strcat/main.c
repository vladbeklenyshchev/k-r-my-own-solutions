#include <stdio.h>

char * str_cat(char * s, char * t) /*copies the string t to the of s*/
{
	char * first = s;
	while(*s++)
		;
	--s;
	while(*s++ = *t++)
		;
	/*now s points to the first item:*/
	s = first;
	return s;
}

int main(int argc, char const *argv[])
{
	char s[100] = "first";
	char * t = " second";
	printf("%s\n", str_cat(s, t));
	return 0;
}