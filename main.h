#ifndef HEADER_FILE
#define HEADER_FILE

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct look_up_table - stuct
 * @specifier_type: operator
 * @func_ptr: function
 */

struct look_up_table 
{
	/*pointer to a function that takes variable list of arguments */
	unsigned int (*func_ptr)(va_list);

	/*key for functions in the look_up_table*/
	char* specifier_type;
}

typedef struct look_up_table look_up_table;
/* function prototype*/
int _printf(const char *format, ...);
int writer(char characier);
int format_operator(__attribute__((unused))va_list lst);
int parser(const char *format, look_up_table func_spcfr_array[], arg_itr);
int printout_char(va_list);
int printout_str(va_list);
int print_integer(va_list);
int unsigned_integer(va_list);

/*helper functions*/
int print_nbr(unsigned int);
int print_number(va_list);

#endif
