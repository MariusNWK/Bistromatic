/*
** EPITECH PROJECT, 2020
** division3
** File description:
** bistro inf div
*/
#include "my.h"
#include <stdlib.h>

char *minus_adder(char *result)
{
    int i = 0;
    char *str = malloc(sizeof(char) * (my_strlen(result) + 1));

    str[0] = '-';
    for (; result[i] != '\0'; i++)
        str[i + 1] = result[i];
    str[i + 1] = '\0';
    return (str);
}

char *value_str_s1(char *s1, char *s2)
{
    int size_s1 = my_strlen(s1);
    int size_s2 = my_strlen(s2);
    char *str_s1;

    while (size_s1 - size_s2 > 5)
        size_s1--;
    str_s1 = malloc(sizeof(char) * size_s1);
    for (int i = 0; size_s1 > 0; size_s1--, i++)
        str_s1[i] = s1[i];
    return (str_s1);
}
