/*
** EPITECH PROJECT, 2020
** s1_s2 multiplier
** File description:
** numero 1
*/
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *val_new_b_p_mult(int i1_result, int i2_result, char *b_p, char *result)
{
    int i = 0;
    char *new_b_p;

    for (; b_p[i] != '*' && b_p[i] != '\0'; i++);
    if (b_p[i] == '*') {
        new_b_p = malloc(sizeof(char) * (my_strlen(b_p) -
        (i2_result - i1_result + 1) + my_strlen(result)));
        for (i = 0; i < i1_result; i++)
            new_b_p[i] = b_p[i];
        for (int j = 0; result[j] != '\0'; j++, i++)
            new_b_p[i] = result[j];
        for (; b_p[i2_result + 1]
            != '\0'; i++, i2_result++)
            new_b_p[i] = b_p[i2_result + 1];
        new_b_p[i] = '\0';
    }
    return (new_b_p);
}

char *s1_s2_multiplier(char *b_p, char c)
{
    int i = 0;
    char *s1;
    char *s2;
    char *result;
    int i2_result = 0;
    int i1_result = 0;
    char *new_b_p;

    for (; b_p[i] != c && b_p[i] != '\0'; i++);
    if (b_p[i] == c) {
        s1 = val_s1(b_p, c);
        s2 = val_s2(b_p, c);
        result = multiplication(s1, s2);
        i1_result = val_i1_for_size_result(b_p, c);
        i2_result = val_i2_for_size_result(b_p, c);
        new_b_p = val_new_b_p_mult(i1_result, i2_result, b_p, result);
        return (new_b_p);
    }
    return (b_p);
}
