#include "holberton.h"
#include <stdlib.h>

/**
 * print_c - Prints characters
 * @c: Character
 *
 * Return: 1: The lenght of a char
 */
int print_c(va_list c)
{
	char ch = (char)va_arg(c, int);

	_putchar(ch);
	return (1);
}

/**
 * print_s - Prints strings
 * @s: Strings
 *
 * Return: The lenght of the string
 */
int print_s(va_list s)
{
	int count;
	char *str = va_arg(s, char *);

	if (str == NULL)
		str = "(null)";
	for (count = 0; str[count]; count++)
	{
		_putchar(str[count]);
	}
	return (count);
}
