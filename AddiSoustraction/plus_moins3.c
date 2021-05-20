/*
** EPITECH PROJECT, 2020
** plus_moins3
** File description:
** projet solo 1
*/
#include <stdio.h>
#include <my.h>
#include <stdlib.h>

int value_s1plusgrand(int size_s1, int size_s2, char *s1, char *s2)
{
    int s1plusgrand = 0;

    if (size_s1 == size_s2) {
        for (int i = 0; s1plusgrand == 0 && s1[i] != '\0'; i++) {
            if (s1[i] > s2[i])
                s1plusgrand = 1;
            if (s1[i] < s2[i])
                s1plusgrand = 2;
        }
    }
    return (s1plusgrand);
}

char *s_equal_zero(char *s, int size_s)
{
    if (size_s < 1)
        s[size_s - 1] = '0';
    return (s);
}
