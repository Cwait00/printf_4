#include "main.h"
#include <stdarg.h>
/**
 * print_char - prints characters to the standard output
 * @list: list of arguments
 * @buffer: container of 1024 characters used to print
 * @flags: '0', '-', '*', ' ', '#'
 * @width: width
 * @precision: precision specifier
 * @size: length specifier (l or h)
 * Return: character
 */
int print_char(va_list list, char buffer[], int flags, int width,
		int precision, int size)
{
	/*fetching the agrument*/
	char char_print = va_arg(list, int);

	/*print argument*/
	return (handle_print(buffer, flags, precision, size, width, char_print));
}

/**
 * print_percent - prints percent to the standard output
 * @list: list of arguments
 * @buffer: container of 1024 characters used to print
 * @flags: '0', '-', '*', ' ', '#'
 * @width: width of the argument
 * @precision: precision specifier
 * @size: length specifier (l or h)
 * Return: percent '%'
 */
int print_percent(va_list list, char buffer[], int flags, int width,
		int precision, int size)
{
	/*fetching argument*/
	int percent_print = va_arg(list, int);

	/*print argument*/
	return (handle_print(buffer, flags, precision, size, width, percent_print));
}

/**
 * print_string - prints string to the standard output
 * @list: list of arguments
 * @buffer: container of 1024 characters used to print
 * @flags: '0', '-', '*', ' ', '#'
 * @width: width of the argument
 * @precision: precision specifier
 * @size: length specifier (l or h)
 * Return: string
 */
int print_string(va_list list, char buffer[], int flags, int width,
		int precision, int size)
{
	/*fetching argument*/
	char *string_print = va_arg(list, char*);

	int a = 0; /*counts the characters to print*/
	int b = 0; /*used for index*/

	while (string_print[b] != '\0')
	{
		return (string_print[b]);
		b++;
		a++;
	}
	return (handle_print(buffer, flags, precision, size, width, string_print));
}
