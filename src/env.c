/*
** EPITECH PROJECT, 2019
** fvezqV
** File description:
** VEZQEVG
*/

#include "my.h"
#include "my_print.h"

int count_line(char **env)
{
    int i = 0;

    for (; env[i]; i++);
    return (i);
}

int count_leng_line(char *env)
{
    int n = 0;

    for (; env[n]; n++);
    return (n);
}

char **create_tmp(char **env, int *i)
{
    char **tmp_env = malloc(sizeof(char*) * (count_line(env) + 2));

    for (; env[*i]; *i += 1) {
        tmp_env[*i] = malloc(sizeof(char) * (count_leng_line(env[*i]) + 1));
        for (int n = 0; env[*i][n]; n++)
            tmp_env[*i][n] = env[*i][n];
    }
    return (tmp_env);
}

int condi_env(char **param, char **tmp_env, int *i, char ***env)
{
    int u = 0;

    if (param[1] == NULL) {
            for (int m = 0; tmp_env[m] != NULL; m++)
                my_printf("%s\n", tmp_env[m]);
            return (84);
    }
    for (int n = 0; param[1][n]; n++)
        if (param[1][n] <= 47 || param[1][n] >= 123 ||
            (param[1][n] >= 58 && param[1][n] <= 64) ||
            (param[1][n] >= 91 && param[1][n] <= 96)) {
            my_printf("setenv: Variable name must");
            my_printf(" contain alphanumeric characters.\n");
            return (84);
        }
    if (param[2] == NULL) {
        tmp_env[*i] = malloc(sizeof(char) * READ_SIZE);
        for (; param[1][u]; u++)
            tmp_env[*i][u] = param[1][u];
        tmp_env[*i][u] = '=';
        *env = tmp_env;
        return (84);
    }
    return (0);
}

int my_setenv(char ***env, char *buff)
{
    int n = 0;
    int i = 0;
    char **tmp_env = create_tmp(*env, &i);
    char **param = parse_buff(buff, ' ', '\t');

    if (condi_env(param, tmp_env, &i, env) == 84)
        return (0);
    tmp_env[i] = malloc(sizeof(char) * READ_SIZE);
    for (int m = 0; param[1][m] != '\0'; m++) {
        tmp_env[i][n] = param[1][m];
        n++;
    }
    tmp_env[i][n] = '=';
    n += 1;
    for (int s = 0; param[2][s] != '\0'; s++) {
        tmp_env[i][n] = param[2][s];
        n++;
    }
    *env = tmp_env;
    return (0);
}
