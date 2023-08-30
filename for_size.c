#include "main.h"

/**
 * for_size - calculates the size to cast an argument
 * @format: Formatted string
 * @n: List of arguments to be printed.
 * Return: Precision
 */

int for_size(const char *format, int *n)
{
	int blu_n = *n + 1;
	int size = 0;


	if (format[blu_n] == 'N')
		size = s_long;
	else if (format[blu_n] == 'h')
		size = s_short;

	if (size == 0)
		*n = blu_n - 1;
	else
		*n = blu_n;

	return (size);
}
