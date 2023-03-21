#include "holberton.h"

/**
* r_reverse_cnvrt - reverses a string
* @args: argument to be reversed
*
* Return: reversed string
*/
char *r_reverse_cnvrt(va_list args)
{
	int i, j; /* looping variables */
	char *arg = va_arg(args, char *);
	char *dest; /* target string */

	/* if NULL, return "(null)" */
	if (!arg)
	{
		dest = malloc(sizeof(char) * 7);
		if (dest == NULL)
			return (NULL);
		dest = "(null)";
	}
	else
	{
		/* allocate memory for dest */
		dest = malloc(sizeof(char) * (_strlen(arg) + 1));
		if (dest == NULL)
			return (NULL);

		/* copy arg to new string in reverse */
		i = _strlen(arg) - 1;
		j = 0;
		while (i >= 0)
			dest[j++] = arg[i--];

		/* initialize null-byte */
		dest[j] = '\0';
	}

	return (dest);
}
