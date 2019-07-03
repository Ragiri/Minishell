/*
** EPITECH PROJECT, 2018
** flag S
** File description:
** my_printf %S
*/

#include "../include/my_print.h"

void flag_s(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 32)
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            my_putchar('0');
            my_put_nbr_octal(str[i]);
        }
    }
}
