#include "main.h"
#include <stdarg.h>
/**
 * print_octal - prints ocatal of integer input to the
 * standard output unsigned
 * @list: list of arguments
 * @buffer: container of 1024 characters used to print
 * @flags: '0', '-', '*', ' ', '#'
 * @width: width of the argument
 * @precision: precision specifier
 * @size: specifies size/length specifier (l or h)
 * Return: octal of integer
 */
int print_octal(va_list list, char buffer[], int flags, int width,
		int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int nr = va_arg(types, unsigned long int);
	unsigned long int initi_nr = nr;

	UNUSED(width);
	nr = change_size_un_sgned(nr, size);

	if (nr == 0)
		buffer[a--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (nr > 0)
	{
		buffer[a--] = (nr % 8) + '0';
		nr = nr / 8;
	}
	if (flags & F_HASH && initi_nr != 0)
		buffer[a--] = '0';
	a++;
	return (write_un_sgned(0, a, buffer, flags, width, precision, size));
}
/**
 * print_hexidecimal - prints hexidecimal to
 * standard output in unsigned nr
 * @list: list of arguments
 * @buffer: container of 1024 characters used to print
 * @flags: '0', '-', '*', ' ', '#'
 * @width: width of the argument
 * @precision: precision specifier
 * @size: specifies size/length specifier (l or h)
 * Return: hexidecimal
 */
int print_hexidecimal(va_list list, char buffer[], int flags, int width,
		int precision, int size)
{
	return (hexa_print(list, "0123456789abcdef", buffer, flags,
			       'x', precision, width, size));
}

/**
 * print_upper_hexa - prints upper hexadecimal
 * in unsigned nr
 * @list: list of args
 * @buffer: buffer container to help print
 * @flags: active flags
 * @width: width
 * @precision: specifies precision
 * @size: specifies size/length (l or h)
 * Return: number of chars printed
 */
int print_upper_hexa(va_list list, char buffer[], int flags, int width,
		int precision, int size)
{
	return (hexa_print(list, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/**
 * hexa_print_ul - print hexadecimal in upper or lower
 * @flags: active flags such as '#'
 * @list: list of args
 * @width: width
 * @buffer: 1024 container to help print
 * @precision: specifies precision
 * @size: size specifier/len(l or h)
 * @map_to_nr: values in an array used to map numbers
 * @flag_cha: active flags
 * Return: needs to print hexa upper or lower
 */
int hexa_print_ul(va_list list, char map_to_nr[], char buffer[],
		int flags, char flag_cha, int width,
		int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int nr = va_arg(types, unsigned long int);
	unsigned long int initi_nr = nr;

	UNUSED(width);
	nr = changed_size_un_sgned(nr, size);

	if (nr == 0)
		buffer[a--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (nr > 0)
	{
		buffer[a--] = map_to_nr[nr % 16];
		nr = nr / 16;
	}

	if (flags & F_HASH && initi_nr != 0)
	{
		buffer[a--] = flag_cha;
		buffer[a--] = '0';
	}
	a++;

	return (write_un_sgned(0, a, buffer, flags,
				width, precision, size));
}
/**
 * print_rot13string - prints a string in rot13
 * @flags: active flags such as '#'
 * @list: list of args
 * @width: width
 * @buffer: 1024 container to help print
 * @precision: specifies precision
 * @size: size specifier/len(l or h)
 * Return: needs to print a string in rot13
 */
int print_rot13string(va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	char z;
	char *str;
	unsigned int a, b;
	int counter = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (a = 0; str[a]; a++)
	{
		for (b = 0; in[b]; b++)
		{
			if (input[b] == str[a])
			{
				z = output[b];
				write(1, &z, 1);
				counter++;
				break;
			}
		}
		if (!in[b])
		{
			z = str[a];
			write(1, &z, 1);
			counter++;
		}
	}
	return (counter);
}
