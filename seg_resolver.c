/*
** EPITECH PROJECT, 2020
** seg resolver
** File description:
** eval expr
*/
#include "my.h"

char *seg_fault_resolver(char *str)
{
    int pA = 0;
    int pB = 0;

    for (int a = 0; a < my_strlen(str); a++) {
        if (str[a] == '(')
            pA++;
        if (str[a] == ')')
            pB++;
    }
    if (str[my_strlen(str) - 1] == '!' && pA == pB)
        str[my_strlen(str) - 1] = '\0';
    if (str[my_strlen(str) - 1] == '!' && pA != pB)
        str[my_strlen(str) - 1] = ')';
    return (str);
}
