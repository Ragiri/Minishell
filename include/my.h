/*
** EPITECH PROJECT, 2019
** vre
** File description:
** ve
*/

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <dirent.h>

#define READ_SIZE (4096)
#ifndef MY_H_
#define MY_H_

int my_setenv(char***, char*);
char **parse_buff(char*, char, char);
int my_strcmp(char*, char*);
char *getpath(char**, char*);
int exec(char**, char*);
char *my_strcat(char *, char *);
char **create_tmp(char**, int*);
int my_unsetenv(char***, char*);
int my_cd(char*, char***);
int count_line(char**);
char **create_tmp(char **, int *);
int count_leng_line(char*);
char **exec_bis(char*);
char *parse_path(char *str, char c, int b);

#endif
