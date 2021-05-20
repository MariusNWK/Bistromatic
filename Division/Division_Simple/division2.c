/*
** EPITECH PROJECT, 2020
** Modulo
** File description:
** modulo
*/
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int boucle_division(int d, int b, char *s1, char *s2)
{
    while (d == 1) {
        b = b + 1;
        s1 = s1_moins_s2(s1, s2);
        d = sup_equal_inf(s1, s2);
        if (d == 0)
            d = 1;
    }
    return (b);
}

char *s1_sup_s2(char *s1, char *s2, int d)
{
    char *boucles = malloc(sizeof(char) * my_strlen(s1) + 1);
    int b = 0;
    int i = 0;
    int vals1 = 0;
    int vals2 = 0;
    int size_s1 = my_strlen(s1);

    b = boucle_division(d, b, s1, s2);
    boucles = int_to_str_converter(b);
    return (boucles);
}
