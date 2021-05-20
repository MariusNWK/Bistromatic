/*
** EPITECH PROJECT, 2020
** plus_moins
** File description:
** projet solo 1
*/
#include <stdio.h>
#include <my.h>
#include <stdlib.h>

char *result_if_plus_higher(char *s1, char *s2, char *result)
{
    int add = 0;
    int carry = 0;
    int size_result = value_size_result(s1, s2);
    int size_s1 = my_strlen(s1);
    int size_s2 = my_strlen(s2);

    for (; size_result > 0; size_s1--, size_s2--, size_result--) {
        s1 = s_equal_zero(s1, size_s1);
        s2 = s_equal_zero(s2, size_s2);
        if (s2[size_s2 - 1] - 48 + carry > s1[size_s1 - 1] - 48) {
            add = (s1[size_s1 - 1] - 48 + 10) -
                (s2[size_s2 - 1] - 48 + carry);
            carry = 1;
        }
        else {
            add = ((s1[size_s1 - 1] - 48)) - (s2[size_s2 - 1] - 48 + carry);
            carry = 0;
        }
        result[size_result - 1] = add + 48;
    }
    return (result);
}

char *result_if_moins_higher(char *s1, char *s2, char *result)
{
    int add = 0;
    int carry = 0;
    int size_result = value_size_result(s1, s2);
    int size_s1 = my_strlen(s1);
    int size_s2 = my_strlen(s2);

    for (; size_result > 0; size_s1--, size_s2--, size_result--) {
        s1 = s_equal_zero(s1, size_s1);
        s2 = s_equal_zero(s2, size_s2);
        if (s1[size_s1 - 1] - 48 + carry > s2[size_s2 - 1] - 48) {
            add = (s2[size_s2 - 1] - 48 + 10) -
                (s1[size_s1 - 1] - 48 + carry);
            carry = 1;
        }
        else {
            add = ((s2[size_s2 - 1] - 48)) - (s1[size_s1 - 1] - 48 + carry);
            carry = 0;
        }
        result[size_result - 1] = add + 48;
    }
    return (result);
}

char *nothing_zero_moins(char *s1, char *s2, int s1plusgrand, char *result)
{
    int size_s1 = my_strlen(s1);
    int size_s2 = my_strlen(s2);
    char *new_result;

    if (size_s1 > size_s2 || s1plusgrand == 1);
    else if (s1[0] == s2[0] && my_strlen(s1) ==
        my_strlen(s2) && s1plusgrand != 2) {
        result[0] = '0';
    }
    else {
        new_result = malloc(sizeof(char) * (my_strlen(result) + 1));
        new_result[0] = '-';
        for (int i = 0; result[i] != '\0'; i++)
            new_result[i + 1] = result[i];
        return (new_result);
    }
    return (result);
}

char *plus_moins(char *s1, char *moins_s2)
{
    char *s2 = value_s2(moins_s2);
    char *result = value_result(s1, s2);
    int full_of_zero = value_full_of_zero(s1, s2);
    int size_result = value_size_result(s1, s2);
    int size_s1 = my_strlen(s1);
    int size_s2 = my_strlen(s2);
    int add_s1_s2 = 0;
    int carry = 0;
    int s1plusgrand = value_s1plusgrand(size_s1, size_s2, s1, s2);

    result = result_zeros_only(full_of_zero, result);
    if (size_s1 > size_s2 || s1plusgrand == 1)
        result = result_if_plus_higher(s1, s2, result);
    else
        result = result_if_moins_higher(s1, s2, result);
    for (int i = 0; result[0] == '0'; i++)
        result++;
    result = nothing_zero_moins(s1, s2, s1plusgrand, result);
    return (result);
}
