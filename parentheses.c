/*
** EPITECH PROJECT, 2020
** parentheses
** File description:
** evalexpr
*/
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *result_between_parentheses1(char *b_p)
{
    int i = 0;

    for (; b_p[i] != '\0'; i++) {
        if (b_p[i] == '/') {
            b_p = s1_s2_divisor(b_p, '/');
            i = 0;
        }
        if (b_p[i] == '*') {
            b_p = s1_s2_multiplier(b_p, '*');
            i = 0;
        }
        if (b_p[i] == '%') {
            b_p = s1_s2_modulo(b_p, '%');
            i = 0;
        }
    }
    return (b_p);
}

char *result_between_parentheses2(char *b_p)
{
    int i = 0;

    for (i = 0; b_p[i] != '\0'; i++) {
        if (b_p[i] == '+' && b_p[i + 1] == '-') {
            b_p = plus_moins_to_moins(b_p, i);
            i = 0;
        }
        if (b_p[i] == '-' && b_p[i + 1] == '-') {
            b_p = moins_moins_to_plus(b_p, i);
            i = 0;
        }
        if ((b_p[i] == '+' && i == 0) ||
            (b_p[i] == '+' && (b_p[i - 1] < '0' ||
            b_p[i - 1] > '9') && b_p[i - 1] != ')')) {
            b_p = plus_to_nothing(b_p, i);
            i = 0;
        }
    }
    return (b_p);
}

char *result_between_parentheses3(char *b_p)
{
    int i = 0;

    if (b_p[0] == '+') {
        my_putstr(b_p);
        my_putchar('\n');
        b_p++;
    }
    for (i = 0; b_p[i] != '\0'; i++) {
        if (b_p[i] == '+') {
            b_p = s1_s2_addition(b_p, '+');
            i = 0;
        }
        if (b_p[i] == '-') {
            b_p = s1_s2_soustraction(b_p, '-');
            i = 0;
        }
    }
    return (b_p);
}

char *result_between_parentheses(char *b_p)
{
    int i = 0;

    b_p = result_between_parentheses1(b_p);
    b_p = result_between_parentheses2(b_p);
    b_p = result_between_parentheses3(b_p);
    return (b_p);
}

char *parentheses_searcher(char *str)
{
    int i = 0;
    int j = 0;
    int jbis = 0;
    char *between_parentheses;
    char *new_str;

    str = seg_fault_resolver(str);
    for (; str[i] != ')'; i++);
    j = i;
    for (; str[j] != '('; j--);
    between_parentheses = malloc(sizeof(char) * (i - j - 1));
    i = i - 1;
    j = j + 1;
    jbis = j;
    for (int k = 0; jbis <= i; jbis++, k++)
        between_parentheses[k] = str[jbis];
    between_parentheses = result_between_parentheses(between_parentheses);
    new_str = string_new_str(i, j, str, between_parentheses);
    return (new_str);
}
