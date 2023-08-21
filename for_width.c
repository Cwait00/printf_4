#include "main.h"
/**
 * for_width - print calculations of the width for printf
 * @format: formatted strings of the printed arguments
 * @x: list of printed arguments
 * @list: list of arguments
 * Return: width
 */
int for_width(const char *format, int *x, va_list list)
{
	int print_width = 0;
	int a;

	if (format[*x] == '%')
	{/*find and move away from %*/
		*x++;
	}

	/*"%9d"  "123456" "   123456"*/
	while (format[*x] >= 48 && format[*x] <= 57)
	{
		/*to determind how many places need to be filled with spaces*/
		if (format[*x] < print_width)
		{
			a = 0;
			while (a < print_width - strlen(format[*x]))
			{
				_putchar(' ');
				a++;
			}
		}
		/*this is where i lost my train of thought*/
