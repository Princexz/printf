#include "main.h"

/**
 * _printf - Simulates the printf function
 * @format: Format to print to the console
 *
 * Description: Function that simulate the printf function
 * for the following conversion specifiers:
 *    - c:    Chracter
 *    - s/S:  Strings. 's' prints the same string.
 *            'S' prints the string, changing the non-printable characters
 *            to '\x??' format, where '??' corresponds to a hexadecimal number
 *    - d/i:  Integers
 *    - o:    Octal numbers
 *    - x/X:  Hexadecimal numbers
 *    - b:    Binary numbers
 *    - u:    Unsigned numbers
 *    - %:    '%' char
 *    - r:    Reverse string
 *    - R:    Root13 of the string
 * The function considerate the next arguments, checking the usability for the
 * conversion specifier used:
 * (+)      Adds a '+' sign to positive integers
 * ( )      Adds a ' ' to the start of the number
 * (#)      Adds '0' or '0x' to the start of the octal or hexadecimal number
 * (l)      Converts the number to a 'long' type
 * (h)      Converts the number to a 'short' type
 * (width)  Add spaces(?) to the printing format
 * (preci)  Print the number with the corresponding precision
 * (0)      Add '0' to the spaces created with 'width'
 * (-)      Justify the string to the left
 *
 * Return: Number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list list;
	char *buffer, *str;
	int i = 0, i_buffer = 0, j_spec, lenstr, stock = 0;

	buffer = malloc(1024);
	if (buffer == NULL)
		return (-1);
	va_start(list, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (check_specs(format + i, &j_spec) == 1
			    && check_format(format + i, j_spec))
			{
				str = generate_malloc(format + i, j_spec, list, &lenstr);
				lenstr = format[i + j_spec - 1] == 'c' ? lenstr : _strlen(str);
				if (str == NULL)
					return (free_buffer(buffer, i_buffer));
				_memcpy(buffer, str, &i_buffer, &stock, lenstr), free(str);
				i += j_spec;
				continue;
			}
			if (check_specs(format + i, &j_spec) == -1)
				return (free_buffer(buffer, i_buffer));
			if (format[i + 1] == 'h' || format[i + 1] == 'l')
				_memcpy(buffer, format + i, &i_buffer, &stock, 1), j_spec = 2;
			else
				_memcpy(buffer, format + i, &i_buffer, &stock, j_spec);
			i += j_spec;
			continue;
		}
		_memcpy(buffer, format + i, &i_buffer, &stock, 1), i++;
	}
	va_end(list), i_buffer = write(1, buffer, i_buffer), free(buffer);
	return (i == 0 && !format ? -1 : stock + i_buffer);
}

/**
 * check_specs - Check if a string has a conversion specifier
 * @s: String where to check the conversion specifier
 * @p: Pointer to the variable where the length to consider is saved
 * Return: -1 if ends the string
 * 0 if does not find a conversion specifier but does not end the format
 * 1 if find a conversition specifier
 */
int check_specs(const char *s, int *p)
{
	char *specs = "%csSdioxXburRp";
	char *flags = " 0-+#123456789.lh*";
	int i = 0, j = 0, len_flags = _strlen(flags);

	while (s[i])
	{
		j = 0;
		while (specs[j])
		{
			if (s[i] == specs[j] && i != 0)
			{
				*p = i + 1;
				return (1);
			}
			j++;
		}
		j = 0;
		while (flags[j])
		{
			if (s[i] == flags[j])
				break;
			j++;
		}
		if (i > 0 && j == len_flags)
			break;
		i++;
	}
	if (!s[i])
		return (-1);
	*p = i;
	return (0);
}


/**
 * _memcpy - copies the memory from src to the buffer
 * @buffer: The destination pointer
 * @src: The source pointer
 * @i_b: Pointer to the index of the buffer
 * @stock: Pointer to the actual stock of bytes written
 * @n: bytes to use from src
 *
 * Description: Copies the memory from src to the buffer inserted.
 * the buffer has a limit of 1024. If the index of buffer is greater than
 * 1024 after the copy, writes the content to the standard output, sum the
 * bytes written and resets the index
 *
 * Return: Nothing(?)
 */
void _memcpy(char *buffer, const char *src, int *i_b, int *stock, int n)
{
	int i = 0;

	while (i < n)
	{
		*(buffer + *i_b) = *(src + i);
		i++;
		*i_b = *i_b + 1;
		if (*i_b > 1024)
		{
			*stock = *stock + *i_b;
			write(1, buffer, *i_b);
			*i_b = 0;
		}
	}
}

/**
 * _strlen - return the length of a string
 * @s: Pointer to an string
 *
 * Return: Length of the string
 * If is a null pointer returns 0
 */
int _strlen(char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);

	while (*(s + i) != '\0')
		i++;

	return (i);
}

/**
 * free_buffer - Writes the content of the buffer and frees it
 * @buff: Buffer to free
 * @len: Bytes to write
 *
 * Return: Always -1 (Success)
 */
int free_buffer(char *buff, int len)
{
	write(1, buff, len);
	free(buff);
	return (-1);
}
