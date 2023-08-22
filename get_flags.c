#include "main.h"

/**
 * get_flags - calculate number of flags.
 * @format: Format strings to print arguments.
 * @x: take a parameter.
 * Return: Flags.
 */

int get_flags(const char *format, int *x)
{
	/* - = 0 # ' ' */
	/* 1 2 4 8 16 8*/

	int n, curr_x;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_x = *x + 1; format[curr_x] != '\0'; curr_x++)
	{
		for (n = 0; FLAGS_CH[n] != '\0'; n++)
			if (format[curr_x] == FLAGS_CH[n])
			{
				flags |= FLAGS_ARR[n];
				break;
			}

		if (FLAGS_CH[n] == 0)
			break;
	}

	*x = cuur_x - 1;

	return (flags);
}
