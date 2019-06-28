#include <stdio.h>
#include <ctype.h>
#include "atof.h"

#define MAXLINE 100

/*rudimentary calculator*/
int main(int argc, char const *argv[])
{
	/*double sum, atof(char[]);
*/
	double sum;
	char line[MAXLINE];
	int get_line(char line[], int max);

	sum = 0;
	while(get_line(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line));
	return 0;
}