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

int sup_equal_inf(char *s1, char *s2)
{
    int d = 0;
    int size_s1 = my_strlen(s1);
    int size_s2 = my_strlen(s2);

    if (size_s1 > size_s2)
        d = 1;
    else if (size_s1 < size_s2)
        d = 2;
    else {
        for (int i = 0; s1[i] != '\0' && s2[i] != '\0' && d == 0; i++) {
            if (s1[i] > s2[i])
                d = 1;
            if (s1[i] < s2[i])
                d = 2;
        }
    }
    return (d);
}

char *val_av(char *s)
{
    int size_s = my_strlen(s);

    if (s[0] == '0' && size_s > 1)
        for (; s[0] == '0' && size_s > 1; size_s--)
            s++;
    return (s);
}

void *division_simple(char *s1, char *s2)
{
    int d = 0;

    if (s2[0]  == '0')
        return (NULL);
    d = sup_equal_inf(s1, s2);
    if (d == 1)
        return (s1_sup_s2(s1, s2, d));
    else if (d == 0)
        return ("1");
    else
        return ("0");
}
