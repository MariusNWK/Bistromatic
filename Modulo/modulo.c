/*
** EPITECH PROJECT, 2020
** modulo
** File description:
** infini
*/
#include <stdlib.h>
#include <stddef.h>
#include "my.h"

int how_many_minus(char *nbr)
{
    int moins = 0;

    for (int i = 0; nbr[i] != '\0'; i++)
        if (nbr[i] == '-')
            moins++;
    return (moins);
}

char *modulo_complexe(char *s1, char *s2, char *result, char *modulo_div)
{
    int size_str_s1 = 0;
    int size_result = my_strlen(result);
    char *result_div;
    char *new_s1;

    if (number_comparator(s1, s2) == 2)
        return (modulo_div);
    else if (my_strlen(s1) - my_strlen(s2) <= 5)
        return (modulo_simple(s1, s2));
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
    modulo_complexe(new_s1, s2, result, modulo_div);
}

void *modulo(char *s1, char *s2)
{
    int nbr_moins_s1 = how_many_minus(s1) % 2;
    int nbr_moins_s2 = how_many_minus(s2) % 2;
    char *result = malloc(sizeof(char) * my_strlen(s1));
    char *modulo_div;

    s1 = number_cleaner(s1);
    s2 = number_cleaner(s2);
    if (s1[0] == '0') return ("0");
    if (s2[0] == '0') return (NULL);
    if (my_strlen(s1) - my_strlen(s2) <= 5) result = modulo_simple(s1, s2);
    else result = modulo_complexe(s1, s2, result, modulo_div);
    if (nbr_moins_s1 == 0 && nbr_moins_s2 == 0) return (result);
    if (nbr_moins_s1 == 1 && nbr_moins_s2 == 1) return (minus_adder(result));
    if (nbr_moins_s1 == 1 && nbr_moins_s2 == 0) {
        result = minus_adder(result);
        return (addisoustraction(s2, result));
    }
    else { result = minus_adder(result);
        return (minus_adder(addisoustraction(result, s2)));
    }
}
