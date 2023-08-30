#include "main.h"
#include <stdarg.h>
/**
 * print_pointer- prints pointer
 * @list: list of arguments
 * @buffer: container of 1024 characters used to print
 * @flags: '0', '-', '*', ' ', '#'
 * @width: width of the argument
 * @precision: precision specifier
 * @size: length specifier (l or h)
 * Return: integer
 */
int print_pointer(va_list list, char buffer[], int flags,
		int width, int precision, int size)
{
	char extr_c = 0, padding = ' ';
	/* length=2, for '0x' */
	int idx = BUFF_SIZE - 2, length = 2, padding_start = 1;
	unsigned long nr_addr;
	char map_to_nr[] = "0123456789abcdef";
	void *addr = va_arg(list, void *);

	UNUSED(width);
	UNUSED(size);

	if (addr == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';

	UNUSED(precision);

	nr_addr = (unsigned long)addr;
	while (nr_addr > 0)
	{
		buffer[idx--] = map_to_nr[nr_addr % 16];
		nr_addr = nr_addr / 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (flags & F_PLUS)
		extr_c = '+', len++;
	else if (flags & F_SPACE)
		extr_c = ' ', len++;
	idx++;
	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, idx, len,
				width, flags, padding, extr_c, padding_start));

}
/**
 * print_non_printable - prints ascii codes in hexa
 * of non printable characters
 * @list: list of arguments
 * @buffer: container of 1024 characters used to print
 * @flags: '0', '-', '*', ' ', '#'
 * @width: width of the argument
 * @precision: precision specifier
 * @size: length specifier (l or h)
 * Return: binary
 */
int print_non_printable(va_list list, char buffer[], int flags, int width,
		int precision, int size)
{
	int x = 0, offst = 0;/*offset*/
	char *str = va_arg(list, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (printable_yes(str[i]))
			buffer[x + offst] = str[i];
		else
			offst = offst + append_hexa_code(str[x], buffer, x + offst);
		x++;
	}
	buffer[x + offst] = '\0';
	return (write(1, buffer, i + offst));
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
	int a = BUFF_SIZE - 2;
	unsigned long int nr = va_arg(types, unsigned long int);

	nr = convert_size_un_sgned(nr, size);
	if (nr == 0)
		buffer[a--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (nr > 0)
	{
		buffer[a--] = (nr % 10) + '0';
		nr = nr / 10;
	}
	a++;
	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
/**
 * print_reverse - prints string in reverse
 * @list: list of arguments
 * @buffer: container of 1024 characters used to print
 * @flags: '0', '-', '*', ' ', '#'
 * @width: width of the argument
 * @precision: precision specifier
 * @size: length specifier (l or h)
 * Return: unsigned int
 */
int print_reverse(va_list list, char buffer[], int flags,
		int width, int precision, int size)
{
	char *str;
	int x;
	int counter = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(list, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = "(Null)";
	}
	for (x = 0; str[x]; x++)
		;
	for (x = x - 1; x >= 0; x--)
	{
		char v = str[x];

		write(1, &v, 1);
		counter++;
	}
	return (counter);
}
