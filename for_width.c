#include "main.h"

/**
 * for_width - print calculations of the width for printf
 * @format: formatted strings of the printed arguments
 * @x: list of printed arguments
 * @list: list of arguments
 * Return: width
 */
int for_width(const char *format, int *b, va_list list)
{
	int print_width = 0;
	int a;

	if (format[*b] == '%')
	{/*find and move away from %*/
		(*b)++;
	}

	/*"%9d"  "123456" "   123456"*/
	while (format[*b] >= '0' && format[*b] <= '9')
	{/*making sure the characters are changed to integer by -'0'*/
		print_width *= 10 + (format[*b] - '0');
		(*b)++;
	}
	if (print_width > 0)
	{/* to determine how many places need spaces*/
		a = 0;
		/*sizeof is used cause format[*x] is a single character*/
		while (a < print_width - (int)sizeof(char))
		{
			_putchar (' ');
			a++;
		}
	}
	else if (format[*b] == '*')
	{/*check for * to then fetch the width from the argument instead */
		print_width = va_arg(list, int);

	}
	return (print_width);
}
