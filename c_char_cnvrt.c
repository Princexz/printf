#include "holberton.h"
/**
* c_char_cnvrt - copy char to string
* @args: ASCII value to be converted
*
* Return: Converted string
*/
char *c_char_cnvrt(va_list args)
{
	char *print_char;

	print_char = malloc(sizeof(char) + 1);
	if (print_char == NULL)
		return (NULL);
	print_char[0] = va_arg(args, int);
	print_char[1] = '\0';
	return (print_char);
}
