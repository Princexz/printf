#include "holberton.h"
char *_utoa(unsigned long int number, char *buffer, int base);

/**
* u_unsigned_cnvrt - converts an unsigned int to string
* @args: argument to be converted
*
* Return: Converted string on success, NULL on fail
*/
char *u_unsigned_cnvrt(va_list args)
{
	char *u_to_s;

	/* Allocate space for buffer */
	u_to_s = malloc(sizeof(char) * 100);
	if (u_to_s == NULL)
		return (NULL);

	/* Convert unsigned int to string in new buffer and return*/
	return (_utoa(va_arg(args, unsigned int), u_to_s, 10));
}
/**
* lu_unsigned_cnvrt - converts a long unsigned int to string
* @args: long unsigned int to be converted
*
* Return: Converted string on success, NULL on fail
*/
char *lu_unsigned_cnvrt(va_list args)
{
	char *u_to_s;

	/* Allocate space for buffer */
	u_to_s = malloc(sizeof(char) * 100);
	if (u_to_s == NULL)
		return (NULL);

	/* Convert unsigned int to string in new buffer and return*/
	return (_utoa(va_arg(args, unsigned long), u_to_s, 10));
}
/**
* _utoa - A function that converts an unsigned int to a string
* @number: Number to be converted
* @buffer: Holds the string while converting
* @base: base value for string to be returned in
*
* Return: Converted string on Success, Null on fail
*/
char *_utoa(unsigned long int number, char *buffer, int base)
{
	int i = 0;
	long int remainder = 0;

	/* if number is 0, hard code result */
	if (number == 0)
	{
		buffer[i++] = '0';
		buffer[i] = '\0';
	}
	/* if number is not 0 */
	while (number)
	{
		remainder = number % base;
		buffer[i++] = '0' + remainder;
		number /= base;
	}

	/* terminate string */
	if (number)
		buffer[i] = '\0';
	return (_revstr(buffer));
}
