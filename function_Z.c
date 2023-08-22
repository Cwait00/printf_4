#include "main.h"
#include <stdarg.h>
/**
 * print_octal - prints ocatal of integer input to the
 * standard output
 * @list: list of arguments
 * @buffer: container of 1024 characters used to print
 * @flags: '0', '-', '*', ' ', '#'
 * @width: width of the argument
 * @precision: precision specifier
 * @size: length specifier (l or h)
 * Return: octal of integer
 */
int print_octal(va_list list, char buffer[], int flags, int width,
		int precision, int size)
{
	/*fetch argument*/
	int octal_print = va_arg(list, int);

	return (handle_print(buffer, flags, width, precision, size, octal_print));
}
/**
 * print_hexidecimal - prints hexidecimal to standard output
 * @list: list of arguments
 * @buffer: container of 1024 characters used to print
 * @flags: '0', '-', '*', ' ', '#'
 * @width: width of the argument
 * @precision: precision specifier
 * @size: length specifier (l or h)
 * Return: hexidecimal
 */
int print_hexidecimal(va_list list, char buffer[], int flags, int width,
		int precision, int size)
{
	/*fetch argument from variadic functions*/
	int hexidecimal_print = va_arg(list, int);

	return (handle_print(buffer, flags, width, precision, size,
				hexidecimal_print));
}
