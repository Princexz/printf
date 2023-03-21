#include "holberton.h"
/**
* d_decimal_cnvrt -  converts decimal to string
* @args: decimal to be converted to string
*
* Return: converted string on Success, NULL on Fail
*/
char *d_decimal_cnvrt(va_list args)
{
	char *num_to_s;

	/* allocate for new buffer */
	num_to_s = malloc(sizeof(char) * 100);
	if (num_to_s == NULL)
		return (NULL);

	/* convert number to str in new buffer and return */
	return (_itoa(va_arg(args, int), num_to_s, 10));
}
/**
* ld_decimal_cnvrt -  converts long decimal to string
* @args: long decimal to be converted to string
*
* Return: converted string on Success, NULL on Fail
*/
char *ld_decimal_cnvrt(va_list args)
{
	char *num_to_s;

	/* allocate for new buffer */
	num_to_s = malloc(sizeof(char) * 100);
	if (num_to_s == NULL)
		return (NULL);

	/* convert number to str in new buffer and return */
	return (_itoa(va_arg(args, long int), num_to_s, 10));
}
