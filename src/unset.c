/*
** EPITECH PROJECT, 2019
** ffyul
** File description:
** illuf
*/

#include "my.h"
#include "my_print.h"

char **recpy(char **tmp_env, char *str)
{
    int m = 0;
    char **tmp = malloc(sizeof(char*) * count_line(tmp_env) + 1);

    for (int i = 0; tmp_env[i]; i++) {
        if (my_strcmp(tmp_env[i], str) == 0)
            continue;
        tmp[m] = malloc(sizeof(char) * (count_leng_line(tmp_env[i]) + 1));
        for (int n = 0; tmp_env[i][n]; n++)
            tmp[m][n] = tmp_env[i][n];
        m += 1;
    }
    tmp[m] = NULL;
    return (tmp);
}

int my_unsetenv(char ***env, char *buff)
{
    int i = 0;
    char *str = NULL;
    char **param = parse_buff(buff, ' ', '\t');
    char **tmp_env = create_tmp(*env, &i);

    if (param[1] == NULL) {
        my_printf("unsetenv: Too few arguments.\n");
        return (0);
    }
    for (int m = 1; param[m]; m++) {
        for (int n = 0; tmp_env[n]; n++) {
            if (my_strcmp(tmp_env[n], param[m]) == 0) {
                str = tmp_env[n];
                tmp_env = recpy(tmp_env, str);
                break;
            }
        }
    }
    *env = tmp_env;
    return (0);
}
