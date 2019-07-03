/*
** EPITECH PROJECT, 2018
** unsigned
** File description:
** flag %u
*/

#include "../include/my_print.h"

void my_put_nbr_unsigned(unsigned int nb)
{
    unsigned int str = nb;
    int a = 1;
    int n = 1;
    int c;

    while (str >= 10) {
        a *= 10;
        n += 1;
        str /= 10;
    }
    while (n > 0) {
        c = ((nb / a) % 10) + 48;
        a /= 10;
        n -= 1;
        my_putchar(c);
    }
}
