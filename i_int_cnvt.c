#include "holberton.h"
/**
* i_int_cnvrt - converts an integer to string
* @args: argument to be converted
*
* Return: Converted string
*/
char *i_int_cnvrt(va_list args)
{
	char *num_to_s;

	num_to_s = malloc(sizeof(char) * 100);
	if (num_to_s == NULL)
		return (NULL);

	return (_itoa(va_arg(args, int), num_to_s, 10));
}

/**
* li_int_cnvrt - converts a long integer to string
* @args: long int to be converted
*
* Return: Converted string
*/
char *li_int_cnvrt(va_list args)
{
	char *num_to_s;

	num_to_s = malloc(sizeof(char) * 100);
	if (num_to_s == NULL)
		return (NULL);

	return (_itoa(va_arg(args, long int), num_to_s, 10));
}
