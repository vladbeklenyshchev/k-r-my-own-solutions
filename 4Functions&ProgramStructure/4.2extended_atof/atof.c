#include <ctype.h>
#include <stdio.h>
/*atof: convert string s to double*/
double atof(char s[])
{
	double val, power, res;
	int i, sign;

	for (i = 0; isspace(s[i]); ++i) // skip white space
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for(val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if(s[i] == '.')
		i++;
	for(power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	
	/* extended version */
	double exp_value, exp_power;
	int exp_sign;

	if(s[i] == 'e' || s[i] == 'E')
		i++;
	
	exp_sign = (s[i] == '-') ? -1 : 1;
	
	i++;
	for(exp_value = 0.0; isdigit(s[i]); i++)
		exp_value = 10.0 * exp_value + (s[i] - '0');

	exp_power = 1.0;
	for(double k = 1.0; k <= exp_value; k++)
		exp_power *= 10.0;
	
	if (exp_sign > 0)
		res = (sign * val / power) * exp_power;
	else
		res = (sign * val / power) / exp_power;

	return res;
}