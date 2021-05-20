/*
** EPITECH PROJECT, 2020
** InfinAdd
** File description:
** Projet solo 1
*/
#include <stdio.h>
#include <my.h>
#include <stdlib.h>

char *moins_moins(char *s1, char *s2)
{
    char *s1copy = malloc(sizeof(char) * my_strlen(s1) - 1);
    char *s2copy = malloc(sizeof(char) * my_strlen(s2) - 1);
    int i = 0;
    char *result;
    char *new_result;

    for (i = 0; i < my_strlen(s1) - 1; i++)
        s1copy[i] = s1[i + 1];
    s1copy[i] = '\0';
    for (i = 0; i < my_strlen(s2) - 1; i++)
        s2copy[i] = s2[i + 1];
    s2copy[i] = '\0';
    result = plus_plus_addsoustr(s1copy, s2copy);
    if (s1copy[0] == '0' && s2copy[0] == '0');
    else { new_result = malloc(sizeof(char) * (my_strlen(result) + 1));
        new_result[0] = '-';
        for (int i = 0; result[i] != '\0'; i++)
            new_result[i + 1] = result[i];
        return (new_result);
    }
    return (result);
}

char *addisoustraction(char *s1, char *s2)
{
    int condition = 0;
    char *result;

    s1 = val_av(s1);
    s2 = val_av(s2);
    if (s1[0] == '-' && s2[0] == '-') {
        result = moins_moins(s1, s2);
        condition = 1;
    }
    if (s2[0] == '-' && condition == 0) {
        result = plus_moins(s1, s2);
        condition = 1;
    }
    if (s1[0] == '-' && condition == 0) {
        result = plus_moins(s2, s1);
        condition = 1;
    }
    if (condition == 0)
        result = plus_plus_addsoustr(s1, s2);
    return (result);
}
