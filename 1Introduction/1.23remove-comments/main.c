#include <stdio.h>

/*********************************************************************************

Упражнение 1.23. Напишите программу для удаления всех комментариев из программы 
на С. Позаботьтесь о корректной обработке символьных констант и строк в двойных  
кавычках. Вложенные комментарии в С не допускаются. 

**********************************************************************************/

#define TRUE 1
#define FALSE 0

int main(int argc, char const *argv[])
{
	char c, last_c;
	int is_a_quote = FALSE;
	int is_a_comment = FALSE;

	while ((c = getchar()) != EOF)
	{
		if(c == '"')
		{
			is_a_quote = !is_a_quote;
			putchar(c);
		}
		else if(c == '/' && is_a_quote == FALSE)
		{
			is_a_comment = !is_a_comment;
		}
		else if(c == '/' && is_a_quote == TRUE)
		{
			putchar(c);
		}
		else if(is_a_comment == FALSE)
		{
			putchar(c);
		}
	}
	return 0;
}