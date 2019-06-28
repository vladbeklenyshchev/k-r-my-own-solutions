#include <stdio.h>
#include <stdlib.h>
#include <>

#include "Getch.h"
#include "Getword.h"

#define MAXWORD 100

int main(int argc, char const *argv[])
{
	char word[MAXWORD];

	int c;
	while(getword(word, MAXWORD) != EOF)
		if(isalpha(word))
			;
	return 0;
}