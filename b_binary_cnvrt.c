#include "holberton.h"
/**
 * b_binary_cnvrt - convert unsigned number to binary
 * @args: decimal to convert
 *
 * Return: converted string on Success, NULL on Fail
 */
char *b_binary_cnvrt(va_list args)
{
	char *cnvrtd_str;
	int base = 2, i = 0; 
	unsigned int rem = 0;
	unsigned int num = va_arg(args, unsigned int);
	
	/* allocate for converted string */
	cnvrtd_str = malloc(sizeof(char) * 100);
	if (!cnvrtd_str)
		return (NULL);

	while (num)
	{
		rem = num % base;
		cnvrtd_str[i++] = rem + 48;
		num /= base;
	}

	cnvrtd_str[i] = '\0';

	return (_revstr(cnvrtd_str));
}
/**
 * lb_binary_cnvrt - convert unsigned long number to binary
 * @args: decimal to convert
 *
 * Return: converted string on Success, NULL on Fail
 */
char *lb_binary_cnvrt(va_list args)
{
	char *cnvrtd_str;
	int base = 2, i = 0; 
	unsigned long rem = 0;
	unsigned long num = va_arg(args, unsigned long);
	
	/* allocate for converted string */
	cnvrtd_str = malloc(sizeof(char) * 100);
	if (!cnvrtd_str)
		return (NULL);

	while (num)
	{
		rem = num % base;
		cnvrtd_str[i++] = rem + 48;
		num /= base;
	}

	cnvrtd_str[i] = '\0';

	return (_revstr(cnvrtd_str));
}
