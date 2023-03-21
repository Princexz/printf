#include "holberton.h"
/**
* _strlen - Function that finds the length of a string
* @s: string that the length of is found
*
* Return: length of the @s
*/
int _strlen(char *s)
{
	/* variable to loop through string to get length */
	int len = 0;

	/* Loop through string, checking for null byte */
	while (s[len] != '\0')
		len++;

	/* return length variable once null byte is reached */
	return (len);
}
/**
* _itoa - Function that converts a number to string
* @number: value to be converted to a string
* @buffer: array that stores null-termintated string result
* @base: value of the string
* Return: converted string
*/
char *_itoa(long int number, char *buffer, int base)
{
	int sign = 1, i = 0;
	long int remainder = 0;

	/* if number is 0, hard code result */
	if (number == 0)
	{
		buffer[i++] = '0';
		buffer[i] = '\0';
	}
	/* if negative, convert to pos and track sign */
	if (number < 0 && base == 10)
	{
		number *= -1;
		sign *= -1;
	}
	/* if number is not 0 */
	while (number)
	{
		remainder = number % base;
		buffer[i++] = '0' + remainder;
		number /= base;
	}
	/* if negative, add sign char */
	if (sign < 0)
		buffer[i++] = '-';

	/* terminate string */
	if (number)
		buffer[i] = '\0';
	return (_revstr(buffer));
}
/**
 * *_strncpy - copies n bytes of src to dest string
 * @dest: string to copy to
 * @src: string to copy from
 * @n: number of bytes of src to copy
 *
 * Return: string copied to i.e dest
 */
char *_strncpy(char *dest, const char *src, int n)
{
	int i = 0;

	while (i < n)
	{
		if (src[i] == '\0')
			break;
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/**
 * _revstr - reverse string
 * @s: string to reverse
 *
 * Return: reversed string
 */
char *_revstr(char *s)
{
	int i = 0, j = 0, length = 0, half = 0;
	char *rev = s;
	char buff;

	length = _strlen(s);

	if (length % 2 == 0)
		half = length / 2;
	else
		half = (length - 1) / 2;
	for (i = length - 1; i >= half; j++, i--)
	{
		buff = rev[j];
		rev[j] = s[i];
		s[i] = buff;
	}
	return (s);
}
