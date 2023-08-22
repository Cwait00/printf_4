#include "main.h"
#include <stdarg.h>
/**
 * print_int - prints integer as 'd' or/and 'i'
 * @list: list of arguments
 * @buffer: container of 1024 characters used to print
 * @flags: '0', '-', '*', ' ', '#'
 * @width: width of the argument
 * @precision: precision specifier
 * @size: length specifier (l or h)
 * Return: integer
 * */
int print_int(va_list list, char buffer[], int flags, int width, int precision, int size)
{
	/*fetch argument*/
	int int_print = va_arg(list, int);

	return (handle_print(buffer, flags, width, precision, size, int_print));
}
/**
 * print_binary - prints binary
 * @list: list of arguments
 * @buffer: container of 1024 characters used to print
 * @flags: '0', '-', '*', ' ', '#'
 * @width: width of the argument
 * @precision: precision specifier
 * @size: length specifier (l or h)
 * Return: binary
 */
int print_binary(va_list list, char buffer[], int flags, int width,
		int precision, int size)
{
	/*fetch argument for binary*/
	int binary_print = va_arg(list, int);

	return (handle_print(buffer, flags, width, precision, size, binary_print));
}
/**
 * print_unsigned_int - prints unsigned int
 * @list: list of arguments
 * @buffer: container of 1024 characters used to print
 * @flags: '0', '-', '*', ' ', '#'
 * @width: width of the argument
 * @precision: precision specifier
 * @size: length specifier (l or h)
 * Return: unsigned int
 */
int print_unsigned_int(va_list list, char buffer[], int flags, int width,
		int precision, int size)
{
	/*fetch argument for unsigned int*/
	int unsigned_int_print = va_arg(list, int);

	return (handle_print(buffer, flags, width, precision, size, unsigned_int_print));
}
