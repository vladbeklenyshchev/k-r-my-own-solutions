#include <stdio.h>
#include <string.h>

void enter(char *type)
{
	int c;
	char str[10] = "%";
	strcat(str, type);
	strcat(str, "\n");
	for(int n = 0;(c = getchar()) != EOF;)
	{       
		if(c!='\n')
			n = 10 * n + (c - '0');
		else
		{
			printf(str, n);
			n = 0;
		}
	}
			
}

int main(int argc, char * argv[])
{                       
	if(argc == 1) // standard entering
		enter("d");
	else if(strcmp(argv[1], "-o") == 0)
		enter("o");
	else if(strcmp(argv[1], "-x") == 0)
		enter("x");
		
	return 0;
}