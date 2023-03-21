#include "holberton.h"
/**
* R_rot13_cnvrt - encode string in rot13
* @args: argument to be encoded
*
* Return: string encoded in rot13
*/
char *R_rot13_cnvrt(va_list args)
{
	int i, j; /*loop iterating variables*/
	char *in = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *out = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *arg = va_arg(args, char *);
	char *encoded;

	if (!arg)
	{
		encoded = malloc(sizeof(char) * 7);
		if (encoded == NULL)
			return (NULL);
		encoded = "(null)";
	}
	else
	{
		/* allocate for encoded, plus null-byte */
		encoded = malloc(sizeof(char) * (_strlen(arg) + 1));
		if (encoded == NULL)
			return (NULL);

		/*  Loop through string until null byte*/
		for (i = 0; arg[i] != '\0'; i++)
			/* increment 51 times, the length of the upper and lower alpha*/
			for (j = 0; j <= 51; j++)
				/* When the letter of the string matches alpha letter*/
				if (arg[i] == in[j])
				{
					/* Replace string letter with Rot13 alpha*/
					encoded[i] = out[j];
					/* break from loop to avoid reversing letter */
					break;
				}
		/* terminate new str with null-byte */
		encoded[i] = '\0';
	}
	/* return the encoded string*/
	return (encoded);
}
