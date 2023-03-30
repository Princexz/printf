#include "holberton.h"

/**
 * print_i - Prints integer
 * @i: Int to print
 *
 * Return: Numbers of integers printed
 */
int print_i(va_list i)
{
	int count = 0;

	if (i < 0)
	{
		putchar('-');
		i = -i;
	}
	if (i / 10)
	{
		print_i(i / 10);
		count++;
	}
	putchar((i % 10) + '0');

	return (count);
}

/**
 * print_d - Prints a decimal number
 * @d: Number to print
 *
 * Return: Numbers of decimals printed
 */
int print_d(va_list d)
{
	int count = 0;

	if (i < 0)
	{
		putchar('-');
		i = -i;
	}
	if (i / 10)
	{
		print_d(i / 10);
		count++;
	}
	putchar((i % 10) + '0');

	return (count);
}
