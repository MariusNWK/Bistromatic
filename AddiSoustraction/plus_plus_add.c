/*
** EPITECH PROJECT, 2020
** plus_plus
** File description:
** plus_plus
*/
#include <stdio.h>
#include <my.h>
#include <stdlib.h>

char *plus_plus_addsoustr2(char *s1, char *s2, char *result)
{
    char *new_result;
    int i = 0;

    if (my_strlen(s1) != my_strlen(s2) && result[0] == '0') {
        new_result = malloc(sizeof(char) * (my_strlen(result) + 1));
        new_result[0] = '1';
        for (i = 0; result[i] != '\0'; i++)
            new_result[i + 1] = result[i];
        new_result[i + 1] = '\0';
        return (new_result);
    }
    return (result);
}

char *plus_plus_addsoustr(char *s1, char *s2)
{
    char *result;
    int size_result = 0;
    char *new_result;

    if (my_strlen(s1) >= my_strlen(s2)) {
        result = malloc(sizeof(char) * my_strlen(s1) + 1);
        size_result = my_strlen(s1) + 1;
    }
    else {
        result = malloc(sizeof(char) * my_strlen(s2) + 1);
        size_result = my_strlen(s2) + 1;
    }
    size_result = plus_plus4(size_result, s1, s2, result);
    result = plus_plus3(size_result, s1, s2, result);
    result = plus_plus2(size_result, result, s1, s2);
    new_result = plus_plus_addsoustr2(s1, s2, result);
    return (new_result);
}
