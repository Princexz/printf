#include "holberton.h"
void _print_string(char *s);
void _free(char *a, char *b);
/**
* _printf - A function that prints formatted text
* @format: Character string
* Return: number of chars printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int fmt_i, dest_i, i; /* string iterators */
	char *fmt_spec, *cnvrtd_str, dest_buff[1024]; /* string to return */

	if (!format)
		return (-1);
	va_start(args, format);
	for (fmt_i = dest_i = 0; format[fmt_i]; fmt_i++, dest_i++)
	{
		if ((format[fmt_i] == '%') && (format[fmt_i + 1] != '%'))/* check for '%' */
		{
			if (format[fmt_i + 1] == '\0')
			{
				dest_buff[dest_i] = '\0';
				_print_string(dest_buff);
				return (-1);
			}
			fmt_spec = cpy_fmt_spec(&format[fmt_i]); /* copy fmt spec to new str */
			if (fmt_spec) /* if valid specifier, send to mnger to retrieve fp */
			{
				cnvrtd_str = fmt_mngr(args, fmt_spec);
				if (!cnvrtd_str)
					return (-1);
				for (i = 0; cnvrtd_str[i]; i++, dest_i++)
					dest_buff[dest_i] = cnvrtd_str[i];
				dest_i--;
				fmt_i += _strlen(fmt_spec) - 1;
			}
			else
				dest_buff[dest_i] = format[fmt_i];
		}
		else if ((format[fmt_i] == '%') && (format[fmt_i + 1] == '%'))
			dest_buff[dest_i] = format[++fmt_i];
		else
			dest_buff[dest_i] = format[fmt_i];
	}
	va_end(args);/* free args*/
	dest_buff[dest_i] = '\0';/* place null byte at end of dest*/
	_print_string(dest_buff);
	_free(fmt_spec, cnvrtd_str);
	return (_strlen(dest_buff));
}

/**
 * _free - free multiple buffers
 * @a: string to free
 * @b: string to free
 */
void _free(char *a, char *b)
{
	if (a)
		free(a);
	if (b)
		free(b);
}
/**
 * _print_string - print string
 * @s: string to print
 */
void _print_string(char *s)
{
	int i = 0;

	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
