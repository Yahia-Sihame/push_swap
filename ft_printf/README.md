*This project has been created as part of the 42 curriculum by ebajja.*

# ft_printf

## Description

`ft_printf` is a recode of the C function `printf()`. The goal of the project is to learn how variadic functions work in C (`va_start`, `va_arg`, `va_copy`, `va_end`) and to build a reusable library, `libftprintf.a`.

Prototype:

```c
int ft_printf(const char *format, ...);
```

Handled conversions:

| Conversion | Description                                         |
|------------|-----------------------------------------------------|
| `%c`       | Prints a single character.                          |
| `%s`       | Prints a string (as defined by the common C convention). |
| `%p`       | Prints a `void *` pointer in hexadecimal format.    |
| `%d`       | Prints a decimal (base 10) number.                  |
| `%i`       | Prints an integer in base 10.                       |
| `%u`       | Prints an unsigned decimal (base 10) number.        |
| `%x`       | Prints a number in hexadecimal (base 16) lowercase. |
| `%X`       | Prints a number in hexadecimal (base 16) uppercase. |
| `%%`       | Prints a percent sign.                              |

Like the original `printf()`, `ft_printf` returns the total number of characters printed.

## Instructions

Build the library `libftprintf.a` with:

```bash
make        # compile the library
make clean  # remove object files
make fclean # remove object files and the library
make re     # recompile everything
```

Use it in your code:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, number %d\n", "world", 42);
    return (0);
}
```

Compile and link your program with the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

## Algorithm

The function reads the format string character by character:

- A normal character is printed with `write()`.
- After a `%`, the next character decides the conversion. The matching function gets the argument with `va_arg` and prints it.
- Each print function returns the number of characters written, and `ft_printf` adds them up to return the total.

No special data structure is needed: only a `va_list` and a counter. Writing directly with `write()` keeps the code simple and avoids implementing the internal buffer of the original `printf()`. Numbers are printed recursively, digit by digit, so no memory allocation is required.

## Resources

- `man 3 printf`
- `man 3 stdarg`
- `man 2 write`

### Use of AI

AI was used to help me understand how `va_list`, `va_start`, `va_arg` and `va_end` work, and to generate a test program that compares `ft_printf` against the real `printf()`. The test program is not part of the submitted code. All the code of the project was written by me.
