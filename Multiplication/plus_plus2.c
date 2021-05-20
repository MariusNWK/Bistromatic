/*
** EPITECH PROJECT, 2020
** plus plus 2
** File description:
** eval expr
*/
#include <stdlib.h>
#include "my.h"

char *plus_plus_suite(char *result)
{
    char *str;
    int i = 0;

    str = malloc (sizeof(char) * my_strlen(result) + 1);
    str[0] = '1';
    for (i = 0; result[i] != '\0'; i++)
        str[i + 1] = result[i];
    str[i + 1] = '\0';
    return (str);
}
