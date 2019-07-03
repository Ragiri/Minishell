/*
** EPITECH PROJECT, 2018
** fonctions
** File description:
** bistro matic
*/
#include <stdarg.h>

#ifndef MY_PRINT_
#define MY_PRINT_

int my_putstr(char const*);
char *binary_base(int);
void my_put_nbr(int);
void condi(char const*, int, va_list);
void my_put_nbr_octal(int);
void my_putchar(char);
void my_put_nbr_hexa(int);
void my_put_nbr_hexa_second(int);
void my_putchar1(char);
void my_put_nbr_unsigned(unsigned int);
int my_printf(char const*, ...);
void flag_s(char *);

#endif
