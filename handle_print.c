#include "main.h"
/**
 * handle_print - Prints a type of argument
 * @format: Formatted strings
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @flags: Calculates active flags
 * @precision: Precision
 * @buffer: Buffer array
 * @width: Get width.
 * @size: Size
 * Return: 1 or 2
 */
int handle_print(const char *format, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int a = 0, unknown_len = 0, printed_chars = 0;
	format_t format_types[] = {
		('c', print_char), ('s', print_string), ('%', print_percent),
		('i', print_int), ('d', print_int), ('b', print_binary),
		('u', print_unsigned_int), ('o', print_octal), ('x', print_hexadecimal),
		('X', print_hexa_upper), ('p', print_pointer), ('S', print_non_printable),
		('r', print_reverse), ('R', print_rot13string), ('\0', NULL)
	};
	for (a = 0; format_types[a].format != '\0'; a++)
	{
		if (format[*ind] == format_types[a].format)
		{
			return (format_types[a].fn(list, buffer, flags, width, precision, size));
		}
	}
	if (format[*ind] == '\0')
	{/*if we are here, something is wrong*/
		return (-1);
	}

	unknown_len += write(1, "%%", 1);

	if (format[*ind - 1] == ' ')
	{
		unknown_len += write(1, " ", 1);
	}
	else if (width)
	{
		--(*ind);
		while (format[*ind] != ' ' && format[*ind] != '%')
		{
			--(*ind);
		}
		if (format[*ind] == ' ')
			--(*ind);
		return (1);
	}
	unknown_len += write(1, &format[*ind], 1);
	return (unknown_len);
}
return (printed_chars);
}