#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char ** argv)
{
	while(--argc > 0) // 
		printf("%s%s", *++argv, (argc > 1) ? " " : ""); // pass name of the program
	
	printf("\n");
	exit(EXIT_SUCCESS);
}