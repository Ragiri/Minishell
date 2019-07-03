/*
** EPITECH PROJECT, 2019
** cz
** File description:
** vesz
*/

#include "my.h"
#include "my_print.h"

char *my_strcat(char *str, char *tmp)
{
    char *cmp = malloc(sizeof(char) * READ_SIZE);
    int n = 0;

    for (int t = 0; str[t]; t++) {
        cmp[n] = str[t];
        n++;
    }
    for (int i = 0; tmp[i]; i++) {
        cmp[n] = tmp[i];
        n++;
    }
    cmp[n] = '\0';
    return (cmp);
}

char **exec_bis(char *buff)
{
    char **argv_sh = malloc(sizeof(char*) * 3);
    int n = 0;

    argv_sh[0] = malloc(sizeof(char) * 500);
    for (int i = 2; buff[i] != '\n'; i++) {    
        argv_sh[0][n] = buff[i];
        n++;
    }
    argv_sh[0][n] = '\0';
    argv_sh[1] = NULL;
    return (argv_sh);
}
