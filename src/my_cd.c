/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** cd
*/

#include "my.h"
#include "my_print.h"

char **my_cd_param(char **tmp, char *str, char *p, int i)
{
    int m = 0;

    for (int n = 0; tmp[n]; n++) {
        if (my_strcmp(tmp[n], p) == 0) {
            for (; str[m]; m++)
                tmp[n][m + i] = str[m];
            tmp[n][m + i] = '\0';
        }
    }
    return (tmp);
}

int cd_home(char **tmp, char ***env)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 4096);
    size_t m = 4096;
    char *old = NULL;

    old = getcwd(old, m);
    for (int n = 0; tmp[n]; n++) {
        if (my_strcmp(tmp[n], "HOME") == 0) {
            for (; tmp[n][i + 5]; i++)
                str[i] = tmp[n][i + 5];
            str[i] = '\0';
        }
    }
    chdir(str);
    tmp = my_cd_param(tmp, str, "PWD", 4);
    tmp = my_cd_param(tmp, old, "OLDPWD", 7);
    *env = tmp;
    return (0);
}

int cd_bis(char **tmp, char ***env)
{
    int i = 0;
    size_t m = 4096;
    char *str = malloc(sizeof(char) * 4096);
    char *old = NULL;
    
    old = getcwd(old, m);
    for (int n = 0; tmp[n]; n++) {
        if (my_strcmp(tmp[n], "OLDPWD") == 0) {
            for (; tmp[n][i + 7]; i++)
                str[i] = tmp[n][i + 7];
            str[i] = '\0';
        }
    }
    chdir(str);
    tmp = my_cd_param(tmp, str, "PWD", 4);
    tmp = my_cd_param(tmp, old, "OLDPWD", 7);
    *env = tmp;
    return (0);
}

int my_cd_bis(char **tmp, char ***env, char **param)
{
    size_t i = 4096;
    char *str = NULL;
    char *old = NULL;

    old = getcwd(old, i);
    chdir(param[1]);
    str = getcwd(str, i);
    tmp = my_cd_param(tmp, str, "PWD", 4);
    tmp = my_cd_param(tmp, old, "OLDPWD", 7);
    *env = tmp;
    return (0);
}

int my_cd(char *buff, char ***env)
{
    char **param = parse_buff(buff, ' ', '\t');
    int y = 0;
    char **tmp = create_tmp(*env, &y);
    DIR *dir;

    if (param[1] == NULL || (param[1][0] == '-' && param[1][1] == '-'
    && param[1][2] == '\0'))
        return (cd_home(tmp, env));
    if (param[1][0] == '-' && param[1][1] == '\0')
        return (cd_bis(tmp, env));
    if ((dir = opendir(param[1])) == NULL) {
        my_printf("%s: No such file or directory.\n", param[1]);
        return (84);
    }
    my_cd_bis(tmp, env, param);
    return (0);
}