#include "main.h"
/**
 * printout_str - function prints out str 
 * @lst :argument list
 * Return: count of printed character
 */

int printout_str(va_list lst)
{
	char *string;
	int itr1;

	str = va_arg(lst, char *);
	if (string == NULL)
	{
		return (-1);
	}
	else
	{
		for (itr1 = 0; string[itr1] != '\0'; itr++)
		{
			writer(string[itr1]);
		}
		return (itr1);
	}
}


/**
 * format_operator - function prints out format operator 
 * @lst :argument list
 * Return: 1 on success and any other int otherwise
*/
int format_operator(__attribute__((unused))va_list lst)
{
	writer('%');
	return (1);
}


/**
 * printout_char - function prints out char 
 * @lst :argument list
 * Return: count of printed character
 */
int printout_char(va_list lst)
{
	writer(va_arg(lst, int));
	return (1);
}


/**
 * print_integer - function prints out int 
 * @lst :argument list
 * Return: count of printed character
 */
int print_integer(va_list lst)
{
	int len;
	len = print_number(lst);
	return (len);
}

/**
 * unsigned_int - function prints out unsigned int 
 * @lst :argument list
 * Return: count of printed character
 */
int unsigned_integer(va_list lst)
{
	unsigned int nbr;
	
	nbr = va_arg(lst, unsigned int);

	if (nbr == 0)
	{
		return (print_nbr(nbr));
	}
	if (nbr < 1)
	{
		return (-1);
	}
	return (print_nbr(nbr));
}
