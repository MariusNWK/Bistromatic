/*
** EPITECH PROJECT, 2020
** error handling 2
** File description:
** bistro
*/
#include <stddef.h>

char *error_no_operator(char *expr)
{
    for (int i = 0; expr[i] != '\0'; i++)
        if ((expr[i] >= '0' && expr[i] <= '9') &&
            (expr[i - 1] == ')' || expr[i + 1] == '('))
            return (NULL);
    return ("tout va bien");
}
