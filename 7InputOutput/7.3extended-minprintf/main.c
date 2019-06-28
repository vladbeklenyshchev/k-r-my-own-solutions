#include <stdarg.h>

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
	va_list ap; /*points to each unnamed arg in turn*/
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt); /*make ap point to 1st unnamed arg */
	for(p = fmt; *p; p++)
	{
		if (*p != '%')
		{
			putchar(*p);
			continue;
		}
		switch (*++p)
		{
			case 'd':
			case 'i':
				ival = va_arg(ap, int);
				printf("%d", ival);
				break;
			case 'e':
			case 'f':
			case 'g':
				dval = va_arg(ap, double);
				printf("%f\n", dval);
				break;
			case 's':
				for(sval = va_arg(ap, char *); *sval; sval++)
					putchar(*sval);
				break;
			default:
				putchar(*sval);
				break;
		}
		va_end(ap); /*clean up when done*/
	}
}