/*
** EPITECH PROJECT, 2020
** division3
** File description:
** eval expr
*/
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int val_val_s2(int size_s2, char *s2)
{
    int val_s2 = 0;

    if (size_s2 > 0)
        val_s2 = s2[size_s2 - 1];
    else
        val_s2 = '0';
    return (val_s2);
}

char *val_s1_autre(int size_s1, int size_s2, char *s1, char *s2)
{
    int val_s2 = 0;
    int carry = 0;
    int add_s1_s2 = 0;

    for (; size_s1 > 0; size_s1--, size_s2--) {
        val_s2 = val_val_s2(size_s2, s2);
        add_s1_s2 = (s1[size_s1 - 1] - 48) - (val_s2 - 48 + carry);
        if (add_s1_s2 >= 0) {
            s1[size_s1 - 1] = add_s1_s2 + 48;
            carry = 0;
        }
        else {
            if (size_s1 > 1) {
                s1[size_s1 - 1] = add_s1_s2 + 48 + 10;
                carry = 1;
            }
            else
                s1[size_s1 - 1] = add_s1_s2 + 48;
        }
    }
    return (s1);
}

char *s1_moins_s2(char *s1, char *s2)
{
    int size_s1 = my_strlen(s1);
    int size_s2 = my_strlen(s2);
    int carry = 0;
    int add_s1_s2 = 0;
    int val_s2 = 0;

    s1 = val_s1_autre(size_s1, size_s2, s1, s2);
    s1 = val_av(s1);
    return (s1);
}
