/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "../include/my_print.h"

char *binary_base(int nb)
{
    char *str = malloc(sizeof(char) * nb);
    int i = nb;
    int a = 0;

    while (i > 0) {
        nb = i;
        i = nb / 2;
        nb = nb % 2;
        str[a] = nb;
        a += 1;
    }
    return (str);
}

void condi(char const *str, int i, va_list ap)
{
    if (str[i] == 's')
        my_putstr(va_arg(ap, char*));
    if (str[i] == 'b')
        binary_base(va_arg(ap, int));
    if (str[i] == 'o')
        my_put_nbr_octal(va_arg(ap, int));
    if (str[i] == 'u')
        my_put_nbr_unsigned(va_arg(ap, unsigned int));
    if (str[i] == '%')
        my_putchar('%');
    if (str[i] == 'S')
        flag_s(va_arg(ap, char *));
}

int my_printf(char const *str, ...)
{
    va_list ap;

    va_start(ap, str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '%') {
            i += 1;
            if (str[i] == 'c')
                my_putchar(va_arg(ap, int));
            if (str[i] == 'd')
                my_put_nbr(va_arg(ap, int));
            condi(str, i, ap);
            i += 1;
        }
        my_putchar(str[i]);
    }
    va_end(ap);
    return (0);
}
