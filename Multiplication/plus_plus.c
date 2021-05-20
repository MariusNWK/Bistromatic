/*
** EPITECH PROJECT, 2020
** plus_plus
** File description:
** plus_plus
*/
#include <stdio.h>
#include <my.h>
#include <stdlib.h>

char *plus_plus5(int size_s, char *s)
{
    if (size_s < 1)
        s[size_s - 1] = '0';
    return (s);
}

char *plus_plus2(int size_result, char *result, char *s1, char *s2)
{
    int size_s1 = 0;
    int size_s2 = 0;
    int carry = 0;
    int add_s1_s2 = 0;

    size_s1 = my_strlen(s1);
    size_s2 = my_strlen(s2);
    while (size_result > 0) {
        s1 = plus_plus5(size_s1, s1);
        s2 = plus_plus5(size_s2, s2);
        add_s1_s2 = (s1[size_s1 - 1] - 48) + (s2[size_s2 - 1] - 48);
        add_s1_s2 = add_s1_s2 + carry;
        carry = add_s1_s2 / 10;
        add_s1_s2 = add_s1_s2 % 10;
        result[size_result - 1] = add_s1_s2 + 48;
        size_s1--;
        size_s2--;
        size_result--;
    }
    return (result);
}

char *plus_plus3(int size_result, char *s1, char *s2, char *result)
{
    int full_of_zero = 0;

    if (my_strlen(s1) >= my_strlen(s2))
        full_of_zero = my_strlen(s1);
    else
        full_of_zero = my_strlen(s2);
    if ((my_strlen(s1) == my_strlen(s2)) && ((s1[0] - 48) + (s2[0] - 48) >= 10))
        full_of_zero++;
    else
        size_result--;
    while (full_of_zero > 0) {
        result[full_of_zero - 1] = '0';
        full_of_zero--;
    }
    return (result);
}

int plus_plus4(int size_result, char *s1, char *s2, char *result)
{
    int full_of_zero = 0;

    if (my_strlen(s1) >= my_strlen(s2))
        full_of_zero = my_strlen(s1);
    else
        full_of_zero = my_strlen(s2);
    if ((my_strlen(s1) == my_strlen(s2)) && ((s1[0] - 48) + (s2[0] - 48) >= 10))
        full_of_zero++;
    else
        size_result--;
    while (full_of_zero > 0) {
        result[full_of_zero - 1] = '0';
        full_of_zero--;
    }
    return (size_result);
}

char *plus_plus(char *s1, char *s2)
{
    char *result;
    int size_result = 0;

    for (int size_s1 = my_strlen(s1); s1[0] == '0'
        && size_s1 > 1; size_s1--, s1++);
    if (my_strlen(s1) >= my_strlen(s2)) {
        result = malloc(sizeof(char) * my_strlen(s1) + 1);
        size_result = my_strlen(s1) + 1;
    }
    else {
        result = malloc(sizeof(char) * my_strlen(s2) + 1);
        size_result = my_strlen(s2) + 1;
    }
    size_result = plus_plus4(size_result, s1, s2, result);
    result = plus_plus3(size_result, s1, s2, result);
    result = plus_plus2(size_result, result, s1, s2);
    for (int size = my_strlen(result); result[0] == '0' && size > 1; size--)
        result++;
    if (result[0] == '0' && my_strlen(result) > 1)
        return (plus_plus_suite(result));
    return (result);
}
