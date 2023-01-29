#include "main.h"
/**
 * _printf - prints  formatted string to the std output
 * @format: input string
 * Return: Total character count printed to std output or input string otherwise.
 */

int _printf(const char *format, ...)
{
	int print_count;
	va_list arg_itr;

	/* look up table*/
	look_up_table function_array[] = 
	{
		{"c",printout_char},
		{"s",printout_str},
		{"%",format_operator},
		{"i",print_integer},
		{"d",print_integer},
		{"u",unsigned_int},
		{NULL, NULL}		
	};

	if (format == NULL)
	{
		return (-1);
	}
	va_start(arg_itr, format);

	/*function call to parser*/
	print_count = parser_func(format, function_array, arg_itr);

	/*free argument list before function return*/

	va_end(arg_itr);
	return (print_count);
}
