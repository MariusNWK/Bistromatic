/*
** EPITECH PROJECT, 2020
** Division
** File description:
** infinie
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char *value_new_s1(char *s1, char *modulo_div)
{
    int j = 0;
    char *new_s1;

    new_s1 = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(modulo_div)));
    for (int i = 0; i < my_strlen(modulo_div); i++)
        new_s1[i] = modulo_div[i];
    for (j = 0; s1[j] != '\0'; j++)
        new_s1[j + my_strlen(modulo_div)] = s1[j];
    new_s1[j + my_strlen(modulo_div)] = '\0';
    return (new_s1);
}

char *result_last_div(char *s1, char *s2, char *result, int size_result)
{
    char *result_div;
    int j = 0;
    int nbr_zeros = 0;

    if (s1[0] == '0') {
        for (; s1[0] == '0' && my_strlen(s1) > 1; nbr_zeros++)
            s1++;
        for (; nbr_zeros > 1; nbr_zeros--) {
            result = multiplication("10", result);
        }
    }
    result_div = division_simple(s1, s2);
    size_result = my_strlen(result);
    for (j = 0; result_div[j] != '\0'; j++)
        result[j + size_result] = result_div[j];
    result[j + size_result] = '\0';
    return (result);
}

char *division_complexe(char *s1, char *s2, char *result)
{
    int size_str_s1 = 0;
    int size_result = my_strlen(result);
    char *result_div;
    char *modulo_div;
    char *new_s1;

    if (number_comparator(s1, s2) == 2 ||
        my_strlen(s1) - my_strlen(s2) <= 5)
        return ((number_comparator(s1, s2) == 2) ? result :
        result_last_div(s1, s2, result, size_result));
    result = result_with_new_zeros(s1, result);
    s1 = s1_without_the_useless_zeros(s1);
    modulo_div = value_str_s1(s1, s2);
    size_str_s1 = my_strlen(modulo_div);
    result_div = division_simple(modulo_div, s2);
    for (int i = 0; result_div[i] != '\0'; i++)
        result[i + size_result] = result_div[i];
    modulo_div = zeros_cleaner(modulo_div);
    for (; size_str_s1 > 0; s1++, size_str_s1--);
    new_s1 = value_new_s1(s1, modulo_div);
    division_complexe(new_s1, s2, result);
}

char *simple_division(char *s1, char *s2, char *result, int moins)
{
    char *s1copy = malloc(sizeof(char) * my_strlen(s1));
    int i = 0;

    for (i = 0; s1[i] != '\0'; i++)
        s1copy[i] = s1[i];
    s1copy[i] = '\0';
    result = division_simple(s1copy, s2);
    result = zeros_cleaner(result);
    if (moins % 2 == 1) {
        result = minus_adder(result);
        return (result);
    }
    else
        return (result);
}

void *division(char *s1, char *s2)
{
    char *result;
    char *str;
    char *result_compl = malloc(sizeof(char) * my_strlen(s1));
    int moins = minus_number(s1, s2);

    s1 = number_cleaner(s1);
    s2 = number_cleaner(s2);
    if (s2[0] == '0') return (NULL);
    result = malloc_result(s1, s2);
    if (my_strlen(s1) - my_strlen(s2) <= 5) {
        return (simple_division(s1, s2, result, moins));
    }
    else {
        result = division_complexe(s1, s2, result_compl);
        if (moins % 2 == 1) {
            result = minus_adder(result);
            return (result);
        }
        else
            return (result);
    }
}
