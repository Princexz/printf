#include "holberton.h"
/**
* s_string_cnvrt - a function that copies a string
* @args: argument to be copies
*
* Return: copied string
*/
char *s_string_cnvrt(va_list args)
{
	int j;
	char *arg = va_arg(args, char *);
	char *dest;

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
		dest = malloc(sizeof(char) * (_strlen(arg) + 1));
		if (dest == NULL)
			return (NULL);

		/* copy arg to buffer */
		for (j = 0; arg[j] != '\0'; j++)
			dest[j] = arg[j];
		dest[j] = '\0';
	}
	/* return copied string */
	return (dest);
}
