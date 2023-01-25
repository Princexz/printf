#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct Checkstr - Struct to check format
 *
 * @flag: character associated to flags
 * @flagnot: Flags that are not allowed per specifier
 */
typedef struct Checkstr
{
	char flag;
	char *flagnot;
} checkstr;

/**
 * struct Specs_t - struct to call specifier functions
 *
 * @s: character representing specifier
 * @f: The function associated
 */
typedef struct Specs_t
{
	char s;
	char *(*f)(const char *, int, va_list, int *);
} specs_t;
/* Custom printf function */
int _printf(const char *format, ...);

/* Auxiliar functions */
int _strlen(char *s);
int blen(unsigned long int n, unsigned long int base);
int blen10(long int n, long int base);
void rev_str(char *s);
char *hexS(int n);
char *rot13(char *s);
int check_format(const char *formspec, int j);
int check_specs(const char *s, int *p);
void _memcpy(char *buffer, const char *src, int *i_b, int *stock, int n);
void print_number_str(long int n, char *str);
void print_number_str_u(unsigned long int n, char *str);
int free_buffer(char *, int);
int effective_length(char *buffer);

/* Generate strings functions */
char *generate_malloc(const char *s, int len_p, va_list list, int *);
char *gen_c(const char *, int, va_list, int *);
char *gen_s(const char *, int, va_list, int *);
char *gen_d(const char *, int, va_list, int *);
char *gen_i(const char *, int, va_list, int *);
char *gen_o(const char *, int, va_list, int *);
char *gen_b(const char *, int, va_list, int *);
char *gen_x(const char *, int, va_list, int *);
char *gen_X(const char *, int, va_list, int *);
char *gen_p(const char *, int, va_list, int *);
char *gen_u(const char *, int, va_list, int *);
char *gen_S(const char *, int, va_list, int *);
char *gen_r(const char *, int, va_list, int *);
char *gen_R(const char *, int, va_list, int *);
char *gen_per(const char *, int, va_list, int *);
/* Flags functions */
unsigned int get_width(const char *pattern, int len_p, va_list list);
unsigned int get_precision(const char *pattern, int len_p, va_list list);
long int get_param(const char *pattern, int len_p, va_list list);
unsigned long int get_param_u(const char *pattern, int len_p, va_list list);
void app_flags(const char *, int, char *, int *, int, int);
int app_precision(const char *pattern, int len_p, char *buffer, int pr);
int app_width(char *buffer, int len_b, int wi);
int app_hash(const char *pattern, int len_p, char *buffer);
int app_plus_space(const char *pattern, int len_p, char *buffer);
int check_flag(const char *pattern, int len_p, char flag);
#endif /** Princexz */
