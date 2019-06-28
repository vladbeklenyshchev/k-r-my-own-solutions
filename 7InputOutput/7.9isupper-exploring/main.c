#include <stdio.h>
#include <stdlib.h>

/*adv: saves time -> there is no function call overhead*/
/*disadv: is that the arg is evaluated more than once. Example: (*c++)*/
#define isupper(c) (c >= 'A' && c <= 'Z')

/*function saves space because the code for isupper is not coppied everytime
an isupper() call is found*/
/*int isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}*/

int main(int argc, char const *argv[])
{
	int c;
	c = getchar();
	if(isupper(c))
		printf("The letter %c in upper case.\n", c);
	else
		printf("The letter %c in lower case.\n", c);
	return 0;
}