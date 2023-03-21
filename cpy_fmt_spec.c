#include "holberton.h"

/**
 * cpy_fmt_spec - validate format spec and copy to new string
 * @src: string from which to copy specifier
 *
 * Return: format spec on Success, NULL if invalid spec
 */
char *cpy_fmt_spec(const char *src)
{
	int i, j;
	int size_spec = 0, prec_spec = 0; /* track instance of size/precision specs */
	char *valid_specs = "dicuoxXbsSrRp"; /* possible conversion specifiers */
	char *fmt_spec;

	/* loop through fmt spec candidate, validating char by char */
	for (i = 1; src[i]; i++)
	{
		/* if valid conversion spec */
		for (j = 0; valid_specs[j]; j++)
			/* if match found, copy spec to new str */
			if (src[i] == valid_specs[j])
			{
				/* allocote for fmt spec str (+1 for index offset; +1 for '\0') */
				fmt_spec = malloc(sizeof(*src) * (i + 2));
				if (fmt_spec == NULL)
					return (NULL);
				/* return initialized fmt_spec */
				fmt_spec = (_strncpy(fmt_spec, src, (i + 1)));
				return (_revstr(fmt_spec));
			}
		/**
		 * if given char is not a conversion spec, check to see if
		 * it's on of the format modifiers. we may receive n occurence
		 * of digits, but only one size or precision specifier.
		 */
		/* if not a digit */
		if (src[i] < '0' || src[i] > '9')
		{
			/* if first occurence of 'h' or 'l' */
			if ((src[i] == 'h' || src[i] == 'l') && (!size_spec))
				size_spec = 1;
			/* if first occurence of '.' */
			else if ((src[i] == '.') && (!prec_spec))
				prec_spec = 1;
			else
				break;
		}
	}
	return (NULL);
}
