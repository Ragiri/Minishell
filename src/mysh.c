/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** sezv
*/

#include "my.h"
#include "my_print.h"

int count_separator(char *str)
{
    int i = 0;

    for (int n = 0; str[n] != '\n'; n++)
        if (str[n] == ';')
            i += 1;
    return (i);
}

int mysh_condi(char *buff, char ***env)
{
    if (my_strcmp(buff, "setenv") == 0) {
        my_setenv(env, buff);
        return (1);
    }
    if (my_strcmp(buff, "unsetenv") == 0) {
        my_unsetenv(env, buff);
        return (1);
    }
    if (my_strcmp(buff, "cd") == 0) {
        my_cd(buff, env);
        return (1);
    }
    return (0);
}

int mysh(char **env)
{
    char *buff = malloc(sizeof(char) * 50);
    size_t nb = 225;
    int n = 0;

    while (1) {
        my_printf("$> ");
        if (getline(&buff, &nb, stdin) == -1) {
            my_printf("\nexit\n");
            return (0);
        }
        if (my_strcmp(buff, "env") == 0) {
            for (int i = 0; env[i]; i++)
                my_printf("%s\n", env[i]);
            continue;
        }
        if (mysh_condi(buff, &env) != 0)
            continue;
        n = count_separator(buff);
        if (n != 0)
            for (; n != 0; n--)
                exec(env, buff);
        else
            exec(env, buff);
    }
}

char *getpath(char **env, char *elem)
{
    char *path = malloc(sizeof(char) * READ_SIZE);

    for (int i = 0; env[i]; i++) {
        if (my_strcmp(env[i], elem) == 0) {
            for (int n = 0; env[i][n + 5]; n++)
                path[n] = env[i][n + 5];
        }
    }
    return (path);
}

int main(int ac, char **av, char **env)
{
    if (!env[0])
        return (84);
    if (ac != 1)
        return (84);
    av = av;
    return (mysh(env));
}
