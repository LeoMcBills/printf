#include "main.h"
/**
 * function - function that to parse format string and returns count of output
 * @format: pointer to input string
 * @func_spcfr_array[]: look up table for specifier type and
 * corresponding function
 * @arg_itr: argument list
 * Return: count of characters printed to std output
 */
int parser(const char *format, look_up_table func_spcfr_array[], arg_itr) 
{
	int str_itr, struct_itr, result, value;
	
	value = 0;
	result = 0;
	if (format == NULL)
	{
		return (-1);
	}
	
	/*iterate incoming string in search for formator - %*/
	str_itr = 0;
	for (; format[str_itr] != '\0'; str_itr++)
	{
		if (format[str_itr] == "%")
		{
			struct_itr = 0;
			for(; (func_spcfr_array[struct_itr].specifier_type) != NULL; struct_itr++)
			{
				if ((format[str_itr + 1]) == (func_spcfr_array[struct_itr].specifier_type[0])) 
				{
					value = func_spcfr_array[struct_itr].function_ptr(arg_itr);
				if (value == -1)
				{
					return (-1);
				}
				result += value;
				break;
				}
			}
			if (func_spcfr_array[struct_itr].specifier_type == NULL && format[str_itr + 1] != ' ')
			{
				if (format[str_itr + 1] != '\0')
				{
					writer(format[str_itr]);
					writer(format[str_itr + 1]);
					result = result + 2;
				}
				else
				{
					return (-1);
				}
				str_itr = str_itr + 1;
			}
		}
		else
		{
			writer(format[str_itr]);
			result++;
		}
	}
	return (result);
}
