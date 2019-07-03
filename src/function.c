/*
** EPITECH PROJECT, 2019
** ftu
** File description:
** fyu
*/

#include "my.h"
#include "my_print.h"

int my_strcmp(char *str, char *elem)
{
    for (int i = 0; elem[i]; i++) {
        if (elem[i] != str[i])
            return (84);
    }
    return (0);
}

int count(char *str, char c, char t)
{
    int i = 0;

    for (int n = 0; str[n]; n++)
        if (str[n] == c || str[n] == '\n' || str[n] == t)
            i += 1;
    return (i);
}

char *parse_path(char *str, char c, int b)
{
    int i = 0;
    char *p = malloc(sizeof(char) * READ_SIZE);
    int m = 0;

    if (b > 0)
        for (; b > 0; b--) {
            for (; str[m] != c && str[m] != '\0'; m++);
            if (str[m] == '\0') {
               break;
            }
            m += 1;
        }
    for (; str[m] != c && str[m] != '\0'; m++) {
        p[i] = str[m];
        i++;
    }
    p[i] = '/';
    return (p);
}

char **parse_buff(char *str, char c, char t)
{
    int i = count(str, c, t);
    int u = 0;
    int m = 0;
    char **b = malloc(sizeof(char*) * (i + 1));
    static int n = 0;

    for (; str[n] == c || str[n] == t; n++);
    b[u] = malloc(sizeof(char) * READ_SIZE);
    for (; str[n] != '\n' && str[n] != ';'; n++) {
        if (str[n] == c || str[n] == t) {
            for (; str[n] == c || str[n] == t; n++);
            n--;
            u += 1;
            b[u] = malloc(sizeof(char) * READ_SIZE);
            m = 0;
            continue;
        }
        b[u][m] = str[n];
        m += 1;
    }
    if (str[n] == '\n')
        n = 0;
    if (str[n] == ';')
        n++;
    return (b);
}

int exec(char **env, char *buff)
{
    static int b = 0;
    char *path = parse_path(getpath(env, "PATH"), ':', b);
    char **argv_sh = parse_buff(buff, ' ', '\t');
    char *tmp = my_strcat(path, argv_sh[0]);
    pid_t pid = fork();
    int a;

    if (buff[0] == '.' && buff[1] == '/') {
        argv_sh = exec_bis(buff);
        tmp = path;
        if (pid != 0)
            kill(pid, SIGKILL);
    }
    if (access(tmp, F_OK) == -1) {
        if (b != 6) {
            if (pid != 0)
                kill(pid, SIGKILL);
            b += 1;
            return (exec(env, buff));
        }else {
            for (;b >= 0; b--)
                if (pid != 0)
                    kill(pid, SIGKILL);
            my_printf("%s: Command not found.\n", argv_sh[0]);
            b = 0;
            return (84);
        }
    }
    if (pid == 0)
        execve(tmp, argv_sh, NULL);
    waitpid(pid, &a, WUNTRACED);
    for (;b >= 0; b--)
        if (pid != 0)
            kill(pid, SIGKILL);
    b = 0;
    return (0);
}
