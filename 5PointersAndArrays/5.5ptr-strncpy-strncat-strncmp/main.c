#include <stdio.h>

void mystrncpy(char *s, char *t, int n)
{
	int i;
	for(i = 0;i!=n && (*s++ = *t++); i++)
		;
	*s = '\0';
}

/*return <0 if s<t, 0 if s==t, >0 if s>t*/
int mystrncmp(char *s, char *t, int n)
{
	int i;
	for (i = 0; i!=n && *s == *t; ++i, s++, t++)
		if(*s == '\0')
			return 0;
	return *s - *t;
}

char * mystrncat(char * s, char * t, int n) /*copies the string t to the of s*/
{
	char * first = s;
	while(*s++)
		;
	--s;
	for(int i = 0; i!=n && (*s++ = *t++); i++)
		;
	/*now s points to the first item:*/
	s = first;
	return s;
}

int main(int argc, char const *argv[])
{
	char s_for_copying[100];
	char * t_for_copying = "this_is_string_t";
	mystrncpy(s_for_copying, t_for_copying, 5);
	printf("strncpy: %s\n",s_for_copying); /*this_*/
	
	char * scmp = "this_is_string_s";
	char * tcmp = "tHis_is_string_t";
	printf("strncmp: %d\n", mystrncmp(scmp, tcmp, 5)); /*32*/
	
	char scat[100] = "this_is_string_s+";
	char * tcat = "this_is_string_t";
	printf("strncat: %s\n", mystrncat(scat, tcat, 5)); /*this_is_string_s+this_*/
	return 0;
}