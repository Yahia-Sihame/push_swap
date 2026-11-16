#include "checker.h"

void ft_putdouble(double num)
{
    int     integer;
    int     decimal;

    integer = (int)num;
    decimal = (int)((num - integer) * 100);

    ft_putnbr_fd(integer, 2);
    write(1, ".", 1);
    if (decimal < 10)
        write(1, "0", 1);
    ft_putnbr_fd(decimal, 2);
}
