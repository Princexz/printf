 ## ALX printf Project

This a repository for the ALX team project for the printf.

The printf() function prints output to stdout, according to format and other arguments passed to printf(). 
The string format consists of two types of items - characters that will be printed to the screen,
and format commands that define how the other arguments to printf() are displayed. Basically,
you specify a format string that has text in it, as well as "special" characters
that map to the other arguments of printf().

---

The prototype of this function is: int _printf(const char format, ...);

This means that it has one mandatory format argument, and an extra number of arguments that can be none, or many.

Format of the format string

The format string is a character string starting and ending with double quotes. The format string is composed of zero or more directives; ordinary characters (not %), and conversion specifications, each of which results in fetching zero or more subsequent arguments.

Each conversion specification is introduced by the character % and ends with a conversion specifier. In between there may be (in this order):

Zero or more flags

An optional field width

An optional precision modifier

An optional length modifier


 ## **Synopsis**

The function _printf() writes output to stdout, the standard output stream with the format and options presented below. It uses an internal buffer of 1024 bytes although it can print larger sets of data.

Upon successful execution, this function returns the number of characters printed (excluding the null byte used to end output to strings).

If an output error is encountered, a negative value of -1 is returned.

The prototype of this function is the next:

> **int _printf(const char *format, ...);***

Meaning that it has one mandatory format argument, and an extra number of arguments that can be none, or many.

**Format of the format string**

The format string is a character string starting and ending with double quotes. The format string is composed of zero or more directives; ordinary characters (not %), and conversion specifications, each of which results in fetching zero or more subsequent arguments. 

Each conversion specification is introduced by the character **%** and ends with a **conversion specifier**. In between there may be (in this order):

> Zero or more **flags**
>
> An optional field **width**
>
> An optional **precision** modifier
>
> An optional **length** modifier


# **The flag characters**

|**Flag**| Description  |
|--|--|
|**#**| For **o** conversions the first character of the output string is made zero (by prefixing a 0 if it was not zero already).  For **x** and **X** conversions, a nonzero result has the string "**0x**" or "**0X**" respectively added. |
|**0**| (Not implemented yet) The  value should be zero padded. For **d**, **i**, **o**, **u**, **x**, and **X** the converted value is padded on the left with zeros. If the 0 and **-** flags both appear,the **0** flag is ignored. If a precision is given with a numeric conversion, the **0** flag is ignored.|
|**-**|(Minus sign, not implemented yet) The converted value is to be left adjusted on the field boundary, (Default is right justification) and  padded  with  blanks  in  the right rather than on the left with blanks or zeros. This flag overrides **0** if both are given.|
|' '| (Blank Space) The argument is padded with a single blank space before a positive number or empty string produced by a signed conversion.|
|**+**| A sign (+ or -) should always be placed before a number produced with a signed conversion.  By default, only negative numbers have this sign.|

# **The field width**

An  optional decimal digit string (with nonzero first digit) specifying a minimum field width.  If  the  converted  value  has  fewer characters  than  the field width, it will be padded with spaces on the left if the flag - is not present, and on the right  if  it  is present.  A character * can be used instead of a decimal string. In this case, an argument passed to the function will be taken as  the width value.

    printf("%5d", num);

or

	printf("%*d", width, num);

**The precision**

 An  optional  precision,  in  the  form  of a period ('.')  followed by an optional decimal digit string.  A negative precision is taken  as  if  the precision were omitted.  This gives the minimum number of digits to appear for d, i, o, u, x, and X conversions,  or the  maximum  number of characters to be printed from a string for s and S conversions. A character * can be used instead of a  decimal string. In this case, an argument passed to the function will be taken as the precision value.

    printf("%.3d", num);

  or

    printf("%.*d", precision, num);

**The length modifiers**

|Modifier| Description |
|--|--|
|**l**| An integer conversion to a **long int** or **unsigned long int** argument.  |
|**h**| An integer conversion to a **short int** or **unsigned short int** argument. |

**The conversion specifier**

