#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

#define BUFF_SIZE 1024

/**
 * _printf - function of a printf
 * @format: format
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	int x, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);

	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[buff_ind++] = format[x];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[x], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &x);
			width = for_width(format, &x, list);
			precision = for_precision(format, &x, list);
			size = for_size(format, &x);
			++x;
			printed = handle_print(format, &x, list, buffer,
					flags, width, precision, size);

			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}
/**
 * print_buffer - prints the contents of the buffer
 * @buffer: Array of characters
 * @buff_ind: index that adds the next character, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
