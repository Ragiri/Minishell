/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** oburebho
*/

#include <stdio.h>
#include "../include/my_print.h"

void my_put_nbr(int nb)
{
    int str = nb;
    int a = 1;
    int n = 1;
    int c;

    while (str >= 10) {
        a = a * 10;
        n = n + 1;
        str = str / 10;
    }
    if (nb >= 0) {
        while (n > 0) {
            c = ((nb / a) % 10) + 48;
            a = a / 10;
            n = n - 1;
            my_putchar(c);
        }
    }
}
