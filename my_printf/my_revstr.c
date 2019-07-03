/*
** EPITECH PROJECT, 2019
** czd
** File description:
** cze
*/

#include <unistd.h>
#include "../include/my_print.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

char *my_revstr(char *str)
{
    int a;
    int i = 0;
    char truc;

    a = 0;
    while (str[i] != '\0')
        i += 1;
    i -= 1;
    while (str[a] != '\0') {
        truc = str[a];
        str[a] = str[i];
        str[i] = truc;
        a = a + 1;
        i = i - 1;
	my_putchar(str[i]);
    }
    return (str);
}
