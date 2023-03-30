#include "holberton.h"
#include <stdlib.h>

/**
 * check_formats - Checks for specifiers
 * @format: Specifier
 *
 * Return: Pointer to function or NULL
 */
static int (*check_formats(const char *format))(va_list)
{
	unsigned int i;
	print_t mystruct[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_d},
		{"b", print_b},
		{"R", print_R},
		{NULL, NULL}
	};

	for (i = 0; mystruct[i].t != NULL; i++)
	{
		if (*(mystruct[i].t) == *format)
		{
			break;
		}
	}
	return (mystruct[i].f);
}

/**
 * _printf - Function that prints with a format
 * @format: Format passed to printf
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list mylist;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);
	va_start(mylist, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}
		if (!format[i])
			return (count);
		f = check_formats(&format[i + 1]);
		if (f != NULL)
		{
			count += f(mylist);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(mylist);
	return (count);
}
