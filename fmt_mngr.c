#include "holberton.h"
/**
* fmt_mngr - selects and calls pointer to function
* @args: arg list
* @fmt_spec: format spec (reversed, i.e. "il%")
*
* Return: converted string on Success, NULL on Fail
*/
char *fmt_mngr(va_list args, char *fmt_spec)
{
	/* supported conversion functions */
	func_ps fps[] = {
		{"d", d_decimal_cnvrt}, {"dl", ld_decimal_cnvrt}, /* long variant */
		{"i", i_int_cnvrt}, {"il", li_int_cnvrt}, /* long variant */
		{"c", c_char_cnvrt},
		{"u", u_unsigned_cnvrt}, {"ul", lu_unsigned_cnvrt}, /* long variant */
		{"o", o_octal_cnvrt}, {"ol", lo_octal_cnvrt}, /* long variant */
		{"x", x_lowhex_cnvrt}, {"xl", lx_lowhex_cnvrt}, /* long variant */
		{"X", X_uphex_cnvrt}, {"Xl", lX_uphex_cnvrt}, /* long variant */
		{"b", b_binary_cnvrt}, {"bl", lb_binary_cnvrt}, /* long variant */
		{"s", s_string_cnvrt},
		{"r", r_reverse_cnvrt},
		{"R", R_rot13_cnvrt},
		{NULL, NULL}
	};
	int i = 0; /* iterator */
	char *(*fp)(va_list); /* function pointer */

	while (fps[i].spec)
	{
		/* if match is found, assign pointer and call with args */
		if (*fps[i].spec == fmt_spec[0])
		{
			if (fmt_spec[1] == 'l')
			{
				fp = fps[++i].f;
				return (fp(args));	
			}
			else
			{
				fp = fps[i].f;
				return (fp(args));
			}
		}
		i++;
	}
	/* if no match, return NULL */
	return (NULL);
}
