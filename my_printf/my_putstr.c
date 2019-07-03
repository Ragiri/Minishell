/*
** EPITECH PROJECT, 2019
** vzs
** File description:
** vz
*/

#include "../include/my_print.h"

int my_putstr(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a = a + 1;
    }
    return (0);
}
