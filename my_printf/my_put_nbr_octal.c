/*
** EPITECH PROJECT, 2018
** octal
** File description:
** octal base
*/

#include "../include/my_print.h"

void my_put_nbr_octal(int nb)
{
    int str = nb;
    int a = 1;
    int n = 1;
    int c;

    while (str >= 8) {
	a *= 8;
        n += 1;
	str /= 8;
    }
    if (nb >= 0) {
        while (n > 0) {
            c = ((nb / a) % 8) + 48;
            a = a / 8;
            n -= 1;
            my_putchar(c);
        }
    }
}
