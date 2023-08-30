#include "main.h"

/**
 * for_width - print calculations of the width for printf
 * @format: formatted strings of the printed arguments
 * @b: list of printed arguments
 * @list: list of arguments
 * Return: width
 */

int for_width(const char *format, int *b, va_list list)
{
	int print_width;
	int a = 0;

	for (print_width = *b + 1; format[print_width] != '\0'; print_width++)
	{
		if (is_digit(format[print_width]))
		{
		a *= 10;
		a += format[print_width] - '0';
		}
		else if (format[print_width] == '*')
		{
		print_width++;
		a = va_arg(list, int);
		break;
		}
		else
		break;

	}
	*b = print_width - 1;
	return (width);
}
