#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Getch.h"
#include "Getword.h"
#include "Strdup.h"
#include "Hashtab.h"

#define MAXWORD 100

int main(int argc, char const *argv[])
{
	char word[MAXWORD]; // to find #define directive
	char name[MAXWORD];
	char rtext[MAXWORD];
	struct nlist * result;

	while(getword(word, MAXWORD) > 0)
	{	
		/* can't support expressions like this one:
		#define max(A, B) ((A) > (B) ? (A) : (B))*/
		if(strcmp(word, "define") == 0)
		{
			getword(name, MAXWORD);
			getword(rtext, MAXWORD);
			printf("%s\n", rtext);
			install(name, rtext);
		}
	}

	if(strcmp(argv[1], "-lup") == 0 && argv[2] != NULL)
		if((result = lookup(argv[2])) != NULL)
			printf("Definition: %s\n", result->defn);
		else
			printf("FeelsBadMan :(\n");
	
	if(strcmp(argv[1], "-udf") == 0 && argv[2] != NULL)
		if((result = undef(argv[2])) != NULL)
			printf("Removed word %s.\n", lookup(result->name));

	if((result = lookup("MAXWORD")) == NULL)
		printf("This word doesn't exist.\n");
	else
		printf("This word exists.\n");

	install("MAXWORD", "500");

	if((result = lookup("MAXWORD")) == NULL)

		printf("This word doesn't exist.\n");
	else
	{
		printf("This word exists. Its definition: %s\n", result->defn);	
	}

	undef("X");

	if((result = lookup("MAXWORD")) == NULL)

		printf("This word doesn't exist.\n");
	else
	{
		printf("This word exists. Its definition: %s\n", result->defn);	
	}
	return 0;
}