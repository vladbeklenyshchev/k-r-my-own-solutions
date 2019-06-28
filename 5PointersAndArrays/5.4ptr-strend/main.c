#include <stdio.h>

int str_end(char *s, char *t)
{
	while(*s++);
	while(*t++); /*after that t points to symbol after '\0'*/ 
	--s; --t; /*after that  t points to symbol '\0'*/
	while(*--s == *--t && *s && *t); /*begin with last symbols not including '\0'*/
	
	if(!*t && *++s == *++t)
		/*after that ptrs should point to the corresponding first characters*/
		return 1;
	return 0;
}

int main(int argc, char const *argv[])
{
	char * s = "tringT";
	char * t = "stringT";
	printf("%d\n", str_end(s, t));
	printf("%d\n", str_end("Hello, world!", "world!"));
	printf("%d\n", str_end("Hello", "HHHHHello"));
	printf("%d\n", str_end("", "Hello"));
	printf("%d\n", str_end("Hello", ""));
	printf("%d\n", str_end("Hello", "Hello"));
	/* Should print:
		0
		1
		0
		0
		1
		1
	*/
	return 0;
}