/*
** EPITECH PROJECT, 2020
** parentheses 2
** File description:
** eval expr
*/
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *plus_to_nothing(char *b_p, int i)
{
    char *new_b_p = malloc(sizeof(char) * (my_strlen(b_p) - 1));
    int j = 0;

    for (; j < i; j++)
        new_b_p[j] = b_p[j];
    for (; b_p[i + 1] != '\0'; i++, j++)
        new_b_p[j] = b_p[j + 1];
    new_b_p[j] = '\0';
    return (new_b_p);
}

char *moins_moins_to_plus(char *b_p, int i)
{
    char *new_b_p = malloc(sizeof(char) * (my_strlen(b_p) - 1));
    char *b_p_without_minus = malloc(sizeof(char) * (my_strlen(b_p) - 2));
    int j = 0;

    if (i == 0 || b_p[i - 1] == '(') {
        for (j = 0; j < i; j++)
            b_p_without_minus[j] = b_p[j];
        for (; b_p[i + 2] != '\0'; i++, j++)
            b_p_without_minus[j] = b_p[i + 2];
        b_p_without_minus[j] = '\0';
        return (b_p_without_minus);
    }
    else { for (j = 0; j < i; j++)
            new_b_p[j] = b_p[j];
        new_b_p[j] = '+';
        j = j + 1;
        for (; b_p[i + 2] != '\0'; i++, j++)
            new_b_p[j] = b_p[i + 2];
        new_b_p[j] = '\0';
        return (new_b_p);
    }
}

char *plus_moins_to_moins(char *b_p, int i)
{
    char *new_b_p = malloc(sizeof(char) * (my_strlen(b_p) - 1));

    b_p[i] = b_p[i + 1];
    i = i + 1;
    for (int j = 0; j < i; j++)
        new_b_p[j] = b_p[j];
    for (; b_p[i + 1] != '\0'; i++)
        new_b_p[i] = b_p[i + 1];
    return (new_b_p);
}

char *string_new_str(int i, int j, char *str, char *between_parentheses)
{
    int m = 0;
    int p = 0;
    char *new_str;

    i = i + 1;
    j = j - 1;
    new_str = malloc(sizeof(char) * (my_strlen(str) - (i - j + 1)));
    for (m = 0; m < j; m++)
        new_str[m] = str[m];
    for (int n = 0; n <= my_strlen(between_parentheses) - 1; m++, n++)
        new_str[m] = between_parentheses[n];
    for (; str[i + 1] != '\0'; i++, m++)
        new_str[m] = str[i + 1];
    new_str[m] = '\0';
    for (p = 0; new_str[p] != ')' && new_str[p] != '\0'; p++);
    if (new_str[p] == ')')
        return (parentheses_searcher(new_str));
    return (new_str);
}
