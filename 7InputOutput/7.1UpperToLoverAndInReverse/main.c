#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_upper_case_name(char name[])
{
	printf("sname: %s\n", name);
	for (int i = 0; name[i] != '\0'; ++i)
		if(islower(name[i]))
			return 0;
	return 1;
}

int main(int argc, char *argv[])
{
	int c;

	char * name = strtok(strrchr(argv[0], '\\'), "\\.");
	if(is_upper_case_name(name))
		while((c = getchar()) != EOF)
			putchar(toupper(c));
	else
		while((c = getchar()) != EOF)
			putchar(tolower(c));
	return 0;
}