/*
** EPITECH PROJECT, 2020
** Multiplication
** File description:
** infinie
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *last_number(int mult, int size_result, int m, char *result)
{
    int unit = 0;

    for (; mult > 0; mult = mult / 10, size_result--) {
        unit = mult % 10;
        result[size_result - 1 - m] = unit + 48;
    }
    return (result);
}

char *multiplication_two(char *s1, char *s2, char *result, char *result_mult)
{
    for (int n = 0, m = my_strlen(s1) - 1; n < my_strlen(s1); n++, m--) {
        for (int i = 0; i < my_strlen(s1) + my_strlen(s2); i++)
            result[i] = '0';
        for (int size_s2 = my_strlen(s2), size_result = my_strlen(result), mult
            = 0, unit = 0, carry = 0; size_s2 > 0; size_s2--, size_result--) {
            if (size_s2 > 1) {
                mult = (s1[n] - 48) * (s2[size_s2 - 1] - 48) + carry;
                unit = mult % 10;
                carry = mult / 10;
                result[size_result - 1 - m] = unit + 48;
            }
            else {
                mult = (s1[n] - 48) * (s2[0] - 48) + carry;
                result = last_number (mult, size_result, m, result);
                carry = 0;
                result_mult = plus_plus(result_mult, result);
            }
        }
    }
    return (result_mult);
}

char *negative_mult(char *result_mult)
{
    char *result = malloc(sizeof(char) * (my_strlen(result_mult) + 1));
    int i = 0;

    result[0] = '-';
    for (i = 0; result_mult[i] != '\0'; i++)
        result[i + 1] = result_mult[i];
    result[i + 1] = '\0';
    return (result);
}

char *number_cleaner(char *nbr)
{
    for (; nbr[0] == '+' || nbr[0] == '-' ||
        (nbr[0] == '0' && my_strlen(nbr) > 1); nbr++);
    return (nbr);
}

char *multiplication(char *s1, char *s2)
{
    int d = 1;
    char *result = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2)));
    char *result_mult;
    int moins = 0;

    for (int i = 0; s1[i] != '\0'; i++)
        if (s1[i] == '-')
            moins++;
    for (int i = 0; s2[i] != '\0'; i++)
        if (s2[i] == '-')
            moins++;
    s1 = number_cleaner(s1);
    s2 = number_cleaner(s2);
    for (int i = 0; i < my_strlen(s1) + my_strlen(s2); i++)
        result[i] = '0';
    result_mult = malloc(sizeof(char) * my_strlen(result));
    for (int i = 0; i < my_strlen(result); i++, result_mult[i] = '0');
    result_mult = multiplication_two(s1, s2, result, result_mult);
    if (moins % 2 == 1 && (my_strlen(result_mult) > 1 && result_mult[0] != '0'))
        result_mult = negative_mult(result_mult);
    return (result_mult);
}
