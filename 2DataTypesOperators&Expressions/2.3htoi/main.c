#include <stdio.h>

int htoi(char s[])
{
	int n = 0;
	// not including '0x'
	for (int i = 2; s[i] >= '0' && s[i] <= '9' 
		|| s[i] >= 'A' && s[i] <= 'F'
		|| s[i] >= 'a' && s[i] <= 'f'; ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			n = 16 * n + (s[i] - '0');
		}
		else if (s[i] >= 'A' && s[i] <= 'F')
		{
			// plus 7 elements between range of [0-9] and range of [A-F] 
		    n = 16 * n + (s[i] - ('0' + ('A' - '9' - 1)));
			// n = 16 * n + 10 + (s[i] - 'A');
		}
		else if (s[i] >= 'a' && s[i] <= 'f')
		{
			// plus 7 elements between range of [0-9] and range of [a-f] 
			 n = 16 * n + (s[i] - ('0' + ('a' - '9' - 1)));
			// n = 16 * n + 10 + (s[i] - 'a');
		}
	}
	return n;
}

int main(int argc, char const *argv[])
{
	char s_hex[] = "0x1f";
	printf("%d\n", htoi(s_hex));
	return 0;
}