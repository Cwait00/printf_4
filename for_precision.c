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
	int num_precision = 0;

	if (format[x] == 48)
	{/* '.' is found and ignored*/
		x++;
	}

	while (format[x] => 48 && format[x] <= 57)
	{/*multipled by 10 to shift one place to the left*/
		precision = precision * 10 + (format[x] - 48);
		/* - 48 to give the numeric value of characters*/
		x++;
	}
	return (num_precision);
}
