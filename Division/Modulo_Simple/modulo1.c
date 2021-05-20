/*
** EPITECH PROJECT, 2020
** main Modulo
** File description:
** main
*/
#include "my.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *s1_sup_s2_mod(char *s1, char *s2, int d)
{
    char *str;
    int i = 0;

    while (d == 1) {
        s1 = s1_moins_s2(s1, s2);
        d = sup_equal_inf(s1, s2);
        if (d == 0)
            d = 1;
    }
    return (s1);
}

char *s1_equal_s2_mod(char *s1, char *s2)
{
    return ("0");
}

void *modulo_simple(char *s1, char *s2)
{
    int d = 0;

    if (s2[0] == '0')
        return (NULL);
    d = sup_equal_inf(s1, s2);
    if (d == 1)
        s1 = s1_sup_s2_mod(s1, s2, d);
    else if (d == 0)
        s1 = s1_equal_s2_mod(s1, s2);
    return (s1);
}
