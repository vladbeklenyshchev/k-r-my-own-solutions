#include <stdio.h>

/*void squeeze(char s[], char c)
{
	// i - counter of the array s
	// j - counter of the squeezed array
	int i, j;

	for (i = j = 0; s[i] != '\0'; ++i)
		if(s[i] != c)
			s[j++] = s[i];

	s[j] = '\0';
}*/

enum bool{FALSE, TRUE};

void squeeze(char s1[], char s2[])
{
	// i - counter of the array s
	// j - counter of the squeezed array
	int i, j, k;
	int is_coincided = FALSE;

	for (i = j = k = 0; s1[i] != '\0'; ++i)
	{
		for (j = 0; s2[j] != '\0'; ++j)
			if (s1[i] == s2[j])
			{
				is_coincided = !is_coincided;
				break;
			}

		if(!is_coincided)
			s1[k++] = s1[i];
		else is_coincided = !is_coincided;
	}

	s1[k] = '\0';
}

int main(int argc, char const *argv[])
{
	char c = 'e';
	char s1[] = "Little Green Bag";
	char s2[] = "tea";

	//squeeze(s1, c);
	squeeze(s1, s2);

	printf("%s\n", s1);
	return 0;
}