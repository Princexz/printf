#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

/* STRUCTURES */
/**
 * struct func_pointers - conversion functions
 * @spec: format specifier
 * @f: function pointer
 */
typedef struct function_pointers
{
	char *spec;
	char *(*f)(va_list);
} func_ps;

/* PARENT FUNCTION */
int _printf(const char *format, ...);

/* MANAGER FUNCTIONS */
char *fmt_mngr(va_list, char *);

/* CONVERSION FUNCTIONS */
char *r_reverse_cnvrt(va_list);
char *R_rot13_cnvrt(va_list);
char *s_string_cnvrt(va_list);
char *c_char_cnvrt(va_list);
char *d_decimal_cnvrt(va_list);
char *ld_decimal_cnvrt(va_list);
char *i_int_cnvrt(va_list);
char *li_int_cnvrt(va_list);
char *u_unsigned_cnvrt(va_list);
char *lu_unsigned_cnvrt(va_list);
char *o_octal_cnvrt(va_list);
char *lo_octal_cnvrt(va_list);
char *x_lowhex_cnvrt(va_list);
char *lx_lowhex_cnvrt(va_list);
char *X_uphex_cnvrt(va_list);
char *lX_uphex_cnvrt(va_list);
char *b_binary_cnvrt(va_list);
char *lb_binary_cnvrt(va_list);

/* FORMATTING FUNCTIONS */

/* HELPER FUNCTIONS */
int _strlen(char *);
char *_itoa(long int, char *, int);
char *_strncpy(char *, const char *, int);
char *_revstr(char *);
void _print_string(char *);
char *cpy_fmt_spec(const char *);
#endif
