int get_line(char s[], int lim)
{
	int c, i;
	for(i = 0; i< lim - 1 && (c = getchar()) != EOF && c!='\n'; ++i)
		s[i] = c;

	if (c == '\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';

	return i;
}

void reverse(char s[])
{
	for (int i = strlen(s) - 1, j = 0; i >= j; --i, j ++)
	{
		int tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}

void itoa(int n, char s[])
{
	int i, sign;
	int is_over_load = FALSE;
	
	sign = (n < 0 ? -1 : 1); 
	
	i = 0;

	do 
	{
		s[i++] = (n % 10)*sign + '0';
	} while ((n /= 10) != 0);

	if(sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);
}

/*strindex: return index of t in s, -1 if none */
int strrindex(char s[], char t[])
{
	int i, j, k, tmp;

	tmp = -1;
	for (i = 0; s[i] != '\0'; ++i, k = 0)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, k++)
			;
		if (k > 0 && t[k] == '\0')
			tmp = i;
	}

	return tmp;
}