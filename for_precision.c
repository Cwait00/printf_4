#include "main.h"
/**
 * for_precision - finds and returns the precision value to show
 * you the right amounts of parts you want to see.
 * @x: parameter for precision
 * @format: for strings and floats
 * Return: precision value in numeric form
 */
int for_precision(const char *format, int *x)
{
	int curr_x = *x + 1;
	int precision = -1;

	if (format[curr_x] != '.')

	return (precision);

	precision = 0;

	for (curr_x += 1; format[curr_x] != '\0'; curr_x++)
	{
	if (is_digit(format[curr_x]))
	{
	precision *= 10;

	precision += format[curr_x] - '0';
	}

	else if (format[curr_x] == '*')
	{
		curr_x++;
		precision = va_arg(list, int);
	break;
	}

	else
	break;

	}
	*x = curr_x - 1;

	return (precision);

}
