#include <stdio.h>

// let's assume that s has enough free space
void escape(char s[], char t[])
{
	int j;
	for (int i = j = 0; t[i] != '\0'; ++i)
	{
		switch(t[i])
		{
			case '\t': 
				s[j++] = '\\';
				s[j++] = 't';
				break;
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			default:
				s[j++] = t[i];
				break;
		}
	}

	s[j] = '\0';
}

void rescape(char s[], char t[])
{
	int j;
	for (int i = j = 0; t[i] != '\0'; ++i)
	{
		switch(t[i])
		{
			case '\\':
				if(t[i+1] != '\0')
				{
					switch(t[++i])
					{
						case 't':
							s[j++] = '\t';
							break;
						case 'n':
							s[j++] = '\n';
							break;
					}
				}
				else s[j++] = t[i];
				break;
			default:
				s[j++] = t[i];
				break;
		}
	}

	s[j] = '\0';
}

int main(int argc, char const *argv[])
{
	char s[1000];
	char t[] = "	this is a normal string	!";
	escape(s, t);
	printf("%s\n", s);
	
	char new_s[1000];
	rescape(new_s, s);
	printf("%s\n", new_s);
	return 0;
}