|Specifier| Description |
|--|--|
|**d, i**|The argument **int** is converted to a signed decimal notation. If precision is present,it gives the minimum number of digits that must appear; if the converted value requires fewer digits, then it is padded with zeros on the left. Default precision is 1.|
|**o, u, x, X**|The argument is converted to unsigned octal (**o**), unsigned decimal (**u**), or unsigned hexamedical (**x** and **X**) notation. The letters abcdef are used for x conversion and the letters ABCDEF are used for X conversion. If precision is present, it will give  the  minimum  number  of  digits  that  must appear; if the converted value requires fewer digits, then it will be padded with zeros. By default the precision is 1.  |
|**c**|The  int argument is converted to an unsigned char and the resulting character is written. The representation of characters is based off the ASCII coding.|
|**s**|The argument received is expected to be a pointer type char * to an array of characters.  Characters from this array are printed up  to  (but  not including) a null byte  (**'\0'**).  If precision is specified, then this will determine how many characters are taken into account for printing.|
|**p**|A void * pointer argument is printed as hexadecimal in lower caps representing an adress in memory.|
|**%**|A  ' **%** ' character is written and no conversion is made. The specification is as follows: **%%**. |
|**b**|The argument is converted to an unsigned int value and then operated to get its binary representation (base 2).|
|**S**| The  argument  received  is expected to be a pointer type char * to an array of characters.  Characters from this array are printed up to (but not including) a null byte  ('\0').  Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by  the  ASCII  code value in hexadecimal (upper case - always 2 characters). |
|**r**|The  argument received is expected to be a pointer type char * to an array of characters.  Characters from this array are printed in reverse order up to (but not including) a null byte  ('\0').  |
|**R**|The argument received is expected to be a pointer type char * to an array of characters.  Characters from this array  are  encoded  to  ROT13  and printed in order up to (but not including a null byte  ('\0').  |

---

/* This header is mandatory for the function to run */
    #include "main.h"
    /**
    * This Header is optional and allows you to compare the
    *  custom _printf() function to the standard library one.
    */
    #include <stdio.h>

    /**
     * main - Entry point
     *
     * Return: Always 0
     */

    int main(void)
    {
        int len1, len2;
        char *s = "Hello";

        /* The '\n' character is used for printing a new line */

        /* Custom printf Function */
         _printf("Text\n");
        /* Standard Library printf Function */
         printf("Text\n");
         _printf("Hello %s\n", World);
         printf("Hello %s\n", World);
         _printf("I like %ctags\n", '#');
         printf("I like %ctags\n", '#');

         len1 = _printf("%s World\n", s);
         len2 = printf("%s World\n", s);

         _printf("The length was [%d]\n", len1);
         printf("The length was [%d]\n", len2);

	 _printf("Plus Sign Pos Number[%+d]\n", 54);
	 _printf("Plus Sign Neg Number[%+d]\n", -54);

	 _printf("Space Pos Number[% d]\n", 54);
	 _printf("Space Neg Number[% d]\n", -54);

	 _printf("Hash Hexadecimal[%#x]\n", 123);
	 _printf("Hash Octal[%#o]\n", 123);

         return (0);
    }

--- # **Compilation:**

When you are done creating you *main.c* file  you will need to compile it. You can use any compiler software you like, although this project was tested in GNU GCC 5.5.0 with different error flags such as:

> **-Wall:** Enables all the warnings about constructions.
>
> **-Wextra :** Enables some extra warning flags that are not enabled by **-Wall**.
>
> **-Werror:** Make all warnings into hard errors.
>
> **-pedantic:** Issue all the mandatory diagnostics listed in the C standard.
>
> **-Wno-format:** Disables warnings about printf format (so that you can try any type of format you want) in equivalence to a custom made variadic function.

    test@ubuntu:~/printf$ gcc -Wall -Wextra -Werror -pedantic -Wno-format *.c

# **Execution:**

    test@ubuntu:~/printf$ ./a.out

> **Output:**
>
> Text
>
> Text
>
> Hello World
>
> Hello World
>
> I like #tags
>
> I like #tags
>
> Hello World
>
> Hello World
>
> The length was [12]
>
> The length was [12]
>
>Plus Sign Pos Number[+54]
>
>Plus Sign Neg Number[+54]
>
>Space Pos Number[ 54]
>
>Space Pos Number[-54]
>
>Hash Hexadecimal[0x7B]
>
>Hash Octal[0173]

## **Flowchart**

Here is a diagram of the general behaviour of the _printf.

The most important functions are presented:

_printf


## **Flowchart**

Here is a diagram of the general behaviour of the _printf.

The most important functions are presented:

_printf

![_printf](https://i.imgur.com/nOO6dKj.png)

Generate malloc

![Generate Malloc](https://i.imgur.com/oqukAVN.png)

## **Bugs**

The field width and precision modifiers are still in development, so there may be flaws with their functions.
The flags (-) and (0) are yet to be implemented.## **Flowchart**

Here is a diagram of the general behaviour of the _printf.

The most important functions are presented:

_printf

![_printf](https://i.imgur.com/nOO6dKj.png)

Generate malloc

![Generate Malloc](https://i.imgur.com/oqukAVN.png)

## **Bugs**

The field width and precision modifiers are still in development, so there may be flaws with their functions.
The flags (-) and (0) are yet to be implemented.


## Author :black_nib:

* **Prince Solomon** [princexz](https://github.com/princexz)

## Acknowledgements :pray:

All work contained in this project was completed as part of the curriculum for ALX Africa SE. ALX Africa is an online full-stack software engineering program that prepares students for careers in the tech industry using project-based peer learning. For more information, visit [this link](https://www.alxafrica.com//).

<p align="center">
  <img
   src="https://www.alxafrica.com/wp-content/uploads/2022/01/header-logo.png"
       alt="ALX Africa Logo"
  >
</p>



