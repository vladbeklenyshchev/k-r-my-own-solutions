#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc, char *argv[])
{
	FILE * f1p; char fstfline[MAXLINE];
	FILE * f2p; char sndfline[MAXLINE];
	char * program = argv[0];
	
	if(argc != 3)
	{
		fprintf(stderr, "Program %s compares two files!\n", program);
		exit(1);
	}

	f1p = fopen(argv[1], "r");
	f2p = fopen(argv[2], "r");
	while(fgets(fstfline, MAXLINE, f1p) != NULL &&
		  fgets(sndfline, MAXLINE, f2p) != NULL &&
		  strcmp(fstfline, sndfline) == 0)
		;
	fclose(f1p);
	fclose(f2p);

	if(ferror(stdin))
	{
		fprintf(stderr, "%s: error reading stdin\n", program);
		exit(2);
	}

	if(strcmp(fstfline, sndfline) == 0)
		fputs("Files are similar!\n", stdout);
	else
	{
		fputs("Sorry. The files differ in these lines:\n", stdout);
		fputs(strcat(fstfline, " \n"), stdout);
		fputs(strcat(sndfline, " \n"), stdout);
	}
	
	exit(0);
}