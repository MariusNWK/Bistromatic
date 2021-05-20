/*
** EPITECH PROJECT, 2020
** division4
** File description:
** infinie
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char *result_with_new_zeros(char *s1, char *result)
{
    int nbr_zeros = 0;

    if (s1[0] == '0') {
        for (; s1[0] == '0' && my_strlen(s1) > 1; nbr_zeros++)
            s1++;
        for (; nbr_zeros > 0; nbr_zeros--) {
            result = multiplication("10", result);
        }
    }
    return (result);
}

char *s1_without_the_useless_zeros(char *s1)
{
    for (; s1[0] == '0' && my_strlen(s1) > 1; s1++);
    return (s1);
}
