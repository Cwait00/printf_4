#include "main.h"

/*****CHAR****/

/**
 * print_char - prints a char
 * @width: introduces width
 * @buffer: 1024 array to help handle print
 * @flags: active flags such as '#', '-', etc
 * @size: specifies size
 * @precision: specifies precision
 * @types: list of arguments
 * Return: nr of chars to be printed
 */
int print_char(va_list types, int flags, char buffer[],
		int width, int size, int precision)
{
	char_c = va_arg(types, int);

	return (write_char(c, buffer, flags, size, width, precision));
}

/****STRING****/

/**
 * print_str - prints a string
 * @width: introduces width
 * @buffer: 1024 array to help with printing
 * @flags: active flags such as '#', '-', etc
 * @size: specifies size
 * @precision: specififes precisions
 * @types: list of args
 * Return: string in form of chars?
 */
int print_str(va_list types, int flags, char buffer[],
		int width, int size, int precision)
{
	int len = 0;
	int a;

	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = " ";
	}
	while (str[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (a = width - len; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - len; a > 0; a--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}

/***PERCENT SIGN***/
/**
 * print_pecent - prnts the percent sign
 * @width: width
 * @precision: specifies precision
 * @size: specifies size
 * @flags: active flags '#', '-', etc
 * @buffer: 1024 containter that helps us print
 * @types: list of args
 * Return: needs to print percent
 */
int print_percent(va_list types, int precision, int size,
		int width, int flags, char buffer[])
{
	UNUSED(types);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(buffer);

	write(1, "%%", 1);
}

/***INT***/
/**
 * print_int - prints integer
 * @types: list of args
 * @precision: specifies precision
 * @size: specifies size
 * @width: width
 * @flags: active flags such as '#', '-', etc
 * @buffer: 1024 containter that helps print
 * Return: needs to print int
 */
int print_int(va_list types, int flags, char buffer[],
		int size, int precision, int width)
{
	int a = BUFF_SIZE - 2;
	int nega = 0;
	long int b = va_arg(types, long int);
	unsigned long int nr;

	b = change_size_num(b, size);

	if (b == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	nr = (unsigned long int)b;

	if (b < 0)
	{
		nr = (unsigned long int)((-1) * b);
		nega = 1;
	}

	while (nr > 0)
	{
		buffer[a--] = (nr % 10) + '0';
		nr = nr / 10;
	}
	a++;

	return (write_nr(nega, a, buffer, flags, width, size, precision));
}

/***BINARY***/
/**
 * print_binary - prints binary
 * @width: width
 * @precision: specifies precision
 * @size: specifies size
 * @flags: contains active flags
 * @types: list of args
 * @buffer: buffer container used to help print
 * Return: needs to print binary
 */
int print_binary(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	unsigned int a;
	unsigned int b;
	unsigned int c;
	unsigned int sum;
	unsigned int x[32];
	int counter;

	UNUSED(flags);
	UNUSED(size);
	UNUSED(buffer);
	UNUSED(width);
	UNUSED(precision);

	a = va_arg(types, unsigned int);
	b = (2 ^ 31);
	x[0] = a / b;

	for (c = 1; c < 32; c++)
	{
		b = b / 2;
		x[c] = (a / b) % 2;
	}

	for (c = 0, sum = 0, counter = 0; c < 32; c++)
	{
		sum += x[c];
		if (sum || c == 31)
		{
			char i = '0' + x[c];

			write(1, &i, 1);
			counter++;
		}
	}
	return (counter);
}
