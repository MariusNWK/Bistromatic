/*
** EPITECH PROJECT, 2020
** s1_s2 multiplier
** File description:
** numero 2
*/
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *val_s1(char *b_p, char c)
{
    int i = 0;
    int i1 = 0;
    int i1_result = 0;
    char *s1;

    for (; b_p[i] != c && b_p[i] != '\0'; i++);
    if (b_p[0] == '-' && c == '-')
        for (; (b_p[i] != c || i == 0) && b_p[i] != '\0'; i++);
    if (b_p[i] == c) {
        i1 = i - 1;
        for (; (b_p[i1] >= '0' && b_p[i1] <= '9') ||
            ((b_p[i1 - 1] == '*' || b_p[i1 - 1] == '+' ||
            b_p[i1 - 1] == '/' || b_p[i1 - 1] == '%'||
            b_p[i1 - 1] == '-' || i1 == 0) && b_p[i1] == '-'); i1--);
        i1 = i1 + 1;
        i1_result = i1;
        s1 = malloc(sizeof(char) * (i - i1));
        for (int k = 0; i1 < i; i1++, k++)
            s1[k] = b_p[i1];
    }
    return (s1);
}

char *val_s2(char *b_p, char c)
{
    int i = 0;
    int i2 = 0;
    int i2_result = 0;
    char *s2;

    for (; b_p[i] != c && b_p[i] != '\0'; i++);
    if (b_p[0] == '-' && c == '-')
        for (; (b_p[i] != c || i == 0) && b_p[i] != '\0'; i++);
    if (b_p[i] == c) {
        i2 = i + 1;
        for (; (b_p[i2] >= '0' && b_p[i2] <= '9') ||
            ((b_p[i2 - 1] == '*' || b_p[i2 - 1] == '+' ||
            b_p[i2 - 1] == '/' || b_p[i2 - 1] == '%'||
            b_p[i2 - 1] == '-') && b_p[i2] == '-'); i2++);
        i2 = i2 - 1;
        i2_result = i2;
        s2 = malloc(sizeof(char) * (i2 - i));
        for (; i2 > i; i2--)
            s2[i2 - i - 1] = b_p[i2];
    }
    return (s2);
}

int val_i1_for_size_result(char *b_p, char c)
{
    int i = 0;
    int i1 = 0;
    int i1_result = 0;
    char *s1;

    for (; b_p[i] != c && b_p[i] != '\0'; i++);
    if (b_p[0] == '-' && c == '-')
        for (; (b_p[i] != c || i == 0) && b_p[i] != '\0'; i++);
    if (b_p[i] == c) {
        i1 = i - 1;
        for (; (b_p[i1] >= '0' && b_p[i1] <= '9') ||
            ((b_p[i1 - 1] == '*' || b_p[i1 - 1] == '+' ||
            b_p[i1 - 1] == '/' || b_p[i1 - 1] == '%'||
            b_p[i1 - 1] == '-' || i1 == 0) && b_p[i1] == '-'); i1--);
        i1 = i1 + 1;
        i1_result = i1;
        s1 = malloc(sizeof(char) * (i - i1));
        for (int k = 0; i1 < i; i1++, k++)
            s1[k] = b_p[i1];
    }
    return (i1_result);
}

int val_i2_for_size_result(char *b_p, char c)
{
    int i = 0;
    int i2 = 0;
    int i2_result = 0;
    char *s2;

    for (; b_p[i] != c && b_p[i] != '\0'; i++);
    if (b_p[0] == '-' && c == '-')
        for (; (b_p[i] != c || i == 0) && b_p[i] != '\0'; i++);
    if (b_p[i] == c) {
        i2 = i + 1;
        for (; (b_p[i2] >= '0' && b_p[i2] <= '9') ||
            ((b_p[i2 - 1] == '*' || b_p[i2 - 1] == '+' ||
            b_p[i2 - 1] == '/' || b_p[i2 - 1] == '%'||
            b_p[i2 - 1] == '-') && b_p[i2] == '-'); i2++);
        i2 = i2 - 1;
        i2_result = i2;
        s2 = malloc(sizeof(char) * (i2 - i));
        for (; i2 > i; i2--)
            s2[i2 - i - 1] = b_p[i2];
    }
    return (i2_result);
}
