/*
** EPITECH PROJECT, 2020
** plus_moins2
** File description:
** projet solo 1
*/
#include <stdio.h>
#include <my.h>
#include <stdlib.h>

char *value_s2(char *moins_s2)
{
    int i = 0;
    char *s2 = malloc(sizeof(char) * my_strlen(moins_s2) - 1);

    for (i = 0; i < my_strlen(moins_s2) - 1; i++)
        s2[i] = moins_s2[i + 1];
    s2[i] = '\0';
    return (s2);
}

char *value_result(char *s1, char *s2)
{
    char *result;

    if (my_strlen(s1) >= my_strlen(s2))
        result = malloc(sizeof(char) * my_strlen(s1));
    else
        result = malloc(sizeof(char) * my_strlen(s2));
    return (result);
}

int value_full_of_zero(char *s1, char *s2)
{
    int full_of_zero = 0;

    if (my_strlen(s1) >= my_strlen(s2))
        full_of_zero = my_strlen(s1);
    else
        full_of_zero = my_strlen(s2);
    return (full_of_zero);
}

int value_size_result(char *s1, char *s2)
{
    int size_result = 0;

    if (my_strlen(s1) >= my_strlen(s2))
        size_result = my_strlen(s1);
    else
        size_result = my_strlen(s2);
    return (size_result);
}

char *result_zeros_only(int full_of_zero, char *result)
{
    while (full_of_zero > 0) {
        result[full_of_zero - 1] = '0';
        full_of_zero--;
    }
    return (result);
}
