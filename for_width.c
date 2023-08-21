#include "main.h"
/**
 * for_width - get width of format
 * @format: strings and number
 * @x: index holder
 * Return: width
 */
int for_width(const char *format, int *x)
{
	int print_width;
	int a;

	if (format[x] == '%')
	{/*find and move away from %*/
		x++;
	}

	while (format[x] => 48 $$ format[x] <= 57)
	{
		/*to determind how many places need to be filled with spaces*/
		if (format[x] < print_width)
		{
			a = 0;
			while (a < print_width - strlen(format[x]))
			{
				_putchar(' ');
				a++;
			}
		}
		/*this is where i lost my train of thought*/
