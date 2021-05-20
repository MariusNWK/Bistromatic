/*
** EPITECH PROJECT, 2020
** division2
** File description:
** bistro div infinie
*/
#include "my.h"
#include <stdlib.h>

int minus_number(char *s1, char *s2)
{
    int moins = 0;

    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == '-')
            moins++;
    }
    for (int i = 0; s2[i] != '\0'; i++)
        if (s2[i] == '-')
            moins++;
    return (moins);
}

char *malloc_result(char *s1, char *s2)
{
    char *result;

    if (my_strlen(s2) >= my_strlen(s1)) {
        result = malloc(sizeof(char) * my_strlen(s2));
        for (int i = 0; i < my_strlen(s2); i++)
            result[i] = '0';
    }
    if (my_strlen(s1) > my_strlen(s2)) {
        result = malloc(sizeof(char) * my_strlen(s1));
        for (int i = 0; i < my_strlen(s1); i++)
            result[i] = '0';
    }
    return (result);
}

int number_comparator(char *s1, char *s2)
{
    if (my_strlen(s1) > my_strlen(s2))
        return (0);
    else if (my_strlen(s1) < my_strlen(s2))
        return (1);
    else
        for (int i = 0; s1[i] != '\0'; i++) {
            if (s1[i] > s2[i])
                return (1);
            if (s1[i] < s2[i])
                return (2);
        }
    return (0);
}

char *zeros_cleaner(char *result)
{
    while (result[0] == '0' && my_strlen(result) > 1)
        result++;
    return (result);
}
