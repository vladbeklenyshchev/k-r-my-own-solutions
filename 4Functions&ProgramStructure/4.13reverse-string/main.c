#include <stdio.h>

void swap(char v[], char i, char j) 
{ 
	char temp; 
	temp = v[i]; 
	v[i] = v[j] ; 
	v[j] = temp; 
}

int count(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; ++i)
		;
	return i;
}

void reverse(char s[], int from, int to)
{
	if (from >= to)
		return;

	swap(s, from, to);
	reverse(s, from+1, to-1);
}

int main(int argc, char const *argv[])
{
	char s[] = "NOICE";
	reverse(s, 0, count(s) - 1);
	printf("%s\n", s);
	return 0;
}