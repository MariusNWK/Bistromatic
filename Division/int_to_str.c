/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char *int_to_str_converter(int b)
{
    int fois_dix = 1;
    int b_bis = b;
    char *boucles;
    int size_boucles = 0;
    int i = 0;

    while (b_bis > 0) {
        b_bis = b_bis / 10;
        fois_dix = fois_dix * 10;
        size_boucles++;
    }
    boucles = malloc(sizeof(char) * size_boucles);
    fois_dix = fois_dix / 10;
    while (fois_dix > 0) {
        boucles[i] = (b / fois_dix) + 48;
        b = b % fois_dix;
        i++;
        fois_dix = fois_dix / 10;
    }
    return (boucles);
}
