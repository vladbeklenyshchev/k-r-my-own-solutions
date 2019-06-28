#include "detab.h"
#include "stdio.h"

int count_tabs(char s[], int len)
{
	int count = 0;

	for(int i = 0; i < len && s[i]!='\n'; i++)
		if(s[i]=='\t')
			count++;

	return count;
}

void copy_with_space_insertion(char * to, char * from)
{
	int to_counter = 0, from_counter = 0, tab_counter = 0;
	int spaces = 0;

	for(;;++from_counter)
	{
		if(tab_counter == SPACES_PER_TAB) tab_counter = 0;
		if (from[from_counter] == '\t')
		{
			spaces = SPACES_PER_TAB - tab_counter;
			//spaces = SPACES_PER_TAB - tab_counter%SPACES_PER_TAB;
			for (int j = 0; j < spaces; ++j)
			{
				//printf("j: %d and to_counter: %d\n", j, to_counter);
				to[to_counter++] = ' ';
			}
			tab_counter = spaces = 0;
		}
		else if(from[from_counter] != '\n')
		{
			to[to_counter++] = from[from_counter];
			++tab_counter;
		}
		else 
		{
			to[to_counter] = '\0';
			return;
		}
	}
}

char * detab(char s[], int len)
{
	char * detabed_array = (char*) malloc(len + count_tabs(s, len) * SPACES_PER_TAB);
	copy_with_space_insertion(detabed_array, s);
	return detabed_array;
}